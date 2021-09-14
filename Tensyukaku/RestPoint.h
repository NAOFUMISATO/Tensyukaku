#pragma once
#include "ObjectBase.h"

class RestPoint :public ObjectBase {
public:
	RestPoint();
	~RestPoint();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::RESTPOINT; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;

};