/*****************************************************************//**
 * \file   ModeGame.h
 * \brief  ���[�h�C���Q�[���N���X�i���[�h�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include	"ModeBase.h"
#include	"BackGround.h"
#include	"Player.h"
#include	"GimikPlacement.h"
#include	"EnemySpawn.h"
#include	"EventHappen.h"

class ModeGame : public ModeBase
{
	typedef ModeBase base;
public:
	//������
	virtual bool Initialize(Game& g);
	//�I��
	virtual bool Terminate(Game& g);
	//�X�V
	virtual bool Process(Game& g);
	//�`��
	virtual bool Draw(Game& g);
	//�I�u�W�F�N�g�����̃X�g�b�v�����Ԃ��֐�
	bool		GetstopObjProcess() { return _stop_obj_process; }
	//�I�u�W�F�N�g�����̃X�g�b�v����̐ݒ�֐�
	void		SetStopObjProcess(bool stopobjprocess) { _stop_obj_process = stopobjprocess; }
	

private:
	int		_player_x;					//�C���X�^���X���������v���C���[�̏���X���W
	int		_player_y;					//�C���X�^���X���������v���C���[�̏���Y���W
	bool		_player_flip;				//�C���X�^���X���������v���C���[�̏������]����
	bool		_stop_obj_process;	//�I�u�W�F�N�g�����̃X�g�b�v����
	BackGround			_bg;							//�w�i�N���X
	GimikPlacement*	_gimikplacement;	//�M�~�b�N�̔z�u�N���X
	EnemySpawn*		_enemyspawn;		//�G�X�|�[���u���b�N�̔z�u�N���X
	EventHappen*		_eventhappen;		//�C�x���g�u���b�N�̔z�u�N���X
};