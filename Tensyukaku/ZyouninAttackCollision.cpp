/*****************************************************************//**
 * \file   ZyouninAttackCollision.cpp
 * \brief  上忍の攻撃当たり判定クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ZyouninAttackCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Zyounin.h"

using namespace ZInfo;

ZyouninAttackCollision::ZyouninAttackCollision(int x, int y) {
   _x = x;
   _y = y;
   Init();
}
ZyouninAttackCollision::~ZyouninAttackCollision() {
}

void ZyouninAttackCollision::Init() {
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

void ZyouninAttackCollision::Process(Game& g) {
   ObjectBase::Process(g);
   if (_cnt - _action_cnt == ATTACK_ENDFRAME) {
      Delete(g);
   }
}
void ZyouninAttackCollision::Draw(Game& g) {
   ObjectBase::Draw(g);
}
void ZyouninAttackCollision::Delete(Game& g) {
   g.GetOS()->Del(this);
}