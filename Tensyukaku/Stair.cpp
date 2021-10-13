#include <DxLib.h>
#include "Stair.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
#include "Game.h"
using namespace StInfo;
Stair::Stair(int x,int y,bool flip) {
   _x = x;
   _y = y;
   _isflip = flip;
   Init();
   _grhandle=ResourceServer::LoadGraph("res/Gimik/Stair.png");
}
Stair::~Stair() {
}

void Stair::Init() {
   _sort = 4;
   _gx = GRAPHPOINT_X;
   _gy = GRAPHPOINT_Y;
   _hit_x = POSITION_HITX;
   _hit_y = POSITION_HITY;
   _hit_w = COLLISION_WIDTH;
   _hit_h = COLLISION_HEIGHT;
#ifdef _DEBUG
   _debug_color = std::make_tuple(0, 0, 255);
   _debug_alpha = 128;
   _debug_fill = false;
#endif
}
void Stair::Process(Game& g) {
   ObjectBase::Process(g);
}

void Stair::Draw(Game& g) {
   ObjectBase::Draw(g);
}