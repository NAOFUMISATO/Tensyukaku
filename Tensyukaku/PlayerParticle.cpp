#include <DxLib.h>
#include <tuple>
#include <utility>
#include "Game.h"
#include "ResourceServer.h"
#include "PlayerParticle.h"
#include "ParticleBase.h"
using namespace PParInfo;
//���i�U��1
MiddleAttackParticle1::MiddleAttackParticle1(std::pair<double, double> xy, std::pair<double, double> dxy, bool flip) {
	_xy = xy;
	_dxy = dxy;
	_isFlip = flip;
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
}

void MiddleAttackParticle1::Process(Game& g) {
	ParticleBase::Process(g);
}

void MiddleAttackParticle1::Draw(Game& g) {
	ParticleBase::Draw(g);
}
//���i�U��2
MiddleAttackParticle2::MiddleAttackParticle2(std::pair<double, double> xy, std::pair<double, double> dxy, bool flip) {
	_xy = xy;
	_dxy = dxy;
	_isFlip = flip;
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
}

void MiddleAttackParticle2::Process(Game& g) {
	ParticleBase::Process(g);
}

void MiddleAttackParticle2::Draw(Game& g) {
	ParticleBase::Draw(g);
}
//���i�U��1
LowAttackParticle1::LowAttackParticle1(std::pair<double, double> xy, std::pair<double, double> dxy, bool flip) {
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
//���i�U��2
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
//����1
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
	_drg = std::make_pair(IAI_PARTICLE1_SCALE, IAI_PARTICLE1_ANGLE);
	_Cnt = IAI_PARTICLE1_CNT;
}

void IaiParticle1::Process(Game& g) {
	ParticleBase::Process(g);
}

void IaiParticle1::Draw(Game& g) {
	ParticleBase::Draw(g);
}
//����2
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
	_drg = std::make_pair(IAI_PARTICLE2_SCALE, IAI_PARTICLE2_ANGLE);
	_Cnt = IAI_PARTICLE2_CNT;
}

void IaiParticle2::Process(Game& g) {
	ParticleBase::Process(g);
}

void IaiParticle2::Draw(Game& g) {
	ParticleBase::Draw(g);
}
//����3
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
	_drg = std::make_pair(IAI_PARTICLE3_SCALE, IAI_PARTICLE3_ANGLE);
	_Cnt = IAI_PARTICLE3_CNT;
}

void IaiParticle3::Process(Game& g) {
	ParticleBase::Process(g);
}

void IaiParticle3::Draw(Game& g) {
	ParticleBase::Draw(g);
}