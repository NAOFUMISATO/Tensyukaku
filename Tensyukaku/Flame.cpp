#include <DxLib.h>
#include "Flame.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
#include "Game.h"
using namespace FInfo;
Flame::Flame(int x, int y) {
	_x = x;
	_y = y;
	Init();
	_grall["Flame"].resize(FLAME_ANIMEMAX);
	ResourceServer::LoadDivGraph(FLAME_GRAPHNAME, FLAME_ANIMEMAX, FLAME_WIDTHCOUNT, FLAME_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Flame"].data());
}
Flame::~Flame() {
}

void Flame::Init() {
	_sort = 7;
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_alpha = 255;
	_action_cnt = _cnt;
	_debug_color = std::make_tuple(0, 0, 255);
}

void Flame::Process(Game& g) {
ObjectBase::Process(g);
	auto frame = _cnt-_action_cnt;
	_grhandle = _grall["Flame"][_anime["Flame"]];
	_anime["Flame"] = (_cnt / ANIMESPEED_FLAME) % FLAME_ANIMEMAX;
	
	if (frame >= FLAME_ANIMEFRAME && FLAME_ALLFLAME > frame) {
		_alpha -= FLAME_FADEOUTSPEED;
	}
	if (frame == FLAME_ALLFLAME) {
		Delete(g);
	}

}

void Flame::Draw(Game& g) {
SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
ObjectBase::Draw(g);
}

void Flame::Delete(Game& g) {
	g.GetOS()->Del(this);
}