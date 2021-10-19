/*****************************************************************//**
 * \file   IaiParticle2.cpp
 * \brief  居合パーティクル２クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Game.h"
#include "ResourceServer.h"
#include "IaiParticle2.h"

using namespace IP2Info;

IaiParticle2::IaiParticle2(std::pair<double, double> xy, std::pair<double, double> dxy, bool flip) {
   _xy = xy;
   _dxy = dxy;
   _isflip = flip;
   Init();
   _grhandle = ResourceServer::LoadGraph(IAI_PARTICLE2_GRAPH);
}
IaiParticle2::~IaiParticle2() {
}

void IaiParticle2::Init() {
   _mxy = std::make_pair(IAI_PARTICLE2_POSITIONX, IAI_PARTICLE2_POSITIONY);
   _bm = IAI_PARTICLE2_BLENDMODE;
   _pal = IAI_PARTICLE2_PAL;
   _rgb = std::make_tuple(IAI_PARTICLE2_RED, IAI_PARTICLE2_GREEN, IAI_PARTICLE2_BLUE);
   _drg = std::make_pair(IAI_PARTICLE2_SCALE, IAI_PARTICLE2_ANGLE);
   _cnt = IAI_PARTICLE2_CNT;

}

void IaiParticle2::Process(Game& g) {
   ParticleBase::Process(g);
}

void IaiParticle2::Draw(Game& g) {
   ParticleBase::Draw(g);
}
