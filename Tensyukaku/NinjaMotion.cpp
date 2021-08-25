#include <DxLib.h>
#include "EnemyBase.h"
#include "Ninja.h"
#include "Game.h"
#include "NinjaMotionCollision.h"
#include "ObjectBase.h"

using namespace NInfo;
void Ninja::Patrol(Game& g) {
	_GrHandle = _Patrol_GrAll[_Patrol_AnimeNo];
	if (_Cnt - _Action_Cnt == PATROL_ALLFRAME) {
		_isFlip = true;
	}
	if (_Cnt - _Action_Cnt == PATROL_ALLFRAME + PATROL_ALLFRAME) {
		_isFlip = false;
		_Action_Cnt = _Cnt;
	}
	if (_isFlip == false) {
		//忍者の索敵範囲判定オブジェクトの生成
		NinjaPatrolCollision npc;

		// 忍者の索敵範囲判定オブジェクトの開始位置をプレイヤー位置から算出
		npc.SetPosition(_x + _hit_x - npc.GetHitW(), _y - _hit_h);
		//索敵範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 索敵範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(npc) == true)
				{
					_State = ENEMYSTATE::COMING;
				}
			}
		}
	}

	if (_isFlip == true) {
		//武士の索敵範囲判定オブジェクトの生成
		NinjaPatrolCollision npc;
		// 武士の索敵範囲判定オブジェクトの開始位置をプレイヤー位置から算出
		npc.SetPosition(_x - _hit_x, _y - _hit_h);
		//索敵範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 索敵範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(npc) == true)
				{
					_State = ENEMYSTATE::COMING;
				}
			}
		}
	}
	//敵とプレイヤーの下段攻撃オブジェクトの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーの下段攻撃オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::LOWATTACK)
		{
			// 敵とプレイヤーの下段攻撃オブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
				_Life--;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
	//敵とプレイヤーの居合オブジェクトの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーの居合オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::IAI)
		{
			// 敵とプレイヤーの居合オブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				_Life--;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
}
void Ninja::Coming(Game& g) {
	_GrHandle = _Coming_GrAll[_Coming_AnimeNo];
	if (_isFlip == false) {
		_x -= _Spd;
		//武士の攻撃発生範囲判定オブジェクトの生成
		NinjaComingCollision ncc;
		// 武士の攻撃発生範囲オブジェクトの開始位置をプレイヤー位置から算出
		ncc.SetPosition(_x + _hit_x - ncc.GetHitW(), _y - _hit_h);
		//攻撃発生範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 攻撃発生範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(ncc) == true)
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
		NinjaComingCollision ncc;
		// 武士の攻撃発生範囲判定オブジェクトの開始位置をプレイヤー位置から算出
		ncc.SetPosition(_x - _hit_x, _y - _hit_h);
		//攻撃発生範囲判定オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 攻撃発生範囲判定オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(ncc) == true)
				{
					_Action_Cnt = _Cnt;
					_State = Ninja::ENEMYSTATE::ATTACK;
				}
			}
		}
	}
	//敵とプレイヤーの下段攻撃オブジェクトの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーの下段攻撃オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::LOWATTACK)
		{
			// 敵とプレイヤーの下段攻撃オブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
				_Life--;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
	//敵とプレイヤーの居合オブジェクトの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーの居合オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::IAI)
		{
			// 敵とプレイヤーの居合オブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				_Life--;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
}

void Ninja::Attack(Game& g) {
	_GrHandle = _Attack_GrAll[_Attack_AnimeNo];
	if (_Cnt - _Action_Cnt == ATTACK_BEGINFRAME) {
		//忍者の攻撃判定オブジェクトの生成
		NinjaAttackCollision* nac = new NinjaAttackCollision();
		if (_isFlip == false) {
			// 忍者の攻撃判定オブジェクトの開始位置を武士位置から算出
			nac->SetPosition(_x + _hit_x - nac->GetHitW(), _y - _hit_h);
			// オブジェクトサーバ-に武士の攻撃判定オブジェクトを追加
			g.GetOS()->Add(nac);
		};
		if (_isFlip == true) {
			// 忍者の攻撃判定オブジェクトの開始位置を武士位置から算出
			nac->SetPosition(_x - _hit_x, _y - _hit_h);
			// オブジェクトサーバ-に武士の攻撃判定オブジェクトを追加
			g.GetOS()->Add(nac);
		}
	}
	if (_Cnt - _Action_Cnt == ATTACK_ALLFRAME)
	{
		_State = Ninja::ENEMYSTATE::PATROL;
	}
	//敵とプレイヤーの下段攻撃オブジェクトの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーの下段攻撃オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::LOWATTACK)
		{
			// 敵とプレイヤーの下段攻撃オブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
				_Life--;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
	//敵とプレイヤーの居合オブジェクトの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーの居合オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::IAI)
		{
			// 敵とプレイヤーの居合オブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				_Life--;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
}

void Ninja::Dead(Game& g) {
	_GrHandle = _Dead_GrAll[_Dead_AnimeNo];
	if (_Cnt - _Action_Cnt == DEAD_FRAME)
	{
		Delete(g);
	}
}