
#include <DxLib.h>
#include "ModeGame.h"
#include "Game.h"
#include "Player.h"
#include "MapChip.h"
#include "ModePause.h"
#include "ResourceServer.h"
#include "CPointBlock.h"

using namespace CPInfo;
namespace {
	constexpr auto FIRST_POSITION_X = 200;			//�����������W�i��������j
	constexpr auto FIRST_POSITION_Y = 9360;			//�c���������W�i��������j
}
bool ModeGame::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_enemyspawn = new EnemySpawn(g);
	_gimikplacement = new GimikPlacement(g);
	_eventhappen = new EventHappen(g);
	/*-----------�e�`�F�b�N�|�C���g�ʉ߂ɂ��v���C���[�������W-------------*/
	if (g.GetCPointFlag()["11A"] == true) {
		_Player_x = CPOINT_11A_X;
		_Player_y = CPOINT_11A_Y;
	}
	else if (g.GetCPointFlag()["8A"] == true) {
		_Player_x = CPOINT_8A_X;
		_Player_y = CPOINT_8A_Y;
	}
	else if(g.GetCPointFlag()["5B"] == true){
		_Player_x = CPOINT_5B_X;
		_Player_y = CPOINT_5B_Y;
	}
	else if (g.GetCPointFlag()["5A"] == true) {
		_Player_x = CPOINT_5A_X;
		_Player_y = CPOINT_5A_Y;
	}
	else if (g.GetCPointFlag()["4A"] == true) {
		_Player_x = CPOINT_4A_X;
		_Player_y = CPOINT_4A_Y;
	}
	else if (g.GetCPointFlag()["3A"] == true) {
		_Player_x = CPOINT_3A_X;
		_Player_y = CPOINT_3A_Y;
	}
	else if (g.GetCPointFlag()["2A"] == true) {
		_Player_x = CPOINT_2A_X;
		_Player_y = CPOINT_2A_Y;
	}
	else {
		_Player_x = FIRST_POSITION_X;
		_Player_y = FIRST_POSITION_Y;
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
	_stopObj_Flag = false;
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
	
	return true;
}

bool ModeGame::Draw(Game& g) {
	base::Draw(g);
	_bg.Draw(g);				// �w�i�摜�`��
	g.GetChip()->Draw(g);			//�}�b�v�`�b�v�`��
	g.GetOS()->Draw(g);				// �I�u�W�F�N�g�̕`��
	return true;
}


