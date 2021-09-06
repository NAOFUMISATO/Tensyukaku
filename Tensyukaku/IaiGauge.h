#pragma once
#include "ObjectBase.h"

class IaiGauge :public ObjectBase {
public:
	IaiGauge();
	~IaiGauge();

	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::UI; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};