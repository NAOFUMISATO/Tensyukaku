/*****************************************************************//**
 * \file   CreditLeftGuide.cpp
 * \brief  左スティックガイドボタンクラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Game.h"
#include "ResourceServer.h"
#include "CreditLeftGuide.h"

/*-----------左スティックガイドボタンクラス-------------*/
/*-----初期化------*/
bool CreditLeftGuide::Initialize(Game& g) {
   _x = 1800;          //Ｘ座標の初期化
   _y = 100;           //Ｙ座標の初期化
   _pal = 255;         //透明度の初期化
   _trans_flag = true; //背景透過フラグを真で初期化
   _grhandle = ResourceServer::LoadGraph("res/Mode/MoveGuide.png");   //画像読み込み
   return true;
}
/*-----終了------*/
bool CreditLeftGuide::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}
/*-----更新------*/
bool CreditLeftGuide::Process(Game& g) {
   base::Process(g);
   return true;
}
/*-----描画------*/
bool CreditLeftGuide::Draw(Game& g) {
   SetDrawBlendMode(DX_BLENDMODE_ALPHA, _pal);
   DrawRotaGraph(_x, _y, 1.0, 0.0, _grhandle, _trans_flag, false);
   SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
   return true;
}