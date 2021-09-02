#include "EnemySpawn.h"
#include "SpawnBlock.h"
#include "Game.h"
EnemySpawn::EnemySpawn(Game& g){

}
EnemySpawn::~EnemySpawn() {
}

void EnemySpawn::Process(Game& g) {
		//各スポーンブロック生成
		auto sp1a = new Spawn1A();
		g.GetOS()->Add(sp1a);
		auto sp2a = new Spawn2A();
		g.GetOS()->Add(sp2a);
		auto sp3a = new Spawn3A();
		g.GetOS()->Add(sp3a);
		auto sp4a = new Spawn4A();
		g.GetOS()->Add(sp4a);
		auto sp5a = new Spawn5A();
		g.GetOS()->Add(sp5a);
		auto sp5b = new Spawn5B();
		g.GetOS()->Add(sp5b);
		auto sp7a = new Spawn7A();
		g.GetOS()->Add(sp7a);
		auto sp9a = new Spawn9A();
		g.GetOS()->Add(sp9a);
		auto sp9b = new Spawn9B();
		g.GetOS()->Add(sp9b);
		auto sp10a = new Spawn10A();
		g.GetOS()->Add(sp10a);
		auto sp10b = new Spawn10B();
		g.GetOS()->Add(sp10b);
}
