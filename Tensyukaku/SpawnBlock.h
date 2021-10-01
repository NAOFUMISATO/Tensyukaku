#pragma once
#include "ObjectBase.h"

class Spawn :public ObjectBase {
public:
	Spawn(std::string spawntype);
	~Spawn();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::SPAWNBLOCK; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
private:
	void SpawnPositon();

	std::string  _spawn_type;
};

namespace SpaInfo {
	/*----------スポーンブロックの位置&スポーンする敵の位置&忍者のクナイ本数----------*/
		//スポーンブロック1A(プレイヤーの初期位置)
	constexpr auto SPAWN1A_XPOSITION = 400;	constexpr auto SPAWN1A_YPOSITION = 9360;	//スポーンブロック1A
	constexpr auto  SPAWN1A_BUSHI2_X = 1600;	constexpr auto  SPAWN1A_BUSHI2_Y = 9360;	constexpr auto  SPAWN1A_BUSHI2_FLIP = false;	//武士2
	constexpr auto  SPAWN1A_BUSHI3_X = 1900;	constexpr auto  SPAWN1A_BUSHI3_Y = 9360;	constexpr auto  SPAWN1A_BUSHI3_FLIP = false;	//武士3
	//スポーンブロック1B
	constexpr auto SPAWN1B_XPOSITION = 2300;	constexpr auto SPAWN1B_YPOSITION = 9360;	//スポーンブロック1B
	constexpr auto  SPAWN1B_BUSHI1_X = 1900;	constexpr auto  SPAWN1B_BUSHI1_Y = 9360;	constexpr auto  SPAWN1B_BUSHI1_FLIP = true;	//武士1
	constexpr auto  SPAWN1B_BUSHI2_X = 3000;	constexpr auto  SPAWN1B_BUSHI2_Y = 9360;	constexpr auto  SPAWN1B_BUSHI2_FLIP = false;	//武士2
	constexpr auto  SPAWN1B_BUSHI3_X = 3300;	constexpr auto  SPAWN1B_BUSHI3_Y = 9360;	constexpr auto  SPAWN1B_BUSHI3_FLIP = false;	//武士3
	constexpr auto  SPAWN1B_BUSHI4_X = 3600;	constexpr auto  SPAWN1B_BUSHI4_Y = 9360;	constexpr auto  SPAWN1B_BUSHI4_FLIP = false;	//武士4
	//スポーンブロック2A
	constexpr auto  SPAWN2A_XPOSITION = 3700;	constexpr auto SPAWN2A_YPOSITION = 8600;	//スポーンブロック2A
	constexpr auto  SPAWN2A_NINJA1_X = 2300;		constexpr auto  SPAWN2A_NINJA1_Y = 8600;	constexpr auto  SPAWN2A_NINJA1_FLIP = true;		constexpr auto  SPAWN2A_NINJA1_KUNAI = 0;	//忍者1
	constexpr auto  SPAWN2A_NINJA2_X = 2000;		constexpr auto  SPAWN2A_NINJA2_Y = 8600;	constexpr auto  SPAWN2A_NINJA2_FLIP = true;		constexpr auto  SPAWN2A_NINJA2_KUNAI = 0;	//忍者2
	//スポーンブロック2B
	constexpr auto  SPAWN2B_XPOSITION = 2200;	constexpr auto SPAWN2B_YPOSITION = 8600;	//スポーンブロック2B
	constexpr auto  SPAWN2B_NINJA1_X = 900;		constexpr auto  SPAWN2B_NINJA1_Y = 8600;	constexpr auto  SPAWN2B_NINJA1_FLIP = true;		constexpr auto  SPAWN2B_NINJA1_KUNAI = 1;	//忍者1
	constexpr auto  SPAWN2B_NINJA2_X = 1200;	constexpr auto  SPAWN2B_NINJA2_Y = 8600;	constexpr auto  SPAWN2B_NINJA2_FLIP = true;		constexpr auto  SPAWN2B_NINJA2_KUNAI = 0;	//忍者2
	constexpr auto  SPAWN2B_NINJA3_X = 600;		constexpr auto  SPAWN2B_NINJA3_Y = 8600;	constexpr auto  SPAWN2B_NINJA3_FLIP = true;		constexpr auto  SPAWN2B_NINJA3_KUNAI = 3;	//忍者3
	constexpr auto  SPAWN2B_NINJA4_X = 300;		constexpr auto  SPAWN2B_NINJA4_Y = 8600;	constexpr auto  SPAWN2B_NINJA4_FLIP = true;		constexpr auto  SPAWN2B_NINJA4_KUNAI = 0;	//忍者4
	//スポーンブロック3A
	constexpr auto  SPAWN3A_XPOSITION = 400;	constexpr auto SPAWN3A_YPOSITION = 7840;	//スポーンブロック3A
	constexpr auto  SPAWN3A_LANCE1_X = 1200;	constexpr auto  SPAWN3A_LANCE1_Y = 7840;	constexpr auto  SPAWN3A_LANCE1_FLIP = false;	//槍兵
	//スポーンブロック3B
	constexpr auto  SPAWN3B_XPOSITION = 1300;	constexpr auto SPAWN3B_YPOSITION = 7840;	//スポーンブロック3B
	constexpr auto  SPAWN3B_LANCE1_X = 1900;	constexpr auto  SPAWN3B_LANCE1_Y = 7840;	constexpr auto  SPAWN3B_LANCE1_FLIP = false;	//槍兵1
	constexpr auto  SPAWN3B_LANCE2_X = 2200;	constexpr auto  SPAWN3B_LANCE2_Y = 7840;	constexpr auto  SPAWN3B_LANCE2_FLIP = false;	//槍兵2
	//スポーンブロック3C
	constexpr auto  SPAWN3C_XPOSITION = 2400;	constexpr auto SPAWN3C_YPOSITION = 7840;	//スポーンブロック3C
	constexpr auto  SPAWN3C_SHIEL1_X = 3100;	constexpr auto  SPAWN3C_SHIEL1_Y = 7840;	constexpr auto  SPAWN3C_SHIEL1_FLIP = false;	//盾兵1
	constexpr auto  SPAWN3C_SHIEL2_X = 3800;	constexpr auto  SPAWN3C_SHIEL2_Y = 7840;	constexpr auto  SPAWN3C_SHIEL2_FLIP = false;	//盾兵2
	//スポーンブロック3D
	constexpr auto  SPAWN3D_XPOSITION = 3900;	constexpr auto SPAWN3D_YPOSITION = 7840;	//スポーンブロック3D
	constexpr auto  SPAWN3D_SHIEL1_X = 4700;	constexpr auto  SPAWN3D_SHIEL1_Y = 7840;	constexpr auto  SPAWN3D_SHIEL1_FLIP = false;	//盾兵1
	constexpr auto  SPAWN3D_LANCE1_X = 5200;	constexpr auto  SPAWN3D_LANCE1_Y = 7840;	constexpr auto  SPAWN3D_LANCE1_FLIP = false;	//槍兵1
	//スポーンブロック3E
	constexpr auto  SPAWN3E_XPOSITION = 4700;	constexpr auto SPAWN3E_YPOSITION = 7840;	//スポーンブロック3E
	constexpr auto  SPAWN3E_LANCE1_X = 4000;	constexpr auto  SPAWN3E_LANCE1_Y = 7840;	constexpr auto  SPAWN3E_LANCE1_FLIP = true;	//槍兵1
	//スポーンブロック4A
	constexpr auto  SPAWN4A_XPOSITION = 5800;	constexpr auto SPAWN4A_YPOSITION = 7080;	//スポーンブロック4A
	constexpr auto  SPAWN4A_SHIEL1_X = 4800;		constexpr auto  SPAWN4A_SHIEL1_Y = 7080;	constexpr auto  SPAWN4A_SHIEL1_FLIP = true;//盾兵1
	//スポーンブロック4B
	constexpr auto  SPAWN4B_XPOSITION = 4700;	constexpr auto SPAWN4B_YPOSITION = 7080;	//スポーンブロック4B
	constexpr auto  SPAWN4B_BUSHI1_X = 4000;	constexpr auto  SPAWN4B_BUSHI1_Y = 7080;	constexpr auto  SPAWN4B_BUSHI1_FLIP = true;	//武士1
	constexpr auto  SPAWN4B_NINJA1_X = 3700;		constexpr auto  SPAWN4B_NINJA1_Y = 7080;		constexpr auto  SPAWN4B_NINJA1_FLIP = true;		constexpr auto  SPAWN4B_NINJA1_KUNAI = 1;	//忍者1
	//スポーンブロック4C
	constexpr auto  SPAWN4C_XPOSITION = 3600;	constexpr auto SPAWN4C_YPOSITION = 7080;	//スポーンブロック4C
	constexpr auto  SPAWN4C_BUSHI1_X = 3000;	constexpr auto  SPAWN4C_BUSHI1_Y = 7080;	constexpr auto  SPAWN4C_BUSHI1_FLIP = true;	//武士1
	constexpr auto  SPAWN4C_LANCE1_X = 2700;	constexpr auto  SPAWN4C_LANCE1_Y = 7080;	constexpr auto  SPAWN4C_LANCE1_FLIP = true;	//槍兵1
	constexpr auto  SPAWN4C_NINJA1_X = 2400;		constexpr auto  SPAWN4C_NINJA1_Y = 7080;		constexpr auto  SPAWN4C_NINJA1_FLIP = true;		constexpr auto  SPAWN4C_NINJA1_KUNAI = 2;	//忍者1
	//スポーンブロック4D
	constexpr auto  SPAWN4D_XPOSITION = 2000;	constexpr auto SPAWN4D_YPOSITION = 7080;	//スポーンブロック4D
	constexpr auto  SPAWN4D_SHIEL1_X = 1300;	constexpr auto  SPAWN4D_SHIEL1_Y = 7080;	constexpr auto  SPAWN4D_SHIEL1_FLIP = true;	//盾兵1
	//スポーンブロック5A
	constexpr auto  SPAWN5A_XPOSITION = 400; constexpr auto  SPAWN5A_YPOSITION = 6320;	//スポーンブロック5A
	constexpr auto  SPAWN5A_NINJA1_X = 2000;	constexpr auto  SPAWN5A_NINJA1_Y = 6320;	constexpr auto  SPAWN5A_NINJA1_FLIP = false;		constexpr auto  SPAWN5A_NINJA1_KUNAI = 2;	//忍者1
	constexpr auto  SPAWN5A_NINJA2_X = 3100;	constexpr auto  SPAWN5A_NINJA2_Y = 6320;	constexpr auto  SPAWN5A_NINJA2_FLIP = false;		constexpr auto  SPAWN5A_NINJA2_KUNAI = 2;	//忍者2
	constexpr auto  SPAWN5A_POIJA1_X = 900;	constexpr auto  SPAWN5A_POIJA1_Y = 5560;	constexpr auto  SPAWN5A_POIJA1_FLIP = false;		//毒液忍者1
	constexpr auto  SPAWN5A_POIJA2_X = 1200;	constexpr auto  SPAWN5A_POIJA2_Y = 5560;	constexpr auto  SPAWN5A_POIJA2_FLIP = true;		//毒液忍者2
	constexpr auto  SPAWN5A_POIJA3_X = 1600;	constexpr auto  SPAWN5A_POIJA3_Y = 5560;	constexpr auto  SPAWN5A_POIJA3_FLIP = false;		//毒液忍者3
	constexpr auto  SPAWN5A_POIJA4_X = 1900;	constexpr auto  SPAWN5A_POIJA4_Y = 5560;	constexpr auto  SPAWN5A_POIJA4_FLIP = true;		//毒液忍者4
	constexpr auto  SPAWN5A_POIJA5_X = 2100;	constexpr auto  SPAWN5A_POIJA5_Y = 5560;	constexpr auto  SPAWN5A_POIJA5_FLIP = false;		//毒液忍者5
	constexpr auto  SPAWN5A_POIJA6_X = 2500;	constexpr auto  SPAWN5A_POIJA6_Y = 5560;	constexpr auto  SPAWN5A_POIJA6_FLIP = true;		//毒液忍者6
	constexpr auto  SPAWN5A_POIJA7_X = 2800;	constexpr auto  SPAWN5A_POIJA7_Y = 5560;	constexpr auto  SPAWN5A_POIJA7_FLIP = false;		//毒液忍者7
	constexpr auto  SPAWN5A_POIJA8_X = 3000;	constexpr auto  SPAWN5A_POIJA8_Y = 5560;	constexpr auto  SPAWN5A_POIJA8_FLIP = true;		//毒液忍者8
	//スポーンブロック5B
	constexpr auto  SPAWN5B_XPOSITION = 4900;	constexpr auto  SPAWN5B_YPOSITION = 6320;	//スポーンブロック5B
	constexpr auto  SPAWN5B_SHIEL1_X = 5600;		constexpr auto  SPAWN5B_SHIEL1_Y = 6320;	constexpr auto  SPAWN5B_SHIEL1_FLIP = true;		//盾兵1
	constexpr auto  SPAWN5B_SHIEL2_X = 5400;		constexpr auto  SPAWN5B_SHIEL2_Y = 6320;	constexpr auto  SPAWN5B_SHIEL2_FLIP = false;		//盾兵2
	//スポーンブロック5C
	constexpr auto  SPAWN5C_XPOSITION = 5500;	constexpr auto  SPAWN5C_YPOSITION = 6320;	//スポーンブロック5C
	constexpr auto  SPAWN5C_BUSHI1_X = 4600;	constexpr auto  SPAWN5C_BUSHI1_Y = 5560;	constexpr auto  SPAWN5C_BUSHI1_FLIP = true;	//武士1
	constexpr auto  SPAWN5C_BUSHI2_X = 3000;	constexpr auto  SPAWN5C_BUSHI2_Y = 4800;	constexpr auto  SPAWN5C_BUSHI2_FLIP = true;	//武士2
	constexpr auto  SPAWN5C_BUSHI3_X = 4000;	constexpr auto  SPAWN5C_BUSHI3_Y = 3280;	constexpr auto  SPAWN5C_BUSHI3_FLIP = true;	//武士3
	constexpr auto  SPAWN5C_BUSYO1_X = 4800;	constexpr auto  SPAWN5C_BUSYO1_Y = 4800;	constexpr auto  SPAWN5C_BUSYO1_FLIP = true;	//武将1
	constexpr auto  SPAWN5C_LANCE1_X = 3700;	constexpr auto  SPAWN5C_LANCE1_Y = 3280;	constexpr auto  SPAWN5C_LANCE1_FLIP = true;	//槍兵1
	constexpr auto  SPAWN5C_NINJA1_X = 4300;		constexpr auto  SPAWN5C_NINJA1_Y = 5560;		constexpr auto  SPAWN5C_NINJA1_FLIP = true;	constexpr auto  SPAWN5C_NINJA1_KUNAI = 1;	//忍者1
	constexpr auto  SPAWN5C_NINJA2_X = 2400;		constexpr auto  SPAWN5C_NINJA2_Y = 4800;		constexpr auto  SPAWN5C_NINJA2_FLIP = true;	constexpr auto  SPAWN5C_NINJA2_KUNAI = 1;	//忍者2
	constexpr auto  SPAWN5C_NINJA3_X = 2100;		constexpr auto  SPAWN5C_NINJA3_Y = 3280;		constexpr auto  SPAWN5C_NINJA3_FLIP = true;	constexpr auto  SPAWN5C_NINJA3_KUNAI = 2;	//忍者3
	constexpr auto  SPAWN5C_ZYONI1_X = 5600;		constexpr auto  SPAWN5C_ZYONI1_Y = 4800;		constexpr auto  SPAWN5C_ZYONI1_FLIP = false;	constexpr auto  SPAWN5C_ZYONI1_KUNAI = 6;	//上忍1
	//スポーンブロック6A
	constexpr auto  SPAWN6A_XPOSITION = 3500;	constexpr auto  SPAWN6A_YPOSITION = 5560;	//スポーンブロック6A
	constexpr auto  SPAWN6A_SHIEL1_X = 2500;		constexpr auto	 SPAWN6A_SHIEL1_Y = 5560;		constexpr auto	SPAWN6A_SHIEL1_FLIP = true;	//盾兵1
	constexpr auto  SPAWN6A_SHIEL2_X = 2200;		constexpr auto	 SPAWN6A_SHIEL2_Y = 5560;		constexpr auto	SPAWN6A_SHIEL2_FLIP = true;	//盾兵2
	//スポーンブロック8A
	constexpr auto  SPAWN8A_XPOSITION = 4900;	constexpr auto SPAWN8A_YPOSITION = 4040;	//スポーンブロック8A
	constexpr auto  SPAWN8A_BUSHI1_X = 4500;	constexpr auto  SPAWN8A_BUSHI1_Y = 2520;	constexpr auto  SPAWN8A_BUSHI1_FLIP = true;	//武士1
	constexpr auto  SPAWN8A_SHIEL1_X = 5100;		constexpr auto  SPAWN8A_SHIEL1_Y = 2520;		constexpr auto  SPAWN8A_SHIEL1_FLIP = true;	//盾兵1
	constexpr auto  SPAWN8A_BUSYO1_X = 5500;	constexpr auto  SPAWN8A_BUSYO1_Y = 2520;	constexpr auto  SPAWN8A_BUSYO1_FLIP = true;	//武将1
	constexpr auto  SPAWN8A_BOSS1_X = 4200;	constexpr auto  SPAWN8A_BOSS1_Y = 1760;	constexpr auto  SPAWN8A_BOSS1_FLIP = true;	//ボス
	//スポーンブロック9A
	constexpr auto  SPAWN9A_XPOSITION = 3600;	constexpr auto SPAWN9A_YPOSITION = 3280;	//スポーンブロック9A
	constexpr auto  SPAWN9A_BUSHI1_X = 2800;	constexpr auto  SPAWN9A_BUSHI1_Y = 3280;	constexpr auto  SPAWN9A_BUSHI1_FLIP = true;	//武士1
	constexpr auto  SPAWN9A_LANCE1_X = 2500;	constexpr auto  SPAWN9A_LANCE1_Y = 3280;	constexpr auto  SPAWN9A_LANCE1_FLIP = true;	//槍兵1
	constexpr auto  SPAWN9A_NINJA1_X = 4100;		constexpr auto  SPAWN9A_NINJA1_Y = 3280;		constexpr auto  SPAWN9A_NINJA1_FLIP = false;	constexpr auto  SPAWN9A_NINJA1_KUNAI = 2;	//忍者1
	//スポーンブロック9B
	constexpr auto  SPAWN9B_XPOSITION = 2100;	constexpr auto SPAWN9B_YPOSITION = 3280;	//スポーンブロック9B
	constexpr auto  SPAWN9B_BUSYO1_X = 500;		constexpr auto  SPAWN9B_BUSYO1_Y = 3280;	constexpr auto  SPAWN9B_BUSYO1_FLIP = true;	//武将1
	constexpr auto  SPAWN9B_LANCE1_X = 1000;	constexpr auto  SPAWN9B_LANCE1_Y = 3280;	constexpr auto  SPAWN9B_LANCE1_FLIP = true;	//槍兵1
	constexpr auto  SPAWN9B_SHIEL1_X = 1400;		constexpr auto  SPAWN9B_SHIEL1_Y = 3280;		constexpr auto  SPAWN9B_SHIEL1_FLIP = true;	//盾兵1
	constexpr auto  SPAWN9B_ZYONI1_X = 2600;		constexpr auto  SPAWN9B_ZYONI1_Y = 3280;		constexpr auto  SPAWN9B_ZYONI1_FLIP = true;	constexpr auto  SPAWN9B_ZYONI1_KUNAI = 4;	//上忍1
	//スポーンブロック10A
	constexpr auto  SPAWN10A_XPOSITION = 1000;	constexpr auto SPAWN10A_YPOSITION = 2520;	//スポーンブロック10A
	constexpr auto  SPAWN10A_BUSHI1_X = 600;	constexpr auto  SPAWN10A_BUSHI1_Y = 2520;	constexpr auto  SPAWN10A_BUSHI1_FLIP = true;		//武士1
	constexpr auto  SPAWN10A_BUSHI2_X = 1500;	constexpr auto  SPAWN10A_BUSHI2_Y = 2520;	constexpr auto  SPAWN10A_BUSHI2_FLIP = false;	//武士2
	constexpr auto  SPAWN10A_BUSHI3_X = 2000;	constexpr auto  SPAWN10A_BUSHI3_Y = 2520;	constexpr auto  SPAWN10A_BUSHI3_FLIP = false;	//武士3
	constexpr auto  SPAWN10A_LANCE1_X = 1800;	constexpr auto  SPAWN10A_LANCE1_Y = 2520;	constexpr auto  SPAWN10A_LANCE1_FLIP = false;	//槍兵1
	constexpr auto  SPAWN10A_NINJA1_X = 2400;	constexpr auto  SPAWN10A_NINJA1_Y = 2520;	constexpr auto  SPAWN10A_NINJA1_FLIP = true;	constexpr auto  SPAWN10A_NINJA1_KUNAI = 2;	//忍者1
	//スポーンブロック10B
	constexpr auto  SPAWN10B_XPOSITION = 2500; constexpr auto SPAWN10B_YPOSITION = 2520;	//スポーンブロック10B
	constexpr auto  SPAWN10B_BUSHI1_X = 1800;	constexpr auto  SPAWN10B_BUSHI1_Y = 2520;	constexpr auto  SPAWN10B_BUSHI1_FLIP = true;	//武士1
	constexpr auto  SPAWN10B_BUSHI2_X = 3000;	constexpr auto  SPAWN10B_BUSHI2_Y = 2520;	constexpr auto  SPAWN10B_BUSHI2_FLIP = false;	//武士2
	constexpr auto  SPAWN10B_BUSHI3_X = 3600;	constexpr auto  SPAWN10B_BUSHI3_Y = 2520;	constexpr auto  SPAWN10B_BUSHI3_FLIP = false;	//武士3
	constexpr auto  SPAWN10B_SHIEL1_X = 3300;	constexpr auto  SPAWN10B_SHIEL1_Y = 2520;	constexpr auto  SPAWN10B_SHIEL1_FLIP = false;	//盾兵1
	constexpr auto  SPAWN10B_NINJA1_X = 2000;	constexpr auto  SPAWN10B_NINJA1_Y = 2520;	constexpr auto  SPAWN10B_NINJA1_FLIP = true;	constexpr auto  SPAWN10B_NINJA1_KUNAI = 1;	//忍者1
	constexpr auto  SPAWN10B_ZYONI1_X = 4200;	constexpr auto  SPAWN10B_ZYONI1_Y = 2520;	constexpr auto  SPAWN10B_ZYONI1_FLIP = true;	constexpr auto  SPAWN10B_ZYONI1_KUNAI = 4;	//上忍1
	//スポーンブロック11A
	constexpr auto  SPAWN11A_XPOSITION = 5200; constexpr auto SPAWN11A_YPOSITION = 1760;	//スポーンブロック11A
	constexpr auto  SPAWN11A_BUSHI1_X = 4600;	constexpr auto SPAWN11A_BUSHI1_Y = 1760;	constexpr auto SPAWN11A_BUSHI1_FLIP = true;		//武士1
	constexpr auto  SPAWN11A_NINJA1_X = 4300;  constexpr auto SPAWN11A_NINJA1_Y = 1760;  constexpr auto SPAWN11A_NINJA1_FLIP = true;	constexpr auto  SPAWN11A_NINJA1_KUNAI = 1;	//忍者1
	constexpr auto  SPAWN11A_POIJA1_X = 3700;	constexpr auto  SPAWN11A_POIJA1_Y = 1000;	constexpr auto  SPAWN11A_POIJA1_FLIP = true;		//毒液忍者1
	constexpr auto  SPAWN11A_POIJA2_X = 3500;	constexpr auto  SPAWN11A_POIJA2_Y = 1000;	constexpr auto  SPAWN11A_POIJA2_FLIP = true;		//毒液忍者2
	constexpr auto  SPAWN11A_POIJA3_X = 3200;	constexpr auto  SPAWN11A_POIJA3_Y = 1000;	constexpr auto  SPAWN11A_POIJA3_FLIP = true;		//毒液忍者3
	constexpr auto  SPAWN11A_POIJA4_X = 2900;	constexpr auto  SPAWN11A_POIJA4_Y = 1000;	constexpr auto  SPAWN11A_POIJA4_FLIP = true;		//毒液忍者4
	//スポーンブロック11B
	constexpr auto  SPAWN11B_XPOSITION = 4300;	constexpr auto SPAWN11B_YPOSITION = 1760;	//スポーンブロック11B
	constexpr auto  SPAWN11B_BUSHI1_X = 3200;	constexpr auto SPAWN11B_BUSHI1_Y = 1760;	constexpr auto SPAWN11B_BUSHI1_FLIP = true;		//武士1
	constexpr auto  SPAWN11B_SHIEL1_X = 3400;	constexpr auto  SPAWN11B_SHIEL1_Y = 1760;	constexpr auto  SPAWN11B_SHIEL1_FLIP = true;		//盾兵1
	//スポーンブロック11C
	constexpr auto  SPAWN11C_XPOSITION = 3900;	constexpr auto SPAWN11C_YPOSITION = 1760;	//スポーンブロック11C
	constexpr auto  SPAWN11C_ZYONI1_X = 2300;	constexpr auto  SPAWN11C_ZYONI1_Y = 1760;	constexpr auto  SPAWN11C_ZYONI1_FLIP = true;	constexpr auto  SPAWN11C_ZYONI1_KUNAI = 8;	//上忍1
	//スポーンブロック11D
	constexpr auto  SPAWN11D_XPOSITION = 2600;	constexpr auto SPAWN11D_YPOSITION = 1760;	//スポーンブロック11D
	constexpr auto  SPAWN11D_LANCE1_X = 1500;	constexpr auto  SPAWN11D_LANCE1_Y = 1760; constexpr auto  SPAWN11D_LANCE1_FLIP = false;	//槍兵1
	constexpr auto  SPAWN11D_SHIEL1_X = 1700;	constexpr auto  SPAWN11D_SHIEL1_Y = 1760; constexpr auto  SPAWN11D_SHIEL1_FLIP = false;		//盾兵1
	constexpr auto  SPAWN11D_NINJA1_X = 1300;  constexpr auto SPAWN11D_NINJA1_Y = 1760;  constexpr auto SPAWN11D_NINJA1_FLIP = true;		constexpr auto  SPAWN11D_NINJA1_KUNAI = 2;	//忍者1
	//スポーンブロック11E
	constexpr auto  SPAWN11E_XPOSITION = 1000; constexpr auto SPAWN11E_YPOSITION = 1760;	//スポーンブロック11E
	constexpr auto  SPAWN11E_BUSYO1_X = 1700;	constexpr auto  SPAWN11E_BUSYO1_Y = 1760; constexpr auto SPAWN11E_BUSYO1_FLIP = false;	//武将1
	constexpr auto  SPAWN11E_BUSYO2_X = 2000;	constexpr auto  SPAWN11E_BUSYO2_Y = 1760; constexpr auto  SPAWN11E_BUSYO2_FLIP = false;	//武将2
	//スポーンブロック11F
	constexpr auto  SPAWN11F_XPOSITION = 700; constexpr auto SPAWN11F_YPOSITION = 1760;	//スポーンブロック11F
	constexpr auto  SPAWN11F_BUSHI1_X = 1300;	constexpr auto  SPAWN11F_BUSHI1_Y = 1000; constexpr auto SPAWN11F_BUSHI1_FLIP = false;	//武士1
	constexpr auto  SPAWN11F_NINJA1_X = 1600;	constexpr auto  SPAWN11F_NINJA1_Y = 1000; constexpr auto  SPAWN11F_NINJA1_FLIP = false; constexpr auto  SPAWN11F_NINJA1_KUNAI = 1;//忍者1
	//スポーンブロック12A
	constexpr auto  SPAWN12A_XPOSITION = 1400;	constexpr auto SPAWN12A_YPOSITION = 1000;	//スポーンブロック12A
	constexpr auto  SPAWN12A_BUSHI1_X = 2300;	constexpr auto  SPAWN12A_BUSHI1_Y = 1000;	constexpr auto  SPAWN12A_BUSHI1_FLIP = false;	//武士1
	constexpr auto  SPAWN12A_BUSHI2_X = 2900;	constexpr auto  SPAWN12A_BUSHI2_Y = 1000;	constexpr auto  SPAWN12A_BUSHI2_FLIP = false;	//武士2
	constexpr auto  SPAWN12A_NINJA1_X = 950;	constexpr auto  SPAWN12A_NINJA1_Y = 1000;	constexpr auto  SPAWN12A_NINJA1_FLIP = true;	constexpr auto  SPAWN12A_NINJA1_KUNAI = 2;	//忍者1
	constexpr auto  SPAWN12A_ZYONI1_X = 3200;	constexpr auto  SPAWN12A_ZYONI1_Y = 1000;	constexpr auto  SPAWN12A_ZYONI1_FLIP = true;	constexpr auto  SPAWN12A_ZYONI1_KUNAI = 4;	//上忍1
	constexpr auto  SPAWN12A_SHIEL1_X = 2000;	constexpr auto  SPAWN12A_SHIEL1_Y = 1000;	constexpr auto  SPAWN12A_SHIEL1_FLIP = false;	//盾兵1
	constexpr auto  SPAWN12A_SHIEL2_X = 2600;	constexpr auto  SPAWN12A_SHIEL2_Y = 1000;	constexpr auto  SPAWN12A_SHIEL2_FLIP = false;	//盾兵2
	constexpr auto  SPAWN12A_BOSS2_X = 5050;	constexpr auto  SPAWN12A_BOSS2_Y = 1000;	constexpr auto  SPAWN12A_BOSS2_FLIP = false;	//ボス
	//スポーンブロック12B
	constexpr auto  SPAWN12B_XPOSITION = 2100;	constexpr auto SPAWN12B_YPOSITION = 1000;	//スポーンブロック12B
	constexpr auto  SPAWN12B_BUSHI1_X = 1800;	constexpr auto  SPAWN12B_BUSHI1_Y = 1000;	constexpr auto  SPAWN12B_BUSHI1_FLIP = false;	//武士1
	constexpr auto  SPAWN12B_LANCE1_X = 1600;	constexpr auto  SPAWN12B_LANCE1_Y = 1000; constexpr auto  SPAWN12B_LANCE1_FLIP = false;	//槍兵1
	//スポーンブロック12C
	constexpr auto  SPAWN12C_XPOSITION = 3200; constexpr auto SPAWN12C_YPOSITION = 1000;	//スポーンブロック12C
	constexpr auto  SPAWN12C_BUSYO1_X = 4200;	constexpr auto  SPAWN12C_BUSYO1_Y = 1000;	constexpr auto  SPAWN12C_BUSYO1_FLIP = false;	//武将1

}
