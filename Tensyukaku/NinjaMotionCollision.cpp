#include <DxLib.h>
#include "NinjaMotionCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Ninja.h"


using namespace NInfo;
NinjaPatrolCollision::NinjaPatrolCollision() {
	Init();
}
NinjaPatrolCollision::~NinjaPatrolCollision() {
}

void NinjaPatrolCollision::Init() {
	_w = PatrolWidth;
	_h = PatrolHeight;
	_gx = 0;
	_gy = 0;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = PatrolWidth;
	_hit_h = PatrolHeight;
}

void NinjaPatrolCollision::Process(Game& g) {
	ObjectBase::Process(g);
}

NinjaComingCollision::NinjaComingCollision() {
	Init();
}
NinjaComingCollision::~NinjaComingCollision() {
}

void NinjaComingCollision::Init() {
	_w = ComingWidth;
	_h = ComingHeight;
	_gx = 0;
	_gy = 0;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = ComingWidth;
	_hit_h = ComingHeight;
}

void NinjaComingCollision::Process(Game& g) {
	ObjectBase::Process(g);
}

NinjaAttackCollision::NinjaAttackCollision() {
	Init();
}
NinjaAttackCollision::~NinjaAttackCollision() {
}

void NinjaAttackCollision::Init() {
	_w = AttackWidth;
	_h = AttackHeight;
	_gx = 0;
	_gy = 0;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = AttackWidth;
	_hit_h = AttackHeight;
	_Action_Cnt = _Cnt;
}

void NinjaAttackCollision::Process(Game& g) {
	ObjectBase::Process(g);
	if (_Cnt - _Action_Cnt == AEnd_Frame) {
		g.GetOS()->Del(this);
	}
}
void NinjaAttackCollision::Draw(Game& g) {
	ObjectBase::Draw(g);
}
void NinjaAttackCollision::Delete(Game& g) {
	g.GetOS()->Del(this);
}