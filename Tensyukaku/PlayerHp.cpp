#include <DxLib.h>
#include "ResourceServer.h"
#include "PlayerHp.h"
#include "Game.h"


PlayerHp::PlayerHp(){
	Init();
	_GrAll["HP"].resize(3);
	ResourceServer::LoadDivGraph("res/UI/ALLHP.png", 3, 3, 1, 240, 80, _GrAll["HP"].data());
}
PlayerHp::~PlayerHp() {
}

void PlayerHp::Init() {
	_x = 300;
	_y = 1040;
}
void PlayerHp::Process(Game& g) {
	ObjectBase::Process(g);
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER) {
			_GrHandle = _GrAll["HP"][_Anime["HP"]];
			auto hp=(*ite)->GetHp();
			if (hp >= 3) {
				_Anime["HP"] = 2;
			}
			if (hp == 2) {
				_Anime["HP"] = 1;
			}
			if (hp == 1) {
				_Anime["HP"] = 0;
			}
			if (hp <= 0) {
				_GrHandle = -1;
			}
		}
	}
}
void PlayerHp::Draw(Game& g) {
	DrawRotaGraph(_x, _y, 1.0, 0.0, _GrHandle,true,false);
}
