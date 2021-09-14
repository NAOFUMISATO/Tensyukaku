#include <DxLib.h>
#include "OverlayFlame.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ModeBase.h"
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