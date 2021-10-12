/*****************************************************************//**
 * \file   OverlayFlame.cpp
 * \brief  インゲームでの炎演出クラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "OverlayFlame.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ModeBase.h"
#include "FlamePerformParticle.h"

using namespace FParInfo;
namespace {
	constexpr auto FADEIN_FRAME = 120;
	constexpr auto FADE_SPEED = 2;
	constexpr auto FADEOUT_FRAME = 120;
}
/*----初期化-----*/
bool OverlayFlame::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;							//X座標の初期化
	_y = 540;							//Y座標の初期化
	_pal = 0;								//フェードインしていくため、透明度0で初期化
	_mode_cnt = _cnt;			//フレームの初期化
	_trans_flag = true;				//背景透過フラグを真で初期化
	_grhandle = ResourceServer::LoadGraph("res/Mode/OverFlame.png");		//画像読み込み
	return true;
}
/*-----終了------*/
bool OverlayFlame::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
/*-----更新-----*/
bool OverlayFlame::Process(Game& g) {
	base::Process(g);
	auto frame = _cnt - _mode_cnt;
	//炎演出パーティクル発生
	if ((_cnt /10 %2) == 0) {
		for (int i = 0; i < FLAME_QTY; i++) {
			std::pair<int, int> xy = std::make_pair(_x, _y);
			std::pair<double, double> dxy = std::make_pair(((rand() % FLAME_RANDOMX1) - FLAME_RANDOMX2) / FLAME_RANDOMX3, ((rand() % -FLAME_RANDOMY1) - FLAME_RANDOMY2) / FLAME_RANDOMY3);
			auto fp = new FlamePerform(xy, dxy, true);
			g.GetOS()->Add(fp);
		}
	}
	if (frame >= 0 && FADEIN_FRAME > frame) {
		_pal += FADE_SPEED;
	}
	if (frame == FADEIN_FRAME) {
		_pal = 255;
	}
	return true;
}
/*-----描画-----*/
bool OverlayFlame::Draw(Game& g) {
	base::Draw(g);
	return true;
}