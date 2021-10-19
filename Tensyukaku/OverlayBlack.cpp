/*****************************************************************//**
 * \file   OverlayBlack.cpp
 * \brief  フェードアウトフェードインのための黒背景クラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "OverlayBlack.h"
#include "Game.h"
#include "ResourceServer.h"

bool OverlayBlack::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 960;           //X座標の初期化
   _y = 540;           //Y座標の初期化
   _pal = 0;           //フェードインしていくため、透明度0で初期化
   _mode_cnt = _cnt;   //フレームの初期化
   _grhandle=ResourceServer::LoadGraph("res/Mode/Black.png"); //画像読み込み
   return true;
}

bool OverlayBlack::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}

void OverlayBlack::SetFade(int fadeoutframe,int fadeinbeginframe,int fadeinendframe, int fadespeed) {
   _fadeout_frame= fadeoutframe;
   _fadein_beginframe = fadeinbeginframe;
   _fadein_endframe = fadeinendframe;
   _fade_speed = fadespeed;
}

bool OverlayBlack::Process(Game& g) {
   base::Process(g);
   auto frame = _cnt - _mode_cnt;
   //フェードの処理
   if (frame >= 0 && _fadeout_frame >frame) {
      _pal += _fade_speed;
   }
   if (frame == _fadeout_frame) {
      _pal = 255;
   }
   if (frame >= _fadein_beginframe && _fadein_endframe > frame) {
      _pal -= _fade_speed;
   }
   if (frame == _fadein_endframe) {
      _pal = 0;
      g.GetMS()->Del(this);
   }
   return true;
}

bool OverlayBlack::Draw(Game& g) {
   base::Draw(g);
   return true;
}