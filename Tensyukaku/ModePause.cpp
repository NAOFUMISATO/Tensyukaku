
#include <DxLib.h>
#include "ModePause.h"
#include "ModeGame.h"
#include "PauseSelect.h"
#include "Game.h"
#include "ResourceServer.h"


namespace {
	
}
bool ModePause::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;
	_y = 540;
	_pal = 200;
	_mode_cnt = _cnt;
	_grhandle = ResourceServer::LoadGraph("res/Mode/Black.png");
	auto ps = new PauseSelect();
	g.GetMS()->Add(ps, 25, "PSelect");
	auto pc = new PController();
	g.GetMS()->Add(pc, 25, "PController");
	return true;
}

bool ModePause::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool ModePause::Process(Game& g) {
	base::Process(g);
	return true;
}

bool ModePause::Draw(Game& g) {
	base::Draw(g);
	return true;
}

bool PController::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;
	_y = 400;
	_pal = 255;
	_mode_cnt = _cnt;
	_trans_flag = true;
	_grhandle = ResourceServer::LoadGraph("res/Mode/PController.png");
	return true;
}

bool PController::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool PController::Process(Game& g) {
	base::Process(g);
	return true;
}

bool PController::Draw(Game& g) {
	base::Draw(g);
	return true;
}
