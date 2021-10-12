/*****************************************************************//**
 * \file   ModeTitle.cpp
 * \brief  モードタイトルクラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModeTitle.h"
#include "ModeGame.h"
#include "Game.h"
#include "ResourceServer.h"
#include "Cursor.h"
#include "TitleSelect.h"

using namespace MTInfo;
/*-----初期化-----*/
 bool ModeTitle::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;										//X座標の初期化
	_y = 540;										//Y座標の初期化
	_pal = 0;											//フェードインしていくため、透明度0で初期化
	_mode_cnt = _cnt;						//フレーム０で初期化
	_stopObjProcess = false;				//オブジェクト処理を止めるフラグを偽で初期化
	_trans_flag = true;							//背景透過フラグを真で初期化
	//画像読み込み
	_grall["AmgLogo"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/AmgLogo.png",1,1,1,1920,1080, _grall["AmgLogo"].data());
	_grall["TeamLogo"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/TeamLogo.png", 1, 1, 1, 1920, 1080, _grall["TeamLogo"].data());
	_grall["TitleBG"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/TitleBG.png", 1, 1, 1, 1920, 1080, _grall["TitleBG"].data());
	//各チェックポイント到達フラグを全て偽で初期化
	auto flag = g.GetCPointFlag();
	flag["2A"] = false;
	flag["3A"] = false;
	flag["4A"] = false;
	flag["5A"] = false;
	flag["5B"] = false;
	flag["8A"] = false;
	flag["11A"] = false;
	g.SetCPointFlag(flag);
	//再起かどうかのフラグを偽で初期化
	g.SetRestartFlag(false);
	//各BGMの初期化
	g.VolumeInit();
	return true;
}
 /*-----終了------*/
bool ModeTitle::Terminate(Game& g) {
	base::Terminate(g);
	g.GetOS()->Clear();
	return true;
}
/*-----更新-----*/
bool ModeTitle::Process(Game& g) {
	base::Process(g);
	auto frame = _cnt - _mode_cnt;
	auto pal = _pal;
	/*--各状態ごとの処理*/
	switch (_type) {
		//AMGロゴ
	case TITLETYPE::AMGLOGO:
		_grhandle = _grall["AmgLogo"][_anime["AmgLogo"]];
		_anime["AmgLogo"] = 0;
		//フェード関係の処理
		if (frame < AMG_FADEINFRAME) {
			_pal += AMG_FADESPEED;
		}
		if (frame == AMG_FADEINFRAME) {
			_pal = 255;
		}
		if (frame > AMG_FADEOUTBEGINFRAME && AMG_FADEOUTENDFRAME > frame) {
			_pal -= AMG_FADESPEED;
		}
		if (frame == AMG_FADEOUTENDFRAME) {
			_pal = 0;
			_mode_cnt = _cnt;
			_type = TITLETYPE::TEAMLOGO;			//フェードの処理が終わったならチームロゴへ
		}
		break;
		//チームロゴ
	case TITLETYPE::TEAMLOGO:
		_grhandle = _grall["TeamLogo"][_anime["TeamLogo"]];
		_anime["TeamLogo"] = 0;
		//フェード関係の処理
		if (frame < TEAM_FADEINFRAME) {
			_pal += TEAM_FADESPEED;
		}
		if (frame == TEAM_FADEINFRAME) {
			_pal = 255;
		}
		if (frame > TEAM_FADEOUTBEGINFRAME && TEAM_FADEOUTENDFRAME > frame) {
			_pal -= TEAM_FADESPEED;
		}
		if (frame == TEAM_FADEOUTENDFRAME) {
			_pal = 0;
			_mode_cnt = _cnt;
			_type = TITLETYPE::TITLEBG;			//フェードの処理が終わったならチームロゴへ
		}
		break;
		//タイトル背景
	case TITLETYPE::TITLEBG:
		_grhandle = _grall["TitleBG"][_anime["TitleBG"]];
		_anime["TitleBG"] = 0;
		if (frame == 1) {
			auto cu = new Cursor();		//タイトルカーソル生成
			g.GetOS()->Add(cu);
		}
		if (frame > TITLE_FADEINBEGINFRAME && TITLE_FADEINENDFRAME > frame) {
			_pal += TITLE_FADESPEED;
		}
		if (frame == TITLE_FADEINENDFRAME) {
			_pal = 255;
			PlaySoundMem(g.GetBgm()["Title"], DX_PLAYTYPE_LOOP, true);
			auto tl = new TitleLogo();		//タイトルロゴ生成
			g.GetOS()->Add(tl);
		}
		if (frame == GAMESTART_APPEARFRAME) {
			auto gs = new GameStart();	//ゲームスタートセレクト生成
			g.GetOS()->Add(gs);
		}
		if (frame == EXPLAIN_APPEARFRAME) {
			auto ex = new Explain();		//説明セレクト生成
			g.GetOS()->Add(ex);
		}
		if (frame == GAMEEND_APPEARFRAME) {
			auto ge = new GameEnd();	//ゲーム終了セレクト生成
			g.GetOS()->Add(ge);
		}
		if (frame ==CREDIT_APPEARFRAME) {
			auto cr = new Credit();			//クレジットセレクト生成
			g.GetOS()->Add(cr);
		}
		break;
	}
	//オブジェクトを止めるフラグが偽ならオブジェクト処理を更新する
	if (_stopObjProcess == false) {
		g.GetOS()->Process(g);
	}
	return true;
}
/*-----描画-----*/
bool ModeTitle::Draw(Game& g) {
	base::Draw(g);
	g.GetOS()->Draw(g);
	return true;
}

