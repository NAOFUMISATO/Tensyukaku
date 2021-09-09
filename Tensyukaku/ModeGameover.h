#pragma once

#include	"ModeBase.h"


class ModeGameover : public ModeBase
{
	typedef ModeBase base;
	enum class TITLETYPE { AMGLOGO, TEAMLOGO, TITLEBG };
public:
	virtual bool Initialize(Game& g);
	virtual bool Terminate(Game& g);
	virtual bool Process(Game& g);
	virtual bool Draw(Game& g);
};

