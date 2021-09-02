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
}
