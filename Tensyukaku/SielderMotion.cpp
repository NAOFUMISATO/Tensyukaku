#include <DxLib.h>
#include "EnemyBase.h"
#include "Shielder.h"
#include "Shield.h"
#include "Game.h"
#include "ShielderMotionCollision.h"
#include "ObjectBase.h"
#include <tuple>
#include <utility>

using namespace SInfo;

/*----------巡回----------*/
void Shielder::Patrol(Game& g) {
	_GrHandle = _GrAll["Patrol"][_Anime["Patrol"]];
	auto frame = _Cnt - _Action_Cnt;
	if (frame == PATROL_TURNFRAME) {
		_isFlip = true;
	}
	if (frame == PATROL_TURNFRAME *2) {
		_isFlip = false;
		_Action_Cnt = _Cnt;
	}
	if (_isFlip == false) {
		//盾兵の索敵範囲判定オブジェクトの生成
		ShielderPatrolCollision spc(_x + _hit_x - PATROL_WIDTH, _y - _hit_h);
		//索敵範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 索敵範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(spc) == true)
				{
					_State = ENEMYSTATE::COMING;
				}
			}
		}
	}
	if (_isFlip == true) {
		//武士の索敵範囲判定オブジェクトの生成
		ShielderPatrolCollision spc(_x - _hit_x, _y - _hit_h);
		//索敵範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 索敵範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(spc) == true)
				{
					_State = ENEMYSTATE::COMING;
				}
			}
		}

	}
	//敵とプレイヤーの中段攻撃オブジェクトの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーの中段攻撃オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::MIDDLEATTACK)
		{
			// 敵とプレイヤーの中段攻撃オブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
				if (_Shield_Flag == false) {
					_Life--;
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::DEAD;
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
				if (_Shield_Flag == false) {
					_Life--;
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::DEAD;
				}
			}
		}
	}
	//敵とプレイヤーのキックオブジェクトの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーのキックオブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::KICK)
		{
			// 敵とプレイヤーのキックオブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) はキックオブジェクト
				_Shield_Cnt = _Cnt;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::GUARDBREAK;
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
				_Shield_Cnt = _Cnt;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
}
/*----------追跡----------*/
void Shielder::Coming(Game& g) {
	_GrHandle = _GrAll["Coming"][_Anime["Coming"]];
	if (_isFlip == false) {
		_x -= _Spd;
		//盾兵の攻撃発生範囲判定オブジェクトの生成
		ShielderComingCollision scc(_x + _hit_x - COMING_WIDTH, _y - _hit_h);
		//攻撃発生範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{

				// 攻撃発生範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(scc) == true)
				{
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::ATTACK;
				}
			}
		}
	}
	if (_isFlip == true) {
		_x += _Spd;
		//盾兵の攻撃発生範囲判定オブジェクトの生成
		ShielderComingCollision scc(_x - _hit_x, _y - _hit_h);
		//攻撃発生範囲判定オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 攻撃発生範囲判定オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(scc) == true)
				{
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::ATTACK;
				}
			}
		}
	}
	//敵とプレイヤーの中段攻撃オブジェクトの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーの中段攻撃オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::MIDDLEATTACK)
		{
		// 敵とプレイヤーの中段攻撃オブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
				if (_Shield_Flag == false) {
					_Life--;
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::DEAD;
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
				if (_Shield_Flag == false) {
					_Life--;
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::DEAD;
				}
			}
		}
	}
	//敵とプレイヤーのキックオブジェクトの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーのキックオブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::KICK)
		{
			// 敵とプレイヤーのキックオブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) はキックオブジェクト
				_Shield_Cnt = _Cnt;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::GUARDBREAK;
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
				_Shield_Cnt = _Cnt;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
}
/*----------攻撃----------*/
void Shielder::Attack(Game& g) {
	_GrHandle = _GrAll["Attack"][_Anime["Attack"]];
	auto frame = _Cnt - _Action_Cnt;
	if (frame == ATTACK_BEGINFRAME) {
		if (_isFlip == false) {
			//盾兵の攻撃判定オブジェクトの生成
			auto sac = new ShielderAttackCollision(_x + _hit_x - ATTACK_WIDTH, _y - _hit_h);
			// オブジェクトサーバ-に盾兵の攻撃判定オブジェクトを追加
			g.GetOS()->Add(sac);

		};
		if (_isFlip == true) {
			//盾兵の攻撃判定オブジェクトの生成
			auto sac = new ShielderAttackCollision(_x - _hit_x, _y - _hit_h);
			// オブジェクトサーバ-に盾兵の攻撃判定オブジェクトを追加
			g.GetOS()->Add(sac);
		}
	}
	if (frame == ATTACK_ALLFRAME)
	{
		_State = ENEMYSTATE::PATROL;
	}
	//敵とプレイヤーの中段攻撃オブジェクトの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーの中段攻撃オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::MIDDLEATTACK)
		{
			// 敵とプレイヤーの中段攻撃オブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
				if (_Shield_Flag == false) {
					_Life--;
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::DEAD;
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
				if (_Shield_Flag == false) {
					_Life--;
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::DEAD;
				}
			}
		}
	}
	//敵とプレイヤーのキックオブジェクトの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーのキックオブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::KICK)
		{
			// 敵とプレイヤーのキックオブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) はキックオブジェクト
				_Shield_Cnt = _Cnt;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::GUARDBREAK;
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
				_Shield_Cnt = _Cnt;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
}
/*----------盾崩し----------*/
void Shielder::GuardBreak(Game& g) {
	_GrHandle =_GrAll["GuardBreak"][_Anime["GuardBreak"]];
	auto frame = _Cnt - _Action_Cnt;
	if (frame == GUARDBREAK_ALLFRAME) {
	_Action_Cnt = _Cnt;
	_State = ENEMYSTATE::PATROL;
	}
}
/*----------死亡----------*/
void Shielder::Dead(Game& g) {
	_GrHandle =_GrAll["Dead"][_Anime["Dead"]];
	auto frame = _Cnt - _Action_Cnt;
	if (frame == DEAD_ALLFRAME) {
		Delete(g);
	}
}