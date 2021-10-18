/*****************************************************************//**
 * \file   KickCollision.cpp
 * \brief  �R�蓖���蔻��N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Game.h"
#include "KickCollision.h"
#include "Player.h"

using namespace PInfo;
//�R�蓖���蔻�����
KickCollision::KickCollision(int x, int y) {
   _x = x;
   _y = y;
   Init();
}
KickCollision::~KickCollision() {
}

void KickCollision::Init() {
   _w = KICK_WIDTH;
   _h = KICK_HEIGHT;
   _gx = 0;
   _gy = 0;
   _hit_x = 0;
   _hit_y = 0;
   _hit_w = KICK_WIDTH;
   _hit_h = KICK_HEIGHT;
   _action_cnt = _cnt;
#ifdef _DEBUG
   _debug_color = std::make_tuple(255, 0, 0);
   _debug_alpha = 128;
   _debug_fill = true;
#endif
}

void KickCollision::Process(Game& g) {
   ObjectBase::Process(g);
   if (_cnt - _action_cnt == KICK_ENDFRAME) {
      Delete(g);
   }
}
void KickCollision::Draw(Game& g) {
   ObjectBase::Draw(g);
}
void KickCollision::Delete(Game& g) {
   g.GetOS()->Del(this);
}