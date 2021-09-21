#include <DxLib.h>
#include "LancerMotionCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Lancer.h"


using namespace LInfo;
/*
�����̊e���[�V�������̓����蔻�����
*/

//�U�������蔻�����
LancerAttackCollision::LancerAttackCollision(int x, int y) {
	_x = x;
	_y = y;
	Init();
}
LancerAttackCollision::~LancerAttackCollision() {
}

void LancerAttackCollision::Init() {
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

void LancerAttackCollision::Process(Game& g) {
	ObjectBase::Process(g);
	if (_Cnt - _Action_Cnt == ATTACK_ENDFRAME) {
		g.GetOS()->Del(this);
	}
}
void LancerAttackCollision::Draw(Game& g) {
	ObjectBase::Draw(g);
}
void LancerAttackCollision::Delete(Game& g) {
	g.GetOS()->Del(this);
}


