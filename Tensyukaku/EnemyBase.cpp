/*
		“G‚ÌŠî’ê
*/
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
/*----------‰Šú‰»----------*/
void EnemyBase::Init()
{
}
/*----------XV----------*/
void EnemyBase::Process(Game& g) {
	ObjectBase::Process(g);
}
/*----------•`‰æ----------*/
void EnemyBase::Draw(Game& g) {
	ObjectBase::Draw(g);
}