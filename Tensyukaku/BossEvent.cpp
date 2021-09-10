#include "BossEvent.h"
#include "Game.h"
using namespace BEInfo;
BossEventA::BossEventA() {
	Init();
}
BossEventA::~BossEventA() {
}

void BossEventA::Init() {
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
}
void BossEventA::Process(Game& g) {
	ObjectBase::Process(g);
	//ボスイベントAとプレイヤーの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			// //ボスイベントAとプレイヤーの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				Delete(g);
				(*ite)->SetEventA();
				for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
				{
					// iteはプレイヤーか？
					if ((*ite)->GetObjType() == OBJECTTYPE::BOSS)
					{
						(*ite)->SetEventA();
					}
				}
			}
		}
	}
}
void BossEventA::Draw(Game& g) {
	ObjectBase::Draw(g);
}
void BossEventA::Delete(Game& g) {
	g.GetOS()->Del(this);
}
BossEventB::BossEventB() {
	Init();
}
BossEventB::~BossEventB() {
}

void BossEventB::Init() {
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
}
void BossEventB::Process(Game& g) {
	ObjectBase::Process(g);
	//ボスイベントAとプレイヤーの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			// //ボスイベントAとプレイヤーの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				Delete(g);
				(*ite)->SetEventB();
				for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
				{
					// iteはプレイヤーか？
					if ((*ite)->GetObjType() == OBJECTTYPE::BOSS)
					{
						(*ite)->SetEventB();
					}
				}
			}
		}
	}
}
void BossEventB::Draw(Game& g) {
	ObjectBase::Draw(g);
}
void BossEventB::Delete(Game& g) {
	g.GetOS()->Del(this);
}
BossEventC::BossEventC() {
	Init();
}
BossEventC::~BossEventC() {
}

void BossEventC::Init() {
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
}
void BossEventC::Process(Game& g) {
	ObjectBase::Process(g);
	//ボスイベントAとプレイヤーの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			// //ボスイベントAとプレイヤーの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				Delete(g);
				(*ite)->SetEventC();
				for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
				{
					// iteはプレイヤーか？
					if ((*ite)->GetObjType() == OBJECTTYPE::BOSS)
					{
						(*ite)->SetEventC();
					}
				}
			}
		}
	}
}
void BossEventC::Draw(Game& g) {
	ObjectBase::Draw(g);
}
void BossEventC::Delete(Game& g) {
	g.GetOS()->Del(this);
}