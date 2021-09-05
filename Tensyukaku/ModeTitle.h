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
private:
	TITLETYPE _Type;
};

