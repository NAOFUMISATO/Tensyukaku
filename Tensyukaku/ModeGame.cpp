
#include "DxLib.h"
#include "ModeGame.h"
#include "Game.h"
#include "Player.h"
#include "Bushi.h"
#include "Ninja.h"

using namespace Tsk;
bool ModeGame::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }

	// プレイヤーを生成し、オブジェクトサーバに登録する
	g.GetOS()->Add(new Player);
	g.GetOS()->Add(new Bushi);
	g.GetOS()->Add(new Ninja);

	// オブジェクト処理を行う
	_stopObjProcess = false;

	// BGM演奏開始
	_bgm = PlaySoundFile("res/bgm/game_maoudamashii_1_battle35.ogg", DX_PLAYTYPE_LOOP);

	// カメラ＆マップ初期化
	g.SetmapW(SCREEN_W);
	g.SetmapH(10000);
	g.SetcvX(0);
	g.SetcvY(g.GetmapH() - SCREEN_H);

	return true;
}

bool ModeGame::Terminate(Game& g) {
	base::Terminate(g);

	g.GetOS()->Clear();


	return true;
}

bool ModeGame::Process(Game& g) {
	base::Process(g);

	if (_stopObjProcess == false)
	{
		// オブジェクトサーバに登録されているオブジェクトのProcess()を呼び出す
		g.GetOS()->Process(g);
	}

	return true;
}

bool ModeGame::Draw(Game& g) {
	base::Draw(g);

	_bg.Draw(g);				// 背景画像描画
	g.GetOS()->Draw(g);		// オブジェクトの描画

	// 開発用
	/*DrawFormatString(32, 32, GetColor(255, 0, 0), "カメラ x=%d, y=%d", g.GetcvX(), g.GetcvY());*/

	return true;
}

