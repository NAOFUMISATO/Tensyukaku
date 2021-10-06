#include <DxLib.h>
#include "ModeGameover.h"
#include "ModeGame.h"
#include "OverlayBlack.h"
#include "OverSelect.h"
#include "OverLogo.h"
#include "Game.h"
#include "ResourceServer.h"

bool ModeGameover::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;
	_y = 540;
	_pal = 0;
	_mode_cnt = _cnt;
	_grhandle = ResourceServer::LoadGraph("res/Mode/Black.png");
	_se["GameOver"] = ResourceServer::LoadSoundMem("se/OutGame/GameOver.wav");
	_vpal["GameOver"] = 255;
	ChangeVolumeSoundMem(_vpal["GameOver"], _se["GameOver"]);
	PlaySoundMem(_se["GameOver"], DX_PLAYTYPE_BACK, true);
	return true;
}

bool ModeGameover::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool ModeGameover::Process(Game& g) {
	base::Process(g);
	auto frame = _cnt - _mode_cnt;
	if (frame < 60) {
		_pal += 3;
	}
	if (frame == 60) {
		_pal = 200;
		auto ol = new Overlogo();
		g.GetMS()->Add(ol, 3, "OverLogo");
	}
	if (frame == 120) {
		auto ps = new OverSelect();
		g.GetMS()->Add(ps, 3, "PSelect");
	}
	return true;
}

bool ModeGameover::Draw(Game& g) {
	base::Draw(g);
	return true;
}