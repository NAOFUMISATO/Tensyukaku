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
#include "PrivateCollision.h"

/*
	盾兵
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
	_State = ENEMYSTATE::APPEAR;
	_Life = LIFE_MAX;
	_Spd = SPEED;
	_Alpha = 0;
}
void Shielder::Process(Game& g) {
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
	case ENEMYSTATE::GUARDATTACK:
		GuardAttack(g);
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
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Alpha);
	EnemyBase::Draw(g);
	ShieldDraw(g);
}
void Shielder::Delete(Game& g) {
	g.GetOS()->Del(this);
}
//盾の描画関数
void Shielder::ShieldDraw(Game& g) {
	if (_Shield_Flag == true) {
		Shield Sh;
		auto x = _x + SHIELD_DIFFPOINTX;
		auto y = _y + SHIELD_DIFFPOINTY;
		auto gr = Sh.GetHandle();
		auto a = _Alpha;
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

//盾兵の画像読み込み関数
void Shielder::LoadActionGraph() {
	_GrAll["Appear"].resize(APPEAR_ANIMEMAX);
	ResourceServer::LoadDivGraph(APPEAR_GRAPHNAME, APPEAR_ANIMEMAX, APPEAR_WIDTHCOUNT, APPEAR_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Appear"].data());
	_GrAll["Patrol"].resize(PATROL_ANIMEMAX);
	ResourceServer::LoadDivGraph(PATROL_GARAPHNAME, PATROL_ANIMEMAX, PATROL_WIDTHCOUNT, PATROL_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Patrol"].data());
	_GrAll["Coming"].resize(COMING_ANIMEMAX);
	ResourceServer::LoadDivGraph(COMING_GRAPHNAME, COMING_ANIMEMAX, COMING_WIDTHCOUNT, COMING_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Coming"].data());
	_GrAll["Attack"].resize(ATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(ATTACK_GRAPHNAME, ATTACK_ANIMEMAX, ATTACK_WIDTHCOUNT, ATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Attack"].data());
	_GrAll["GuardAttack"].resize(GUARDATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(GUARDATTACK_GRAPHNAME, GUARDATTACK_ANIMEMAX, GUARDATTACK_WIDTHCOUNT, GUARDATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["GuardAttack"].data());
	_GrAll["GuardBreak"].resize(GUARDBREAK_ANIMEMAX);
	ResourceServer::LoadDivGraph(GUARDBREAK_GRAPHNAME, GUARDBREAK_ANIMEMAX, GUARDBREAK_WIDTHCOUNT, GUARDBREAK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["GuardBreak"].data());
	_GrAll["Dead"].resize(DEAD_ANIMEMAX);
	ResourceServer::LoadDivGraph(DEAD_GRAPHNAME, DEAD_ANIMEMAX, DEAD_WIDTHCOUNT, DEAD_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Dead"].data());
}

//盾兵のSE読み込み関数
void Shielder::LoadActionSE() {
}

//デバッグ用関数
void Shielder::DebugDraw(Game& g) {
	switch (_State) {
	case ENEMYSTATE::PATROL:
		if (_isFlip == false) {
			PrivateCollision spc(_x + _hit_x -PATROL_WIDTH, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
			spc.SetColor(std::make_tuple(0, 255, 0));
			spc.Draw(g);
		}
		if (_isFlip == true) {
			PrivateCollision spc(_x - _hit_x, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
			spc.SetColor(std::make_tuple(0, 255, 0));
			spc.Draw(g);
		}
		break;
	case ENEMYSTATE::COMING:
		if (_isFlip == false) {
			PrivateCollision scc(_x + _hit_x - COMING_WIDTH, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
			scc.SetColor(std::make_tuple(2555, 255, 0));
			scc.Draw(g);
		}
		if (_isFlip == true) {
			PrivateCollision scc(_x - _hit_x, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
			scc.SetColor(std::make_tuple(255, 255, 0));
			scc.Draw(g);
		}
		break;
	}
	std::stringstream ss;
	ss << "盾兵HP=" << _Life << "\n";
	ss << "盾兵Spd=" << _Spd << "\n";
	ss << "盾生存フラグ=" << _Shield_Flag << "\n";
	DrawString(600, 10, ss.str().c_str(), GetColor(255, 50, 255));
}
