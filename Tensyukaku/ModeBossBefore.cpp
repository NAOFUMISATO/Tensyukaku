/*****************************************************************//**
 * \file   ModeBossBefore.cpp
 * \brief  �{�X�X�e�[�W�O��1���G�N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModeGame.h"
#include "ModeBossBefore.h"
#include "OverlayBlack.h"
#include "Game.h"
#include "ResourceServer.h"

using namespace BBInfo;
/*-----������------*/
bool ModeBossBefore::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;							//X���W�̏�����
	_y = 540;							//Y���W�̏�����
	_mode_cnt = _cnt;		//�t���[���̏�����
	_grhandle = ResourceServer::LoadGraph("res/Mode/BossBefore.png");		//�摜�ǂݍ���
	//SE�ǂݍ���
	_se["BossBefore"]=ResourceServer::LoadSoundMem("se/Voice/BossBefore.wav");	
	_se["BossFoot"] = ResourceServer::LoadSoundMem("se/Player/BBossFoot.wav");
	//SE���ʏ�����
	_vpal["BossBefore"] = 255;
	_vpal["BossFoot"] = 255;
	return true;
}

bool ModeBossBefore::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
/*-----�X�V------*/
bool ModeBossBefore::Process(Game& g) {
	base::Process(g);
	//SE�̉��ʕύX
	ChangeVolumeSoundMem(_vpal["BossBefore"], _se["BossBefore"]);
	ChangeVolumeSoundMem(_vpal["BossFoot"], _se["BossFoot"]);
	auto frame = _cnt - _mode_cnt;
	if (frame == FOOT_FRAME) {
		//SE�Đ�
		PlaySoundMem(_se["BossFoot"], DX_PLAYTYPE_BACK, true);
	}
	if (frame == VOICE_FRAME) {
		//SE�Đ�
		PlaySoundMem(_se["BossBefore"],DX_PLAYTYPE_BACK,true);
	}
	auto fadeoutendframe = 60;
	if (frame == FADEOUT_FRAME) {
		//��ʑJ�ڗp�t�F�[�h�N���X����
		auto ol = new OverlayBlack();
		ol->SetFade(fadeoutendframe, 80,140 , 5);
		g.GetMS()->Add(ol,10, "OverlayBlack");
	}
	if (frame == FADEOUT_FRAME + fadeoutendframe) {
		//���[�h�Q�[���̏������ĊJ
		auto mg = (ModeGame*)g.GetMS()->Get("Game");
		//BGM�Đ�
		PlaySoundMem(g.GetBgm()["Boss"], DX_PLAYTYPE_LOOP, true);
		mg->SetStopObjProcess(false);
		//���̃��[�h�̍폜
		g.GetMS()->Del(this);
	}
	return true;
}
/*-----�`��-----*/
bool ModeBossBefore::Draw(Game& g) {
	base::Draw(g);
	return true;
}