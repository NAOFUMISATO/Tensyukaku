/*****************************************************************//**
 * \file   OverlayBlack.cpp
 * \brief  フェードアウトフェードインのための黒背景クラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "OverlayBlack.h"
#include "Game.h"
#include "ResourceServer.h"

/*-----初期化-----*/
bool OverlayBlack::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;								//X座標の初期化
	_y = 540;								//Y座標の初期化
	_pal = 0;									//フェードインしていくため、透明度0で初期化
	_mode_cnt = _cnt;				//フレームの初期化
	_grhandle=ResourceServer::LoadGraph("res/Mode/Black.png");		//画像読み込み
	return true;
}
/*-----終了------*/
bool OverlayBlack::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
//フェード時間を設定する関数
void OverlayBlack::SetFade(int fadeoutframe,int fadeinbeginframe,int fadeinendframe, int fadespeed) {
	_Fadeoutframe= fadeoutframe;
	_FadeinBeginframe = fadeinbeginframe;
	_FadeinEndframe = fadeinendframe;
	_fade_speed = fadespeed;
}
/*-----更新-----*/
bool OverlayBlack::Process(Game& g) {
	base::Process(g);
	auto frame = _cnt - _mode_cnt;
	//フェードの処理
	if (frame >= 0 && _Fadeoutframe >frame) {
		_pal += _fade_speed;
	}
	if (frame == _Fadeoutframe) {
		_pal = 255;
	}
	if (frame >= _FadeinBeginframe && _FadeinEndframe > frame) {
		_pal -= _fade_speed;
	}
	if (frame == _FadeinEndframe) {
		_pal = 0;
		g.GetMS()->Del(this);
	}
	return true;
}
/*-----描画-----*/
bool OverlayBlack::Draw(Game& g) {
	base::Draw(g);
	return true;
}