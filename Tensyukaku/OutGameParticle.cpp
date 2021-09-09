#include <DxLib.h>
#include <tuple>
#include <utility>
#include "Game.h"
#include "ResourceServer.h"
#include "OutGameParticle.h"
#include "ParticleBase.h"
namespace {
	/*----------Tupleå^â¬ì«ê´å¸è„---------*/
	constexpr auto RED = 0;
	constexpr auto GREEN = 1;
	constexpr auto BLUE = 2;
}
using namespace CParInfo;
CursorParticle1::CursorParticle1(std::pair<double, double> xy, std::pair<double, double> dxy,int colortype){
	_xy = xy;
	_dxy = dxy;
	_ColorType = colortype;
	Init();
	_GrHandle = ResourceServer::LoadGraph(CURSOR_PARTICLE1_GRAPH);
}
CursorParticle1::~CursorParticle1() {
}

void CursorParticle1::Init() {
	_mxy = std::make_pair(CURSOR_PARTICLE1_POSITIONX, CURSOR_PARTICLE1_POSITIONY);
	_bm = CURSOR_PARTICLE1_BLENDMODE;
	_pal = CURSOR_PARTICLE1_PAL;
	_rgb = std::make_tuple(230, 70, 5);
	_drg = std::make_pair(CURSOR_PARTICLE1_SCALE, CURSOR_PARTICLE1_ANGLE);
	_Cnt = CURSOR_PARTICLE1_CNT;
}

void CursorParticle1::Process(Game& g) {
	ParticleBase::Process(g);
	switch (_ColorType) {
	case 0:
		_rgb = std::make_tuple(70, 230, 5);
		break;
	case 1:
		_rgb = std::make_tuple(5, 70, 230);
		break;
	case 2:
		_rgb = std::make_tuple(120, 70, 120);
		break;
	case 3:
		_rgb = std::make_tuple(150, 5, 5);
		break;
	case 4:
		_rgb = std::make_tuple(150, 150, 5);
		break;
	case 5:
		_rgb = std::make_tuple(230, 70, 5);
		break;
	}
}

void CursorParticle1::Draw(Game& g) {
	int a = _pal;
	int& re = std::get<RED>(_rgb);
	int& gr = std::get<GREEN>(_rgb);
	int& bl = std::get<BLUE>(_rgb);
	SetDrawBlendMode(_bm, a);
	SetDrawBright(re, gr, bl);
	auto GC = g.GetChip();
	auto x = _xy.first + _mxy.first;
	auto y = _xy.second + _mxy.second;
	double scale = _drg.first;
	double angle = _drg.second;
	auto cx = static_cast<int>(x);
	auto cy = static_cast<int>(y);
	DrawRotaGraph(cx, cy, scale, angle, _GrHandle, true, _isFlip);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawBright(255, 255, 255);
}

