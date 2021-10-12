/*****************************************************************//**
 * \file   Overlogo.cpp
 * \brief  ゲームオーバーロゴクラス（モードベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ResourceServer.h"
#include "Overlogo.h"

namespace {
	constexpr auto FADEIN_FRAME = 60;
	constexpr auto FADE_SPEED = 4;
}
/*-----初期化-----*/
bool Overlogo::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;						//X座標の初期化
	_y = 450;						//Y座標の初期化
	_pal = 0;							//フェードインしていくため、透明度０で初期化
	_mode_cnt = _cnt;		//フレームの初期化
	_trans_flag = true;			//背景透過フラグを真で初期化
	_grhandle = ResourceServer::LoadGraph("res/Mode/OverLogo.png");		//画像読み込み
	return true;
}
/*-----終了------*/
bool Overlogo::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
/*-----更新-----*/
bool Overlogo::Process(Game& g) {
	base::Process(g);
	auto frame = _cnt - _mode_cnt;
	//フェードインの処理
	if (frame < FADEIN_FRAME) {
		_pal += FADE_SPEED;
	}
	if (frame == FADEIN_FRAME) {
		_pal = 255;
	}
	return true;
}
/*-----描画-----*/
bool Overlogo::Draw(Game& g) {
	base::Draw(g);
	return true;
}
