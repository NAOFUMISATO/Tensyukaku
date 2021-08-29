#include <DxLib.h>
#include <tuple>
#include <utility>
#include "Game.h"
#include "ResourceServer.h"
#include "LowAttackParticle.h"
#include "ParticleBase.h"
using namespace ParInfo;
LowAttackParticle1::LowAttackParticle1(std::pair<double, double> xy, std::pair<double, double> dxy,bool flip ) {
	_xy = xy;
	_dxy = dxy;
	_isFlip = flip;
	Init();
	_GrHandle = ResourceServer::LoadGraph(LOWATTACK_PARTICLE1_GRAPH);
}
LowAttackParticle1::~LowAttackParticle1() {
}

void LowAttackParticle1::Init() {
	_mxy = std::make_pair(LOWATTACK_PARTICLE1_POSITIONX, LOWATTACK_PARTICLE1_POSITIONY);
	_bm = LOWATTACK_PARTICLE1_BLENDMODE;
	_pal = LOWATTACK_PARTICLE1_PAL;
	_rgb = std::make_tuple(LOWATTACK_PARTICLE1_RED, LOWATTACK_PARTICLE1_GREEN, LOWATTACK_PARTICLE1_BLUE);
	_drg = std::make_pair(LOWATTACK_PARTICLE1_SCALE, LOWATTACK_PARTICLE1_ANGLE);
	_Cnt = LOWATTACK_PARTICLE1_CNT;
}

void LowAttackParticle1::Process(Game& g) {
	ParticleBase::Process(g);
}

void LowAttackParticle1::Draw(Game& g) {
	ParticleBase::Draw(g);
}

LowAttackParticle2::LowAttackParticle2(std::pair<double, double> xy, std::pair<double, double> dxy, bool flip) {
	_xy = xy;
	_dxy = dxy;
	_isFlip = flip;
	Init();
	_GrHandle = ResourceServer::LoadGraph(LOWATTACK_PARTICLE2_GRAPH);
}
LowAttackParticle2::~LowAttackParticle2() {
}

void LowAttackParticle2::Init() {
	_mxy = std::make_pair(LOWATTACK_PARTICLE2_POSITIONX, LOWATTACK_PARTICLE2_POSITIONY);
	_bm = LOWATTACK_PARTICLE2_BLENDMODE;
	_pal = LOWATTACK_PARTICLE2_PAL;
	_rgb = std::make_tuple(LOWATTACK_PARTICLE2_RED, LOWATTACK_PARTICLE2_GREEN, LOWATTACK_PARTICLE2_BLUE);
	_drg = std::make_pair(LOWATTACK_PARTICLE2_SCALE, LOWATTACK_PARTICLE2_ANGLE);
	_Cnt = LOWATTACK_PARTICLE2_CNT;
}

void LowAttackParticle2::Process(Game& g) {
	ParticleBase::Process(g);
}

void LowAttackParticle2::Draw(Game& g) {
	ParticleBase::Draw(g);
}