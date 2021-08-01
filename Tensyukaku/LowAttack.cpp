#include <DxLib.h>
#include "Player.h"
#include "Game.h"
using namespace Tsk;
using namespace PInfo;
void Player::LowAttack(Game& g) {
	if (_Cnt - _Action_Cnt == LowAttack_Frame) {
		_Action = PLAYERACTION::IDLE;
	}
}