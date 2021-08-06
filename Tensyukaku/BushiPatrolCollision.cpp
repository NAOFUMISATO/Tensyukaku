#include <DxLib.h>
#include "BushiPatrolCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Bushi.h"
namespace {
	constexpr auto Width = 500;
	constexpr auto Height = 100;
}
using namespace Tsk;
BushiPatrolCollision::BushiPatrolCollision() {
	Init();
}
BushiPatrolCollision::~BushiPatrolCollision() {
}

void BushiPatrolCollision::Init() {
	_w = Width;
	_h = Height;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = Width;
	_hit_h = Height;
}

void BushiPatrolCollision::Process(Game& g) {
	ObjectBase::Process(g);
}

