
#include <DxLib.h>
#include "Game.h"
#include "ModeTitle.h"
#include "MapChip.h"
#include "Player.h"
#include "ResourceServer.h"


// アプリの初期化
// 起動時に1回だけ実行される
Game::Game()
{
	_gKey = 0;
	_gTrg = 0;
	_Xbuf = 0;
	_Ybuf = 0;
	_gCnt = 0;
	_cvX = 0;
	_cvY = 0;
	_mapW = 0;
	_mapH = 0 ;
	// モードサーバの初期化
	_serverMode = new ModeServer(*this);
	// タイトルモードを生成し、モードサーバに登録する
	ModeTitle* modeTitle = new ModeTitle();
	_serverMode->Add(modeTitle, 0, "Title");
	//マップチップ指定
	_mapChip = new MapChip("res/Map/", "Tensyukaku");
	//BGM読み込み
	LoadBgm();
	//BGMのボリューム初期値
	VolumeInit();
}

// アプリの解放
// 終了時に1回だけ実行される
Game::~Game()
{
	delete _serverMode;
	delete _mapChip;
}



//
// フレーム処理。1フレームに1回ずつ実行される
//

// フレーム処理：入力
void Game::Input()
{
	int keyold = _gKey;
	_gKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	_gTrg = (_gKey ^ keyold) & _gKey;	// キーのトリガ情報生成（押した瞬間しか反応しないキー情報）
	GetJoypadAnalogInput(&_Xbuf, &_Ybuf, DX_INPUT_KEY_PAD1);
}

// フレーム処理：計算
void Game::Process()
{
	VolumeChange();
	_serverMode->ProcessInit();
	_serverMode->Process();
	_serverMode->ProcessFinish();
	_gCnt++;
}

// フレーム処理：描画
void Game::Draw()
{
	_serverMode->DrawInit();
	_serverMode->Draw();
	_serverMode->DrawFinish();
}
// BGM読み込み
void Game::LoadBgm() {
	_Bgm["Title"] = ResourceServer::LoadSoundMem("bgm/Title.wav");
	_Bgm["Main"] = ResourceServer::LoadSoundMem("bgm/民謡パワフル.wav");
	_Bgm["Boss"] = ResourceServer::LoadSoundMem("bgm/BossStage.wav");
	_Bgm["Flame"]= ResourceServer::LoadSoundMem("bgm/Flame.wav");
}
//BGMのボリューム初期値
void	Game::VolumeInit() {
	_Vpal["Title"] = 255;
	_Vpal["Main"] = 150;
	_Vpal["Boss"] = 150;
	_Vpal["Flame"] = 255;
}

//BGMのボリューム変更関数
void	Game::VolumeChange() {
	ChangeVolumeSoundMem(_Vpal["Title"], _Bgm["Title"]);
	ChangeVolumeSoundMem(_Vpal["Main"], _Bgm["Main"]);
	ChangeVolumeSoundMem(_Vpal["Boss"], _Bgm["Boss"]);
	ChangeVolumeSoundMem(_Vpal["Flame"], _Bgm["Flame"]);
};