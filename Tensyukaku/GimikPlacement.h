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
	void StairAppear(Game& g);		//ŠK’iİ’èŠÖ”
	void PoisonAppear(Game& g);		//“Å‰t”EÒİ’èŠÖ”
	void AndonAppear(Game& g);		//s“•İ’èŠÖ”
};

namespace GInfo {
	/*----------ŠeŠK‚ÌŠK’iˆÊ’u&Œü‚«’²®----------*/
	constexpr auto FLOOR1STAIR_X = 5560;
	constexpr auto FLOOR1STAIR_Y = 7840;
	constexpr auto FLOOR1STAIR_FLIP = false;
	constexpr auto FLOOR2STAIR_X = 2120;
	constexpr auto FLOOR2STAIR_Y = 7080;
	constexpr auto FLOOR2STAIR_FLIP = true;
	constexpr auto FLOOR3STAIR_X = 3650;
	constexpr auto FLOOR3STAIR_Y = 6320;
	constexpr auto FLOOR3STAIR_FLIP = false;
	constexpr auto FLOOR4STAIR_X = 200;
	constexpr auto FLOOR4STAIR_Y = 5560;
	constexpr auto FLOOR4STAIR_FLIP = true;
}