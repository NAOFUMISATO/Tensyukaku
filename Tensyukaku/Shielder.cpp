#include <DxLib.h>
#include <vector>
#include <sstream>
#include "EnemyBase.h"
#include "Shielder.h"
#include "Shield.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ObjectBase.h"

using namespace SInfo;
using namespace ShInfo;
Shielder::Shielder() :
	_Patrol_AnimeNo(0),
	_Coming_AnimeNo(0),
	_Attack_AnimeNo(0),
	_GuardBreak_AnimeNo(0),
	_Dead_AnimeNo(0),
	_Walk_SEHandle(-1),
	_Attack_SEHandle(-1),
	_Shield_Flag(true),
	_Shield_Cnt(-61)
{
	Init();
	LoadActionGraph();
	LoadActionSE();
};

Shielder::~Shielder() {

};

void Shielder::Init() {
	_w = SInfo::GraphWidth;
	_h = SInfo::GraphHeight;
	_x = PositionX;
	_y = PositionY;
	_gx = SInfo::GraphPointX;
	_gy = SInfo::GraphPointY;
	_hit_x = SInfo::PositionHitX;
	_hit_y = SInfo::PositionHitY;
	_hit_w = SInfo::CollisionWidth;
	_hit_h = SInfo::CollisionHeight;
	_State = ENEMYSTATE::PATROL;
	_Life = LifeMax;
	_Spd = Speed;
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
void Shielder ::Draw(Game& g) {
	EnemyBase::Draw(g);
	
	ShieldDraw(g);
#ifdef _DEBUG
	std::stringstream ss;
	ss << "ShielderLife=" << _Life << "\n";
	ss << "ShielderActionCnt=" << _Action_Cnt << "\n";
	DrawString(300, 10, ss.str().c_str(), GetColor(255, 50, 255));
#endif
}
void Shielder::Delete(Game& g) {
	g.GetOS()->Del(this);
}

void Shielder::ShieldDraw(Game& g) {
	if (_Shield_Flag == true) {
		Shield Sh;
		auto x = _x + ShInfo::GraphPointX;
		auto y = _y + ShInfo::GraphPointY;
		auto gr = Sh.GetHandle();
		auto angle = Sh.GetAngle();
		auto a =Alpha;
		auto frame = _Cnt - _Shield_Cnt;
		if (_Cnt - _Shield_Cnt >= 0 && Shield_Frame >= _Cnt - _Shield_Cnt) {
			angle += frame * AnChange;
			a -= frame * AlChange;
			y += frame * XChange;
			x += frame * YChange;
			gr = SetDrawBlendMode(DX_BLENDMODE_ALPHA, a);
		}
		if (_Cnt - _Shield_Cnt == Shield_Frame) {
			_Shield_Flag = false;
		}
		Sh.SetAngle(angle);
		Sh.SetPosition(x, y);
		Sh.Draw(g);
	}
}

//盾兵の画像読み込み関数
void Shielder::LoadActionGraph() {
	_Patrol_GrAll.resize(Patrol_AnimeMax);
	ResourceServer::LoadDivGraph(Patrol_GraphName, Patrol_AnimeMax, Patrol_WidthCount, Patrol_HeightCount, SInfo::GraphWidth, SInfo::GraphHeight, _Patrol_GrAll.data());
	_Coming_GrAll.resize(Coming_AnimeMax);
	ResourceServer::LoadDivGraph(Coming_GraphName, Coming_AnimeMax, Coming_WidthCount, Coming_HeightCount, SInfo::GraphWidth, SInfo::GraphHeight, _Coming_GrAll.data());
	_Attack_GrAll.resize(Attack_AnimeMax);
	ResourceServer::LoadDivGraph(Attack_GraphName, Attack_AnimeMax, Attack_WidthCount, Attack_HeightCount, SInfo::GraphWidth, SInfo::GraphHeight, _Attack_GrAll.data());
	_GuardBreak_GrAll.resize(GuardBreak_AnimeMax);
	ResourceServer::LoadDivGraph(GuardBreak_GraphName, GuardBreak_AnimeMax, GuardBreak_WidthCount, GuardBreak_HeightCount, SInfo::GraphWidth, SInfo::GraphHeight, _GuardBreak_GrAll.data());
	_Dead_GrAll.resize(Dead_AnimeMax);
	ResourceServer::LoadDivGraph(Dead_GraphName, Dead_AnimeMax, Dead_WidthCount, Dead_HeightCount, SInfo::GraphWidth, SInfo::GraphHeight, _Dead_GrAll.data());
}

//盾兵のSE読み込み関数
void Shielder::LoadActionSE() {
}

//盾兵のアニメーション関数
void Shielder::AnimeUpdate(Game& g) {
	_Patrol_AnimeNo = (_Cnt / AnimeSpeed_Patrol) % Patrol_AnimeMax;
	_Coming_AnimeNo = (_Cnt / AnimeSpeed_Coming) % Coming_AnimeMax;
	_Attack_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Attack) % Attack_AnimeMax;
	_GuardBreak_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_GuardBreak) % GuardBreak_AnimeMax;
	_Dead_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Dead) % Dead_AnimeMax;
}