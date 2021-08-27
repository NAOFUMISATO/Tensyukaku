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
class Spawn2 :public SpawnBlockBase {
public:
	Spawn2();
	~Spawn2();
	virtual SPAWNTYPE	GetSpaType() { return SPAWNTYPE::SPAWN2; }
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
class Spawn3 :public SpawnBlockBase {
public:
	Spawn3();
	~Spawn3();
	virtual SPAWNTYPE	GetSpaType() { return SPAWNTYPE::SPAWN3; }
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
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
	constexpr auto SPAWN1_XPOSITION = 4000;			//スポーンブロック1のX座標
	constexpr auto SPAWN1_YPOSITION = 7840;			//スポーンブロック1のY座標
	constexpr auto SPAWN1_BUSHI1_X = 4840;			//武士1のX座標
	constexpr auto SPAWN1_BUSHI1_Y = 7840;			//武士1のY座標
	constexpr auto SPAWN1_BUSHI1_FLIP = false;		//武士1の向き
	constexpr auto SPAWN1_BUSHI2_X = 5040;			//武士2のX座標
	constexpr auto SPAWN1_BUSHI2_Y = 7840;			//武士2のY座標
	constexpr auto SPAWN1_BUSHI2_FLIP = true;		//武士2の向き
	constexpr auto SPAWN1_BUSHI3_X = 5240;			//武士3のX座標
	constexpr auto SPAWN1_BUSHI3_Y = 7080;			//武士3のY座標
	constexpr auto SPAWN1_BUSHI3_FLIP = false;		//武士3の向き
	constexpr auto SPAWN1_BUSHI4_X = 5040;			//武士4のX座標
	constexpr auto SPAWN1_BUSHI4_Y = 7080;			//武士4のY座標
	constexpr auto SPAWN1_BUSHI4_FLIP = true;		//武士4の向き
	constexpr auto SPAWN1_BUSHI5_X = 4640;			//武士5のX座標
	constexpr auto SPAWN1_BUSHI5_Y = 7080;			//武士5のY座標
	constexpr auto SPAWN1_BUSHI5_FLIP = true;		//武士5の向き
	constexpr auto SPAWN1_BUSHI6_X = 4300;			//武士6のX座標
	constexpr auto SPAWN1_BUSHI6_Y = 7080;			//武士6のY座標
	constexpr auto SPAWN1_BUSHI6_FLIP = false;		//武士6の向き
	constexpr auto SPAWN1_BUSHI7_X = 3000;			//武士7のX座標
	constexpr auto SPAWN1_BUSHI7_Y = 7080;			//武士7のY座標
	constexpr auto SPAWN1_BUSHI7_FLIP = true;		//武士7の向き
	constexpr auto SPAWN1_BUSHI8_X = 2700;			//武士8のX座標
	constexpr auto SPAWN1_BUSHI8_Y = 7080;			//武士8のY座標
	constexpr auto SPAWN1_BUSHI8_FLIP = false;		//武士8の向き
	constexpr auto SPAWN1_NINJA1_X = 4800;			//忍者1のX座標
	constexpr auto SPAWN1_NINJA1_Y = 7080;			//忍者1のY座標
	constexpr auto SPAWN1_NINJA1_FLIP = true;		//忍者1の向き
	constexpr auto SPAWN1_NINJA2_X = 4100;			//忍者2のX座標
	constexpr auto SPAWN1_NINJA2_Y = 7080;			//忍者2のY座標
	constexpr auto SPAWN1_NINJA2_FLIP = false;		//忍者2の向き
	constexpr auto SPAWN1_NINJA3_X = 2850;			//忍者3のX座標
	constexpr auto SPAWN1_NINJA3_Y = 7080;			//忍者3のY座標
	constexpr auto SPAWN1_NINJA3_FLIP = true;		//忍者3の向き
	constexpr auto SPAWN1_SHIELDER1_X = 3300;		//盾兵1のX座標
	constexpr auto SPAWN1_SHIELDER1_Y = 6320;		//盾兵1のY座標
	constexpr auto SPAWN1_SHIELDER1_FLIP = false;	//盾兵1の向き
	
	//スポーンブロック2
	constexpr auto SPAWN2_XPOSITION = 3400;			//スポーンブロック2のX座標
	constexpr auto SPAWN2_YPOSITION = 7080;			//スポーンブロック2のY座標
	constexpr auto SPAWN2_BUSHI1_X = 3900;			//武士1のX座標
	constexpr auto SPAWN2_BUSHI1_Y = 7080;			//武士1のY座標
	constexpr auto SPAWN2_BUSHI1_FLIP = false;		//武士1の向き
	constexpr auto SPAWN2_NINJA1_X = 4000;			//忍者1のX座標
	constexpr auto SPAWN2_NINJA1_Y = 7080;			//忍者1のY座標
	constexpr auto SPAWN2_NINJA1_FLIP = false;		//忍者1の向き
	constexpr auto SPAWN2_NINJA2_X = 3800;			//忍者2のX座標
	constexpr auto SPAWN2_NINJA2_Y = 7080;			//忍者2のY座標
	constexpr auto SPAWN2_NINJA2_FLIP = false;		//忍者2の向き

	//スポーンブロック3
	constexpr auto SPAWN3_XPOSITION = 3100;			//スポーンブロック3のX座標
	constexpr auto SPAWN3_YPOSITION = 6320;			//スポーンブロック3のY座標
	constexpr auto SPAWN3_SHIELDER1_X = 2600;		//盾兵1のX座標
	constexpr auto SPAWN3_SHIELDER1_Y = 6320;		//盾兵1のY座標
	constexpr auto SPAWN3_SHIELDER1_FLIP = false;	//盾兵1の向き
	
}