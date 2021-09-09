#include <DxLib.h>
#include "ModeGameover.h"
#include "ModeGame.h"
#include "OverCursor.h"
#include "OverSelect.h"
#include "OverBlack.h"
#include "OverlayBlack.h"
#include "Game.h"
#include "ResourceServer.h"

bool ModeGameover::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;
	_y = 540;
	_Pal = 0;
	_Mode_Cnt = _Cnt;
	return true;
}

bool ModeGameover::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool ModeGameover::Process(Game& g) {
	base::Process(g);
	auto frame = _Cnt - _Mode_Cnt;
	if (frame == 1) {
		auto ob = new OverBlack();
		g.GetOS()->Add(ob);
		auto olo = new OverLogo();
		g.GetOS()->Add(olo);
	}
	if (frame == 200) {
		auto ore = new OverRetry();
		g.GetOS()->Add(ore);
		auto ogt = new OverGotitle();
		g.GetOS()->Add(ogt);
	}
	if (frame == 400) {
		auto ocu = new OverCursor();
		g.GetOS()->Add(ocu);
	}
	return true;
}

bool ModeGameover::Draw(Game& g) {
	base::Draw(g);
	return true;
}