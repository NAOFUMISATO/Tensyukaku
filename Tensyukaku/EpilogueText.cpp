#include <DxLib.h>
#include "ModeEpilogue.h"
#include "EpilogueText.h"
#include "ModeGame.h"
#include "Game.h"
#include "ResourceServer.h"
using namespace EpiInfo;
bool EpilogueText::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = TEXT_FIRST_XPOSITION;
	_y = 900;
	_Pal = 0;
	_GraphNo = 0;
	_Mode_Cnt = _Cnt;
	_Trans_Flag = true;
	_GrAll["EText"].resize(TEXT_ANIMEMAX);
	ResourceServer::LoadDivGraph(TEXT_GRAPHNAME, TEXT_ANIMEMAX, TEXT_WIDTHCOUNT, TEXT_HEIGHTCOUNT, TEXT_GRAPH_WIDTH, TEXT_GRAPH_HEIGHT, _GrAll["EText"].data());
	return true;
}

bool EpilogueText::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool EpilogueText::Process(Game& g) {
	base::Process(g);
	auto frame = _Cnt - _Mode_Cnt;
	_GrHandle = _GrAll["EText"][_Anime["EText"]];
	_Anime["EText"] = _GraphNo;
	//テキスト6
	if (frame < TEXT6_FADEIN_FRAME) {
		_Pal += TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT6_FADEIN_FRAME) {
		_Pal = 255;
	}
	if (frame >= TEXT6_FADEOUT_BEGINFRAME && TEXT6_FADEOUT_ENDFRAME > frame) {
		_Pal -= TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT6_FADEOUT_ENDFRAME) {
		_Pal = 0;
		_x = TEXT_FIRST_XPOSITION;
		_GraphNo = 1;
	}
	//テキスト7
	if (frame >= TEXT7_FADEIN_BEGINFRAME && TEXT7_FADEIN_ENDFRAME > frame) {
		_Pal += TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT7_FADEIN_ENDFRAME) {
		_Pal = 255;
	}
	if (frame >= TEXT7_FADEOUT_BEGINFRAME && TEXT7_FADEOUT_ENDFRAME > frame) {
		_Pal -= TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT7_FADEOUT_ENDFRAME) {
		_Pal = 0;
		_x = TEXT_FIRST_XPOSITION;
		_GraphNo = 2;
	}
	//テキスト8
	if (frame >= TEXT8_FADEIN_BEGINFRAME && TEXT8_FADEIN_ENDFRAME > frame) {
		_Pal += TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT8_FADEIN_ENDFRAME) {
		_Pal = 255;
	}
	if (frame >= TEXT8_FADEOUT_BEGINFRAME && TEXT8_FADEOUT_ENDFRAME > frame) {
		_Pal -= TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT8_FADEOUT_ENDFRAME) {
		_Pal = 0;
		_x = TEXT_FIRST_XPOSITION;
		_GraphNo = 3;
	}
	//テキスト9
	if (frame >= TEXT9_FADEIN_BEGINFRAME && TEXT9_FADEIN_ENDFRAME > frame) {
		_Pal += TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT9_FADEIN_ENDFRAME) {
		_Pal = 255;
	}
	if (frame >= TEXT9_FADEOUT_BEGINFRAME && TEXT9_FADEOUT_ENDFRAME > frame) {
		_Pal -= TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT9_FADEOUT_ENDFRAME) {
		_Pal = 0;
		g.GetMS()->Del(this);
	}
	return true;
}

bool EpilogueText::Draw(Game& g) {
	base::Draw(g);
	return true;
}
