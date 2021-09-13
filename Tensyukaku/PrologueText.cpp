#include <DxLib.h>
#include "ModePrologue.h"
#include "PrologueText.h"
#include "ModeGame.h"
#include "Game.h"
#include "ResourceServer.h"
using namespace ProInfo;
bool PrologueText::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 1600;
	_y = 540;
	_Pal = 0;
	_GraphNo = 0;
	_Mode_Cnt = _Cnt;
	_Trans_Flag = true;
	_GrAll["PText"].resize(TEXT_ANIMEMAX);
	ResourceServer::LoadDivGraph(TEXT_GRAPHNAME, TEXT_ANIMEMAX, TEXT_WIDTHCOUNT, TEXT_HEIGHTCOUNT, TEXT_GRAPH_WIDTH, TEXT_GRAPH_HEIGHT, _GrAll["PText"].data());
	return true;
}

bool PrologueText::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool PrologueText::Process(Game& g) {
	base::Process(g);
	auto frame = _Cnt - _Mode_Cnt;
	_GrHandle = _GrAll["PText"][_Anime["PText"]];
	_Anime["PText"] = _GraphNo;
	//テキスト1
	if (frame < TEXT1_FADEIN_FRAME) {
		_Pal += TEXT_FADE_SPEED;
	}
	if (frame == TEXT1_FADEIN_FRAME) {
		_Pal = 255;
	}
	if (frame >= TEXT1_FADEOUT_BEGINFRAME && TEXT1_FADEOUT_ENDFRAME>frame) {
		_Pal -= TEXT_FADE_SPEED;
	}
	if (frame == TEXT1_FADEOUT_ENDFRAME) {
		_Pal = 0;
		_GraphNo = 1;
	}
	//テキスト2
	if (frame >= TEXT2_FADEIN_BEGINFRAME && TEXT2_FADEIN_ENDFRAME > frame) {
		_Pal += TEXT_FADE_SPEED;
	}
	if (frame == TEXT2_FADEIN_ENDFRAME) {
		_Pal = 255;
	}
	if (frame >= TEXT2_FADEOUT_BEGINFRAME && TEXT2_FADEOUT_ENDFRAME > frame) {
		_Pal -= TEXT_FADE_SPEED;
	}
	if (frame == TEXT2_FADEOUT_ENDFRAME) {
		_Pal = 0;
		_GraphNo = 2;
	}
	//テキスト3
	if (frame >= TEXT3_FADEIN_BEGINFRAME && TEXT3_FADEIN_ENDFRAME > frame) {
		_Pal += TEXT_FADE_SPEED;
	}
	if (frame == TEXT3_FADEIN_ENDFRAME) {
		_Pal = 255;
	}
	if (frame >= TEXT3_FADEOUT_BEGINFRAME && TEXT3_FADEOUT_ENDFRAME > frame) {
		_Pal -= TEXT_FADE_SPEED;
	}
	if (frame == TEXT3_FADEOUT_ENDFRAME) {
		_Pal = 0;
		_GraphNo = 3;
	}
	//テキスト4
	if (frame >= TEXT4_FADEIN_BEGINFRAME && TEXT4_FADEIN_ENDFRAME > frame) {
		_Pal += TEXT_FADE_SPEED;
	}
	if (frame == TEXT4_FADEIN_ENDFRAME) {
		_Pal = 255;
	}
	if (frame >= TEXT4_FADEOUT_BEGINFRAME && TEXT4_FADEOUT_ENDFRAME > frame) {
		_Pal -= TEXT_FADE_SPEED;
	}
	if (frame == TEXT4_FADEOUT_ENDFRAME) {
		_Pal = 0;
		_GraphNo = 4;
	}
	//テキスト5
	if (frame >= TEXT5_FADEIN_BEGINFRAME && TEXT5_FADEIN_ENDFRAME > frame) {
		_Pal += TEXT_FADE_SPEED;
	}
	if (frame == TEXT5_FADEIN_ENDFRAME) {
		_Pal = 255;
	}
	if (frame >= TEXT5_FADEOUT_BEGINFRAME && TEXT5_FADEOUT_ENDFRAME > frame) {
		_Pal -= TEXT_FADE_SPEED;
	}
	if (frame == TEXT5_FADEOUT_ENDFRAME) {
		_Pal = 0;
		g.GetMS()->Del(this);
	}
	return true;
}

bool PrologueText::Draw(Game& g) {
	base::Draw(g);
	return true;
}