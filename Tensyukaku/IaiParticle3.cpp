/*****************************************************************//**
 * \file   IaiParticle3.cpp
 * \brief  居合パーティクル３クラス（パーティクルベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Game.h"
#include "ResourceServer.h"
#include "IaiParticle3.h"

using namespace IP3Info;
//居合3
IaiParticle3::IaiParticle3(std::pair<double, double> xy, std::pair<double, double> dxy, bool flip) {
   _xy = xy;
   _dxy = dxy;
   _isflip = flip;
   Init();
   _grhandle = ResourceServer::LoadGraph(IAI_PARTICLE3_GRAPH);
}
IaiParticle3::~IaiParticle3() {
}

void IaiParticle3::Init() {
   _mxy = std::make_pair(IAI_PARTICLE3_POSITIONX, IAI_PARTICLE3_POSITIONY);
   _bm = IAI_PARTICLE3_BLENDMODE;
   _pal = IAI_PARTICLE3_PAL;
   _rgb = std::make_tuple(IAI_PARTICLE3_RED, IAI_PARTICLE3_GREEN, IAI_PARTICLE3_BLUE);
   _drg = std::make_pair(IAI_PARTICLE3_SCALE, IAI_PARTICLE3_ANGLE);
   _cnt = IAI_PARTICLE3_CNT;
}

void IaiParticle3::Process(Game& g) {
   ParticleBase::Process(g);
}

void IaiParticle3::Draw(Game& g) {
   ParticleBase::Draw(g);
}