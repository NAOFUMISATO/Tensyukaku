#include <DxLib.h>
#include "EnemyBase.h"
#include "Bushi.h"
#include "Game.h"
#include "BushiComingCollision.h"
#include "ObjectBase.h"
using namespace Tsk;
using namespace BInfo;
void Bushi::Coming(Game& g) {
	if (_isFlip == false) {
		_x -= _Spd;
		//武士の索敵範囲判定オブジェクトの生成
		BushiComingCollision BCC;

		// 武士の索敵範囲判定オブジェクトの開始位置をプレイヤー位置から算出
		BCC.SetPosition(_x + _hit_x - BCC.GetW(), _y - _hit_h);
		BCC.GetHitW();
		BCC.GetHitH();
		//索敵範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{

				// 索敵範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(BCC) == true)
				{
					_Action_Cnt = _Cnt;
					_State = Bushi::ENEMYSTATE::ATTACK;
				}
			}
		}
	}
	if (_isFlip == true) {
		_x += _Spd;
		//武士の索敵範囲判定オブジェクトの生成
		BushiComingCollision BCC;
		// 武士の索敵範囲判定オブジェクトの開始位置をプレイヤー位置から算出
		BCC.SetPosition(_x - _hit_x, _y - _hit_h);
		BCC.GetHitW();
		BCC.GetHitH();
		BCC.Draw(g);
		//索敵範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{

				// 索敵範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(BCC) == true)
				{
					_Action_Cnt = _Cnt;
					_State = Bushi::ENEMYSTATE::ATTACK;
				}
			}
		}
	}
}