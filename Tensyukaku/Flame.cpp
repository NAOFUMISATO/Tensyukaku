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
	_GrAll["Flame"].resize(FLAME_ANIMEMAX);
	ResourceServer::LoadDivGraph(FLAME_GRAPHNAME, FLAME_ANIMEMAX, FLAME_WIDTHCOUNT, FLAME_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Flame"].data());
}
Flame::~Flame() {
}

void Flame::Init() {
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_Alpha = 255;
	_Action_Cnt = _Cnt;
	_Color = std::make_tuple(0, 0, 255);
}

void Flame::Process(Game& g) {
ObjectBase::Process(g);
	auto frame = _Cnt-_Action_Cnt;
	_GrHandle = _GrAll["Flame"][_Anime["Flame"]];
	_Anime["Flame"] = (_Cnt / ANIMESPEED_FLAME) % FLAME_ANIMEMAX;
	
	if (frame >= FLAME_ANIMEFRAME && FLAME_ALLFLAME > frame) {
		_Alpha -= FLAME_FADEOUTSPEED;
	}
	if (frame == FLAME_ALLFLAME) {
		Delete(g);
	}

}

void Flame::Draw(Game& g) {
SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Alpha);
ObjectBase::Draw(g);
}

void Flame::Delete(Game& g) {
	g.GetOS()->Del(this);
}