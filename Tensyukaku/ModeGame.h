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


private:
	// �I�u�W�F�N�g�������X�g�b�v����
	bool	_stopObjProcess;
	bool	_Apeear_Flag;
	// BGM�p
	int		_bgm;

	BackGround	_bg;
	GimikPlacement* _gimikplacement;
	EnemySpawn* _enemyspawn;
	EventHappen* _eventhappen;
};