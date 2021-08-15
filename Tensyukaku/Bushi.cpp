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
	_Patrol_GrHandle(-1),
	_Patrol_AnimeNo(0),
	_Coming_GrHandle(-1),
	_Coming_AnimeNo(0),
	_Attack_GrHandle(-1),
	_Attack_AnimeNo(0),
	_Damage_GrHandle(-1),
	_Damage_AnimeNo(0),
	_Dead_GrHandle(-1),
	_Dead_AnimeNo(0),
	_Walk_SEHandle(-1),
	_Attack_SEHandle(-1)
{
	Init();
	LoadActionGraph();
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
	// カメラから見た座標に変更（ワールド座標→ビュー座標）
	auto GC = g.GetChip();
	auto x = _x + _gx - GC->GetscrX();
	auto y = _y + _gy - GC->GetscrY();
	//武士の状態によるアニメーション遷移
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
		DrawRotaGraph(x, y, GraphScale, GraphAngle, _Coming_GrHandle, true, _isFlip);
		break;
		//攻撃状態
	case ENEMYSTATE::ATTACK:
		_Attack_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Attack) % Attack_AnimeMax;
		_Attack_GrHandle = _Attack_GrAll[_Attack_AnimeNo];
		DrawRotaGraph(x, y, GraphScale, GraphAngle, _Attack_GrHandle, true, _isFlip);
		break;
		//被ダメ状態
	case ENEMYSTATE::DAMAGE:
		_Damage_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Damage) % Damage_AnimeMax;
		_Damage_GrHandle = _Damage_GrAll[_Damage_AnimeNo];
		DrawRotaGraph(x, y, GraphScale, GraphAngle, _Damage_GrHandle, true, _isFlip);
		break;
		//死亡状態
	case ENEMYSTATE::DEAD:
		_Dead_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Dead) % Dead_AnimeMax;
		_Dead_GrHandle = _Dead_GrAll[_Dead_AnimeNo];
		DrawRotaGraph(x, y, GraphScale, GraphAngle, _Dead_GrHandle, true, _isFlip);
		break;
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// 半透明描画指定
	DrawBox(x + _hit_x, y + _hit_y, x + _hit_x + _hit_w, y + _hit_y + _hit_h, GetColor(255, 0, 0), FALSE);	// 半透明の赤で当たり判定描画
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// 不透明描画指定
	std::stringstream ss;
	ss << "BushiLife=" << _Life << "\n";
	ss << "BushiActionCnt=" << _Action_Cnt << "\n";

	DrawString(10, 100, ss.str().c_str(), GetColor(255, 50, 255));
}
void Bushi::Delete(Game& g) {
		g.GetOS()->Del(this);
}
//武士の画像読み込み関数
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
