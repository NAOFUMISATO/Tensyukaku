/*****************************************************************//**
 * \file   ModeEpilogue.cpp
 * \brief  �G�s���[�O�N���X�i���[�h�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModeEpilogue.h"
#include "EpilogueText.h"
#include "ModeTitle.h"
#include "Game.h"
#include "ResourceServer.h"

using namespace EpiInfo;
/*------������-------*/
bool ModeEpilogue::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;														//X���W�̏�����
	_y = 540;														//Y���W�̏�����
	_pal = 0;														//�t�F�[�h�C�����Ă������߁A�����x0�ŏ�����
	_mode_cnt = _cnt;									//�t���[���ŏ�����
	_grhandle=ResourceServer::LoadGraph("res/Mode/Epilogue.png");				//�摜�ǂݍ���
	PlaySoundMem(g.GetBgm()["Epilogue"], DX_PLAYTYPE_LOOP, true);			//BGM�Đ�
	return true;
}

bool ModeEpilogue::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
/*------�X�V-------*/
bool ModeEpilogue::Process(Game& g) {
	base::Process(g);
	auto frame = _cnt - _mode_cnt;
	//�t�F�[�h�C���̏���
	if(frame < BG_FADEIN_FRAME) {
		_pal += BG_FADEIN_SPEED;
	}
	if (frame == BG_FADEIN_FRAME) {
		_pal = 255;
		auto et = new EpilogueText();						//�G�s���[�O�e�L�X�g����
		g.GetMS()->Add(et, 1, "PText");
	}
	//�t�F�[�h�A�E�g�̏���
	if (frame >= BG_FADEOUT_BEGINFRAME && BG_FADEOUT_ENDFRAME > frame) {
		_pal -= BG_FADEOUT_SPEED;
	}
	if (frame == BG_FADEOUT_ENDFRAME) {
		_pal = 0;
		g.GetMS()->Del(g.GetMS()->Get("Epilogue"));			//�G�s���[�O�e�L�X�g���[�h�̍폜
		StopSoundMem(g.GetBgm()["Epilogue"]);
		auto mt = new ModeTitle();													//�^�C�g�����[�h����
		mt->SetTitlebg();
		g.GetMS()->Add(mt, 0, "Title");
	}
	return true;
}
/*------�`��-------*/
bool ModeEpilogue::Draw(Game& g) {
	base::Draw(g);
	return true;
}