#include <DxLib.h>
#include <tuple>
#include <utility>
#include "Game.h"
#include "ResourceServer.h"
#include "HitBushiParticle.h"
#include "ParticleBase.h"
using namespace ParInfo;
HitBushiParticle::HitBushiParticle(std::pair<double, double> xy, std::pair<double, double> dxy){
	_xy = xy;
	_dxy = dxy;
	Init();
	_GrHandle=ResourceServer::LoadGraph(HitBushiPar_Graph);
}
HitBushiParticle::~HitBushiParticle() {
}

void HitBushiParticle::Init() {
	_mxy = std::make_pair(HitBushiPar_PozX, HitBushiPar_PozY);
	_bm = HitBushiPar_BLENDMODE;
	_a	= HitBushiPar_Pal;
	_rgb=std::make_tuple(HitBushiPar_Red, HitBushiPar_Green, HitBushiPar_Blue);
	_drg=std::make_tuple(HitBushiPar_Scale, HitBushiPar_Angle, HitBushiPar_Flip);
	_Cnt = HitBushiPar_Cnt;
}

void HitBushiParticle::Process(Game& g) {
	ParticleBase::Process(g);
}

void HitBushiParticle::Draw(Game& g) {
	ParticleBase::Draw(g);
}