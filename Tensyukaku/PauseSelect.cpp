/*****************************************************************//**
 * \file   PauseSelect.cpp
 * \brief  �|�[�Y�Z���N�g�N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "PauseSelect.h"
#include "Game.h"
#include "ModeTitle.h"
#include "ModeGame.h"
#include "OverlayBlack.h"
#include "ResourceServer.h"
/*----������----- */
bool PauseSelect::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;												//X���W�̏�����
	_y = 850;												//Y���W�̏�����
	_graph_no = 0;									  	//�V�[�g�ԍ��O�ŏ�����
	_type = SELECTTYPE::NOSELECT;	  	//�����I�����Ă��Ȃ���Ԃŏ�����
	_trans_flag = true;								   	//�w�i���߃t���O��^�ŏ�����
	_input_flag = false;							   	//���͎�t�t���O���U�ŏ�����
	_grall["PSelect"].resize(3);
	ResourceServer::LoadDivGraph("res/Mode/PauseSelect.png",3,3,1,1230,275,_grall["PSelect"].data());	//�摜�ǂݍ���
	//SE�ǂݍ���
	_se["Select"] = ResourceServer::LoadSoundMem("se/OutGame/OtherSelectPush.wav");
	_se["Push"] = ResourceServer::LoadSoundMem("se/OutGame/GameStartPush.wav");
	//SE���ʏ�����
	_vpal["Select"] = 125;
	_vpal["Push"] =200;
	return true;
}
/*-----�I��------*/
bool PauseSelect::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
/*----�X�V----- */
bool PauseSelect::Process(Game& g) {
	base::Process(g);
	//SE���ʕύX
	ChangeVolumeSoundMem(_vpal["Select"], _se["Select"]);
	ChangeVolumeSoundMem(_vpal["Push"], _se["Push"]);
	_grhandle = _grall["PSelect"][_anime["PSelect"]];
	_anime["PSelect"] = _graph_no;
	auto frame = _cnt - _mode_cnt;
	/*-----�e��Ԗ��̏���-----*/
	switch (_type) {
		//�����I�����Ă��Ȃ����
	case SELECTTYPE::NOSELECT:
		_graph_no = 0;
		if (g.GetTrg() & PAD_INPUT_LEFT) {
			PlaySoundMem(_se["Select"],DX_PLAYTYPE_BACK,true);
			_type = SELECTTYPE::RETURNSELECT;
		}
		if (g.GetTrg() & PAD_INPUT_RIGHT) {
			PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
			_type = SELECTTYPE::GOTITLESELECT;
		}
		break;
		//�Q�[���ɖ߂�I�����
	case SELECTTYPE::RETURNSELECT:
		_graph_no = 1;
		if (g.GetTrg() & PAD_INPUT_3&&_input_flag==false) {
			PlaySoundMem(_se["Push"], DX_PLAYTYPE_BACK, true);
			_input_flag = true;
			_mode_cnt = _cnt;
		}
		if (frame == 1 && _input_flag == true) {
			g.GetMS()->Del(this);
			g.GetMS()->Del(g.GetMS()->Get("Pause"));
			g.GetMS()->Del(g.GetMS()->Get("PController"));
			_input_flag = false;
			auto mg = (ModeGame*)g.GetMS()->Get("Game");
			mg->SetStopObjProcess(false);
		}
		if (g.GetTrg() & PAD_INPUT_RIGHT) {
			PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
			_type = SELECTTYPE::GOTITLESELECT;
		}
		break;
		//�^�C�g���I�����
	case SELECTTYPE::GOTITLESELECT:
		_graph_no = 2;
		if (g.GetTrg() & PAD_INPUT_3&&_input_flag==false) {
			PlaySoundMem(_se["Push"], DX_PLAYTYPE_BACK, true);
			_input_flag =true;
			_mode_cnt = _cnt;
			g.GetMS()->Del(g.GetMS()->Get("Flame"));
			auto ob = new OverlayBlack();
			ob->SetFade(60,180, 240, 5);
			g.GetMS()->Add(ob, 30, "OverlayBlack");
		}
		if (frame == 60 && _input_flag == true) {
			g.GetMS()->Del(this);
			g.GetMS()->Del(g.GetMS()->Get("PController"));
			g.GetMS()->Del(g.GetMS()->Get("Pause"));
			auto mg = (ModeGame*)g.GetMS()->Get("Game");
			mg->SetStopObjProcess(false);
			_input_flag = false;
			g.GetMS()->Del(g.GetMS()->Get("Game"));
			auto mt = new ModeTitle();
			mt->SetTitlebg();
			g.GetMS()->Add(mt, 0, "Title");	
			StopSoundMem(g.GetBgm()["Main"]); 
			StopSoundMem(g.GetBgm()["Flame"]);
			StopSoundMem(g.GetBgm()["Boss"]);
		}
		if(g.GetTrg() & PAD_INPUT_LEFT) {
			PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
			_type = SELECTTYPE::RETURNSELECT;
		}
		break;
	}
	return true;
}
/*----�`��----- */
bool PauseSelect::Draw(Game& g) {
	base::Draw(g);
	return true;
}

