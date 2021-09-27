#pragma once
#include "ModeBase.h"

class ModeBossBefore :public ModeBase {
	typedef ModeBase base;
public:
	virtual bool Initialize(Game& g);
	virtual bool Terminate(Game& g);
	virtual bool Process(Game& g);
	virtual bool Draw(Game& g);
};

namespace BBInfo {
	constexpr auto VOICE_FRAME = 180;
	constexpr auto FADEOUT_FRAME = 540;
}