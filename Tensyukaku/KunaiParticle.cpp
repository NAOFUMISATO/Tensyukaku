/*****************************************************************//**
 * \file   KunaiParticle.cpp
 * \brief  クナイ投げ予備動作パーティクルクラス（パーティクルベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ResourceServer.h"
#include "KunaiParticle.h"

using namespace KPInfo;

KunaiParticle::KunaiParticle(std::pair<double, double> xy, std::pair<double, double> dxy, bool flip) {
   _xy = xy;
   _dxy = dxy;
   _isflip = flip;
   Init();
   _grhandle = ResourceServer::LoadGraph(KRESERVELIGHT_PARTICLE_GRAPH);
}
KunaiParticle::~KunaiParticle() {
}

void KunaiParticle::Init() {
   _mxy = std::make_pair(KRESERVELIGHT_PARTICLE_POSITIONX, KRESERVELIGHT_PARTICLE_POSITIONY);
   _bm = KRESERVELIGHT_PARTICLE_BLENDMODE;
   _pal = KRESERVELIGHT_PARTICLE_PAL;
   _rgb = std::make_tuple(KRESERVELIGHT_PARTICLE_RED, KRESERVELIGHT_PARTICLE_GREEN, KRESERVELIGHT_PARTICLE_BLUE);
   _drg = std::make_pair(KRESERVELIGHT_PARTICLE_SCALE, KRESERVELIGHT_PARTICLE_ANGLE);
   _cnt = KRESERVELIGHT_PARTICLE_CNT;
}
void KunaiParticle::Process(Game& g) {
   ParticleBase::Process(g);
}
void KunaiParticle::Draw(Game& g) {
   ParticleBase::Draw(g);
}