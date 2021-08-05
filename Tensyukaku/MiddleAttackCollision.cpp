#include <DxLib.h>
#include "MiddleAttackCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Player.h"
namespace {
	constexpr auto Width = 150;
	constexpr auto Height = 125;
}

using namespace Tsk;
using namespace PInfo;
MiddleAttackCollision::MiddleAttackCollision() {
	Init();
}
MiddleAttackCollision::~MiddleAttackCollision() {
}

void MiddleAttackCollision::Init() {
	_w = Width;
	_h = Height;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = Width;
	_hit_h = Height;
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

