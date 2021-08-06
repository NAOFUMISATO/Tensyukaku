#include <DxLib.h>
#include "EnemyBase.h"
#include "Ninja.h"
#include "Game.h"
#include "NinjaMotionCollision.h"
#include "ObjectBase.h"
using namespace Tsk;
using namespace NInfo;
void Ninja::Patrol(Game& g) {
	if (_Cnt - _Action_Cnt == Patrol_Frame) {
		_isFlip = true;
	}
	if (_Cnt - _Action_Cnt == Patrol_Frame + Patrol_Frame) {
		_isFlip = false;
		_Action_Cnt = _Cnt;
	}
	if (_isFlip == false) {
		//武士の索敵範囲判定オブジェクトの生成
		NinjaPatrolCollision NPC;

		// 武士の索敵範囲判定オブジェクトの開始位置をプレイヤー位置から算出
		NPC.SetPosition(_x + _hit_x - NPC.GetW(), _y - _hit_h);
		NPC.GetHitW();
		NPC.GetHitH();
		//索敵範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{

				// 索敵範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(NPC) == true)
				{
					_State = Ninja::ENEMYSTATE::COMING;
				}
			}
		}
	}

	if (_isFlip == true) {
		//武士の索敵範囲判定オブジェクトの生成
		NinjaPatrolCollision NPC;
		// 武士の索敵範囲判定オブジェクトの開始位置をプレイヤー位置から算出
		NPC.SetPosition(_x - _hit_x, _y - _hit_h);
		NPC.GetHitW();
		NPC.GetHitH();
		NPC.Draw(g);
		//索敵範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{

				// 索敵範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(NPC) == true)
				{

					_State = Ninja::ENEMYSTATE::COMING;
				}
			}
		}
	}
}
void Ninja::Coming(Game& g) {
	if (_isFlip == false) {
		_x -= _Spd;
		//武士の攻撃発生範囲判定オブジェクトの生成
		NinjaComingCollision NCC;

		// 武士の攻撃発生範囲オブジェクトの開始位置をプレイヤー位置から算出
		NCC.SetPosition(_x + _hit_x - NCC.GetW(), _y - _hit_h);
		NCC.GetHitW();
		NCC.GetHitH();
		//攻撃発生範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{

				// 攻撃発生範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(NCC) == true)
				{
					_Action_Cnt = _Cnt;
					_State = Ninja::ENEMYSTATE::ATTACK;
				}
			}
		}
	}
	if (_isFlip == true) {
		_x += _Spd;
		//武士の攻撃発生範囲判定オブジェクトの生成
		NinjaComingCollision NCC;
		// 武士の攻撃発生範囲判定オブジェクトの開始位置をプレイヤー位置から算出
		NCC.SetPosition(_x - _hit_x, _y - _hit_h);
		NCC.GetHitW();
		NCC.GetHitH();
		NCC.Draw(g);
		//攻撃発生範囲判定オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 攻撃発生範囲判定オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(NCC) == true)
				{
					_Action_Cnt = _Cnt;
					_State = Ninja::ENEMYSTATE::ATTACK;
				}
			}
		}
	}
}

void Ninja::Attack(Game& g) {
	if (_Cnt - _Action_Cnt == ABegin_Frame) {
		//武士の攻撃判定オブジェクトの生成
		NinjaAttackCollision* NAC = new NinjaAttackCollision();
		if (_isFlip == false) {
			// 武士の攻撃判定オブジェクトの開始位置を武士位置から算出
			NAC->SetPosition(_x + _hit_x - NAC->GetW(), _y - _hit_h);
			// オブジェクトサーバ-に武士の攻撃判定オブジェクトを追加
			g.GetOS()->Add(NAC);
		};
		if (_isFlip == true) {
			// 武士の攻撃判定オブジェクトの開始位置を武士位置から算出
			NAC->SetPosition(_x - _hit_x, _y - _hit_h);
			// オブジェクトサーバ-に武士の攻撃判定オブジェクトを追加
			g.GetOS()->Add(NAC);
		}
	}
	if (_Cnt - _Action_Cnt == Attack_Frame)
	{
		_State = Ninja::ENEMYSTATE::PATROL;
	}
}

