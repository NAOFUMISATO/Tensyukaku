#include <DxLib.h>
#include <tuple>
#include <utility>
#include "Game.h"
#include "ResourceServer.h"
#include "OutGameParticle.h"
#include "ParticleBase.h"
namespace {
	/*----------Tuple型可読性向上---------*/
	constexpr auto RED = 0;
	constexpr auto GREEN = 1;
	constexpr auto BLUE = 2;
}
using namespace CParInfo;
CursorParticle1::CursorParticle1(std::pair<double, double> xy, std::pair<double, double> dxy,std::string hittype){
	_xy = xy;
	_dxy = dxy;
	_hit_type = hittype;
	Init();
	_grhandle = ResourceServer::LoadGraph(CURSOR_PARTICLE1_GRAPH);
}
CursorParticle1::~CursorParticle1() {
}

void CursorParticle1::Init() {
	SetState();
	_mxy = std::make_pair(CURSOR_PARTICLE1_POSITIONX, CURSOR_PARTICLE1_POSITIONY);
	_bm = CURSOR_PARTICLE1_BLENDMODE;
	_pal =50;
	_drg = std::make_pair(CURSOR_PARTICLE1_SCALE, CURSOR_PARTICLE1_ANGLE);
}
void CursorParticle1::Process(Game& g) {
	ParticleBase::Process(g);

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

void CursorParticle1::SetState() {
	if (_hit_type == "NOHIT") {
		_rgb = std::make_tuple(240,70, 5);
		_cnt =30;
	}
	else if (_hit_type == "STARTHIT") {
		_rgb = std::make_tuple(240, 70, 5);
		_cnt = 70;
	}
	else if (_hit_type == "EXHIT") {
		_rgb = std::make_tuple(240, 70, 5);
		_cnt = 70;
	}
	else if (_hit_type == "ENDHIT") {
		_rgb = std::make_tuple(240, 70, 5);
		_cnt = 70;
	}
	else if (_hit_type == "CREDITHIT") {
		_rgb = std::make_tuple(240, 70, 5);
		_cnt = 70;
	}
};
