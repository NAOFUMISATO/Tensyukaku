#include <DxLib.h>
#include "BushiPatrolCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Bushi.h"
namespace {
	constexpr auto Width = 800;
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
	if (_Cnt - _Action_Cnt == Patrol_Frame || _Cnt - _Action_Cnt == Patrol_Frame+Patrol_Frame) {
	}
}
void BushiPatrolCollision::Draw(Game& g) {
#ifdef _DEBUG
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// îºìßñæï`âÊéwíË
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_w, _y + _hit_h, GetColor(255, 0, 0), FALSE);	// îºìßñæÇÃê‘Ç≈ìñÇΩÇËîªíËï`âÊ
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// ïsìßñæï`âÊéwíË
#endif
}
void BushiPatrolCollision::Damage(Game& g) {
}

