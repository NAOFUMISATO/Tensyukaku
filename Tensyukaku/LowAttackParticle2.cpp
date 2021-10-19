/*****************************************************************//**
 * \file   LowAttackParticle2.cpp
 * \brief  下段攻撃パーティクル２クラス（パーティクルベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Game.h"
#include "ResourceServer.h"
#include "LowAttackParticle2.h"

using namespace LP2Info;

LowAttackParticle2::LowAttackParticle2(std::pair<double, double> xy, std::pair<double, double> dxy, bool flip) {
   _xy = xy;
   _dxy = dxy;
   _isflip = flip;
   Init();
   _grhandle = ResourceServer::LoadGraph(LOWATTACK_PARTICLE2_GRAPH);
}
LowAttackParticle2::~LowAttackParticle2() {
}

void LowAttackParticle2::Init() {
   _mxy = std::make_pair(LOWATTACK_PARTICLE2_POSITIONX, LOWATTACK_PARTICLE2_POSITIONY);
   _bm = LOWATTACK_PARTICLE2_BLENDMODE;
   _pal = LOWATTACK_PARTICLE2_PAL;
   _rgb = std::make_tuple(LOWATTACK_PARTICLE2_RED, LOWATTACK_PARTICLE2_GREEN, LOWATTACK_PARTICLE2_BLUE);
   _drg = std::make_pair(LOWATTACK_PARTICLE2_SCALE, LOWATTACK_PARTICLE2_ANGLE);
   _cnt = LOWATTACK_PARTICLE2_CNT;
}

void LowAttackParticle2::Process(Game& g) {
   ParticleBase::Process(g);
}

void LowAttackParticle2::Draw(Game& g) {
   ParticleBase::Draw(g);
}