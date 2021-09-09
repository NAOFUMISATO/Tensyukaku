
#include <DxLib.h>
#include "ModeTitle.h"
#include "ModeGame.h"
#include "Game.h"
#include "ResourceServer.h"
#include "Cursor.h"
#include "TitleSelect.h"

namespace {
	/*----------AMGƒƒSŠÖŒW---------*/
	constexpr auto AMG_FADEINFRAME = 60;
	constexpr auto AMG_FADESPEED = 5;
	constexpr auto AMG_FADEOUTBEGINFRAME = 90;
	constexpr auto AMG_FADEOUTENDFRAME = 150;
	/*----------TEAMƒƒSŠÖŒW---------*/
	constexpr auto TEAM_FADEINFRAME = 120;
	constexpr auto TEAM_FADESPEED = 3;
	constexpr auto TEAM_FADEOUTBEGINFRAME = 180;
	constexpr auto TEAM_FADEOUTENDFRAME = 300;
	/*----------ƒ^ƒCƒgƒ‹”wŒi---------*/
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
	_Pal = 0;
	_Mode_Cnt = _Cnt;
	_Type = TITLETYPE::AMGLOGO;
	_GrAll["AmgLogo"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/AmgLogo.png",1,1,1,1920,1080, _GrAll["AmgLogo"].data());
	_GrAll["TeamLogo"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/TeamLogo.png", 1, 1, 1, 1920, 1080, _GrAll["TeamLogo"].data());
	_GrAll["TitleBG"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/TitleBG.png", 1, 1, 1, 1920, 1080, _GrAll["TitleBG"].data());
	return true;
}

bool ModeTitle::Terminate(Game& g) {
	base::Terminate(g);
	g.GetOS()->Clear();
	return true;
}

bool ModeTitle::Process(Game& g) {
	base::Process(g);
	auto frame = _Cnt - _Mode_Cnt;
	auto pal = _Pal;
	switch (_Type) {
	case TITLETYPE::AMGLOGO:
		_GrHandle = _GrAll["AmgLogo"][_Anime["AmgLogo"]];
		_Anime["AmgLogo"] = 0;
		if (frame < AMG_FADEINFRAME) {
			_Pal += AMG_FADESPEED;
		}
		if (frame == AMG_FADEINFRAME) {
			_Pal = 255;
		}
		if (frame > AMG_FADEOUTBEGINFRAME && AMG_FADEOUTENDFRAME > frame) {
			_Pal -= AMG_FADESPEED;
		}
		if (frame == AMG_FADEOUTENDFRAME) {
			_Pal = 0;
			_Mode_Cnt = _Cnt;
			_Type = TITLETYPE::TEAMLOGO;
		}
		break;
	case TITLETYPE::TEAMLOGO:
		_GrHandle = _GrAll["TeamLogo"][_Anime["TeamLogo"]];
		_Anime["TeamLogo"] = 0;
		if (frame < TEAM_FADEINFRAME) {
			_Pal += TEAM_FADESPEED;
		}
		if (frame == TEAM_FADEINFRAME) {
			_Pal = 255;
		}
		if (frame > TEAM_FADEOUTBEGINFRAME && TEAM_FADEOUTENDFRAME > frame) {
			_Pal -= TEAM_FADESPEED;
		}
		if (frame == TEAM_FADEOUTENDFRAME) {
			_Pal = 0;
			_Mode_Cnt = _Cnt;
			auto cu = new Cursor();
			g.GetOS()->Add(cu);
			_Type = TITLETYPE::TITLEBG;
		}
		break;
	case TITLETYPE::TITLEBG:
		_GrHandle = _GrAll["TitleBG"][_Anime["TitleBG"]];
		_Anime["TitleBG"] = 0;
		if (frame > TITLE_FADEINBEGINFRAME && TITLE_FADEINENDFRAME > frame) {
			_Pal += TITLE_FADESPEED;
		}
		if (frame == TITLE_FADEINENDFRAME) {
			_Pal = 255;
			auto tl = new TitleLogo();
			g.GetOS()->BAdd(tl);
		}
		if (frame == GAMESTART_APPEARFRAME) {
			auto gs = new GameStart();
			g.GetOS()->BAdd(gs);
		}
		if (frame == EXPLAIN_APPEARFRAME) {
			auto ex = new Explain();
			g.GetOS()->BAdd(ex);
		}
		if (frame == GAMEEND_APPEARFRAME) {
			auto ge = new GameEnd();
			g.GetOS()->BAdd(ge);
		}
		break;
	}
	g.GetOS()->Process(g);
	return true;
}

bool ModeTitle::Draw(Game& g) {
	base::Draw(g);
	g.GetOS()->Draw(g);
	return true;
}

