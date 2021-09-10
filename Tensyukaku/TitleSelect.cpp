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
	constexpr auto Blue = 2;
}
//É^ÉCÉgÉãÉçÉS
TitleLogo::TitleLogo() {
	Init();
	_GrAll["TitleLogo"].resize(30);
	ResourceServer::LoadDivGraph("res/Mode/TitleLogo.png",30,7,5,1280,410, _GrAll["TitleLogo"].data());
}
TitleLogo::~TitleLogo() {
}
void TitleLogo::Init() {
	_x = 1300;
	_y = 250;
	_gx = 0;
	_gy = -60;
	_hit_x = -400;
	_hit_y = -100;
	_hit_w = 700;
	_hit_h = 200;
	_Action_Cnt = _Cnt;
}
void TitleLogo::Process(Game& g) {
	ObjectBase::Process(g);
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["TitleLogo"][_Anime["TitleLogo"]];
	if (frame < 90) {
		_Anime["TitleLogo"]= ((frame) / 3) % 30;
	}
}

void TitleLogo::Draw(Game& g) {
	DrawRotaGraph(_x, _y, 1.0, 0.0, _GrHandle, true, false);
	int& re = std::get<RED>(_Color);
	int& gr = std::get<GREEN>(_Color);
	int& bl = std::get<Blue>(_Color);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Dalpha);		// îºìßñæï`âÊéwíË
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_x + _hit_w, _y + _hit_y + _hit_h, GetColor(re, gr, bl), _Fill);	// îºìßñæÇÃê‘Ç≈ìñÇΩÇËîªíËï`âÊ
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
//ÉQÅ[ÉÄÉXÉ^Å[Ég
GameStart::GameStart() {
	Init();
	_GrHandle=ResourceServer::LoadGraph("res/Mode/GameStart.png");
};
GameStart::~GameStart() {
};

void GameStart::Init() {
	_x = 1580;
	_y = 500;
	_hit_x = -320;
	_hit_y = -60;
	_hit_w = 550;
	_hit_h = 150;
	_Alpha = 0;
}

void GameStart::Process(Game& g) {
	ObjectBase::Process(g);
	if (_x >= 1460) {
		_x -= 2;
	}
	if (_Alpha <= 255) {
		_Alpha += 4;
	}
}

void GameStart::Draw(Game& g) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Alpha);
	DrawRotaGraph(_x, _y, 1.0, 0.0, _GrHandle, true, false);
	int& re = std::get<RED>(_Color);
	int& gr = std::get<GREEN>(_Color);
	int& bl = std::get<Blue>(_Color);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Dalpha);		// îºìßñæï`âÊéwíË
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_x + _hit_w, _y + _hit_y + _hit_h, GetColor(re, gr, bl), _Fill);	// îºìßñæÇÃê‘Ç≈ìñÇΩÇËîªíËï`âÊ
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
//ê‡ñæâÊñ 
Explain::Explain() {
	Init();
	_GrHandle = ResourceServer::LoadGraph("res/Mode/Explain.png");
};
Explain::~Explain() {
};

void Explain::Init() {
	_x = 1580;
	_y = 700;
	_hit_x = -320;
	_hit_y = -60;
	_hit_w = 550;
	_hit_h = 150;
	_Alpha = 0;
}
void Explain::Process(Game& g) {
	ObjectBase::Process(g);
	if (_x >= 1460) {
		_x -= 2;
	}
	if (_Alpha <= 255) {
		_Alpha += 4;
	}
}

void Explain::Draw(Game& g) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Alpha);
	DrawRotaGraph(_x, _y, 1.0, 0.0, _GrHandle, true, false);
	int& re = std::get<RED>(_Color);
	int& gr = std::get<GREEN>(_Color);
	int& bl = std::get<Blue>(_Color);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Dalpha);		// îºìßñæï`âÊéwíË
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_x + _hit_w, _y + _hit_y + _hit_h, GetColor(re, gr, bl), _Fill);	// îºìßñæÇÃê‘Ç≈ìñÇΩÇËîªíËï`âÊ
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
//ÉQÅ[ÉÄèIóπ
GameEnd::GameEnd() {
	Init();
	_GrHandle = ResourceServer::LoadGraph("res/Mode/GameEnd.png");
};
GameEnd::~GameEnd() {
};

void GameEnd::Init() {
	_x = 1580;
	_y = 900;
	_hit_x = -320;
	_hit_y = -60;
	_hit_w = 550;
	_hit_h = 150;
	_Alpha = 0;
}

void GameEnd::Process(Game& g) {
	ObjectBase::Process(g);
	if (_x >= 1460) {
		_x -= 2;
	}
	if (_Alpha <= 255) {
		_Alpha += 4;
	}
}

void GameEnd::Draw(Game& g) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Alpha);
	DrawRotaGraph(_x, _y, 1.0, 0.0, _GrHandle, true, false);
	int& re = std::get<RED>(_Color);
	int& gr = std::get<GREEN>(_Color);
	int& bl = std::get<Blue>(_Color);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Dalpha);		// îºìßñæï`âÊéwíË
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_x + _hit_w, _y + _hit_y + _hit_h, GetColor(re, gr, bl), _Fill);	// îºìßñæÇÃê‘Ç≈ìñÇΩÇËîªíËï`âÊ
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}