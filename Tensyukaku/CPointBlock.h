#pragma once
#include "ObjectBase.h"

class CPointBlock :public ObjectBase {
public:
	CPointBlock(int x, int y);
	~CPointBlock();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::CPOINTBLOCK; }
	void Init()override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
};