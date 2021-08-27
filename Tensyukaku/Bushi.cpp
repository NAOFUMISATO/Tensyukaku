#include <DxLib.h>
#include <vector>
#include <sstream>
#include "EnemyBase.h"
#include "Bushi.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
#include "BushiMotionCollision.h"
/*
	ïêém
*/
using namespace BInfo;
Bushi::Bushi(int x,int y,bool flip)
{
	_x = x;
	_y = y;
	_isFlip = flip;
	Init();
	LoadActionGraph();
	LoadActionSE();
};

Bushi::~Bushi() {
	
};

void Bushi::Init() {
	_w = GRAPH_WIDTH;
	_h = GRAPH_HEIGHT;
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_State=ENEMYSTATE::PATROL;
	_Life = LIFE_MAX;
	_Spd = SPEED;
}
void Bushi::Process(Game& g) {
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
	case ENEMYSTATE::DAMAGE:
		Damage(g);
		break;
	case ENEMYSTATE::DEAD:
		Dead(g);
		break;
	}
}

void Bushi::Draw(Game& g) {	
#ifdef _DEBUG
	DebugDraw(g);
#endif
	EnemyBase::Draw(g);
}

void Bushi::Delete(Game& g) {
		g.GetOS()->Del(this);
}

//ïêémÇÃâÊëúì«Ç›çûÇ›ä÷êî
void Bushi::LoadActionGraph() {
	_GrAll["Patrol"].resize(PATROL_ANIMEMAX);
	ResourceServer::LoadDivGraph(PATROL_GRAPHNAME, PATROL_ANIMEMAX, PATROL_WIDTHCOUNT, PATROL_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Patrol"].data());
	_GrAll["Coming"].resize(COMING_ANIMEMAX);
	ResourceServer::LoadDivGraph(COMING_GRAPHNAME, COMING_ANIMEMAX, COMING_WIDTHCOUNT, COMING_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Coming"].data());
	_GrAll["Attack"].resize(ATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(ATTACK_GRAPHNAME, ATTACK_ANIMEMAX, ATTACK_WIDTHCOUNT, ATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Attack"].data());
	_GrAll["Damage"].resize(DAMAGE_ANIMEMAX);
	ResourceServer::LoadDivGraph(DAMAGE_GRAPHNAME, DAMAGE_ANIMEMAX, DAMAGE_WIDTHCOUNT, DAMAGE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Damage"].data());
	_GrAll["Dead"].resize(DEAD_ANIMEMAX);
	ResourceServer::LoadDivGraph(DEAD_GRAPHNAME, DEAD_ANIMEMAX, DEAD_WIDTHCOUNT, DEAD_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Dead"].data());
}

//ïêémÇÃSEì«Ç›çûÇ›ä÷êî
void Bushi::LoadActionSE() {
}

//ïêémÇÃÉAÉjÉÅÅ[ÉVÉáÉìä÷êî
void Bushi::AnimeUpdate(Game& g) {
	_Anime["Patrol"] = (_Cnt / ANIMESPEED_PATROL) % PATROL_ANIMEMAX;
	_Anime["Coming"] = (_Cnt / ANIMESPEED_COMING) % COMING_ANIMEMAX;
	_Anime["Attack"] = ((_Cnt - _Action_Cnt) / ANIMESPEED_ATTACK) % ATTACK_ANIMEMAX;
	_Anime["Damage"] = ((_Cnt - _Action_Cnt) / ANIMESPEED_DAMAGE) % DAMAGE_ANIMEMAX;
	_Anime["Dead"] = ((_Cnt - _Action_Cnt) / ANIMESPEED_DEAD) % DEAD_ANIMEMAX;
}
//ÉfÉoÉbÉOópä÷êî
void Bushi::DebugDraw(Game& g) {
	switch (_State) {
	case ENEMYSTATE::PATROL:
		if (_isFlip == false) {
			BushiPatrolCollision bpc(_x + _hit_x - PATROL_WIDTH, _y - _hit_h);
			bpc.Draw(g);
		}
		if (_isFlip == true) {
			BushiPatrolCollision bpc(_x - _hit_x, _y - _hit_h);
			bpc.Draw(g);
		}
		break;
	case ENEMYSTATE::COMING:
		if (_isFlip == false) {
			BushiComingCollision bcc(_x + _hit_x - COMING_WIDTH, _y - _hit_h);
			bcc.Draw(g);
		}
		if (_isFlip == true) {
			BushiComingCollision bcc(_x - _hit_x, _y - _hit_h);
			bcc.Draw(g);
		}
		break;
	}
	std::stringstream ss;
	ss << "ïêémHP=" << _Life << "\n";
	ss << "ïêémSpd=" << _Spd << "\n";
	DrawString(200, 10, ss.str().c_str(), GetColor(255, 50, 255));
}