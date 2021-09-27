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
	_grhandle = ResourceServer::LoadGraph(CURSOR_PARTICLE1_GRAPH);
}
CursorParticle1::~CursorParticle1() {
}

void CursorParticle1::Init() {
	_mxy = std::make_pair(CURSOR_PARTICLE1_POSITIONX, CURSOR_PARTICLE1_POSITIONY);
	_bm = DX_BLENDMODE_PMA_ADD;
	_pal =50;
	_rgb = std::make_tuple(230, 70, 5);
	_drg = std::make_pair(CURSOR_PARTICLE1_SCALE, CURSOR_PARTICLE1_ANGLE);
	_cnt = CURSOR_PARTICLE1_CNT;
}

void CursorParticle1::Process(Game& g) {
	ParticleBase::Process(g);
	switch (_ColorType) {
	case 0:
		_bm = DX_BLENDMODE_PMA_ADD;
		_pal = 50;
		_rgb = std::make_tuple(240, 70, 5);
		break;
	case 1:
		_bm = DX_BLENDMODE_PMA_ADD;
		_pal = 50;
		_rgb = std::make_tuple(5, 70, 240);
		break;
	case 2:
		_bm = DX_BLENDMODE_PMA_SUB;
		_pal = 240;
		_rgb = std::make_tuple(240, 70, 5);
		break;
	case 3:
		_bm = DX_BLENDMODE_PMA_SUB;
		_pal = 240;
		_rgb = std::make_tuple(5, 70, 240);
		break;
	case 4:
		_bm = DX_BLENDMODE_PMA_SUB;
		_pal = 240;
		_rgb = std::make_tuple(7,7,240);
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
	DrawRotaGraph(cx, cy, scale, angle, _grhandle, true, _isflip);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawBright(255, 255, 255);
}

