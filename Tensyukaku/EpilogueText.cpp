/*****************************************************************//**
 * \file   EpilogueText.cpp
 * \brief  �G�s���[�O�e�L�X�g�N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModeEpilogue.h"
#include "EpilogueText.h"
#include "ModeGame.h"
#include "Game.h"
#include "ResourceServer.h"

using namespace EpiInfo;
/*-----������------*/
bool EpilogueText::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = TEXT_FIRST_XPOSITION;		//X���W������
	_y = 750;													//Y���W������
	_pal = 0;													//�t�F�[�h�C�����Ă������߁A�����x0�ŏ�����
	_GraphNo = 0;										//�V�[�g�ԍ�0�ŏ�����
	_mode_cnt = _cnt;								//�t���[���̏�����
	_trans_flag = true;								//�w�i���߃t���O��^�ŏ�����
	//�摜�ǂݍ���
	_grall["EText"].resize(TEXT_ANIMEMAX);
	ResourceServer::LoadDivGraph(TEXT_GRAPHNAME, TEXT_ANIMEMAX, TEXT_WIDTHCOUNT, TEXT_HEIGHTCOUNT, TEXT_GRAPH_WIDTH, TEXT_GRAPH_HEIGHT, _grall["EText"].data());
	LoadSE();													//SE�ǂݍ���
	VolumeInit();											//SE���ʂ̏�����
	return true;
}

bool EpilogueText::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
/*-----�X�V------*/
bool EpilogueText::Process(Game& g) {
	base::Process(g);
	VolumeChange();					//���ʉ����ʕύX
	auto frame = _cnt - _mode_cnt;
	_grhandle = _grall["EText"][_anime["EText"]];
	_anime["EText"] = _GraphNo;
	/*-----�e�e�L�X�g�̃t�F�[�h�C���A�t�F�[�h�A�E�g�A�ړ��t���[��-----*/
	//�e�L�X�g1
	if (frame == 1) {
		//�{�C�X
		PlaySoundMem(_se["Text1"], DX_PLAYTYPE_BACK, true);
	}
	if (frame < TEXT1_FADEIN_FRAME) {
		_pal += TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT1_FADEIN_FRAME) {
		_pal = 255;
	}
	if (frame >= TEXT1_FADEOUT_BEGINFRAME && TEXT1_FADEOUT_ENDFRAME > frame) {
		_pal -= TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT1_FADEOUT_ENDFRAME) {
		_pal = 0;
		_x = TEXT_FIRST_XPOSITION;
		_GraphNo = 1;
	}
	//�e�L�X�g2
	if (frame == TEXT2_FADEIN_BEGINFRAME) {
		//�{�C�X
		PlaySoundMem(_se["Text2"], DX_PLAYTYPE_BACK, true);
	}
	if (frame >= TEXT2_FADEIN_BEGINFRAME && TEXT2_FADEIN_ENDFRAME > frame) {
		_pal += TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT2_FADEIN_ENDFRAME) {
		_pal = 255;
	}
	if (frame >= TEXT2_FADEOUT_BEGINFRAME && TEXT2_FADEOUT_ENDFRAME > frame) {
		_pal -= TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT2_FADEOUT_ENDFRAME) {
		_pal = 0;
		_x = TEXT_FIRST_XPOSITION;
		_GraphNo = 2;
	}
	//�e�L�X�g3
	if (frame == TEXT3_FADEIN_BEGINFRAME) {
		//�{�C�X
		PlaySoundMem(_se["Text3"], DX_PLAYTYPE_BACK, true);
	}
	if (frame >= TEXT3_FADEIN_BEGINFRAME && TEXT3_FADEIN_ENDFRAME > frame) {
		_pal += TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT3_FADEIN_ENDFRAME) {
		_pal = 255;
	}
	if (frame >= TEXT3_FADEOUT_BEGINFRAME && TEXT3_FADEOUT_ENDFRAME > frame) {
		_pal -= TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT3_FADEOUT_ENDFRAME) {
		_pal = 0;
		_x = TEXT_FIRST_XPOSITION;
		_GraphNo = 3;
	}
	//�e�L�X�g4
	if (frame == TEXT4_FADEIN_BEGINFRAME) {
		//�{�C�X
		PlaySoundMem(_se["Text4"], DX_PLAYTYPE_BACK, true);
	}
	if (frame >= TEXT4_FADEIN_BEGINFRAME && TEXT4_FADEIN_ENDFRAME > frame) {
		_pal += TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT4_FADEIN_ENDFRAME) {
		_pal = 255;
	}
	if (frame >= TEXT4_FADEOUT_BEGINFRAME && TEXT4_FADEOUT_ENDFRAME > frame) {
		_pal -= TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT4_FADEOUT_ENDFRAME) {
		_pal = 0;
		g.GetMS()->Del(this);
	}
	return true;
}
/*-----�`��------*/
bool EpilogueText::Draw(Game& g) {
	base::Draw(g);
	return true;
}

//SE�ǂݍ���
void	EpilogueText::LoadSE() {
	_se["Text1"] = ResourceServer::LoadSoundMem("se/Voice/Epilogue01.wav");
	_se["Text2"] = ResourceServer::LoadSoundMem("se/Voice/Epilogue02.wav");
	_se["Text3"] = ResourceServer::LoadSoundMem("se/Voice/Epilogue03.wav");
	_se["Text4"] = ResourceServer::LoadSoundMem("se/Voice/Epilogue04.wav");
}

//�{�����[�������l
void	EpilogueText::VolumeInit() {
	_vpal["Text1"] = 255;
	_vpal["Text2"] = 255;
	_vpal["Text3"] = 255;
	_vpal["Text4"] = 255;
}
//�{�����[���ύX
void	EpilogueText::VolumeChange() {
	ChangeVolumeSoundMem(_vpal["Text1"], _se["Text1"]);
	ChangeVolumeSoundMem(_vpal["Text2"], _se["Text2"]);
	ChangeVolumeSoundMem(_vpal["Text3"], _se["Text3"]);
	ChangeVolumeSoundMem(_vpal["Text4"], _se["Text4"]);
}
