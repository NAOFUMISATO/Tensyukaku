/*****************************************************************//**
 * \file   BossBlood.cpp
 * \brief  ボスの血しぶきクラス（エフェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Game.h"
#include "ResourceServer.h"
#include "BossBlood.h"

BossBlood::BossBlood(int x, int y, int bloodtype) {
   _x = x;
   _y = y;
   _blood_type = bloodtype;
   _grall["BossBlood1"].resize(1);
   ResourceServer::LoadDivGraph("res/Efect/BossBlood1.png", 1, 1, 1, 420, 420, _grall["BossBlood1"].data());
   _grall["BossBlood2"].resize(1);
   ResourceServer::LoadDivGraph("res/Efect/BossBlood2.png", 1, 1, 1, 420, 420, _grall["BossBlood2"].data());
   Init();
}
BossBlood::~BossBlood() {
};

void BossBlood::Init() {
   _alpha = 255;
   _action_cnt = _cnt;
}

void BossBlood::Process(Game& g) {
   EfectBase::Process(g);
   auto frame = _cnt - _action_cnt;
   switch (_blood_type) {
   case 0:
      _grhandle = _grall["BossBlood1"][0];
      break;
   case 1:
      _grhandle = _grall["BossBlood2"][0];
      break;
   }
   if (frame >= 30 && _alpha > 0) {
      _alpha -= 10;
   }
   if (_alpha == 0) {
      Delete(g);
   }
}

void BossBlood::Draw(Game& g) {
   EfectBase::Draw(g);
}

void BossBlood::Delete(Game& g) {
   g.GetOS()->Del(this);
}