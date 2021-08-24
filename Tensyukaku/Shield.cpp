#include <DxLib.h>
#include "ResourceServer.h"
#include "Shielder.h"
#include "Shield.h"
#include "Game.h"
#include "ObjectBase.h"
#include <utility>

using namespace ShInfo;
Shield::Shield() {
	Init();
	_GrHandle = ResourceServer::LoadGraph("res/Shielder/Shield.png");
}
Shield::~Shield() {
}

void Shield::Init() {
	_w = GraphWidth;
	_h = GraphHeight;
	_gx = GraphX;
	_gy = GraphY;
	_hit_x = PositionHitX;
	_hit_y = PositionHitY;
	_hit_w = CollisionWidth;
	_hit_h = CollisionHeight;
	_drg.second = Angle;
	_Dalpha = 0;
}

void Shield::Process(Game& g) {
	ObjectBase::Process(g);
}

void Shield::Draw(Game& g) {
	ObjectBase::Draw(g);
}

