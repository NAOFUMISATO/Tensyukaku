#include <DxLib.h>
#include "ResourceServer.h"
#include "Player.h"
#include "PlayerHp.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ModeGame.h"


PlayerHp::PlayerHp():
	_Hp1_GrHandle(-1),
	_Hp2_GrHandle(-1),
	_Hp3_GrHandle(-1)
{
	_Hp1_GrHandle=ResourceServer::LoadGraph("res/UI/HP1.png");
	_Hp2_GrHandle=ResourceServer::LoadGraph("res/UI/HP2.png");
	_Hp3_GrHandle=ResourceServer::LoadGraph("res/UI/HP3.png");
	Init();
}
PlayerHp::~PlayerHp() {
}

void PlayerHp::Init() {
	_x = 0;
	_y = 0;
}
void PlayerHp::Process(Game& g) {
	ObjectBase::Process(g);
}
