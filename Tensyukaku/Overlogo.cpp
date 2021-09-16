#include <DxLib.h>
#include "ResourceServer.h"
#include "Overlogo.h"
bool Overlogo::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;
	_y = 350;
	_Pal = 0;
	_Mode_Cnt = _Cnt;
	_Trans_Flag = true;
	_GrHandle = ResourceServer::LoadGraph("res/Mode/OverLogo.png");
	return true;
}

bool Overlogo::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
bool Overlogo::Process(Game& g) {
	base::Process(g);
	auto frame = _Cnt - _Mode_Cnt;
	if (frame < 60) {
		_Pal += 4;
	}
	if (frame == 60) {
		_Pal = 255;
	}
	return true;
}

bool Overlogo::Draw(Game& g) {
	base::Draw(g);
	return true;
}
