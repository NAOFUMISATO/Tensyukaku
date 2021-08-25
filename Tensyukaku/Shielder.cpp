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

using namespace SInfo;
Shielder::Shielder() :
	_Patrol_AnimeNo(0),
	_Coming_AnimeNo(0),
	_Attack_AnimeNo(0),
	_GuardBreak_AnimeNo(0),
	_Dead_AnimeNo(0),
	_Walk_SEHandle(-1),
	_Attack_SEHandle(-1),
	_Shield_Flag(true),
	_Shield_Cnt(-60)
{
	Init();
	LoadActionGraph();
	LoadActionSE();
};

Shielder::~Shielder() {

};

void Shielder::Init() {
	_w = GRAPH_WIDTH;
	_h = GRAPH_HEIGHT;
	_x = POSITION_X;
	_y = POSITION_Y;
	_gx = GRAPHPOINT_X;
	_gy =GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_State = ENEMYSTATE::PATROL;
	_Life = LIFE_MAX;
	_Spd = SPEED;
	_isFlip = false;
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
//盾の描画関数
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

//盾兵の画像読み込み関数
void Shielder::LoadActionGraph() {
	_Patrol_GrAll.resize(PATROL_ANIMEMAX);
	ResourceServer::LoadDivGraph(PATROL_GARAPHNAME, PATROL_ANIMEMAX, PATROL_WIDTHCOUNT, PATROL_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _Patrol_GrAll.data());
	_Coming_GrAll.resize(COMING_ANIMEMAX);
	ResourceServer::LoadDivGraph(COMING_GRAPHNAME, COMING_ANIMEMAX, COMING_WIDTHCOUNT, COMING_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _Coming_GrAll.data());
	_Attack_GrAll.resize(ATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(ATTACK_GRAPHNAME, ATTACK_ANIMEMAX, ATTACK_WIDTHCOUNT, ATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _Attack_GrAll.data());
	_GuardBreak_GrAll.resize(GUARDBREAK_ANIMEMAX);
	ResourceServer::LoadDivGraph(GUARDBREAK_GRAPHNAME, GUARDBREAK_ANIMEMAX, GUARDBREAK_WIDTHCOUNT, GUARDBREAK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GuardBreak_GrAll.data());
	_Dead_GrAll.resize(DEAD_ANIMEMAX);
	ResourceServer::LoadDivGraph(DEAD_GRAPHNAME, DEAD_ANIMEMAX, DEAD_WIDTHCOUNT, DEAD_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _Dead_GrAll.data());
}

//盾兵のSE読み込み関数
void Shielder::LoadActionSE() {
}

//盾兵のアニメーション関数
void Shielder::AnimeUpdate(Game& g) {
	_Patrol_AnimeNo = (_Cnt / ANIMESPEED_PATROL) % PATROL_ANIMEMAX;
	_Coming_AnimeNo = (_Cnt / ANIMESPEED_COMING) % COMING_ANIMEMAX;
	_Attack_AnimeNo = ((_Cnt - _Action_Cnt) / ANIMESPEED_ATTACK) % ATTACK_ANIMEMAX;
	_GuardBreak_AnimeNo = ((_Cnt - _Action_Cnt) / ANIMESPEED_GUARDBREAK) % GUARDBREAK_ANIMEMAX;
	_Dead_AnimeNo = ((_Cnt - _Action_Cnt) / ANIMESPEED_DEAD) % DEAD_ANIMEMAX;
}

//デバッグ用関数
void Shielder::DebugDraw(Game& g) {
	ShielderPatrolCollision spc;
	ShielderComingCollision scc;
	switch (_State) {
	case ENEMYSTATE::PATROL:
		if (_isFlip == false) {
			spc.SetPosition(_x + _hit_x - spc.GetHitW(), _y - _hit_h);
			spc.Draw(g);
		}
		if (_isFlip == true) {
			spc.SetPosition(_x - _hit_x, _y - _hit_h);
			spc.Draw(g);
		}
		break;
	case ENEMYSTATE::COMING:
		if (_isFlip == false) {
			scc.SetPosition(_x + _hit_x - scc.GetHitW(), _y - _hit_h);
			scc.Draw(g);
		}
		if (_isFlip == true) {
			scc.SetPosition(_x - _hit_x, _y - _hit_h);
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
