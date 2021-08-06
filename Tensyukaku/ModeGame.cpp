
#include "DxLib.h"
#include "ModeGame.h"
#include "Game.h"
#include "Player.h"
#include "Bushi.h"
#include "Ninja.h"

using namespace Tsk;
bool ModeGame::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }

	// �v���C���[�𐶐����A�I�u�W�F�N�g�T�[�o�ɓo�^����
	g.GetOS()->Add(new Player);
	g.GetOS()->Add(new Bushi);
	g.GetOS()->Add(new Ninja);

	// �I�u�W�F�N�g�������s��
	_stopObjProcess = false;

	// BGM���t�J�n
	_bgm = PlaySoundFile("res/bgm/game_maoudamashii_1_battle35.ogg", DX_PLAYTYPE_LOOP);

	// �J�������}�b�v������
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
		// �I�u�W�F�N�g�T�[�o�ɓo�^����Ă���I�u�W�F�N�g��Process()���Ăяo��
		g.GetOS()->Process(g);
	}

	return true;
}

bool ModeGame::Draw(Game& g) {
	base::Draw(g);

	_bg.Draw(g);				// �w�i�摜�`��
	g.GetOS()->Draw(g);		// �I�u�W�F�N�g�̕`��

	// �J���p
	/*DrawFormatString(32, 32, GetColor(255, 0, 0), "�J���� x=%d, y=%d", g.GetcvX(), g.GetcvY());*/

	return true;
}

