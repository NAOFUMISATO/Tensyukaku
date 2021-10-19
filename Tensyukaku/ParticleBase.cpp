/*****************************************************************//**
 * \file   ParticleBase.cpp
 * \brief  �e�p�[�e�B�N���̃x�[�X�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ParticleBase.h"
#include "Game.h"

namespace {
   constexpr auto RED = 0;    //!< tuple�^�ǐ�����
   constexpr auto GREEN = 1;  //!< tuple�^�ǐ�����
   constexpr auto BLUE = 2;   //!< tuple�^�ǐ�����
}
ParticleBase::ParticleBase() {
   Init();
}
ParticleBase::~ParticleBase() {};

void ParticleBase::Init() {
   _sort = 15;
}

void ParticleBase::Process(Game& g) {
   _xy.first += _dxy.first;
   _xy.second += _dxy.second;
   _cnt--;
   if (_cnt <= 0) {
      g.GetOS()->Del(this);
   }
}

void ParticleBase::Draw(Game& g) {
   int a = _pal;
   int& re = std::get<RED>(_rgb);
   int& gr = std::get<GREEN>(_rgb);
   int& bl = std::get<BLUE>(_rgb);
   SetDrawBlendMode(_bm, a);
   SetDrawBright(re,gr,bl);
   auto GC = g.GetChip();
   auto x = _xy.first + _mxy.first - GC->GetscrX();
   auto y = _xy.second + _mxy.second - GC->GetscrY();
   double scale = _drg.first;
   double angle = _drg.second;
   auto cx = static_cast<int>(x);
   auto cy = static_cast<int>(y);
   DrawRotaGraph(cx, cy, scale, angle, _grhandle, true, _isflip);
   SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
   SetDrawBright(255, 255, 255);
}

