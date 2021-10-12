#pragma once

#include	"ModeBase.h"


class ModeTitle : public ModeBase
{
	typedef ModeBase base;
	enum class TITLETYPE {AMGLOGO,TEAMLOGO,TITLEBG};
public:
	virtual bool Initialize(Game& g);
	virtual bool Terminate(Game& g);
	virtual bool Process(Game& g);
	virtual bool Draw(Game& g);
	void SetTitlebg() { _type = TITLETYPE::TITLEBG; }
	void	SetStopObjProcess(bool stopobjprocess) { _stopObjProcess = stopobjprocess; }
	
private:
	TITLETYPE _type;
	bool	_stopObjProcess;	//オブジェクト処理をストップする
};

namespace MTInfo{
	/*----------AMGロゴ関係---------*/
	constexpr auto AMG_FADEINFRAME = 60;
	constexpr auto AMG_FADESPEED = 5;
	constexpr auto AMG_FADEOUTBEGINFRAME = 90;
	constexpr auto AMG_FADEOUTENDFRAME = 150;
	/*----------TEAMロゴ関係---------*/
	constexpr auto TEAM_FADEINFRAME = 120;
	constexpr auto TEAM_FADESPEED = 3;
	constexpr auto TEAM_FADEOUTBEGINFRAME = 180;
	constexpr auto TEAM_FADEOUTENDFRAME = 300;
	/*----------タイトル背景---------*/
	constexpr auto TITLE_FADEINBEGINFRAME = 120;
	constexpr auto TITLE_FADEINENDFRAME = 240;
	constexpr auto TITLE_FADESPEED = 3;
	constexpr auto GAMESTART_APPEARFRAME = 300;
	constexpr auto EXPLAIN_APPEARFRAME = 315;
	constexpr auto GAMEEND_APPEARFRAME = 345;
	constexpr auto CREDIT_APPEARFRAME = 330;
}
