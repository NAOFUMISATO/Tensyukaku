#pragma once
#include "ObjectBase.h"

class EnemySpawnCollisionBase :public ObjectBase {
public:
	EnemySpawnCollisionBase();
	~EnemySpawnCollisionBase();

	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::ENEMYSPAWN; }

	enum class SPAWNTYPE{
		SPAWN1,SPAWN2,SPAWN3,SPAWN4
	};

	virtual SPAWNTYPE	GetSpaType() = 0;

	void Init()override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
};