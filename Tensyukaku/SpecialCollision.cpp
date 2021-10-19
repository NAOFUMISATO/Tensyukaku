/*****************************************************************//**
 * \file   SpecialCollision.cpp
 * \brief  特殊攻撃当たり判定クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Game.h"
#include "SpecialCollision.h"
#include "Player.h"

using namespace PInfo;

SpecialCollision::SpecialCollision(int x, int y) {
   _x = x;
   _y = y;
   Init();
}
SpecialCollision::~SpecialCollision() {
}

void SpecialCollision::Init() {
   _w = SPECIALATTACK_WIDTH;
   _h = SPECIALATTACK_HEIGHT;
   _gx = 0;
   _gy = 0;
   _hit_x = 0;
   _hit_y = 0;
   _hit_w = SPECIALATTACK_WIDTH;
   _hit_h = SPECIALATTACK_HEIGHT;
   _action_cnt = _cnt;
#ifdef _DEBUG
   _debug_color = std::make_tuple(255, 0, 0);
   _debug_alpha = 128;
   _debug_fill = true;
#endif
}

void SpecialCollision::Process(Game& g) {
   ObjectBase::Process(g);
   if (_cnt - _action_cnt == SPECIALATTACK_ENDFRAME) {
      Delete(g);
   }
}
void SpecialCollision::Draw(Game& g) {
   ObjectBase::Draw(g);
}
void SpecialCollision::Delete(Game& g) {
   g.GetOS()->Del(this);
}

