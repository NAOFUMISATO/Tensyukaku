#pragma once
#include "Stair.h"
#include <unordered_map>
class Game;
class GimikPlacement {
public:
	GimikPlacement(Game& g);
	~GimikPlacement();
	void Init(Game& g);
private:
	void StairAppear(Game& g);		//階段設定関数
	void AndonAppear(Game& g);		//行燈設定関数
};

namespace GInfo {
	/*----------各ギミックの位置&向き----------*/
	//階段
	constexpr auto  FLOOR1_STAIR_X = 5560;	 constexpr auto FLOOR1_STAIR_Y = 9360;	 constexpr auto FLOOR1_STAIR_FLIP = false;
	constexpr auto  FLOOR2_STAIR_X = 2120;	 constexpr auto FLOOR2_STAIR_Y = 8600;	 constexpr auto FLOOR2_STAIR_FLIP = true;
	constexpr auto  FLOOR3_STAIR_X = 3650;	 constexpr auto FLOOR3_STAIR_Y = 7840;	 constexpr auto FLOOR3_STAIR_FLIP = false;
	constexpr auto  FLOOR4_STAIR_X =  200;	 constexpr auto FLOOR4_STAIR_Y = 7080;	 constexpr auto FLOOR4_STAIR_FLIP = true;
	constexpr auto  FLOOR5_STAIR_X = 3650;	 constexpr auto FLOOR5_STAIR_Y = 6320;	 constexpr auto FLOOR5_STAIR_FLIP = false;
	constexpr auto  FLOOR6_STAIR_X = 2120;	 constexpr auto FLOOR6_STAIR_Y = 5560;	 constexpr auto FLOOR6_STAIR_FLIP = true;
	constexpr auto FLOOR7A_STAIR_X = 3650;	constexpr auto FLOOR7A_STAIR_Y = 4800;	constexpr auto FLOOR7A_STAIR_FLIP = false;
	constexpr auto FLOOR7B_STAIR_X = 4050;	constexpr auto FLOOR7B_STAIR_Y = 4800;	constexpr auto FLOOR7B_STAIR_FLIP = true;
	constexpr auto FLOOR8A_STAIR_X = 2120;	constexpr auto FLOOR8A_STAIR_Y = 4040;	constexpr auto FLOOR8A_STAIR_FLIP = true;
	constexpr auto FLOOR8B_STAIR_X = 5600;	constexpr auto FLOOR8B_STAIR_Y = 4040;	constexpr auto FLOOR8B_STAIR_FLIP = false;
	constexpr auto  FLOOR9_STAIR_X =  200;	 constexpr auto FLOOR9_STAIR_Y = 3280;	 constexpr auto FLOOR9_STAIR_FLIP = true;
	constexpr auto FLOOR10_STAIR_X = 5600;	constexpr auto FLOOR10_STAIR_Y = 2520;	constexpr auto FLOOR10_STAIR_FLIP = false;
	constexpr auto FLOOR11_STAIR_X = 200;	constexpr auto FLOOR11_STAIR_Y = 1760;	constexpr auto FLOOR11_STAIR_FLIP = true;

	//行燈
	constexpr auto  FLOOR6_ANDON_X = 2700;	 constexpr auto FLOOR6_ANDON_Y = 5560;
	constexpr auto  FLOOR7_ANDON_X = 3400;	 constexpr auto FLOOR7_ANDON_Y = 4800;
	constexpr auto FLOOR10_ANDON_X = 1800;	constexpr auto FLOOR10_ANDON_Y = 2520;
	constexpr auto FLOOR11A_ANDON_X = 5100;	constexpr auto FLOOR11A_ANDON_Y = 1760;
	constexpr auto FLOOR11B_ANDON_X = 3700;	constexpr auto FLOOR11B_ANDON_Y = 1760;
	constexpr auto FLOOR11C_ANDON_X = 1800;	constexpr auto FLOOR11C_ANDON_Y = 1760;
	constexpr auto FLOOR11D_ANDON_X = 900;	constexpr auto FLOOR11D_ANDON_Y = 1760;
	constexpr auto FLOOR12A_ANDON_X = 2300;	constexpr auto FLOOR12A_ANDON_Y = 1000;
}