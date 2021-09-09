#pragma once
#include "ObjectBase.h"

class OverBlack :public ObjectBase {
public:
	OverBlack();
	~OverBlack();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::OVERBLACK; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;

};