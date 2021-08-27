#include <DxLib.h>
#include "NinjaMotionCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Ninja.h"

/*
”EŽÒ‚ÌŠeƒ‚[ƒVƒ‡ƒ“Žž‚Ì“–‚½‚è”»’èŽÀ‘Ì
*/
using namespace NInfo;
//õ“G”ÍˆÍ“–‚½‚è”»’èŽÀ‘Ì
NinjaPatrolCollision::NinjaPatrolCollision(int x,int y) {
	_x = x;
	_y = y;
	Init();
}
NinjaPatrolCollision::~NinjaPatrolCollision() {
}

void NinjaPatrolCollision::Init() {
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
NinjaComingCollision::NinjaComingCollision(int x, int y) {
	_x = x;
	_y = y;
	Init();
}
NinjaComingCollision::~NinjaComingCollision() {
}

void NinjaComingCollision::Init() {
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
NinjaAttackCollision::NinjaAttackCollision(int x, int y) {
	_x = x;
	_y = y;
	Init();
}
NinjaAttackCollision::~NinjaAttackCollision() {
}

void NinjaAttackCollision::Init() {
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

void NinjaAttackCollision::Process(Game& g) {
	ObjectBase::Process(g);
	if (_Cnt - _Action_Cnt == ATTACK_ENDFRAME) {
		g.GetOS()->Del(this);
	}
}
void NinjaAttackCollision::Draw(Game& g) {
	ObjectBase::Draw(g);
}
void NinjaAttackCollision::Delete(Game& g) {
	g.GetOS()->Del(this);
}