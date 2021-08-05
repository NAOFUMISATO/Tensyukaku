#include <DxLib.h>
#include "BushiPatrolCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Bushi.h"
namespace {
	constexpr auto Width = 500;
	constexpr auto Height = 100;
}
using namespace BInfo;
using namespace Tsk;
BushiPatrolCollision::BushiPatrolCollision() {
	Init();
}
BushiPatrolCollision::~BushiPatrolCollision() {
}

void BushiPatrolCollision::Init() {
	_w = Width;
	_h = Height;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = Width;
	_hit_h = Height;
	_Action_Cnt = _Cnt;
}

void BushiPatrolCollision::Process(Game& g) {
	ObjectBase::Process(g);
	if(_Cnt-_Action_Cnt== Patrol_Frame1|| _Cnt - _Action_Cnt == Patrol_Frame2)
	{
		g.GetOS()->Del(this); 
	}
}
void BushiPatrolCollision::Draw(Game& g) {
#ifdef _DEBUG
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// ”¼“§–¾•`‰æŽw’è
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_w, _y + _hit_h, GetColor(255, 0, 0), FALSE);	// ”¼“§–¾‚ÌÔ‚Å“–‚½‚è”»’è•`‰æ
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// •s“§–¾•`‰æŽw’è
#endif
}
void BushiPatrolCollision::Damage(Game& g) {
	g.GetOS()->Del(this);
}

