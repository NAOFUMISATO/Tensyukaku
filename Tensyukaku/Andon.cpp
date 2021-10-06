#include <DxLib.h>
#include "Andon.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
#include "Game.h"
#include "PrivateCollision.h"
#include "Flame.h"

using namespace AInfo;
Andon::Andon(int x, int y):_AndonDrop_Flag(false) {
	_x = x;
	_y = y;
	Init();
	_grall["Andon"].resize(ANDON_ANIMEMAX);
	ResourceServer::LoadDivGraph(ANDON_GRAPHNAME, ANDON_ANIMEMAX, ANDON_WIDTHCOUNT, ANDON_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Andon"].data());
	_se["Andon"] = ResourceServer::LoadSoundMem("se/Gimik/Andon.wav");
	_vpal["Andon"] = 255;
}

Andon::~Andon() {
};

void Andon::Init() {
	_sort = 8;
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h= COLLISION_HEIGHT;
	_alpha = 255;
	_drg.second = 0.0;
	_Flame_y = _y;
}

void Andon::Process(Game& g) {
	ObjectBase::Process(g);
	ChangeVolumeSoundMem(_vpal["Andon"], _vpal["Andon"]);
	auto frame = _cnt - _action_cnt;
	_grhandle=_grall["Andon"][_anime["Andon"]];
	if (_AndonDrop_Flag == true) {
		if (frame == ANDON_FIREFRAME1) {
			PlaySoundMem(_se["Andon"], DX_PLAYTYPE_BACK, true);
			auto lf1 = new Flame(_x - ANDON_FIREWIDTH * 1, _Flame_y);
			g.GetOS()->Add(lf1);
			auto rf1 = new Flame(_x + ANDON_FIREWIDTH * 1, _Flame_y);
			g.GetOS()->Add(rf1);
		}
		if (frame == ANDON_FIREFRAME2) {
			auto lf2 = new Flame(_x - ANDON_FIREWIDTH * 2, _Flame_y);
			g.GetOS()->Add(lf2);
			auto rf2 = new Flame(_x + ANDON_FIREWIDTH * 2, _Flame_y);
			g.GetOS()->Add(rf2);
		}
		if (frame == ANDON_FIREFRAME3) {
			auto lf3 = new Flame(_x - ANDON_FIREWIDTH * 3, _Flame_y);
			g.GetOS()->Add(lf3);
			auto rf3 = new Flame(_x + ANDON_FIREWIDTH * 3, _Flame_y);
			g.GetOS()->Add(rf3);
		}
		if (_PlayerFlip_Flag == false) {
			if (frame >= 0 && ANDON_DROPFRAME >= frame) {
				if (_drg.second > -ANDON_DROPANGLEMAX) {
					_drg.second -= ANDON_DROPANGLE;
				}
				_x -= ANDON_DROPMOVEX;
				_y += ANDON_DROPMOVEY;
			}
		}
		if (_PlayerFlip_Flag == true) {
			if (frame >= 0 && ANDON_DROPFRAME >= frame) {
				if (_drg.second < ANDON_DROPANGLEMAX) {
					_drg.second += ANDON_DROPANGLE;
				}
				_x += ANDON_DROPMOVEX;
				_y += ANDON_DROPMOVEY;
			}
		}
		if (frame > ANDON_DROPFRAME && ANDON_ALLFRAME > frame) {
			_alpha -= ANDON_FADEOUTSPEED;
		}
		if (frame == ANDON_ALLFRAME) {
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

void Andon::Draw(Game& g) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
	ObjectBase::Draw(g);
}

void Andon::Delete(Game& g) {
	g.GetOS()->Del(this);
}
