#include <DxLib.h>
#include "EfectBase.h"
#include "Game.h"
EfectBase::EfectBase() {
	Init();
}
EfectBase::~EfectBase() {
}

void	EfectBase::Init() {
	_sort = 15;
}

void EfectBase::Process(Game& g) {
	ObjectBase::Process(g);
}

void EfectBase::Draw(Game& g) {
	auto GC = g.GetChip();
	auto x = _x + _gx - GC->GetscrX();
	auto y = _y + _gy - GC->GetscrY();
	auto scale = _drg.first;
	auto angle = _drg.second;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
	DrawRotaGraph(x,y, scale, angle, _grhandle, true, _isflip);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}