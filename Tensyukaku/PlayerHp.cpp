/*****************************************************************//**
 * \file   PlayerHp.cpp
 * \brief  プレイヤーの体力UIクラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ResourceServer.h"
#include "PlayerHp.h"
#include "Game.h"

PlayerHp::PlayerHp(int hp){
   _life = hp;
   Init();
   _grall["HP"].resize(31);
   ResourceServer::LoadDivGraph("res/UI/HP.png",31,10,4,100,105, _grall["HP"].data());
}
PlayerHp::~PlayerHp() {
}

void PlayerHp::Init() {
   _sort = 14;
   _x = 220+(105*_life);
   _y = 1025;
}
void PlayerHp::Process(Game& g) {
   ObjectBase::Process(g);
   _grhandle = _grall["HP"][_anime["HP"]];
   for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
   {
      // iteはプレイヤーか？
      if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER) {
         auto hp=(*ite)->GetLife();
         if (hp <= _life) {
            _anime["HP"] = 30;
         }
         else { _anime["HP"] = (_cnt / 3) % 29; }
      }
   }
}
void PlayerHp::Draw(Game& g) {
   DrawRotaGraph(_x, _y, 1.0, 0.0, _grhandle,true,false);
}
void PlayerHp::Delete(Game& g) {
   g.GetOS()->Del(this);
}