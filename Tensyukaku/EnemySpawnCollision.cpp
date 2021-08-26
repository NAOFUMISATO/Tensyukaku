#include "EnemySpawnCollision.h"
#include "Game.h"
#include "Bushi.h"
#include "Ninja.h"
#include "Shielder.h"

using namespace SpaInfo;
//スポーンブロック実体
Spawn1::Spawn1() {
	EnemySpawnCollisionBase::Init();
	_x = SPAWN1_XPOSITION;
	_y = SPAWN1_YPOSITION;
}
Spawn1::~Spawn1() {
}
void Spawn1::Process(Game& g) {
	//プレイヤーとの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			if (IsHit(*(*ite)) == true) {
				Delete(g);
				Bushi* bu1 = new Bushi();
				bu1->SetPosition(SPAWN1_BUSHI1_X, SPAWN1_BUSHI1_Y);
				bu1->SetFlip(SPAWN1_BUSHI1_FLIP);
				g.GetOS()->Add(bu1);
				/*Bushi* bu2 = new Bushi();
				bu2->SetPosition(SPAWN1_BUSHI1_X, SPAWN1_BUSHI1_Y);
				bu2->SetFlip(SPAWN1_BUSHI1_FLIP);
				g.GetOS()->Add(bu1);*/
			}
		}
	}
}
void Spawn1::Draw(Game& g) {
	EnemySpawnCollisionBase::Draw(g);
}