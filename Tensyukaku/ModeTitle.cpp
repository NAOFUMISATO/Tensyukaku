
#include <DxLib.h>
#include "ModeTitle.h"
#include "ModeGame.h"
#include "Game.h"
#include "ResourceServer.h"
#include "Cursor.h"
#include "TitleSelect.h"

namespace {
	/*----------AMGロゴ関係---------*/
	constexpr auto AMG_FADEINFRAME = 60;
	constexpr auto AMG_FADESPEED = 5;
	constexpr auto AMG_FADEOUTBEGINFRAME = 90;
	constexpr auto AMG_FADEOUTENDFRAME = 150;
	/*----------TEAMロゴ関係---------*/
	constexpr auto TEAM_FADEINFRAME = 120;
	constexpr auto TEAM_FADESPEED = 3;
	constexpr auto TEAM_FADEOUTBEGINFRAME = 180;
	constexpr auto TEAM_FADEOUTENDFRAME = 300;
	/*----------タイトル背景---------*/
	constexpr auto TITLE_FADEINBEGINFRAME = 120;
	constexpr auto TITLE_FADEINENDFRAME = 240;
	constexpr auto TITLE_FADESPEED = 3;
	constexpr auto GAMESTART_APPEARFRAME = 300;
	constexpr auto EXPLAIN_APPEARFRAME = 315;
	constexpr auto GAMEEND_APPEARFRAME = 330;
}
bool ModeTitle::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;
	_y = 540;
	_pal = 0;
	_mode_cnt = _cnt;
	_stopObjProcess = false;
	_Type = TITLETYPE::AMGLOGO;
	_grall["AmgLogo"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/AmgLogo.png",1,1,1,1920,1080, _grall["AmgLogo"].data());
	_grall["TeamLogo"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/TeamLogo.png", 1, 1, 1, 1920, 1080, _grall["TeamLogo"].data());
	_grall["TitleBG"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/TitleBG.png", 1, 1, 1, 1920, 1080, _grall["TitleBG"].data());
	//各チェックポイント到達フラグリセット
	auto flag = g.GetCPointFlag();
	flag["2A"] = false;
	flag["3A"] = false;
	flag["4A"] = false;
	flag["5A"] = false;
	flag["5B"] = false;
	flag["8A"] = false;
	flag["11A"] = false;
	g.SetCPointFlag(flag);
	//再起かどうかのフラグ
	g.SetRestartFlag(false);
	//各チュートリアルの出現フラグ
	return true;
}

bool ModeTitle::Terminate(Game& g) {
	base::Terminate(g);
	g.GetOS()->Clear();
	return true;
}

bool ModeTitle::Process(Game& g) {
	base::Process(g);
	auto frame = _cnt - _mode_cnt;
	auto pal = _pal;
	switch (_Type) {
	case TITLETYPE::AMGLOGO:
		_grhandle = _grall["AmgLogo"][_anime["AmgLogo"]];
		_anime["AmgLogo"] = 0;
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
			_Type = TITLETYPE::TEAMLOGO;
		}
		break;
	case TITLETYPE::TEAMLOGO:
		_grhandle = _grall["TeamLogo"][_anime["TeamLogo"]];
		_anime["TeamLogo"] = 0;
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
			auto cu = new Cursor();
			g.GetOS()->Add(cu);
			_Type = TITLETYPE::TITLEBG;
		}
		break;
	case TITLETYPE::TITLEBG:
		_grhandle = _grall["TitleBG"][_anime["TitleBG"]];
		_anime["TitleBG"] = 0;
		if (frame > TITLE_FADEINBEGINFRAME && TITLE_FADEINENDFRAME > frame) {
			_pal += TITLE_FADESPEED;
		}
		if (frame == TITLE_FADEINENDFRAME) {
			_pal = 255;
			PlaySoundMem(g.GetBgm()["Title"], DX_PLAYTYPE_LOOP, true);
			auto tl = new TitleLogo();
			g.GetOS()->Add(tl);
		}
		if (frame == GAMESTART_APPEARFRAME) {
			auto gs = new GameStart();
			g.GetOS()->Add(gs);
		}
		if (frame == EXPLAIN_APPEARFRAME) {
			auto ex = new Explain();
			g.GetOS()->Add(ex);
		}
		if (frame == GAMEEND_APPEARFRAME) {
			auto ge = new GameEnd();
			g.GetOS()->Add(ge);
		}
		break;
	}
	if (_stopObjProcess == false) {
		g.GetOS()->Process(g);
	}
	return true;
}

bool ModeTitle::Draw(Game& g) {
	base::Draw(g);
	g.GetOS()->Draw(g);
	return true;
}

