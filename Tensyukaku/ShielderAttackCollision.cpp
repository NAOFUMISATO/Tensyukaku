/*****************************************************************//**
 * \file   ShielderAttackCollision.cpp
 * \brief  盾兵の攻撃当たり判定クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ShielderAttackCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Shielder.h"


using namespace SInfo;

ShielderAttackCollision::ShielderAttackCollision(int x, int y) {
   _x = x;
   _y = y;
   Init();
}
ShielderAttackCollision::~ShielderAttackCollision() {
}

void ShielderAttackCollision::Init() {
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

void ShielderAttackCollision::Process(Game& g) {
   ObjectBase::Process(g);
   if (_cnt - _action_cnt == ATTACK_ENDFRAME) {
      g.GetOS()->Del(this);
   }
}
void ShielderAttackCollision::Draw(Game& g) {
   ObjectBase::Draw(g);
}
void ShielderAttackCollision::Delete(Game& g) {
   g.GetOS()->Del(this);
}


