#pragma once
#include "ObjectBase.h"

class SpawnBlockBase :public ObjectBase {
public:
	SpawnBlockBase();
	~SpawnBlockBase();

	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::SPAWNBLOCK; }

	enum class SPAWNTYPE{
		SPAWN1,SPAWN2,SPAWN3,SPAWN4
	};

	virtual SPAWNTYPE	GetSpaType() = 0;

	void Init()override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
};