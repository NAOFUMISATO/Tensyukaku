#include <DxLib.h>
#include "ResourceServer.h"
#include "OverBlack.h"
#include "Game.h"


OverBlack::OverBlack() {
	Init();
	_GrHandle = ResourceServer::LoadGraph("res/Mode/Black.png");
}
OverBlack::~OverBlack() {
}

void OverBlack::Init() {
	_x = 960;
	_y = 540;
	_gx = 0;
	_gy = 0;
	_Alpha = 0;
	_Action_Cnt = _Cnt;
}

void OverBlack::Process(Game& g) {
	ObjectBase::Process(g);
	auto frame = _Cnt - _Action_Cnt;
	if (_Alpha < 200) {
		_Alpha += 2;
	}
}

void OverBlack::Draw(Game& g) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Alpha);
	DrawRotaGraph(_x, _y, 1.0, 0.0, _GrHandle, false, false);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

