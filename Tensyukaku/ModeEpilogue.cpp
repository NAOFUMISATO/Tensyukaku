#include <DxLib.h>
#include "ModeEpilogue.h"
#include "EpilogueText.h"
#include "ModeTitle.h"
#include "Game.h"
#include "ResourceServer.h"

using namespace EpiInfo;
bool ModeEpilogue::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;
	_y = 540;
	_Pal = 0;
	_Mode_Cnt = _Cnt;
	_GrHandle=ResourceServer::LoadGraph("res/Mode/Epilogue.png");
	return true;
}

bool ModeEpilogue::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
bool ModeEpilogue::Process(Game& g) {
	base::Process(g);
	auto frame = _Cnt - _Mode_Cnt;
	if(frame < BG_FADEIN_FRAME) {
		_Pal += BG_FADEIN_SPEED;
	}
	if (frame == BG_FADEIN_FRAME) {
		_Pal = 255;
		auto et = new EpilogueText();
		g.GetMS()->Add(et, 1, "PText");
	}
	if (frame >= BG_FADEOUT_BEGINFRAME && BG_FADEOUT_ENDFRAME > frame) {
		_Pal -= BG_FADEOUT_SPEED;
	}
	if (frame == BG_FADEOUT_ENDFRAME) {
		_Pal = 0;
		g.GetMS()->Del(g.GetMS()->Get("Epilogue"));
		auto mt = new ModeTitle();
		g.GetMS()->Add(mt, 0, "Title");
	}
	return true;
}
bool ModeEpilogue::Draw(Game& g) {
	base::Draw(g);
	return true;
}