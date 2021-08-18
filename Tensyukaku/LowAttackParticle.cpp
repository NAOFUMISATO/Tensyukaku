#include <DxLib.h>
#include <tuple>
#include <utility>
#include "Game.h"
#include "ResourceServer.h"
#include "LowAttackParticle.h"
#include "ParticleBase.h"
using namespace ParInfo;
LowAttackParticle1::LowAttackParticle1(std::pair<double, double> xy, std::pair<double, double> dxy) {
	_xy = xy;
	_dxy = dxy;
	Init();
	_GrHandle = ResourceServer::LoadGraph(LowAttackPar1_Graph);
}
LowAttackParticle1::~LowAttackParticle1() {
}

void LowAttackParticle1::Init() {
	_mxy = std::make_pair(LowAttackPar1_PozX, LowAttackPar1_PozY);
	_bm = LowAttackPar1_BLENDMODE;
	_a = LowAttackPar1_Pal;
	_rgb = std::make_tuple(LowAttackPar1_Red, LowAttackPar1_Green, LowAttackPar1_Blue);
	_drg = std::make_pair(LowAttackPar1_Scale, LowAttackPar1_Angle);
	_Cnt = LowAttackPar1_Cnt;
	_isFlip = false;
}

void LowAttackParticle1::Process(Game& g) {
	ParticleBase::Process(g);
}

void LowAttackParticle1::Draw(Game& g) {
	ParticleBase::Draw(g);
}

LowAttackParticle2::LowAttackParticle2(std::pair<double, double> xy, std::pair<double, double> dxy) {
	_xy = xy;
	_dxy = dxy;
	Init();
	_GrHandle = ResourceServer::LoadGraph(LowAttackPar2_Graph);
}
LowAttackParticle2::~LowAttackParticle2() {
}

void LowAttackParticle2::Init() {
	_mxy = std::make_pair(LowAttackPar2_PozX, LowAttackPar2_PozY);
	_bm = LowAttackPar2_BLENDMODE;
	_a = LowAttackPar2_Pal;
	_rgb = std::make_tuple(LowAttackPar2_Red, LowAttackPar2_Green, LowAttackPar2_Blue);
	_drg = std::make_pair(LowAttackPar2_Scale, LowAttackPar2_Angle);
	_Cnt = LowAttackPar2_Cnt;
	_isFlip = false;
}

void LowAttackParticle2::Process(Game& g) {
	ParticleBase::Process(g);
}

void LowAttackParticle2::Draw(Game& g) {
	ParticleBase::Draw(g);
}