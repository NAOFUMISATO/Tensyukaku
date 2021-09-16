
#include <DxLib.h>
#include "ModeGame.h"
#include "Game.h"
#include "Player.h"
#include "MapChip.h"
#include "ModePause.h"
#include "ResourceServer.h"
namespace {
	constexpr auto POSITION_X = 4000;			//横軸初期位置（足下が基準）
	constexpr auto POSITION_Y = 9360;			//縦軸初期位置（足下が基準）
	constexpr auto CPOINT_POSITION_X = 5600;	//チェックポイントX座標
	constexpr auto CPOINT_POSITION_Y = 1760;	//チェックポイントY座標
}
bool ModeGame::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_enemyspawn = new EnemySpawn(g);
	_gimikplacement = new GimikPlacement(g);
	_eventhappen = new EventHappen(g);
	if (g.GetCPointFlag() == false) {
		PlaySoundMem(g.GetBgm()["Main"], DX_PLAYTYPE_LOOP, true);
		_Player_x = 1500/*POSITION_X*/;
		_Player_y =1760/*POSITION_Y*/;
	}
	else {
		_Player_x = CPOINT_POSITION_X;
		_Player_y = CPOINT_POSITION_Y;
	}
	auto pl = new Player(_Player_x,_Player_y);
	g.GetOS()->Add(pl);
	// カメラ＆マップ初期化
	g.SetmapW(5760);
	g.SetmapH(9440);
	g.SetcvX(0);
	g.SetcvY(g.GetmapH() - SCREEN_H);
	//オブジェクト処理を止める
	_stopObjProcess = false;
	//ポーズ画面が出現しているか
	_Pause_Flag = false;
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
	if (g.GetTrg() & PAD_INPUT_12&&_Pause_Flag==false) {
		_stopObjProcess=true;
		_Pause_Flag = true;
		auto mp = new ModePause();
		g.GetMS()->Add(mp, 2, "Pause");
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


