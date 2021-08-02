#include <DxLib.h>
#include "EnemyBase.h"
#include "Bushi.h"
#include "Game.h"
using namespace Tsk;
using namespace BInfo;
void Bushi::Patrol(Game& g) {
	_Action_Cnt=_Cnt;
	if (_Cnt - _Action_Cnt == Patrol_Frame1) {
		_isFlip = false;
	}
	if (_Cnt - _Action_Cnt == Patrol_Frame2) {
		_isFlip = true;
		_Action_Cnt=_Cnt;
	}
	
}

