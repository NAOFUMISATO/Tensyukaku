
#include <DxLib.h>
#include "Game.h"
#include "ModeTitle.h"
#include "MapChip.h"
#include "Player.h"
#include "ResourceServer.h"


// �A�v���̏�����
// �N������1�񂾂����s�����
Game::Game()
{
	_gkey = 0;
	_gtrg = 0;
	_xbuf = 0;
	_ybuf = 0;
	_gcnt = 0;
	_cv_x = 0;
	_cv_y = 0;
	_map_w = 0;
	_map_h = 0 ;
	// ���[�h�T�[�o�̏�����
	_servermode = new ModeServer(*this);
	// �^�C�g�����[�h�𐶐����A���[�h�T�[�o�ɓo�^����
	ModeTitle* modeTitle = new ModeTitle();
	_servermode->Add(modeTitle, 0, "Title");
	//�}�b�v�`�b�v�w��
	_mapchip = new MapChip("res/Map/", "Tensyukaku");
	//BGM�ǂݍ���
	LoadBgm();
	//BGM�̃{�����[�������l
	VolumeInit();
}

// �A�v���̉��
// �I������1�񂾂����s�����
Game::~Game()
{
	delete _servermode;
	delete _mapchip;
}



//
// �t���[�������B1�t���[����1�񂸂��s�����
//

// �t���[�������F����
void Game::Input()
{
	int keyold = _gkey;
	_gkey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	_gtrg = (_gkey ^ keyold) & _gkey;	// �L�[�̃g���K��񐶐��i�������u�Ԃ����������Ȃ��L�[���j
	GetJoypadAnalogInput(&_xbuf, &_ybuf, DX_INPUT_KEY_PAD1);
}

// �t���[�������F�v�Z
void Game::Process()
{
	VolumeChange();
	_servermode->ProcessInit();
	_servermode->Process();
	_servermode->ProcessFinish();
	_gcnt++;
}

// �t���[�������F�`��
void Game::Draw()
{
	_servermode->DrawInit();
	_servermode->Draw();
	_servermode->DrawFinish();
}
// BGM�ǂݍ���
void Game::LoadBgm() {
	_bgm["Prologue"] = ResourceServer::LoadSoundMem("bgm/��y�҂��Ă���.wav");
	_bgm["Title"] = ResourceServer::LoadSoundMem("bgm/Title.wav");
	_bgm["Main"] = ResourceServer::LoadSoundMem("bgm/���w�p���t��.wav");
	_bgm["Epilogue"] = ResourceServer::LoadSoundMem("bgm/��y���₩.wav");
	_bgm["Boss"] = ResourceServer::LoadSoundMem("bgm/BossStage.wav");
	_bgm["Flame"]= ResourceServer::LoadSoundMem("bgm/Flame.wav");
}
//BGM�̃{�����[�������l
void	Game::VolumeInit() {
	_vpal["Prologue"] = 80;
	_vpal["Title"] = 255;
	_vpal["Main"] = 0;
	_vpal["Epilogue"] = 80;
	_vpal["Boss"] = 150;
	_vpal["Flame"] = 255;
}

//BGM�̃{�����[���ύX�֐�
void	Game::VolumeChange() {
	ChangeVolumeSoundMem(_vpal["Prologue"], _bgm["Prologue"]);
	ChangeVolumeSoundMem(_vpal["Title"], _bgm["Title"]);
	ChangeVolumeSoundMem(_vpal["Main"], _bgm["Main"]);
	ChangeVolumeSoundMem(_vpal["Epilogue"], _bgm["Epilogue"]);
	ChangeVolumeSoundMem(_vpal["Boss"], _bgm["Boss"]);
	ChangeVolumeSoundMem(_vpal["Flame"], _bgm["Flame"]);
};