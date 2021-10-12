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
/*----初期化----- */
bool PauseSelect::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;												//X座標の初期化
	_y = 850;												//Y座標の初期化
	_graph_no = 0;									  	//シート番号０で初期化
	_type = SELECTTYPE::NOSELECT;	  	//何も選択していない状態で初期化
	_trans_flag = true;								   	//背景透過フラグを真で初期化
	_input_flag = false;							   	//入力受付フラグを偽で初期化
	_grall["PSelect"].resize(3);
	ResourceServer::LoadDivGraph("res/Mode/PauseSelect.png",3,3,1,1230,275,_grall["PSelect"].data());	//画像読み込み
	//SE読み込み
	_se["Select"] = ResourceServer::LoadSoundMem("se/OutGame/OtherSelectPush.wav");
	_se["Push"] = ResourceServer::LoadSoundMem("se/OutGame/GameStartPush.wav");
	//SE音量初期化
	_vpal["Select"] = 125;
	_vpal["Push"] =200;
	return true;
}
/*-----終了------*/
bool PauseSelect::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
/*----更新----- */
bool PauseSelect::Process(Game& g) {
	base::Process(g);
	//SE音量変更
	ChangeVolumeSoundMem(_vpal["Select"], _se["Select"]);
	ChangeVolumeSoundMem(_vpal["Push"], _se["Push"]);
	_grhandle = _grall["PSelect"][_anime["PSelect"]];
	_anime["PSelect"] = _graph_no;
	auto frame = _cnt - _mode_cnt;
	/*-----各状態毎の処理-----*/
	switch (_type) {
		//何も選択していない状態
	case SELECTTYPE::NOSELECT:
		_graph_no = 0;
		if (g.GetTrg() & PAD_INPUT_LEFT) {
			PlaySoundMem(_se["Select"],DX_PLAYTYPE_BACK,true);
			_type = SELECTTYPE::RETURNSELECT;
		}
		if (g.GetTrg() & PAD_INPUT_RIGHT) {
			PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
			_type = SELECTTYPE::GOTITLESELECT;
		}
		break;
		//ゲームに戻る選択状態
	case SELECTTYPE::RETURNSELECT:
		_graph_no = 1;
		if (g.GetTrg() & PAD_INPUT_3&&_input_flag==false) {
			PlaySoundMem(_se["Push"], DX_PLAYTYPE_BACK, true);
			_input_flag = true;
			_mode_cnt = _cnt;
		}
		if (frame == 1 && _input_flag == true) {
			g.GetMS()->Del(this);
			g.GetMS()->Del(g.GetMS()->Get("Pause"));
			g.GetMS()->Del(g.GetMS()->Get("PController"));
			_input_flag = false;
			auto mg = (ModeGame*)g.GetMS()->Get("Game");
			mg->SetStopObjProcess(false);
		}
		if (g.GetTrg() & PAD_INPUT_RIGHT) {
			PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
			_type = SELECTTYPE::GOTITLESELECT;
		}
		break;
		//タイトル選択状態
	case SELECTTYPE::GOTITLESELECT:
		_graph_no = 2;
		if (g.GetTrg() & PAD_INPUT_3&&_input_flag==false) {
			PlaySoundMem(_se["Push"], DX_PLAYTYPE_BACK, true);
			_input_flag =true;
			_mode_cnt = _cnt;
			g.GetMS()->Del(g.GetMS()->Get("Flame"));
			auto ob = new OverlayBlack();
			ob->SetFade(60,180, 240, 5);
			g.GetMS()->Add(ob, 30, "OverlayBlack");
		}
		if (frame == 60 && _input_flag == true) {
			g.GetMS()->Del(this);
			g.GetMS()->Del(g.GetMS()->Get("PController"));
			g.GetMS()->Del(g.GetMS()->Get("Pause"));
			auto mg = (ModeGame*)g.GetMS()->Get("Game");
			mg->SetStopObjProcess(false);
			_input_flag = false;
			g.GetMS()->Del(g.GetMS()->Get("Game"));
			auto mt = new ModeTitle();
			mt->SetTitlebg();
			g.GetMS()->Add(mt, 0, "Title");	
			StopSoundMem(g.GetBgm()["Main"]); 
			StopSoundMem(g.GetBgm()["Flame"]);
			StopSoundMem(g.GetBgm()["Boss"]);
		}
		if(g.GetTrg() & PAD_INPUT_LEFT) {
			PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
			_type = SELECTTYPE::RETURNSELECT;
		}
		break;
	}
	return true;
}
/*----描画----- */
bool PauseSelect::Draw(Game& g) {
	base::Draw(g);
	return true;
}

