#include <DxLib.h>
#include <tuple>
#include <utility>
#include "Game.h"
#include "ResourceServer.h"
#include "MiddleAttackParticle.h"
#include "ParticleBase.h"
using namespace ParInfo;
MiddleAttackParticle1::MiddleAttackParticle1(std::pair<double, double> xy, std::pair<double, double> dxy) {
	_xy = xy;
	_dxy = dxy;
	Init();
	_GrHandle = ResourceServer::LoadGraph(MIDDLEATTACK_PARTICLE1_GRAPH);
}
MiddleAttackParticle1::~MiddleAttackParticle1() {
}

void MiddleAttackParticle1::Init() {
	_mxy = std::make_pair(MIDDLEATTACK_PARTICLE1_POSITIONX, MIDDLEATTACK_PARTICLE1_POSITIONY);
	_bm = MIDDLEATTACK_PARTICLE1_BLENDMODE;
	_pal = MIDDLEATTACK_PARTICLE1_PAL;
	_rgb = std::make_tuple(MIDDLEATTACK_PARTICLE1_RED, MIDDLEATTACK_PARTICLE1_GREEN, MIDDLEATTACK_PARTICLE1_BLUE);
	_drg = std::make_pair(MIDDLEATTACK_PARTICLE1_SCALE, MIDDLEATTACK_PARTICLE1_ANGLE);
	_Cnt = MIDDLEATTACK_PARTICLE1_CNT;
	_isFlip = false;
}

void MiddleAttackParticle1::Process(Game& g) {
	ParticleBase::Process(g);
}

void MiddleAttackParticle1::Draw(Game& g) {
	ParticleBase::Draw(g);
}

MiddleAttackParticle2::MiddleAttackParticle2(std::pair<double, double> xy, std::pair<double, double> dxy) {
	_xy = xy;
	_dxy = dxy;
	Init();
	_GrHandle = ResourceServer::LoadGraph(MIDDLEATTACK_PARTICLE2_GRAPH);
}
MiddleAttackParticle2::~MiddleAttackParticle2() {
}

void MiddleAttackParticle2::Init() {
	_mxy = std::make_pair(MIDDLEATTACK_PARTICLE2_POSITIONX, MIDDLEATTACK_PARTICLE2_POSITIONY);
	_bm = MIDDLEATTACK_PARTICLE2_BLENDMODE;
	_pal = MIDDLEATTACK_PARTICLE2_PAL;
	_rgb = std::make_tuple(MIDDLEATTACK_PARTICLE2_RED, MIDDLEATTACK_PARTICLE2_GREEN, MIDDLEATTACK_PARTICLE2_BLUE);
	_drg = std::make_pair(MIDDLEATTACK_PARTICLE2_SCALE, MIDDLEATTACK_PARTICLE2_ANGLE);
	_Cnt = MIDDLEATTACK_PARTICLE2_CNT;
	_isFlip = false;
}

void MiddleAttackParticle2::Process(Game& g) {
	ParticleBase::Process(g);
}

void MiddleAttackParticle2::Draw(Game& g) {
	ParticleBase::Draw(g);
}