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
	/*----------�e�C�x���g�u���b�N���W��----------*/
	//�񕜃u���b�N
	constexpr auto RECOVERY_X = 2700;
	constexpr auto RECOVERY_Y = 4040;
	//�{�X�C�x���g�u���b�NA
	constexpr auto BOSSA_X = 5300;
	constexpr auto BOSSA_Y = 1760;
	//�{�X�C�x���g�u���b�NB
	constexpr auto BOSSB_X = 4500;
	constexpr auto BOSSB_Y = 1000;
	//�����o�u���b�N
	constexpr auto FLAME_X = 500;
	constexpr auto FLAME_Y = 1760;
}