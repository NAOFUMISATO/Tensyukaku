#include "SpawnBlock.h"
#include "Game.h"
#include "Bushi.h"
#include "Ninja.h"
#include "Shielder.h"

using namespace SpaInfo;
/*
	スポーンブロック
*/
//スポーンブロック1
Spawn1::Spawn1() {
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
				auto bu1 = new Bushi(SPAWN1_BUSHI1_X, SPAWN1_BUSHI1_Y,SPAWN1_BUSHI1_FLIP);
				g.GetOS()->Add(bu1);
				auto bu2 = new Bushi(SPAWN1_BUSHI2_X, SPAWN1_BUSHI2_Y, SPAWN1_BUSHI2_FLIP);
				g.GetOS()->Add(bu2);
				/*auto bu3 = new Bushi(SPAWN1_BUSHI3_X, SPAWN1_BUSHI3_Y, SPAWN1_BUSHI3_FLIP);
				g.GetOS()->Add(bu3);
				auto bu4 = new Bushi(SPAWN1_BUSHI4_X, SPAWN1_BUSHI4_Y, SPAWN1_BUSHI4_FLIP);
				g.GetOS()->Add(bu4);
				auto bu5 = new Bushi(SPAWN1_BUSHI5_X, SPAWN1_BUSHI5_Y, SPAWN1_BUSHI5_FLIP);
				g.GetOS()->Add(bu5);
				auto bu6 = new Bushi(SPAWN1_BUSHI6_X, SPAWN1_BUSHI6_Y, SPAWN1_BUSHI6_FLIP);
				g.GetOS()->Add(bu6);
				auto bu7 = new Bushi(SPAWN1_BUSHI7_X, SPAWN1_BUSHI7_Y, SPAWN1_BUSHI7_FLIP);
				g.GetOS()->Add(bu7);
				auto bu8 = new Bushi(SPAWN1_BUSHI8_X, SPAWN1_BUSHI8_Y, SPAWN1_BUSHI8_FLIP);
				g.GetOS()->Add(bu8);
				auto ni1 = new Ninja(SPAWN1_NINJA1_X, SPAWN1_NINJA1_Y, SPAWN1_NINJA1_FLIP);
				g.GetOS()->Add(ni1);
				auto ni2 = new Ninja(SPAWN1_NINJA2_X, SPAWN1_NINJA2_Y, SPAWN1_NINJA2_FLIP);
				g.GetOS()->Add(ni2);
				auto ni3 = new Ninja(SPAWN1_NINJA3_X, SPAWN1_NINJA3_Y, SPAWN1_NINJA3_FLIP);
				g.GetOS()->Add(ni3);*/
				auto sh1 = new Shielder(SPAWN1_SHIELDER1_X, SPAWN1_SHIELDER1_Y, SPAWN1_SHIELDER1_FLIP);
				g.GetOS()->Add(sh1);
			}
		}
	}
}
void Spawn1::Draw(Game& g) {
	SpawnBlockBase::Draw(g);
}
//スポーンブロック2
Spawn2::Spawn2() {
	_x = SPAWN2_XPOSITION;
	_y = SPAWN2_YPOSITION;
}
Spawn2::~Spawn2() {
}
void Spawn2::Process(Game& g) {
	//プレイヤーとの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			if (IsHit(*(*ite)) == true) {
				Delete(g);
				auto bu1 = new Bushi(SPAWN2_BUSHI1_X, SPAWN2_BUSHI1_Y, SPAWN2_BUSHI1_FLIP);
				g.GetOS()->Add(bu1);
				auto ni1 = new Ninja(SPAWN2_NINJA1_X, SPAWN2_NINJA1_Y, SPAWN2_NINJA1_FLIP);
				g.GetOS()->Add(ni1);
				auto ni2 = new Ninja(SPAWN2_NINJA2_X, SPAWN2_NINJA2_Y, SPAWN2_NINJA2_FLIP);
				g.GetOS()->Add(ni2);
			}
		}
	}
}
void Spawn2::Draw(Game& g) {
	SpawnBlockBase::Draw(g);
}
//スポーンブロック3
Spawn3::Spawn3() {
	_x = SPAWN3_XPOSITION;
	_y = SPAWN3_YPOSITION;
}
Spawn3::~Spawn3() {
}
void Spawn3::Process(Game& g) {
	//プレイヤーとの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			if (IsHit(*(*ite)) == true) {
				Delete(g);
				auto sh1 = new Shielder(SPAWN3_SHIELDER1_X, SPAWN3_SHIELDER1_Y, SPAWN3_SHIELDER1_FLIP);
				g.GetOS()->Add(sh1);
			}
		}
	}
}
void Spawn3::Draw(Game& g) {
	SpawnBlockBase::Draw(g);
}