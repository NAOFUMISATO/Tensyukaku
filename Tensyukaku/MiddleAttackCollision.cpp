#include <DxLib.h>
#include "MiddleAttackCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
namespace {
	constexpr auto Width = 150;
	constexpr auto Height = 125;
}

using namespace Tsk;
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

}

void MiddleAttackCollision::Process(Game& g) {

}
void MiddleAttackCollision::Draw(Game& g) {
#ifdef _DEBUG
	DebugDraw();
#endif

}
void MiddleAttackCollision::Damage(Game& g) {
	g.GetOS()->Del(this);
}

void MiddleAttackCollision::DebugDraw() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// ”¼“§–¾•`‰æw’è
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_w, _y + _hit_h, GetColor(255, 0, 0), FALSE);	// ”¼“§–¾‚ÌÔ‚Å“–‚½‚è”»’è•`‰æ
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// •s“§–¾•`‰æw’è
}

