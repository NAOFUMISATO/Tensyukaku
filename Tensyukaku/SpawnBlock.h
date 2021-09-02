#pragma once
#include "SpawnBlockBase.h"

class Spawn1A :public SpawnBlockBase {
public:
	Spawn1A();
	~Spawn1A();
	virtual SPAWNTYPE	GetSpaType() { return SPAWNTYPE::SPAWN1A; }
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
class Spawn2A :public SpawnBlockBase {
public:
	Spawn2A();
	~Spawn2A();
	virtual SPAWNTYPE	GetSpaType() { return SPAWNTYPE::SPAWN2A; }
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
class Spawn3A :public SpawnBlockBase {
public:
	Spawn3A();
	~Spawn3A();
	virtual SPAWNTYPE	GetSpaType() { return SPAWNTYPE::SPAWN3A; }
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
class Spawn4A :public SpawnBlockBase {
public:
	Spawn4A();
	~Spawn4A();
	virtual SPAWNTYPE	GetSpaType() { return SPAWNTYPE::SPAWN4A; }
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
class Spawn5A :public SpawnBlockBase {
public:
	Spawn5A();
	~Spawn5A();
	virtual SPAWNTYPE	GetSpaType() { return SPAWNTYPE::SPAWN5A; }
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
class Spawn5B :public SpawnBlockBase {
public:
	Spawn5B();
	~Spawn5B();
	virtual SPAWNTYPE	GetSpaType() { return SPAWNTYPE::SPAWN5B; }
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
class Spawn7A :public SpawnBlockBase {
public:
	Spawn7A();
	~Spawn7A();
	virtual SPAWNTYPE	GetSpaType() { return SPAWNTYPE::SPAWN7A; }
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
class Spawn9A :public SpawnBlockBase {
public:
	Spawn9A();
	~Spawn9A();
	virtual SPAWNTYPE	GetSpaType() { return SPAWNTYPE::SPAWN9A; }
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
class Spawn9B :public SpawnBlockBase {
public:
	Spawn9B();
	~Spawn9B();
	virtual SPAWNTYPE	GetSpaType() { return SPAWNTYPE::SPAWN9B; }
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
class Spawn10A :public SpawnBlockBase {
public:
	Spawn10A();
	~Spawn10A();
	virtual SPAWNTYPE	GetSpaType() { return SPAWNTYPE::SPAWN10A; }
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
class Spawn10B :public SpawnBlockBase {
public:
	Spawn10B();
	~Spawn10B();
	virtual SPAWNTYPE	GetSpaType() { return SPAWNTYPE::SPAWN10B; }
	void Process(Game& g)override;
	void Draw(Game& g)override;
};


namespace SpaInfo {
	/*----------�X�|�[���u���b�N�̈ʒu&�X�|�[������G�̈ʒu&�E�҂̃N�i�C�{��----------*/
	//�X�|�[���u���b�N1A(�v���C���[�̏����ʒu)
	constexpr auto SPAWN1A_XPOSITION = 4000;	constexpr auto SPAWN1A_YPOSITION = 7840;	//�X�|�[���u���b�N1A
	constexpr auto  SPAWN1A_BUSHI1_X = 4840;	constexpr auto  SPAWN1A_BUSHI1_Y = 7840;	constexpr auto  SPAWN1A_BUSHI1_FLIP = false;	//���m1
	constexpr auto  SPAWN1A_BUSHI2_X = 5040;	constexpr auto  SPAWN1A_BUSHI2_Y = 7840;	constexpr auto  SPAWN1A_BUSHI2_FLIP = true;		//���m2
	constexpr auto  SPAWN1A_BUSHI3_X = 5000;	constexpr auto  SPAWN1A_BUSHI3_Y = 7080;	constexpr auto  SPAWN1A_BUSHI3_FLIP = false;	//���m3
	constexpr auto  SPAWN1A_BUSHI4_X = 4600;	constexpr auto  SPAWN1A_BUSHI4_Y = 7080;	constexpr auto  SPAWN1A_BUSHI4_FLIP = true;		//���m4
	constexpr auto  SPAWN1A_BUSHI5_X = 3500;	constexpr auto  SPAWN1A_BUSHI5_Y = 5560;	constexpr auto  SPAWN1A_BUSHI5_FLIP = true;		//���m5
	constexpr auto  SPAWN1A_BUSHI6_X = 3100;	constexpr auto  SPAWN1A_BUSHI6_Y = 5560;	constexpr auto  SPAWN1A_BUSHI6_FLIP = false;	//���m6
	constexpr auto  SPAWN1A_BUSHI7_X = 2900;	constexpr auto  SPAWN1A_BUSHI7_Y = 2520;	constexpr auto  SPAWN1A_BUSHI7_FLIP = false;	//���m7
	constexpr auto  SPAWN1A_BUSHI8_X = 2600;	constexpr auto  SPAWN1A_BUSHI8_Y = 2520;	constexpr auto  SPAWN1A_BUSHI8_FLIP = false;	//���m8
	constexpr auto  SPAWN1A_BUSHI9_X = 2300;	constexpr auto  SPAWN1A_BUSHI9_Y = 2520;	constexpr auto  SPAWN1A_BUSHI9_FLIP = false;	//���m9
	constexpr auto SPAWN1A_BUSHI10_X = 5300;	constexpr auto SPAWN1A_BUSHI10_Y = 1760;	constexpr auto SPAWN1A_BUSHI10_FLIP = false;	//���m10
	constexpr auto SPAWN1A_BUSHI11_X = 4500;	constexpr auto SPAWN1A_BUSHI11_Y = 1760;	constexpr auto SPAWN1A_BUSHI11_FLIP = false;	//���m11
	constexpr auto SPAWN1A_BUSHI12_X =  500;	constexpr auto SPAWN1A_BUSHI12_Y = 1000;	constexpr auto SPAWN1A_BUSHI12_FLIP = false;	//���m12
	constexpr auto SPAWN1A_BUSHI13_X = 4000;	constexpr auto SPAWN1A_BUSHI13_Y = 1000;	constexpr auto SPAWN1A_BUSHI13_FLIP = false;	//���m13
	constexpr auto SPAWN1A_BUSHI14_X = 4300;	constexpr auto SPAWN1A_BUSHI14_Y = 1000;	constexpr auto SPAWN1A_BUSHI14_FLIP = false;	//���m14
	constexpr auto SPAWN1A_BUSHI15_X = 5000;	constexpr auto SPAWN1A_BUSHI15_Y = 1000;	constexpr auto SPAWN1A_BUSHI15_FLIP = false;	//���m15
	constexpr auto SPAWN1A_BUSHI16_X = 5300;	constexpr auto SPAWN1A_BUSHI16_Y = 1000;	constexpr auto SPAWN1A_BUSHI16_FLIP = false;	//���m16
	constexpr auto  SPAWN1A_NINJA1_X = 4300;	constexpr auto  SPAWN1A_NINJA1_Y = 7080;	constexpr auto  SPAWN1A_NINJA1_FLIP = true;		constexpr auto  SPAWN1A_NINJA1_KUNAI = 0;	//�E��1
	constexpr auto  SPAWN1A_NINJA2_X = 2100;	constexpr auto  SPAWN1A_NINJA2_Y = 5560;	constexpr auto  SPAWN1A_NINJA2_FLIP = false;	constexpr auto  SPAWN1A_NINJA2_KUNAI = 2;	//�E��2
	constexpr auto  SPAWN1A_NINJA3_X =  900;	constexpr auto  SPAWN1A_NINJA3_Y = 4800;	constexpr auto  SPAWN1A_NINJA3_FLIP = false;	constexpr auto  SPAWN1A_NINJA3_KUNAI = 3;	//�E��3
	constexpr auto  SPAWN1A_NINJA4_X = 4100;	constexpr auto  SPAWN1A_NINJA4_Y = 1760;	constexpr auto  SPAWN1A_NINJA4_FLIP = false;	constexpr auto  SPAWN1A_NINJA4_KUNAI = 2;	//�E��4
	constexpr auto  SPAWN1A_NINJA5_X = 1200;	constexpr auto  SPAWN1A_NINJA5_Y = 1000;	constexpr auto  SPAWN1A_NINJA5_FLIP = false;	constexpr auto  SPAWN1A_NINJA5_KUNAI = 2;	//�E��5
	constexpr auto  SPAWN1A_SHIEL1_X = 3300;	constexpr auto  SPAWN1A_SHIEL1_Y = 6320;	constexpr auto  SPAWN1A_SHIEL1_FLIP = true;		//����1
	constexpr auto  SPAWN1A_SHIEL2_X = 3500;	constexpr auto  SPAWN1A_SHIEL2_Y = 2520;	constexpr auto  SPAWN1A_SHIEL2_FLIP = true;		//����2
	constexpr auto  SPAWN1A_SHIEL3_X = 3200;	constexpr auto  SPAWN1A_SHIEL3_Y = 2520;	constexpr auto  SPAWN1A_SHIEL3_FLIP = true;		//����3
	constexpr auto  SPAWN1A_SHIEL4_X = 3600;	constexpr auto  SPAWN1A_SHIEL4_Y = 1760;	constexpr auto  SPAWN1A_SHIEL4_FLIP = true;		//����4
	constexpr auto  SPAWN1A_SHIEL5_X =  800;	constexpr auto  SPAWN1A_SHIEL5_Y = 1000;	constexpr auto  SPAWN1A_SHIEL5_FLIP = true;		//����5
	constexpr auto  SPAWN1A_SHIEL6_X = 4700;	constexpr auto  SPAWN1A_SHIEL6_Y = 1000;	constexpr auto  SPAWN1A_SHIEL6_FLIP = true;		//����6
	constexpr auto  SPAWN1A_POIJA1_X = 3500;	constexpr auto  SPAWN1A_POIJA1_Y = 4800;	constexpr auto  SPAWN1A_POIJA1_FLIP = true;		//�ŉt�E��1
	constexpr auto  SPAWN1A_POIJA2_X = 3000;	constexpr auto  SPAWN1A_POIJA2_Y = 4800;	constexpr auto  SPAWN1A_POIJA2_FLIP = false;	//�ŉt�E��2
	constexpr auto  SPAWN1A_POIJA3_X =  400;	constexpr auto  SPAWN1A_POIJA3_Y = 4040;	constexpr auto  SPAWN1A_POIJA3_FLIP = true;		//�ŉt�E��3
	constexpr auto  SPAWN1A_POIJA4_X =  700;	constexpr auto  SPAWN1A_POIJA4_Y = 4040;	constexpr auto  SPAWN1A_POIJA4_FLIP = false;	//�ŉt�E��4
	constexpr auto  SPAWN1A_POIJA5_X = 1000;	constexpr auto  SPAWN1A_POIJA5_Y = 4040;	constexpr auto  SPAWN1A_POIJA5_FLIP = true;		//�ŉt�E��5
	constexpr auto  SPAWN1A_POIJA6_X = 1300;	constexpr auto  SPAWN1A_POIJA6_Y = 4040;	constexpr auto  SPAWN1A_POIJA6_FLIP = false;	//�ŉt�E��6
	constexpr auto  SPAWN1A_POIJA7_X = 1600;	constexpr auto  SPAWN1A_POIJA7_Y = 4040;	constexpr auto  SPAWN1A_POIJA7_FLIP = true;		//�ŉt�E��7
	constexpr auto  SPAWN1A_POIJA8_X = 1900;	constexpr auto  SPAWN1A_POIJA8_Y = 4040;	constexpr auto  SPAWN1A_POIJA8_FLIP = false;	//�ŉt�E��8
	//�X�|�[���u���b�N2A
	constexpr auto  SPAWN2A_XPOSITION = 3900;	constexpr auto SPAWN2A_YPOSITION = 7080;	//�X�|�[���u���b�N2A
	constexpr auto  SPAWN2A_BUSHI1_X = 3300;	constexpr auto  SPAWN2A_BUSHI1_Y = 7080;	constexpr auto  SPAWN2A_BUSHI1_FLIP = false;	//���m1
	constexpr auto  SPAWN2A_BUSHI2_X = 3000;	constexpr auto  SPAWN2A_BUSHI2_Y = 7080;	constexpr auto  SPAWN2A_BUSHI2_FLIP = false;	//���m2
	constexpr auto  SPAWN2A_NINJA1_X = 2700;	constexpr auto  SPAWN2A_NINJA1_Y = 7080;	constexpr auto  SPAWN2A_NINJA1_FLIP = false;	constexpr auto SPAWN2A_NINJA1_KUNAI = 2;	//�E��1
	//�X�|�[���u���b�N3A
	constexpr auto  SPAWN3A_XPOSITION = 2700;	constexpr auto SPAWN3A_YPOSITION = 6320;	//�X�|�[���u���b�N3A
	constexpr auto  SPAWN3A_SHIEL1_X = 2300;	constexpr auto  SPAWN3A_SHIEL1_Y = 6320;	constexpr auto  SPAWN3A_SHIEL1_FLIP = false;	//����1
	//�X�|�[���u���b�N4A
	constexpr auto  SPAWN4A_XPOSITION = 1900;	constexpr auto SPAWN4A_YPOSITION = 5560;	//�X�|�[���u���b�N4A
	constexpr auto  SPAWN4A_BUSHI1_X = 1500;	constexpr auto  SPAWN4A_BUSHI1_Y = 5560;	constexpr auto  SPAWN4A_BUSHI1_FLIP = false;	//���m1
	constexpr auto  SPAWN4A_BUSHI2_X =  900;	constexpr auto  SPAWN4A_BUSHI2_Y = 5560;	constexpr auto  SPAWN4A_BUSHI2_FLIP = false;	//���m2
	constexpr auto  SPAWN4A_NINJA1_X =  500;	constexpr auto  SPAWN4A_NINJA1_Y = 5560;	constexpr auto  SPAWN4A_NINJA1_FLIP = true;		constexpr auto  SPAWN4A_NINJA1_KUNAI = 2;	//�E��1
	constexpr auto  SPAWN4A_SHIEL1_X = 1800;	constexpr auto  SPAWN4A_SHIEL1_Y = 5560;	constexpr auto  SPAWN4A_SHIEL1_FLIP = true;		//����1
	constexpr auto  SPAWN4A_POIJA1_X = 1000;	constexpr auto  SPAWN4A_POIJA1_Y = 4800;	constexpr auto  SPAWN4A_POIJA1_FLIP = true;		//�ŉt�E��1
	//�X�|�[���u���b�N5A
	constexpr auto  SPAWN5A_XPOSITION = 900;	constexpr auto  SPAWN5A_YPOSITION = 4800;	//�X�|�[���u���b�N5A
	constexpr auto  SPAWN5A_NINJA1_X = 1900;	constexpr auto  SPAWN5A_NINJA1_Y = 4800;	constexpr auto  SPAWN5A_NINJA1_FLIP = true;		constexpr auto  SPAWN5A_NINJA1_KUNAI = 3;	//�E��1
	//�X�|�[���u���b�N5B
	constexpr auto  SPAWN5B_XPOSITION = 1900;	constexpr auto SPAWN5B_YPOSITION = 4800;	//�X�|�[���u���b�N5B
	constexpr auto  SPAWN5B_BUSHI1_X = 1500;	constexpr auto  SPAWN5B_BUSHI1_Y = 4800;	constexpr auto  SPAWN5B_BUSHI1_FLIP = false;	//���m1
	constexpr auto  SPAWN5B_BUSHI2_X = 2700;	constexpr auto  SPAWN5B_BUSHI2_Y = 4800;	constexpr auto  SPAWN5B_BUSHI2_FLIP = false;	//���m2
	constexpr auto  SPAWN5B_NINJA1_X = 3500;	constexpr auto  SPAWN5B_NINJA1_Y = 4800;	constexpr auto  SPAWN5B_NINJA1_FLIP = true;		constexpr auto  SPAWN5B_NINJA1_KUNAI = 2;	//�E��1
	constexpr auto  SPAWN5B_SHIEL1_X = 2400;	constexpr auto  SPAWN5B_SHIEL1_Y = 4800;	constexpr auto  SPAWN5B_SHIEL1_FLIP = true;		//����1
	constexpr auto  SPAWN5B_SHIEL2_X = 3100;	constexpr auto  SPAWN5B_SHIEL2_Y = 4800;	constexpr auto  SPAWN5B_SHIEL2_FLIP = true;		//����2
	//�X�|�[���u���b�N7A
	constexpr auto  SPAWN7A_XPOSITION = 3200;	constexpr auto  SPAWN7A_YPOSITION = 3280;	//�X�|�[���u���b�N7A
	constexpr auto  SPAWN7A_SHIEL1_X = 2400;	constexpr auto  SPAWN7A_SHIEL1_Y = 3280;	constexpr auto  SPAWN7A_SHIEL1_FLIP = false;	//����1
	constexpr auto  SPAWN7A_SHIEL2_X = 2700;	constexpr auto  SPAWN7A_SHIEL2_Y = 3280;	constexpr auto  SPAWN7A_SHIEL2_FLIP = false;	//����2
	constexpr auto  SPAWN7A_SHIEL3_X = 3000;	constexpr auto  SPAWN7A_SHIEL3_Y = 3280;	constexpr auto  SPAWN7A_SHIEL3_FLIP = false;	//����3
	constexpr auto  SPAWN7A_SHIEL4_X = 3600;	constexpr auto  SPAWN7A_SHIEL4_Y = 3280;	constexpr auto  SPAWN7A_SHIEL4_FLIP = true;		//����4
	constexpr auto  SPAWN7A_SHIEL5_X = 3900;	constexpr auto  SPAWN7A_SHIEL5_Y = 3280;	constexpr auto  SPAWN7A_SHIEL5_FLIP = true;		//����5
	constexpr auto  SPAWN7A_SHIEL6_X = 4200;	constexpr auto  SPAWN7A_SHIEL6_Y = 3280;	constexpr auto  SPAWN7A_SHIEL6_FLIP = true;		//����6
	//�X�|�[���u���b�N9A
	constexpr auto  SPAWN9A_XPOSITION = 3400;	constexpr auto SPAWN9A_YPOSITION = 1760;	//�X�|�[���u���b�N9A
	constexpr auto  SPAWN9A_BUSHI1_X = 3500;	constexpr auto  SPAWN9A_BUSHI1_Y = 1760;	constexpr auto  SPAWN9A_BUSHI1_FLIP = false;	//���m1
	constexpr auto  SPAWN9A_BUSHI2_X = 3000;	constexpr auto  SPAWN9A_BUSHI2_Y = 1760;	constexpr auto  SPAWN9A_BUSHI2_FLIP = false;	//���m2
	constexpr auto  SPAWN9A_BUSHI3_X = 2700;	constexpr auto  SPAWN9A_BUSHI3_Y = 1760;	constexpr auto  SPAWN9A_BUSHI3_FLIP = false;	//���m3
	constexpr auto  SPAWN9A_NINJA1_X = 2400;	constexpr auto  SPAWN9A_NINJA1_Y = 1760;	constexpr auto  SPAWN9A_NINJA1_FLIP = true;		constexpr auto  SPAWN9A_NINJA1_KUNAI = 2;	//�E��1
	constexpr auto  SPAWN9A_POIJA1_X = 2600;	constexpr auto  SPAWN9A_POIJA1_Y = 1760;	constexpr auto  SPAWN9A_POIJA1_FLIP = true;		//�ŉt�E��1
	//�X�|�[���u���b�N9B
	constexpr auto  SPAWN9B_XPOSITION = 1600;	constexpr auto SPAWN9B_YPOSITION = 1760;	//�X�|�[���u���b�N9B
	constexpr auto  SPAWN9B_BUSHI1_X = 1300;	constexpr auto  SPAWN9B_BUSHI1_Y = 1760;	constexpr auto  SPAWN9B_BUSHI1_FLIP = false;	//���m1
	constexpr auto  SPAWN9B_NINJA1_X = 1900;	constexpr auto  SPAWN9B_NINJA1_Y = 1760;	constexpr auto  SPAWN9B_NINJA1_FLIP = true;		constexpr auto  SPAWN9B_NINJA1_KUNAI = 0;	//�E��1
	constexpr auto  SPAWN9B_NINJA2_X = 1000;	constexpr auto  SPAWN9B_NINJA2_Y = 1760;	constexpr auto  SPAWN9B_NINJA2_FLIP = false;	constexpr auto  SPAWN9B_NINJA2_KUNAI = 2;	//�E��2
	constexpr auto  SPAWN9B_NINJA3_X = 800;		constexpr auto  SPAWN9B_NINJA3_Y = 1760;	constexpr auto  SPAWN9B_NINJA3_FLIP = false;	constexpr auto  SPAWN9B_NINJA3_KUNAI = 3;	//�E��3
	constexpr auto  SPAWN9B_POIJA1_X = 1800;	constexpr auto  SPAWN9B_POIJA1_Y = 1000;	constexpr auto  SPAWN9B_POIJA1_FLIP = true;		//�ŉt�E��1
	//�X�|�[���u���b�N10A
	constexpr auto  SPAWN10A_XPOSITION = 1700;	constexpr auto SPAWN10A_YPOSITION = 1000;	//�X�|�[���u���b�N10A
	constexpr auto  SPAWN10A_BUSHI1_X = 1300;	constexpr auto  SPAWN10A_BUSHI1_Y = 1000;	constexpr auto  SPAWN10A_BUSHI1_FLIP = false;	//���m1
	constexpr auto  SPAWN10A_NINJA1_X =  900;	constexpr auto  SPAWN10A_NINJA1_Y = 1000;	constexpr auto  SPAWN10A_NINJA1_FLIP = true;	constexpr auto  SPAWN10A_NINJA1_KUNAI = 0;	//�E��1
	constexpr auto  SPAWN10A_SHIEL1_X = 2100;	constexpr auto  SPAWN10A_SHIEL1_Y = 1000;	constexpr auto  SPAWN10A_SHIEL1_FLIP = false;	//����1
	constexpr auto  SPAWN10A_SHIEL2_X = 2400;	constexpr auto  SPAWN10A_SHIEL2_Y = 1000;	constexpr auto  SPAWN10A_SHIEL2_FLIP = false;	//����2
	//�X�|�[���u���b�N10B
	constexpr auto  SPAWN10B_XPOSITION = 2700;	constexpr auto SPAWN10B_YPOSITION = 1000;	//�X�|�[���u���b�N10B
	constexpr auto  SPAWN10B_NINJA1_X = 3100;	constexpr auto  SPAWN10B_NINJA1_Y = 1000;	constexpr auto  SPAWN10B_NINJA1_FLIP = true;	constexpr auto  SPAWN10B_NINJA1_KUNAI = 0;	//�E��1
	constexpr auto  SPAWN10B_NINJA2_X = 3400;	constexpr auto  SPAWN10B_NINJA2_Y = 1000;	constexpr auto  SPAWN10B_NINJA2_FLIP = true;	constexpr auto  SPAWN10B_NINJA2_KUNAI = 0;	//�E��2
}