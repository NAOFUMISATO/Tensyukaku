/*****************************************************************//**
 * \file   LowAttackCollision.cpp
 * \brief  下段攻撃当たり判定クラス（オブジェクトベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Game.h"
#include "LowAttackCollision.h"
#include "Player.h"

using namespace PInfo;

LowAttackCollision::LowAttackCollision(int x, int y) {
   _x = x;
   _y = y;
   Init();
}
LowAttackCollision::~LowAttackCollision() {
}

void LowAttackCollision::Init() {
   _w = LOWATTACK_WIDTH;
   _h = LOWATTACK_HEIGHT;
   _gx = 0;
   _gy = 0;
   _hit_x = 0;
   _hit_y = 0;
   _hit_w = LOWATTACK_WIDTH;
   _hit_h = LOWATTACK_HEIGHT;
   _action_cnt = _cnt;
#ifdef _DEBUG
   _debug_color = std::make_tuple(255, 0, 0);
   _debug_alpha = 128;
   _debug_fill = true;
#endif
}

void LowAttackCollision::Process(Game& g) {
   ObjectBase::Process(g);
   if (_cnt - _action_cnt == LOWATTACK_ENDFRAME) {
      Delete(g);
   }
}
void LowAttackCollision::Draw(Game& g) {
   ObjectBase::Draw(g);
}
void LowAttackCollision::Delete(Game& g) {
   g.GetOS()->Del(this);
}