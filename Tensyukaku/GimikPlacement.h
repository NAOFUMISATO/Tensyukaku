#pragma once

class Game;
class GimikPlacement {
public:
	GimikPlacement(Game& g);
	~GimikPlacement();

	void Process(Game& g);

private:
	void StairAppear(Game& g);		//階段設定関数

	bool _Appear_Flag;
};

namespace GInfo {
	/*----------各階の階段位置&向き調整----------*/
	constexpr auto FLOOR1STAIR_X = 3650;
	constexpr auto FLOOR1STAIR_Y = 2200;
	constexpr auto FLOOR1STAIR_FLIP = false;
	constexpr auto FLOOR2STAIR_X = 200;
	constexpr auto FLOOR2STAIR_Y = 1440;
	constexpr auto FLOOR2STAIR_FLIP = true;
	constexpr auto FLOOR3STAIR_X = 3650;
	constexpr auto FLOOR3STAIR_Y = 680;
	constexpr auto FLOOR3STAIR_FLIP = false;
}