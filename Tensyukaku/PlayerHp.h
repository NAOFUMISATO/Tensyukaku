#pragma once
#include "ObjectBase.h"


class PlayerHp :public ObjectBase {
public:
	PlayerHp();
	~PlayerHp();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::UI; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};