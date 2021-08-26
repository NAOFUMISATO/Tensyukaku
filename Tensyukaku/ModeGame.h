#pragma once
#include	"ModeBase.h"
#include	"BackGround.h"
#include	"Player.h"
#include	"GimikPlacement.h"
#include	"EnemySpawn.h"



class ModeGame : public ModeBase
{
	typedef ModeBase base;
public:
	virtual bool Initialize(Game& g);
	virtual bool Terminate(Game& g);
	virtual bool Process(Game& g);
	virtual bool Draw(Game& g);


private:
	// オブジェクト処理をストップする
	bool	_stopObjProcess;
	bool	_Player_Apeear;
	// BGM用
	int		_bgm;

	BackGround	_bg;
	GimikPlacement* _gimikplacement;
	EnemySpawn* _enemyspawn;
};