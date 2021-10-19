/*****************************************************************//**
 * \file   MiddleAttackCollision.cpp
 * \brief  中段攻撃当たり判定クラス（オブジェクトベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Game.h"
#include "MiddleAttackCollision.h"
#include "Player.h"

using namespace PInfo;

MiddleAttackCollision::MiddleAttackCollision(int x, int y) {
   _x = x;
   _y = y;
   Init();
}
MiddleAttackCollision::~MiddleAttackCollision() {
}

void MiddleAttackCollision::Init() {
   _w = MIDDLEATTACK_WIDTH;
   _h = MIDDLEATTACK_HEIGHT;
   _gx = 0;
   _gy = 0;
   _hit_x = 0;
   _hit_y = 0;
   _hit_w = MIDDLEATTACK_WIDTH;
   _hit_h = MIDDLEATTACK_HEIGHT;
   _action_cnt = _cnt;
#ifdef _DEBUG
   _debug_color = std::make_tuple(255, 0, 0);
   _debug_alpha = 128;
   _debug_fill = true;
#endif
}

void MiddleAttackCollision::Process(Game& g) {
   ObjectBase::Process(g);
   if (_cnt - _action_cnt == MIDDLEATTACK_ENDFRAME) {
      Delete(g);
   }
}
void MiddleAttackCollision::Draw(Game& g) {
   ObjectBase::Draw(g);
}
void MiddleAttackCollision::Delete(Game& g) {
   g.GetOS()->Del(this);
}