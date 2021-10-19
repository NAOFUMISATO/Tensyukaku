/*****************************************************************//**
 * \file   OverSelect.cpp
 * \brief  ゲームオーバーセレクトクラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "OverSelect.h"
#include "Game.h"
#include "ModeTitle.h"
#include "ModeGame.h"
#include "ResourceServer.h"
#include "OverlayBlack.h"

namespace {
   constexpr auto FADEIN_FRAME = 60;
   constexpr auto FADE_SPEED = 4;
}

bool OverSelect::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 960;                       //X座標の初期化
   _y = 850;                       //Y座標の初期化
   _pal = 0;                       //フェードインしていくため、透明度0で初期化
   _graph_no = 0;                  //シート番号０で初期化
   _state = SELECTSTATE::NOSELECT; //何も選択していない状態で初期化
   _trans_flag = true;             //背景透過フラグを真で初期化
   _input_flag = true;             //入力受付フラグを真で初期化
   _grall["PSelect"].resize(3);
   ResourceServer::LoadDivGraph("res/Mode/OverSelect.png", 3, 3, 1, 1230, 275, _grall["PSelect"].data()); //画像読み込み
   //SE読み込み
   _se["Select"] = ResourceServer::LoadSoundMem("se/OutGame/OtherSelectPush.wav");
   _se["Push"] = ResourceServer::LoadSoundMem("se/OutGame/GameStartPush.wav");
   //SE音量初期化
   _vpal["Select"] = 125;
   _vpal["Push"] = 200;
   return true;
}

bool OverSelect::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}

bool OverSelect::Process(Game& g) {
   base::Process(g);
   //SE音量変更
   ChangeVolumeSoundMem(_vpal["Select"], _se["Select"]);
   ChangeVolumeSoundMem(_vpal["Push"], _se["Push"]);
   auto frame = _cnt - _mode_cnt;
   auto fadeoutframe = 60;
   _grhandle = _grall["PSelect"][_anime["PSelect"]];
   _anime["PSelect"] = _graph_no;
   //フェードインの処理
   if (frame < FADEIN_FRAME) {
      _pal += FADE_SPEED;
   }
   if (frame == FADEIN_FRAME) {
      _pal = 255;
   }
   /*-----各状態毎の処理-----*/
   switch (_state) {
   //何も選択していない状態
   case SELECTSTATE::NOSELECT:
      _graph_no = 0;
      //フェードが終わったなら中の処理を受け付ける
      if (frame > FADEIN_FRAME) {
         //左入力したならリトライ選択状態へ移行
         if (g.GetTrg() & PAD_INPUT_LEFT) {
            //SE再生
            PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
            _state = SELECTSTATE::RETRYSELECT;
         }
         //右入力したならタイトル選択状態へ移行
         if (g.GetTrg() & PAD_INPUT_RIGHT) {
            //SE再生
            PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
            _state = SELECTSTATE::GOTITLESELECT;
         }
      }
      break;
      //リトライ選択状態
   case SELECTSTATE::RETRYSELECT:
      _graph_no = 1;
      //3ボタン押下した且つ、入力受付フラグが真なら処理する
      if (g.GetTrg() & PAD_INPUT_3&&_input_flag==true) {
         //SE再生
         PlaySoundMem(_se["Push"], DX_PLAYTYPE_BACK, true);
         _mode_cnt = _cnt;
         _input_flag = false;
         auto ob = new OverlayBlack();          //フェードアウトのためのオーバーレイブラックモード生成
         ob->SetFade(fadeoutframe, 90, 150, 5); //フェード時間の設定
         g.GetMS()->Add(ob, 5, "OverlayBlack");
      }
      //押下より、一定フレーム経ったなら処理する
      if (frame == fadeoutframe) {
         g.GetMS()->Del(this);                      //このモードを削除する
         g.GetMS()->Del(g.GetMS()->Get("Gameover"));//ゲームオーバーモードを削除する
         g.GetMS()->Del(g.GetMS()->Get("OverLogo"));//ゲームオーバーロゴを削除する
         g.GetMS()->Del(g.GetMS()->Get("Game"));    //モードゲームを削除する
         auto mg = new ModeGame();                  //モードゲーム生成
         g.GetMS()->Add(mg, 0, "Game");
      }
      //右入力した且つ、入力受付フラグが真ならタイトル選択状態へ移行
      if (g.GetTrg() & PAD_INPUT_RIGHT && _input_flag == true) {
         PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
         _state = SELECTSTATE::GOTITLESELECT;
      }
      break;
      //タイトル選択状態
   case SELECTSTATE::GOTITLESELECT:
      _graph_no = 2;
      //3ボタン押下した且つ、入力受付フラグが真なら処理する
      if (g.GetTrg() & PAD_INPUT_3 && _input_flag == true) {
         //SE再生
         PlaySoundMem(_se["Push"], DX_PLAYTYPE_BACK, true);
         _mode_cnt = _cnt;
         _input_flag = false;
         auto ob =new OverlayBlack();          //フェードアウトのためのオーバーレイブラックモード生成
         ob->SetFade(fadeoutframe, 70, 70, 4); //フェード時間の設定
         g.GetMS()->Add(ob, 5, "OverlayBlack");
      }
      //押下より、一定フレーム経ったなら処理する
      if (frame== fadeoutframe) {
         g.GetMS()->Del(this);                      //このモードを削除する
         g.GetMS()->Del(g.GetMS()->Get("OverLogo"));//ゲームオーバーモードを削除する
         g.GetMS()->Del(g.GetMS()->Get("Gameover"));//ゲームオーバーロゴを削除する
         g.GetMS()->Del(g.GetMS()->Get("Game"));    //モードゲームを削除する
         auto mt = new ModeTitle();                 //モードタイトル生成
         mt->SetTitlebg();                          //モードタイトル状態をタイトル背景に設定
         g.GetMS()->Add(mt, 0, "Title");
      }
      //左入力した且つ、入力受付フラグが真ならタイトル選択状態へ移行
      if (g.GetTrg() & PAD_INPUT_LEFT && _input_flag == true) {
         PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
         _state = SELECTSTATE::RETRYSELECT;
      }
      break;
   }
   return true;
}

bool OverSelect::Draw(Game& g) {
   base::Draw(g);
   return true;
}

