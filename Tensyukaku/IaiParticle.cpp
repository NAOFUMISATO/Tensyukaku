#include <DxLib.h>
#include <tuple>
#include <utility>
#include "Game.h"
#include "ResourceServer.h"
#include "IaiParticle.h"
#include "ParticleBase.h"
using namespace ParInfo;
IaiParticle1::IaiParticle1(std::pair<double, double> xy, std::pair<double, double> dxy, bool flip) {
	_xy = xy;
	_dxy = dxy;
	_isFlip = flip;
	Init();
	_GrHandle = ResourceServer::LoadGraph(IAI_PARTICLE1_GRAPH);
}
IaiParticle1::~IaiParticle1() {
}

void IaiParticle1::Init() {
	_mxy = std::make_pair(IAI_PARTICLE1_POSITIONX, IAI_PARTICLE1_POSITIONY);
	_bm = IAI_PARTICLE1_BLENDMODE;
	_pal = IAI_PARTICLE1_PAL;
	_rgb = std::make_tuple(IAI_PARTICLE1_RED, IAI_PARTICLE1_GREEN, IAI_PARTICLE1_BLUE);
	_Drg = std::make_pair(IAI_PARTICLE1_SCALE, IAI_PARTICLE1_ANGLE);
	_Cnt = IAI_PARTICLE1_CNT;	
}

void IaiParticle1::Process(Game& g) {
	ParticleBase::Process(g);
}

void IaiParticle1::Draw(Game& g) {
	ParticleBase::Draw(g);
}

IaiParticle2::IaiParticle2(std::pair<double, double> xy, std::pair<double, double> dxy, bool flip) {
	_xy = xy;
	_dxy = dxy;
	_isFlip = flip;
	Init();
	_GrHandle = ResourceServer::LoadGraph(IAI_PARTICLE2_GRAPH);
}
IaiParticle2::~IaiParticle2() {
}

void IaiParticle2::Init() {
	_mxy = std::make_pair(IAI_PARTICLE2_POSITIONX, IAI_PARTICLE2_POSITIONY);
	_bm = IAI_PARTICLE2_BLENDMODE;
	_pal = IAI_PARTICLE2_PAL;
	_rgb = std::make_tuple(IAI_PARTICLE2_RED, IAI_PARTICLE2_GREEN, IAI_PARTICLE2_BLUE);
	_Drg = std::make_pair(IAI_PARTICLE2_SCALE, IAI_PARTICLE2_ANGLE);
	_Cnt = IAI_PARTICLE2_CNT;
}

void IaiParticle2::Process(Game& g) {
	ParticleBase::Process(g);
}

void IaiParticle2::Draw(Game& g) {
	ParticleBase::Draw(g);
}

IaiParticle3::IaiParticle3(std::pair<double, double> xy, std::pair<double, double> dxy, bool flip) {
	_xy = xy;
	_dxy = dxy;
	_isFlip = flip;
	Init();
	_GrHandle = ResourceServer::LoadGraph(IAI_PARTICLE3_GRAPH);
}
IaiParticle3::~IaiParticle3() {
}

void IaiParticle3::Init() {
	_mxy = std::make_pair(IAI_PARTICLE3_POSITIONX, IAI_PARTICLE3_POSITIONY);
	_bm = IAI_PARTICLE3_BLENDMODE;
	_pal = IAI_PARTICLE3_PAL;
	_rgb = std::make_tuple(IAI_PARTICLE3_RED, IAI_PARTICLE3_GREEN, IAI_PARTICLE3_BLUE);
	_Drg = std::make_pair(IAI_PARTICLE3_SCALE, IAI_PARTICLE3_ANGLE);
	_Cnt = IAI_PARTICLE3_CNT;
}

void IaiParticle3::Process(Game& g) {
	ParticleBase::Process(g);
}

void IaiParticle3::Draw(Game& g) {
	ParticleBase::Draw(g);
}