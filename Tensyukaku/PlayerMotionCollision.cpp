#include <DxLib.h>
#include "PlayerMotionCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Player.h"


using namespace PInfo;

//中段攻撃当たり判定実体
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
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// 半透明描画指定
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_w, _y + _hit_h, GetColor(255, 0, 0), FALSE);	// 半透明の赤で当たり判定描画
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// 不透明描画指定
#endif
}
void MiddleAttackCollision::Delete(Game& g) {
	g.GetOS()->Del(this);
}

//下段攻撃当たり判定実体
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
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// 半透明描画指定
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_w, _y + _hit_h, GetColor(255, 0, 0), FALSE);	// 半透明の赤で当たり判定描画
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// 不透明描画指定
#endif

}
void LowAttackCollision::Delete(Game& g) {
	g.GetOS()->Del(this);
}

//蹴り当たり判定実体
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
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// 半透明描画指定
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_w, _y + _hit_h, GetColor(255, 0, 0), FALSE);	// 半透明の赤で当たり判定描画
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// 不透明描画指定
#endif
}
void KickCollision::Delete(Game& g) {
	g.GetOS()->Del(this);
}

//居合当たり判定実体
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
	if (_Cnt - _Action_Cnt == IAEnd_Frame) {
		g.GetOS()->Del(this);
	}
}
void IaiCollision::Draw(Game& g) {
#ifdef _DEBUG
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// 半透明描画指定
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_w, _y + _hit_h, GetColor(255, 0, 0), FALSE);	// 半透明の赤で当たり判定描画
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// 不透明描画指定
#endif
}
void IaiCollision::Delete(Game& g) {
	g.GetOS()->Del(this);
}

