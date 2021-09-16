
#include <DxLib.h>
#include "ModeGame.h"
#include "Game.h"
#include "Player.h"
#include "MapChip.h"
#include "ModePause.h"
#include "ResourceServer.h"
namespace {
	constexpr auto POSITION_X = 4000;			//���������ʒu�i��������j
	constexpr auto POSITION_Y = 9360;			//�c�������ʒu�i��������j
	constexpr auto CPOINT_POSITION_X = 5600;	//�`�F�b�N�|�C���gX���W
	constexpr auto CPOINT_POSITION_Y = 1760;	//�`�F�b�N�|�C���gY���W
}
bool ModeGame::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_enemyspawn = new EnemySpawn(g);
	_gimikplacement = new GimikPlacement(g);
	_eventhappen = new EventHappen(g);
	if (g.GetCPointFlag() == false) {
		PlaySoundMem(g.GetBgm()["Main"], DX_PLAYTYPE_LOOP, true);
		_Player_x = 1500/*POSITION_X*/;
		_Player_y =1760/*POSITION_Y*/;
	}
	else {
		_Player_x = CPOINT_POSITION_X;
		_Player_y = CPOINT_POSITION_Y;
	}
	auto pl = new Player(_Player_x,_Player_y);
	g.GetOS()->Add(pl);
	// �J�������}�b�v������
	g.SetmapW(5760);
	g.SetmapH(9440);
	g.SetcvX(0);
	g.SetcvY(g.GetmapH() - SCREEN_H);
	//�I�u�W�F�N�g�������~�߂�
	_stopObjProcess = false;
	//�|�[�Y��ʂ��o�����Ă��邩
	_Pause_Flag = false;
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

	if (_stopObjProcess==false)
	{
		g.GetChip()->Process(g);
		g.GetOS()->Process(g);
	}
	if (g.GetTrg() & PAD_INPUT_12&&_Pause_Flag==false) {
		_stopObjProcess=true;
		_Pause_Flag = true;
		auto mp = new ModePause();
		g.GetMS()->Add(mp, 2, "Pause");
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


