#include <DxLib.h>
#include "EnemyBase.h"
#include "Shielder.h"
#include "Shield.h"
#include "Game.h"
#include "ShielderMotionCollision.h"
#include "ObjectBase.h"
#include "PrivateCollision.h"

using namespace SInfo;
/*----------出現----------*/
void Shielder::Appear(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Appear"][_Anime["Appear"]];
	_Anime["Appear"] = (_Cnt / ANIMESPEED_APPEAR) % APPEAR_ANIMEMAX;
	if (frame < APPEAR_ALLFRAME) {
		_Alpha += FADEIN_SPEED;
	}
	if (frame == APPEAR_ALLFRAME) {
		_Alpha = 255;
		_State = ENEMYSTATE::PATROL;
	}
}
/*----------巡回----------*/
void Shielder::Patrol(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Patrol"][_Anime["Patrol"]];
	_Anime["Patrol"] = (_Cnt / ANIMESPEED_PATROL) % PATROL_ANIMEMAX;
	if (frame == PATROL_TURNFRAME) {
		_isFlip = true;
	}
	if (frame == PATROL_TURNFRAME *2) {
		_isFlip = false;
		_Action_Cnt = _Cnt;
	}
	if (_isFlip == false) {
		//盾兵の索敵範囲判定オブジェクトの生成
		PrivateCollision spc(_x + _hit_x - PATROL_WIDTH, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
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
		//盾兵の索敵範囲判定オブジェクトの生成
		PrivateCollision spc(_x - _hit_x, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
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
				if (_Shield_Flag == true) {
					_Anime["Attack"] = 0;
					_Shield_Cnt = _Cnt;
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::GUARDBREAK;
				}
			}
		}
	}
		//敵とプレイヤーの居合オブジェクトの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーの居合オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::IAI || (*ite)->GetObjType() == OBJECTTYPE::FLAME)
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
	_Anime["Coming"] = (_Cnt / ANIMESPEED_COMING) % COMING_ANIMEMAX;
	if (_isFlip == false) {
		_x -= _Spd;
		//盾兵の攻撃発生範囲判定オブジェクトの生成
		PrivateCollision scc(_x + _hit_x - COMING_WIDTH, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
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
					if (_Shield_Flag == false) {
						_State = ENEMYSTATE::ATTACK;
					}
					else {
						_State = ENEMYSTATE::GUARDATTACK;
					}
				}
			}
		}
		//盾兵の追跡中止範囲判定オブジェクトの生成
		PrivateCollision sccc(_x + _hit_x - COMINGCANCEL_WIDTH, _y - _hit_h, COMINGCANCEL_WIDTH, COMINGCANCEL_HEIGHT);
		//追跡中止範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 追跡中止範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(sccc) == false)
				{
					_Action_Cnt;
					_State = ENEMYSTATE::PATROL;
				}
			}
		}
	}
	if (_isFlip == true) {
		_x += _Spd;
		//盾兵の攻撃発生範囲判定オブジェクトの生成
		PrivateCollision scc(_x - _hit_x, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
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
					if (_Shield_Flag == false) {
						_State = ENEMYSTATE::ATTACK;
					}
					else {
						_State = ENEMYSTATE::GUARDATTACK;
					}
				}
			}
		}
		//盾兵の追跡中止範囲判定オブジェクトの生成
		PrivateCollision sccc(_x - _hit_x, _y - _hit_h, COMINGCANCEL_WIDTH, COMINGCANCEL_HEIGHT);
		//追跡中止範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 攻撃中止範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(sccc) == false)
				{
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::PATROL;
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
				if (_Shield_Flag == true) {
					_Anime["Attack"] = 0;
					_Shield_Cnt = _Cnt;
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::GUARDBREAK;
				}
			}
		}
	}
	//敵とプレイヤーの居合オブジェクトの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーの居合オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::IAI || (*ite)->GetObjType() == OBJECTTYPE::FLAME)
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
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Attack"][_Anime["Attack"]];
	if (frame<ATTACK_ANIMEFRAME){
		_Anime["Attack"] = ((frame) / ANIMESPEED_ATTACK) % ATTACK_ANIMEMAX; 
	}
	if (_isFlip == false) {
		PrivateCollision sacc(_x + _hit_x - ATTACKCANCEL_WIDTH, _y - _hit_h, ATTACKCANCEL_WIDTH, ATTACKCANCEL_HEIGHT);
		if (frame == ATTACK_ANIMEFRAME || frame == ATTACK_ALLFRAME) {
			//攻撃中止範囲オブジェクトはプレイヤーに当たったか？
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// iteはプレイヤーか？
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// 攻撃中止範囲オブジェクトとプレイヤーの当たり判定を行う
					if ((*ite)->IsHit(sacc) == false)
					{
						_Anime["Attack"] = 0;
						_State = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
	if (_isFlip == true) {
		PrivateCollision sacc(_x - _hit_x, _y - _hit_h, ATTACKCANCEL_WIDTH, ATTACKCANCEL_HEIGHT);
		if (frame == ATTACK_ANIMEFRAME || frame == ATTACK_ALLFRAME) {
			//攻撃中止範囲オブジェクトはプレイヤーに当たったか？
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// iteはプレイヤーか？
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// 攻撃中止範囲オブジェクトとプレイヤーの当たり判定を行う
					if ((*ite)->IsHit(sacc) == false)
					{
						_Anime["Attack"] = 0;
						_State = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
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
	
	//敵とプレイヤーの居合オブジェクトの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーの居合オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::IAI|| (*ite)->GetObjType() == OBJECTTYPE::FLAME)
		{
			// 敵とプレイヤーの居合オブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				_Shield_Cnt = _Cnt;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
	if (frame == ATTACK_ALLFRAME) {
		_Action_Cnt = _Cnt;
	}
}

/*---------盾持ち攻撃----------*/
void Shielder::GuardAttack(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["GuardAttack"][_Anime["GuardAttack"]];
	if (frame < ATTACK_ANIMEFRAME) {
		_Anime["GuardAttack"] = ((frame) / ANIMESPEED_GUARDATTACK) % GUARDATTACK_ANIMEMAX;
	}
	if (_isFlip == false) {
		PrivateCollision sacc(_x + _hit_x - ATTACKCANCEL_WIDTH, _y - _hit_h, ATTACKCANCEL_WIDTH, ATTACKCANCEL_HEIGHT);
		if (frame == GUARDATTACK_ANIMEFRAME || frame == GUARDATTACK_ALLFRAME) {
			//攻撃中止範囲オブジェクトはプレイヤーに当たったか？
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// iteはプレイヤーか？
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// 攻撃中止範囲オブジェクトとプレイヤーの当たり判定を行う
					if ((*ite)->IsHit(sacc) == false)
					{
						_Anime["GuardAttack"] = 0;
						_State = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
	if (_isFlip == true) {
		PrivateCollision sacc(_x - _hit_x, _y - _hit_h, ATTACKCANCEL_WIDTH, ATTACKCANCEL_HEIGHT);
		if (frame == GUARDATTACK_ANIMEFRAME || frame == GUARDATTACK_ALLFRAME) {
			//攻撃中止範囲オブジェクトはプレイヤーに当たったか？
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// iteはプレイヤーか？
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// 攻撃中止範囲オブジェクトとプレイヤーの当たり判定を行う
					if ((*ite)->IsHit(sacc) == false)
					{
						_Anime["GuardAttack"] = 0;
						_State = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
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
				if (_Shield_Flag == true) {
					_Anime["GuardAttack"] = 0;
					_Shield_Cnt = _Cnt;
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::GUARDBREAK;
				}
			}
		}
	}
	//敵とプレイヤーの攻撃オブジェクトの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーの攻撃オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::MIDDLEATTACK|| (*ite)->GetObjType() == OBJECTTYPE::LOWATTACK)
		{
			// 敵とプレイヤーの攻撃オブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
			}
		}
	}

	//敵とプレイヤーの居合オブジェクトの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーの居合オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::IAI || (*ite)->GetObjType() == OBJECTTYPE::FLAME)
		{
			// 敵とプレイヤーの居合オブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				_Shield_Cnt = _Cnt;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
	if (frame == GUARDATTACK_ALLFRAME) {
		_Action_Cnt = _Cnt;
	}
}
/*----------盾崩し----------*/
void Shielder::GuardBreak(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle =_GrAll["GuardBreak"][_Anime["GuardBreak"]];
	if (frame < GUARDBREAK_ANIMEFRAME) {
		_Anime["GuardBreak"] = ((frame) / ANIMESPEED_GUARDBREAK) % GUARDBREAK_ANIMEMAX;
	}
	if (frame == GUARDBREAK_ALLFRAME) {
	_Action_Cnt = _Cnt;
	_State = ENEMYSTATE::COMING;
	}
}
/*----------死亡----------*/
void Shielder::Dead(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle =_GrAll["Dead"][_Anime["Dead"]];
	_hit_x = 10000;
	if (frame < DEAD_ANIMEFRAME) {
		_Anime["Dead"] = ((frame) / ANIMESPEED_DEAD) % DEAD_ANIMEMAX;
	}
	if (frame >= DEAD_ANIMEFRAME && DEAD_ALLFRAME > frame) {
		_Alpha -= FADEOUT_SPEED;
	}
	if (frame == DEAD_ALLFRAME) {
		Delete(g);
	}
}