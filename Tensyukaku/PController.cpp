#include <DxLib.h>
#include "ResourceServer.h"
#include "PController.h"
bool PController::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_pal = 255;
	_mode_cnt = _cnt;
	_trans_flag = true;
	_grhandle=ResourceServer::LoadGraph("res/Mode/Controller.png");
	return true;
}

bool PController::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

void PController::PositionSetting(int x,int y) {
	_x = x;
	_y = y;
}
bool PController::Process(Game& g) {
	base::Process(g);
	return true;
}

bool PController::Draw(Game& g) {
	base::Draw(g);
	return true;
}
