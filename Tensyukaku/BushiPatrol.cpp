#include <DxLib.h>
#include "EnemyBase.h"
#include "Bushi.h"
#include "Game.h"
using namespace Tsk;
using namespace BInfo;
void Bushi::Patrol(Game& g) {
	if (_Cnt - _Action_Cnt == Patrol_Frame1) {
		_isFlip = true;
	}
	if (_Cnt - _Action_Cnt == Patrol_Frame2) {
		_isFlip = false;
		 _Action_Cnt= _Cnt;
	}
	
}

