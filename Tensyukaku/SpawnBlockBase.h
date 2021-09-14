#pragma once
#include "ObjectBase.h"

class SpawnBlockBase :public ObjectBase {
public:
	SpawnBlockBase();
	~SpawnBlockBase();

	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::SPAWNBLOCK; }

	enum class SPAWNTYPE{
		SPAWN1A,SPAWN2A,SPAWN3A,SPAWN4A,SPAWN5A, SPAWN5B,SPAWN7A,SPAWN9A,SPAWN9B,SPAWN10A,SPAWN10B,SPAWN11A,SPAWN11B,SPAWN11C,SPAWN12A,SPAWN12B,SPAWN12C,BOSSSPAWN
	};

	virtual SPAWNTYPE	GetSpaType() = 0;

	void Init()override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
};