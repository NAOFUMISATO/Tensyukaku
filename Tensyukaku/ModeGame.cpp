
#include "DxLib.h"
#include "ModeGame.h"
#include "Game.h"
#include "Player.h"
#include "Bushi.h"
#include "Ninja.h"
#include "MapChip.h"
#include "Stair.h"
#include "Shielder.h"
#include "GimikPlacement.h"
#include "EnemySpawn.h"
#include <memory>

bool ModeGame::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_enemyspawn = new EnemySpawn(g);
	_gimikplacement = new GimikPlacement(g);
	_Apeear_Flag = false;
	// オブジェクト処理を行う
	_stopObjProcess = false;
	
	// カメラ＆マップ初期化
	g.SetmapW(5760);
	g.SetmapH(7920);
	g.SetcvX(0);
	g.SetcvY(g.GetmapH() - SCREEN_H);
	// BGM演奏開始	
	_bgm = PlaySoundFile("bgm/InGame70dB.mp3", DX_PLAYTYPE_LOOP);
	return true;
}

bool ModeGame::Terminate(Game& g) {
	base::Terminate(g);
	delete g.GetChip();
	delete _enemyspawn;
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
		if (_Apeear_Flag == false) {
		_Apeear_Flag = true;
		_gimikplacement->Process(g);
		_enemyspawn->Process(g);
		g.GetOS()->Add(new Player);
		}
		
	}

	return true;
}

bool ModeGame::Draw(Game& g) {
	base::Draw(g);
	
	_bg.Draw(g);				// 背景画像描画
	g.GetChip()->Draw();			//マップチップ描画
	g.GetOS()->Draw(g);				// オブジェクトの描画

	// 開発用
	/*DrawFormatString(32, 32, GetColor(255, 0, 0), "カメラ x=%d, y=%d", g.GetcvX(), g.GetcvY());*/

	return true;
}

