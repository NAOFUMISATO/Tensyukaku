#include <DxLib.h>
#include <tuple>
#include <utility>
#include "Game.h"
#include "ResourceServer.h"
#include "EnemyParticle.h"
using namespace EPInfo;
//ÉNÉiÉCìäÇ∞ó\îıìÆçÏÇÃåı
KunaiReserveLight::KunaiReserveLight(std::pair<double, double> xy, std::pair<double, double> dxy, bool flip) {
   _xy = xy;
   _dxy = dxy;
   _isflip = flip;
   Init();
   _grhandle = ResourceServer::LoadGraph(KRESERVELIGHT_PARTICLE_GRAPH);
}
KunaiReserveLight::~KunaiReserveLight() {
}

void KunaiReserveLight::Init() {
   _mxy = std::make_pair(KRESERVELIGHT_PARTICLE_POSITIONX, KRESERVELIGHT_PARTICLE_POSITIONY);
   _bm = KRESERVELIGHT_PARTICLE_BLENDMODE;
   _pal = KRESERVELIGHT_PARTICLE_PAL;
   _rgb = std::make_tuple(KRESERVELIGHT_PARTICLE_RED, KRESERVELIGHT_PARTICLE_GREEN, KRESERVELIGHT_PARTICLE_BLUE);
   _drg = std::make_pair(KRESERVELIGHT_PARTICLE_SCALE, KRESERVELIGHT_PARTICLE_ANGLE);
   _cnt = KRESERVELIGHT_PARTICLE_CNT;
}

void KunaiReserveLight::Process(Game& g) {
   ParticleBase::Process(g);
}

void KunaiReserveLight::Draw(Game& g) {
   ParticleBase::Draw(g);
}
//ëÑï∫ó\îıìÆçÏÇÃåı
LanceReserveLight::LanceReserveLight(std::pair<double, double> xy, std::pair<double, double> dxy, bool flip) {
   _xy = xy;
   _dxy = dxy;
   _isflip = flip;
   Init();
   _grhandle = ResourceServer::LoadGraph(LRESERVELIGHT_PARTICLE_GRAPH);
}
LanceReserveLight::~LanceReserveLight() {
}

void LanceReserveLight::Init() {
   _mxy = std::make_pair(LRESERVELIGHT_PARTICLE_POSITIONX, LRESERVELIGHT_PARTICLE_POSITIONY);
   _bm = LRESERVELIGHT_PARTICLE_BLENDMODE;
   _pal = LRESERVELIGHT_PARTICLE_PAL;
   _rgb = std::make_tuple(LRESERVELIGHT_PARTICLE_RED, LRESERVELIGHT_PARTICLE_GREEN, LRESERVELIGHT_PARTICLE_BLUE);
   _drg = std::make_pair(LRESERVELIGHT_PARTICLE_SCALE, LRESERVELIGHT_PARTICLE_ANGLE);
   _cnt = LRESERVELIGHT_PARTICLE_CNT;
}

void LanceReserveLight::Process(Game& g) {
   ParticleBase::Process(g);
}

void LanceReserveLight::Draw(Game& g) {
   ParticleBase::Draw(g);
}