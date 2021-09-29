#pragma once

class Game;
class EventHappen {
public:
	EventHappen(Game& g);
	~EventHappen();

	void Init(Game& g);
private:
	void TutorialAppear(Game& g);
};

namespace EHInfo {
	/*----------各イベントブロック座標等----------*/
	//回復ブロック
	constexpr auto RECOVERY_X = 2700;
	constexpr auto RECOVERY_Y = 4040;
	//ボスイベントブロックA
	constexpr auto BOSSA_X = 5300;
	constexpr auto BOSSA_Y = 1760;
	//ボスイベントブロックB
	constexpr auto BOSSB_X = 4500;
	constexpr auto BOSSB_Y = 1000;
	//炎演出ブロック
	constexpr auto FLAME_X = 500;
	constexpr auto FLAME_Y = 1760;
}