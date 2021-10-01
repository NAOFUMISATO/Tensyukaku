#pragma once
#include "ModeBase.h"

class  ModeTutorial :public ModeBase {
	typedef ModeBase base;
public:
	virtual bool Initialize(Game& g);
	virtual bool Terminate(Game& g);
	virtual bool Process(Game& g);
	virtual bool Draw(Game& g);
	void SetType(std::string tutorialtype) { _tutorial_type = tutorialtype; }
private:
	void LoadTextGraph();
	std::string	_tutorial_type;
};

namespace TuInfo {
	constexpr auto GRAPH_WIDTH = 880;
	constexpr auto GRAPH_HEIGHT = 470;
}