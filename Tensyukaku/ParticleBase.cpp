#include <DxLib.h>
#include <utility>
#include <tuple>
#include "ParticleBase.h"
#include "Game.h"

using namespace ParInfo;
ParticleBase::ParticleBase() {
	Init();
}
ParticleBase::~ParticleBase() {};

void ParticleBase::Init() {
}

void ParticleBase::Process(Game& g) {
	_xy.first += _dxy.first;
	_xy.second += _dxy.second;
	_Cnt--;
	if (_Cnt <= 0) {
		g.GetOS()->Del(this);
	}
}

void ParticleBase::Draw(Game& g) {
	int a = _a;
	int& re = std::get<Red>(_rgb);
	int& gr = std::get<Green>(_rgb);
	int& bl = std::get<Blue>(_rgb);
	SetDrawBlendMode(_bm, a);
	SetDrawBright(re,gr,bl);
	auto GC = g.GetChip();
	auto x = _xy.first + _mxy.first - GC->GetscrX();
	auto y = _xy.second + _mxy.second - GC->GetscrY();
	double scale = _drg.first;
	double angle = _drg.second;
	DrawRotaGraph(x, y,scale,angle, _GrHandle, true,_isFlip);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawBright(255, 255, 255);
}

