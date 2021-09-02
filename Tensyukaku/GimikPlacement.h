#pragma once
#include "Stair.h"
#include <unordered_map>
class Game;
class GimikPlacement {
public:
	GimikPlacement(Game& g);
	~GimikPlacement();

	void Process(Game& g);
private:
	void StairAppear(Game& g);		//階段設定関数
	//void PoisonAppear(Game& g);		//毒液忍者設定関数
	//void AndonAppear(Game& g);		//行燈設定関数
};

namespace GInfo {
	/*----------各ギミックの位置&向き----------*/
	//階段
	constexpr auto FLOOR1STAIR_X = 5560;	constexpr auto FLOOR1STAIR_Y = 7840;	constexpr auto FLOOR1STAIR_FLIP = false;
	constexpr auto FLOOR2STAIR_X = 2120;	constexpr auto FLOOR2STAIR_Y = 7080;	constexpr auto FLOOR2STAIR_FLIP = true;
	constexpr auto FLOOR3STAIR_X = 3650;	constexpr auto FLOOR3STAIR_Y = 6320;	constexpr auto FLOOR3STAIR_FLIP = false;
	constexpr auto FLOOR4STAIR_X = 200;		constexpr auto FLOOR4STAIR_Y = 5560;	constexpr auto FLOOR4STAIR_FLIP = true;
	//行燈

	//毒液忍者

}