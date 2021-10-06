
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
	_se["Appear"] = ResourceServer::LoadSoundMem("se/OutGame/Pause.wav");
	_vpal["Appear"] = 255;
	auto ps = new PauseSelect();
	g.GetMS()->Add(ps, 25, "PSelect");
	auto pc = new PController();
	g.GetMS()->Add(pc, 25, "PController");
	PlaySoundMem(_se["Appear"],DX_PLAYTYPE_BACK,true);
	return true;
}

bool ModePause::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool ModePause::Process(Game& g) {
	ChangeVolumeSoundMem(_vpal["Appear"], _se["Appear"]);
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
