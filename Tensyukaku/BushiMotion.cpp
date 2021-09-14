#include <DxLib.h>
#include "EnemyBase.h"
#include "Bushi.h"
#include "Game.h"
#include "BushiMotionCollision.h"
#include "ObjectBase.h"
#include "PrivateCollision.h"
#include <tuple>
#include <utility>

using namespace BInfo;
/*----------出現----------*/
void Bushi::Appear(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Appear"][_Anime["Appear"]];
	_Anime["Appear"] = (_Cnt / ANIMESPEED_APPEAR) % APPEAR_ANIMEMAX;
	if (frame < APPEAR_ALLFRAME) {
		_Alpha += FADEIN_SPEED;
	}
	if (frame == APPEAR_ALLFRAME) {
		_Alpha = 255;
		_State=ENEMYSTATE::PATROL;
	}
}

/*----------巡回----------*/
void Bushi::Patrol(Game& g) {
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
		//武士の索敵範囲判定オブジェクトの生成
		PrivateCollision bpc(_x + _hit_x - PATROL_WIDTH, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);

		//索敵範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 索敵範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(bpc) == true)
				{
					_State = ENEMYSTATE::COMING;
				}
			}
		}
	}
	if (_isFlip == true) {
		//武士の索敵範囲判定オブジェクトの生成
		PrivateCollision bpc(_x - _hit_x, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);

		//索敵範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 索敵範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(bpc) == true)
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
				_Life = 0;
				_Action_Cnt = _Cnt;
				_State =ENEMYSTATE::DEAD;
				//居合ゲージの増加
				//居合ゲージの増加
				for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
				{
					// iteはプレイヤか？
					if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
					{
						auto ig = (*ite)->GetGauge();
						if (ig < PLAYER_IAI_MAX) {
							(*ite)->SetGauge(ig += 1);
						}
					}
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
				_State =ENEMYSTATE::DAMAGE;
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
				_Life -= 3;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
}
/*----------追跡----------*/
void Bushi::Coming(Game& g) {
	_GrHandle = _GrAll["Coming"][_Anime["Coming"]];
	_Anime["Coming"] = (_Cnt / ANIMESPEED_COMING) % COMING_ANIMEMAX;
	if (_isFlip == false) {
		_x -= _Spd;
		g.GetChip()->IsHit(*this, -1, 0);
		//武士の攻撃発生範囲判定オブジェクトの生成
		PrivateCollision bcc(_x + _hit_x - COMING_WIDTH, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
		//攻撃発生範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 攻撃発生範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(bcc) == true)
				{
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::ATTACK;
				}
			}
		}
		//武士の追跡中止範囲判定オブジェクトの生成
		PrivateCollision bccc(_x + _hit_x - COMINGCANCEL_WIDTH, _y - _hit_h, COMINGCANCEL_WIDTH, COMINGCANCEL_HEIGHT);
		//追跡中止範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 追跡中止範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(bccc) == false)
				{
					_Action_Cnt;
					_State = ENEMYSTATE::PATROL;
				}
			}
		}	
	}
	if (_isFlip == true) {
		_x += _Spd;
		g.GetChip()->IsHit(*this, 1, 0);
		//武士の攻撃発生範囲判定オブジェクトの生成
		PrivateCollision bcc(_x - _hit_x, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
		//攻撃発生範囲判定オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{

				// 攻撃発生範囲判定オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(bcc) == true)
				{
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::ATTACK;
				}
			}
		}
		//武士の追跡中止範囲判定オブジェクトの生成
		PrivateCollision bccc(_x - _hit_x, _y - _hit_h, COMINGCANCEL_WIDTH, COMINGCANCEL_HEIGHT);
		//追跡中止範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 攻撃中止範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(bccc) == false)
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
				_Life -= 3;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
				//居合ゲージの増加
				for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
				{
					// iteはプレイヤか？
					if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
					{
						auto ig = (*ite)->GetGauge();
						if (ig < PLAYER_IAI_MAX) {
							(*ite)->SetGauge(ig += 1);
						}
					}
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
				_State = ENEMYSTATE::DAMAGE;
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
				_Life -= 3;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
}
/*----------攻撃----------*/
void Bushi::Attack(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Attack"][_Anime["Attack"]];
	if (frame<ATTACK_ANIMEFRAME) {
		_Anime["Attack"] = ((frame) / ANIMESPEED_ATTACK) % ATTACK_ANIMEMAX;
	}
	if (_isFlip == false) {
		if (frame == STEP_BEGINFRAME) {
			_x -= ATTACK_STEP;
		}
		if (frame == STEP_ENDFRAME) {
			_x += ATTACK_STEP;
		}
		PrivateCollision bacc(_x + _hit_x - ATTACKCANCEL_WIDTH, _y - _hit_h, ATTACKCANCEL_WIDTH, ATTACKCANCEL_HEIGHT);
		if (frame == ATTACK_ANIMEFRAME|| frame == ATTACK_ALLFRAME) {
			//攻撃中止範囲オブジェクトはプレイヤーに当たったか？
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// iteはプレイヤーか？
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// 攻撃中止範囲オブジェクトとプレイヤーの当たり判定を行う
					if ((*ite)->IsHit(bacc) == false)
					{
						_Anime["Attack"] = 0;
						_State = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
	if (_isFlip == true) {
		if (frame == STEP_BEGINFRAME) {
			_x += ATTACK_STEP;
		}
		if (frame == STEP_ENDFRAME) {
			_x -= ATTACK_STEP;
		}
		PrivateCollision bacc(_x - _hit_x, _y - _hit_h, ATTACKCANCEL_WIDTH, ATTACKCANCEL_HEIGHT);
		if (frame == ATTACK_ANIMEFRAME || frame==ATTACK_ALLFRAME) {
			//攻撃中止範囲オブジェクトはプレイヤーに当たったか？
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// iteはプレイヤーか？
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// 攻撃中止範囲オブジェクトとプレイヤーの当たり判定を行う
					if ((*ite)->IsHit(bacc) == false)
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
			//武士の攻撃判定オブジェクトの生成
			auto bac = new BushiAttackCollision(_x + _hit_x - ATTACK_WIDTH, _y - _hit_h);
			// オブジェクトサーバ-に武士の攻撃判定オブジェクトを追加
			g.GetOS()->Add(bac);
		};
		if (_isFlip == true) {
			//武士の攻撃判定オブジェクトの生成
			auto bac = new BushiAttackCollision(_x - _hit_x, _y - _hit_h);
			// オブジェクトサーバ-に武士の攻撃判定オブジェクトを追加
			g.GetOS()->Add(bac);
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
				_Life -= 3;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
				//居合ゲージの増加
				for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
				{
					// iteはプレイヤか？
					if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
					{
						auto ig = (*ite)->GetGauge();
						if (ig < PLAYER_IAI_MAX) {
							(*ite)->SetGauge(ig += 1);
						}
					}
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
				_Anime["Attack"] = 0;
				_State = ENEMYSTATE::DAMAGE;
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
				_Life -= 3;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
	if (frame == ATTACK_ALLFRAME) {
		_Action_Cnt=_Cnt;
	}
}
/*----------被ダメ----------*/
void Bushi::Damage(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Damage"][_Anime["Damage"]];
	if (frame < DAMAGE_ANIMEFRAME) {
		_Anime["Damage"] = ((frame) / ANIMESPEED_DAMAGE) % DAMAGE_ANIMEMAX;
	}
	if (frame == DAMAGE_ALLFRAME) {
		if (_Life <= 0) {
			_Action_Cnt = _Cnt;
			_State = ENEMYSTATE::DEAD;
		}
		else {
			_State = ENEMYSTATE::COMING;
		}
	}
}
/*----------死亡----------*/
void Bushi::Dead(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Dead"][_Anime["Dead"]];	
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