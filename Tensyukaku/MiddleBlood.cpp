#include  <DxLib.h>
#include "Game.h"
#include "ResourceServer.h"
#include "MiddleBlood.h"

MiddleBlood::MiddleBlood(int x,int y,bool flip,int bloodtype) {
	_x = x;
	_y = y;
	_isflip = flip;
	_blood_type = bloodtype;
	_grall["MiddleBlood1"].resize(1);
	ResourceServer::LoadDivGraph("res/Efect/MiddleBlood1.png",1,1,1,420,420,_grall["MiddleBlood1"].data());
	_grall["MiddleBlood2"].resize(1);
	ResourceServer::LoadDivGraph("res/Efect/MiddleBlood2.png", 1, 1, 1, 420, 420, _grall["MiddleBlood2"].data());
	_grall["MiddleBlood3"].resize(1);
	ResourceServer::LoadDivGraph("res/Efect/MiddleBlood3.png", 1, 1, 1, 420, 420, _grall["MiddleBlood3"].data());
	_grall["MiddleBlood4"].resize(1);
	ResourceServer::LoadDivGraph("res/Efect/MiddleBlood4.png", 1, 1, 1, 420, 420, _grall["MiddleBlood4"].data());
	Init();
}
MiddleBlood::~MiddleBlood() {
};

void MiddleBlood::Init() {
	_alpha = 255;
	_action_cnt = _cnt;
}

void MiddleBlood::Process(Game& g) {
	EfectBase::Process(g);
	auto frame = _cnt - _action_cnt;
	switch (_blood_type) {
	case 0:
		_grhandle = _grall["MiddleBlood1"][0];
		break;
	case 1:
		_grhandle = _grall["MiddleBlood2"][0];
		break;
	case 2:
		_grhandle = _grall["MiddleBlood3"][0];
		break;
	case 3:
		_grhandle = _grall["MiddleBlood4"][0];
		break;
	}
	if (frame >= 30&&_alpha>0) {
		_alpha -= 10;
	}
	if (_alpha == 0) {
		Delete(g);
	}
}

void MiddleBlood::Draw(Game& g) {
	EfectBase::Draw(g);
}

void MiddleBlood::Delete(Game& g) {
	g.GetOS()->Del(this);
}