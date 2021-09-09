
#include <DxLib.h>
#include "ModeGame.h"
#include "Game.h"
#include "Player.h"
#include "MapChip.h"

bool ModeGame::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_enemyspawn = new EnemySpawn(g);
	_gimikplacement = new GimikPlacement(g);
	_eventhappen = new EventHappen(g);
	auto pl = new Player();
	g.GetOS()->Add(pl);
	_stopObjProcess = false;
	// �J�������}�b�v������
	g.SetmapW(5760);
	g.SetmapH(7920);
	g.SetcvX(0);
	g.SetcvY(g.GetmapH() - SCREEN_H);
	_bgm = PlaySoundFile("bgm/InGame70dB.mp3", DX_PLAYTYPE_LOOP);
	return true;
}

bool ModeGame::Terminate(Game& g) {
	base::Terminate(g);
	delete _enemyspawn;
	delete _eventhappen;
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
	}

	return true;
}

bool ModeGame::Draw(Game& g) {
	base::Draw(g);
	_bg.Draw(g);				// �w�i�摜�`��
	g.GetChip()->Draw(g);			//�}�b�v�`�b�v�`��
	g.GetOS()->Draw(g);				// �I�u�W�F�N�g�̕`��
	return true;
}

