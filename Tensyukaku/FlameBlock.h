#pragma once

#include "ObjectBase.h"

class FlameBlock :public ObjectBase {
public:
	FlameBlock(int x, int y);
	~FlameBlock();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::FLAMEBLOCK; }
	void Init()override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
};