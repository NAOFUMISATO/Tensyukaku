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
	_GrHandle = ResourceServer::LoadGraph(MiddleAttackPar1_Graph);
}
MiddleAttackParticle1::~MiddleAttackParticle1() {
}

void MiddleAttackParticle1::Init() {
	_mxy = std::make_pair(MiddleAttackPar1_PozX, MiddleAttackPar1_PozY);
	_bm = MiddleAttackPar1_BLENDMODE;
	_a = MiddleAttackPar1_Pal;
	_rgb = std::make_tuple(MiddleAttackPar1_Red, MiddleAttackPar1_Green, MiddleAttackPar1_Blue);
	_drg = std::make_pair(MiddleAttackPar1_Scale, MiddleAttackPar1_Angle);
	_Cnt = MiddleAttackPar1_Cnt;
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
	_GrHandle = ResourceServer::LoadGraph(MiddleAttackPar2_Graph);
}
MiddleAttackParticle2::~MiddleAttackParticle2() {
}

void MiddleAttackParticle2::Init() {
	_mxy = std::make_pair(MiddleAttackPar2_PozX, MiddleAttackPar2_PozY);
	_bm = MiddleAttackPar2_BLENDMODE;
	_a = MiddleAttackPar2_Pal;
	_rgb = std::make_tuple(MiddleAttackPar2_Red, MiddleAttackPar2_Green, MiddleAttackPar2_Blue);
	_drg = std::make_pair(MiddleAttackPar2_Scale, MiddleAttackPar2_Angle);
	_Cnt = MiddleAttackPar2_Cnt;
	_isFlip = false;
}

void MiddleAttackParticle2::Process(Game& g) {
	ParticleBase::Process(g);
}

void MiddleAttackParticle2::Draw(Game& g) {
	ParticleBase::Draw(g);
}