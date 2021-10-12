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
/*-----初期化-----*/
bool OverSelect::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;												//X座標の初期化
	_y = 850;												//Y座標の初期化
	_pal = 0;													//フェードインしていくため、透明度0で初期化
	_GraphNo = 0;										//シート番号０で初期化
	_Type = SELECTTYPE::NOSELECT;	//何も選択していない状態で初期化
	_trans_flag = true;									//背景透過フラグを真で初期化
	_input_flag = true;									//入力受付フラグを真で初期化
	_grall["PSelect"].resize(3);
	ResourceServer::LoadDivGraph("res/Mode/OverSelect.png", 3, 3, 1, 1230, 275, _grall["PSelect"].data());		//画像読み込み
	//SE読み込み
	_se["Select"] = ResourceServer::LoadSoundMem("se/OutGame/OtherSelectPush.wav");
	_se["Push"] = ResourceServer::LoadSoundMem("se/OutGame/GameStartPush.wav");
	//SE音量初期化
	_vpal["Select"] = 125;
	_vpal["Push"] = 200;
	return true;
}
/*-----終了------*/
bool OverSelect::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
/*-----更新-----*/
bool OverSelect::Process(Game& g) {
	base::Process(g);
	//SE音量変更
	ChangeVolumeSoundMem(_vpal["Select"], _se["Select"]);
	ChangeVolumeSoundMem(_vpal["Push"], _se["Push"]);
	_grhandle = _grall["PSelect"][_anime["PSelect"]];
	_anime["PSelect"] = _GraphNo;
	auto frame = _cnt - _mode_cnt;
	//フェードインの処理
	if (frame < FADEIN_FRAME) {
		_pal += FADE_SPEED;
	}
	if (frame == FADEIN_FRAME) {
		_pal = 255;
	}
	/*-----各状態毎の処理-----*/
	switch (_Type) {
	//何も選択していない状態
	case SELECTTYPE::NOSELECT:
		_GraphNo = 0;
		if (frame > FADEIN_FRAME) {
			if (g.GetTrg() & PAD_INPUT_LEFT) {
				PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
				_Type = SELECTTYPE::RETRYSELECT;
			}
			if (g.GetTrg() & PAD_INPUT_RIGHT) {
				PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
				_Type = SELECTTYPE::GOTITLESELECT;
			}
		}
		break;
		//リトライ選択状態
	case SELECTTYPE::RETRYSELECT:
		_GraphNo = 1;
		if (g.GetTrg() & PAD_INPUT_3&&_input_flag==true) {
			PlaySoundMem(_se["Push"], DX_PLAYTYPE_BACK, true);
			_mode_cnt = _cnt;
			_input_flag = false;
			auto ob = new OverlayBlack();
			ob->SetFade(60, 90, 150, 5);
			g.GetMS()->Add(ob, 5, "OverlayBlack");
		}
		if (frame == FADEIN_FRAME) {
			_input_flag = true;
			g.GetMS()->Del(this);
			g.GetMS()->Del(g.GetMS()->Get("Gameover"));
			g.GetMS()->Del(g.GetMS()->Get("OverLogo"));
			g.GetMS()->Del(g.GetMS()->Get("Game"));
			auto mg = new ModeGame();
			g.GetMS()->Add(mg, 0, "Game");
		}
		if (g.GetTrg() & PAD_INPUT_RIGHT) {
			PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
			_Type = SELECTTYPE::GOTITLESELECT;
		}
		break;
		//タイトル選択状態
	case SELECTTYPE::GOTITLESELECT:
		_GraphNo = 2;
		if (g.GetTrg() & PAD_INPUT_3 && _input_flag == true) {
			PlaySoundMem(_se["Push"], DX_PLAYTYPE_BACK, true);
			_mode_cnt = _cnt;
			_input_flag = false;
			auto ob =new OverlayBlack();
			ob->SetFade(60, 70, 70, 4);
			g.GetMS()->Add(ob, 5, "OverlayBlack");
		}
		if (frame== FADEIN_FRAME) {
			_input_flag = true;
			g.GetMS()->Del(this);
			g.GetMS()->Del(g.GetMS()->Get("OverLogo"));
			g.GetMS()->Del(g.GetMS()->Get("Gameover"));
			g.GetMS()->Del(g.GetMS()->Get("Game"));
			StopSoundMem(g.GetBgm()["Main"]);
			auto mt = new ModeTitle();
			mt->SetTitlebg();
			g.GetMS()->Add(mt, 0, "Title");
		}
		if (g.GetTrg() & PAD_INPUT_LEFT) {
			PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
			_Type = SELECTTYPE::RETRYSELECT;
		}
		break;
	}
	return true;
}
/*-----描画-----*/
bool OverSelect::Draw(Game& g) {
	base::Draw(g);
	return true;
}

