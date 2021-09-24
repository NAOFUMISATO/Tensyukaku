#pragma once
#include "ModeBase.h"
class  ModeTutorial :public ModeBase {
	typedef ModeBase base;
public:
	virtual bool Initialize(Game& g);
	virtual bool Terminate(Game& g);
	virtual bool Process(Game& g);
	virtual bool Draw(Game& g);
	void SetNum(int num) { _TutorialNum = num; }
private:
	void LoadTextGraph();

	int	_TutorialNum;
	bool	_Return_Flag;
};