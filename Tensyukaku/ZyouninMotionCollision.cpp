#include <DxLib.h>
#include "ZyouninMotionCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Zyounin.h"

/*
��E�̊e���[�V�������̓����蔻�����
*/
using namespace ZInfo;

//�U�������蔻�����
ZyouninAttackCollision::ZyouninAttackCollision(int x, int y) {
	_x = x;
	_y = y;
	Init();
}
ZyouninAttackCollision::~ZyouninAttackCollision() {
}

void ZyouninAttackCollision::Init() {
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

void ZyouninAttackCollision::Process(Game& g) {
	ObjectBase::Process(g);
	if (_cnt - _action_cnt == ATTACK_ENDFRAME) {
		g.GetOS()->Del(this);
	}
}
void ZyouninAttackCollision::Draw(Game& g) {
	ObjectBase::Draw(g);
}
void ZyouninAttackCollision::Delete(Game& g) {
	g.GetOS()->Del(this);
}