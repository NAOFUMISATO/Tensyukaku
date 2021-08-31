#include <DxLib.h>
#include "Poison.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
#include "Game.h"
/*
	ì≈ât
*/
using namespace PoInfo;
//ì≈âtèÄîı
PoisonReserve::PoisonReserve(int x, int y) {
	_x = x;
	_y = y;
	Init();
	_GrAll["Reserve"].resize(RESERVE_ANIMEMAX);
	ResourceServer::LoadDivGraph(RESERVE_GRAPHNAME, RESERVE_ANIMEMAX, RESERVE_WIDTHCOUNT, RESERVE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Reserve"].data());
}

PoisonReserve::~PoisonReserve() {
};

void PoisonReserve::Init() {
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_Alpha = 255;
	_Dalpha = 0;
	_Action_Cnt = _Cnt;
}

void PoisonReserve::Process(Game& g) {
	ObjectBase::Process(g);
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Reserve"][_Anime["Reserve"]];
	if (frame < RESERVE_ANIMEFRAME) {
		_Anime["Reserve"] = ((frame) / ANIMESPEED_RESERVE) % RESERVE_ANIMEMAX;
	}
	if (frame == RESERVE_FALLFRAME) {
		auto pf = new PoisonFall(_x+_gx,_y+_gy);
		g.GetOS()->Add(pf);
	}
	if (frame >= RESERVE_ANIMEFRAME && frame < RESERVE_ALLFRAME) {
		_Alpha -= RESERVE_FADEOUTSPEED;
	}
	if (frame == RESERVE_ALLFRAME) {
		Delete(g);
	}
}

void PoisonReserve::Draw(Game& g) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Alpha);
	ObjectBase::Draw(g);
}

void PoisonReserve::Delete(Game& g) {
	g.GetOS()->Del(this);
}

//ì≈âtóéâ∫
PoisonFall::PoisonFall(int x, int y) {
	_x = x;
	_y = y;
	Init();
	_GrAll["Fall"].resize(FALL_ANIMEMAX);
	ResourceServer::LoadDivGraph(FALL_GRAPHNAME, FALL_ANIMEMAX, FALL_WIDTHCOUNT, FALL_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Fall"].data());
}

PoisonFall::~PoisonFall() {
}

void PoisonFall::Init() {
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_Alpha = 255;
	_Spd =0;
	_Action_Cnt = _Cnt;
	_Appear_y = _y;
}

void PoisonFall::Process(Game& g) {
	ObjectBase::Process(g);
	auto frame = _Cnt - _Action_Cnt;
	auto ymovement = _y - _Appear_y;
	if (ymovement < FALL_STOPHEIGHT) {
		_y += _Spd;
		_Spd++;
	}
	_GrHandle = _GrAll["Fall"][_Anime["Fall"]];
	if (frame >= FALL_ANIMEFRAME) {
		_Anime["Fall"] = ((frame) / ANIMESPEED_FALL) % FALL_ANIMEMAX;
	}

	if (frame >= FALL_ANIMEFRAME && frame < FALL_ALLFRAME) {
		_Alpha -= FALL_FADEOUTSPEED;
	}
	if (frame == FALL_ALLFRAME) {
		Delete(g);
	}
}

void PoisonFall::Draw(Game& g) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Alpha);
	ObjectBase::Draw(g);
}

void PoisonFall::Delete(Game& g) {
	g.GetOS()->Del(this);
}