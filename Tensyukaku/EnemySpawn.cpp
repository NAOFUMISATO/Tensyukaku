#include "EnemySpawn.h"
#include "EnemySpawnCollision.h"
#include "Game.h"
EnemySpawn::EnemySpawn(Game& g) :_Appear_Flag(false) {

}
EnemySpawn::~EnemySpawn() {
}

void EnemySpawn::Process(Game& g) {
	if (_Appear_Flag == false) {
		_Appear_Flag = true;
		//�e�X�|�[���u���b�N����
		Spawn1* sp1 = new Spawn1();
		g.GetOS()->Add(sp1);
	}
}
