#include <DxLib.h>
#include "MugenFlame.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
#include "Game.h"
using namespace MFInfo;
MugenFlame::MugenFlame(int x, int y) {
	_x = x;
	_y = y;
	Init();
	_GrAll["Flame"].resize(MFLAME_ANIMEMAX);
	ResourceServer::LoadDivGraph(MFLAME_GRAPHNAME, MFLAME_ANIMEMAX, MFLAME_WIDTHCOUNT, MFLAME_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Flame"].data());
}
MugenFlame::~MugenFlame() {
}

void MugenFlame::Init() {
	_Sort = 7;
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

void MugenFlame::Process(Game& g) {
	ObjectBase::Process(g);
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Flame"][_Anime["Flame"]];
	_Anime["Flame"] = (_Cnt / ANIMESPEED_MFLAME) % MFLAME_ANIMEMAX;

	if (frame >= MFLAME_ANIMEFRAME && MFLAME_ALLFLAME > frame) {
		_Alpha -= MFLAME_FADEOUTSPEED;
	}
}

void MugenFlame::Draw(Game& g) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Alpha);
	ObjectBase::Draw(g);
}

void MugenFlame::Delete(Game& g) {
	g.GetOS()->Del(this);
}