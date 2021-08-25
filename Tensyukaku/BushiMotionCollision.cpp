#include <DxLib.h>
#include "BushiMotionCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Bushi.h"

/*
•Žm‚ÌŠeƒ‚[ƒVƒ‡ƒ“Žž‚Ì“–‚½‚è”»’èŽÀ‘Ì
*/
using namespace BInfo;
//õ“G”ÍˆÍ“–‚½‚è”»’èŽÀ‘Ì
BushiPatrolCollision::BushiPatrolCollision() {
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
	_color = std::make_tuple(0, 255, 0);
	_Dalpha = 128;
	_fill = true;
#endif
}

//UŒ‚”­¶”ÍˆÍ“–‚½‚è”»’èŽÀ‘Ì
BushiComingCollision::BushiComingCollision() {
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
	_color = std::make_tuple(255,255, 0);
	_Dalpha = 128;
	_fill = true;
#endif
}

//UŒ‚“–‚½‚è”»’èŽÀ‘Ì
BushiAttackCollision::BushiAttackCollision() {
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
	_color = std::make_tuple(255, 0, 0);
	_Dalpha = 128;
	_fill = true;
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


