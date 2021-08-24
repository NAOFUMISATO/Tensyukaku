#include <DxLib.h>
#include "SielderMotionCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Shielder.h"


using namespace SInfo;
/*
�����̊e���[�V�������̓����蔻�����
*/

//���G�͈͓����蔻�����
ShielderPatrolCollision::ShielderPatrolCollision() {
	Init();
}
ShielderPatrolCollision::~ShielderPatrolCollision() {
}

void ShielderPatrolCollision::Init() {
	_w = PatrolWidth;
	_h = PatrolHeight;
	_gx = 0;
	_gy = 0;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = PatrolWidth;
	_hit_h = PatrolHeight;
}

void ShielderPatrolCollision::Process(Game& g) {
	ObjectBase::Process(g);
}


//�U�������͈͓����蔻�����
ShielderComingCollision::ShielderComingCollision() {
	Init();
}
ShielderComingCollision::~ShielderComingCollision() {
}

void ShielderComingCollision::Init() {
	_w = ComingWidth;
	_h = ComingHeight;
	_gx = 0;
	_gy = 0;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = ComingWidth;
	_hit_h = ComingHeight;
}

void ShielderComingCollision::Process(Game& g) {
	ObjectBase::Process(g);
}


//�U�������蔻�����
ShielderAttackCollision::ShielderAttackCollision() {
	Init();
}
ShielderAttackCollision::~ShielderAttackCollision() {
}

void ShielderAttackCollision::Init() {
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

void ShielderAttackCollision::Process(Game& g) {
	ObjectBase::Process(g);
	if (_Cnt - _Action_Cnt == AEnd_Frame) {
		g.GetOS()->Del(this);
	}
}
void ShielderAttackCollision::Draw(Game& g) {
	ObjectBase::Draw(g);
}
void ShielderAttackCollision::Delete(Game& g) {
	g.GetOS()->Del(this);
}


