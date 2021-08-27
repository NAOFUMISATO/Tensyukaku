#include <DxLib.h>
#include <vector>
#include <sstream>
#include "EnemyBase.h"
#include "Ninja.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
#include "NinjaMotionCollision.h"


using namespace NInfo;
Ninja::Ninja(int x, int y, bool flip)
{
	_x = x;
	_y = y;
	_isFlip = flip;
	Init();
	LoadActionGraph();
	LoadActionSE();
};

Ninja::~Ninja() {
};

void Ninja::Init() {
	_GrHandle = -1;
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_State= ENEMYSTATE::PATROL;
	_Life = LIFE_MAX;
	_Spd = SPPED;
}
void Ninja::Process(Game& g) {
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
	case ENEMYSTATE::DEAD:
		Dead(g);
		break;
	}
}
void Ninja::Draw(Game& g) {
#ifdef _DEBUG
	DebugDraw(g);
#endif
	EnemyBase::Draw(g);
}
void Ninja::Delete(Game& g) {
		g.GetOS()->Del(this);
	}
//忍者の画像読み込み関数
void Ninja::LoadActionGraph() {
	_GrAll["Patrol"].resize(PATROL_ANIMEMAX);
	ResourceServer::LoadDivGraph(PATROL_GRAPHNAME, PATROL_ANIMEMAX, PATROL_WIDTHCOUNT, PATROL_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Patrol"].data());
	_GrAll["Coming"].resize(COMING_ANIMEMAX);
	ResourceServer::LoadDivGraph(COMING_GRAPHNAME, COMING_ANIMEMAX, COMING_WIDTHCOUNT, COMING_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Coming"].data());
	_GrAll["Attack"].resize(ATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(ATTACK_GRAPHNAME, ATTACK_ANIMEMAX, ATTACK_WIDTHCOUNT, ATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Attack"].data());
	_GrAll["Dead"].resize(DEAD_ANIMEMAX);
	ResourceServer::LoadDivGraph(DEAD_GRAPHNAME, DEAD_ANIMEMAX, DEAD_WIDTHCOUNT, DEAD_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Dead"].data());
}

//忍者のSE読み込み関数
void Ninja::LoadActionSE() {
	_Se["Walk"]=ResourceServer::LoadSoundMem(WALK_SE);
	_Se["Attack"] = ResourceServer::LoadSoundMem(ATTACK_SE);
}
//忍者のアニメーション関数
void Ninja::AnimeUpdate(Game& g) {
	_Anime["Patrol"] = (_Cnt / ANIMESPEED_PATROL) % PATROL_ANIMEMAX;
	_Anime["Coming"] = (_Cnt / ANIMESPEED_COMING) % COMING_ANIMEMAX;
	_Anime["Atatck"] = ((_Cnt - _Action_Cnt) / ANIMESPEED_ATTACK) % ATTACK_ANIMEMAX;
	_Anime["Dead"] = ((_Cnt - _Action_Cnt) / ANIMESPEED_DEAD) % DEAD_ANIMEMAX;
}
//デバッグ用関数
void Ninja::DebugDraw(Game& g) {
	switch (_State) {
	case ENEMYSTATE::PATROL:
		if (_isFlip == false) {
			NinjaPatrolCollision npc(_x + _hit_x - PATROL_WIDTH, _y - _hit_h);
			npc.Draw(g);
		}
		if (_isFlip == true) {
			NinjaPatrolCollision npc(_x - _hit_x, _y - _hit_h);
			npc.Draw(g);
		}
		break;
	case ENEMYSTATE::COMING:
		if (_isFlip == false) {
			NinjaComingCollision ncc(_x + _hit_x - COMING_WIDTH, _y - _hit_h);
			ncc.Draw(g);
		}
		if (_isFlip == true) {
			NinjaComingCollision ncc(_x - _hit_x, _y - _hit_h);
			ncc.Draw(g);
		}
		break;
	}
	std::stringstream ss;
	ss << "忍者HP=" << _Life << "\n";
	ss << "忍者Spd=" << _Spd << "\n";
	DrawString(400, 10, ss.str().c_str(), GetColor(255, 50, 255));
}
