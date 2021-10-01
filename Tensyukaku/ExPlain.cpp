#include <DxLib.h>
#include "ExPlain.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ModeTitle.h"
bool ExPlain::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;
	_y = 540;
	_pal = 255;
	_cnt = 6;
	_grhandle = ResourceServer::LoadGraph("res/Mode/Black.png");
	auto pc = new EXController();
	g.GetMS()->Add(pc, 3, "EXController");
	return true;
}

bool ExPlain::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool ExPlain::Process(Game& g) {
	base::Process(g);
	auto frame = _cnt - _mode_cnt;
	if (g.GetTrg() & PAD_INPUT_4) {
		_mode_cnt = _cnt;
	}
	if (frame == 5) {
		auto mt = (ModeTitle*)g.GetMS()->Get("Title");
		mt->SetStopObjProcess(false);
		g.GetMS()->Del(this);
		g.GetMS()->Del(g.GetMS()->Get("EXController"));
	}
	return true;
}

bool ExPlain::Draw(Game& g) {
	base::Draw(g);
	return true;
}

bool EXController::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;
	_y = 540;
	_pal = 255;
	_trans_flag = true;
	_grhandle = ResourceServer::LoadGraph("res/Mode/EXController.png");
	return true;
}

bool EXController::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool EXController::Process(Game& g) {
	base::Process(g);
	return true;
}

bool EXController::Draw(Game& g) {
	base::Draw(g);
	return true;
}


