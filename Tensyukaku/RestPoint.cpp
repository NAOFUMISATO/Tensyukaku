#include <DxLib.h>
#include "RestPoint.h"
#include "ResourceServer.h"

RestPoint::RestPoint(int x,int y) {
	_x = x;
	_y = y;
	Init();
	_grhandle=ResourceServer::LoadGraph("res/Gimik/RestPoint.png");
}
RestPoint::~RestPoint() {
}

void RestPoint::Init() {
	_sort = 5;
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