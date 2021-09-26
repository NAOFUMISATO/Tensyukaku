#include <DxLib.h>
#include "ModeEpilogue.h"
#include "EpilogueText.h"
#include "ModeGame.h"
#include "Game.h"
#include "ResourceServer.h"
using namespace EpiInfo;
bool EpilogueText::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = TEXT_FIRST_XPOSITION;
	_y = 900;
	_Pal = 0;
	_GraphNo = 0;
	_Mode_Cnt = _Cnt;
	_Trans_Flag = true;
	_GrAll["EText"].resize(TEXT_ANIMEMAX);
	ResourceServer::LoadDivGraph(TEXT_GRAPHNAME, TEXT_ANIMEMAX, TEXT_WIDTHCOUNT, TEXT_HEIGHTCOUNT, TEXT_GRAPH_WIDTH, TEXT_GRAPH_HEIGHT, _GrAll["EText"].data());
	LoadSE();
	VolumeInit();
	return true;
}

bool EpilogueText::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool EpilogueText::Process(Game& g) {
	base::Process(g);
	VolumeChange();
	auto frame = _Cnt - _Mode_Cnt;
	_GrHandle = _GrAll["EText"][_Anime["EText"]];
	_Anime["EText"] = _GraphNo;
	//テキスト1
	if (frame == 1) {
		PlaySoundMem(_Se["Text1"], DX_PLAYTYPE_BACK, true);
	}
	if (frame < TEXT1_FADEIN_FRAME) {
		_Pal += TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT1_FADEIN_FRAME) {
		_Pal = 255;
	}
	if (frame >= TEXT1_FADEOUT_BEGINFRAME && TEXT1_FADEOUT_ENDFRAME > frame) {
		_Pal -= TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT1_FADEOUT_ENDFRAME) {
		_Pal = 0;
		_x = TEXT_FIRST_XPOSITION;
		_GraphNo = 1;
	}
	//テキスト2
	if (frame == TEXT2_FADEIN_BEGINFRAME) {
		PlaySoundMem(_Se["Text2"], DX_PLAYTYPE_BACK, true);
	}
	if (frame >= TEXT2_FADEIN_BEGINFRAME && TEXT2_FADEIN_ENDFRAME > frame) {
		_Pal += TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT2_FADEIN_ENDFRAME) {
		_Pal = 255;
	}
	if (frame >= TEXT2_FADEOUT_BEGINFRAME && TEXT2_FADEOUT_ENDFRAME > frame) {
		_Pal -= TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT2_FADEOUT_ENDFRAME) {
		_Pal = 0;
		_x = TEXT_FIRST_XPOSITION;
		_GraphNo = 2;
	}
	//テキスト3
	if (frame == TEXT3_FADEIN_BEGINFRAME) {
		PlaySoundMem(_Se["Text3"], DX_PLAYTYPE_BACK, true);
	}
	if (frame >= TEXT3_FADEIN_BEGINFRAME && TEXT3_FADEIN_ENDFRAME > frame) {
		_Pal += TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT3_FADEIN_ENDFRAME) {
		_Pal = 255;
	}
	if (frame >= TEXT3_FADEOUT_BEGINFRAME && TEXT3_FADEOUT_ENDFRAME > frame) {
		_Pal -= TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT3_FADEOUT_ENDFRAME) {
		_Pal = 0;
		_x = TEXT_FIRST_XPOSITION;
		_GraphNo = 3;
	}
	//テキスト4
	if (frame == TEXT4_FADEIN_BEGINFRAME) {
		PlaySoundMem(_Se["Text4"], DX_PLAYTYPE_BACK, true);
	}
	if (frame >= TEXT4_FADEIN_BEGINFRAME && TEXT4_FADEIN_ENDFRAME > frame) {
		_Pal += TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT4_FADEIN_ENDFRAME) {
		_Pal = 255;
	}
	if (frame >= TEXT4_FADEOUT_BEGINFRAME && TEXT4_FADEOUT_ENDFRAME > frame) {
		_Pal -= TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT4_FADEOUT_ENDFRAME) {
		_Pal = 0;
		g.GetMS()->Del(this);
	}
	return true;
}

bool EpilogueText::Draw(Game& g) {
	base::Draw(g);
	return true;
}

//SE読み込み
void	EpilogueText::LoadSE() {
	_Se["Text1"] = ResourceServer::LoadSoundMem("se/Voice/Epilogue01.wav");
	_Se["Text2"] = ResourceServer::LoadSoundMem("se/Voice/Epilogue02.wav");
	_Se["Text3"] = ResourceServer::LoadSoundMem("se/Voice/Epilogue03.wav");
	_Se["Text4"] = ResourceServer::LoadSoundMem("se/Voice/Epilogue04.wav");
}

//ボリューム初期値
void	EpilogueText::VolumeInit() {
	_Vpal["Text1"] = 255;
	_Vpal["Text2"] = 255;
	_Vpal["Text3"] = 255;
	_Vpal["Text4"] = 255;
}
//ボリューム変更
void	EpilogueText::VolumeChange() {
	ChangeVolumeSoundMem(_Vpal["Text1"], _Se["Text1"]);
	ChangeVolumeSoundMem(_Vpal["Text2"], _Se["Text2"]);
	ChangeVolumeSoundMem(_Vpal["Text3"], _Se["Text3"]);
	ChangeVolumeSoundMem(_Vpal["Text4"], _Se["Text4"]);
}
