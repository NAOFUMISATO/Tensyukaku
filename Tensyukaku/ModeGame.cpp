
#include "DxLib.h"
#include "ModeGame.h"
#include "Game.h"
#include "Player.h"
#include "Bushi.h"
#include "Ninja.h"
#include "MapChip.h"
#include "Stair.h"
#include "Shielder.h"
#include "GimikPlacement.h"
#include "EnemySpawn.h"
#include <memory>

bool ModeGame::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_enemyspawn = new EnemySpawn(g);
	_gimikplacement = new GimikPlacement(g);
	_Apeear_Flag = false;
	// �I�u�W�F�N�g�������s��
	_stopObjProcess = false;
	
	// �J�������}�b�v������
	g.SetmapW(5760);
	g.SetmapH(7920);
	g.SetcvX(0);
	g.SetcvY(g.GetmapH() - SCREEN_H);
	// BGM���t�J�n	
	_bgm = PlaySoundFile("bgm/InGame70dB.mp3", DX_PLAYTYPE_LOOP);
	return true;
}

bool ModeGame::Terminate(Game& g) {
	base::Terminate(g);
	delete g.GetChip();
	delete _enemyspawn;
	delete _gimikplacement;
	g.GetOS()->Clear();
	return true;
}

bool ModeGame::Process(Game& g) {
	base::Process(g);
	if (_stopObjProcess == false)
	{
		g.GetChip()->Process(g);
		g.GetOS()->Process(g);
		if (_Apeear_Flag == false) {
		_Apeear_Flag = true;
		_gimikplacement->Process(g);
		_enemyspawn->Process(g);
		g.GetOS()->Add(new Player);
		}
		
	}

	return true;
}

bool ModeGame::Draw(Game& g) {
	base::Draw(g);
	
	_bg.Draw(g);				// �w�i�摜�`��
	g.GetChip()->Draw();			//�}�b�v�`�b�v�`��
	g.GetOS()->Draw(g);				// �I�u�W�F�N�g�̕`��

	// �J���p
	/*DrawFormatString(32, 32, GetColor(255, 0, 0), "�J���� x=%d, y=%d", g.GetcvX(), g.GetcvY());*/

	return true;
}

