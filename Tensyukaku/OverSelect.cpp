#include <DxLib.h>
#include "ResourceServer.h"
#include "OverSelect.h"
#include "Game.h"
#include "ObjectBase.h"
namespace {
	constexpr auto RED = 0;
	constexpr auto GREEN = 1;
	constexpr auto Blue = 2;
}

//óéñΩÉçÉS
OverLogo::OverLogo() {
	Init();
	_GrHandle = ResourceServer::LoadGraph("res/Mode/OverLogo.png");
}
OverLogo::~OverLogo() {
}
void OverLogo::Init() {
	_x = 960;
	_y = 250;
	_hit_x = -500;
	_hit_y = -200;
	_hit_w = 1000;
	_hit_h = 400;
	_Alpha = 0;
}
void OverLogo::Process(Game& g) {
	ObjectBase::Process(g);
	if (_Alpha <= 255) {
		_Alpha += 2;
	}
}

void OverLogo::Draw(Game& g) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Alpha);
	DrawRotaGraph(_x, _y, 1.0, 0.0, _GrHandle, true, false);
#ifdef _DEBUG
	int& re = std::get<RED>(_Color);
	int& gr = std::get<GREEN>(_Color);
	int& bl = std::get<Blue>(_Color);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Dalpha);	// îºìßñæï`âÊéwíË
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_x + _hit_w, _y + _hit_y + _hit_h, GetColor(re, gr, bl), _Fill);	// îºìßñæÇÃê‘Ç≈ìñÇΩÇËîªíËï`âÊ
#endif
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
//ÉäÉgÉâÉC
OverRetry::OverRetry() {
	Init();
	_GrHandle = ResourceServer::LoadGraph("res/Mode/OverRetry.png");
};
OverRetry::~OverRetry() {
};

void OverRetry::Init() {
	_x = 540;
	_y = 700;
	_hit_x = -370;
	_hit_y = -80;
	_hit_w = 650;
	_hit_h = 190;
	_Alpha = 0;
}

void OverRetry::Process(Game& g) {
	ObjectBase::Process(g);
	if (_Alpha <= 255) {
		_Alpha += 4;
	}
}

void OverRetry::Draw(Game& g) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Alpha);
	DrawRotaGraph(_x, _y, 1.0, 0.0, _GrHandle, true, false);
#ifdef _DEBUG
	int& re = std::get<RED>(_Color);
	int& gr = std::get<GREEN>(_Color);
	int& bl = std::get<Blue>(_Color);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Dalpha);		// îºìßñæï`âÊéwíË
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_x + _hit_w, _y + _hit_y + _hit_h, GetColor(re, gr, bl), _Fill);	// îºìßñæÇÃê‘Ç≈ìñÇΩÇËîªíËï`âÊ
#endif
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
//É^ÉCÉgÉãÇ÷ñﬂÇÈ
OverGotitle::OverGotitle() {
	Init();
	_GrHandle = ResourceServer::LoadGraph("res/Mode/OverGotitle.png");
};
OverGotitle::~OverGotitle() {
};

void OverGotitle::Init() {
	_x = 1380;
	_y = 700;
	_hit_x = -370;
	_hit_y = -80;
	_hit_w = 650;
	_hit_h = 190;
	_Alpha = 0;
}
void OverGotitle::Process(Game& g) {
	ObjectBase::Process(g);
	if (_Alpha <= 255) {
		_Alpha += 4;
	}
}

void OverGotitle::Draw(Game& g) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Alpha);
	DrawRotaGraph(_x, _y, 1.0, 0.0, _GrHandle, true, false);
#ifdef _DEBUG
	int& re = std::get<RED>(_Color);
	int& gr = std::get<GREEN>(_Color);
	int& bl = std::get<Blue>(_Color);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Dalpha);		// îºìßñæï`âÊéwíË
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_x + _hit_w, _y + _hit_y + _hit_h, GetColor(re, gr, bl), _Fill);	// îºìßñæÇÃê‘Ç≈ìñÇΩÇËîªíËï`âÊ
#endif
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}