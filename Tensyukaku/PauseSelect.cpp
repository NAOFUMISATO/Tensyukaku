/*****************************************************************//**
 * \file   PauseSelect.cpp
 * \brief  ポーズセレクトクラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "PauseSelect.h"
#include "Game.h"
#include "ModeTitle.h"
#include "ModeGame.h"
#include "OverlayBlack.h"
#include "ResourceServer.h"
#include "ObjectBase.h"

bool PauseSelect::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 960;                       //X座標の初期化
   _y = 850;                       //Y座標の初期化
   _graph_no = 0;                  //シート番号０で初期化
   _state = SELECTSTATE::NOSELECT; //何も選択していない状態で初期化
   _trans_flag = true;             //背景透過フラグを真で初期化
   _input_flag = true;             //入力受付フラグを真で初期化
   //画像読み込み
   _grall["PSelect"].resize(3);
   ResourceServer::LoadDivGraph("res/Mode/PauseSelect.png",3,3,1,1230,275,_grall["PSelect"].data());
   //SE読み込み
   _se["Select"] = ResourceServer::LoadSoundMem("se/OutGame/OtherSelectPush.wav");
   _se["Push"] = ResourceServer::LoadSoundMem("se/OutGame/GameStartPush.wav");
   //SE音量初期化
   _vpal["Select"] = 125;
   _vpal["Push"] =200;
   return true;
}

bool PauseSelect::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}

bool PauseSelect::Process(Game& g) {
   base::Process(g);
   //SE音量変更
   ChangeVolumeSoundMem(_vpal["Select"], _se["Select"]);
   ChangeVolumeSoundMem(_vpal["Push"], _se["Push"]);
   auto frame = _cnt - _mode_cnt;
   auto fadeoutframe = 60;
   _grhandle = _grall["PSelect"][_anime["PSelect"]];
   _anime["PSelect"] = _graph_no;
   /*-----各状態毎の処理-----*/
   switch (_state) {
      //何も選択していない状態
   case SELECTSTATE::NOSELECT:
      _graph_no = 0;
      //左入力したならリトライ選択状態へ移行
      if (g.GetTrg() & PAD_INPUT_LEFT) {
         //SE再生
         PlaySoundMem(_se["Select"],DX_PLAYTYPE_BACK,true);
         _state = SELECTSTATE::RETURNSELECT;
      }
      //右入力したならリトライ選択状態へ移行
      if (g.GetTrg() & PAD_INPUT_RIGHT) {
         //SE再生
         PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
         _state = SELECTSTATE::GOTITLESELECT;
      }
      break;
      //ゲームに戻る選択状態
   case SELECTSTATE::RETURNSELECT:
      _graph_no = 1;
      //3ボタン押下した且つ、入力受付フラグが真なら処理する
      if (g.GetTrg() & PAD_INPUT_3&&_input_flag==true) {
         //SE再生
         PlaySoundMem(_se["Push"], DX_PLAYTYPE_BACK, true);
         _input_flag = false;
         _mode_cnt = _cnt;
      }
      //押下と同時にアクションを行わないために1フレーム空けて処理する
      if (frame == 1 && _input_flag == false) {
         g.GetMS()->Del(this);                            //このモードの削除
         g.GetMS()->Del(g.GetMS()->Get("Pause"));         //ポーズモード削除
         g.GetMS()->Del(g.GetMS()->Get("PController"));   //ポーズ画面用コントローラーを削除
         auto mg = (ModeGame*)g.GetMS()->Get("Game");
         mg->SetStopObjProcess(false);                    //モードゲームの処理を再開
      }
      //右入力した且つ、入力受付フラグが真ならリトライ選択状態へ移行
      if (g.GetTrg() & PAD_INPUT_RIGHT && _input_flag == true) {
         //SE再生
         PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
         _state = SELECTSTATE::GOTITLESELECT;
      }
      break;
      //タイトル選択状態
   case SELECTSTATE::GOTITLESELECT:
      _graph_no = 2;
      //3ボタン押下した且つ、入力受付フラグが真なら処理する
      if (g.GetTrg() & PAD_INPUT_3&&_input_flag==true) {
         //SE再生
         PlaySoundMem(_se["Push"], DX_PLAYTYPE_BACK, true);
         _input_flag =false;
         _mode_cnt = _cnt;
         g.GetMS()->Del(g.GetMS()->Get("Flame"));         //炎演出モードの削除
         auto ob = new OverlayBlack();                    //フェードアウトの為の、オーバレイブラックモード生成
         ob->SetFade(fadeoutframe,180, 240, 5);           //フェード時間の設定
         g.GetMS()->Add(ob, 30, "OverlayBlack");
      }
      //押下より一定フレーム経過後、処理する
      if (frame == fadeoutframe && _input_flag == false) {
         g.GetMS()->Del(this);                            //このモードの削除
         g.GetMS()->Del(g.GetMS()->Get("PController"));   //説明画面用コントローラー削除
         g.GetMS()->Del(g.GetMS()->Get("Pause"));         //モードポーズ削除
         auto mg = (ModeGame*)g.GetMS()->Get("Game");
         mg->SetStopObjProcess(false);                    //ゲームの処理を再開する
         TutorialDel(g);                                  //チュートリアルボードに当たっていたならモードチュートリアルを削除する
         g.GetMS()->Del(g.GetMS()->Get("Game"));          //モードゲームを削除する
         auto mt = new ModeTitle();                       //モードタイトル生成
         mt->SetTitlebg();                                //タイトル状態をタイトル背景に設定
         g.GetMS()->Add(mt, 0, "Title");
         //各音源の停止
         StopSoundMem(g.GetBgm()["Main"]);
         StopSoundMem(g.GetBgm()["Flame"]);
         StopSoundMem(g.GetBgm()["Boss"]);
      }
      //左入力した且つ、入力受付フラグが真ならリトライ選択状態へ移行
      if(g.GetTrg() & PAD_INPUT_LEFT && _input_flag == true) {
         PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
         _state = SELECTSTATE::RETURNSELECT;
      }
      break;
   }
   return true;
}

bool PauseSelect::Draw(Game& g) {
   base::Draw(g);
   return true;
}

void PauseSelect::TutorialDel(Game& g) {
    g.GetMS()->Del(g.GetMS()->Get("1A"));
    g.GetMS()->Del(g.GetMS()->Get("1B"));
    g.GetMS()->Del(g.GetMS()->Get("2A"));
    g.GetMS()->Del(g.GetMS()->Get("3A"));
    g.GetMS()->Del(g.GetMS()->Get("3B"));
    g.GetMS()->Del(g.GetMS()->Get("4A"));
    g.GetMS()->Del(g.GetMS()->Get("5A"));
}

