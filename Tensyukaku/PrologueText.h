#pragma once
#include "ModeBase.h"

class  PrologueText :public ModeBase {
	typedef ModeBase base;
public:
	virtual bool Initialize(Game& g);
	virtual bool Terminate(Game& g);
	virtual bool Process(Game& g);
	virtual bool Draw(Game& g);
private:
	void		LoadSE();
	void		VolumeInit();
	void		VolumeChange();

	int		_GraphNo;
	bool	_Skip_Flag;
};

class  PrologueASkip :public ModeBase {
	typedef ModeBase base;
public:
	virtual bool Initialize(Game& g);
	virtual bool Terminate(Game& g);
	virtual bool Process(Game& g);
	virtual bool Draw(Game& g);
};