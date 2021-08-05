#include <DxLib.h>
#include "EnemyBase.h"
#include "Bushi.h"
#include "Game.h"
#include "BushiPatrolCollision.h"
using namespace Tsk;
using namespace BInfo;
void Bushi::Patrol(Game& g) {
	if (_Cnt - _Action_Cnt == Patrol_Frame1) {
		_isFlip = true;
		//武士の索敵範囲判定オブジェクトの生成
		BushiPatrolCollision* BPC = new BushiPatrolCollision();
		// 武士の索敵範囲判定オブジェクトの開始位置をプレイヤー位置から算出
		BPC->SetPosition(_x - _hit_x, _y - _hit_h);
		// オブジェクトサーバ-に武士の索敵範囲判定オブジェクトを追加
		g.GetOS()->Add(BPC);
	}
	if (_Cnt - _Action_Cnt == Patrol_Frame2) {
		_isFlip = false;
		//武士の索敵範囲判定オブジェクトの生成
		BushiPatrolCollision* BPC = new BushiPatrolCollision();
		// 武士の索敵範囲判定オブジェクトの開始位置をプレイヤー位置から算出
		BPC->SetPosition(_x + _hit_x - BPC->GetW(), _y - _hit_h);
		// オブジェクトサーバ-に武士の索敵範囲判定オブジェクトを追加
		g.GetOS()->Add(BPC);
		 _Action_Cnt= _Cnt;
	}

	

	
		
	
}

