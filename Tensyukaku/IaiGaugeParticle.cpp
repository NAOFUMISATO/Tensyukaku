/*****************************************************************//**
 * \file   IaiGaugeParticle.cpp
 * \brief  居合ゲージMAX時のゲージ側パーティクルクラス（パーティクルベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Game.h"
#include "ResourceServer.h"
#include "IaiGaugeParticle.h"

using namespace IGPInfo;

IaiGaugeParticle::IaiGaugeParticle(std::pair<double, double> xy, std::pair<double, double> dxy, bool flip) {
   _xy = xy;
   _dxy = dxy;
   _isflip = flip;
   Init();
   _grhandle = ResourceServer::LoadGraph(IAIG_PARTICLE_GRAPH);
}
IaiGaugeParticle::~IaiGaugeParticle() {
}

void IaiGaugeParticle::Init() {
   _mxy = std::make_pair(IAIG_PARTICLE_POSITIONX, IAIG_PARTICLE_POSITIONY);
   _bm = IAIG_PARTICLE_BLENDMODE;
   _pal = IAIG_PARTICLE_PAL;
   _rgb = std::make_tuple(IAIG_PARTICLE_RED, IAIG_PARTICLE_GREEN, IAIG_PARTICLE_BLUE);
   _drg = std::make_pair(IAIG_PARTICLE_SCALE, IAIG_PARTICLE_ANGLE);
   _cnt = IAIG_PARTICLE_CNT;
}

void IaiGaugeParticle::Process(Game& g) {
   ParticleBase::Process(g);
}

void IaiGaugeParticle::Draw(Game& g) {
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