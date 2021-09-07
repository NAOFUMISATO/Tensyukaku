#pragma once

class Game;
class EventHappen {
public:
	EventHappen(Game& g);
	~EventHappen();

	void Process(Game& g);
};

namespace EHInfo {
	constexpr auto RECOVERY_X = 3200;
	constexpr auto RECOVERY_Y = 4040;
}