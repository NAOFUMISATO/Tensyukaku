#pragma once

class Game;
class EventHappen {
public:
	EventHappen(Game& g);
	~EventHappen();

	void Init(Game& g);
};

namespace EHInfo {
	constexpr auto RECOVERY_X = 2700;
	constexpr auto RECOVERY_Y = 4040;
	constexpr auto CPOINT_X = 3500;
	constexpr auto CPOINT_Y = 5560;
	constexpr auto BOSSA_X = 5300;
	constexpr auto BOSSA_Y = 1760;
	constexpr auto BOSSB_X = 4500;
	constexpr auto BOSSB_Y = 1000;
	constexpr auto FLAME_X = 500;
	constexpr auto FLAME_Y = 1760;
}