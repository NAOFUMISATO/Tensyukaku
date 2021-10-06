#pragma once
#include "ModeBase.h"

class PauseSelect :public ModeBase {
	typedef ModeBase base;
public:
	virtual bool Initialize(Game& g);
	virtual bool Terminate(Game& g);
	virtual bool Process(Game& g);
	virtual bool Draw(Game& g);
private:
	enum class SELECTTYPE {
	NOSELECT,RETURNSELECT,GOTITLESELECT
	};
	SELECTTYPE _type;
	int _graph_no;
	bool _input_flag;
};