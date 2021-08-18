#include <DxLib.h>
#include <vector>
#include <sstream>
#include "EnemyBase.h"
#include "Ninja.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ObjectBase.h"


using namespace NInfo;
Ninja::Ninja() :
	_Patrol_AnimeNo(0),
	_Coming_AnimeNo(0),
	_Attack_AnimeNo(0),
	_Dead_AnimeNo(0),
	_Walk_SEHandle(-1),
	_Attack_SEHandle(-1)
{
	Init();
	LoadActionGraph();
	LoadActionSE();
};

Ninja::~Ninja() {
};

void Ninja::Init() {
	_GrHandle = -1;
	_w = GraphWidth;
	_h = GraphHeight;
	_x = PositionX;
	_y = PositionY;
	_gx = GraphPointX;
	_gy = GraphPointY;
	_hit_x = PositionHitX;
	_hit_y = PositionHitY;
	_hit_w = CollisionWidth;
	_hit_h = CollisionHeight;
	_State= ENEMYSTATE::PATROL;
	_Life = LifeMax;
	_Spd = Speed;
	_isFlip = false;
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
	EnemyBase::Draw(g);
#ifdef _DEBUG
	std::stringstream ss;
	ss << "NinjaLife="<<_Life<< "\n";
	ss << "NinjaActionCnt=" << _Action_Cnt << "\n";
	DrawString( 600, 10, ss.str().c_str(), GetColor(255, 50, 255));
#endif
}
void Ninja::Delete(Game& g) {
		g.GetOS()->Del(this);
	}
//îEé“ÇÃâÊëúì«Ç›çûÇ›ä÷êî
void Ninja::LoadActionGraph() {
	_Patrol_GrAll.resize(Patrol_AnimeMax);
	ResourceServer::LoadDivGraph(Patrol_GraphName, Patrol_AnimeMax, Patrol_WidthCount, Patrol_HeightCount, GraphWidth, GraphHeight, _Patrol_GrAll.data());
	_Coming_GrAll.resize(Coming_AnimeMax);
	ResourceServer::LoadDivGraph(Coming_GraphName, Coming_AnimeMax, Coming_WidthCount, Coming_HeightCount, GraphWidth, GraphHeight, _Coming_GrAll.data());
	_Attack_GrAll.resize(Attack_AnimeMax);
	ResourceServer::LoadDivGraph(Attack_GraphName, Attack_AnimeMax, Attack_WidthCount, Attack_HeightCount, GraphWidth, GraphHeight, _Attack_GrAll.data());
	_Dead_GrAll.resize(Dead_AnimeMax);
	ResourceServer::LoadDivGraph(Dead_GraphName, Dead_AnimeMax, Dead_WidthCount, Dead_HeightCount, GraphWidth, GraphHeight, _Dead_GrAll.data());
}

//îEé“ÇÃSEì«Ç›çûÇ›ä÷êî
void Ninja::LoadActionSE() {
}

//îEé“ÇÃÉAÉjÉÅÅ[ÉVÉáÉìä÷êî
void Ninja::AnimeUpdate(Game& g) {
	_Patrol_AnimeNo = (_Cnt / AnimeSpeed_Patrol) % Patrol_AnimeMax;
	_Coming_AnimeNo = (_Cnt / AnimeSpeed_Move) % Coming_AnimeMax;
	_Attack_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Attack) % Attack_AnimeMax;
	_Dead_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Dead) % Dead_AnimeMax;
}

