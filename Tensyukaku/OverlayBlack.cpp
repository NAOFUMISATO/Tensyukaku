#include <DxLib.h>
#include "OverlayBlack.h"
#include "Game.h"
#include "ResourceServer.h"

bool OverlayBlack::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;
	_y = 540;
	_Pal = 0;
	_Mode_Cnt = _Cnt;
	_GrHandle=ResourceServer::LoadGraph("res/Mode/Black.png");
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
	_FadeSpeed = fadespeed;
}
bool OverlayBlack::Process(Game& g) {
	base::Process(g);
	auto frame = _Cnt - _Mode_Cnt;
	if (frame >= 0 && _Fadeoutframe >frame) {
		_Pal += _FadeSpeed;
	}
	if (frame == _Fadeoutframe) {
		_Pal = 255;
	}
	if (frame >= _FadeinBeginframe && _FadeinEndframe > frame) {
		_Pal -= _FadeSpeed;
	}
	if (frame == _FadeinEndframe) {
		_Pal = 0;
		g.GetMS()->Del(this);
	}
	return true;
}
bool OverlayBlack::Draw(Game& g) {
	base::Draw(g);
	return true;
}