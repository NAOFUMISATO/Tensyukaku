#include <DxLib.h>
#include "ResourceServer.h"
#include "Ninja.h"
#include "Kunai.h"
#include "Game.h"
#include "ObjectBase.h"

using namespace NInfo;
Kunai::Kunai(int x,int y, bool flip,int spd):_Repel_Flag(false) {
	_x = x;
	_y = y;
	_isFlip = flip;
	_Spd = spd;
	Init();
	_GrAll["Kunai"].resize(2);
	ResourceServer::LoadDivGraph(KUNAI_GRAPHNAME, 2, 2, 1, 120, 120, _GrAll["Kunai"].data());
}

Kunai::~Kunai() {
};

void Kunai::Init() {
	_Sort = 11;
	_gx = KUNAI_GRAPHPOINT_X;
	_gy = KUNAI_GRAPHPOINT_Y;
	_hit_x = KUNAI_POSITION_HITX;
	_hit_y = KUNAI_POSITION_HITY;
	_hit_w = KUNAI_COLLISION_WIDTH;
	_hit_h = KUNAI_COLLISION_HEIGHT;
	_Alpha =255;
	_drg.second = 0.0;
}

void Kunai::Process(Game& g) {
	ObjectBase::Process(g);
	_GrHandle=_GrAll["Kunai"][_Anime["Kunai"]];
	_Anime["Kunai"] = 1;
	auto frame = _Cnt - _Action_Cnt;
	if (_Repel_Flag == true) {
		_hit_x = 10000;
		_Anime["Kunai"] = 0;
		if (frame < REPEL_FRAME) {
			_Alpha -= KUNAI_ALPHACHANGE;
			if (_isFlip == false) {

				_drg.second += KUNAI_ANGLECHANGE;
				_x += KUNAI_XCHANGE;
				_y += KUNAI_YCHANGE;
			}
			if (_isFlip == true) {

				_drg.second -= KUNAI_ANGLECHANGE;
				_x -= KUNAI_XCHANGE;
				_y += KUNAI_YCHANGE;
			}
		}
		if (frame == REPEL_FRAME) {
			Delete(g);
			_Repel_Flag = false;
		}
	}
	
	if (_Repel_Flag == false) {
		//クナイとプレイヤーの下段攻撃オブジェクトの当たり判定
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーの下段攻撃オブジェクトか？
			if ((*ite)->GetObjType() == OBJECTTYPE::LOWATTACK|| (*ite)->GetObjType() == OBJECTTYPE:: IAI)
			{
				// クナイとプレイヤーの下段攻撃オブジェクトの当たり判定を行う
				if (IsHit(*(*ite)) == true) {
					_Repel_Flag = true;
					_Spd = 0;
					_Action_Cnt = _Cnt;
				}
			}
		}
	}
	if (_isFlip == false) {
		_x -= _Spd;
	}
	if (_isFlip == true) {
		_x += _Spd;
	}
}

void Kunai::Draw(Game& g) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Alpha);
	ObjectBase::Draw(g);
}

void Kunai::Delete(Game& g) {
	g.GetOS()->Del(this);
}