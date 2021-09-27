#include <DxLib.h>
#include "ResourceServer.h"
#include "Overlogo.h"
bool Overlogo::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;
	_y = 350;
	_pal = 0;
	_mode_cnt = _cnt;
	_trans_flag = true;
	_grhandle = ResourceServer::LoadGraph("res/Mode/OverLogo.png");
	return true;
}

bool Overlogo::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
bool Overlogo::Process(Game& g) {
	base::Process(g);
	auto frame = _cnt - _mode_cnt;
	if (frame < 60) {
		_pal += 4;
	}
	if (frame == 60) {
		_pal = 255;
	}
	return true;
}

bool Overlogo::Draw(Game& g) {
	base::Draw(g);
	return true;
}
