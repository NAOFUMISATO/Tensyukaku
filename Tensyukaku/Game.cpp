/*****************************************************************//**
 * \file   Game.cpp
 * \brief  ゲームクラス
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Game.h"
#include "ModeTitle.h"
#include "MapChip.h"
#include "Player.h"
#include "ResourceServer.h"

Game::Game()
{
   //初期化
   _gkey = 0;
   _gtrg = 0;
   _xbuf = 0;
   _ybuf = 0;
   _gcnt = 0;
   _cv_x = 0;
   _cv_y = 0;
   _map_w = 0;
   _map_h = 0 ;
   // モードサーバの初期化
   _servermode = new ModeServer(*this);
   // タイトルモードを生成し、モードサーバに登録する
   ModeTitle* modeTitle = new ModeTitle();
   _servermode->Add(modeTitle, 0, "Title");
   //マップチップ指定
   _mapchip = new MapChip("res/Map/", "Tensyukaku");
   //BGM読み込み
   LoadBgm();
   //BGMのボリューム初期値
   VolumeInit();
}

Game::~Game()
{
   delete _servermode;
   delete _mapchip;
}

void Game::Input()
{
   int keyold = _gkey;
   _gkey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
   _gtrg = (_gkey ^ keyold) & _gkey;   // キーのトリガ情報生成（押した瞬間しか反応しないキー情報）
   GetJoypadAnalogInput(&_xbuf, &_ybuf, DX_INPUT_KEY_PAD1);
}

void Game::Process()
{
   VolumeChange();
   _servermode->ProcessInit();
   _servermode->Process();
   _servermode->ProcessFinish();
   _gcnt++;
}

void Game::Draw()
{
   _servermode->DrawInit();
   _servermode->Draw();
   _servermode->DrawFinish();
}

void Game::LoadBgm() {
   _bgm["Prologue"] = ResourceServer::LoadSoundMem("bgm/雅楽待っている.wav");
   _bgm["Title"] = ResourceServer::LoadSoundMem("bgm/Title.wav");
   _bgm["Main"] = ResourceServer::LoadSoundMem("bgm/民謡パワフル.wav");
   _bgm["Epilogue"] = ResourceServer::LoadSoundMem("bgm/雅楽穏やか.wav");
   _bgm["Boss"] = ResourceServer::LoadSoundMem("bgm/BossStage.wav");
   _bgm["Flame"]= ResourceServer::LoadSoundMem("bgm/Flame.wav");
}

void Game::VolumeInit() {
   _vpal["Prologue"] = 80;
   _vpal["Title"] = 255;
   _vpal["Main"] = 0;
   _vpal["Epilogue"] = 80;
   _vpal["Boss"] = 150;
   _vpal["Flame"] = 255;
}

void Game::VolumeChange() {
   ChangeVolumeSoundMem(_vpal["Prologue"], _bgm["Prologue"]);
   ChangeVolumeSoundMem(_vpal["Title"], _bgm["Title"]);
   ChangeVolumeSoundMem(_vpal["Main"], _bgm["Main"]);
   ChangeVolumeSoundMem(_vpal["Epilogue"], _bgm["Epilogue"]);
   ChangeVolumeSoundMem(_vpal["Boss"], _bgm["Boss"]);
   ChangeVolumeSoundMem(_vpal["Flame"], _bgm["Flame"]);
};