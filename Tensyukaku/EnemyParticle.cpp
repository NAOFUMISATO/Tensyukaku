#include <DxLib.h>
#include <tuple>
#include <utility>
#include "Game.h"
#include "ResourceServer.h"
#include "EnemyParticle.h"
using namespace EPInfo;
//çUåÇó\îıìÆçÏÇÃåı
ReserveLight::ReserveLight(std::pair<double, double> xy, std::pair<double, double> dxy, bool flip) {
	_xy = xy;
	_dxy = dxy;
	_isflip = flip;
	Init();
	_grhandle = ResourceServer::LoadGraph(RESERVELIGHT_PARTICLE_GRAPH);
}
ReserveLight::~ReserveLight() {
}

void ReserveLight::Init() {
	_mxy = std::make_pair(RESERVELIGHT_PARTICLE_POSITIONX, RESERVELIGHT_PARTICLE_POSITIONY);
	_bm = RESERVELIGHT_PARTICLE_BLENDMODE;
	_pal = RESERVELIGHT_PARTICLE_PAL;
	_rgb = std::make_tuple(RESERVELIGHT_PARTICLE_RED, RESERVELIGHT_PARTICLE_GREEN, RESERVELIGHT_PARTICLE_BLUE);
	_drg = std::make_pair(RESERVELIGHT_PARTICLE_SCALE, RESERVELIGHT_PARTICLE_ANGLE);
	_cnt = RESERVELIGHT_PARTICLE_CNT;
}

void ReserveLight::Process(Game& g) {
	ParticleBase::Process(g);
}

void ReserveLight::Draw(Game& g) {
	ParticleBase::Draw(g);
}