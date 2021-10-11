/*****************************************************************//**
 * \file   ModeGameover.cpp
 * \brief  モードゲームオーバークラス（モードベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModeGameover.h"
#include "ModeGame.h"
#include "OverlayBlack.h"
#include "OverSelect.h"
#include "OverLogo.h"
#include "Game.h"
#include "ResourceServer.h"

namespace {
	constexpr auto FADEIN_FRAME = 60;						//フェードインフレーム
	constexpr auto FADEIN_SPEED = 3;							//フェードインスピード
	constexpr auto OVERLAY_PAL = 200;						//ぼかし処理の透明度
	constexpr auto OVERSELECT_FRAME = 120;		//セレクト画面の表示フレーム
}
/*-----初期化-----*/
bool ModeGameover::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;									//X座標初期化
	_y = 540;									//Y座標初期化
	_pal = 0;									//フェードインしていくため、透明度０で初期化
	_mode_cnt = _cnt;				//フレームの初期化
	_grhandle = ResourceServer::LoadGraph("res/Mode/Black.png");													//画像読み込み（ぼかし処理のための黒背景）
	_se["GameOver"] = ResourceServer::LoadSoundMem("se/OutGame/GameOver.wav");		//SE読み込み
	_vpal["GameOver"] = 255;				//SE音量の初期化
	ChangeVolumeSoundMem(_vpal["GameOver"], _se["GameOver"]);				//SE音量の変更
	PlaySoundMem(_se["GameOver"], DX_PLAYTYPE_BACK, true);						//SE再生
	return true;
}

bool ModeGameover::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
/*-----更新-----*/
bool ModeGameover::Process(Game& g) {
	base::Process(g);
	auto frame = _cnt - _mode_cnt;
	//フェードインの処理
	if (frame < FADEIN_FRAME) {
		_pal += FADEIN_SPEED;
	}
	if (frame == FADEIN_FRAME) {
		_pal = OVERLAY_PAL;
		auto ol = new Overlogo();						//ゲームオーバーロゴの生成
		g.GetMS()->Add(ol, 3, "OverLogo");
	}
	if (frame == OVERSELECT_FRAME) {
		auto ps = new OverSelect();					//ゲームオーバーセレクトの生成
		g.GetMS()->Add(ps, 3, "PSelect");
	}
	return true;
}
/*-----描画-----*/
bool ModeGameover::Draw(Game& g) {
	base::Draw(g);
	return true;
}