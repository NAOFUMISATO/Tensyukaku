#include <DxLib.h>
#include "Player.h"
#include "Game.h"
using namespace Tsk;

void Player::Move(Game& g) {
	if (g.GetTrg() & PAD_INPUT_X) {
		_Action = PLAYERACTION::MIDDLEATTACK;
		_Action_Cnt = _Cnt;
		PlaySoundMem(_MiddleAttack_SEHandle, DX_PLAYTYPE_BACK, true);
	}
	else if (g.GetTrg() & PAD_INPUT_Z) {
		_Action = PLAYERACTION::LOWATTACK;
		_Action_Cnt = _Cnt;
		PlaySoundMem(_LowAttack_SEHandle, DX_PLAYTYPE_BACK, true);
	}
	else if (g.GetKey() & PAD_INPUT_LEFT)
	{
		_x -= _Spd;
		/*g.GetChips().IsHit(*this, -1, 0);*/
		_isFlip = false;

	}
	else if (g.GetKey() & PAD_INPUT_RIGHT)
	{
		_x += _Spd;
		/*g.GetChips().IsHit(*this, 1, 0);*/
		_isFlip = true;

	}
	else {
		_Action = PLAYERACTION::IDLE;
	}
}