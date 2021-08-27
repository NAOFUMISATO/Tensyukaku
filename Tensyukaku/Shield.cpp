#include <DxLib.h>
#include "ResourceServer.h"
#include "Shielder.h"
#include "Shield.h"
#include "Game.h"
#include "ObjectBase.h"
#include <utility>

using namespace SInfo;
Shield::Shield() {
	Init();
	_GrHandle = ResourceServer::LoadGraph("res/Shielder/Shield.png");
}
Shield::~Shield() {
}

void Shield::Init() {
	_gx = SHIELD_GRAPH_POINTX;
	_gy = SHIELD_GRAPH_POINTY;
	_Drg.second = SHIELD_ANGLE;
	_Dalpha = 0;
}

void Shield::Process(Game& g) {
	ObjectBase::Process(g);
}

void Shield::Draw(Game& g) {
	ObjectBase::Draw(g);
}

