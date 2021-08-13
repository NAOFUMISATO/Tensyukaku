#include "Game.h"
#include <DxLib.h>
#include "ResourceServer.h"
#include "EnemyBase.h"

EnemyBase::EnemyBase()
{
	Init();
}

EnemyBase::~EnemyBase()
{
}
void EnemyBase::Init()
{
}
void EnemyBase::Process(Game& g) {
	ObjectBase::Process(g);
	
}