/*****************************************************************//**
 * \file   ModeIngameText.cpp
 * \brief  インゲームでの階層表示クラス（モードベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ResourceServer.h"
#include "Game.h"
#include "ModeIngameText.h"
#include "ModeGame.h"

using namespace ITInfo;
/*-----初期化------*/
bool ModeIngameText::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 960;                       //X座標初期化
   _y = 250;                       //Y座標初期化
   _pal = 0;                       //フェードインしていくため、透明度０で初期化
   _fadein_frame = FADEIN_FRAME;   //階層によってフェードインフレームが異なるため、メンバ変数で初期化
   _fadeout_frame = FADEOUT_FRAME; //階層によってフェードアウトフレームが異なるため、メンバ変数で初期化
   _fade_speed=FADE_SPEED;         //階層によってフェードスピードが異なるため、メンバ変数で初期化
   _mode_cnt = _cnt;               //フレームの初期化
   _trans_flag = true;             //背景透過フラグを真で初期化
   LoadPicture();                  //画像読み込み
   return true;
}
/*-----終了------*/
bool ModeIngameText::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}
/*-----更新------*/
bool ModeIngameText::Process(Game& g) {
   base::Process(g);
   auto frame = _cnt - _mode_cnt;
   //各階層によって画像&フェード関係の変更
   if (_text_type == "TOP") {
      _grhandle = _grall["TOP"][0];
   }
   else if (_text_type == "UPPER") {
      _grhandle = _grall["UPPER"][0];
   }
   else if (_text_type == "MIDDLE") {
      _grhandle = _grall["MIDDLE"][0];
   }
   else if (_text_type == "UNDER") {
      _grhandle = _grall["UNDER"][0];
      _fadeout_frame = 80;
      _fade_speed = 6;
   }
   //フェードインの処理
   if (frame < _fadein_frame) {
      _pal += _fade_speed;
   }
   if (frame == _fadein_frame) {
      _pal = 255;
   }
   //フェードアウトの処理
   if (frame >= _fadeout_frame&&_pal>0) {
      _pal -= _fade_speed;
   }
   if (frame >= _fadeout_frame && _pal <= 0) {
      g.GetMS()->Del(this);
   }
   return true;
}
/*-----描画------*/
bool ModeIngameText::Draw(Game& g) {
   base::Draw(g);
   return true;
}
//画像読み込み関数
void  ModeIngameText::LoadPicture() {
   _grall["TOP"].resize(1);
   ResourceServer::LoadDivGraph("res/Mode/IngameText04.png", 1, 1, 1,GRAPH_WIDTH,GRAPH_HEIGHT,_grall["TOP"].data());
   _grall["UPPER"].resize(1);
   ResourceServer::LoadDivGraph("res/Mode/IngameText03.png", 1, 1, 1, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["UPPER"].data());
   _grall["MIDDLE"].resize(1);
   ResourceServer::LoadDivGraph("res/Mode/IngameText02.png", 1, 1, 1, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["MIDDLE"].data());
   _grall["UNDER"].resize(1);
   ResourceServer::LoadDivGraph("res/Mode/IngameText01.png", 1, 1, 1, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["UNDER"].data());
}
