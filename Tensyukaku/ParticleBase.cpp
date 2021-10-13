#include <DxLib.h>
#include <utility>
#include <tuple>
#include "ParticleBase.h"
#include "Game.h"
namespace {
/*----------Tupleå^â¬ì«ê´å¸è„---------*/
   constexpr auto RED = 0;
   constexpr auto GREEN = 1;
   constexpr auto BLUE = 2;
}
ParticleBase::ParticleBase() {
   Init();
}
ParticleBase::~ParticleBase() {};

void ParticleBase::Init() {
   _sort = 15;
}

void ParticleBase::Process(Game& g) {
   _xy.first += _dxy.first;
   _xy.second += _dxy.second;
   _cnt--;
   if (_cnt <= 0) {
      g.GetOS()->Del(this);
   }
}

void ParticleBase::Draw(Game& g) {
   int a = _pal;
   int& re = std::get<RED>(_rgb);
   int& gr = std::get<GREEN>(_rgb);
   int& bl = std::get<BLUE>(_rgb);
   SetDrawBlendMode(_bm, a);
   SetDrawBright(re,gr,bl);
   auto GC = g.GetChip();
   auto x = _xy.first + _mxy.first - GC->GetscrX();
   auto y = _xy.second + _mxy.second - GC->GetscrY();
   double scale = _drg.first;
   double angle = _drg.second;
   auto cx = static_cast<int>(x);
   auto cy = static_cast<int>(y);
   DrawRotaGraph(cx, cy, scale, angle, _grhandle, true, _isflip);
   SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
   SetDrawBright(255, 255, 255);
}

