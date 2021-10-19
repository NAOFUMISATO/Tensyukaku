/*****************************************************************//**
 * \file   ModePause.cpp
 * \brief  インゲームでのポーズ画面クラス（モードベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModePause.h"
#include "ModeGame.h"
#include "PauseSelect.h"
#include "PauseController.h"
#include "Game.h"
#include "ResourceServer.h"

bool ModePause::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 960;           //X座標の初期化
   _y = 540;           //Y座標の初期化
   _pal = 200;         //透明度の初期化
   _mode_cnt = _cnt;   //フレームの初期化
   _grhandle = ResourceServer::LoadGraph("res/Mode/Black.png");         //画像読み込み（ぼかし処理のため、黒背景）
   _se["Appear"] = ResourceServer::LoadSoundMem("se/OutGame/Pause.wav");//SE読み込み
   _vpal["Appear"] = 255;                                               //SE音量初期化
   ChangeVolumeSoundMem(_vpal["Appear"], _se["Appear"]);                //SE音量変更
   PlaySoundMem(_se["Appear"], DX_PLAYTYPE_BACK, true);                 //SE再生
   auto ps = new PauseSelect();      //ポーズセレクト生成
   g.GetMS()->Add(ps, 25, "PSelect");   
   auto pc = new PController();      //ポーズ画面用コントローラー生成
   g.GetMS()->Add(pc, 25, "PController");
   return true;
}

bool ModePause::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}

bool ModePause::Process(Game& g) {
   base::Process(g);
   return true;
}

bool ModePause::Draw(Game& g) {
   base::Draw(g);
   return true;
}