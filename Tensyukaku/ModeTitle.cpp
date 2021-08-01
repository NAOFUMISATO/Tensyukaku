
#include "DxLib.h"
#include "ModeTitle.h"
#include "ModeGame.h"
#include "Game.h"
#include "ResourceServer.h"

using namespace Tsk;
bool ModeTitle::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }

	// タイトル画像のロード
	_cgTitle = ResourceServer::LoadGraph("res/title.png");

	return true;
}

bool ModeTitle::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool ModeTitle::Process(Game& g) {
	base::Process(g);

	if (g.GetTrg() & PAD_INPUT_A)
	{
		// このモードを削除
		g.GetMS()->Del(this);

		// ゲームモードを追加
		ModeGame* modeGame = new ModeGame();
		g.GetMS()->Add(modeGame, 0, "Game");
	}


	return true;
}

bool ModeTitle::Draw(Game& g) {
	base::Draw(g);

	DrawGraph(0, 0, _cgTitle, FALSE);

	return true;
}

