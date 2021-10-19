/*****************************************************************//**
 * \file   IaiGauge.cpp
 * \brief  居合ゲージUIクラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ResourceServer.h"
#include "IaiGauge.h"
#include "Game.h"
#include "IaiGaugeParticle.h"

using namespace IGPInfo;
IaiGauge::IaiGauge(){
   Init();
   _grall["IaiGauge"].resize(6);
   ResourceServer::LoadDivGraph("res/UI/IaiGauge.png",6,3,2,800,80,_grall["IaiGauge"].data());
}
IaiGauge::~IaiGauge() {
}

void IaiGauge::Init() {
   _sort = 14;
   _x = 960;
   _y = 1040;
}

void IaiGauge::Process(Game& g) {
   ObjectBase::Process(g);

   _grhandle = _grall["IaiGauge"][_anime["IaiGauge"]];
   for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
   {
      // iteはプレイヤーか？
      if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER) {
         auto ig = (*ite)->GetGauge();
         _anime["IaiGauge"] = ig;
         if(ig==5){
            for (int i = 0; i < IAIG_PARTICLE_QTY; i++)
            {
               std::pair<int, int> xy = std::make_pair(_x, _y);
               std::pair<double, double> dxy = std::make_pair(((rand() % IAIG_PARTICLE_RANDOMX1) - IAIG_PARTICLE_RANDOMX2) / IAIG_PARTICLE_RANDOMX3, ((rand() % IAIG_PARTICLE_RANDOMY1) - IAIG_PARTICLE_RANDOMY2) / IAIG_PARTICLE_RANDOMY3);
               auto igp = new IaiGaugeParticle(xy, dxy, false);
               g.GetOS()->Add(igp);
            }
         }
      }
   }
}
void IaiGauge::Draw(Game& g) {
   DrawRotaGraph(_x, _y, 1.0, 0.0, _grhandle, true, false);
}