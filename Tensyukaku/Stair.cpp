#include <DxLib.h>
#include "Stair.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
#include "Game.h"
using namespace StInfo;
Stair::Stair(int x,int y,bool flip) {
	_x = x;
	_y = y;
	_isFlip = flip;
	Init();
	_GrHandle=ResourceServer::LoadGraph("res/Gimik/Stair.png");
}
Stair::~Stair() {
}

void Stair::Init() {
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
#ifdef _DEBUG
	_Color = std::make_tuple(0, 0, 255);
	_Dalpha = 128;
	_Fill = false;
#endif
}
void Stair::Process(Game& g) {
	ObjectBase::Process(g);
}

void Stair::Draw(Game& g) {
	ObjectBase::Draw(g);
}