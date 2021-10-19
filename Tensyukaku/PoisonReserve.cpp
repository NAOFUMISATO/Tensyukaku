/*****************************************************************//**
 * \file   PoisonReserve.cpp
 * \brief  毒液準備クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "PoisonReserve.h"
#include "PoisonFall.h"
#include "PoisonNinja.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
#include "Game.h"

using namespace PoInfo;

PoisonReserve::PoisonReserve(int x, int y) {
   _x = x;
   _y = y;
   Init();
   _grall["Reserve"].resize(RESERVE_ANIMEMAX);
   ResourceServer::LoadDivGraph(RESERVE_GRAPHNAME, RESERVE_ANIMEMAX, RESERVE_WIDTHCOUNT, RESERVE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Reserve"].data());

}

PoisonReserve::~PoisonReserve() {
};

void PoisonReserve::Init() {
   _gx = GRAPHPOINT_X;
   _gy = GRAPHPOINT_Y;
   _alpha = 255;
   _debug_alpha = 0;
   _action_cnt = _cnt;
}

void PoisonReserve::Process(Game& g) {
   ObjectBase::Process(g);
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["Reserve"][_anime["Reserve"]];
   if (frame < RESERVE_ANIMEFRAME) {
      _anime["Reserve"] = ((frame) / ANIMESPEED_RESERVE) % RESERVE_ANIMEMAX;
   }
   if (frame == RESERVE_FALLFRAME) {
      auto pf = new PoisonFall(_x + _gx, _y + _gy);
      g.GetOS()->Add(pf);
   }
   if (frame >= RESERVE_ANIMEFRAME && frame < RESERVE_ALLFRAME) {
      _alpha -= RESERVE_FADEOUTSPEED;
   }
   if (frame == RESERVE_ALLFRAME) {
      Delete(g);
   }
}

void PoisonReserve::Draw(Game& g) {
   SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
   ObjectBase::Draw(g);
}

void PoisonReserve::Delete(Game& g) {
   g.GetOS()->Del(this);
}
