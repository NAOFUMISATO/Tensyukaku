#include <DxLib.h>
#include "ModeGame.h"
#include "ModeBossBefore.h"
#include "OverlayBlack.h"
#include "Game.h"
#include "ResourceServer.h"

using namespace BBInfo;
bool ModeBossBefore::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;
	_y = 540;
	_pal = 255;
	_mode_cnt = _cnt;
	_grhandle = ResourceServer::LoadGraph("res/Mode/BossBefore.png");
	_se["BossBefore"]=ResourceServer::LoadSoundMem("se/Voice/BossBefore.wav");
	_vpal["BossBefore"] = 255;
	return true;
}

bool ModeBossBefore::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool ModeBossBefore::Process(Game& g) {
	base::Process(g);
	ChangeVolumeSoundMem(_vpal["BossBefore"], _se["BossBefore"]);
	auto frame = _cnt - _mode_cnt;
	if (frame == VOICE_FRAME) {
		PlaySoundMem(_se["BossBefore"],DX_PLAYTYPE_BACK,true);
	}
	auto fadeoutendframe = 60;
	if (frame == FADEOUT_FRAME) {
		auto ol = new OverlayBlack();
		ol->SetFade(fadeoutendframe, 80,140 , 5);
		g.GetMS()->Add(ol,10, "OverlayBlack");
	}
	if (frame == FADEOUT_FRAME + fadeoutendframe) {
		auto mg = (ModeGame*)g.GetMS()->Get("Game");
		PlaySoundMem(g.GetBgm()["Boss"], DX_PLAYTYPE_LOOP, true);
		mg->SetStopObjProcess(false);
		g.GetMS()->Del(this);
	}
	return true;
}

bool ModeBossBefore::Draw(Game& g) {
	base::Draw(g);
	return true;
}