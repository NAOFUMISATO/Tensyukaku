/*****************************************************************//**
 * \file   BusyoAttackCollision.cpp
 * \brief  武将の攻撃当たり判定クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "BusyoAttackCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Busyo.h"

using namespace BsInfo;
//攻撃当たり判定実体
BusyoAttackCollision::BusyoAttackCollision(int x, int y) {
   _x = x;
   _y = y;
   Init();
}
BusyoAttackCollision::~BusyoAttackCollision() {
}

void BusyoAttackCollision::Init() {
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

void BusyoAttackCollision::Process(Game& g) {
   ObjectBase::Process(g);
   auto frame = _cnt - _action_cnt;
   if (frame == ATTACK_ENDFRAME||frame==ATTACK_END2FRAME) {
      Delete(g);
   }
}
void BusyoAttackCollision::Draw(Game& g) {
   ObjectBase::Draw(g);
}
void BusyoAttackCollision::Delete(Game& g) {
   g.GetOS()->Del(this);
}


