#pragma once

class Game;
class EventHappen {
public:
	EventHappen(Game& g);
	~EventHappen();

	void Init(Game& g);
private:
	void TutorialAppear(Game& g);
	void CPointAppear(Game& g);
	void BossEventAppear(Game& g);
	void IngameTextAppear(Game& g);
	void RecoveryAppear(Game& g);
	void FlameAppear(Game& g);
};

namespace EHInfo {
	/*----------�e�C�x���g�u���b�N���W��----------*/
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