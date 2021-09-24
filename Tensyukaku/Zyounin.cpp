#include <DxLib.h>
#include <vector>
#include <sstream>
#include "EnemyBase.h"
#include "Zyounin.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
#include "NinjaMotionCollision.h"
#include "PrivateCollision.h"

/*
	��E
*/

using namespace ZInfo;
Zyounin::Zyounin(int x, int y, bool flip, int kunai_stock)
{
	_x = x;
	_y = y;
	_isFlip = flip;
	_Kunai_Stock = kunai_stock;
	Init();
	LoadActionGraph();
	LoadActionSE();
};

Zyounin::~Zyounin() {
};

void Zyounin::Init() {
	_Sort = 6;
	_GrHandle = -1;
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_State = ENEMYSTATE::APPEAR;
	_Life = LIFE_MAX;
	_Spd = SPEED;
	_Alpha = 0;
}
void Zyounin::Process(Game& g) {
	EnemyBase::Process(g);
	switch (_State) {
	case ENEMYSTATE::APPEAR:
		Appear(g);
		break;
	case ENEMYSTATE::PATROL:
		Patrol(g);
		break;
	case ENEMYSTATE::COMING:
		Coming(g);
		break;
	case ENEMYSTATE::ATTACK:
		Attack(g);
		break;
	case ENEMYSTATE::THROW:
		Throw(g);
		break;
	case ENEMYSTATE::DEAD:
		Dead(g);
		break;
	}
	HitJudge(g);
}

void Zyounin::Draw(Game& g) {
#ifdef _DEBUG
	DebugDraw(g);
#endif
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Alpha);
	EnemyBase::Draw(g);
}

void Zyounin::Delete(Game& g) {
	g.GetOS()->Del(this);
}

//��_������&�����o���̏���
void Zyounin::HitJudge(Game& g) {
	//�G�ƃv���C���[�̃A�N�V�����̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		OBJECTTYPE objType = (*ite)->GetObjType();
		switch (objType) {
		case ObjectBase::OBJECTTYPE::LOWATTACK:
			// �G�ƃv���C���[�̉��i�U���I�u�W�F�N�g�̓����蔻����s��
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) �͍U���I�u�W�F�N�g
				_Life--;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
				//�����Q�[�W�̑���
				for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
				{
					// ite�̓v���C���[���H
					if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
					{
						auto ig = (*ite)->GetGauge();
						if (ig < PLAYER_IAI_MAX) {
							(*ite)->SetGauge(ig += 1);
						}
					}
				}
			}
			break;
		case ObjectBase::OBJECTTYPE::IAI:
		case ObjectBase::OBJECTTYPE::FLAME:
		case ObjectBase::OBJECTTYPE::MUGENFLAME:
			// �G�ƃv���C���[�̋����I�u�W�F�N�g�̓����蔻����s��
			if (IsHit(*(*ite)) == true)
			{
				_Life--;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
			break;
		case ObjectBase::OBJECTTYPE::PLAYER:
			// �v���C���[�Ƃ��̓G�̓����蔻����s��
			if (IsHit(*(*ite)) == true) {
				_x = _Before_x;
			}
			break;
		default:
			break;
		}
	}
}
//�E�҂̉摜�ǂݍ��݊֐�
void Zyounin::LoadActionGraph() {
	_GrAll["Appear"].resize(APPEAR_ANIMEMAX);
	ResourceServer::LoadDivGraph(APPEAR_GRAPHNAME, APPEAR_ANIMEMAX, APPEAR_WIDTHCOUNT, APPEAR_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Appear"].data());
	_GrAll["Patrol"].resize(PATROL_ANIMEMAX);
	ResourceServer::LoadDivGraph(PATROL_GRAPHNAME, PATROL_ANIMEMAX, PATROL_WIDTHCOUNT, PATROL_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Patrol"].data());
	_GrAll["Coming"].resize(COMING_ANIMEMAX);
	ResourceServer::LoadDivGraph(COMING_GRAPHNAME, COMING_ANIMEMAX, COMING_WIDTHCOUNT, COMING_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Coming"].data());
	_GrAll["Attack"].resize(ATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(ATTACK_GRAPHNAME, ATTACK_ANIMEMAX, ATTACK_WIDTHCOUNT, ATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Attack"].data());
	_GrAll["Throw"].resize(THROW_ANIMEMAX);
	ResourceServer::LoadDivGraph(THROW_GRAPHNAME, THROW_ANIMEMAX, THROW_WIDTHCOUNT, THROW_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Throw"].data());
	_GrAll["Dead"].resize(DEAD_ANIMEMAX);
	ResourceServer::LoadDivGraph(DEAD_GRAPHNAME, DEAD_ANIMEMAX, DEAD_WIDTHCOUNT, DEAD_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Dead"].data());
}

//SE�ǂݍ��݊֐�
void Zyounin::LoadActionSE() {
	_Se["Attack"] = ResourceServer::LoadSoundMem("bgm/NinjaAttack.wav");
}

//�f�o�b�O�p�֐�
void Zyounin::DebugDraw(Game& g) {
	switch (_State) {
	case ENEMYSTATE::PATROL:
		if (_isFlip == false) {
			PrivateCollision pc(_x + _hit_x - PATROL_WIDTH, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
			PrivateCollision bpc(_x - _hit_x, _y - _hit_h, PATROL_BACKWIDTH, PATROL_HEIGHT);
			pc.SetColor(std::make_tuple(0, 255, 0));
			bpc.SetColor(std::make_tuple(0, 128, 128));
			pc.Draw(g);
			bpc.Draw(g);
		}
		if (_isFlip == true) {
			PrivateCollision pc(_x - _hit_x, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
			PrivateCollision bpc(_x + _hit_x - PATROL_BACKWIDTH, _y - _hit_h, PATROL_BACKWIDTH, PATROL_HEIGHT);
			pc.SetColor(std::make_tuple(0, 255, 0));
			bpc.SetColor(std::make_tuple(0, 128, 128));
			pc.Draw(g);
			bpc.Draw(g);
		}
		break;
	case ENEMYSTATE::COMING:
		if (_isFlip == false) {
			PrivateCollision cc(_x + _hit_x - COMING_WIDTH, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
			cc.SetColor(std::make_tuple(255, 255, 0));
			cc.Draw(g);
		}
		if (_isFlip == true) {
			PrivateCollision cc(_x - _hit_x, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
			cc.SetColor(std::make_tuple(255, 255, 0));
			cc.Draw(g);
		}
		break;
	}
}
