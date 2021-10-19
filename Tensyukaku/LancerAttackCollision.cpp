/*****************************************************************//**
 * \file   LancerAttackCollision.cpp
 * \brief  槍兵の攻撃当たり判定クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "LancerAttackCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Lancer.h"


using namespace LInfo;

LancerAttackCollision::LancerAttackCollision(int x, int y) {
   _x = x;
   _y = y;
   Init();
}
LancerAttackCollision::~LancerAttackCollision() {
}

void LancerAttackCollision::Init() {
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

void LancerAttackCollision::Process(Game& g) {
   ObjectBase::Process(g);
   if (_cnt - _action_cnt == ATTACK_ENDFRAME) {
      Delete(g);
   }
}
void LancerAttackCollision::Draw(Game& g) {
   ObjectBase::Draw(g);
}
void LancerAttackCollision::Delete(Game& g) {
   g.GetOS()->Del(this);
}


