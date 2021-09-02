
#include <DxLib.h>
#include "Game.h"
#include "ModeTitle.h"
#include "MapChip.h"


// �A�v���̏�����
// �N������1�񂾂����s�����
Game::Game()
{
	_gKey = 0;
	_gTrg = 0;
	_Xbuf = 0;
	_Ybuf = 0;
	_gCnt = 0;
	// ���[�h�T�[�o�̏�����
	_serverMode = new ModeServer(*this);
	// �^�C�g�����[�h�𐶐����A���[�h�T�[�o�ɓo�^����
	ModeTitle* modeTitle = new ModeTitle();
	_serverMode->Add(modeTitle, 0, "Title");
	//�}�b�v�`�b�v�w��
	_mapChip = new MapChip("res/Map/", "Tensyukaku");
}

// �A�v���̉��
// �I������1�񂾂����s�����
Game::~Game()
{
	delete _serverMode;
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

