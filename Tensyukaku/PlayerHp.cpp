#include <DxLib.h>
#include "ResourceServer.h"
#include "PlayerHp.h"
#include "Game.h"


PlayerHp::PlayerHp(int hp){
	_Life = hp;
	Init();
	_GrHandle = ResourceServer::LoadGraph("res/UI/HP.png");
}
PlayerHp::~PlayerHp() {
}

void PlayerHp::Init() {
	_x = 220+(80*_Life);
	_y = 1040;
}
void PlayerHp::Process(Game& g) {
	ObjectBase::Process(g);
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER) {
			auto hp=(*ite)->GetHp();
			if (hp <= _Life) {
				Delete(g);
			}
		}
	}
}
void PlayerHp::Draw(Game& g) {
	DrawRotaGraph(_x, _y, 1.0, 0.0, _GrHandle,true,false);
}
void PlayerHp::Delete(Game& g) {
	g.GetOS()->Del(this);
}