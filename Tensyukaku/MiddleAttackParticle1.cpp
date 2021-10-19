/*****************************************************************//**
 * \file   MiddleAttackParticle1.cpp
 * \brief  中段攻撃パーティクル１クラス（パーティクルベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Game.h"
#include "ResourceServer.h"
#include "MiddleAttackParticle1.h"

using namespace MP1Info;

MiddleAttackParticle1::MiddleAttackParticle1(std::pair<double, double> xy, std::pair<double, double> dxy, bool flip) {
   _xy = xy;
   _dxy = dxy;
   _isflip = flip;
   Init();
   _grhandle = ResourceServer::LoadGraph(MIDDLEATTACK_PARTICLE1_GRAPH);
}
MiddleAttackParticle1::~MiddleAttackParticle1() {
}

void MiddleAttackParticle1::Init() {
   _mxy = std::make_pair(MIDDLEATTACK_PARTICLE1_POSITIONX, MIDDLEATTACK_PARTICLE1_POSITIONY);
   _bm = MIDDLEATTACK_PARTICLE1_BLENDMODE;
   _pal = MIDDLEATTACK_PARTICLE1_PAL;
   _rgb = std::make_tuple(MIDDLEATTACK_PARTICLE1_RED, MIDDLEATTACK_PARTICLE1_GREEN, MIDDLEATTACK_PARTICLE1_BLUE);
   _drg = std::make_pair(MIDDLEATTACK_PARTICLE1_SCALE, MIDDLEATTACK_PARTICLE1_ANGLE);
   _cnt = MIDDLEATTACK_PARTICLE1_CNT;
}

void MiddleAttackParticle1::Process(Game& g) {
   ParticleBase::Process(g);
}

void MiddleAttackParticle1::Draw(Game& g) {
   ParticleBase::Draw(g);
}
