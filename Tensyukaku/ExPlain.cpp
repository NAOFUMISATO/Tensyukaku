#include <DxLib.h>
#include "ExPlain.h"
#include "Game.h"
#include "PController.h"
#include "ResourceServer.h"
#include "ModeTitle.h"

bool ExPlain::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;
	_y = 540;
	_Pal = 255;
	_Cnt = 6;
	_GrHandle = ResourceServer::LoadGraph("res/Mode/Black.png");
	auto pc = new PController();
	pc->PositionSetting(960, 540);
	g.GetMS()->Add(pc, 3, "PController");
	return true;
}

bool ExPlain::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool ExPlain::Process(Game& g) {
	base::Process(g);
	auto frame = _Cnt - _Mode_Cnt;
	if (g.GetTrg() & PAD_INPUT_1) {
		_Mode_Cnt = _Cnt;
	}
	if (frame == 5) {
		auto mt = (ModeTitle*)g.GetMS()->Get("Title");
		mt->SetStopObjProcess(false);
		g.GetMS()->Del(this);
		g.GetMS()->Del(g.GetMS()->Get("PController"));
	}
	return true;
}

bool ExPlain::Draw(Game& g) {
	base::Draw(g);
	return true;
}
