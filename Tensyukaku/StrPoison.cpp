#include <DxLib.h>
#include "StrPoison.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
#include "Game.h"
/*
	ì≈ât
*/
using namespace SPInfo;
//ì≈âtèÄîı
StrPoisonReserve::StrPoisonReserve(int x, int y) {
	_x = x;
	_y = y;
	Init();
	_GrAll["Reserve"].resize(RESERVE_ANIMEMAX);
	ResourceServer::LoadDivGraph(RESERVE_GRAPHNAME, RESERVE_ANIMEMAX, RESERVE_WIDTHCOUNT, RESERVE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Reserve"].data());

}

StrPoisonReserve::~StrPoisonReserve() {
};

void StrPoisonReserve::Init() {
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_Alpha = 255;
	_Dalpha = 0;
	_Action_Cnt = _Cnt;
}

void StrPoisonReserve::Process(Game& g) {
	ObjectBase::Process(g);
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Reserve"][_Anime["Reserve"]];
	if (frame < RESERVE_ANIMEFRAME) {
		_Anime["Reserve"] = ((frame) / ANIMESPEED_RESERVE) % RESERVE_ANIMEMAX;
	}
	if (frame == RESERVE_FALLFRAME) {
		auto pf = new StrPoisonFall(_x + _gx, _y + _gy);
		g.GetOS()->Add(pf);
	}
	if (frame >= RESERVE_ANIMEFRAME && frame < RESERVE_ALLFRAME) {
		_Alpha -= RESERVE_FADEOUTSPEED;
	}
	if (frame == RESERVE_ALLFRAME) {
		Delete(g);
	}
}

void StrPoisonReserve::Draw(Game& g) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Alpha);
	ObjectBase::Draw(g);
}

void StrPoisonReserve::Delete(Game& g) {
	g.GetOS()->Del(this);
}

//ì≈âtóéâ∫
StrPoisonFall::StrPoisonFall(int x, int y) {
	_x = x;
	_y = y;
	Init();
	_GrAll["Fall"].resize(FALL_ANIMEMAX);
	ResourceServer::LoadDivGraph(FALL_GRAPHNAME, FALL_ANIMEMAX, FALL_WIDTHCOUNT, FALL_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Fall"].data());
	_GrAll["Land"].resize(LAND_ANIMEMAX);
	ResourceServer::LoadDivGraph(LAND_GRAPHNAME, LAND_ANIMEMAX, LAND_WIDTHCOUNT, LAND_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Land"].data());
}

StrPoisonFall::~StrPoisonFall() {
}

void StrPoisonFall::Init() {
	_Sort = 14;
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_Alpha = 255;
	_Spd = 15;
	_Action_Cnt = _Cnt;
	_Appear_y = _y;
	_State = POISONSTATE::FALL;
}

void StrPoisonFall::Process(Game& g) {
	ObjectBase::Process(g);
	auto frame = _Cnt - _Action_Cnt;
	switch (_State) {
	case	POISONSTATE::FALL:
		_GrHandle = _GrAll["Fall"][_Anime["Fall"]];
		_Anime["Fall"] = 0;
		if (frame < FALL_STOPFRAME) {
			_y += _Spd;
		}
		if (frame == FALL_STOPFRAME) {
			_Action_Cnt = _Cnt;
			_State = POISONSTATE::LAND;
		}
		break;
	case POISONSTATE::LAND:
		_GrHandle = _GrAll["Land"][_Anime["Land"]];
		if (frame < LAND_ANIMEFRAME) {
			_Anime["Land"] = ((frame) / ANIMESPEED_LAND) % LAND_ANIMEMAX;
		}
		if (frame >= LAND_ANIMEFRAME && LAND_ALLFRAME > frame) {
			_hit_x = 10000;
			_Alpha -= LAND_FADEOUTSPEED;
		}
		if (frame == LAND_ALLFRAME) {
			Delete(g);
			break;
		}



	}
}

void StrPoisonFall::Draw(Game& g) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Alpha);
	ObjectBase::Draw(g);
}

void StrPoisonFall::Delete(Game& g) {
	g.GetOS()->Del(this);
}