#include <DxLib.h>
#include "BushiMotionCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Bushi.h"

/*
���m�̊e���[�V�������̓����蔻�����
*/
using namespace BInfo;
//���G�͈͓����蔻�����
BushiPatrolCollision::BushiPatrolCollision(int x,int y) {
	_x = x;
	_y = y;
	Init();
}
BushiPatrolCollision::~BushiPatrolCollision() {
}

void BushiPatrolCollision::Init() {
	_gx = 0;
	_gy = 0;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = PATROL_WIDTH;
	_hit_h = PATROL_HEIGHT;
#ifdef _DEBUG
	_Color = std::make_tuple(0, 255, 0);
	_Dalpha = 128;
	_Fill = true;
#endif
}

//�U�������͈͓����蔻�����
BushiComingCollision::BushiComingCollision(int x, int y) {
	_x = x;
	_y = y;
	Init();
}
BushiComingCollision::~BushiComingCollision() {
}

void BushiComingCollision::Init() {
	_gx = 0;
	_gy = 0;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = COMING_WIDTH;
	_hit_h = COMING_HEIGHT;
#ifdef _DEBUG
	_Color = std::make_tuple(255,255, 0);
	_Dalpha = 128;
	_Fill = true;
#endif
}

//�U�������蔻�����
BushiAttackCollision::BushiAttackCollision(int x, int y) {
	_x = x;
	_y = y;
	Init();
}
BushiAttackCollision::~BushiAttackCollision() {
}

void BushiAttackCollision::Init() {
	_gx = 0;
	_gy = 0;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = ATTACK_WIDTH;
	_hit_h = ATTACK_HEIGHT;
	_Action_Cnt = _Cnt;
#ifdef _DEBUG
	_Color = std::make_tuple(255, 0, 0);
	_Dalpha = 128;
	_Fill = true;
#endif
}

void BushiAttackCollision::Process(Game& g) {
	ObjectBase::Process(g);
	if (_Cnt - _Action_Cnt == ATTACK_ENDFRAME) {
		g.GetOS()->Del(this);
	}
}
void BushiAttackCollision::Draw(Game& g) {
	ObjectBase::Draw(g);
}
void BushiAttackCollision::Delete(Game& g) {
	g.GetOS()->Del(this);
}


