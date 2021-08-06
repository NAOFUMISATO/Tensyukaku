#include <DxLib.h>
#include "EnemyBase.h"
#include "Bushi.h"
#include "Game.h"
#include "BushiPatrolCollision.h"
#include "ObjectBase.h"
using namespace Tsk;
using namespace BInfo;
void Bushi::Patrol(Game& g) {
	if (_Cnt - _Action_Cnt == Patrol_Frame) {
		_isFlip = true;
	}
	if (_Cnt - _Action_Cnt == Patrol_Frame + Patrol_Frame) {
		_isFlip = false;
		_Action_Cnt=_Cnt;
	}
	if (_isFlip == false) {
		//武士の索敵範囲判定オブジェクトの生成
		BushiPatrolCollision BPC;

		// 武士の索敵範囲判定オブジェクトの開始位置をプレイヤー位置から算出
		BPC.SetPosition(_x + _hit_x - BPC.GetW(), _y - _hit_h);
		BPC.GetHitW();
		BPC.GetHitH();
		//索敵範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{

				// 索敵範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(BPC) == true)
				{
					_State = Bushi::ENEMYSTATE::COMING;
				}
			}
		}
	}

	if (_isFlip == true) {
		//武士の索敵範囲判定オブジェクトの生成
		BushiPatrolCollision BPC;
		// 武士の索敵範囲判定オブジェクトの開始位置をプレイヤー位置から算出
		BPC.SetPosition(_x - _hit_x, _y - _hit_h);
		BPC.GetHitW();
		BPC.GetHitH();
		BPC.Draw(g);
		//索敵範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				
				// 索敵範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(BPC) == true)
				{
					
					_State=Bushi::ENEMYSTATE::COMING;
				}
			}
		}
	
	}
	
}

