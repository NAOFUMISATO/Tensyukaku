#include <DxLib.h>
#include "NinjaMotionCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Ninja.h"

using namespace Tsk;
using namespace NInfo;
NinjaPatrolCollision::NinjaPatrolCollision() {
	Init();
}
NinjaPatrolCollision::~NinjaPatrolCollision() {
}

void NinjaPatrolCollision::Init() {
	_w = PatrolWidth;
	_h = PatrolHeight;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = PatrolWidth;
	_hit_h = PatrolHeight;
}

void NinjaPatrolCollision::Process(Game& g) {
	ObjectBase::Process(g);
}

NinjaComingCollision::NinjaComingCollision() {
	Init();
}
NinjaComingCollision::~NinjaComingCollision() {
}

void NinjaComingCollision::Init() {
	_w = ComingWidth;
	_h = ComingHeight;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = ComingWidth;
	_hit_h = ComingHeight;
}

void NinjaComingCollision::Process(Game& g) {
	ObjectBase::Process(g);
}

NinjaAttackCollision::NinjaAttackCollision() {
	Init();
}
NinjaAttackCollision::~NinjaAttackCollision() {
}

void NinjaAttackCollision::Init() {
	_w = AttackWidth;
	_h = AttackHeight;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = AttackWidth;
	_hit_h = AttackHeight;
	_Action_Cnt = _Cnt;
}

void NinjaAttackCollision::Process(Game& g) {
	ObjectBase::Process(g);
	if (_Cnt - _Action_Cnt == AEnd_Frame) {
		g.GetOS()->Del(this);
	}
}
void NinjaAttackCollision::Draw(Game& g) {
#ifdef _DEBUG
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// ”¼“§–¾•`‰æŽw’è
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_w, _y + _hit_h, GetColor(255, 0, 0), FALSE);	// ”¼“§–¾‚ÌÔ‚Å“–‚½‚è”»’è•`‰æ
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// •s“§–¾•`‰æŽw’è
#endif
}
void NinjaAttackCollision::Delete(Game& g) {
	g.GetOS()->Del(this);
}