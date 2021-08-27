#include <DxLib.h>
#include "ShielderMotionCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Shielder.h"


using namespace SInfo;
/*
‚•º‚ÌŠeƒ‚[ƒVƒ‡ƒ“Žž‚Ì“–‚½‚è”»’èŽÀ‘Ì
*/

//õ“G”ÍˆÍ“–‚½‚è”»’èŽÀ‘Ì
ShielderPatrolCollision::ShielderPatrolCollision(int x, int y) {
	_x = x;
	_y = y;
	Init();
}
ShielderPatrolCollision::~ShielderPatrolCollision() {
}

void ShielderPatrolCollision::Init() {
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

//UŒ‚”­¶”ÍˆÍ“–‚½‚è”»’èŽÀ‘Ì
ShielderComingCollision::ShielderComingCollision(int x, int y) {
	_x = x;
	_y = y;
	Init();
}
ShielderComingCollision::~ShielderComingCollision() {
}

void ShielderComingCollision::Init() {
	_gx = 0;
	_gy = 0;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = COMING_WIDTH;
	_hit_h = COMING_HEIGHT;
#ifdef _DEBUG
	_Color = std::make_tuple(255, 255, 0);
	_Dalpha = 128;
	_Fill = true;
#endif
}

//UŒ‚“–‚½‚è”»’èŽÀ‘Ì
ShielderAttackCollision::ShielderAttackCollision(int x, int y) {
	_x = x;
	_y = y;
	Init();
}
ShielderAttackCollision::~ShielderAttackCollision() {
}

void ShielderAttackCollision::Init() {
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

void ShielderAttackCollision::Process(Game& g) {
	ObjectBase::Process(g);
	if (_Cnt - _Action_Cnt == ATTACK_ENDFRAME) {
		g.GetOS()->Del(this);
	}
}
void ShielderAttackCollision::Draw(Game& g) {
	ObjectBase::Draw(g);
}
void ShielderAttackCollision::Delete(Game& g) {
	g.GetOS()->Del(this);
}


