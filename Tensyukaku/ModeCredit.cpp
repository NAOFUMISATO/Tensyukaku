/*****************************************************************//**
 * \file   ModeCredit.cpp
 * \brief  クレジットクラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModeCredit.h"
#include "Game.h"
#include "Player.h"
#include "ModeTitle.h"
#include "ResourceServer.h"
#include "OverlayBlack.h"
#include "CreditLeftGuide.h"
#include "CreditRedReturn.h"

using namespace CrInfo;
/*-----初期化------*/
bool ModeCredit::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 2880;               //X座標初期化
   _y = 1080;               //Y座標初期化
   _pal = 0;                //フェードインしていくため、透明度0で初期化
   _mode_cnt = _cnt;        //フレームの初期化
   _leftmove_flag = false;  //クレジットのページをめくるフラグ（左へ移動用）
   _rightmove_flag = false; //クレジットのページをめくるフラグ（右へ移動用）
   _start_flag = true;      //クレジットモードの開始フラグを真で初期化
   _end_flag = false;       //クレジットモードの終了フラグを偽で初期化
   _grhandle=ResourceServer::LoadGraph("res/Mode/ModeCredit.png");  //画像読みこみ
   //SE読み込み
   _se["CreditOpen"] = ResourceServer::LoadSoundMem("se/OutGame/CreditOpen.wav");
   _se["CreditMove"] = ResourceServer::LoadSoundMem("se/OutGame/CreditMove.wav");
   //SE音量初期化
   _vpal["CreditOpen"] = 200;   
   _vpal["CreditMove"] = 200;
   return true;
}
/*-----終了------*/
bool ModeCredit::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}
/*-----更新------*/
bool ModeCredit::Process(Game& g) {
   base::Process(g);
   //SEの音量変更
   ChangeVolumeSoundMem(_vpal["CreditOpen"], _se["CreditOpen"]);
   ChangeVolumeSoundMem(_vpal["CreditMove"], _se["CreditMove"]);
   auto frame = _cnt - _mode_cnt;
   if (frame == 1) {
      //SE再生
      PlaySoundMem(_se["CreditOpen"],DX_PLAYTYPE_BACK,true);
   }
   //フェードインの処理
   if (frame<FADE_FRAME&&_start_flag==true) {
      _pal += FADE_SPEED;
   }
   if (frame == FADE_FRAME && _start_flag == true) {
      auto gu = new CreditLeftGuide();         //左スティックガイドの生成
      g.GetMS()->Add(gu, 3, "Guide");
      auto rr = new CreditRedReturn();      //赤ボタンガイドの生成
      g.GetMS()->Add(rr, 3, "RedReturn");
      _start_flag = false;
   }
   //フェードアウトの処理
   if (frame == FADE_FRAME && _end_flag == true) {
      g.GetMS()->Del(this);
      auto mt = new ModeTitle();      //モードタイトル生成
      mt->SetTitlebg();   
      g.GetMS()->Add(mt, 0, "Title");
   }
   if (g.GetTrg() & PAD_INPUT_LEFT&&_x==960) {
      //SE再生
      PlaySoundMem(_se["CreditMove"], DX_PLAYTYPE_BACK, true);
      _leftmove_flag = true;
   }
   if (g.GetTrg() & PAD_INPUT_RIGHT && _x == 2880) {
      //SE再生
      PlaySoundMem(_se["CreditMove"], DX_PLAYTYPE_BACK, true);
      _rightmove_flag = true;
   }
   //4ボタン押下したなら各モード削除し、タイトルモード生成
   if (g.GetTrg() & PAD_INPUT_4) {
      _mode_cnt = _cnt;
      auto ol = new OverlayBlack();                 //フェードアウトのためのオーバーレイモード生成
      ol->SetFade(FADE_FRAME, 120,180, FADE_SPEED); //フェード時間の設定
      g.GetMS()->Add(ol, 2, "OverlayBlack");
      g.GetMS()->Del(g.GetMS()->Get("Guide"));      //左スティックガイド削除
      g.GetMS()->Del(g.GetMS()->Get("RedReturn"));  //赤ボタンガイド削除
      _end_flag = true;
   }
   if (_leftmove_flag == true) {
      if (_x < 2880) {
         _x += 60;
      }
      if (_x == 2880) {
         _leftmove_flag = false;
      }
   }
   if (_rightmove_flag == true) {
      if (_x > 960) {
         _x-= 60;
      }
      if (_x == 960) {
         _rightmove_flag = false;
      }
   }
   return true;
}
/*-----描画------*/
bool ModeCredit::Draw(Game& g) {
   auto posx = _x - 960;
   auto posy = _y - 540;
   SetDrawBlendMode(DX_BLENDMODE_ALPHA, _pal);
   DrawRotaGraph(posx, posy, 1.0, 0.0, _grhandle, _trans_flag, false);
   SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
   return true;
}