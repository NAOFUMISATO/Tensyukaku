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
	virtual bool Initialize(Game& g);
	virtual bool Terminate(Game& g);
	virtual bool Process(Game& g);
	virtual bool Draw(Game& g);
	void	SetStopObjProcess(bool stopobjprocess) { _stopObjProcess = stopobjprocess; }
	void	SetPauseFlag(bool pauseflag) { _Pause_Flag = pauseflag; }
	void	LoadSound();

private:
	bool	_stopObjProcess;	//�I�u�W�F�N�g�������X�g�b�v����
	bool	_Pause_Flag;		//�|�[�Y��ʂ��o�����Ă��邩�̃t���O
	// BGM�p
	int		_bgm;
	int		_Player_x;
	int		_Player_y;
	BackGround	_bg;
	GimikPlacement* _gimikplacement;
	EnemySpawn* _enemyspawn;
	EventHappen* _eventhappen;
};