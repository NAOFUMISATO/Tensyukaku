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

