/*****************************************************************//**
 * \file   OverlayFlame.cpp
 * \brief  �C���Q�[���ł̉����o�N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "OverlayFlame.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ModeBase.h"
#include "FlamePerformParticle.h"

using namespace FParInfo;
namespace {
	constexpr auto FADEIN_FRAME = 120;
	constexpr auto FADE_SPEED = 2;
	constexpr auto FADEOUT_FRAME = 120;
}
/*----������-----*/
bool OverlayFlame::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;							//X���W�̏�����
	_y = 540;							//Y���W�̏�����
	_pal = 0;								//�t�F�[�h�C�����Ă������߁A�����x0�ŏ�����
	_mode_cnt = _cnt;			//�t���[���̏�����
	_trans_flag = true;				//�w�i���߃t���O��^�ŏ�����
	_grhandle = ResourceServer::LoadGraph("res/Mode/OverFlame.png");		//�摜�ǂݍ���
	return true;
}
/*-----�I��------*/
bool OverlayFlame::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
/*-----�X�V-----*/
bool OverlayFlame::Process(Game& g) {
	base::Process(g);
	auto frame = _cnt - _mode_cnt;
	//�����o�p�[�e�B�N������
	if ((_cnt /10 %2) == 0) {
		for (int i = 0; i < FLAME_QTY; i++) {
			std::pair<int, int> xy = std::make_pair(_x, _y);
			std::pair<double, double> dxy = std::make_pair(((rand() % FLAME_RANDOMX1) - FLAME_RANDOMX2) / FLAME_RANDOMX3, ((rand() % -FLAME_RANDOMY1) - FLAME_RANDOMY2) / FLAME_RANDOMY3);
			auto fp = new FlamePerform(xy, dxy, true);
			g.GetOS()->Add(fp);
		}
	}
	if (frame >= 0 && FADEIN_FRAME > frame) {
		_pal += FADE_SPEED;
	}
	if (frame == FADEIN_FRAME) {
		_pal = 255;
	}
	return true;
}
/*-----�`��-----*/
bool OverlayFlame::Draw(Game& g) {
	base::Draw(g);
	return true;
}