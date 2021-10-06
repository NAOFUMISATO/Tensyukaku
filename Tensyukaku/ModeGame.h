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
	bool		GetstopObjProcess() { return _stopObjProcess; }
	void		SetStopObjProcess(bool stopobjprocess) { _stopObjProcess = stopobjprocess; }
	

private:
	bool	_stopObjProcess;	//オブジェクト処理をストップする
	// BGM用
	int		_bgm;
	int		_player_x;
	int		_player_y;
	bool  _player_flip;
	BackGround	_bg;
	GimikPlacement* _gimikplacement;
	EnemySpawn* _enemyspawn;
	EventHappen* _eventhappen;
};