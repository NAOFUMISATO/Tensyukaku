#include <DxLib.h>
#include <vector>
#include <sstream>
#include "EnemyBase.h"
#include "Ninja.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ObjectBase.h"

using namespace Tsk;
using namespace NInfo;
Ninja::Ninja() :
	_Patrol_GrHandle(-1),
	_Patrol_AnimeNo(0),
	_Coming_GrHandle(-1),
	_Coming_AnimeNo(0),
	_Attack_GrHandle(-1),
	_Attack_AnimeNo(0),
	_Dead_GrHandle(-1),
	_Dead_AnimeNo(0),
	_Walk_SEHandle(-1),
	_Attack_SEHandle(-1)
{
	Init();
	LoadActionGraph();
};

Ninja::~Ninja() {};

void Ninja::Init() {
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
	auto x = _x + _gx;
	auto y = _y + _gy;
	//ïêémÇÃèÛë‘Ç…ÇÊÇÈÉAÉjÉÅÅ[ÉVÉáÉìëJà⁄
	switch (_State) {
		//èÑâÒèÛë‘
	case ENEMYSTATE::PATROL:
		_Patrol_AnimeNo = (_Cnt / AnimeSpeed_Patrol) % Patrol_AnimeMax;
		_Patrol_GrHandle = _Patrol_GrAll[_Patrol_AnimeNo];
		DrawRotaGraph(x, y, GraphScale, GraphAngle, _Patrol_GrHandle, true, _isFlip);
		break;
		//í«ê’èÛë‘
	case ENEMYSTATE::COMING:
		_Coming_AnimeNo = (_Cnt / AnimeSpeed_Move) % Coming_AnimeMax;
		_Coming_GrHandle = _Coming_GrAll[_Coming_AnimeNo];
		DrawRotaGraph(x, y, GraphScale, GraphAngle, _Coming_GrHandle, true, _isFlip);
		break;
		//çUåÇèÛë‘
	case ENEMYSTATE::ATTACK:
		_Attack_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Attack) % Attack_AnimeMax;
		_Attack_GrHandle = _Attack_GrAll[_Attack_AnimeNo];
		DrawRotaGraph(x, y, GraphScale, GraphAngle, _Attack_GrHandle, true, _isFlip);
		break;
		//éÄñSèÛë‘
	case ENEMYSTATE::DEAD:
		_Dead_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Dead) % Dead_AnimeMax;
		_Dead_GrHandle = _Dead_GrAll[_Dead_AnimeNo];
		DrawRotaGraph(x, y, GraphScale, GraphAngle, _Dead_GrHandle, true, _isFlip);
		break;
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// îºìßñæï`âÊéwíË
	DrawBox(x + _hit_x, y + _hit_y, x + _hit_x + _hit_w, y + _hit_y + _hit_h, GetColor(255, 0, 0), FALSE);	// îºìßñæÇÃê‘Ç≈ìñÇΩÇËîªíËï`âÊ
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// ïsìßñæï`âÊéwíË
	std::stringstream ss;
	ss << "NinjaLife="<<_Life<< "\n";
	ss << "NinjaActionCnt=" << _Action_Cnt << "\n";

	DrawString( 10, 200, ss.str().c_str(), GetColor(255, 50, 255));
}
void Ninja::Delete(Game& g) {
		g.GetOS()->Del(this);
	}
//ïêémÇÃâÊëúì«Ç›çûÇ›ä÷êî
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