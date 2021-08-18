#include <DxLib.h>
#include <vector>
#include <sstream>
#include "EnemyBase.h"
#include "Bushi.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ObjectBase.h"

using namespace BInfo;
Bushi::Bushi() :
	_Patrol_AnimeNo(0),
	_Coming_AnimeNo(0),
	_Attack_AnimeNo(0),
	_Damage_AnimeNo(0),
	_Dead_AnimeNo(0),
	_Walk_SEHandle(-1),
	_Attack_SEHandle(-1)
{
	Init();
	LoadActionGraph();
	LoadActionSE();
};

Bushi::~Bushi() {
	
};

void Bushi::Init() {
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
	_State=Bushi::ENEMYSTATE::PATROL;
	_Life = LifeMax;
	_Spd = Speed;
	_isFlip = false;
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
	EnemyBase::Draw(g);
#ifdef _DEBUG
	std::stringstream ss;
	ss << "BushiLife=" << _Life << "\n";
	ss << "BushiActionCnt=" << _Action_Cnt << "\n";
	DrawString(300, 10, ss.str().c_str(), GetColor(255, 50, 255));
#endif
}
void Bushi::Delete(Game& g) {
		g.GetOS()->Del(this);
}

//ïêémÇÃâÊëúì«Ç›çûÇ›ä÷êî
void Bushi::LoadActionGraph() {
	_Patrol_GrAll.resize(Patrol_AnimeMax);
	ResourceServer::LoadDivGraph(Patrol_GraphName, Patrol_AnimeMax, Patrol_WidthCount, Patrol_HeightCount, GraphWidth, GraphHeight, _Patrol_GrAll.data());
	_Coming_GrAll.resize(Coming_AnimeMax);
	ResourceServer::LoadDivGraph(Coming_GraphName, Coming_AnimeMax, Coming_WidthCount, Coming_HeightCount, GraphWidth, GraphHeight, _Coming_GrAll.data());
	_Attack_GrAll.resize(Attack_AnimeMax);
	ResourceServer::LoadDivGraph(Attack_GraphName, Attack_AnimeMax, Attack_WidthCount, Attack_HeightCount, GraphWidth, GraphHeight, _Attack_GrAll.data());
	_Damage_GrAll.resize(Damage_AnimeMax);
	ResourceServer::LoadDivGraph(Damage_GraphName, Damage_AnimeMax, Damage_WidthCount, Damage_HeightCount, GraphWidth, GraphHeight, _Damage_GrAll.data());
	_Dead_GrAll.resize(Dead_AnimeMax);
	ResourceServer::LoadDivGraph(Dead_GraphName, Dead_AnimeMax, Dead_WidthCount, Dead_HeightCount, GraphWidth, GraphHeight, _Dead_GrAll.data());
}

//ïêémÇÃSEì«Ç›çûÇ›ä÷êî
void Bushi::LoadActionSE() {
}

//ïêémÇÃÉAÉjÉÅÅ[ÉVÉáÉìä÷êî
void Bushi::AnimeUpdate(Game& g) {
	_Patrol_AnimeNo = (_Cnt / AnimeSpeed_Patrol) % Patrol_AnimeMax;
	_Coming_AnimeNo = (_Cnt / AnimeSpeed_Move) % Coming_AnimeMax;
	_Attack_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Attack) % Attack_AnimeMax;
	_Damage_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Damage) % Damage_AnimeMax;
	_Dead_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Dead) % Dead_AnimeMax;
}