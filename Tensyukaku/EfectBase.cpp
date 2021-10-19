/*****************************************************************//**
 * \file   EfectBase.cpp
 * \brief  �G�t�F�N�g�x�[�X�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "EfectBase.h"
#include "Game.h"

EfectBase::EfectBase() {
   Init();
}
EfectBase::~EfectBase() {
}

void   EfectBase::Init() {
   _sort = 15;
}

void EfectBase::Process(Game& g) {
   ObjectBase::Process(g);
}

void EfectBase::Draw(Game& g) {
   auto GC = g.GetChip();
   auto x = _x + _gx - GC->GetscrX();
   auto y = _y + _gy - GC->GetscrY();
   auto scale = _drg.first;
   auto angle = _drg.second;
   SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
   DrawRotaGraph(x,y, scale, angle, _grhandle, true, _isflip);
   SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}