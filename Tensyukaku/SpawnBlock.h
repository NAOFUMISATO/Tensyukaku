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
	/*----------�X�|�[���u���b�N�̈ʒu&�X�|�[������G�̈ʒu----------*/
	//�X�|�[���u���b�N1
	constexpr auto SPAWN1_XPOSITION = 500;			//�X�|�[���u���b�N1��X���W
	constexpr auto SPAWN1_YPOSITION = 2200;			//�X�|�[���u���b�N1��Y���W
	constexpr auto SPAWN1_BUSHI1_X = 800;			//���m1��X���W
	constexpr auto SPAWN1_BUSHI1_Y = 2200;			//���m1��Y���W
	constexpr auto SPAWN1_BUSHI1_FLIP = false;		//���m1�̌���
	constexpr auto SPAWN1_BUSHI2_X = 3000;			//���m2��X���W
	constexpr auto SPAWN1_BUSHI2_Y = 2200;			//���m2��Y���W
	constexpr auto SPAWN1_BUSHI2_FLIP = false;		//���m2�̌���
	constexpr auto SPAWN1_NINJA1_X = 2200;			//�E��1��X���W
	constexpr auto SPAWN1_NINJA1_Y = 2200;			//�E��1��Y���W
	constexpr auto SPAWN1_NINJA1_FLIP = false;		//�E��1�̌���
}