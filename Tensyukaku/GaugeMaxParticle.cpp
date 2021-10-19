/*****************************************************************//**
 * \file   GaugeMaxParticle.cpp
 * \brief  居合ゲージMAX時のプレイヤー側パーティクルクラス（パーティクルベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Game.h"
#include "ResourceServer.h"
#include "GaugeMaxParticle.h"

using namespace GMPInfo;

GaugeMaxParticle::GaugeMaxParticle(std::pair<double, double> xy, std::pair<double, double> dxy) {
   _xy = xy;
   _dxy = dxy;
   Init();
   _grhandle = ResourceServer::LoadGraph(GAGEMAX_PARTICLE_GRAPH);
}
GaugeMaxParticle::~GaugeMaxParticle() {
}

void GaugeMaxParticle::Init() {
   _mxy = std::make_pair(GAGEMAX_PARTICLE_POSITIONX, GAGEMAX_PARTICLE_POSITIONY);
   _bm = GAGEMAX_PARTICLE_BLENDMODE;
   _pal = GAGEMAX_PARTICLE_PAL;
   _rgb = std::make_tuple(GAGEMAX_PARTICLE_RED, GAGEMAX_PARTICLE_GREEN, GAGEMAX_PARTICLE_BLUE);
   _drg = std::make_pair(GAGEMAX_PARTICLE_SCALE, GAGEMAX_PARTICLE_ANGLE);
   _cnt = GAGEMAX_PARTICLE_CNT;
   _isflip = false;
}

void GaugeMaxParticle::Process(Game& g) {
   ParticleBase::Process(g);
}

void GaugeMaxParticle::Draw(Game& g) {
   ParticleBase::Draw(g);
}