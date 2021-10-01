#pragma once
#include "ModeBase.h"

class ModeCredit :public ModeBase {
	typedef ModeBase base;
public:
	virtual bool Initialize(Game& g);
	virtual bool Terminate(Game& g);
	virtual bool Process(Game& g);
	virtual bool Draw(Game& g);
private:
	bool _leftmove_flag;
	bool _rightmove_flag;
	bool _start_flag;
	bool _end_flag;
};

class Guide:public ModeBase {
	typedef ModeBase base;
public:
	virtual bool Initialize(Game& g);
	virtual bool Terminate(Game& g);
	virtual bool Process(Game& g);
	virtual bool Draw(Game& g);
};

class RedReturn :public ModeBase {
	typedef ModeBase base;
public:
	virtual bool Initialize(Game& g);
	virtual bool Terminate(Game& g);
	virtual bool Process(Game& g);
	virtual bool Draw(Game& g);
};
namespace CrInfo {
	constexpr auto FADE_FRAME = 60;
	constexpr auto  FADE_SPEED = 5;
}