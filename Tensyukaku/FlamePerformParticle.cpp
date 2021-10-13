#include <DxLib.h>
#include <tuple>
#include <utility>
#include "Game.h"
#include "ResourceServer.h"
#include "FlamePerformParticle.h"
using namespace FParInfo;
//âäââèo
FlamePerform::FlamePerform(std::pair<double, double> xy, std::pair<double, double> dxy, bool flip) {
   _xy = xy;
   _dxy = dxy;
   _isflip = flip;
   Init();
   _grhandle = ResourceServer::LoadGraph(FLAME_GRAPH);
}
FlamePerform::~FlamePerform() {
}

void FlamePerform::Init() {
   _mxy = std::make_pair(FLAME_POSITIONX, FLAME_POSITIONY);
   _bm = FLAME_BLENDMODE;
   _pal = FLAME_PAL;
   _rgb = std::make_tuple(FLAME_RED, FLAME_GREEN, FLAME_BLUE);
   _drg = std::make_pair(FLAME_SCALE, FLAME_ANGLE);
   _cnt = FLAME_CNT;
}

void FlamePerform::Process(Game& g) {
   ParticleBase::Process(g);
}

void FlamePerform::Draw(Game& g) {
   int a = _pal;
   int& re = std::get<0>(_rgb);
   int& gr = std::get<1>(_rgb);
   int& bl = std::get<2>(_rgb);
   SetDrawBlendMode(_bm, a);
   SetDrawBright(re, gr, bl);
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