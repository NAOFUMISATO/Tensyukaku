/*****************************************************************//**
 * \file   PrologueText.cpp
 * \brief  プロローグテキストクラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModePrologue.h"
#include "PrologueText.h"
#include "ModeGame.h"
#include "Game.h"
#include "PrologueSkip.h"
#include "OverlayBlack.h"
#include "ResourceServer.h"

using namespace ProInfo;
/*----プロローグテキストクラス-----*/
/*---初期化---*/
bool PrologueText::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 1600;          //X座標の初期化
   _y = 540;           //Y座標の初期化
   _pal = 0;           //フェードインしていくため、透明度０で初期化
   _graph_no = 0;      //シート番号０で初期化
   _mode_cnt = _cnt;   //フレームの初期化
   _trans_flag = true; //背景透過フラグを真で初期化
   _skip_flag = false; //スキップボタン押下したかのフラグを偽で初期化
   //画像読み込み
   _grall["PText"].resize(TEXT_ANIMEMAX);
   ResourceServer::LoadDivGraph(TEXT_GRAPHNAME, TEXT_ANIMEMAX, TEXT_WIDTHCOUNT, TEXT_HEIGHTCOUNT, TEXT_GRAPH_WIDTH, TEXT_GRAPH_HEIGHT, _grall["PText"].data());
   LoadSE();           //SE読み込み
   VolumeInit();       //SE音量初期化
   PlaySoundMem(_se["Text1"], DX_PLAYTYPE_BACK, true);   //テキスト1再生
   return true;
}
/*-----終了------*/
bool PrologueText::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}
/*---更新---*/
bool PrologueText::Process(Game& g) {
   base::Process(g);
   VolumeChange();         //SE音量変更
   auto frame = _cnt - _mode_cnt;
   _grhandle = _grall["PText"][_anime["PText"]];
   _anime["PText"] = _graph_no;
   /*-----各テキストのフェードイン、フェードアウト処理-----*/
   //テキスト1
   //スキップボタン押下フラグが偽なら処理をする
   if (_skip_flag == false) {
      if (frame < TEXT1_FADEIN_FRAME) {
         _pal += TEXT_FADE_SPEED;
      }
      if (frame == TEXT1_FADEIN_FRAME) {
         _pal = 255;
         auto as = new PrologueASkip();      //スキップテキスト生成
         g.GetMS()->Add(as, 1, "PASkip");
      }
      if (frame >= TEXT1_FADEOUT_BEGINFRAME && TEXT1_FADEOUT_ENDFRAME > frame) {
         _pal -= TEXT_FADE_SPEED;
      }
      if (frame == TEXT1_FADEOUT_ENDFRAME) {
         _pal = 0;
         _graph_no = 1;
      }
      //テキスト2
      if (frame == TEXT2_FADEIN_BEGINFRAME) {
         //ボイス再生
         PlaySoundMem(_se["Text2"], DX_PLAYTYPE_BACK, true);
      }
      if (frame >= TEXT2_FADEIN_BEGINFRAME && TEXT2_FADEIN_ENDFRAME > frame) {
         _pal += TEXT_FADE_SPEED;
      }
      if (frame == TEXT2_FADEIN_ENDFRAME) {
         _pal = 255;
      }
      if (frame >= TEXT2_FADEOUT_BEGINFRAME && TEXT2_FADEOUT_ENDFRAME > frame) {
         _pal -= TEXT_FADE_SPEED;
      }
      if (frame == TEXT2_FADEOUT_ENDFRAME) {
         _pal = 0;
         _graph_no = 2;
      }
      //テキスト3
      if (frame == TEXT3_FADEIN_BEGINFRAME) {
         //ボイス再生
         PlaySoundMem(_se["Text3"], DX_PLAYTYPE_BACK, true);
      }
      if (frame >= TEXT3_FADEIN_BEGINFRAME && TEXT3_FADEIN_ENDFRAME > frame) {
         _pal += TEXT_FADE_SPEED;
      }
      if (frame == TEXT3_FADEIN_ENDFRAME) {
         _pal = 255;
      }
      if (frame >= TEXT3_FADEOUT_BEGINFRAME && TEXT3_FADEOUT_ENDFRAME > frame) {
         _pal -= TEXT_FADE_SPEED;
      }
      if (frame == TEXT3_FADEOUT_ENDFRAME) {
         _pal = 0;
         _graph_no = 3;
      }
      //テキスト4
      if (frame == TEXT4_FADEIN_BEGINFRAME) {
         //ボイス再生
         PlaySoundMem(_se["Text4"], DX_PLAYTYPE_BACK, true);
      }
      if (frame >= TEXT4_FADEIN_BEGINFRAME && TEXT4_FADEIN_ENDFRAME > frame) {
         _pal += TEXT_FADE_SPEED;
      }
      if (frame == TEXT4_FADEIN_ENDFRAME) {
         _pal = 255;
      }
      if (frame >= TEXT4_FADEOUT_BEGINFRAME && TEXT4_FADEOUT_ENDFRAME > frame) {
         _pal -= TEXT_FADE_SPEED;
      }
      if (frame == TEXT4_FADEOUT_ENDFRAME) {
         _pal = 0;
         _x = 1500;
         _y = 850;
         _graph_no = 4;
      }
      //テキスト5
      if (frame == TEXT5_FADEIN_BEGINFRAME) {
         //ボイス再生
         PlaySoundMem(_se["Text5"], DX_PLAYTYPE_BACK, true);
      }
      if (frame >= TEXT5_FADEIN_BEGINFRAME && TEXT5_FADEIN_ENDFRAME > frame) {
         _pal += TEXT_FADE_SPEED;
      }
      if (frame == TEXT5_FADEIN_ENDFRAME) {
         _pal = 255;
      }
      if (frame >= TEXT5_FADEOUT_BEGINFRAME && TEXT5_FADEOUT_ENDFRAME > frame) {
         _pal -= TEXT_FADE_SPEED;
      }
      if (frame == TEXT5_FADEOUT_ENDFRAME) {
         _pal = 0;
         g.GetMS()->Del(this);   //このモードを削除
      }
   }
   /*---ボタン押下によるスキップ---*/
   auto fadeoutframe =85;
   //3ボタンを押下した且つ、スキップ押下フラグが偽ならば処理する
   if (g.GetTrg() & PAD_INPUT_3&&_skip_flag==false) {
      _mode_cnt = _cnt;
      _skip_flag = true;
      auto ol = new OverlayBlack();          //フェードアウトのためのモードオーバーレイブラック生成
      ol->SetFade(fadeoutframe, 480, 600, 4);//フェード時間の設定
      g.GetMS()->Add(ol, 2, "OverlayBlack");
   }
   //押下から一定フレーム以内ならば処理する
   if (frame >= 0 && frame < fadeoutframe && _skip_flag == true) {
      //スキップ時の音源のフェードアウト
      auto vpal = g.GetVpal();
      vpal["Prologue"] -= 1;
      g.SetVpal(vpal);
      _vpal["Text1"]-=4;
      _vpal["Text2"]-=4;
      _vpal["Text3"]-=4;
      _vpal["Text4"]-=4;
      _vpal["Text5"]-=4;
   }
   //押下より一定フレーム後、処理する
   if (frame == fadeoutframe&& _skip_flag == true) {
      //各音源の停止
      StopSoundMem(_se["Text1"]);
      StopSoundMem(_se["Text2"]);
      StopSoundMem(_se["Text3"]);
      StopSoundMem(_se["Text4"]);
      StopSoundMem(_se["Text5"]);
      StopSoundMem(g.GetBgm() ["Prologue"]);
      g.GetMS()->Del(g.GetMS()->Get("PASkip"));   //スキップテキスト削除
      g.GetMS()->Del(g.GetMS()->Get("Prologue")); //プロローグモード削除
      g.GetMS()->Del(this);                       //このモードを削除
      auto mg = new ModeGame();                   //モードゲーム生成
      g.GetMS()->Add(mg, 0, "Game");
   }
   return true;
}
/*---描画---*/
bool PrologueText::Draw(Game& g) {
   base::Draw(g);
   return true;
}

//SE読み込み関数
void PrologueText::LoadSE() {
   _se["Text1"] = ResourceServer::LoadSoundMem("se/Voice/Prologue01.wav");
   _se["Text2"] = ResourceServer::LoadSoundMem("se/Voice/Prologue02.wav");
   _se["Text3"] = ResourceServer::LoadSoundMem("se/Voice/Prologue03.wav");
   _se["Text4"] = ResourceServer::LoadSoundMem("se/Voice/Prologue04.wav");
   _se["Text5"] = ResourceServer::LoadSoundMem("se/Voice/Prologue05.wav");
}

//ボリューム初期値設定関数
void PrologueText::VolumeInit() {
   _vpal["Text1"]=255;
   _vpal["Text2"]=255;
   _vpal["Text3"]=255;
   _vpal["Text4"]=255;
   _vpal["Text5"]=255;
}
//ボリューム変更関数
void PrologueText::VolumeChange() {
   ChangeVolumeSoundMem(_vpal["Text1"],_se["Text1"]);
   ChangeVolumeSoundMem(_vpal["Text2"], _se["Text2"]);
   ChangeVolumeSoundMem(_vpal["Text3"], _se["Text3"]);
   ChangeVolumeSoundMem(_vpal["Text4"], _se["Text4"]);
   ChangeVolumeSoundMem(_vpal["Text5"], _se["Text5"]);
}
