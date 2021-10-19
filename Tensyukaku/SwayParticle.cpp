/*****************************************************************//**
 * \file   SwayParticle.cpp
 * \brief  スウェイパーティクルクラス（パーティクルベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Game.h"
#include "ResourceServer.h"
#include "SwayParticle.h"

using namespace SPInfo;

SwayParticle::SwayParticle(std::pair<double, double> xy, std::pair<double, double> dxy, bool flip) {
   _xy = xy;
   _dxy = dxy;
   _isflip = flip;
   Init();
   _grhandle = ResourceServer::LoadGraph(SWAY_PARTICLE_GRAPH);
}
SwayParticle::~SwayParticle() {
}

void SwayParticle::Init() {
   _mxy = std::make_pair(SWAY_PARTICLE_POSITIONX, SWAY_PARTICLE_POSITIONY);
   _bm = SWAY_PARTICLE_BLENDMODE;
   _pal = SWAY_PARTICLE_PAL;
   _rgb = std::make_tuple(SWAY_PARTICLE_RED, SWAY_PARTICLE_GREEN, SWAY_PARTICLE_BLUE);
   _drg = std::make_pair(SWAY_PARTICLE_SCALE, SWAY_PARTICLE_ANGLE);
   _cnt = SWAY_PARTICLE_CNT;
}

void SwayParticle::Process(Game& g) {
   ParticleBase::Process(g);
}

void SwayParticle::Draw(Game& g) {
   ParticleBase::Draw(g);
}
