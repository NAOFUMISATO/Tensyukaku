/*****************************************************************//**
 * \file   IaiParticle1.cpp
 * \brief  居合パーティクル１クラス(パーティクルベースクラスのサブクラス)
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Game.h"
#include "ResourceServer.h"
#include "IaiParticle1.h"

using namespace IP1Info;

IaiParticle1::IaiParticle1(std::pair<double, double> xy, std::pair<double, double> dxy, bool flip) {
   _xy = xy;
   _dxy = dxy;
   _isflip = flip;
   Init();
   _grhandle = ResourceServer::LoadGraph(IAI_PARTICLE1_GRAPH);
}
IaiParticle1::~IaiParticle1() {
}

void IaiParticle1::Init() {
   _mxy = std::make_pair(IAI_PARTICLE1_POSITIONX, IAI_PARTICLE1_POSITIONY);
   _bm = IAI_PARTICLE1_BLENDMODE;
   _pal = IAI_PARTICLE1_PAL;
   _rgb = std::make_tuple(IAI_PARTICLE1_RED, IAI_PARTICLE1_GREEN, IAI_PARTICLE1_BLUE);
   _drg = std::make_pair(IAI_PARTICLE1_SCALE, IAI_PARTICLE1_ANGLE);
   _cnt = IAI_PARTICLE1_CNT;
}

void IaiParticle1::Process(Game& g) {
   ParticleBase::Process(g);
}

void IaiParticle1::Draw(Game& g) {
   ParticleBase::Draw(g);
}