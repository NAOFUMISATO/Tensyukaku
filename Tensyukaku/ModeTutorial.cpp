/*****************************************************************//**
 * \file   ModeTutorial.cpp
 * \brief  インゲームでのチュートリアルクラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ResourceServer.h"
#include "Game.h"
#include "ModeTutorial.h"
#include "ModeGame.h"

using namespace TuInfo;
/*-----初期化-----*/
bool ModeTutorial::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;							//X座標の初期化
	_y = 250;							//Y座標の初期化
	_pal = 255;							//透明度の初期化
	_mode_cnt = _cnt;			//フレームの初期化
	_trans_flag = true;				//背景透過フラグっを真で初期化
	LoadPicture();					//画像読み込み
	return true;
}
/*-----終了------*/
bool ModeTutorial::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
/*-----更新-----*/
bool ModeTutorial::Process(Game& g) {
	base::Process(g);
	//チュートリアルの種類により、描画する画像の変更
	if (_tutorial_type == "1A") {
		_grhandle = _grall["1A"][0];
	}
	else if (_tutorial_type == "1B") {
		_grhandle = _grall["1B"][0];
	}
	else if (_tutorial_type == "2A"){
		_grhandle = _grall["2A"][0];
	}
	else if (_tutorial_type == "3A") {
		_grhandle = _grall["3A"][0];
	}
	else if (_tutorial_type == "3B") {
		_grhandle = _grall["3B"][0];
	}
	else if (_tutorial_type == "4A") {
		_grhandle = _grall["4A"][0];
	}
	else if (_tutorial_type == "5A") {
		_grhandle = _grall["5A"][0];
	}
	return true;
}
/*-----描画-----*/
bool ModeTutorial::Draw(Game& g) {
	base::Draw(g);
	return true;
}
//画像読み込み関数
void  ModeTutorial::LoadPicture() {
	_grall["1A"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial1.png", 1, 1, 1, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["1A"].data());
	_grall["1B"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial2.png", 1, 1, 1, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["1B"].data());
	_grall["2A"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial3.png", 1, 1, 1, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["2A"].data());
	_grall["3A"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial4.png", 1, 1, 1, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["3A"].data());
	_grall["3B"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial5.png", 1, 1, 1, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["3B"].data());
	_grall["4A"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial6.png", 1, 1, 1, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["4A"].data());
	_grall["5A"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial7.png", 1, 1, 1, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["5A"].data());
}
