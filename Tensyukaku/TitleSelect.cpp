#include <DxLib.h>
#include "ResourceServer.h"
#include "TitleSelect.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ModeGame.h"
#include <vector>
#include <sstream>
namespace {
	constexpr auto RED = 0;
	constexpr auto GREEN = 1;
	constexpr auto BLUE = 2;
}
//タイトルロゴ
TitleLogo::TitleLogo() {
	Init();
	_grall["TitleLogo"].resize(30);
	ResourceServer::LoadDivGraph("res/Mode/TitleLogo.png",30,7,5,1280,410, _grall["TitleLogo"].data());
}
TitleLogo::~TitleLogo() {
}
void TitleLogo::Init() {
	_x = 1350;
	_y = 200;
	_hit_x = -400;
	_hit_y = -100;
	_hit_w = 700;
	_hit_h = 200;
	_action_cnt = _cnt;
}
void TitleLogo::Process(Game& g) {
	ObjectBase::Process(g);
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["TitleLogo"][_anime["TitleLogo"]];
	if (frame < 90) {
		_anime["TitleLogo"]= ((frame) / 3) % 30;
	}
}

void TitleLogo::Draw(Game& g) {
	auto scale = _drg.first;
	auto angle = _drg.second;
	DrawRotaGraph(_x, _y, scale, angle, _grhandle, true, _isflip);
#ifdef _DEBUG
	int& re = std::get<RED>(_debug_color);
	int& gr = std::get<GREEN>(_debug_color);
	int& bl = std::get<BLUE>(_debug_color);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _debug_alpha);		// 半透明描画指定
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_x + _hit_w, _y + _hit_y + _hit_h, GetColor(re, gr, bl), _debug_fill);	// 半透明の赤で当たり判定描画
#endif
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// 不透明描画指定
}
//ゲームスタート
GameStart::GameStart() {
	Init();
	_grhandle=ResourceServer::LoadGraph("res/Mode/GameStart.png");
};
GameStart::~GameStart() {
};

void GameStart::Init() {
	_x = 1800;
	_y = 500;
	_hit_x = -260;
	_hit_y = -60;
	_hit_w = 460;
	_hit_h = 120;
	_drg.first = 1.0;
	_drg.second = 0.0;
	_alpha = 0;
}

void GameStart::Process(Game& g) {
	ObjectBase::Process(g);
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{// iteはカーソルか？
		if ((*ite)->GetObjType() == OBJECTTYPE::CURSOR)
		{
			if (IsHit(*(*ite)) == true)
			{
				_drg.first = 1.1;
			}else{ _drg.first = 1.0; }
		}
	}
	if (_x >= 1600) {
		_x -= 2;
	}
	if (_alpha <= 255) {
		_alpha += 2;
	}
}

void GameStart::Draw(Game& g) {
	auto scale = _drg.first;
	auto angle = _drg.second;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
	DrawRotaGraph(_x, _y, scale, angle, _grhandle, true, _isflip);
#ifdef _DEBUG
	int& re = std::get<RED>(_debug_color);
	int& gr = std::get<GREEN>(_debug_color);
	int& bl = std::get<BLUE>(_debug_color);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _debug_alpha);		// 半透明描画指定
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_x + _hit_w, _y + _hit_y + _hit_h, GetColor(re, gr, bl), _debug_fill);	// 半透明の赤で当たり判定描画
#endif
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// 不透明描画指定
}
//説明画面
Explain::Explain() {
	Init();
	_grhandle = ResourceServer::LoadGraph("res/Mode/Explain.png");
};
Explain::~Explain() {
};

void Explain::Init() {
	_x = 1800;
	_y = 670;
	_hit_x = -220;
	_hit_y = -60;
	_hit_w = 400;
	_hit_h = 120;
	_drg.first = 1.0;
	_drg.second = 0.0;
	_alpha = 0;
}
void Explain::Process(Game& g) {
	ObjectBase::Process(g);
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{// iteはカーソルか？
		if ((*ite)->GetObjType() == OBJECTTYPE::CURSOR)
		{
			if (IsHit(*(*ite)) == true)
			{
				_drg.first = 1.1;
			}
			else { _drg.first = 1.0; }
		}
	}
	if (_x >= 1620) {
		_x -= 2;
	}
	if (_alpha <= 255) {
		_alpha += 2;
	}
}

void Explain::Draw(Game& g) {
	auto scale = _drg.first;
	auto angle = _drg.second;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
	DrawRotaGraph(_x, _y, scale, angle, _grhandle, true, _isflip);
#ifdef _DEBUG
	int& re = std::get<RED>(_debug_color);
	int& gr = std::get<GREEN>(_debug_color);
	int& bl = std::get<BLUE>(_debug_color);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _debug_alpha);		// 半透明描画指定
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_x + _hit_w, _y + _hit_y + _hit_h, GetColor(re, gr, bl), _debug_fill);	// 半透明の赤で当たり判定描画
#endif
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// 不透明描画指定
}
//ゲーム終了
GameEnd::GameEnd() {
	Init();
	_grhandle = ResourceServer::LoadGraph("res/Mode/GameEnd.png");
};
GameEnd::~GameEnd() {
};

void GameEnd::Init() {
	_x = 1800;
	_y =970;
	_hit_x = -220;
	_hit_y = -60;
	_hit_w = 400;
	_hit_h = 120;
	_drg.first = 1.0;
	_drg.second = 0.0;
	_alpha = 0;
}

void GameEnd::Process(Game& g) {
	ObjectBase::Process(g);
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはカーソルか？
		if ((*ite)->GetObjType() == OBJECTTYPE::CURSOR)
		{
			if (IsHit(*(*ite)) == true)
			{
				_drg.first = 1.1;
			}
			else { _drg.first = 1.0; }
		}
	}
	if (_x >= 1620) {
		_x -= 2;
	}
	if (_alpha <= 255) {
		_alpha +=2 ;
	}
}

void GameEnd::Draw(Game& g) {
	auto scale = _drg.first;
	auto angle = _drg.second;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
	DrawRotaGraph(_x, _y, scale, angle, _grhandle, true, _isflip);
#ifdef _DEBUG
	int& re = std::get<RED>(_debug_color);
	int& gr = std::get<GREEN>(_debug_color);
	int& bl = std::get<BLUE>(_debug_color);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _debug_alpha);		// 半透明描画指定
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_x + _hit_w, _y + _hit_y + _hit_h, GetColor(re, gr, bl), _debug_fill);	// 半透明の赤で当たり判定描画
#endif
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// 不透明描画指定
}

//クレジット
Credit::Credit() {
	Init();
	_grhandle = ResourceServer::LoadGraph("res/Mode/Credit.png");
};
Credit::~Credit() {
};

void Credit::Init() {
	_x = 1800;
	_y =820;
	_hit_x = -220;
	_hit_y = -60;
	_hit_w = 400;
	_hit_h = 120;
	_drg.first = 1.0;
	_drg.second = 0.0;
	_alpha = 0;
}

void Credit::Process(Game& g) {
	ObjectBase::Process(g);
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{// iteはカーソルか？
		if ((*ite)->GetObjType() == OBJECTTYPE::CURSOR)
		{
			if (IsHit(*(*ite)) == true)
			{
				_drg.first = 1.1;
			}
			else { _drg.first = 1.0; }
		}
	}
	if (_x >= 1620) {
		_x -= 2;
	}
	if (_alpha <= 255) {
		_alpha += 2;
	}
}

void Credit::Draw(Game& g) {
	auto scale = _drg.first;
	auto angle = _drg.second;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
	DrawRotaGraph(_x, _y, scale, angle, _grhandle, true, _isflip);
#ifdef _DEBUG
	int& re = std::get<RED>(_debug_color);
	int& gr = std::get<GREEN>(_debug_color);
	int& bl = std::get<BLUE>(_debug_color);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _debug_alpha);		// 半透明描画指定
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_x + _hit_w, _y + _hit_y + _hit_h, GetColor(re, gr, bl), _debug_fill);	// 半透明の赤で当たり判定描画
#endif
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// 不透明描画指定
}