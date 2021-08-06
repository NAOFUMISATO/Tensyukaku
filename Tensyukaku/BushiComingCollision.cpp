#include <DxLib.h>
#include "BushiComingCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Bushi.h"
namespace {
	constexpr auto Width = 200;
	constexpr auto Height = 100;
}
using namespace Tsk;
BushiComingCollision::BushiComingCollision() {
	Init();
}
BushiComingCollision::~BushiComingCollision() {
}

void BushiComingCollision::Init() {
	_w = Width;
	_h = Height;
	_hit_x = 0;
	_hit_y = 0;
	_hit_w = Width;
	_hit_h = Height;
}

void BushiComingCollision::Process(Game& g) {
	ObjectBase::Process(g);
}

