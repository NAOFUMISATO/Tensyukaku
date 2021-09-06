#include <DxLib.h>
#include "ResourceServer.h"
#include "IaiGauge.h"
#include "Game.h"

IaiGauge::IaiGauge(){
	Init();
	_GrAll["IaiGauge"].resize(7);
	ResourceServer::LoadDivGraph("res/UI/IaiGauge.png",7,7,1,700,80,_GrAll["IaiGauge"].data());
}
IaiGauge::~IaiGauge() {
}

void IaiGauge::Init() {
	_x = 960;
	_y = 1040;
}

void IaiGauge::Process(Game& g) {
	ObjectBase::Process(g);
	_GrHandle = _GrAll["IaiGauge"][_Anime["IaiGauge"]];
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER) {
			auto ig = (*ite)->GetGauge();
			_Anime["IaiGauge"] = ig;
		}
	}
}

void IaiGauge::Draw(Game& g) {
	DrawRotaGraph(_x, _y, 1.0, 0.0, _GrHandle, true, false);
}