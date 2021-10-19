/*****************************************************************//**
 * \file   BushiAttackCollision.cpp
 * \brief  ���m�̍U�������蔻��N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "BushiAttackCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Bushi.h"

using namespace BInfo;

BushiAttackCollision::BushiAttackCollision(int x, int y) {
   _x = x;
   _y = y;
   Init();
}
BushiAttackCollision::~BushiAttackCollision() {
}

void BushiAttackCollision::Init() {
   _gx = 0;
   _gy = 0;
   _hit_x = 0;
   _hit_y = 0;
   _hit_w = ATTACK_WIDTH;
   _hit_h = ATTACK_HEIGHT;
   _action_cnt = _cnt;
#ifdef _DEBUG
   _debug_color = std::make_tuple(255, 0, 0);
   _debug_alpha = 128;
   _debug_fill = true;
#endif
}

void BushiAttackCollision::Process(Game& g) {
   ObjectBase::Process(g);
   if (_cnt - _action_cnt == ATTACK_ENDFRAME) {
      Delete(g);
   }
}
void BushiAttackCollision::Draw(Game& g) {
   ObjectBase::Draw(g);
}
void BushiAttackCollision::Delete(Game& g) {
   g.GetOS()->Del(this);
}


