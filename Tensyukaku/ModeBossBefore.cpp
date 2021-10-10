/*****************************************************************//**
 * \file   ModeBossBefore.cpp
 * \brief  ボスステージ前の1枚絵クラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModeGame.h"
#include "ModeBossBefore.h"
#include "OverlayBlack.h"
#include "Game.h"
#include "ResourceServer.h"

using namespace BBInfo;
/*-----初期化------*/
bool ModeBossBefore::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;							//X座標の初期化
	_y = 540;							//Y座標の初期化
	_mode_cnt = _cnt;		//フレームの初期化
	_grhandle = ResourceServer::LoadGraph("res/Mode/BossBefore.png");		//画像読み込み
	//SE読み込み
	_se["BossBefore"]=ResourceServer::LoadSoundMem("se/Voice/BossBefore.wav");	
	_se["BossFoot"] = ResourceServer::LoadSoundMem("se/Player/BBossFoot.wav");
	//SE音量初期化
	_vpal["BossBefore"] = 255;
	_vpal["BossFoot"] = 255;
	return true;
}

bool ModeBossBefore::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
/*-----更新------*/
bool ModeBossBefore::Process(Game& g) {
	base::Process(g);
	//SEの音量変更
	ChangeVolumeSoundMem(_vpal["BossBefore"], _se["BossBefore"]);
	ChangeVolumeSoundMem(_vpal["BossFoot"], _se["BossFoot"]);
	auto frame = _cnt - _mode_cnt;
	if (frame == FOOT_FRAME) {
		//SE再生
		PlaySoundMem(_se["BossFoot"], DX_PLAYTYPE_BACK, true);
	}
	if (frame == VOICE_FRAME) {
		//SE再生
		PlaySoundMem(_se["BossBefore"],DX_PLAYTYPE_BACK,true);
	}
	auto fadeoutendframe = 60;
	if (frame == FADEOUT_FRAME) {
		//画面遷移用フェードクラス生成
		auto ol = new OverlayBlack();
		ol->SetFade(fadeoutendframe, 80,140 , 5);
		g.GetMS()->Add(ol,10, "OverlayBlack");
	}
	if (frame == FADEOUT_FRAME + fadeoutendframe) {
		//モードゲームの処理を再開
		auto mg = (ModeGame*)g.GetMS()->Get("Game");
		//BGM再生
		PlaySoundMem(g.GetBgm()["Boss"], DX_PLAYTYPE_LOOP, true);
		mg->SetStopObjProcess(false);
		//このモードの削除
		g.GetMS()->Del(this);
	}
	return true;
}
/*-----描画-----*/
bool ModeBossBefore::Draw(Game& g) {
	base::Draw(g);
	return true;
}