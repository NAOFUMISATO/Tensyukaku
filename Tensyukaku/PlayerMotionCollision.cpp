#include <DxLib.h>
#include "PlayerMotionCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Player.h"

using namespace Tsk;
using namespace PInfo;
MiddleAttackCollision::MiddleAttackCollision() {
	Init();
}
MiddleAttackCollision::~MiddleAttackCollision() {
}

void MiddleAttackCollision::Init() {
	_w = MiddleAttackWidth;
	_h = MiddleAttackHeight;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = MiddleAttackWidth;
	_hit_h = MiddleAttackHeight;
	_Action_Cnt = _Cnt;
}

void MiddleAttackCollision::Process(Game& g) {
	ObjectBase::Process(g);
	if (_Cnt - _Action_Cnt == MAEnd_Frame) {
		g.GetOS()->Del(this);
	}
}
void MiddleAttackCollision::Draw(Game& g) {
#ifdef _DEBUG
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// �������`��w��
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_w, _y + _hit_h, GetColor(255, 0, 0), FALSE);	// �������̐Ԃœ����蔻��`��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// �s�����`��w��
#endif
}
void MiddleAttackCollision::Damage(Game& g) {
	g.GetOS()->Del(this);
}

LowAttackCollision::LowAttackCollision() {
	Init();
}
LowAttackCollision::~LowAttackCollision() {
}

void LowAttackCollision::Init() {
	_w = LowAttackWidth;
	_h = LowAttackHeight;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = LowAttackWidth;
	_hit_h = LowAttackHeight;
	_Action_Cnt = _Cnt;
}

void LowAttackCollision::Process(Game& g) {
	ObjectBase::Process(g);
	if (_Cnt - _Action_Cnt == LAEnd_Frame) {
		g.GetOS()->Del(this);
	}
}
void LowAttackCollision::Draw(Game& g) {
#ifdef _DEBUG
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// �������`��w��
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_w, _y + _hit_h, GetColor(255, 0, 0), FALSE);	// �������̐Ԃœ����蔻��`��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// �s�����`��w��
#endif

}
void LowAttackCollision::Damage(Game& g) {
	g.GetOS()->Del(this);
}

