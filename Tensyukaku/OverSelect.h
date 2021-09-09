#pragma once
#include "ObjectBase.h"
class OverLogo :public ObjectBase {
public:
	OverLogo();
	~OverLogo();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::OVERLOGO; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
class OverRetry :public ObjectBase {
public:
	OverRetry();
	~OverRetry();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::OVERRETRY; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};

class OverGotitle :public ObjectBase {
public:
	OverGotitle();
	~OverGotitle();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::OVERGOTITLE; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};