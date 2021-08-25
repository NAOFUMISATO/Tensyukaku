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
	_w = MIDDLEATTACK_WIDTH;
	_h = MIDDLEATTACK_HEIGHT;
	_gx = 0;
	_gy = 0;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = MIDDLEATTACK_WIDTH;
	_hit_h = MIDDLEATTACK_HEIGHT;
	_Action_Cnt = _Cnt;
#ifdef _DEBUG
	_color = std::make_tuple(255, 0, 0);
	_Dalpha = 128;
	_fill = true;
#endif
}

void MiddleAttackCollision::Process(Game& g) {
	ObjectBase::Process(g);
	if (_Cnt - _Action_Cnt == MIDDLEATTACK_ENDFRAME) {
		g.GetOS()->Del(this);
	}
}
void MiddleAttackCollision::Draw(Game& g) {
	ObjectBase::Draw(g);
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
	_w = LOWATTACK_WIDTH;
	_h = LOWATTACK_HEIGHT;
	_gx = 0;
	_gy = 0;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = LOWATTACK_WIDTH;
	_hit_h = LOWATTACK_HEIGHT;
	_Action_Cnt = _Cnt;
#ifdef _DEBUG
	_color = std::make_tuple(255, 0, 0);
	_Dalpha = 128;
	_fill = true;
#endif
}

void LowAttackCollision::Process(Game& g) {
	ObjectBase::Process(g);
	if (_Cnt - _Action_Cnt == LOWATTACK_ENDFRAME) {
		g.GetOS()->Del(this);
	}
}
void LowAttackCollision::Draw(Game& g) {
	ObjectBase::Draw(g);
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
	_w = KICK_WIDTH;
	_h = KICK_HEIGHT;
	_gx = 0;
	_gy = 0;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = KICK_WIDTH;
	_hit_h = KICK_HEIGHT;
	_Action_Cnt = _Cnt;
#ifdef _DEBUG
	_color = std::make_tuple(255, 0, 0);
	_Dalpha = 128;
	_fill = true;
#endif
}

void KickCollision::Process(Game& g) {
	ObjectBase::Process(g);
	if (_Cnt - _Action_Cnt == KICK_ENDFRAME) {
		g.GetOS()->Del(this);
	}
}
void KickCollision::Draw(Game& g) {
	ObjectBase::Draw(g);
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
	_w = IAI_WIDTH;
	_h = IAI_HEIGHT;
	_gx = 0;
	_gy = 0;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = IAI_WIDTH;
	_hit_h = IAI_HEIGHT;
	_Action_Cnt = _Cnt;
#ifdef _DEBUG
	_color = std::make_tuple(255, 0, 0);
	_Dalpha = 128;
	_fill = true;
#endif
}

void IaiCollision::Process(Game& g) {
	ObjectBase::Process(g);
	if (_Cnt - _Action_Cnt == IAI_ENDFRAME) {
		g.GetOS()->Del(this);
	}
}
void IaiCollision::Draw(Game& g) {
	ObjectBase::Draw(g);
}
void IaiCollision::Delete(Game& g) {
	g.GetOS()->Del(this);
}

