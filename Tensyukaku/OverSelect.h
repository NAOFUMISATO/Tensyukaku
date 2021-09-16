#pragma once
#include "ModeBase.h"

class OverSelect :public ModeBase {
	typedef ModeBase base;
public:
	virtual bool Initialize(Game& g);
	virtual bool Terminate(Game& g);
	virtual bool Process(Game& g);
	virtual bool Draw(Game& g);
private:
	enum class SELECTTYPE {
		NOSELECT, RETRYSELECT, GOTITLESELECT
	};
	SELECTTYPE _Type;
	int _GraphNo;
};