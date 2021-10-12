/*****************************************************************//**
 * \file   ModeGame.h
 * \brief  モードインゲームクラス（モードベースクラスのサブクラス）
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
	//初期化
	virtual bool Initialize(Game& g);
	//終了
	virtual bool Terminate(Game& g);
	//更新
	virtual bool Process(Game& g);
	//描画
	virtual bool Draw(Game& g);
	//オブジェクト処理のストップ判定を返す関数
	bool		GetstopObjProcess() { return _stop_obj_process; }
	//オブジェクト処理のストップ判定の設定関数
	void		SetStopObjProcess(bool stopobjprocess) { _stop_obj_process = stopobjprocess; }
	

private:
	int		_player_x;					//インスタンス生成されるプレイヤーの初期X座標
	int		_player_y;					//インスタンス生成されるプレイヤーの初期Y座標
	bool		_player_flip;				//インスタンス生成されるプレイヤーの初期反転判定
	bool		_stop_obj_process;	//オブジェクト処理のストップ判定
	BackGround			_bg;							//背景クラス
	GimikPlacement*	_gimikplacement;	//ギミックの配置クラス
	EnemySpawn*		_enemyspawn;		//敵スポーンブロックの配置クラス
	EventHappen*		_eventhappen;		//イベントブロックの配置クラス
};