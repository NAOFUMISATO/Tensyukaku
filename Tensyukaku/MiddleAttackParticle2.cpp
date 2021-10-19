/*****************************************************************//**
 * \file   MiddleAttackParticle2.cpp
 * \brief  中段攻撃パーティクル２クラス（パーティクルベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Game.h"
#include "ResourceServer.h"
#include "MiddleAttackParticle2.h"

using namespace MP2Info;

MiddleAttackParticle2::MiddleAttackParticle2(std::pair<double, double> xy, std::pair<double, double> dxy, bool flip) {
   _xy = xy;
   _dxy = dxy;
   _isflip = flip;
   Init();
   _grhandle = ResourceServer::LoadGraph(MIDDLEATTACK_PARTICLE2_GRAPH);
}
MiddleAttackParticle2::~MiddleAttackParticle2() {
}

void MiddleAttackParticle2::Init() {
   _mxy = std::make_pair(MIDDLEATTACK_PARTICLE2_POSITIONX, MIDDLEATTACK_PARTICLE2_POSITIONY);
   _bm = MIDDLEATTACK_PARTICLE2_BLENDMODE;
   _pal = MIDDLEATTACK_PARTICLE2_PAL;
   _rgb = std::make_tuple(MIDDLEATTACK_PARTICLE2_RED, MIDDLEATTACK_PARTICLE2_GREEN, MIDDLEATTACK_PARTICLE2_BLUE);
   _drg = std::make_pair(MIDDLEATTACK_PARTICLE2_SCALE, MIDDLEATTACK_PARTICLE2_ANGLE);
   _cnt = MIDDLEATTACK_PARTICLE2_CNT;
}

void MiddleAttackParticle2::Process(Game& g) {
   ParticleBase::Process(g);
}

void MiddleAttackParticle2::Draw(Game& g) {
   ParticleBase::Draw(g);
}
