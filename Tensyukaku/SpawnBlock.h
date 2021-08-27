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
	/*----------�X�|�[���u���b�N�̈ʒu&�X�|�[������G�̈ʒu----------*/
	//�X�|�[���u���b�N1
	constexpr auto SPAWN1_XPOSITION = 4000;			//�X�|�[���u���b�N1��X���W
	constexpr auto SPAWN1_YPOSITION = 7840;			//�X�|�[���u���b�N1��Y���W
	constexpr auto SPAWN1_BUSHI1_X = 4840;			//���m1��X���W
	constexpr auto SPAWN1_BUSHI1_Y = 7840;			//���m1��Y���W
	constexpr auto SPAWN1_BUSHI1_FLIP = false;		//���m1�̌���
	constexpr auto SPAWN1_BUSHI2_X = 5040;			//���m2��X���W
	constexpr auto SPAWN1_BUSHI2_Y = 7840;			//���m2��Y���W
	constexpr auto SPAWN1_BUSHI2_FLIP = true;		//���m2�̌���
	constexpr auto SPAWN1_BUSHI3_X = 5240;			//���m3��X���W
	constexpr auto SPAWN1_BUSHI3_Y = 7080;			//���m3��Y���W
	constexpr auto SPAWN1_BUSHI3_FLIP = false;		//���m3�̌���
	constexpr auto SPAWN1_BUSHI4_X = 5040;			//���m4��X���W
	constexpr auto SPAWN1_BUSHI4_Y = 7080;			//���m4��Y���W
	constexpr auto SPAWN1_BUSHI4_FLIP = true;		//���m4�̌���
	constexpr auto SPAWN1_BUSHI5_X = 4640;			//���m5��X���W
	constexpr auto SPAWN1_BUSHI5_Y = 7080;			//���m5��Y���W
	constexpr auto SPAWN1_BUSHI5_FLIP = true;		//���m5�̌���
	constexpr auto SPAWN1_BUSHI6_X = 4300;			//���m6��X���W
	constexpr auto SPAWN1_BUSHI6_Y = 7080;			//���m6��Y���W
	constexpr auto SPAWN1_BUSHI6_FLIP = false;		//���m6�̌���
	constexpr auto SPAWN1_BUSHI7_X = 3000;			//���m7��X���W
	constexpr auto SPAWN1_BUSHI7_Y = 7080;			//���m7��Y���W
	constexpr auto SPAWN1_BUSHI7_FLIP = true;		//���m7�̌���
	constexpr auto SPAWN1_BUSHI8_X = 2700;			//���m8��X���W
	constexpr auto SPAWN1_BUSHI8_Y = 7080;			//���m8��Y���W
	constexpr auto SPAWN1_BUSHI8_FLIP = false;		//���m8�̌���
	constexpr auto SPAWN1_NINJA1_X = 4800;			//�E��1��X���W
	constexpr auto SPAWN1_NINJA1_Y = 7080;			//�E��1��Y���W
	constexpr auto SPAWN1_NINJA1_FLIP = true;		//�E��1�̌���
	constexpr auto SPAWN1_NINJA2_X = 4100;			//�E��2��X���W
	constexpr auto SPAWN1_NINJA2_Y = 7080;			//�E��2��Y���W
	constexpr auto SPAWN1_NINJA2_FLIP = false;		//�E��2�̌���
	constexpr auto SPAWN1_NINJA3_X = 2850;			//�E��3��X���W
	constexpr auto SPAWN1_NINJA3_Y = 7080;			//�E��3��Y���W
	constexpr auto SPAWN1_NINJA3_FLIP = true;		//�E��3�̌���
	constexpr auto SPAWN1_SHIELDER1_X = 3300;		//����1��X���W
	constexpr auto SPAWN1_SHIELDER1_Y = 6320;		//����1��Y���W
	constexpr auto SPAWN1_SHIELDER1_FLIP = false;	//����1�̌���
	
	//�X�|�[���u���b�N2
	constexpr auto SPAWN2_XPOSITION = 3400;			//�X�|�[���u���b�N2��X���W
	constexpr auto SPAWN2_YPOSITION = 7080;			//�X�|�[���u���b�N2��Y���W
	constexpr auto SPAWN2_BUSHI1_X = 3900;			//���m1��X���W
	constexpr auto SPAWN2_BUSHI1_Y = 7080;			//���m1��Y���W
	constexpr auto SPAWN2_BUSHI1_FLIP = false;		//���m1�̌���
	constexpr auto SPAWN2_NINJA1_X = 4000;			//�E��1��X���W
	constexpr auto SPAWN2_NINJA1_Y = 7080;			//�E��1��Y���W
	constexpr auto SPAWN2_NINJA1_FLIP = false;		//�E��1�̌���
	constexpr auto SPAWN2_NINJA2_X = 3800;			//�E��2��X���W
	constexpr auto SPAWN2_NINJA2_Y = 7080;			//�E��2��Y���W
	constexpr auto SPAWN2_NINJA2_FLIP = false;		//�E��2�̌���

	//�X�|�[���u���b�N3
	constexpr auto SPAWN3_XPOSITION = 3100;			//�X�|�[���u���b�N3��X���W
	constexpr auto SPAWN3_YPOSITION = 6320;			//�X�|�[���u���b�N3��Y���W
	constexpr auto SPAWN3_SHIELDER1_X = 2600;		//����1��X���W
	constexpr auto SPAWN3_SHIELDER1_Y = 6320;		//����1��Y���W
	constexpr auto SPAWN3_SHIELDER1_FLIP = false;	//����1�̌���
	
}