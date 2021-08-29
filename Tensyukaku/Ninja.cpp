#include <DxLib.h>
#include <vector>
#include <sstream>
#include "EnemyBase.h"
#include "Ninja.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
#include "NinjaMotionCollision.h"
#include "PrivateCollision.h"

/*
	îEé“
*/
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
//îEé“ÇÃâÊëúì«Ç›çûÇ›ä÷êî
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

//îEé“ÇÃSEì«Ç›çûÇ›ä÷êî
void Ninja::LoadActionSE() {
	_Se["Walk"]=ResourceServer::LoadSoundMem(WALK_SE);
	_Se["Attack"] = ResourceServer::LoadSoundMem(ATTACK_SE);
}

//ÉfÉoÉbÉOópä÷êî
void Ninja::DebugDraw(Game& g) {
	switch (_State) {
	case ENEMYSTATE::PATROL:
		if (_isFlip == false) {
			PrivateCollision npc(_x + _hit_x - PATROL_WIDTH, _y - _hit_h,PATROL_WIDTH,PATROL_HEIGHT);
			npc.SetColor(std::make_tuple(0, 255, 0));
			npc.Draw(g);
		}
		if (_isFlip == true) {
			PrivateCollision npc(_x - _hit_x, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
			npc.SetColor(std::make_tuple(0, 255, 0));
			npc.Draw(g);
		}
		break;
	case ENEMYSTATE::COMING:
		if (_isFlip == false) {
			PrivateCollision ncc(_x + _hit_x - COMING_WIDTH, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
			ncc.SetColor(std::make_tuple(255, 255, 0));
			ncc.Draw(g);
		}
		if (_isFlip == true) {
			PrivateCollision ncc(_x - _hit_x, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
			ncc.SetColor(std::make_tuple(255, 255, 0));
			ncc.Draw(g);
		}
		break;
	}
	std::stringstream ss;
	ss << "îEé“HP=" << _Life << "\n";
	ss << "îEé“Spd=" << _Spd << "\n";
	DrawString(400, 10, ss.str().c_str(), GetColor(255, 50, 255));
}
