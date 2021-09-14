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
	void	SetStopObjProcess(bool stopobjprocess) { _stopObjProcess = stopobjprocess; }
	
private:
	TITLETYPE _Type;
	bool	_stopObjProcess;	//�I�u�W�F�N�g�������X�g�b�v����

};

