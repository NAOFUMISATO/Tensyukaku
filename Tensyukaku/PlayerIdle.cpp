#include <DxLib.h>
#include "Player.h"
#include "Game.h"
#include "MiddleAttackCollision.h"
using namespace Tsk;
void Player::Idle(Game& g) {
	if (g.GetKey() & PAD_INPUT_LEFT || g.GetKey() & PAD_INPUT_RIGHT) {
		_Action = PLAYERACTION::MOVE;
	}
	if (g.GetTrg() & PAD_INPUT_X) {
		_Action = PLAYERACTION::MIDDLEATTACK;
		_Action_Cnt = _Cnt;
		PlaySoundMem(_MiddleAttack_SEHandle, DX_PLAYTYPE_BACK, true);
	}
	if (g.GetTrg() & PAD_INPUT_Z) {
		_Action = PLAYERACTION::LOWATTACK;
		_Action_Cnt = _Cnt;
		PlaySoundMem(_LowAttack_SEHandle, DX_PLAYTYPE_BACK, true);
	}
	_MiddleAttack_AnimeNo = 0;
	_LowAttack_AnimeNo = 0;
}