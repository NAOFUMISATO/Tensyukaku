#include <DxLib.h>
#include "EnemyBase.h"
#include "Bushi.h"
#include "Game.h"
#include "BushiPatrolCollision.h"
using namespace Tsk;
using namespace BInfo;
void Bushi::Patrol(Game& g) {
	if(_Patrol_Flag==false){
		_Patrol_Flag = true;
		//武士の索敵範囲判定オブジェクトの生成
		BushiPatrolCollision* BPC = new BushiPatrolCollision();
		// 武士の索敵範囲判定オブジェクトの開始位置をプレイヤー位置から算出
		BPC->SetPosition(_x + _hit_x - BPC->GetW(), _y - _hit_h);
		// オブジェクトサーバ-に武士の索敵範囲判定オブジェクトを追加
		g.GetOS()->Add(BPC);
	}
	if (_Cnt - _Action_Cnt == Patrol_Frame) {
		_isFlip = true;
		//武士の索敵範囲判定オブジェクトの生成
		BushiPatrolCollision* BPC = new BushiPatrolCollision();
		// 武士の索敵範囲判定オブジェクトの開始位置をプレイヤー位置から算出
		BPC->SetPosition(_x - _hit_x, _y - _hit_h);
		// オブジェクトサーバ-に武士の索敵範囲判定オブジェクトを追加
		g.GetOS()->Add(BPC);
		//索敵範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 索敵範囲オブジェクトとプレイヤーの当たり判定を行う
				if (IsHitCO(*BPC) == true)
				{
					BPC->Damage(g);
					ENEMYSTATE::COMING;
				}
			}
		}
	
	}
	if (_Cnt - _Action_Cnt == Patrol_Frame+Patrol_Frame) {
		_isFlip = false;
		//武士の索敵範囲判定オブジェクトの生成
		BushiPatrolCollision* BPC = new BushiPatrolCollision();
		// 武士の索敵範囲判定オブジェクトの開始位置をプレイヤー位置から算出
		BPC->SetPosition(_x + _hit_x - BPC->GetW(), _y - _hit_h);
		// オブジェクトサーバ-に武士の索敵範囲判定オブジェクトを追加
		g.GetOS()->Add(BPC);
		//索敵範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 索敵範囲オブジェクトとプレイヤーの当たり判定を行う
				if (IsHitCC(*BPC) == true)
				{
					BPC->Damage(g);
					ENEMYSTATE::COMING;
				}
			}
		}
		_Action_Cnt = _Cnt;
	}
	
}

