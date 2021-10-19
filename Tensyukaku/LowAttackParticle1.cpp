/*****************************************************************//**
 * \file   LowAttackParticle1.cpp
 * \brief  下段攻撃パーティクル１クラス（パーティクルベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Game.h"
#include "ResourceServer.h"
#include "LowAttackParticle1.h"

using namespace LP1Info;

LowAttackParticle1::LowAttackParticle1(std::pair<double, double> xy, std::pair<double, double> dxy, bool flip) {
   _xy = xy;
   _dxy = dxy;
   _isflip = flip;
   Init();
   _grhandle = ResourceServer::LoadGraph(LOWATTACK_PARTICLE1_GRAPH);
}
LowAttackParticle1::~LowAttackParticle1() {
}

void LowAttackParticle1::Init() {
   _mxy = std::make_pair(LOWATTACK_PARTICLE1_POSITIONX, LOWATTACK_PARTICLE1_POSITIONY);
   _bm = LOWATTACK_PARTICLE1_BLENDMODE;
   _pal = LOWATTACK_PARTICLE1_PAL;
   _rgb = std::make_tuple(LOWATTACK_PARTICLE1_RED, LOWATTACK_PARTICLE1_GREEN, LOWATTACK_PARTICLE1_BLUE);
   _drg = std::make_pair(LOWATTACK_PARTICLE1_SCALE, LOWATTACK_PARTICLE1_ANGLE);
   _cnt = LOWATTACK_PARTICLE1_CNT;
}

void LowAttackParticle1::Process(Game& g) {
   ParticleBase::Process(g);
}

void LowAttackParticle1::Draw(Game& g) {
   ParticleBase::Draw(g);
}