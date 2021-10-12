/*****************************************************************//**
 * \file   ModeTitle.cpp
 * \brief  ���[�h�^�C�g���N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModeTitle.h"
#include "ModeGame.h"
#include "Game.h"
#include "ResourceServer.h"
#include "Cursor.h"
#include "TitleSelect.h"

using namespace MTInfo;
/*-----������-----*/
 bool ModeTitle::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;										//X���W�̏�����
	_y = 540;										//Y���W�̏�����
	_pal = 0;											//�t�F�[�h�C�����Ă������߁A�����x0�ŏ�����
	_mode_cnt = _cnt;						//�t���[���O�ŏ�����
	_stopObjProcess = false;				//�I�u�W�F�N�g�������~�߂�t���O���U�ŏ�����
	_trans_flag = true;							//�w�i���߃t���O��^�ŏ�����
	//�摜�ǂݍ���
	_grall["AmgLogo"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/AmgLogo.png",1,1,1,1920,1080, _grall["AmgLogo"].data());
	_grall["TeamLogo"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/TeamLogo.png", 1, 1, 1, 1920, 1080, _grall["TeamLogo"].data());
	_grall["TitleBG"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/TitleBG.png", 1, 1, 1, 1920, 1080, _grall["TitleBG"].data());
	//�e�`�F�b�N�|�C���g���B�t���O��S�ċU�ŏ�����
	auto flag = g.GetCPointFlag();
	flag["2A"] = false;
	flag["3A"] = false;
	flag["4A"] = false;
	flag["5A"] = false;
	flag["5B"] = false;
	flag["8A"] = false;
	flag["11A"] = false;
	g.SetCPointFlag(flag);
	//�ċN���ǂ����̃t���O���U�ŏ�����
	g.SetRestartFlag(false);
	//�eBGM�̏�����
	g.VolumeInit();
	return true;
}
 /*-----�I��------*/
bool ModeTitle::Terminate(Game& g) {
	base::Terminate(g);
	g.GetOS()->Clear();
	return true;
}
/*-----�X�V-----*/
bool ModeTitle::Process(Game& g) {
	base::Process(g);
	auto frame = _cnt - _mode_cnt;
	auto pal = _pal;
	/*--�e��Ԃ��Ƃ̏���*/
	switch (_type) {
		//AMG���S
	case TITLETYPE::AMGLOGO:
		_grhandle = _grall["AmgLogo"][_anime["AmgLogo"]];
		_anime["AmgLogo"] = 0;
		//�t�F�[�h�֌W�̏���
		if (frame < AMG_FADEINFRAME) {
			_pal += AMG_FADESPEED;
		}
		if (frame == AMG_FADEINFRAME) {
			_pal = 255;
		}
		if (frame > AMG_FADEOUTBEGINFRAME && AMG_FADEOUTENDFRAME > frame) {
			_pal -= AMG_FADESPEED;
		}
		if (frame == AMG_FADEOUTENDFRAME) {
			_pal = 0;
			_mode_cnt = _cnt;
			_type = TITLETYPE::TEAMLOGO;			//�t�F�[�h�̏������I������Ȃ�`�[�����S��
		}
		break;
		//�`�[�����S
	case TITLETYPE::TEAMLOGO:
		_grhandle = _grall["TeamLogo"][_anime["TeamLogo"]];
		_anime["TeamLogo"] = 0;
		//�t�F�[�h�֌W�̏���
		if (frame < TEAM_FADEINFRAME) {
			_pal += TEAM_FADESPEED;
		}
		if (frame == TEAM_FADEINFRAME) {
			_pal = 255;
		}
		if (frame > TEAM_FADEOUTBEGINFRAME && TEAM_FADEOUTENDFRAME > frame) {
			_pal -= TEAM_FADESPEED;
		}
		if (frame == TEAM_FADEOUTENDFRAME) {
			_pal = 0;
			_mode_cnt = _cnt;
			_type = TITLETYPE::TITLEBG;			//�t�F�[�h�̏������I������Ȃ�`�[�����S��
		}
		break;
		//�^�C�g���w�i
	case TITLETYPE::TITLEBG:
		_grhandle = _grall["TitleBG"][_anime["TitleBG"]];
		_anime["TitleBG"] = 0;
		if (frame == 1) {
			auto cu = new Cursor();		//�^�C�g���J�[�\������
			g.GetOS()->Add(cu);
		}
		if (frame > TITLE_FADEINBEGINFRAME && TITLE_FADEINENDFRAME > frame) {
			_pal += TITLE_FADESPEED;
		}
		if (frame == TITLE_FADEINENDFRAME) {
			_pal = 255;
			PlaySoundMem(g.GetBgm()["Title"], DX_PLAYTYPE_LOOP, true);
			auto tl = new TitleLogo();		//�^�C�g�����S����
			g.GetOS()->Add(tl);
		}
		if (frame == GAMESTART_APPEARFRAME) {
			auto gs = new GameStart();	//�Q�[���X�^�[�g�Z���N�g����
			g.GetOS()->Add(gs);
		}
		if (frame == EXPLAIN_APPEARFRAME) {
			auto ex = new Explain();		//�����Z���N�g����
			g.GetOS()->Add(ex);
		}
		if (frame == GAMEEND_APPEARFRAME) {
			auto ge = new GameEnd();	//�Q�[���I���Z���N�g����
			g.GetOS()->Add(ge);
		}
		if (frame ==CREDIT_APPEARFRAME) {
			auto cr = new Credit();			//�N���W�b�g�Z���N�g����
			g.GetOS()->Add(cr);
		}
		break;
	}
	//�I�u�W�F�N�g���~�߂�t���O���U�Ȃ�I�u�W�F�N�g�������X�V����
	if (_stopObjProcess == false) {
		g.GetOS()->Process(g);
	}
	return true;
}
/*-----�`��-----*/
bool ModeTitle::Draw(Game& g) {
	base::Draw(g);
	g.GetOS()->Draw(g);
	return true;
}

