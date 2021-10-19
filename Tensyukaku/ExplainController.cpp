/*****************************************************************//**
 * \file   ExplainController.cpp
 * \brief  説明画面用コントローラークラス（モードベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ExplainController.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ModeTitle.h"

bool ExplainController::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 960;                //Ｘ座標の初期化
   _y = 540;                //Ｙ座標の初期化
   _trans_flag = true;      //背景透過フラグを真で初期化
   _grhandle = ResourceServer::LoadGraph("res/Mode/EXController.png");   //画像読み込み
   return true;
}

bool ExplainController::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}

bool ExplainController::Process(Game& g) {
   base::Process(g);
   return true;
}

bool ExplainController::Draw(Game& g) {
   base::Draw(g);
   return true;
}