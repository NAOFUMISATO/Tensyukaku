#include "EnemySpawn.h"
#include "SpawnBlock.h"
#include "Game.h"
EnemySpawn::EnemySpawn(Game& g){

}
EnemySpawn::~EnemySpawn() {
}

void EnemySpawn::Process(Game& g) {
		//�e�X�|�[���u���b�N����
		auto sp1 = new Spawn1();
		g.GetOS()->Add(sp1);
		auto sp2 = new Spawn2();
		g.GetOS()->Add(sp2);
		auto sp3 = new Spawn3();
		g.GetOS()->Add(sp3);
}
