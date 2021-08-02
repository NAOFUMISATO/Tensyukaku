#include <DxLib.h>
#include <vector>
#include "EnemyBase.h"
#include "Bushi.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
using namespace Tsk;
using namespace BInfo;
Bushi::Bushi() :
	_Action_Cnt(0),
	_Patrol_GrHandle(-1),
	_Patrol_AnimeNo(0),
	_Coming_GrHandle(-1),
	_Coming_AnimeNo(0),
	_Attack_GrHandle(-1),
	_Attack_AnimeNo(0),
	_Walk_SEHandle(-1),
	_Attack_SEHandle(-1)
{
	Init();
	LoadActionGraph();
};

Bushi::~Bushi() {};

void Bushi::Init() {
	_w = GraphWidth;
	_h = GraphHeight;
	_x = PositionX;
	_y = PositionY;
	_gx = GraphPointX;
	_gy = GraphPointY;
	_Spd = Speed;
	_hit_x = PositionHitX;
	_hit_y = PositionHitY;
	_hit_w = CollisionWidth;
	_hit_h = CollisionHeight;
	ENEMYSTATE::PATROL;
	_isFlip = true;
}
void Bushi::Process(Game& g) {
	EnemyBase::Process(g);
	switch (_State) {
	case ENEMYSTATE::PATROL:
		break;
	case ENEMYSTATE::COMING:
		break;
	case ENEMYSTATE::ATTACK:
		break;
	case ENEMYSTATE::DAMAGE:
		break;
	case ENEMYSTATE::DEAD:
		break;
	}
}
void Bushi::Draw(Game& g) {
	auto x = _x + _gx;
	auto y = _y + _gy;

	//プレイヤーの状態によるアニメーション遷移
	switch (_State) {
		//巡回状態
	case ENEMYSTATE::PATROL:
		_Patrol_AnimeNo = (_Cnt / AnimeSpeed_Patrol) % Patrol_AnimeMax;
		_Patrol_GrHandle = _Patrol_GrAll[_Patrol_AnimeNo];
		DrawRotaGraph(x, y, GraphScale, GraphAngle, _Patrol_GrHandle, true, _isFlip);
		break;
		//追跡状態
	case ENEMYSTATE::COMING:
		_Coming_AnimeNo = (_Cnt / AnimeSpeed_Move) % Coming_AnimeMax;
		_Coming_GrHandle = _Coming_GrAll[_Coming_AnimeNo];
		if (g.GetKey() & PAD_INPUT_LEFT) {
			DrawRotaGraph(x, y, GraphScale, GraphAngle, _Coming_GrHandle, true, _isFlip);
		}
		else if (g.GetKey() & PAD_INPUT_RIGHT) {
			DrawRotaGraph(x, y, GraphScale, GraphAngle, _Coming_GrHandle, true, _isFlip);
		}
		break;
		//攻撃状態
	case ENEMYSTATE::ATTACK:
		_Attack_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Attack) % Attack_AnimeMax;
		_Attack_GrHandle = _Attack_GrAll[_Attack_AnimeNo];
		DrawRotaGraph(x, y, GraphScale, GraphAngle, _Attack_GrHandle, true, _isFlip);
		break;
	}
}
//プレイヤーの画像読み込み関数
void Bushi::LoadActionGraph() {
	_Patrol_GrAll.resize(Patrol_AnimeMax);
	ResourceServer::LoadDivGraph(Patrol_GraphName, Patrol_AnimeMax, Patrol_WidthCount, Patrol_HeightCount, GraphWidth, GraphHeight, _Patrol_GrAll.data());
	_Coming_GrAll.resize(Coming_AnimeMax);
	ResourceServer::LoadDivGraph(Coming_GraphName, Coming_AnimeMax, Coming_WidthCount, Coming_HeightCount, GraphWidth, GraphHeight, _Coming_GrAll.data());
	_Attack_GrAll.resize(Attack_AnimeMax);
	ResourceServer::LoadDivGraph(Attack_GraphName, Attack_AnimeMax, Attack_WidthCount, Attack_HeightCount, GraphWidth, GraphHeight, _Attack_GrAll.data());
}