#include <DxLib.h>
#include "EnemyBase.h"
#include "Bushi.h"
#include "Game.h"
#include "BushiMotionCollision.h"
#include "ObjectBase.h"
using namespace Tsk;
using namespace BInfo;
void Bushi::Patrol(Game& g) {
	if (_Cnt - _Action_Cnt == Patrol_Frame) {
		_isFlip = true;
	}
	if (_Cnt - _Action_Cnt == Patrol_Frame + Patrol_Frame) {
		_isFlip = false;
		_Action_Cnt = _Cnt;
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

					_State = Bushi::ENEMYSTATE::COMING;
				}
			}
		}

	}

}
void Bushi::Coming(Game& g) {
	if (_isFlip == false) {
		_x -= _Spd;
		//武士の攻撃発生範囲判定オブジェクトの生成
		BushiComingCollision BCC;

		// 武士の攻撃発生範囲オブジェクトの開始位置をプレイヤー位置から算出
		BCC.SetPosition(_x + _hit_x - BCC.GetW(), _y - _hit_h);
		BCC.GetHitW();
		BCC.GetHitH();
		//攻撃発生範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{

				// 攻撃発生範囲オブジェクトとプレイヤーの当たり判定を行う
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
		//武士の攻撃発生範囲判定オブジェクトの生成
		BushiComingCollision BCC;
		// 武士の攻撃発生範囲判定オブジェクトの開始位置をプレイヤー位置から算出
		BCC.SetPosition(_x - _hit_x, _y - _hit_h);
		BCC.GetHitW();
		BCC.GetHitH();
		BCC.Draw(g);
		//攻撃発生範囲判定オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{

				// 攻撃発生範囲判定オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(BCC) == true)
				{
					_Action_Cnt = _Cnt;
					_State = Bushi::ENEMYSTATE::ATTACK;
				}
			}
		}
	}
}
void Bushi::Attack(Game& g) {
	if (_Cnt - _Action_Cnt == ABegin_Frame) {
		//武士の攻撃判定オブジェクトの生成
		BushiAttackCollision* BAC = new BushiAttackCollision();
		if (_isFlip == false) {
			// 武士の攻撃判定オブジェクトの開始位置を武士位置から算出
			BAC->SetPosition(_x + _hit_x - BAC->GetW(), _y - _hit_h);
			// オブジェクトサーバ-に武士の攻撃判定オブジェクトを追加
			g.GetOS()->Add(BAC);
		};
		if (_isFlip == true) {
			// 武士の攻撃判定オブジェクトの開始位置を武士位置から算出
			BAC->SetPosition(_x - _hit_x, _y - _hit_h);
			// オブジェクトサーバ-に武士の攻撃判定オブジェクトを追加
			g.GetOS()->Add(BAC);
		}
	}
	if (_Cnt - _Action_Cnt == Attack_Frame)
	{
		_State = Bushi::ENEMYSTATE::PATROL;
	}
}