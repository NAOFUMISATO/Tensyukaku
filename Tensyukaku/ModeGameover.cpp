#include <DxLib.h>
#include "ModeGameover.h"
#include "ModeGame.h"
#include "OverlayBlack.h"
#include "OverSelect.h"
#include "OverLogo.h"
#include "Game.h"
#include "ResourceServer.h"

bool ModeGameover::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;
	_y = 540;
	_Pal = 0;
	_Mode_Cnt = _Cnt;
	_GrHandle = ResourceServer::LoadGraph("res/Mode/Black.png");
	return true;
}

bool ModeGameover::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool ModeGameover::Process(Game& g) {
	base::Process(g);
	auto frame = _Cnt - _Mode_Cnt;
	if (frame < 60) {
		_Pal += 3;
	}
	if (frame == 60) {
		_Pal = 200;
		auto ol = new Overlogo();
		g.GetMS()->Add(ol, 3, "OverLogo");
	}
	if (frame == 120) {
		auto ps = new OverSelect();
		g.GetMS()->Add(ps, 3, "PSelect");
	}
	return true;
}

bool ModeGameover::Draw(Game& g) {
	base::Draw(g);
	return true;
}