#include <DxLib.h>
#include "OverlayFlame.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ModeBase.h"
#include "FlamePerformParticle.h"
using namespace FParInfo;
namespace {
	constexpr auto FADEIN_FRAME = 120;
	constexpr auto FADE_SPEED = 2;
	constexpr auto FADEOUT_FRAME = 120;
}
bool OverlayFlame::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;
	_y = 540;
	_Pal = 0;
	_Mode_Cnt = _Cnt;
	_Trans_Flag = true;
	_GrHandle = ResourceServer::LoadGraph("res/Mode/OverFlame.png");
	return true;
}

bool OverlayFlame::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool OverlayFlame::Process(Game& g) {
	base::Process(g);
	auto frame = _Cnt - _Mode_Cnt;
	if ((_Cnt /30 % 2) == 0) {
	std::pair<int, int> xy = std::make_pair(_x, _y);
	std::pair<double, double> dxy = std::make_pair(((rand() % FLAME_RANDOMX1) - FLAME_RANDOMX2) / FLAME_RANDOMX3, ((rand() % -FLAME_RANDOMY1) - FLAME_RANDOMY2) / FLAME_RANDOMY3);
	auto fp = new FlamePerform(xy, dxy, true);
	g.GetOS()->Add(fp);
	}
	if (frame >= 0 && FADEIN_FRAME > frame) {
		_Pal += FADE_SPEED;
	}
	if (frame == FADEIN_FRAME) {
		_Pal = 255;
	}
	return true;
}
bool OverlayFlame::Draw(Game& g) {
	base::Draw(g);
	return true;
}