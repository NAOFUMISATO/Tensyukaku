#pragma once
#include "SpawnBlockBase.h"

class Spawn1 :public SpawnBlockBase {
public:
	Spawn1();
	~Spawn1();
	virtual SPAWNTYPE	GetSpaType() { return SPAWNTYPE::SPAWN1; }
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
//class Spawn2 :public EnemySpawnBase {
//public:
//	Spawn2();
//	~Spawn2();
//	virtual SPAWNTYPE	GetSpaType() { return SPAWNTYPE::SPAWN2; }
//	void Process(Game& g)override;
//};
//class Spawn3 :public EnemySpawnBase {
//public:
//	Spawn3();
//	~Spawn3();
//	virtual SPAWNTYPE	GetSpaType() { return SPAWNTYPE::SPAWN3; }
//	void Process(Game& g)override;
//};
//class Spawn4 :public EnemySpawnBase {
//public:
//	Spawn4();
//	~Spawn4();
//	virtual SPAWNTYPE	GetSpaType() { return SPAWNTYPE::SPAWN4; }
//	void Process(Game& g)override;
//};

namespace SpaInfo {
	/*----------スポーンブロックの位置&スポーンする敵の位置----------*/
	//スポーンブロック1
	constexpr auto SPAWN1_XPOSITION = 500;			//スポーンブロック1のX座標
	constexpr auto SPAWN1_YPOSITION = 2200;			//スポーンブロック1のY座標
	constexpr auto SPAWN1_BUSHI1_X = 800;			//武士1のX座標
	constexpr auto SPAWN1_BUSHI1_Y = 2200;			//武士1のY座標
	constexpr auto SPAWN1_BUSHI1_FLIP = false;		//武士1の向き
	constexpr auto SPAWN1_BUSHI2_X = 3000;			//武士2のX座標
	constexpr auto SPAWN1_BUSHI2_Y = 2200;			//武士2のY座標
	constexpr auto SPAWN1_BUSHI2_FLIP = false;		//武士2の向き
	constexpr auto SPAWN1_NINJA1_X = 2200;			//忍者1のX座標
	constexpr auto SPAWN1_NINJA1_Y = 2200;			//忍者1のY座標
	constexpr auto SPAWN1_NINJA1_FLIP = false;		//忍者1の向き
}