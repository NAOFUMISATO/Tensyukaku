/*****************************************************************//**
 * \file   EnemySpawn.cpp
 * \brief  スポーンブロックのインスタンス生成クラス
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include "EnemySpawn.h"
#include "SpawnBlock.h"
#include "Game.h"

using namespace SpaInfo;
EnemySpawn::EnemySpawn(Game& g){
   Init(g);
}
EnemySpawn::~EnemySpawn() {
}

void EnemySpawn::Init(Game& g) {
      //各スポーンブロック生成
      auto sp1a = new SpawnBlock("1A");
      g.GetOS()->Add(sp1a);
      auto sp1b = new SpawnBlock("1B");
      g.GetOS()->Add(sp1b);
      auto sp2a = new SpawnBlock("2A");
      g.GetOS()->Add(sp2a);
      auto sp2b = new SpawnBlock("2B");
      g.GetOS()->Add(sp2b);
      auto sp3a = new SpawnBlock("3A");
      g.GetOS()->Add(sp3a);
      auto sp3b = new SpawnBlock("3B");
      g.GetOS()->Add(sp3b);
      auto sp3c = new SpawnBlock("3C");
      g.GetOS()->Add(sp3c);
      auto sp3d = new SpawnBlock("3D");
      g.GetOS()->Add(sp3d);
      auto sp3e = new SpawnBlock("3E");
      g.GetOS()->Add(sp3e);
      auto sp4a = new SpawnBlock("4A");
      g.GetOS()->Add(sp4a);
      auto sp4b = new SpawnBlock("4B");
      g.GetOS()->Add(sp4b);
      auto sp4c = new SpawnBlock("4C");
      g.GetOS()->Add(sp4c);
      auto sp4d = new SpawnBlock("4D");
      g.GetOS()->Add(sp4d);
      auto sp5a = new SpawnBlock("5A");
      g.GetOS()->Add(sp5a);
      auto sp5b = new SpawnBlock("5B");
      g.GetOS()->Add(sp5b);
      auto sp5c = new SpawnBlock("5C");
      g.GetOS()->Add(sp5c);
      auto sp6a = new SpawnBlock("6A");
      g.GetOS()->Add(sp6a);
      auto sp8a = new SpawnBlock("8A");
      g.GetOS()->Add(sp8a);
      auto sp9a = new SpawnBlock("9A");
      g.GetOS()->Add(sp9a);
      auto sp9b = new SpawnBlock("9B");
      g.GetOS()->Add(sp9b);
      auto sp10a = new SpawnBlock("10A");
      g.GetOS()->Add(sp10a);
      auto sp10b = new SpawnBlock("10B");
      g.GetOS()->Add(sp10b);
      auto sp11a = new SpawnBlock("11A");
      g.GetOS()->Add(sp11a);
      auto sp11b = new SpawnBlock("11B");
      g.GetOS()->Add(sp11b);
      auto sp11c = new SpawnBlock("11C");
      g.GetOS()->Add(sp11c);
      auto sp11d = new SpawnBlock("11D");
      g.GetOS()->Add(sp11d);
      auto sp11e = new SpawnBlock("11E");
      g.GetOS()->Add(sp11e);
      auto sp11f = new SpawnBlock("11F");
      g.GetOS()->Add(sp11f);
      auto sp12a = new SpawnBlock("12A");
      g.GetOS()->Add(sp12a);
      auto sp12b= new SpawnBlock("12B");
      g.GetOS()->Add(sp12b);
      auto sp12c = new SpawnBlock("12C");
      g.GetOS()->Add(sp12c);
}
