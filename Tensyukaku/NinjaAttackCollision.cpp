/*****************************************************************//**
 * \file   NinjaAttackCollision.cpp
 * \brief  忍者の攻撃当たり判定クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "NinjaAttackCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Ninja.h"

using namespace NInfo;
//攻撃当たり判定実体
NinjaAttackCollision::NinjaAttackCollision(int x, int y) {
   _x = x;
   _y = y;
   Init();
}
NinjaAttackCollision::~NinjaAttackCollision() {
}

void NinjaAttackCollision::Init() {
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

void NinjaAttackCollision::Process(Game& g) {
   ObjectBase::Process(g);
   if (_cnt - _action_cnt == ATTACK_ENDFRAME) {
      Delete(g);
   }
}
void NinjaAttackCollision::Draw(Game& g) {
   ObjectBase::Draw(g);
}
void NinjaAttackCollision::Delete(Game& g) {
   g.GetOS()->Del(this);
}