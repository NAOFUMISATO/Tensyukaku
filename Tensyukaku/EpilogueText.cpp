/*****************************************************************//**
 * \file   EpilogueText.cpp
 * \brief  エピローグテキストクラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModeEpilogue.h"
#include "EpilogueText.h"
#include "ModeGame.h"
#include "Game.h"
#include "ResourceServer.h"

using namespace EpiInfo;
/*-----初期化------*/
bool EpilogueText::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = TEXT_FIRST_XPOSITION;		//X座標初期化
	_y = 750;													//Y座標初期化
	_pal = 0;													//フェードインしていくため、透明度0で初期化
	_GraphNo = 0;										//シート番号0で初期化
	_mode_cnt = _cnt;								//フレームの初期化
	_trans_flag = true;								//背景透過フラグを真で初期化
	//画像読み込み
	_grall["EText"].resize(TEXT_ANIMEMAX);
	ResourceServer::LoadDivGraph(TEXT_GRAPHNAME, TEXT_ANIMEMAX, TEXT_WIDTHCOUNT, TEXT_HEIGHTCOUNT, TEXT_GRAPH_WIDTH, TEXT_GRAPH_HEIGHT, _grall["EText"].data());
	LoadSE();													//SE読み込み
	VolumeInit();											//SE音量の初期化
	return true;
}

bool EpilogueText::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
/*-----更新------*/
bool EpilogueText::Process(Game& g) {
	base::Process(g);
	VolumeChange();					//効果音音量変更
	auto frame = _cnt - _mode_cnt;
	_grhandle = _grall["EText"][_anime["EText"]];
	_anime["EText"] = _GraphNo;
	/*-----各テキストのフェードイン、フェードアウト、移動フレーム-----*/
	//テキスト1
	if (frame == 1) {
		//ボイス
		PlaySoundMem(_se["Text1"], DX_PLAYTYPE_BACK, true);
	}
	if (frame < TEXT1_FADEIN_FRAME) {
		_pal += TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT1_FADEIN_FRAME) {
		_pal = 255;
	}
	if (frame >= TEXT1_FADEOUT_BEGINFRAME && TEXT1_FADEOUT_ENDFRAME > frame) {
		_pal -= TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT1_FADEOUT_ENDFRAME) {
		_pal = 0;
		_x = TEXT_FIRST_XPOSITION;
		_GraphNo = 1;
	}
	//テキスト2
	if (frame == TEXT2_FADEIN_BEGINFRAME) {
		//ボイス
		PlaySoundMem(_se["Text2"], DX_PLAYTYPE_BACK, true);
	}
	if (frame >= TEXT2_FADEIN_BEGINFRAME && TEXT2_FADEIN_ENDFRAME > frame) {
		_pal += TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT2_FADEIN_ENDFRAME) {
		_pal = 255;
	}
	if (frame >= TEXT2_FADEOUT_BEGINFRAME && TEXT2_FADEOUT_ENDFRAME > frame) {
		_pal -= TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT2_FADEOUT_ENDFRAME) {
		_pal = 0;
		_x = TEXT_FIRST_XPOSITION;
		_GraphNo = 2;
	}
	//テキスト3
	if (frame == TEXT3_FADEIN_BEGINFRAME) {
		//ボイス
		PlaySoundMem(_se["Text3"], DX_PLAYTYPE_BACK, true);
	}
	if (frame >= TEXT3_FADEIN_BEGINFRAME && TEXT3_FADEIN_ENDFRAME > frame) {
		_pal += TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT3_FADEIN_ENDFRAME) {
		_pal = 255;
	}
	if (frame >= TEXT3_FADEOUT_BEGINFRAME && TEXT3_FADEOUT_ENDFRAME > frame) {
		_pal -= TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT3_FADEOUT_ENDFRAME) {
		_pal = 0;
		_x = TEXT_FIRST_XPOSITION;
		_GraphNo = 3;
	}
	//テキスト4
	if (frame == TEXT4_FADEIN_BEGINFRAME) {
		//ボイス
		PlaySoundMem(_se["Text4"], DX_PLAYTYPE_BACK, true);
	}
	if (frame >= TEXT4_FADEIN_BEGINFRAME && TEXT4_FADEIN_ENDFRAME > frame) {
		_pal += TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT4_FADEIN_ENDFRAME) {
		_pal = 255;
	}
	if (frame >= TEXT4_FADEOUT_BEGINFRAME && TEXT4_FADEOUT_ENDFRAME > frame) {
		_pal -= TEXT_FADE_SPEED;
		_x += TEXT_MOVE_SPEED;
	}
	if (frame == TEXT4_FADEOUT_ENDFRAME) {
		_pal = 0;
		g.GetMS()->Del(this);
	}
	return true;
}
/*-----描画------*/
bool EpilogueText::Draw(Game& g) {
	base::Draw(g);
	return true;
}

//SE読み込み
void	EpilogueText::LoadSE() {
	_se["Text1"] = ResourceServer::LoadSoundMem("se/Voice/Epilogue01.wav");
	_se["Text2"] = ResourceServer::LoadSoundMem("se/Voice/Epilogue02.wav");
	_se["Text3"] = ResourceServer::LoadSoundMem("se/Voice/Epilogue03.wav");
	_se["Text4"] = ResourceServer::LoadSoundMem("se/Voice/Epilogue04.wav");
}

//ボリューム初期値
void	EpilogueText::VolumeInit() {
	_vpal["Text1"] = 255;
	_vpal["Text2"] = 255;
	_vpal["Text3"] = 255;
	_vpal["Text4"] = 255;
}
//ボリューム変更
void	EpilogueText::VolumeChange() {
	ChangeVolumeSoundMem(_vpal["Text1"], _se["Text1"]);
	ChangeVolumeSoundMem(_vpal["Text2"], _se["Text2"]);
	ChangeVolumeSoundMem(_vpal["Text3"], _se["Text3"]);
	ChangeVolumeSoundMem(_vpal["Text4"], _se["Text4"]);
}
