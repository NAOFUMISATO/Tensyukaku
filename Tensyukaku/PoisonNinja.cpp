#include <DxLib.h>
#include "PoisonNinja.h"
#include "Poison.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
#include "Game.h"
#include "PrivateCollision.h"

using namespace PNInfo;
PoisonNinja::PoisonNinja(int x, int y, bool flip):
_Keep_Flag(true)
{
	_x = x;
	_y = y;
	_isFlip = flip;
	Init();
	_GrAll["Appear"].resize(APPEAR_ANIMEMAX);
	ResourceServer::LoadDivGraph(APPEAR_GRAPHNAME, APPEAR_ANIMEMAX, APPEAR_WIDTHCOUNT, APPEAR_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Appear"].data());
	_GrAll["Patrol"].resize(PATROL_ANIMEMAX);
	ResourceServer::LoadDivGraph(PATROL_GRAPHNAME, PATROL_ANIMEMAX, PATROL_WIDTHCOUNT, PATROL_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Patrol"].data());
	_GrAll["Poising"].resize(POISING_ANIMEMAX);
	ResourceServer::LoadDivGraph(POISING_GRAPHNAME, POISING_ANIMEMAX, POISING_WIDTHCOUNT, POISING_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Poising"].data());
}

PoisonNinja::~PoisonNinja() {
}

void PoisonNinja::Init() {
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_Alpha = 0;
	_State = ENEMYSTATE::APPEAR;
}

void PoisonNinja::Process(Game& g) {
	ObjectBase::Process(g);
	//��Ԗ��̏���
	switch (_State) {
	case ENEMYSTATE::APPEAR:
		Appear(g);
		break;
	case ENEMYSTATE::PATROL:
		Patrol(g);
		break;
	case ENEMYSTATE::POISING:
		Poising(g);
		break;
	}
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�̓v���C���[���H
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			//�v���C���[��Y���W�������Ȃ����
			auto py=(*ite)->GetY();
			if (py == _y) {
				_Alpha -= FADEOUT_SPEED;
				if (_Alpha == DELETE_ALPHA) {
					Delete(g);
				}
			}
		}
	}
}

void PoisonNinja::Draw(Game& g) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Alpha);
	ObjectBase::Draw(g);
}
void PoisonNinja::Delete(Game& g) {
	g.GetOS()->Del(this);
}

//�o����Ԏ��̏���
void PoisonNinja::Appear(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Appear"][_Anime["Appear"]];
	_Anime["Appear"] = (_Cnt / ANIMESPEED_APPEAR) % APPEAR_ANIMEMAX;
	if (frame < APPEAR_ALLFRAME) {
		_Alpha += FADEIN_SPEED;
	}
	if (frame == APPEAR_ALLFRAME) {
		_Alpha = 255;
		_Action_Cnt=_Cnt;
		_State = ENEMYSTATE::PATROL;
	}
}

//�����Ԏ��̏���
void PoisonNinja::Patrol(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Patrol"][_Anime["Patrol"]];
	_Anime["Patrol"] = (_Cnt / ANIMESPEED_PATROL) % PATROL_ANIMEMAX;
	if (frame == PATROL_TURNFRAME) {
		_isFlip = true;
	}
	if (frame == PATROL_TURNFRAME * 2) {
		_isFlip = false;
		_Action_Cnt = _Cnt;
	}
	if (_isFlip == false) {
		//�ŉt�E�҂̍��G�͈͔���I�u�W�F�N�g�̐���
		PrivateCollision spc(_x + _hit_x - PATROL_WIDTH, _y , PATROL_WIDTH, PATROL_HEIGHT);
		//���G�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// ���G�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(spc) == true)
				{
					_State = ENEMYSTATE::POISING;
					_Action_Cnt = _Cnt;
				}
			}
		}
	}
	if (_isFlip == true) {
		//�ŉt�E�҂̍��G�͈͔���I�u�W�F�N�g�̐���
		PrivateCollision spc(_x - _hit_x, _y, PATROL_WIDTH, PATROL_HEIGHT);
		//���G�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// ���G�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(spc) == true)
				{
					_State = ENEMYSTATE::POISING;
					_Action_Cnt = _Cnt;
				}
			}
		}
	}
}

//�ŉt���炵��Ԃ̏���
void PoisonNinja::Poising(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Poising"][_Anime["Poising"]];
	if (frame < POISING_ANIMEFRAME) {
		_Anime["Poising"] = ((frame) / ANIMESPEED_POISING) % POISING_ANIMEMAX;
	}
	if (frame == POISING_ANIMEFRAME) {
		if (_isFlip == false) {
			auto pr = new PoisonReserve(_x - POISON_SPAWN_X, _y + POISON_SPAWN_Y);
			g.GetOS()->Add(pr);
		}
		if (_isFlip == true) {
			auto pr = new PoisonReserve(_x + POISON_SPAWN_X, _y + POISON_SPAWN_Y);
			g.GetOS()->Add(pr);
		}
	}
	if (_isFlip == false) {
		PrivateCollision pacc(_x + _hit_x - POISINGCANCEL_WIDTH, _y, POISINGCANCEL_WIDTH, POISINGCANCEL_HEIGHT);
		if (frame == POISING_ALLFRAME) {
			//�ŉt���炵���~�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// ite�̓v���C���[���H
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// �U�����~�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
					if ((*ite)->IsHit(pacc) == false)
					{
						_State = ENEMYSTATE::PATROL;
						_Action_Cnt = _Cnt;
						_Anime["Poising"] = 0;
					}
				}
			}
		}
	}
	if (_isFlip == true) {
		PrivateCollision pacc(_x - _hit_x, _y - _hit_h, POISINGCANCEL_WIDTH, POISINGCANCEL_HEIGHT);
		if (frame == POISING_ALLFRAME) {
			//�ŉt���炵���~�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// ite�̓v���C���[���H
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// �ŉt���炵���~�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
					if ((*ite)->IsHit(pacc) == false)
					{
						_State = ENEMYSTATE::PATROL;
						_Action_Cnt = _Cnt;
						_Anime["Poising"] = 0;
					}
				}
			}
		}
	}
	if (frame == POISING_ALLFRAME) {
		_Action_Cnt = _Cnt;
	}
}