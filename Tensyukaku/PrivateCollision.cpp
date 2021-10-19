/*****************************************************************//**
 * \file   PrivateCollision.cpp
 * \brief  受け側で判定を取らない当たり判定クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "PrivateCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"

PrivateCollision::PrivateCollision(int x, int y,int hit_w,int hit_h) {
   _x = x;
   _y = y;
   _hit_w = hit_w;
   _hit_h = hit_h;
   Init();
}
PrivateCollision::~PrivateCollision() {
}

void PrivateCollision::Init() {
   _gx = 0;
   _gy = 0;
   _hit_x = 0;
   _hit_y = 0;
#ifdef _DEBUG
   _debug_alpha = 128;
   _debug_fill = true;
#endif
}