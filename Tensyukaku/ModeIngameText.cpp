#include <DxLib.h>
#include "ResourceServer.h"
#include "Game.h"
#include "ModeIngameText.h"
#include "ModeGame.h"
using namespace ITInfo;
bool ModeIngameText::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;
	_y = 250;
	_pal = 0;
	_fadein_frame = FADEIN_FRAME;
	_fadeout_frame = FADEOUT_FRAME;
	_fade_speed=FADE_SPEED;
	_mode_cnt = _cnt;
	_trans_flag = true;
	LoadTextGraph();
	return true;
}

bool ModeIngameText::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool ModeIngameText::Process(Game& g) {
	base::Process(g);
	auto frame = _cnt - _mode_cnt;
	if (_text_type == "TOP") {
		_grhandle = _grall["TOP"][0];
	}
	else if (_text_type == "UPPER") {
		_grhandle = _grall["UPPER"][0];
	}
	else if (_text_type == "MIDDLE") {
		_grhandle = _grall["MIDDLE"][0];
	}
	else if (_text_type == "UNDER") {
		_grhandle = _grall["UNDER"][0];
		_fadeout_frame = 80;
		_fade_speed = 6;
	}
	if (frame < _fadein_frame) {
		_pal += _fade_speed;
	}
	if (frame == _fadein_frame) {
		_pal = 255;
	}
	if (frame >= _fadeout_frame&&_pal>0) {
		_pal -= _fade_speed;
	}
	if (frame >= _fadeout_frame && _pal <= 0) {
		g.GetMS()->Del(this);
	}
	return true;
}
bool ModeIngameText::Draw(Game& g) {
	base::Draw(g);
	return true;
}

void  ModeIngameText::LoadTextGraph() {
	_grall["TOP"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/IngameText03.png", 1, 1, 1,GRAPH_WIDTH,GRAPH_HEIGHT,_grall["TOP"].data());
	_grall["UPPER"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/IngameText03.png", 1, 1, 1, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["UPPER"].data());
	_grall["MIDDLE"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/IngameText02.png", 1, 1, 1, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["MIDDLE"].data());
	_grall["UNDER"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/IngameText01.png", 1, 1, 1, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["UNDER"].data());
}
