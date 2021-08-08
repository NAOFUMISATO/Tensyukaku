#include <DxLib.h>
#include "BushiMotionCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Bushi.h"

using namespace Tsk;
using namespace BInfo;
/*
•Žm‚ÌŠeƒ‚[ƒVƒ‡ƒ“Žž‚Ì“–‚½‚è”»’èŽÀ‘Ì
*/

//õ“G”ÍˆÍ“–‚½‚è”»’èŽÀ‘Ì
BushiPatrolCollision::BushiPatrolCollision() {
	Init();
}
BushiPatrolCollision::~BushiPatrolCollision() {
}

void BushiPatrolCollision::Init() {
	_w = PatrolWidth;
	_h = PatrolHeight;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = PatrolWidth;
	_hit_h = PatrolHeight;
}

void BushiPatrolCollision::Process(Game& g) {
	ObjectBase::Process(g);
}


//UŒ‚”­¶”ÍˆÍ“–‚½‚è”»’èŽÀ‘Ì
BushiComingCollision::BushiComingCollision() {
	Init();
}
BushiComingCollision::~BushiComingCollision() {
}

void BushiComingCollision::Init() {
	_w = ComingWidth;
	_h = ComingHeight;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = ComingWidth;
	_hit_h = ComingHeight;
}

void BushiComingCollision::Process(Game& g) {
	ObjectBase::Process(g);
}


//UŒ‚“–‚½‚è”»’èŽÀ‘Ì
BushiAttackCollision::BushiAttackCollision() {
	Init();
}
BushiAttackCollision::~BushiAttackCollision() {
}

void BushiAttackCollision::Init() {
	_w = AttackWidth;
	_h = AttackHeight;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = AttackWidth;
	_hit_h = AttackHeight;
	_Action_Cnt = _Cnt;
}

void BushiAttackCollision::Process(Game& g) {
	ObjectBase::Process(g);
	if (_Cnt - _Action_Cnt == AEnd_Frame) {
		g.GetOS()->Del(this);
	}
}
void BushiAttackCollision::Draw(Game& g) {
#ifdef _DEBUG
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// ”¼“§–¾•`‰æŽw’è
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_w, _y + _hit_h, GetColor(255, 0, 0), FALSE);	// ”¼“§–¾‚ÌÔ‚Å“–‚½‚è”»’è•`‰æ
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// •s“§–¾•`‰æŽw’è
#endif
}
void BushiAttackCollision::Delete(Game& g) {
	g.GetOS()->Del(this);
}


