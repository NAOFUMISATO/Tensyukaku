#include <DxLib.h>
#include "ModePrologue.h"
#include "PrologueText.h"
#include "ModeGame.h"
#include "Game.h"
#include "OverlayBlack.h"
#include "ResourceServer.h"
using namespace ProInfo;
bool PrologueText::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 1600;
	_y = 540;
	_Pal = 0;
	_GraphNo = 0;
	_Mode_Cnt = _Cnt;
	_Trans_Flag = true;
	_Skip_Flag = false;
	_GrAll["PText"].resize(TEXT_ANIMEMAX);
	ResourceServer::LoadDivGraph(TEXT_GRAPHNAME, TEXT_ANIMEMAX, TEXT_WIDTHCOUNT, TEXT_HEIGHTCOUNT, TEXT_GRAPH_WIDTH, TEXT_GRAPH_HEIGHT, _GrAll["PText"].data());
	LoadSE();
	VolumeInit();
	return true;
}

bool PrologueText::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool PrologueText::Process(Game& g) {
	base::Process(g);
	VolumeChange();
	auto frame = _Cnt - _Mode_Cnt;
	_GrHandle = _GrAll["PText"][_Anime["PText"]];
	_Anime["PText"] = _GraphNo;
	//テキスト1
	if (_Skip_Flag == false) {
		if (frame == 1) {
			PlaySoundMem(_Se["Text1"], DX_PLAYTYPE_BACK, true);
		}
		if (frame < TEXT1_FADEIN_FRAME) {
			_Pal += TEXT_FADE_SPEED;
		}
		if (frame == TEXT1_FADEIN_FRAME) {
			_Pal = 255;
			auto as = new PrologueASkip();
			g.GetMS()->Add(as, 1, "PASkip");
		}
		if (frame >= TEXT1_FADEOUT_BEGINFRAME && TEXT1_FADEOUT_ENDFRAME > frame) {
			_Pal -= TEXT_FADE_SPEED;
		}
		if (frame == TEXT1_FADEOUT_ENDFRAME) {
			_Pal = 0;
			_GraphNo = 1;
		}
		//テキスト2
		if (frame == TEXT2_FADEIN_BEGINFRAME) {
			PlaySoundMem(_Se["Text2"], DX_PLAYTYPE_BACK, true);
		}
		if (frame >= TEXT2_FADEIN_BEGINFRAME && TEXT2_FADEIN_ENDFRAME > frame) {
			_Pal += TEXT_FADE_SPEED;
		}
		if (frame == TEXT2_FADEIN_ENDFRAME) {
			_Pal = 255;
		}
		if (frame >= TEXT2_FADEOUT_BEGINFRAME && TEXT2_FADEOUT_ENDFRAME > frame) {
			_Pal -= TEXT_FADE_SPEED;
		}
		if (frame == TEXT2_FADEOUT_ENDFRAME) {
			_Pal = 0;
			_GraphNo = 2;
		}
		//テキスト3
		if (frame == TEXT3_FADEIN_BEGINFRAME) {
			PlaySoundMem(_Se["Text3"], DX_PLAYTYPE_BACK, true);
		}
		if (frame >= TEXT3_FADEIN_BEGINFRAME && TEXT3_FADEIN_ENDFRAME > frame) {
			_Pal += TEXT_FADE_SPEED;
		}
		if (frame == TEXT3_FADEIN_ENDFRAME) {
			_Pal = 255;
		}
		if (frame >= TEXT3_FADEOUT_BEGINFRAME && TEXT3_FADEOUT_ENDFRAME > frame) {
			_Pal -= TEXT_FADE_SPEED;
		}
		if (frame == TEXT3_FADEOUT_ENDFRAME) {
			_Pal = 0;
			_GraphNo = 3;
		}
		//テキスト4
		if (frame == TEXT4_FADEIN_BEGINFRAME) {
			PlaySoundMem(_Se["Text4"], DX_PLAYTYPE_BACK, true);
		}
		if (frame >= TEXT4_FADEIN_BEGINFRAME && TEXT4_FADEIN_ENDFRAME > frame) {
			_Pal += TEXT_FADE_SPEED;
		}
		if (frame == TEXT4_FADEIN_ENDFRAME) {
			_Pal = 255;
		}
		if (frame >= TEXT4_FADEOUT_BEGINFRAME && TEXT4_FADEOUT_ENDFRAME > frame) {
			_Pal -= TEXT_FADE_SPEED;
		}
		if (frame == TEXT4_FADEOUT_ENDFRAME) {
			_Pal = 0;
			_x = 1500;
			_y = 850;
			_GraphNo = 4;
		}
		//テキスト5
		if (frame == TEXT5_FADEIN_BEGINFRAME) {
			PlaySoundMem(_Se["Text5"], DX_PLAYTYPE_BACK, true);
		}
		if (frame >= TEXT5_FADEIN_BEGINFRAME && TEXT5_FADEIN_ENDFRAME > frame) {
			_Pal += TEXT_FADE_SPEED;
		}
		if (frame == TEXT5_FADEIN_ENDFRAME) {
			_Pal = 255;
		}
		if (frame >= TEXT5_FADEOUT_BEGINFRAME && TEXT5_FADEOUT_ENDFRAME > frame) {
			_Pal -= TEXT_FADE_SPEED;
		}
		if (frame == TEXT5_FADEOUT_ENDFRAME) {
			_Pal = 0;
			g.GetMS()->Del(this);
		}
	}
	/*----------ボタン押下によるスキップ----------*/
	auto fadeoutframe =85;
	if (g.GetTrg() & PAD_INPUT_4&&_Skip_Flag==false) {
		_Mode_Cnt = _Cnt;
		_Skip_Flag = true;
		//モードオーバーレイ生成
		auto ol = new OverlayBlack();
		ol->SetFade(fadeoutframe, 480, 600, 3);
		g.GetMS()->Add(ol, 2, "OverlayBlack");
	}
	//スキップ時の音源のフェードアウト
	if (frame >= 0 && frame < fadeoutframe && _Skip_Flag == true) {
		auto vpal = g.GetVpal();
		vpal["Prologue"] -= 1;
		g.SetVpal(vpal);
		_Vpal["Text1"]-=4;
		_Vpal["Text2"]-=4;
		_Vpal["Text3"]-=4;
		_Vpal["Text4"]-=4;
		_Vpal["Text5"]-=4;
	}
	//押下により一定時間後、流れている音源の停止&モードゲーム生成
	if (frame == fadeoutframe&& _Skip_Flag == true) {
		StopSoundMem(_Se["Text1"]);
		StopSoundMem(_Se["Text2"]);
		StopSoundMem(_Se["Text3"]);
		StopSoundMem(_Se["Text4"]);
		StopSoundMem(_Se["Text5"]);
		StopSoundMem(g.GetBgm() ["Prologue"]);
		g.GetMS()->Del(g.GetMS()->Get("PASkip"));
		g.GetMS()->Del(g.GetMS()->Get("Prologue"));
		g.GetMS()->Del(this);
		auto mg = new ModeGame();
		g.GetMS()->Add(mg, 0, "Game");
	}
	return true;
}

bool PrologueText::Draw(Game& g) {
	base::Draw(g);
	return true;
}

//SE読み込み
void		PrologueText::LoadSE() {
	_Se["Text1"] = ResourceServer::LoadSoundMem("se/Voice/Prologue01.wav");
	_Se["Text2"] = ResourceServer::LoadSoundMem("se/Voice/Prologue02.wav");
	_Se["Text3"] = ResourceServer::LoadSoundMem("se/Voice/Prologue03.wav");
	_Se["Text4"] = ResourceServer::LoadSoundMem("se/Voice/Prologue04.wav");
	_Se["Text5"] = ResourceServer::LoadSoundMem("se/Voice/Prologue05.wav");
}

//ボリューム初期値
void		PrologueText::VolumeInit() {
	_Vpal["Text1"]=255;
	_Vpal["Text2"]=255;
	_Vpal["Text3"]=255;
	_Vpal["Text4"]=255;
	_Vpal["Text5"]=255;
}
//ボリューム変更
void		PrologueText::VolumeChange() {
	ChangeVolumeSoundMem(_Vpal["Text1"],_Se["Text1"]);
	ChangeVolumeSoundMem(_Vpal["Text2"], _Se["Text2"]);
	ChangeVolumeSoundMem(_Vpal["Text3"], _Se["Text3"]);
	ChangeVolumeSoundMem(_Vpal["Text4"], _Se["Text4"]);
	ChangeVolumeSoundMem(_Vpal["Text5"], _Se["Text5"]);
}


//Aボタンススキップ画像
bool PrologueASkip::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 1650;
	_y = 1000;
	_Trans_Flag = true;
	_GrHandle=ResourceServer::LoadGraph("res/Mode/ASkip.png");
	return true;
}

bool PrologueASkip::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool PrologueASkip::Process(Game& g) {
	base::Process(g);
	return true;
}

bool PrologueASkip::Draw(Game& g) {
	base::Draw(g);
	return true;
}

