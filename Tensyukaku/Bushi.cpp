#include <DxLib.h>
#include "EnemyBase.h"
#include "Bushi.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
using namespace Tsk;
using namespace BInfo;
Bushi::Bushi() :
	_Action_Cnt(0),
	_Idle_GrHandle(-1),
	_Idle_AnimeNo(0),
	_Move_GrHandle(-1),
	_Move_AnimeNo(0),
	_Attack_GrHandle(-1),
	_Attack_AnimeNo(0),
	_Walk_SEHandle(-1),
	_Attack_SEHandle(-1)
{
	Init();
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
	case(ENEMYSTATE::PATROL):

		break;
	case(ENEMYSTATE::COMING):
		break;
	case(ENEMYSTATE::ATTACK):
		break;
	case(ENEMYSTATE::DAMAGE):
		break;
	case(ENEMYSTATE::DEAD):
		break;
	}
}
void Bushi::Draw(Game& g) {

}
