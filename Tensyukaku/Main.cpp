#include "DxLib.h"
#include <stdio.h>
#include <time.h>
#include "game.h"
#include "ResourceServer.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow)
{
	// 初期化 -------------------------------------------------------------------------
	// ＤＸライブラリ初期化処理
	SetGraphMode(SCREEN_W, SCREEN_H, SCREEN_DEPTH);
	ChangeWindowMode(true);							// ウィンドウモードに指定する
	if (DxLib_Init() == -1)
	{	// エラーが起きたら直ちに終了
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);		// 描画先画面を裏画面にセット

	// 乱数初期化
	srand((unsigned int)time(NULL));

	// リソースサーバ初期化
	ResourceServer::Init();

	// ゲームクラス
	Game* g = new Game();

	// 1フレームループを組む ----------------------------------------------------------
	while (ProcessMessage() == 0)		// プログラムが終了するまでループ
	{
#ifdef _DEBUG
		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
			break;
		}
#endif
		g->Input();		// 入力
		g->Process();	// 計算
		g->Draw();		// 描画
	}

	// 解放 ---------------------------------------------------------------------------
	ResourceServer::Release();	// リソースサーバ解放

	delete g;			// ゲームクラスの解放

	DxLib_End();		// ＤＸライブラリ使用の終了処理

	// 終了
	
	return 0;
}