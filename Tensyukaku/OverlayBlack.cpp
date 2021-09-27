#include <DxLib.h>
#include "OverlayBlack.h"
#include "Game.h"
#include "ResourceServer.h"

bool OverlayBlack::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;
	_y = 540;
	_pal = 0;
	_mode_cnt = _cnt;
	_grhandle=ResourceServer::LoadGraph("res/Mode/Black.png");
	return true;
}
bool OverlayBlack::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
void OverlayBlack::SetFade(int fadeoutframe,int fadeinbeginframe,int fadeinendframe, int fadespeed) {
	_Fadeoutframe= fadeoutframe;
	_FadeinBeginframe = fadeinbeginframe;
	_FadeinEndframe = fadeinendframe;
	_fade_speed = fadespeed;
}
bool OverlayBlack::Process(Game& g) {
	base::Process(g);
	auto frame = _cnt - _mode_cnt;
	if (frame >= 0 && _Fadeoutframe >frame) {
		_pal += _fade_speed;
	}
	if (frame == _Fadeoutframe) {
		_pal = 255;
	}
	if (frame >= _FadeinBeginframe && _FadeinEndframe > frame) {
		_pal -= _fade_speed;
	}
	if (frame == _FadeinEndframe) {
		_pal = 0;
		g.GetMS()->Del(this);
	}
	return true;
}
bool OverlayBlack::Draw(Game& g) {
	base::Draw(g);
	return true;
}