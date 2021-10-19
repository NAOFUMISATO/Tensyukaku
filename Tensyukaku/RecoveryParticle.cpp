/*****************************************************************//**
 * \file   RecoveryParticle.cpp
 * \brief  �񕜃p�[�e�B�N���N���X�i�p�[�e�B�N���x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Game.h"
#include "ResourceServer.h"
#include "RecoveryParticle.h"

using namespace RPInfo;

RecoveryParticle::RecoveryParticle(std::pair<double, double> xy, std::pair<double, double> dxy) {
   _xy = xy;
   _dxy = dxy;
   Init();
   _grhandle = ResourceServer::LoadGraph(RECOVERY_PARTICLE_GRAPH);
}
RecoveryParticle::~RecoveryParticle() {
}

void RecoveryParticle::Init() {
   _mxy = std::make_pair(RECOVERY_PARTICLE_POSITIONX, RECOVERY_PARTICLE_POSITIONY);
   _bm = RECOVERY_PARTICLE_BLENDMODE;
   _pal = RECOVERY_PARTICLE_PAL;
   _rgb = std::make_tuple(RECOVERY_PARTICLE_RED, RECOVERY_PARTICLE_GREEN, RECOVERY_PARTICLE_BLUE);
   _drg = std::make_pair(RECOVERY_PARTICLE_SCALE, RECOVERY_PARTICLE_ANGLE);
   _cnt = RECOVERY_PARTICLE_CNT;
   _isflip = false;
}

void RecoveryParticle::Process(Game& g) {
   ParticleBase::Process(g);
}

void RecoveryParticle::Draw(Game& g) {
   ParticleBase::Draw(g);
}
