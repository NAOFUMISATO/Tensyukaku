#include <DxLib.h>
#include "ResourceServer.h"
#include "TitleSelect.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ModeGame.h"
#include <vector>
#include <sstream>
//タイトルロゴ
TitleLogo::TitleLogo() {
	Init();
	_GrAll["TitleLogo"].resize(30);
	ResourceServer::LoadDivGraph("res/Mode/TitleLogo.png",30,30,1,1000,320, _GrAll["TitleLogo"].data());
}
TitleLogo::~TitleLogo() {
}
void TitleLogo::Init() {
	_x = 1400;
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
	ObjectBase::Draw(g);
}
//ゲームスタート
GameStart::GameStart() {
	Init();
	_GrHandle=ResourceServer::LoadGraph("res/Mode/GameStart.png");
};
GameStart::~GameStart() {
};

void GameStart::Init() {
	_x = 1580;
	_y = 600;
	_gx = 0;
	_gy = -60;
	_hit_x = -240;
	_hit_y = -60;
	_hit_w = 480;
	_hit_h = 120;
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
	ObjectBase::Draw(g);
}
//説明画面
Explain::Explain() {
	Init();
	_GrHandle = ResourceServer::LoadGraph("res/Mode/Explain.png");
};
Explain::~Explain() {
};

void Explain::Init() {
	_x = 1580;
	_y = 780;
	_gx = 0;
	_gy = -60;
	_hit_x = -240;
	_hit_y = -60;
	_hit_w = 480;
	_hit_h = 120;
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
	ObjectBase::Draw(g);
}
//ゲーム終了
GameEnd::GameEnd() {
	Init();
	_GrHandle = ResourceServer::LoadGraph("res/Mode/GameEnd.png");
};
GameEnd::~GameEnd() {
};

void GameEnd::Init() {
	_x = 1580;
	_y = 960;
	_gx = 0;
	_gx = 0;
	_gy = -40;
	_hit_x = -240;
	_hit_y = -60;
	_hit_w = 480;
	_hit_h = 120;
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
	ObjectBase::Draw(g);
}