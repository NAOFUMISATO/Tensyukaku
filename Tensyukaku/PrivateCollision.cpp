#include <DxLib.h>
#include "PrivateCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"


/*
ó‚¯‘¤‚Å”»’è‚ğæ‚ç‚È‚¢Û‚Ì“–‚½‚è”»’èÀ‘Ì
*/
PrivateCollision::PrivateCollision(int x, int y,int hit_w,int hit_h) {
	_x = x;
	_y = y;
	_hit_w = hit_w;
	_hit_h = hit_h;
	Init();
}
PrivateCollision::~PrivateCollision() {
}

void PrivateCollision::Init() {
	_gx = 0;
	_gy = 0;
	_hit_x = 0;
	_hit_y = 0;
#ifdef _DEBUG
	_debug_alpha = 128;
	_debug_fill = true;
#endif
}