#include <DxLib.h>
#include "ResourceServer.h"
#include "Ninja.h"
#include "Kunai.h"
#include "Game.h"
#include "ObjectBase.h"

using namespace NInfo;
Kunai::Kunai(int x,int y, bool flip):_Repel_Flag(false) {
	_x = x;
	_y = y;
	_isFlip = flip;
	Init();
	_GrHandle = ResourceServer::LoadGraph(KUNAI_GRAPHNAME);
}

Kunai::~Kunai() {
};

void Kunai::Init() {
	_gx = KUNAI_GRAPHPOINT_X;
	_gy = KUNAI_GRAPHPOINT_Y;
	_hit_x = KUNAI_POSITION_HITX;
	_hit_y = KUNAI_POSITION_HITY;
	_hit_w = KUNAI_COLLISION_WIDTH;
	_hit_h = KUNAI_COLLISION_HEIGHT;
	_Spd = KUNAI_SPEED;
	_Alpha =255;
	_drg.second = 0.0;
}

void Kunai::Process(Game& g) {
	ObjectBase::Process(g);
	auto frame = _Cnt - _Action_Cnt;
	if (_Repel_Flag == true) {
		_hit_x = 10000;
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
			if ((*ite)->GetObjType() == OBJECTTYPE::LOWATTACK)
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