#include "SpawnBlock.h"
#include "Game.h"
#include "Bushi.h"
#include "Ninja.h"
#include "Shielder.h"
#include "PoisonNinja.h"

using namespace SpaInfo;
/*
	スポーンブロック
*/
//スポーンブロック1A
Spawn1A::Spawn1A() {
	_x = SPAWN1A_XPOSITION;
	_y = SPAWN1A_YPOSITION;
}
Spawn1A::~Spawn1A() {
}
void Spawn1A::Process(Game& g) {
	//プレイヤーとの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			if (IsHit(*(*ite)) == true) {
				Delete(g);
				auto bu1 = new Bushi(SPAWN1A_BUSHI1_X, SPAWN1A_BUSHI1_Y,SPAWN1A_BUSHI1_FLIP);
				g.GetOS()->Add(bu1);
				auto bu2 = new Bushi(SPAWN1A_BUSHI2_X, SPAWN1A_BUSHI2_Y, SPAWN1A_BUSHI2_FLIP);
				g.GetOS()->Add(bu2);
				auto bu3 = new Bushi(SPAWN1A_BUSHI3_X, SPAWN1A_BUSHI3_Y, SPAWN1A_BUSHI3_FLIP);
				g.GetOS()->Add(bu3);
				auto bu4 = new Bushi(SPAWN1A_BUSHI4_X, SPAWN1A_BUSHI4_Y, SPAWN1A_BUSHI4_FLIP);
				g.GetOS()->Add(bu4);
				auto bu5 = new Bushi(SPAWN1A_BUSHI5_X, SPAWN1A_BUSHI5_Y, SPAWN1A_BUSHI5_FLIP);
				g.GetOS()->Add(bu5);
				auto bu6 = new Bushi(SPAWN1A_BUSHI6_X, SPAWN1A_BUSHI6_Y, SPAWN1A_BUSHI6_FLIP);
				g.GetOS()->Add(bu6);
				auto bu7 = new Bushi(SPAWN1A_BUSHI7_X, SPAWN1A_BUSHI7_Y, SPAWN1A_BUSHI7_FLIP);
				g.GetOS()->Add(bu7);
				auto bu8 = new Bushi(SPAWN1A_BUSHI8_X, SPAWN1A_BUSHI8_Y, SPAWN1A_BUSHI8_FLIP);
				g.GetOS()->Add(bu8);
				auto bu9 = new Bushi(SPAWN1A_BUSHI9_X, SPAWN1A_BUSHI9_Y, SPAWN1A_BUSHI9_FLIP);
				g.GetOS()->Add(bu9);
				auto bu10 = new Bushi(SPAWN1A_BUSHI10_X, SPAWN1A_BUSHI10_Y, SPAWN1A_BUSHI10_FLIP);
				g.GetOS()->Add(bu10);
				auto bu11 = new Bushi(SPAWN1A_BUSHI11_X, SPAWN1A_BUSHI11_Y, SPAWN1A_BUSHI11_FLIP);
				g.GetOS()->Add(bu11);
				auto bu12 = new Bushi(SPAWN1A_BUSHI12_X, SPAWN1A_BUSHI12_Y, SPAWN1A_BUSHI12_FLIP);
				g.GetOS()->Add(bu12);
				auto bu13 = new Bushi(SPAWN1A_BUSHI13_X, SPAWN1A_BUSHI13_Y, SPAWN1A_BUSHI13_FLIP);
				g.GetOS()->Add(bu13);
				auto bu14 = new Bushi(SPAWN1A_BUSHI14_X, SPAWN1A_BUSHI14_Y, SPAWN1A_BUSHI14_FLIP);
				g.GetOS()->Add(bu14);
				auto bu15 = new Bushi(SPAWN1A_BUSHI15_X, SPAWN1A_BUSHI15_Y, SPAWN1A_BUSHI15_FLIP);
				g.GetOS()->Add(bu15);
				auto bu16 = new Bushi(SPAWN1A_BUSHI16_X, SPAWN1A_BUSHI16_Y, SPAWN1A_BUSHI16_FLIP);
				g.GetOS()->Add(bu16);
				auto ni1 = new Ninja(SPAWN1A_NINJA1_X, SPAWN1A_NINJA1_Y, SPAWN1A_NINJA1_FLIP, SPAWN1A_NINJA1_KUNAI);
				g.GetOS()->Add(ni1);
				auto ni2 = new Ninja(SPAWN1A_NINJA2_X, SPAWN1A_NINJA2_Y, SPAWN1A_NINJA2_FLIP, SPAWN1A_NINJA2_KUNAI);
				g.GetOS()->Add(ni2);
				auto ni3 = new Ninja(SPAWN1A_NINJA3_X, SPAWN1A_NINJA3_Y, SPAWN1A_NINJA3_FLIP, SPAWN1A_NINJA3_KUNAI);
				g.GetOS()->Add(ni3);
				auto ni4 = new Ninja(SPAWN1A_NINJA4_X, SPAWN1A_NINJA4_Y, SPAWN1A_NINJA4_FLIP, SPAWN1A_NINJA4_KUNAI);
				g.GetOS()->Add(ni4);
				auto ni5 = new Ninja(SPAWN1A_NINJA5_X, SPAWN1A_NINJA5_Y, SPAWN1A_NINJA5_FLIP, SPAWN1A_NINJA5_KUNAI);
				g.GetOS()->Add(ni5);
				auto sh1 = new Shielder(SPAWN1A_SHIEL1_X, SPAWN1A_SHIEL1_Y, SPAWN1A_SHIEL1_FLIP);
				g.GetOS()->Add(sh1);
				auto sh2 = new Shielder(SPAWN1A_SHIEL2_X, SPAWN1A_SHIEL2_Y, SPAWN1A_SHIEL2_FLIP);
				g.GetOS()->Add(sh2);
				auto sh3 = new Shielder(SPAWN1A_SHIEL3_X, SPAWN1A_SHIEL3_Y, SPAWN1A_SHIEL3_FLIP);
				g.GetOS()->Add(sh3);
				auto sh4 = new Shielder(SPAWN1A_SHIEL4_X, SPAWN1A_SHIEL4_Y, SPAWN1A_SHIEL4_FLIP);
				g.GetOS()->Add(sh4);
				auto sh5 = new Shielder(SPAWN1A_SHIEL5_X, SPAWN1A_SHIEL5_Y, SPAWN1A_SHIEL5_FLIP);
				g.GetOS()->Add(sh5);
				auto sh6 = new Shielder(SPAWN1A_SHIEL6_X, SPAWN1A_SHIEL6_Y, SPAWN1A_SHIEL6_FLIP);
				g.GetOS()->Add(sh6);
				auto pn1 = new PoisonNinja(SPAWN1A_POIJA1_X, SPAWN1A_POIJA1_Y, SPAWN1A_POIJA1_FLIP);
				g.GetOS()->Add(pn1);
				auto pn2 = new PoisonNinja(SPAWN1A_POIJA2_X, SPAWN1A_POIJA2_Y, SPAWN1A_POIJA2_FLIP);
				g.GetOS()->Add(pn2);
				auto pn3 = new PoisonNinja(SPAWN1A_POIJA3_X, SPAWN1A_POIJA3_Y, SPAWN1A_POIJA3_FLIP);
				g.GetOS()->Add(pn3);
				auto pn4 = new PoisonNinja(SPAWN1A_POIJA4_X, SPAWN1A_POIJA4_Y, SPAWN1A_POIJA4_FLIP);
				g.GetOS()->Add(pn4);
				auto pn5 = new PoisonNinja(SPAWN1A_POIJA5_X, SPAWN1A_POIJA5_Y, SPAWN1A_POIJA5_FLIP);
				g.GetOS()->Add(pn5);
				auto pn6 = new PoisonNinja(SPAWN1A_POIJA6_X, SPAWN1A_POIJA6_Y, SPAWN1A_POIJA6_FLIP);
				g.GetOS()->Add(pn6);
			}
		}
	}
}
void Spawn1A::Draw(Game& g) {
	SpawnBlockBase::Draw(g);
}
//スポーンブロック2A
Spawn2A::Spawn2A() {
	_x = SPAWN2A_XPOSITION;
	_y = SPAWN2A_YPOSITION;
}
Spawn2A::~Spawn2A() {
}
void Spawn2A::Process(Game& g) {
	//プレイヤーとの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			if (IsHit(*(*ite)) == true) {
				Delete(g);
				auto bu1 = new Bushi(SPAWN2A_BUSHI1_X, SPAWN2A_BUSHI1_Y, SPAWN2A_BUSHI1_FLIP);
				g.GetOS()->Add(bu1);
				auto bu2 = new Bushi(SPAWN2A_BUSHI2_X, SPAWN2A_BUSHI2_Y, SPAWN2A_BUSHI2_FLIP);
				g.GetOS()->Add(bu2);
				auto ni1 = new Ninja(SPAWN2A_NINJA1_X, SPAWN2A_NINJA1_Y, SPAWN2A_NINJA1_FLIP, SPAWN2A_NINJA1_KUNAI);
				g.GetOS()->Add(ni1);
			}
		}
	}
}
void Spawn2A::Draw(Game& g) {
	SpawnBlockBase::Draw(g);
}
//スポーンブロック3A
Spawn3A::Spawn3A() {
	_x = SPAWN3A_XPOSITION;
	_y = SPAWN3A_YPOSITION;
}
Spawn3A::~Spawn3A() {
}
void Spawn3A::Process(Game& g) {
	//プレイヤーとの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			if (IsHit(*(*ite)) == true) {
				Delete(g);
				auto sh1 = new Shielder(SPAWN3A_SHIEL1_X, SPAWN3A_SHIEL1_Y, SPAWN3A_SHIEL1_FLIP);
				g.GetOS()->Add(sh1);
			}
		}
	}
}
void Spawn3A::Draw(Game& g) {
	SpawnBlockBase::Draw(g);
}

//スポーンブロック4A
Spawn4A::Spawn4A() {
	_x = SPAWN4A_XPOSITION;
	_y = SPAWN4A_YPOSITION;
}
Spawn4A::~Spawn4A() {
}

void Spawn4A::Process(Game& g) {
	//プレイヤーとの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			if (IsHit(*(*ite)) == true) {
				Delete(g);
				auto bu1 = new Bushi(SPAWN4A_BUSHI1_X, SPAWN4A_BUSHI1_Y, SPAWN4A_BUSHI1_FLIP);
				g.GetOS()->Add(bu1);
				auto bu2 = new Bushi(SPAWN4A_BUSHI1_X, SPAWN4A_BUSHI2_Y, SPAWN4A_BUSHI2_FLIP);
				g.GetOS()->Add(bu2);
				auto ni1 = new Ninja(SPAWN4A_NINJA1_X, SPAWN4A_NINJA1_Y, SPAWN4A_NINJA1_FLIP, SPAWN4A_NINJA1_KUNAI);
				g.GetOS()->Add(ni1);
				auto sh1 = new Shielder(SPAWN4A_SHIEL1_X, SPAWN4A_SHIEL1_Y, SPAWN4A_SHIEL1_FLIP);
				g.GetOS()->Add(sh1);
				auto pn1 = new PoisonNinja(SPAWN4A_POIJA1_X, SPAWN4A_POIJA1_Y, SPAWN4A_POIJA1_FLIP);
				g.GetOS()->Add(pn1);
			}
		}
	}
}
void Spawn4A::Draw(Game& g) {
	SpawnBlockBase::Draw(g);
}

//スポーンブロック5A
Spawn5A::Spawn5A() {
	_x = SPAWN5A_XPOSITION;
	_y = SPAWN5A_YPOSITION;
}
Spawn5A::~Spawn5A() {
}

void Spawn5A::Process(Game& g) {
	//プレイヤーとの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			if (IsHit(*(*ite)) == true) {
				Delete(g);
				auto ni1 = new Ninja(SPAWN5A_NINJA1_X, SPAWN5A_NINJA1_Y, SPAWN5A_NINJA1_FLIP, SPAWN5A_NINJA1_KUNAI);
				g.GetOS()->Add(ni1);
			}
		}
	}
}
void Spawn5A::Draw(Game& g) {
	SpawnBlockBase::Draw(g);
}

//スポーンブロック5B
Spawn5B::Spawn5B() {
	_x = SPAWN5B_XPOSITION;
	_y = SPAWN5B_YPOSITION;
}
Spawn5B::~Spawn5B() {
}

void Spawn5B::Process(Game& g) {
	//プレイヤーとの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			if (IsHit(*(*ite)) == true) {
				Delete(g);
				auto bu1 = new Bushi(SPAWN5B_BUSHI1_X, SPAWN5B_BUSHI1_Y, SPAWN5B_BUSHI1_FLIP);
				g.GetOS()->Add(bu1);
				auto bu2 = new Bushi(SPAWN5B_BUSHI2_X, SPAWN5B_BUSHI2_Y, SPAWN5B_BUSHI2_FLIP);
				g.GetOS()->Add(bu2);
				auto ni1 = new Ninja(SPAWN5B_NINJA1_X, SPAWN5B_NINJA1_Y, SPAWN5B_NINJA1_Y, SPAWN5B_NINJA1_KUNAI);
				g.GetOS()->Add(ni1);
				auto sh1 = new Shielder(SPAWN5B_SHIEL1_X, SPAWN5B_SHIEL1_Y, SPAWN5B_SHIEL1_FLIP);
				g.GetOS()->Add(sh1);
				auto sh2 = new Shielder(SPAWN5B_SHIEL2_X, SPAWN5B_SHIEL2_Y, SPAWN5B_SHIEL2_FLIP);
				g.GetOS()->Add(sh2);
			}
		}
	}
}
void Spawn5B::Draw(Game& g) {
	SpawnBlockBase::Draw(g);
}

//スポーンブロック7A
Spawn7A::Spawn7A() {
	_x = SPAWN7A_XPOSITION;
	_y = SPAWN7A_YPOSITION;
}
Spawn7A::~Spawn7A() {
}

void Spawn7A::Process(Game& g) {
	//プレイヤーとの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			if (IsHit(*(*ite)) == true) {
				Delete(g);
				auto sh1 = new Shielder(SPAWN7A_SHIEL1_X, SPAWN7A_SHIEL1_Y, SPAWN7A_SHIEL1_FLIP);
				g.GetOS()->Add(sh1);
				auto sh2 = new Shielder(SPAWN7A_SHIEL2_X, SPAWN7A_SHIEL2_Y, SPAWN7A_SHIEL2_FLIP);
				g.GetOS()->Add(sh2);
				auto sh3 = new Shielder(SPAWN7A_SHIEL3_X, SPAWN7A_SHIEL3_Y, SPAWN7A_SHIEL3_FLIP);
				g.GetOS()->Add(sh3);
				auto sh4 = new Shielder(SPAWN7A_SHIEL4_X, SPAWN7A_SHIEL4_Y, SPAWN7A_SHIEL4_FLIP);
				g.GetOS()->Add(sh4);
				auto sh5 = new Shielder(SPAWN7A_SHIEL5_X, SPAWN7A_SHIEL5_Y, SPAWN7A_SHIEL5_FLIP);
				g.GetOS()->Add(sh5);
				auto sh6 = new Shielder(SPAWN7A_SHIEL6_X, SPAWN7A_SHIEL6_Y, SPAWN7A_SHIEL6_FLIP);
				g.GetOS()->Add(sh6);
			}
		}
	}
}
void Spawn7A::Draw(Game& g) {
	SpawnBlockBase::Draw(g);
}

//スポーンブロック9A
Spawn9A::Spawn9A() {
	_x = SPAWN9A_XPOSITION;
	_y = SPAWN9A_YPOSITION;
}
Spawn9A::~Spawn9A() {
}

void Spawn9A::Process(Game& g) {
	//プレイヤーとの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			if (IsHit(*(*ite)) == true) {
				Delete(g);
				auto bu1 = new Bushi(SPAWN9A_BUSHI1_X, SPAWN9A_BUSHI1_Y, SPAWN9A_BUSHI1_FLIP);
				g.GetOS()->Add(bu1);
				auto bu2 = new Bushi(SPAWN9A_BUSHI2_X, SPAWN9A_BUSHI2_Y, SPAWN9A_BUSHI2_FLIP);
				g.GetOS()->Add(bu2);
				auto bu3 = new Bushi(SPAWN9A_BUSHI3_X, SPAWN9A_BUSHI3_Y, SPAWN9A_BUSHI3_FLIP);
				g.GetOS()->Add(bu3);
				auto ni1 = new Ninja(SPAWN9A_NINJA1_X, SPAWN9A_NINJA1_Y, SPAWN9A_NINJA1_Y, SPAWN9A_NINJA1_KUNAI);
				g.GetOS()->Add(ni1);
				auto pn1 = new PoisonNinja(SPAWN9A_POIJA1_X, SPAWN9A_POIJA1_Y, SPAWN9A_POIJA1_FLIP);
				g.GetOS()->Add(pn1);
			}
		}
	}
}
void Spawn9A::Draw(Game& g) {
	SpawnBlockBase::Draw(g);
}

//スポーンブロック9B
Spawn9B::Spawn9B() {
	_x = SPAWN9B_XPOSITION;
	_y = SPAWN9B_YPOSITION;
}
Spawn9B::~Spawn9B() {
}

void Spawn9B::Process(Game& g) {
	//プレイヤーとの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			if (IsHit(*(*ite)) == true) {
				Delete(g);
				auto bu1 = new Bushi(SPAWN9B_BUSHI1_X, SPAWN9B_BUSHI1_Y, SPAWN9B_BUSHI1_FLIP);
				g.GetOS()->Add(bu1);
				auto ni1 = new Ninja(SPAWN9B_NINJA1_X, SPAWN9B_NINJA1_Y, SPAWN9B_NINJA1_FLIP,SPAWN9B_NINJA1_KUNAI);
				g.GetOS()->Add(ni1);
				auto ni2 = new Ninja(SPAWN9B_NINJA2_X, SPAWN9B_NINJA2_Y, SPAWN9B_NINJA2_FLIP, SPAWN9B_NINJA2_KUNAI);
				g.GetOS()->Add(ni2);
				auto ni3 = new Ninja(SPAWN9B_NINJA3_X, SPAWN9B_NINJA3_Y, SPAWN9B_NINJA3_FLIP, SPAWN9B_NINJA3_KUNAI);
				g.GetOS()->Add(ni3);
				auto pn1 = new PoisonNinja(SPAWN9B_POIJA1_X, SPAWN9B_POIJA1_Y, SPAWN9B_POIJA1_FLIP);
				g.GetOS()->Add(pn1);
			}
		}
	}
}
void Spawn9B::Draw(Game& g) {
	SpawnBlockBase::Draw(g);
}

//スポーンブロック10A
Spawn10A::Spawn10A() {
	_x = SPAWN10A_XPOSITION;
	_y = SPAWN10A_YPOSITION;
}
Spawn10A::~Spawn10A() {
}

void Spawn10A::Process(Game& g) {
	//プレイヤーとの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			if (IsHit(*(*ite)) == true) {
				Delete(g);
				auto bu1 = new Bushi(SPAWN10A_BUSHI1_X, SPAWN10A_BUSHI1_Y, SPAWN10A_BUSHI1_FLIP);
				g.GetOS()->Add(bu1);
				auto ni1 = new Ninja(SPAWN10A_NINJA1_X, SPAWN10A_NINJA1_Y, SPAWN10A_NINJA1_FLIP, SPAWN10A_NINJA1_KUNAI);
				g.GetOS()->Add(ni1);
				auto sh1 = new Shielder(SPAWN10A_SHIEL1_X, SPAWN10A_SHIEL1_Y, SPAWN10A_SHIEL1_FLIP);
				g.GetOS()->Add(sh1);
				auto sh2 = new Shielder(SPAWN10A_SHIEL2_X, SPAWN10A_SHIEL2_Y, SPAWN10A_SHIEL2_FLIP);
				g.GetOS()->Add(sh2);
			}
		}
	}
}
void Spawn10A::Draw(Game& g) {
	SpawnBlockBase::Draw(g);
}

//スポーンブロック10B
Spawn10B::Spawn10B() {
	_x = SPAWN10B_XPOSITION;
	_y = SPAWN10B_YPOSITION;
}
Spawn10B::~Spawn10B() {
}

void Spawn10B::Process(Game& g) {
	//プレイヤーとの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			if (IsHit(*(*ite)) == true) {
				Delete(g);
				auto ni1 = new Ninja(SPAWN10B_NINJA1_X, SPAWN10B_NINJA1_Y, SPAWN10B_NINJA1_FLIP, SPAWN10B_NINJA1_KUNAI);
				g.GetOS()->Add(ni1);
				auto ni2 = new Ninja(SPAWN10B_NINJA2_X, SPAWN10B_NINJA2_Y, SPAWN10B_NINJA2_FLIP, SPAWN10B_NINJA2_KUNAI);
				g.GetOS()->Add(ni2);
			}
		}
	}
}
void Spawn10B::Draw(Game& g) {
	SpawnBlockBase::Draw(g);
}