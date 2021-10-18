/*****************************************************************//**
 * \file   PauseController.cpp
 * \brief  ポーズ画面に表示するコントローラークラス（モードベースクラスのサブクラス）
 * 
 * \author 0117H
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModeGame.h"
#include "PauseController.h"
#include "Game.h"
#include "ResourceServer.h"
/*-----------ポーズ画面用コントローラークラス-------------*/
/*-----初期化-----*/
bool PController::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 960;              //X座標の初期化
   _y = 400;              //Y座標の初期化
   _pal = 255;            //透明度の初期化
   _mode_cnt = _cnt;      //フレームの初期化
   _trans_flag = true;    //背景透過フラグを真で初期化
   _grhandle = ResourceServer::LoadGraph("res/Mode/PController.png");  //画像読み込み
   return true;
}
/*-----終了------*/
bool PController::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}
/*-----更新-----*/
bool PController::Process(Game& g) {
   base::Process(g);
   return true;
}
/*-----描画-----*/
bool PController::Draw(Game& g) {
   base::Draw(g);
   return true;
}
