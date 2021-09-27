#include <DxLib.h>
#include "ResourceServer.h"
#include "PlayerHp.h"
#include "Game.h"


PlayerHp::PlayerHp(int hp){
	_life = hp;
	Init();
	_grall["HP"].resize(2);
	ResourceServer::LoadDivGraph("res/UI/HP.png",2,2,1,80,80, _grall["HP"].data());
}
PlayerHp::~PlayerHp() {
}

void PlayerHp::Init() {
	_sort = 14;
	_x = 220+(80*_life);
	_y = 1040;
}
void PlayerHp::Process(Game& g) {
	ObjectBase::Process(g);
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER) {
			_grhandle = _grall["HP"][_anime["HP"]];
			auto hp=(*ite)->GetHp();
			if (hp <= _life) {
				_anime["HP"] = 1;
			}
			else { _anime["HP"] = 0; }
		}
	}
}
void PlayerHp::Draw(Game& g) {
	DrawRotaGraph(_x, _y, 1.0, 0.0, _grhandle,true,false);
}
void PlayerHp::Delete(Game& g) {
	g.GetOS()->Del(this);
}