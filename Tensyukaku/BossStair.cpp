#include <DxLib.h>
#include "BossStair.h"
#include "ResourceServer.h"
#include "Game.h"

using namespace BSInfo;
BossStair::BossStair(int x, int y) {
	_x = x;
	_y = y;
	Init();
	_GrHandle = ResourceServer::LoadGraph("res/Gimik/Stair.png");
}
BossStair::~BossStair() {
}

void BossStair::Init() {
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_isFlip = false;
#ifdef _DEBUG
	_Color = std::make_tuple(0, 0, 255);
	_Dalpha = 128;
	_Fill = false;
#endif
}

void BossStair::Process(Game& g) {
	ObjectBase::Process(g);
}

void BossStair::Draw(Game& g) {
	ObjectBase::Draw(g);
}