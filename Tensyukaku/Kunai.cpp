/*****************************************************************//**
 * \file   Kunai.cpp
 * \brief  クナイクラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ResourceServer.h"
#include "Ninja.h"
#include "Kunai.h"
#include "Game.h"
#include "ObjectBase.h"

using namespace NInfo;

Kunai::Kunai(int x,int y, bool flip,int spd):_repel_flag(false) {
   _x = x;
   _y = y;
   _isflip = flip;
   _spd = spd;
   Init();
   _grall["Kunai"].resize(2);
   ResourceServer::LoadDivGraph(KUNAI_GRAPHNAME, 2, 2, 1, 120, 120, _grall["Kunai"].data());
}

Kunai::~Kunai() {
};

void Kunai::Init() {
   _sort = 14;
   _gx = KUNAI_GRAPHPOINT_X;
   _gy = KUNAI_GRAPHPOINT_Y;
   _hit_x = KUNAI_POSITION_HITX;
   _hit_y = KUNAI_POSITION_HITY;
   _hit_w = KUNAI_COLLISION_WIDTH;
   _hit_h = KUNAI_COLLISION_HEIGHT;
   _alpha =255;
   _drg.second = 0.0;
}

void Kunai::Process(Game& g) {
   ObjectBase::Process(g);
   _grhandle=_grall["Kunai"][_anime["Kunai"]];
   _anime["Kunai"] = 1;
   auto frame = _cnt - _action_cnt;
   if (_repel_flag == true) {
      _hit_x = 10000;
      _anime["Kunai"] = 0;
      if (frame < REPEL_FRAME) {
         _alpha -= KUNAI_ALPHACHANGE;
         if (_isflip == false) {

            _drg.second += KUNAI_ANGLECHANGE;
            _x += KUNAI_XCHANGE;
            _y += KUNAI_YCHANGE;
         }
         if (_isflip == true) {

            _drg.second -= KUNAI_ANGLECHANGE;
            _x -= KUNAI_XCHANGE;
            _y += KUNAI_YCHANGE;
         }
      }
      if (frame == REPEL_FRAME) {
         Delete(g);
         _repel_flag = false;
      }
   }
   
   if (_repel_flag == false) {
      //クナイとプレイヤーの下段攻撃オブジェクトの当たり判定
      for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
      {
         // iteはプレイヤーの下段攻撃オブジェクトか？
         if ((*ite)->GetObjType() == OBJECTTYPE::LOWATTACK|| (*ite)->GetObjType() == OBJECTTYPE:: IAI)
         {
            // クナイとプレイヤーの下段攻撃オブジェクトの当たり判定を行う
            if (IsHit(*(*ite)) == true) {
               _repel_flag = true;
               _spd = 0;
               _action_cnt = _cnt;
            }
         }
      }
   }
   if (_isflip == false) {
      _x -= _spd;
   }
   if (_isflip == true) {
      _x += _spd;
   }
}

void Kunai::Draw(Game& g) {
   SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
   ObjectBase::Draw(g);
}

void Kunai::Delete(Game& g) {
   g.GetOS()->Del(this);
}