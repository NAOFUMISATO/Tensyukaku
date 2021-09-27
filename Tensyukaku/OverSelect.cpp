#include <DxLib.h>
#include "OverSelect.h"
#include "Game.h"
#include "ModeTitle.h"
#include "ModeGame.h"
#include "ResourceServer.h"
#include "OverlayBlack.h"

bool OverSelect::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;
	_y = 900;
	_pal = 0;
	_GraphNo = 0;
	_Type = SELECTTYPE::NOSELECT;
	_trans_flag = true;
	_grall["PSelect"].resize(3);
	ResourceServer::LoadDivGraph("res/Mode/OverSelect.png", 3, 3, 1, 1690, 340, _grall["PSelect"].data());
	return true;
}

bool OverSelect::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool OverSelect::Process(Game& g) {
	base::Process(g);
	_grhandle = _grall["PSelect"][_anime["PSelect"]];
	_anime["PSelect"] = _GraphNo;
	auto frame = _cnt - _mode_cnt;
	if (frame < 60) {
		_pal += 4;
	}
	if (frame == 60) {
		_pal = 255;
	}
	
	switch (_Type) {
	case SELECTTYPE::NOSELECT:
		_GraphNo = 0;
		if (frame > 60) {
			if (g.GetTrg() & PAD_INPUT_LEFT) {
				_Type = SELECTTYPE::RETRYSELECT;
			}
			if (g.GetTrg() & PAD_INPUT_RIGHT) {
				_Type = SELECTTYPE::GOTITLESELECT;
			}
		}
		break;
	case SELECTTYPE::RETRYSELECT:
		_GraphNo = 1;
		if (g.GetTrg() & PAD_INPUT_1) {
			_mode_cnt = _cnt;
			auto ob = new OverlayBlack();
			ob->SetFade(60, 90, 150, 5);
			g.GetMS()->Add(ob, 5, "OverlayBlack");
		}
		if (frame == 60) {
			g.GetMS()->Del(this);
			g.GetMS()->Del(g.GetMS()->Get("Gameover"));
			g.GetMS()->Del(g.GetMS()->Get("OverLogo"));
			g.GetMS()->Del(g.GetMS()->Get("Game"));
			auto mg = new ModeGame();
			g.GetMS()->Add(mg, 0, "Game");
		}
		if (g.GetTrg() & PAD_INPUT_RIGHT) {
			_Type = SELECTTYPE::GOTITLESELECT;
		}
		break;
	case SELECTTYPE::GOTITLESELECT:
		_GraphNo = 2;
		if (g.GetTrg() & PAD_INPUT_1) {
			_mode_cnt = _cnt;
			auto ob =new OverlayBlack();
			ob->SetFade(60, 70, 70, 4);
			g.GetMS()->Add(ob, 5, "OverlayBlack");
		}
		if (frame==60 ) {
			g.GetMS()->Del(this);
			g.GetMS()->Del(g.GetMS()->Get("OverLogo"));
			g.GetMS()->Del(g.GetMS()->Get("Gameover"));
			g.GetMS()->Del(g.GetMS()->Get("Game"));
			auto mt = new ModeTitle();
			g.GetMS()->Add(mt, 0, "Title");
		}
		if (g.GetTrg() & PAD_INPUT_LEFT) {
			_Type = SELECTTYPE::RETRYSELECT;
		}
		break;
	}
	return true;
}

bool OverSelect::Draw(Game& g) {
	base::Draw(g);
	return true;
}

