#include <DxLib.h>
#include "BusyoMotionCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Busyo.h"

/*
•«‚ÌŠeƒ‚[ƒVƒ‡ƒ“Žž‚Ì“–‚½‚è”»’èŽÀ‘Ì
*/	
using namespace BsInfo;

//UŒ‚“–‚½‚è”»’èŽÀ‘Ì
BusyoAttackCollision::BusyoAttackCollision(int x, int y) {
	_x = x;
	_y = y;
	Init();
}
BusyoAttackCollision::~BusyoAttackCollision() {
}

void BusyoAttackCollision::Init() {
	_gx = 0;
	_gy = 0;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = ATTACK_WIDTH;
	_hit_h = ATTACK_HEIGHT;
	_action_cnt = _cnt;
#ifdef _DEBUG
	_Color = std::make_tuple(255, 0, 0);
	_Dalpha = 128;
	_Fill = true;
#endif
}

void BusyoAttackCollision::Process(Game& g) {
	ObjectBase::Process(g);
	auto frame = _cnt - _action_cnt;
	if (frame == ATTACK_ENDFRAME||frame==ATTACK_END2FRAME) {
		g.GetOS()->Del(this);
	}
}
void BusyoAttackCollision::Draw(Game& g) {
	ObjectBase::Draw(g);
}
void BusyoAttackCollision::Delete(Game& g) {
	g.GetOS()->Del(this);
}


