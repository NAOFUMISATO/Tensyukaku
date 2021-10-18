/*****************************************************************//**
 * \file   ModeExPlain.cpp
 * \brief  タイトルでの説明画面クラス（モードベースのサブクラス）、説明画面用コントローラークラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModeExPlain.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ModeTitle.h"
 /*-----初期化------*/
bool ModeExPlain::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 960;      //X座標の初期化
   _y = 540;      //Y座標の初期化
   _cnt = 6;      //5フレームでモード削除のため、動作カウンタ6で初期化
   _grhandle = ResourceServer::LoadGraph("res/Mode/Black.png");   //ぼかし処理用の黒画像読み込み
   auto pc = new EXController();   //説明画面用コントローラークラスのインスタンス生成
   g.GetMS()->Add(pc, 3, "EXController");
   return true;
}
/*-----終了------*/
bool ModeExPlain::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}
/*-----更新------*/
bool ModeExPlain::Process(Game& g) {
   base::Process(g);
   auto frame = _cnt - _mode_cnt;
   //4ボタン押下でフレームリセット
   if (g.GetTrg() & PAD_INPUT_4) {
      _mode_cnt = _cnt;
   }
   //5フレーム経ったならモード削除、タイトルモードの処理を再開する
   if (frame == 5) {
      auto mt = (ModeTitle*)g.GetMS()->Get("Title");
      mt->SetStopObjProcess(false);
      g.GetMS()->Del(this);
      g.GetMS()->Del(g.GetMS()->Get("EXController"));
   }
   return true;
}
/*-----描画------*/
bool ModeExPlain::Draw(Game& g) {
   base::Draw(g);
   return true;
}

/*-----------説明画面用コントローラークラス-------------*/
 /*-----初期化------*/
bool EXController::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 960;                //Ｘ座標の初期化
   _y = 540;                //Ｙ座標の初期化
   _trans_flag = true;      //背景透過フラグを真で初期化
   _grhandle = ResourceServer::LoadGraph("res/Mode/EXController.png");   //画像読み込み
   return true;
}

bool EXController::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}
/*-----更新------*/
bool EXController::Process(Game& g) {
   base::Process(g);
   return true;
}
/*-----描画------*/
bool EXController::Draw(Game& g) {
   base::Draw(g);
   return true;
}