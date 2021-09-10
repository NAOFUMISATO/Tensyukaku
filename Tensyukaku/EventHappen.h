#pragma once

class Game;
class EventHappen {
public:
	EventHappen(Game& g);
	~EventHappen();

	void Init(Game& g);
};

namespace EHInfo {
	constexpr auto RECOVERY_X = 3200;
	constexpr auto RECOVERY_Y = 4040;
	constexpr auto CPOINT_X = 3500;
	constexpr auto CPOINT_Y = 4040;
}