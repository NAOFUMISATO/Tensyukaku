/*****************************************************************//**
 * \file   ModeGameover.cpp
 * \brief  ���[�h�Q�[���I�[�o�[�N���X�i���[�h�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModeGameover.h"
#include "ModeGame.h"
#include "OverlayBlack.h"
#include "OverSelect.h"
#include "OverLogo.h"
#include "Game.h"
#include "ResourceServer.h"

namespace {
	constexpr auto FADEIN_FRAME = 60;						//�t�F�[�h�C���t���[��
	constexpr auto FADEIN_SPEED = 3;							//�t�F�[�h�C���X�s�[�h
	constexpr auto OVERLAY_PAL = 200;						//�ڂ��������̓����x
	constexpr auto OVERSELECT_FRAME = 120;		//�Z���N�g��ʂ̕\���t���[��
}
/*-----������-----*/
bool ModeGameover::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;									//X���W������
	_y = 540;									//Y���W������
	_pal = 0;									//�t�F�[�h�C�����Ă������߁A�����x�O�ŏ�����
	_mode_cnt = _cnt;				//�t���[���̏�����
	_grhandle = ResourceServer::LoadGraph("res/Mode/Black.png");													//�摜�ǂݍ��݁i�ڂ��������̂��߂̍��w�i�j
	_se["GameOver"] = ResourceServer::LoadSoundMem("se/OutGame/GameOver.wav");		//SE�ǂݍ���
	_vpal["GameOver"] = 255;				//SE���ʂ̏�����
	ChangeVolumeSoundMem(_vpal["GameOver"], _se["GameOver"]);				//SE���ʂ̕ύX
	PlaySoundMem(_se["GameOver"], DX_PLAYTYPE_BACK, true);						//SE�Đ�
	return true;
}

bool ModeGameover::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
/*-----�X�V-----*/
bool ModeGameover::Process(Game& g) {
	base::Process(g);
	auto frame = _cnt - _mode_cnt;
	//�t�F�[�h�C���̏���
	if (frame < FADEIN_FRAME) {
		_pal += FADEIN_SPEED;
	}
	if (frame == FADEIN_FRAME) {
		_pal = OVERLAY_PAL;
		auto ol = new Overlogo();						//�Q�[���I�[�o�[���S�̐���
		g.GetMS()->Add(ol, 3, "OverLogo");
	}
	if (frame == OVERSELECT_FRAME) {
		auto ps = new OverSelect();					//�Q�[���I�[�o�[�Z���N�g�̐���
		g.GetMS()->Add(ps, 3, "PSelect");
	}
	return true;
}
/*-----�`��-----*/
bool ModeGameover::Draw(Game& g) {
	base::Draw(g);
	return true;
}