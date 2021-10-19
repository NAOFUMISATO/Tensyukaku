/*****************************************************************//**
 * \file   FlameBlock.cpp
 * \brief  炎演出ブロッククラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include "FlameBlock.h"
#include "Game.h"
namespace {
   constexpr auto GRAPHPOINT_X = 0;       //!< X位置から描画点までの差分
   constexpr auto GRAPHPOINT_Y = -50;     //!< Y位置から描画点までの差分
   constexpr auto POSITION_HITX = -50;    //!< 描画点から当たり判定左上座標までの差分
   constexpr auto POSITION_HITY = -50;    //!< 描画点から当たり判定左上座標までの差分
   constexpr auto COLLISION_WIDTH = 100;  //!< 階段の当たり判定横幅
   constexpr auto COLLISION_HEIGHT = 100; //!< 階段の当たり判定縦幅
}

FlameBlock::FlameBlock(int x, int y) {
   _x = x;
   _y = y;
   Init();
}
FlameBlock::~FlameBlock() {
};

void FlameBlock::Init() {
   _gx = GRAPHPOINT_X;
   _gy = GRAPHPOINT_Y;
   _hit_x = POSITION_HITX;
   _hit_y = POSITION_HITY;
   _hit_w = COLLISION_WIDTH;
   _hit_h = COLLISION_HEIGHT;
#ifdef _DEBUG
   _debug_color = std::make_tuple(255, 0, 0);
   _debug_alpha = 128;
   _debug_fill = true;
#endif
}
void  FlameBlock::Draw(Game& g) {
   ObjectBase::Draw(g);
}

void FlameBlock::Delete(Game& g) {
   g.GetOS()->Del(this);
}