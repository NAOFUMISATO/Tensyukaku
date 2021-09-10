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
	void SetStopProcess(bool stopprocess) { _stopObjProcess = stopprocess; }


private:
	// オブジェクト処理をストップする
	bool	_stopObjProcess;
	// BGM用
	int		_bgm;
	int		_Player_x;
	int		_Player_y;
	BackGround	_bg;
	GimikPlacement* _gimikplacement;
	EnemySpawn* _enemyspawn;
	EventHappen* _eventhappen;
};