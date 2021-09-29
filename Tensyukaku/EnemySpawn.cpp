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
		auto sp1a = new Spawn("1A");
		g.GetOS()->Add(sp1a);
		auto sp1b = new Spawn("1B");
		g.GetOS()->Add(sp1b);
		auto sp2a = new Spawn("2A");
		g.GetOS()->Add(sp2a);
		auto sp2b = new Spawn("2B");
		g.GetOS()->Add(sp2b);
		auto sp3a = new Spawn("3A");
		g.GetOS()->Add(sp3a);
		auto sp3b = new Spawn("3B");
		g.GetOS()->Add(sp3b);
		auto sp3c = new Spawn("3C");
		g.GetOS()->Add(sp3c);
		auto sp3d = new Spawn("3D");
		g.GetOS()->Add(sp3d);
		auto sp3e = new Spawn("3E");
		g.GetOS()->Add(sp3e);
		auto sp4a = new Spawn("4A");
		g.GetOS()->Add(sp4a);
		auto sp4b = new Spawn("4B");
		g.GetOS()->Add(sp4b);
		auto sp4c = new Spawn("4C");
		g.GetOS()->Add(sp4c);
		auto sp4d = new Spawn("4D");
		g.GetOS()->Add(sp4d);
		auto sp5a = new Spawn("5A");
		g.GetOS()->Add(sp5a);
		auto sp5b = new Spawn("5B");
		g.GetOS()->Add(sp5b);
		auto sp5c = new Spawn("5C");
		g.GetOS()->Add(sp5c);
		auto sp6a = new Spawn("6A");
		g.GetOS()->Add(sp6a);
		auto sp8a = new Spawn("8A");
		g.GetOS()->Add(sp8a);
		auto sp9a = new Spawn("9A");
		g.GetOS()->Add(sp9a);
		auto sp9b = new Spawn("9B");
		g.GetOS()->Add(sp9b);
		auto sp10a = new Spawn("10A");
		g.GetOS()->Add(sp10a);
		auto sp10b = new Spawn("10B");
		g.GetOS()->Add(sp10b);
		auto sp11a = new Spawn("11A");
		g.GetOS()->Add(sp11a);
		auto sp11b = new Spawn("11B");
		g.GetOS()->Add(sp11b);
		auto sp11c = new Spawn("11C");
		g.GetOS()->Add(sp11c);
		auto sp11d = new Spawn("11D");
		g.GetOS()->Add(sp11d);
		auto sp11e = new Spawn("11E");
		g.GetOS()->Add(sp11e);
		auto sp11f = new Spawn("11F");
		g.GetOS()->Add(sp11f);
		auto sp12a = new Spawn("12A");
		g.GetOS()->Add(sp12a);
		auto sp12b= new Spawn("12B");
		g.GetOS()->Add(sp12b);
		auto sp12c = new Spawn("12C");
		g.GetOS()->Add(sp12c);
}
