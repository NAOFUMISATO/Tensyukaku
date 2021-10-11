/*****************************************************************//**
 * \file   ModePrologue.cpp
 * \brief  プロローグクラス（モードベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModePrologue.h"
#include "PrologueText.h"
#include "OverlayBlack.h"
#include "ModeGame.h"
#include "Game.h"
#include "ResourceServer.h"

using namespace ProInfo;
/*-----初期化-----*/
bool ModePrologue::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 1920;																//X座標初期化
	_y = 1080;																//Y座標の初期化
	_pal = 0;																	//フェードインしていくため、透明度０で初期化
	_GraphNo = 0;														
	_mode_cnt = _cnt;
	_grall["Prologue"].resize(BG_ANIMEMAX);
	ResourceServer::LoadDivGraph(BG_GRAPHNAME,BG_ANIMEMAX,BG_WIDTHCOUNT, BG_HEIGHTCOUNT,BG_GRAPH_WIDTH, BG_GRAPH_HEIGHT,_grall["Prologue"].data());
	PlaySoundMem(g.GetBgm()["Prologue"], DX_PLAYTYPE_LOOP, true);
	return true;
}

bool ModePrologue::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
/*-----更新-----*/
bool ModePrologue::Process(Game& g) {
	base::Process(g);
	auto frame = _cnt - _mode_cnt;
	_grhandle = _grall["Prologue"][_anime["Prologue"]];
	_anime["Prologue"] = _GraphNo;
	/*----------フェード関係----------*/
	if (frame < BG1_FADEIN_FRAME) {
		_pal += BG1_FADEIN_SPEED;
	}
	if (frame == BG1_FADEIN_FRAME) {
		_pal = 255;
		auto pt = new PrologueText();
		g.GetMS()->Add(pt, 1, "PText");
	}
	if (frame >= BG1_FADEOUT_BEGINFRAME&& BG1_FADEOUT_ENDFRAME>frame) {
		_pal -= BG1_FADEOUT_SPEED;
	}
	if (frame == BG1_FADEOUT_ENDFRAME) {
		_pal = 0;
		_GraphNo = 1;
	}
	if (frame >= BG2_FADEIN_BEGINFRAME&& BG2_FADEIN_ENDFRAME>frame) {
		_pal += BG2_FADEIN_SPEED;
	}
	if (frame == BG2_FADEIN_ENDFRAME) {
		_pal = 255;
	}
	auto fadeoutendframe = 85;
	if (frame == PROLOGUE_FADEOUT_FRAME) {
		auto ol = new OverlayBlack();
		ol->SetFade(fadeoutendframe, 480, 600, 4);
		g.GetMS()->Add(ol, 2, "OverlayBlack");
	}
	if (frame == PROLOGUE_FADEOUT_FRAME + fadeoutendframe) {
		StopSoundMem(g.GetBgm() ["Prologue"]);
		g.GetMS()->Del(g.GetMS()->Get("Prologue"));
		g.GetMS()->Del(g.GetMS()->Get("PASkip"));
		auto mg = new ModeGame();
		g.GetMS()->Add(mg,0,"Game");
	}
	/*----------背景移動関係----------*/
	if (frame >= BG_XMOVE_FRAME && _x <= 3840) {
		_x += BG_XMOVE_SPEED;
	}
	if (frame >= BG_YMOVE_FRAME && _y < 2160) {
		_y += BG_YMOVE_SPEED;
	}
	return true;
}
/*-----描画-----*/
bool ModePrologue::Draw(Game& g) {
	auto posx = _x - 1920;
	auto posy = _y - 1080;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _pal);
	DrawRotaGraph(posx, posy, 1.0,0.0,_grhandle, _trans_flag,false);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	return true;
}

