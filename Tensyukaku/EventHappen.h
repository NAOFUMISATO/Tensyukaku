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
	//�`���[�g���A���u���b�N
	constexpr auto TUTORIAL1_X = 4300;
	constexpr auto TUTORIAL1_Y = 9360;
	constexpr auto TUTORIAL1_NUM = 1;
	constexpr auto TUTORIAL2_X = 5000;
	constexpr auto TUTORIAL2_Y = 8600;
	constexpr auto TUTORIAL2_NUM = 2;
	constexpr auto TUTORIAL3_X = 3400;
	constexpr auto TUTORIAL3_Y = 8600;
	constexpr auto TUTORIAL3_NUM = 3;
	constexpr auto TUTORIAL4_X = 2500;
	constexpr auto TUTORIAL4_Y = 7840;
	constexpr auto TUTORIAL4_NUM = 4;
	constexpr auto TUTORIAL5_X = 3250;
	constexpr auto TUTORIAL5_Y = 7080;
	constexpr auto TUTORIAL5_NUM = 5;
	//�񕜃u���b�N
	constexpr auto RECOVERY_X = 2700;
	constexpr auto RECOVERY_Y = 4040;
	//�`�F�b�N�|�C���g
	constexpr auto CPOINT_X = 5600;
	constexpr auto CPOINT_Y = 1760;
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