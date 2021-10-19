/*****************************************************************//**
 * \file   CusorParticle.cpp
 * \brief  �^�C�g���J�[�\���p�[�e�B�N���N���X�i�p�[�e�B�N���x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Game.h"
#include "ResourceServer.h"
#include "CusorParticle.h"
#include "ParticleBase.h"

namespace {
   constexpr auto RED = 0;    //!< tuple�^�ǐ�����
   constexpr auto GREEN = 1;  //!< tuple�^�ǐ�����
   constexpr auto BLUE = 2;   //!< tuple�^�ǐ�����
}
using namespace CParInfo;
CursorParticle::CursorParticle(std::pair<double, double> xy, std::pair<double, double> dxy,std::string hittype){
   _xy = xy;
   _dxy = dxy;
   _hit_type = hittype;
   Init();
   _grhandle = ResourceServer::LoadGraph(CURSOR_PARTICLE1_GRAPH);
}
CursorParticle::~CursorParticle() {
}

void CursorParticle::Init() {
   SetType();
   _mxy = std::make_pair(CURSOR_PARTICLE1_POSITIONX, CURSOR_PARTICLE1_POSITIONY);
   _bm = CURSOR_PARTICLE1_BLENDMODE;
   _pal =50;
   _drg = std::make_pair(CURSOR_PARTICLE1_SCALE, CURSOR_PARTICLE1_ANGLE);
}
void CursorParticle::Process(Game& g) {
   ParticleBase::Process(g);

}

void CursorParticle::Draw(Game& g) {
   int a = _pal;
   int& re = std::get<RED>(_rgb);
   int& gr = std::get<GREEN>(_rgb);
   int& bl = std::get<BLUE>(_rgb);
   SetDrawBlendMode(_bm, a);
   SetDrawBright(re, gr, bl);
   auto GC = g.GetChip();
   auto x = _xy.first + _mxy.first;
   auto y = _xy.second + _mxy.second;
   double scale = _drg.first;
   double angle = _drg.second;
   auto cx = static_cast<int>(x);
   auto cy = static_cast<int>(y);
   DrawRotaGraph(cx, cy, scale, angle, _grhandle, true, _isflip);
   SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
   SetDrawBright(255, 255, 255);
}

void CursorParticle::SetType() {
   if (_hit_type == "NOHIT") {
      _rgb = std::make_tuple(240,70, 5);
      _cnt =30;
   }
   else if (_hit_type == "STARTHIT") {
      _rgb = std::make_tuple(240, 70, 5);
      _cnt = 50;
   }
   else if (_hit_type == "EXHIT") {
      _rgb = std::make_tuple(240, 70, 5);
      _cnt = 50;
   }
   else if (_hit_type == "ENDHIT") {
      _rgb = std::make_tuple(240, 70, 5);
      _cnt = 50;
   }
   else if (_hit_type == "CREDITHIT") {
      _rgb = std::make_tuple(240, 70, 5);
      _cnt = 50;
   }
};
