/*****************************************************************//**
 * \file   ObjectBase.cpp
 * \brief  各オブジェクトのベースクラス
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include "DxLib.h"
#include "ObjectBase.h"
#include "Game.h"

namespace {
   constexpr auto RED = 0;          //!< Tuple型可読性向上
   constexpr auto GREEN = 1;        //!< Tuple型可読性向上
   constexpr auto BLUE = 2;         //!< Tuple型可読性向上
   constexpr auto DRAW_LIMIT = 400; //!< 描画限界距離
}
ObjectBase::ObjectBase(){
   Init();
}

ObjectBase::~ObjectBase(){
}
/*----------初期化----------*/
void ObjectBase::Init()
{
   _grhandle = -1;   
   _cnt = 0;
   _hit_judge.first = 1;
   _hit_judge.second = 1;
   _drg.first = 1.0;
   _drg.second = 0.0;
   _debug_color = std::make_tuple(255,0,255);
   _debug_alpha = 128;
   _debug_fill = false;
   _bosseventA_flag=false;
   _bosseventB_flag=false;
   _draw_flag = false;
   _dx = 0;
   _dy = 0;
}
/*----------更新----------*/
void ObjectBase::Process(Game& g)
{
   //描画座標が画面+DRAW_LIMITの範囲に入っていなければ描画しないフラグの処理
   if (_dx > 0- DRAW_LIMIT && _dx < SCREEN_W+ DRAW_LIMIT &&_dy>0- DRAW_LIMIT && _dy < SCREEN_H+ DRAW_LIMIT) {
      _draw_flag =true;
   }
   else {
      _draw_flag = false;
   }
   //毎フレーム増加するカウンタ
   ++_cnt;
}
/*----------描画----------*/
void ObjectBase::Draw(Game& g) {
   
   //描画をマップチップの移動分ずらす
      auto GC = g.GetChip();
      auto x = _x + _gx - GC->GetscrX();
      auto y = _y + _gy - GC->GetscrY();
      auto scale = _drg.first;
      auto angle = _drg.second;
      //各当たり判定のために前回のxy座標をここで変数に保存する
      _before_x = _x;
      _before_y = _y ;
      //描画限界のためのxy座標をここで変数に保存
      _dx = x;
      _dy = y;
      //描画座標フラグが立っているならば描画する
      if (_draw_flag == true) {
      DrawRotaGraph(x,y, scale, angle, _grhandle, true, _isflip);
      }
#ifdef _DEBUG
      int& re = std::get<RED>(_debug_color);
      int& gr = std::get<GREEN>(_debug_color);
      int& bl = std::get<BLUE>(_debug_color);
      SetDrawBlendMode(DX_BLENDMODE_ALPHA, _debug_alpha);      // 半透明描画指定
      DrawBox(x + _hit_x, y + _hit_y, x + _hit_x + _hit_w, y + _hit_y + _hit_h, GetColor(re, gr, bl), _debug_fill);
#endif
      SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);      // 不透明描画指定
   
}
bool ObjectBase::IsHit(ObjectBase& o) {
   // このオブジェクトと、別オブジェクトoを、x,y,w,hで比較する
   if (_x +_gx+ _hit_x < o._x +o._hit_x + o._hit_w && o._x + o._hit_x < _x +_gx+ _hit_x + _hit_w                              // x方向の判定
      && _y +_gy+ _hit_y < o._y +o._gy + o._hit_y + o._hit_h && o._y+ o._gy+ o._hit_y < _y+_gy + _hit_y + _hit_h         // y方向の判定
      && _hit_judge.second == 1 && o._hit_judge.first == 1                                                                           // 自分と相手の当たり判定フラグ
      )
   {
      // 2つのboxは当たっている
      return true;
   }

   // 2つのboxは当たっていない
   return false;
}
