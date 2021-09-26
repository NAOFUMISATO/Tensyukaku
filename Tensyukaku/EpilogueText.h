#pragma once
#include "ModeBase.h"

class  EpilogueText :public ModeBase {
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
};
