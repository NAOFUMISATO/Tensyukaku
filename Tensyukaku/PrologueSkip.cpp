/*****************************************************************//**
 * \file   PrologueSkip.cpp
 * \brief  スキップテキストクラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModePrologue.h"
#include "PrologueSkip.h"
#include "ModeGame.h"
#include "Game.h"
#include "OverlayBlack.h"
#include "ResourceServer.h"

using namespace ProInfo;

bool PrologueASkip::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 1700;          //X座標の初期化
   _y = 1030;          //Y座標の初期化
   _trans_flag = true; //背景透過フラグを真で初期化
   _mode_cnt = _cnt;   //フレームの初期化
   _grhandle = ResourceServer::LoadGraph("res/Mode/PrologueSkip.png");   //画像読み込み
   return true;
}

bool PrologueASkip::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}

bool PrologueASkip::Process(Game& g) {
   base::Process(g);
   auto frame = _cnt - _mode_cnt;
   //一定フレーム経ったらフェードアウト
   if (frame >= SKIP_FADEOUT_FRAME) {
      _pal -= SKIP_FADESPEED;
   }
   if (_pal == 0) {
      g.GetMS()->Del(this);    //このモードを削除
   }
   return true;
}

bool PrologueASkip::Draw(Game& g) {
   base::Draw(g);
   return true;
}
