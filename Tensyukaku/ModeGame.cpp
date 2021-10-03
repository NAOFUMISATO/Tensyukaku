
#include <DxLib.h>
#include "ModeGame.h"
#include "Game.h"
#include "Player.h"
#include "MapChip.h"
#include "ModePause.h"
#include "ResourceServer.h"
#include "CPointBlock.h"

using namespace CPInfo;
namespace {
	constexpr auto FIRST_POSITION_X = 200;			//横軸初期座標（足下が基準）
	constexpr auto FIRST_POSITION_Y = 9360;			//縦軸初期座標（足下が基準）
}
bool ModeGame::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_enemyspawn = new EnemySpawn(g);
	_gimikplacement = new GimikPlacement(g);
	_eventhappen = new EventHappen(g);
	/*-----------各チェックポイント通過によるプレイヤー初期座標-------------*/
	if (g.GetCPointFlag()["11A"] == true) {
		_player_x = CPOINT_11A_X;
		_player_y = CPOINT_11A_Y;
		_player_flip = false;
	}
	else if (g.GetCPointFlag()["8A"] == true) {
		_player_x = CPOINT_8A_X;
		_player_y = CPOINT_8A_Y;
		_player_flip = true;
	}
	else if(g.GetCPointFlag()["5B"] == true){
		_player_x = CPOINT_5B_X;
		_player_y = CPOINT_5B_Y;
		_player_flip = true;
	}
	else if (g.GetCPointFlag()["5A"] == true) {
		_player_x = CPOINT_5A_X;
		_player_y = CPOINT_5A_Y;
		_player_flip = true;
	}
	else if (g.GetCPointFlag()["4A"] == true) {
		_player_x = CPOINT_4A_X;
		_player_y = CPOINT_4A_Y;
		_player_flip = false;
	}
	else if (g.GetCPointFlag()["3A"] == true) {
		_player_x = CPOINT_3A_X;
		_player_y = CPOINT_3A_Y;
		_player_flip = true;
	}
	else if (g.GetCPointFlag()["2A"] == true) {
		_player_x = CPOINT_2A_X;
		_player_y = CPOINT_2A_Y;
		_player_flip = false;
	}
	else {
		_player_x = FIRST_POSITION_X;
		_player_y = FIRST_POSITION_Y;
		_player_flip = true;
	}
	auto pl = new Player(_player_x,_player_y,_player_flip);
	g.GetOS()->Add(pl);
	// カメラ＆マップ初期化
	g.SetmapW(5760);
	g.SetmapH(9440);
	g.SetcvX(0);
	g.SetcvY(g.GetmapH() - SCREEN_H);
	//オブジェクト処理を止める
	_stopObjProcess = false;
	//ポーズ画面が出現しているか
	_stopObj_Flag = false;
	return true;
}

bool ModeGame::Terminate(Game& g) {
	base::Terminate(g);
	delete _enemyspawn;
	delete _eventhappen;
	delete _gimikplacement;
	g.GetOS()->Clear();
	return true;
}

bool ModeGame::Process(Game& g) {
	base::Process(g);

	if (_stopObjProcess==false)
	{
		g.GetChip()->Process(g);
		g.GetOS()->Process(g);
	}
	
	return true;
}

bool ModeGame::Draw(Game& g) {
	base::Draw(g);
	_bg.Draw(g);				// 背景画像描画
	g.GetChip()->Draw(g);			//マップチップ描画
	g.GetOS()->Draw(g);				// オブジェクトの描画
	return true;
}


