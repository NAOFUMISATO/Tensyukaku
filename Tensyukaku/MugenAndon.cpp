#include <DxLib.h>
#include "MugenAndon.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
#include "Game.h"
#include "PrivateCollision.h"
#include "MugenFlame.h"

using namespace MAInfo;
MugenAndon::MugenAndon(int x, int y) :_AndonDrop_Flag(false) {
	_x = x;
	_y = y;
	Init();
	_grall["Andon"].resize(MANDON_ANIMEMAX);
	ResourceServer::LoadDivGraph(MANDON_GRAPHNAME, MANDON_ANIMEMAX,MANDON_WIDTHCOUNT, MANDON_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Andon"].data());
}

MugenAndon::~MugenAndon() {
};

void MugenAndon::Init() {
	_sort = 8;
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_alpha = 255;
	_drg.second = 0.0;
	_Flame_y = _y;
}

void MugenAndon::Process(Game& g) {
	ObjectBase::Process(g);
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Andon"][_anime["Andon"]];
	if (_AndonDrop_Flag == true) {
		if (frame == MANDON_FIREFRAME1) {
			auto lf1 = new MugenFlame(_x - MANDON_FIREWIDTH * 1, _Flame_y);
			g.GetOS()->Add(lf1);
			auto rf1 = new MugenFlame( _x + MANDON_FIREWIDTH * 1, _Flame_y);
			g.GetOS()->Add(rf1);
		}
		if (frame == MANDON_FIREFRAME2) {
			auto lf2 = new MugenFlame(_x - MANDON_FIREWIDTH * 2, _Flame_y);
			g.GetOS()->Add(lf2);
			auto rf2 = new MugenFlame(_x + MANDON_FIREWIDTH * 2, _Flame_y);
			g.GetOS()->Add(rf2);
		}
		if (frame == MANDON_FIREFRAME3) {
			auto lf3 = new MugenFlame(_x - MANDON_FIREWIDTH * 3, _Flame_y);
			g.GetOS()->Add(lf3);
			auto rf3 = new MugenFlame(_x + MANDON_FIREWIDTH * 3, _Flame_y);
			g.GetOS()->Add(rf3);
		}
		if (_PlayerFlip_Flag == false) {
			if (frame >= 0 && MANDON_DROPFRAME >= frame) {
				if (_drg.second > -MANDON_DROPANGLEMAX) {
					_drg.second -= MANDON_DROPANGLE;
				}
				_x -= MANDON_DROPMOVEX;
				_y += MANDON_DROPMOVEY;
			}
		}
		if (_PlayerFlip_Flag == true) {
			if (frame >= 0 && MANDON_DROPFRAME >= frame) {
				if (_drg.second < MANDON_DROPANGLEMAX) {
					_drg.second += MANDON_DROPANGLE;
				}
				_x += MANDON_DROPMOVEX;
				_y += MANDON_DROPMOVEY;
			}
		}
		if (frame > MANDON_DROPFRAME && MANDON_ALLFRAME > frame) {
			_alpha -= MANDON_FADEOUTSPEED;
		}
		if (frame == MANDON_ALLFRAME) {
			Delete(g);
			_AndonDrop_Flag = false;
		}
	}
	if (_AndonDrop_Flag == false) {
		//行燈とプレイヤーのキックオブジェクトの当たり判定
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーのキックオブジェクトか？
			if ((*ite)->GetObjType() == OBJECTTYPE::KICK)
			{
				// 行燈とプレイヤーのキックオブジェクトの当たり判定を行う
				if (IsHit(*(*ite)) == true)
				{
					(*ite)->Delete(g);		// (*ite) はキックオブジェクト
					_action_cnt = _cnt;
					_AndonDrop_Flag = true;
					//プレイヤーの向きを参照
					for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
					{
						// iteはプレイヤか？
						if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
						{
							_PlayerFlip_Flag = (*ite)->GetFlip();
						}
					}
				}
			}
		}
	}
}

void MugenAndon::Draw(Game& g) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
	ObjectBase::Draw(g);
}

void MugenAndon::Delete(Game& g) {
	g.GetOS()->Del(this);
}
