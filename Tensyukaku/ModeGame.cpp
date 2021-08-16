
#include "DxLib.h"
#include "ModeGame.h"
#include "Game.h"
#include "Player.h"
#include "Bushi.h"
#include "Ninja.h"
#include "MapChip.h"


bool ModeGame::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }

	//オブジェクトサーバに登録する
	g.GetOS()->Add(new Player);
	g.GetOS()->Add(new Bushi);
	g.GetOS()->Add(new Ninja);
	
	// オブジェクト処理を行う
	_stopObjProcess = false;

	// カメラ＆マップ初期化
	g.SetmapW(3840);
	g.SetmapH(2280);
	g.SetcvX(0);
	g.SetcvY(g.GetmapH() - SCREEN_H);
	// BGM演奏開始	
	/*_bgm = PlaySoundFile("bgm/InGame.mp3", DX_PLAYTYPE_LOOP);*/
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
		
		g.GetChip()->Process(g);
		// オブジェクトサーバに登録されているオブジェクトのProcess()を呼び出す
		g.GetOS()->Process(g);
		
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

