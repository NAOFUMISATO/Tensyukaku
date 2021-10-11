/*****************************************************************//**
 * \file   ModeGame.cpp
 * \brief  ���[�h�C���Q�[���N���X�i���[�h�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
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
/*-------������--------*/
bool ModeGame::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_enemyspawn = new EnemySpawn(g);								//�G�X�|�[���u���b�N�N���X����
	_gimikplacement = new GimikPlacement(g);					//�M�~�b�N�I�u�W�F�N�g�N���X����
	_eventhappen = new EventHappen(g);								//�C�x���g�u���b�N�N���X����
	/*-----------�e�`�F�b�N�|�C���g�ʉ߂ɂ��v���C���[�������W-------------*/
	if (g.GetCPointFlag()["11A"] == true) {
		_player_x = CPOINT_11A_X;
		_player_y = CPOINT_11A_Y;
		_player_flip = false;
	}
	else if (g.GetCPointFlag()["8A"] == true) {
		_player_x = CPOINT_8A_X;
		_player_y = CPOINT_8A_Y;
		_player_flip = true;
	}
	else if(g.GetCPointFlag()["5B"] == true){
		_player_x = CPOINT_5B_X;
		_player_y = CPOINT_5B_Y;
		_player_flip = true;
	}
	else if (g.GetCPointFlag()["5A"] == true) {
		_player_x = CPOINT_5A_X;
		_player_y = CPOINT_5A_Y;
		_player_flip = true;
	}
	else if (g.GetCPointFlag()["4A"] == true) {
		_player_x = CPOINT_4A_X;
		_player_y = CPOINT_4A_Y;
		_player_flip = false;
	}
	else if (g.GetCPointFlag()["3A"] == true) {
		_player_x = CPOINT_3A_X;
		_player_y = CPOINT_3A_Y;
		_player_flip = true;
	}
	else if (g.GetCPointFlag()["2A"] == true) {
		_player_x = CPOINT_2A_X;
		_player_y = CPOINT_2A_Y;
		_player_flip = false;
	}
	else {
		_player_x = FIRST_POSITION_X;
		_player_y = FIRST_POSITION_Y;
		_player_flip = true;
	}
	auto pl = new Player(_player_x,_player_y,_player_flip);			//�v���C���[����
	g.GetOS()->Add(pl);
	// �J�������}�b�v������
	g.SetmapW(5760);
	g.SetmapH(9440);
	g.SetcvX(0);
	g.SetcvY(g.GetmapH() - SCREEN_H);
	//�I�u�W�F�N�g�������~�߂�t���O���U�ŏ�����
	_stopObjProcess = false;
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
/*-------�X�V--------*/
bool ModeGame::Process(Game& g) {
	base::Process(g);
	//�I�u�W�F�N�g�������~�߂�t���O���U�Ȃ�}�b�v�`�b�v�y�уI�u�W�F�N�g�̏������X�V����
	if (_stopObjProcess==false)
	{
		g.GetChip()->Process(g);
		g.GetOS()->Process(g);
	}
	return true;
}
/*-------�`��--------*/
bool ModeGame::Draw(Game& g) {
	base::Draw(g);
	_bg.Draw(g);								// �w�i�摜�`��
	g.GetChip()->Draw(g);			//�}�b�v�`�b�v�`��
	g.GetOS()->Draw(g);				// �I�u�W�F�N�g�̕`��
	return true;
}


