/*****************************************************************//**
 * \file   LanceParticle.cpp
 * \brief  槍兵予備動作パーティクルクラス（パーティクルベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ResourceServer.h"
#include "LanceParticle.h"

using namespace LPInfo;

LanceParticle::LanceParticle(std::pair<double, double> xy, std::pair<double, double> dxy, bool flip) {
   _xy = xy;
   _dxy = dxy;
   _isflip = flip;
   Init();
   _grhandle = ResourceServer::LoadGraph(LRESERVELIGHT_PARTICLE_GRAPH);
}
LanceParticle::~LanceParticle() {
}

void LanceParticle::Init() {
   _mxy = std::make_pair(LRESERVELIGHT_PARTICLE_POSITIONX, LRESERVELIGHT_PARTICLE_POSITIONY);
   _bm = LRESERVELIGHT_PARTICLE_BLENDMODE;
   _pal = LRESERVELIGHT_PARTICLE_PAL;
   _rgb = std::make_tuple(LRESERVELIGHT_PARTICLE_RED, LRESERVELIGHT_PARTICLE_GREEN, LRESERVELIGHT_PARTICLE_BLUE);
   _drg = std::make_pair(LRESERVELIGHT_PARTICLE_SCALE, LRESERVELIGHT_PARTICLE_ANGLE);
   _cnt = LRESERVELIGHT_PARTICLE_CNT;
}

void LanceParticle::Process(Game& g) {
   ParticleBase::Process(g);
}

void LanceParticle::Draw(Game& g) {
   ParticleBase::Draw(g);
}