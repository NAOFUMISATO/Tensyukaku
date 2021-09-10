
#include <DxLib.h>
#include "ModeGame.h"
#include "Game.h"
#include "Player.h"
#include "MapChip.h"
namespace {
	constexpr auto POSITION_X = 4000;			//横軸初期位置（足下が基準）
	constexpr auto POSITION_Y = 7840;			//縦軸初期位置（足下が基準）
	constexpr auto CPOINT_POSITION_X = 3500;	//チェックポイントX座標
	constexpr auto CPOINT_POSITION_Y = 4040;	//チェックポイントY座標
}
bool ModeGame::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_enemyspawn = new EnemySpawn(g);
	_gimikplacement = new GimikPlacement(g);
	_eventhappen = new EventHappen(g);
	if (g.GetCPointFlag() == false) {
		_Player_x = POSITION_X;
		_Player_y = POSITION_Y;
	}
	else {
		_Player_x = CPOINT_POSITION_X;
		_Player_y = CPOINT_POSITION_Y;
	}
	auto pl = new Player(_Player_x,_Player_y);
	g.GetOS()->Add(pl);
	_stopObjProcess = false;
	// カメラ＆マップ初期化
	g.SetmapW(5760);
	g.SetmapH(7920);
	g.SetcvX(0);
	g.SetcvY(g.GetmapH() - SCREEN_H);
	_bgm = PlaySoundFile("bgm/InGame70dB.mp3", DX_PLAYTYPE_LOOP);
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
	if (_stopObjProcess == false)
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

