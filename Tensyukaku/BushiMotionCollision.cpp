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

//UŒ‚“–‚½‚è”»’èŽÀ‘Ì
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
	_action_cnt = _cnt;
#ifdef _DEBUG
	_Color = std::make_tuple(255, 0, 0);
	_Dalpha = 128;
	_Fill = true;
#endif
}

void BushiAttackCollision::Process(Game& g) {
	ObjectBase::Process(g);
	if (_cnt - _action_cnt == ATTACK_ENDFRAME) {
		g.GetOS()->Del(this);
	}
}
void BushiAttackCollision::Draw(Game& g) {
	ObjectBase::Draw(g);
}
void BushiAttackCollision::Delete(Game& g) {
	g.GetOS()->Del(this);
}


