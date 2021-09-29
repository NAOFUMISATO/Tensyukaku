#pragma once
#include "ObjectBase.h"

class EfectBase :public ObjectBase {
public:
	EfectBase();
	~EfectBase();
	virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::EFECT; }

	enum class EFECTTYPE {
	MIDDLEBLOOD,LOWBLOOD,BOSSBLOOD
	};
	virtual  EFECTTYPE GetEfeType() = 0;
	virtual void Init();
	virtual void Process(Game& g);
	virtual void Draw(Game& g);
	virtual	void	Delete(Game& g) {};
};