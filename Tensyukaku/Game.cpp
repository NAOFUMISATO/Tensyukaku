
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
	_gKey = 0;
	_gTrg = 0;
	_Xbuf = 0;
	_Ybuf = 0;
	_gCnt = 0;
	_cvX = 0;
	_cvY = 0;
	_mapW = 0;
	_mapH = 0 ;
	// ���[�h�T�[�o�̏�����
	_serverMode = new ModeServer(*this);
	// �^�C�g�����[�h�𐶐����A���[�h�T�[�o�ɓo�^����
	ModeTitle* modeTitle = new ModeTitle();
	_serverMode->Add(modeTitle, 0, "Title");
	//�}�b�v�`�b�v�w��
	_mapChip = new MapChip("res/Map/", "Tensyukaku");
	//BGM�ǂݍ���
	LoadBgm();
	//BGM�̃{�����[�������l
	VolumeInit();
}

// �A�v���̉��
// �I������1�񂾂����s�����
Game::~Game()
{
	delete _serverMode;
	delete _mapChip;
}



//
// �t���[�������B1�t���[����1�񂸂��s�����
//

// �t���[�������F����
void Game::Input()
{
	int keyold = _gKey;
	_gKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	_gTrg = (_gKey ^ keyold) & _gKey;	// �L�[�̃g���K��񐶐��i�������u�Ԃ����������Ȃ��L�[���j
	GetJoypadAnalogInput(&_Xbuf, &_Ybuf, DX_INPUT_KEY_PAD1);
}

// �t���[�������F�v�Z
void Game::Process()
{
	VolumeChange();
	_serverMode->ProcessInit();
	_serverMode->Process();
	_serverMode->ProcessFinish();
	_gCnt++;
}

// �t���[�������F�`��
void Game::Draw()
{
	_serverMode->DrawInit();
	_serverMode->Draw();
	_serverMode->DrawFinish();
}
// BGM�ǂݍ���
void Game::LoadBgm() {
	_Bgm["Title"] = ResourceServer::LoadSoundMem("bgm/Title.wav");
	_Bgm["Main"] = ResourceServer::LoadSoundMem("bgm/���w�p���t��.wav");
	_Bgm["Boss"] = ResourceServer::LoadSoundMem("bgm/BossStage.wav");
	_Bgm["Flame"]= ResourceServer::LoadSoundMem("bgm/Flame.wav");
}
//BGM�̃{�����[�������l
void	Game::VolumeInit() {
	_Vpal["Title"] = 255;
	_Vpal["Main"] = 150;
	_Vpal["Boss"] = 150;
	_Vpal["Flame"] = 255;
}

//BGM�̃{�����[���ύX�֐�
void	Game::VolumeChange() {
	ChangeVolumeSoundMem(_Vpal["Title"], _Bgm["Title"]);
	ChangeVolumeSoundMem(_Vpal["Main"], _Bgm["Main"]);
	ChangeVolumeSoundMem(_Vpal["Boss"], _Bgm["Boss"]);
	ChangeVolumeSoundMem(_Vpal["Flame"], _Bgm["Flame"]);
};