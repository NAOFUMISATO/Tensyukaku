#include <DxLib.h>
#include "ResourceServer.h"
#include "Game.h"
#include "ModeTutorial.h"
#include "ModeGame.h"
bool ModeTutorial::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;
	_y = 250;
	_pal = 255;
	_mode_cnt = _cnt;
	_trans_flag = true;
	_Return_Flag = false;
	LoadTextGraph();
	return true;
}

bool ModeTutorial::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool ModeTutorial::Process(Game& g) {
	base::Process(g);
	auto frame = _cnt - _mode_cnt;
	switch (_TutorialNum) {
	case 1:
		_grhandle= _grall["Num1"][0];
		break;
	case 2:
		_grhandle = _grall["Num2"][0];
		break;
	case 3:
		_grhandle = _grall["Num3"][0];
		break;
	case 4:
		_grhandle = _grall["Num4"][0];
		break;
	case 5:
		_grhandle = _grall["Num5"][0];
		break;
	default:
		break;
	}
	return true;
}
bool ModeTutorial::Draw(Game& g) {
	base::Draw(g);
	return true;
}

void  ModeTutorial::LoadTextGraph() {
	_grall["Num1"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial1.png", 1, 1, 1, 880, 480, _grall["Num1"].data());
	_grall["Num2"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial2.png", 1, 1, 1, 880, 480, _grall["Num2"].data());
	_grall["Num3"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial3.png", 1, 1, 1, 880, 480, _grall["Num3"].data());
	_grall["Num4"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial4.png", 1, 1, 1, 880, 480, _grall["Num4"].data());
	_grall["Num5"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial5.png", 1, 1, 1, 880, 480, _grall["Num5"].data());
}
