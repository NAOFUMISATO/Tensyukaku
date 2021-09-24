#include <DxLib.h>
#include "ResourceServer.h"
#include "Game.h"
#include "ModeTutorial.h"
#include "ModeGame.h"
bool ModeTutorial::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;
	_y = 250;
	_Pal = 255;
	_Mode_Cnt = _Cnt;
	_Trans_Flag = true;
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
	auto frame = _Cnt - _Mode_Cnt;
	switch (_TutorialNum) {
	case 1:
		_GrHandle= _GrAll["Num1"][0];
		break;
	case 2:
		_GrHandle = _GrAll["Num2"][0];
		break;
	case 3:
		_GrHandle = _GrAll["Num3"][0];
		break;
	case 4:
		_GrHandle = _GrAll["Num4"][0];
		break;
	case 5:
		_GrHandle = _GrAll["Num5"][0];
		break;
	default:
		break;
	}
	if (_Return_Flag == true) {
		g.GetMS()->Del(this);
		auto mg = (ModeGame*)g.GetMS()->Get("Game");
		mg->SetStopObjProcess(false);
		mg->SetStopObjFlag(false);
	}
	if (frame >= 10&& g.GetTrg() & PAD_INPUT_2) {
		_Return_Flag = true;
	}
	return true;
}
bool ModeTutorial::Draw(Game& g) {
	base::Draw(g);
	return true;
}

void  ModeTutorial::LoadTextGraph() {
	_GrAll["Num1"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial1.png", 1, 1, 1, 880, 480, _GrAll["Num1"].data());
	_GrAll["Num2"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial2.png", 1, 1, 1, 880, 480, _GrAll["Num2"].data());
	_GrAll["Num3"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial3.png", 1, 1, 1, 880, 480, _GrAll["Num3"].data());
	_GrAll["Num4"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial4.png", 1, 1, 1, 880, 480, _GrAll["Num4"].data());
	_GrAll["Num5"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial5.png", 1, 1, 1, 880, 480, _GrAll["Num5"].data());
}
