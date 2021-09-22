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
	_GrAll["Andon"].resize(MANDON_ANIMEMAX);
	ResourceServer::LoadDivGraph(MANDON_GRAPHNAME, MANDON_ANIMEMAX,MANDON_WIDTHCOUNT, MANDON_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Andon"].data());
}

MugenAndon::~MugenAndon() {
};

void MugenAndon::Init() {
	_Sort = 8;
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_Alpha = 255;
	_drg.second = 0.0;
	_Flame_y = _y;
}

void MugenAndon::Process(Game& g) {
	ObjectBase::Process(g);
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Andon"][_Anime["Andon"]];
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
			_Alpha -= MANDON_FADEOUTSPEED;
		}
		if (frame == MANDON_ALLFRAME) {
			Delete(g);
			_AndonDrop_Flag = false;
		}
	}
	if (_AndonDrop_Flag == false) {
		//�s���ƃv���C���[�̃L�b�N�I�u�W�F�N�g�̓����蔻��
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[�̃L�b�N�I�u�W�F�N�g���H
			if ((*ite)->GetObjType() == OBJECTTYPE::KICK)
			{
				// �s���ƃv���C���[�̃L�b�N�I�u�W�F�N�g�̓����蔻����s��
				if (IsHit(*(*ite)) == true)
				{
					(*ite)->Delete(g);		// (*ite) �̓L�b�N�I�u�W�F�N�g
					_Action_Cnt = _Cnt;
					_AndonDrop_Flag = true;
					//�v���C���[�̌������Q��
					for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
					{
						// ite�̓v���C�����H
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
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Alpha);
	ObjectBase::Draw(g);
}

void MugenAndon::Delete(Game& g) {
	g.GetOS()->Del(this);
}