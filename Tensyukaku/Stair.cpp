#include <DxLib.h>
#include "Stair.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
using namespace StInfo;
Stair::Stair() {
	Init();
	_GrHandle=ResourceServer::LoadGraph("res/Map/Stair.png");
}
Stair::~Stair() {
}

void Stair::Init() {
	_x = PositionX;
	_y = PositionY;
	_gx = GraphPointX;
	_gy = GraphPointY;
	_hit_x = PositionHitX;
	_hit_y = PositionHitY;
	_hit_w = CollisionWidth;
	_hit_h = CollisionHeight;
	_isFlip = true;
#ifdef _DEBUG
	_color = std::make_tuple(0, 0, 255);
	_Dalpha = 128;
	_fill = false;
#endif
}
void Stair::Process(Game& g) {
	ObjectBase::Process(g);
}

void Stair::Draw(Game& g) {
	ObjectBase::Draw(g);
}