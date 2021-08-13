#include <DxLib.h>
#include "PlayerMotionCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Player.h"


using namespace PInfo;

//’†’iUŒ‚“–‚½‚è”»’èŽÀ‘Ì
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
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// ”¼“§–¾•`‰æŽw’è
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_w, _y + _hit_h, GetColor(255, 0, 0), FALSE);	// ”¼“§–¾‚ÌÔ‚Å“–‚½‚è”»’è•`‰æ
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// •s“§–¾•`‰æŽw’è
#endif
}
void MiddleAttackCollision::Delete(Game& g) {
	g.GetOS()->Del(this);
}

//‰º’iUŒ‚“–‚½‚è”»’èŽÀ‘Ì
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
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// ”¼“§–¾•`‰æŽw’è
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_w, _y + _hit_h, GetColor(255, 0, 0), FALSE);	// ”¼“§–¾‚ÌÔ‚Å“–‚½‚è”»’è•`‰æ
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// •s“§–¾•`‰æŽw’è
#endif

}
void LowAttackCollision::Delete(Game& g) {
	g.GetOS()->Del(this);
}

//R‚è“–‚½‚è”»’èŽÀ‘Ì
KickCollision::KickCollision() {
	Init();
}
KickCollision::~KickCollision() {
}

void KickCollision::Init() {
	_w = KickWidth;
	_h = KickHeight;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = KickWidth;
	_hit_h = KickHeight;
	_Action_Cnt = _Cnt;
}

void KickCollision::Process(Game& g) {
	ObjectBase::Process(g);
	if (_Cnt - _Action_Cnt == KIEnd_Frame) {
		g.GetOS()->Del(this);
	}
}
void KickCollision::Draw(Game& g) {
#ifdef _DEBUG
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// ”¼“§–¾•`‰æŽw’è
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_w, _y + _hit_h, GetColor(255, 0, 0), FALSE);	// ”¼“§–¾‚ÌÔ‚Å“–‚½‚è”»’è•`‰æ
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// •s“§–¾•`‰æŽw’è
#endif
}
void KickCollision::Delete(Game& g) {
	g.GetOS()->Del(this);
}

//‹‡“–‚½‚è”»’èŽÀ‘Ì
IaiCollision::IaiCollision() {
	Init();
}
IaiCollision::~IaiCollision() {
}

void IaiCollision::Init() {
	_w = IaiWidth;
	_h = IaiHeight;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = IaiWidth;
	_hit_h = IaiHeight;
	_Action_Cnt = _Cnt;
}

void IaiCollision::Process(Game& g) {
	ObjectBase::Process(g);
	if (_Cnt - _Action_Cnt == KIEnd_Frame) {
		g.GetOS()->Del(this);
	}
}
void IaiCollision::Draw(Game& g) {
#ifdef _DEBUG
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// ”¼“§–¾•`‰æŽw’è
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_w, _y + _hit_h, GetColor(255, 0, 0), FALSE);	// ”¼“§–¾‚ÌÔ‚Å“–‚½‚è”»’è•`‰æ
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// •s“§–¾•`‰æŽw’è
#endif
}
void IaiCollision::Delete(Game& g) {
	g.GetOS()->Del(this);
}

