/*****************************************************************//**
 * \file   IaiCollision.cpp
 * \brief  居合当たり判定クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Game.h"
#include "IaiCollision.h"
#include "Player.h"

using namespace PInfo;
//居合当たり判定実体
IaiCollision::IaiCollision(int x, int y) {
   _x = x;
   _y = y;
   Init();
}
IaiCollision::~IaiCollision() {
}

void IaiCollision::Init() {
   _w = IAI_WIDTH;
   _h = IAI_HEIGHT;
   _gx = 0;
   _gy = 0;
   _hit_x = 0;
   _hit_y = 0;
   _hit_w = IAI_WIDTH;
   _hit_h = IAI_HEIGHT;
   _action_cnt = _cnt;
#ifdef _DEBUG
   _debug_color = std::make_tuple(255, 0, 0);
   _debug_alpha = 128;
   _debug_fill = true;
#endif
}

void IaiCollision::Process(Game& g) {
   ObjectBase::Process(g);
   if (_cnt - _action_cnt == IAI_ENDFRAME) {
      Delete(g);
   }
}
void IaiCollision::Draw(Game& g) {
   ObjectBase::Draw(g);
}
void IaiCollision::Delete(Game& g) {
   g.GetOS()->Del(this);
}