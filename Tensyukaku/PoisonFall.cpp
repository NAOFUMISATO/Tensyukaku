/*****************************************************************//**
 * \file   PoisonFall.cpp
 * \brief  毒液落下クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "PoisonFall.h"
#include "PoisonNinja.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
#include "Game.h"

using namespace PoInfo;

PoisonFall::PoisonFall(int x, int y) {
   _x = x;
   _y = y;
   Init();
   _grall["Fall"].resize(FALL_ANIMEMAX);
   ResourceServer::LoadDivGraph(FALL_GRAPHNAME, FALL_ANIMEMAX, FALL_WIDTHCOUNT, FALL_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Fall"].data());
   _grall["Land"].resize(LAND_ANIMEMAX);
   ResourceServer::LoadDivGraph(LAND_GRAPHNAME, LAND_ANIMEMAX, LAND_WIDTHCOUNT, LAND_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Land"].data());
   _se["Poisonland"] = ResourceServer::LoadSoundMem("se/Gimik/Poisonfall.wav");
   _vpal["Poisonland"] = 180;
}

PoisonFall::~PoisonFall() {
}

void PoisonFall::Init() {
   _sort = 14;
   _gx = GRAPHPOINT_X;
   _gy = GRAPHPOINT_Y;
   _hit_x = POSITION_HITX;
   _hit_y = POSITION_HITY;
   _hit_w = COLLISION_WIDTH;
   _hit_h = COLLISION_HEIGHT;
   _alpha = 255;
   _spd = 15;
   _action_cnt = _cnt;
   _State = POISONSTATE::FALL;
}

void PoisonFall::Process(Game& g) {
   ObjectBase::Process(g);
   ChangeVolumeSoundMem(_vpal["Poisonland"], _se["Poisonland"]);
   auto frame = _cnt - _action_cnt;
   switch (_State) {
   case   POISONSTATE::FALL:
      _grhandle = _grall["Fall"][_anime["Fall"]];
      _anime["Fall"] = 0;
      if (frame < FALL_STOPFRAME) {
         _y += _spd;
      }
      if (frame == FALL_STOPFRAME) {
         _action_cnt = _cnt;
         _State = POISONSTATE::LAND;
         PlaySoundMem(_se["Poisonland"], DX_PLAYTYPE_BACK, true);
      }
      break;
   case POISONSTATE::LAND:
      _grhandle = _grall["Land"][_anime["Land"]];
      if (frame < LAND_ANIMEFRAME) {
         _anime["Land"] = ((frame) / ANIMESPEED_LAND) % LAND_ANIMEMAX;
      }
      if (frame >= LAND_ANIMEFRAME && LAND_ALLFRAME > frame) {
         _hit_x = 10000;
         _alpha -= LAND_FADEOUTSPEED;
      }
      if (frame == LAND_ALLFRAME) {
         Delete(g);
      }
      break;
   }
}

void PoisonFall::Draw(Game& g) {
   SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
   ObjectBase::Draw(g);
}

void PoisonFall::Delete(Game& g) {
   g.GetOS()->Del(this);
}