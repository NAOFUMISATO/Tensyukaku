/*****************************************************************//**
 * \file   ModeEpilogue.cpp
 * \brief  エピローグクラス（モードベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModeEpilogue.h"
#include "EpilogueText.h"
#include "ModeTitle.h"
#include "Game.h"
#include "ResourceServer.h"

using namespace EpiInfo;
/*------初期化-------*/
bool ModeEpilogue::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;														//X座標の初期化
	_y = 540;														//Y座標の初期化
	_pal = 0;														//フェードインしていくため、透明度0で初期化
	_mode_cnt = _cnt;									//フレームで初期化
	_grhandle=ResourceServer::LoadGraph("res/Mode/Epilogue.png");				//画像読み込み
	PlaySoundMem(g.GetBgm()["Epilogue"], DX_PLAYTYPE_LOOP, true);			//BGM再生
	return true;
}

bool ModeEpilogue::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
/*------更新-------*/
bool ModeEpilogue::Process(Game& g) {
	base::Process(g);
	auto frame = _cnt - _mode_cnt;
	//フェードインの処理
	if(frame < BG_FADEIN_FRAME) {
		_pal += BG_FADEIN_SPEED;
	}
	if (frame == BG_FADEIN_FRAME) {
		_pal = 255;
		auto et = new EpilogueText();						//エピローグテキスト生成
		g.GetMS()->Add(et, 1, "PText");
	}
	//フェードアウトの処理
	if (frame >= BG_FADEOUT_BEGINFRAME && BG_FADEOUT_ENDFRAME > frame) {
		_pal -= BG_FADEOUT_SPEED;
	}
	if (frame == BG_FADEOUT_ENDFRAME) {
		_pal = 0;
		g.GetMS()->Del(g.GetMS()->Get("Epilogue"));			//エピローグテキストモードの削除
		StopSoundMem(g.GetBgm()["Epilogue"]);
		auto mt = new ModeTitle();													//タイトルモード生成
		mt->SetTitlebg();
		g.GetMS()->Add(mt, 0, "Title");
	}
	return true;
}
/*------描画-------*/
bool ModeEpilogue::Draw(Game& g) {
	base::Draw(g);
	return true;
}