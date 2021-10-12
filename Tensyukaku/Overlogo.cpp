/*****************************************************************//**
 * \file   Overlogo.cpp
 * \brief  �Q�[���I�[�o�[���S�N���X�i���[�h�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ResourceServer.h"
#include "Overlogo.h"

namespace {
	constexpr auto FADEIN_FRAME = 60;
	constexpr auto FADE_SPEED = 4;
}
/*-----������-----*/
bool Overlogo::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;						//X���W�̏�����
	_y = 450;						//Y���W�̏�����
	_pal = 0;							//�t�F�[�h�C�����Ă������߁A�����x�O�ŏ�����
	_mode_cnt = _cnt;		//�t���[���̏�����
	_trans_flag = true;			//�w�i���߃t���O��^�ŏ�����
	_grhandle = ResourceServer::LoadGraph("res/Mode/OverLogo.png");		//�摜�ǂݍ���
	return true;
}
/*-----�I��------*/
bool Overlogo::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
/*-----�X�V-----*/
bool Overlogo::Process(Game& g) {
	base::Process(g);
	auto frame = _cnt - _mode_cnt;
	//�t�F�[�h�C���̏���
	if (frame < FADEIN_FRAME) {
		_pal += FADE_SPEED;
	}
	if (frame == FADEIN_FRAME) {
		_pal = 255;
	}
	return true;
}
/*-----�`��-----*/
bool Overlogo::Draw(Game& g) {
	base::Draw(g);
	return true;
}
