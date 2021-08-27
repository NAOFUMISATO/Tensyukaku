#include <DxLib.h>
#include <vector>
#include <sstream>
#include "EnemyBase.h"
#include "Shielder.h"
#include "ShielderMotionCollision.h"
#include "Shield.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
#include "player.h"

/*
	����
*/
using namespace SInfo;
Shielder::Shielder(int x, int y, bool flip) :
	_Shield_Flag(true),
	_Shield_Cnt(-60)
{
	_x = x;
	_y = y;
	_isFlip = flip;
	Init();
	LoadActionGraph();
	LoadActionSE();
};

Shielder::~Shielder() {

};

void Shielder::Init() {
	_w = GRAPH_WIDTH;
	_h = GRAPH_HEIGHT;
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_State = ENEMYSTATE::PATROL;
	_Life = LIFE_MAX;
	_Spd = SPEED;
}
void Shielder::Process(Game& g) {
	EnemyBase::Process(g);
	AnimeUpdate(g);
	switch (_State) {
	case ENEMYSTATE::PATROL:
		Patrol(g);
		break;
	case ENEMYSTATE::COMING:
		Coming(g);
		break;
	case ENEMYSTATE::ATTACK:
		Attack(g);
		break;
	case ENEMYSTATE::GUARDBREAK:
		GuardBreak(g);
		break;
	case ENEMYSTATE::DEAD:
		Dead(g);
		break;
	}
}
void Shielder::Draw(Game& g) {	
#ifdef _DEBUG
	DebugDraw(g);
#endif 
	EnemyBase::Draw(g);
	ShieldDraw(g);
}
void Shielder::Delete(Game& g) {
	g.GetOS()->Del(this);
}
//���̕`��֐�
void Shielder::ShieldDraw(Game& g) {
	if (_Shield_Flag == true) {
		Shield Sh;
		auto x = _x + SHIELD_DIFFPOINTX;
		auto y = _y + SHIELD_DIFFPOINTY;
		auto gr = Sh.GetHandle();
		auto a = SHIELD_ALPHA;
		auto frame = _Cnt - _Shield_Cnt;
		if (_isFlip == false) {
			auto angle = Sh.GetAngle();
			if (frame >= 0 && GUARDBREAK_ALLFRAME >= frame) {
				a -= frame * SHIELD_ALPHACHANGE;
				angle += frame * SHIELD_ANGLECHANGE;
				x += frame * SHIELD_XCHANGE;
				y += frame * SHIELD_YCHANGE;
			}
			Sh.SetAngle(angle);
		}
		if (_isFlip == true) {
			auto angle = -Sh.GetAngle();
			if (frame >= 0 && GUARDBREAK_ALLFRAME >= frame) {
				a -= frame * SHIELD_ALPHACHANGE;
				angle -= frame * SHIELD_ANGLECHANGE;
				x -= frame * SHIELD_XCHANGE;
				y += frame * SHIELD_YCHANGE;
			}
			Sh.SetAngle(angle);
		}
		if (frame == GUARDBREAK_ALLFRAME) {
			_Shield_Flag = false;
		}
		gr = SetDrawBlendMode(DX_BLENDMODE_ALPHA, a);
		Sh.SetPosition(x, y);
		Sh.Draw(g);
		gr = SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
	}
}

//�����̉摜�ǂݍ��݊֐�
void Shielder::LoadActionGraph() {
	_GrAll["Patrol"].resize(PATROL_ANIMEMAX);
	ResourceServer::LoadDivGraph(PATROL_GARAPHNAME, PATROL_ANIMEMAX, PATROL_WIDTHCOUNT, PATROL_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Patrol"].data());
	_GrAll["Coming"].resize(COMING_ANIMEMAX);
	ResourceServer::LoadDivGraph(COMING_GRAPHNAME, COMING_ANIMEMAX, COMING_WIDTHCOUNT, COMING_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Coming"].data());
	_GrAll["Attack"].resize(ATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(ATTACK_GRAPHNAME, ATTACK_ANIMEMAX, ATTACK_WIDTHCOUNT, ATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Attack"].data());
	_GrAll["GuardBreak"].resize(GUARDBREAK_ANIMEMAX);
	ResourceServer::LoadDivGraph(GUARDBREAK_GRAPHNAME, GUARDBREAK_ANIMEMAX, GUARDBREAK_WIDTHCOUNT, GUARDBREAK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["GuardBreak"].data());
	_GrAll["Dead"].resize(DEAD_ANIMEMAX);
	ResourceServer::LoadDivGraph(DEAD_GRAPHNAME, DEAD_ANIMEMAX, DEAD_WIDTHCOUNT, DEAD_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Dead"].data());
}

//������SE�ǂݍ��݊֐�
void Shielder::LoadActionSE() {
}

//�����̃A�j���[�V�����֐�
void Shielder::AnimeUpdate(Game& g) {
	_Anime["Patrol"] = (_Cnt / ANIMESPEED_PATROL) % PATROL_ANIMEMAX;
	_Anime["Coming"] = (_Cnt / ANIMESPEED_COMING) % COMING_ANIMEMAX;
	_Anime["Attack"] = ((_Cnt - _Action_Cnt) / ANIMESPEED_ATTACK) % ATTACK_ANIMEMAX;
	_Anime["GuardBreak"] = ((_Cnt - _Action_Cnt) / ANIMESPEED_GUARDBREAK) % GUARDBREAK_ANIMEMAX;
	_Anime["Dead"] = ((_Cnt - _Action_Cnt) / ANIMESPEED_DEAD) % DEAD_ANIMEMAX;
}

//�f�o�b�O�p�֐�
void Shielder::DebugDraw(Game& g) {
	switch (_State) {
	case ENEMYSTATE::PATROL:
		if (_isFlip == false) {
			ShielderPatrolCollision spc(_x + _hit_x -PATROL_WIDTH, _y - _hit_h);
			spc.Draw(g);
		}
		if (_isFlip == true) {
			ShielderPatrolCollision spc(_x - _hit_x, _y - _hit_h);
			spc.Draw(g);
		}
		break;
	case ENEMYSTATE::COMING:
		if (_isFlip == false) {
			ShielderComingCollision scc(_x + _hit_x - COMING_WIDTH, _y - _hit_h);
			scc.Draw(g);
		}
		if (_isFlip == true) {
			ShielderComingCollision scc(_x - _hit_x, _y - _hit_h);
			scc.Draw(g);
		}
		break;
	}
	std::stringstream ss;
	ss << "����HP=" << _Life << "\n";
	ss << "����Spd=" << _Spd << "\n";
	ss << "�������t���O=" << _Shield_Flag << "\n";
	DrawString(600, 10, ss.str().c_str(), GetColor(255, 50, 255));
}
