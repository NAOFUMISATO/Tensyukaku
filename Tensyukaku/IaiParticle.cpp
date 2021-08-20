#include <DxLib.h>
#include <tuple>
#include <utility>
#include "Game.h"
#include "ResourceServer.h"
#include "IaiParticle.h"
#include "ParticleBase.h"
using namespace ParInfo;
IaiParticle1::IaiParticle1(std::pair<double, double> xy, std::pair<double, double> dxy) {
	_xy = xy;
	_dxy = dxy;
	Init();
	_GrHandle = ResourceServer::LoadGraph(IaiPar1_Graph);
}
IaiParticle1::~IaiParticle1() {
}

void IaiParticle1::Init() {
	_mxy = std::make_pair(IaiPar1_PozX, IaiPar1_PozY);
	_bm = IaiPar1_BLENDMODE;
	_pal = IaiPar1_Pal;
	_rgb = std::make_tuple(IaiPar1_Red, IaiPar1_Green, IaiPar1_Blue);
	_drg = std::make_pair(IaiPar1_Scale, IaiPar1_Angle);
	_Cnt = IaiPar1_Cnt;
	_isFlip = false;
}

void IaiParticle1::Process(Game& g) {
	ParticleBase::Process(g);
}

void IaiParticle1::Draw(Game& g) {
	ParticleBase::Draw(g);
}

IaiParticle2::IaiParticle2(std::pair<double, double> xy, std::pair<double, double> dxy) {
	_xy = xy;
	_dxy = dxy;
	Init();
	_GrHandle = ResourceServer::LoadGraph(IaiPar2_Graph);
}
IaiParticle2::~IaiParticle2() {
}

void IaiParticle2::Init() {
	_mxy = std::make_pair(IaiPar2_PozX, IaiPar2_PozY);
	_bm = IaiPar2_BLENDMODE;
	_pal = IaiPar2_Pal;
	_rgb = std::make_tuple(IaiPar2_Red, IaiPar2_Green, IaiPar2_Blue);
	_drg = std::make_pair(IaiPar2_Scale, IaiPar2_Angle);
	_Cnt = IaiPar2_Cnt;
	_isFlip = false;
}

void IaiParticle2::Process(Game& g) {
	ParticleBase::Process(g);
}

void IaiParticle2::Draw(Game& g) {
	ParticleBase::Draw(g);
}

IaiParticle3::IaiParticle3(std::pair<double, double> xy, std::pair<double, double> dxy) {
	_xy = xy;
	_dxy = dxy;
	Init();
	_GrHandle = ResourceServer::LoadGraph(IaiPar3_Graph);
}
IaiParticle3::~IaiParticle3() {
}

void IaiParticle3::Init() {
	_mxy = std::make_pair(IaiPar3_PozX, IaiPar3_PozY);
	_bm = IaiPar3_BLENDMODE;
	_pal = IaiPar3_Pal;
	_rgb = std::make_tuple(IaiPar3_Red, IaiPar3_Green, IaiPar3_Blue);
	_drg = std::make_pair(IaiPar3_Scale, IaiPar3_Angle);
	_Cnt = IaiPar3_Cnt;
	_isFlip = false;
}

void IaiParticle3::Process(Game& g) {
	ParticleBase::Process(g);
}

void IaiParticle3::Draw(Game& g) {
	ParticleBase::Draw(g);
}