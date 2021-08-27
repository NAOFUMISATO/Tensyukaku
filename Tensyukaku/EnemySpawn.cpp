#include "EnemySpawn.h"
#include "EnemySpawnCollision.h"
#include "Game.h"
EnemySpawn::EnemySpawn(Game& g){

}
EnemySpawn::~EnemySpawn() {
}

void EnemySpawn::Process(Game& g) {
		//各スポーンブロック生成
		Spawn1* sp1 = new Spawn1();
		g.GetOS()->Add(sp1);
}
