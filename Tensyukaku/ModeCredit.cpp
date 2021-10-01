#include <DxLib.h>
#include "ModeCredit.h"
#include "Game.h"
#include "Player.h"
#include "ModeTitle.h"
#include "ResourceServer.h"
#include "OverlayBlack.h"
using namespace CrInfo;
bool ModeCredit::Initialize(Game& g) {
	_x = 2880;
	_y = 1080;
	_pal = 0;
	_mode_cnt = _cnt;
	_leftmove_flag = false;
	_rightmove_flag = false;
	_start_flag = true;
	_end_flag = false;
	_grhandle=ResourceServer::LoadGraph("res/Mode/ModeCredit.png");
	return true;
}

bool ModeCredit::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool ModeCredit::Process(Game& g) {
	base::Process(g);
	auto frame = _cnt - _mode_cnt;
	if (frame<FADE_FRAME&&_start_flag==true) {
		_pal += FADE_SPEED;
	}
	if (frame == FADE_FRAME && _start_flag == true) {
		auto gu = new Guide();
		g.GetMS()->Add(gu, 3, "Guide");
		auto rr = new RedReturn();
		g.GetMS()->Add(rr, 3, "RedReturn");
		_start_flag = false;
	}
	if (frame == FADE_FRAME && _end_flag == true) {
		g.GetMS()->Del(this);
		auto mt = new ModeTitle();
		mt->SetTitlebg();
		g.GetMS()->Add(mt, 0, "Title");
	}
	if (g.GetTrg() & PAD_INPUT_LEFT&&_x==960) {
		_leftmove_flag = true;
	}
	if (g.GetTrg() & PAD_INPUT_RIGHT && _x == 2880) {
		_rightmove_flag = true;
	}
	if (g.GetTrg() & PAD_INPUT_4) {
		_mode_cnt = _cnt;
		auto ol = new OverlayBlack();
		ol->SetFade(FADE_FRAME, 120,180, FADE_SPEED);
		g.GetMS()->Add(ol, 2, "OverlayBlack");
		g.GetMS()->Del(g.GetMS()->Get("Guide"));
		g.GetMS()->Del(g.GetMS()->Get("RedReturn"));
		_end_flag = true;
	}
	if (_leftmove_flag == true) {
		if (_x < 2880) {
			_x += 60;
		}
		if (_x == 2880) {
			_leftmove_flag = false;
		}
	}
	if (_rightmove_flag == true) {
		if (_x > 960) {
			_x-= 60;
		}
		if (_x == 960) {
			_rightmove_flag = false;
		}
	}
	return true;
}

bool ModeCredit::Draw(Game& g) {
	auto posx = _x - 960;
	auto posy = _y - 540;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _pal);
	DrawRotaGraph(posx, posy, 1.0, 0.0, _grhandle, _trans_flag, false);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	return true;
}

bool Guide::Initialize(Game& g) {
	_x = 1500;
	_y = 980;
	_pal = 255;
	_trans_flag = true;
	_grhandle = ResourceServer::LoadGraph("res/Mode/MoveGuide.png");
	return true;
}

bool Guide::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool Guide::Process(Game& g) {
	base::Process(g);
	return true;
}

bool Guide::Draw(Game& g) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _pal);
	DrawRotaGraph(_x, _y, 1.0, 0.0, _grhandle, _trans_flag, false);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	return true;
}

bool RedReturn::Initialize(Game& g) {
	_x = 1750;
	_y = 980;
	_pal = 255;
	_trans_flag = true;
	_grhandle = ResourceServer::LoadGraph("res/Mode/RedReturn.png");
	return true;
}

bool RedReturn::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool RedReturn::Process(Game& g) {
	base::Process(g);
	return true;
}

bool RedReturn::Draw(Game& g) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _pal);
	DrawRotaGraph(_x, _y, 1.0, 0.0, _grhandle, _trans_flag, false);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	return true;
}