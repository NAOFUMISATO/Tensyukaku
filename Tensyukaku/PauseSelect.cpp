#include <DxLib.h>
#include "PauseSelect.h"
#include "Game.h"
#include "ModeTitle.h"
#include "ModeGame.h"
#include "ResourceServer.h"

bool PauseSelect::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;
	_y = 900;
	_GraphNo = 0;
	_Type = SELECTTYPE::NOSELECT;
	_Trans_Flag = true;
	_GrAll["PSelect"].resize(3);
	ResourceServer::LoadDivGraph("res/Mode/PauseSelect.png",3,3,1,1900,340,_GrAll["PSelect"].data());
	return true;
}

bool PauseSelect::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool PauseSelect::Process(Game& g) {
	base::Process(g);
	_GrHandle = _GrAll["PSelect"][_Anime["PSelect"]];
	_Anime["PSelect"] = _GraphNo;
	auto frame = _Cnt - _Mode_Cnt;
	switch (_Type) {
	case SELECTTYPE::NOSELECT:
		_GraphNo = 0;
		if (g.GetTrg() & PAD_INPUT_LEFT) {
			_Type = SELECTTYPE::RETURNSELECT;
		}
		if (g.GetTrg() & PAD_INPUT_RIGHT) {
			_Type = SELECTTYPE::GOTITLESELECT;
		}
		break;
	case SELECTTYPE::RETURNSELECT:
		_GraphNo = 1;
		if (g.GetTrg() & PAD_INPUT_1) {
			_Mode_Cnt = _Cnt;
		}
		if (frame == 10) {
			g.GetMS()->Del(this);
			g.GetMS()->Del(g.GetMS()->Get("Pause"));
			g.GetMS()->Del(g.GetMS()->Get("PController"));
			auto mg = (ModeGame*)g.GetMS()->Get("Game");
			mg->SetStopObjProcess(false);
			mg->SetPauseFlag(false);
		}
		if (g.GetTrg() & PAD_INPUT_RIGHT) {
			_Type = SELECTTYPE::GOTITLESELECT;
		}
		break;
	case SELECTTYPE::GOTITLESELECT:
		_GraphNo = 2;
		if (g.GetTrg() & PAD_INPUT_1) {
			_Mode_Cnt = _Cnt;
		}
		if (frame == 5) {
			g.GetMS()->Del(this);
			g.GetMS()->Del(g.GetMS()->Get("PController"));
			g.GetMS()->Del(g.GetMS()->Get("Pause"));
			auto mg = (ModeGame*)g.GetMS()->Get("Game");
			mg->SetStopObjProcess(false);
			mg->SetPauseFlag(false);
			g.GetMS()->Del(g.GetMS()->Get("Game"));
			auto mt = new ModeTitle();
			g.GetMS()->Add(mt, 0, "Title");	
		}
		if(g.GetTrg() & PAD_INPUT_LEFT) {
			_Type = SELECTTYPE::RETURNSELECT;
		}
		break;
	}
	return true;
}

bool PauseSelect::Draw(Game& g) {
	base::Draw(g);
	return true;
}

