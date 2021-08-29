#include <DxLib.h>
#include "NinjaMotionCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Ninja.h"

/*
忍者の各モーション時の当たり判定実体
*/
using namespace NInfo;

//攻撃当たり判定実体
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