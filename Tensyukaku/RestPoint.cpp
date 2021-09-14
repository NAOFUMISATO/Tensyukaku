#include <DxLib.h>
#include "RestPoint.h"
#include "ResourceServer.h"

RestPoint::RestPoint() {
	Init();
	_GrHandle=ResourceServer::LoadGraph("res/Gimik/RestPoint.png");
}
RestPoint::~RestPoint() {
}

void RestPoint::Init() {
	_x = 3100;
	_y = 5050;
_gx = 0;
_gy = 160;
_hit_x = -80;
_hit_y = -160;
_hit_w = 160;
_hit_h = 320;
}

void RestPoint::Process(Game& g) {
	ObjectBase::Process(g);
}

void RestPoint::Draw(Game& g) {
	ObjectBase::Draw(g);
}