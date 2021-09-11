#include <DxLib.h>
#include "PlayerMotionCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Player.h"



using namespace PInfo;


//���i�U�������蔻�����
MiddleAttackCollision::MiddleAttackCollision(int x,int y) {
	_x = x;
	_y = y;
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
	_Color = std::make_tuple(255, 0, 0);
	_Dalpha = 128;
	_Fill = true;
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

//���i�U�������蔻�����
LowAttackCollision::LowAttackCollision(int x, int y) {
	_x = x;
	_y = y;
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
	_Color = std::make_tuple(255, 0, 0);
	_Dalpha = 128;
	_Fill = true;
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

//�R�蓖���蔻�����
KickCollision::KickCollision(int x, int y) {
	_x = x;
	_y = y;
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
	_Color = std::make_tuple(255, 0, 0);
	_Dalpha = 128;
	_Fill = true;
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

//���������蔻�����
IaiCollision::IaiCollision(int x, int y) {
	_x = x;
	_y = y;
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
	_Color = std::make_tuple(255,0, 0);
	_Dalpha = 128;
	_Fill = true;
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


//����U�������蔻�����
SpecialCollision::SpecialCollision(int x, int y) {
	_x = x;
	_y = y;
	Init();
}
SpecialCollision::~SpecialCollision() {
}

void SpecialCollision::Init() {
	_w = SPECIALATTACK_WIDTH;
	_h = SPECIALATTACK_HEIGHT;
	_gx = 0;
	_gy = 0;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = SPECIALATTACK_WIDTH;
	_hit_h = SPECIALATTACK_HEIGHT;
	_Action_Cnt = _Cnt;
#ifdef _DEBUG
	_Color = std::make_tuple(255, 0, 0);
	_Dalpha = 128;
	_Fill = true;
#endif
}

void SpecialCollision::Process(Game& g) {
	ObjectBase::Process(g);
	if (_Cnt - _Action_Cnt == SPECIALATTACK_ENDFRAME) {
		g.GetOS()->Del(this);
	}
}
void SpecialCollision::Draw(Game& g) {
	ObjectBase::Draw(g);
}
void SpecialCollision::Delete(Game& g) {
	g.GetOS()->Del(this);
}
