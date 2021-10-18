/*****************************************************************//**
 * \file   CreditRedReturn.cpp
 * \brief  赤ボタンガイドクラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Game.h"
#include "ResourceServer.h"
#include "CreditRedReturn.h"

/*-----------赤ボタンガイドクラス-------------*/
/*-----初期化------*/
bool CreditRedReturn::Initialize(Game& g) {
   _x = 1750;          //Ｘ座標の初期化
   _y = 980;           //Ｙ座標の初期化
   _pal = 255;         //透明度の初期化
   _trans_flag = true; //背景透過フラグを真で初期化
   _grhandle = ResourceServer::LoadGraph("res/Mode/RedReturn.png");   //画像読み込み
   return true;
}
/*-----終了------*/
bool CreditRedReturn::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}
/*-----更新------*/
bool CreditRedReturn::Process(Game& g) {
   base::Process(g);
   return true;
}
/*-----描画------*/
bool CreditRedReturn::Draw(Game& g) {
   SetDrawBlendMode(DX_BLENDMODE_ALPHA, _pal);
   DrawRotaGraph(_x, _y, 1.0, 0.0, _grhandle, _trans_flag, false);
   SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
   return true;
}