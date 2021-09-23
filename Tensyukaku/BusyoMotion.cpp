#include <DxLib.h>
#include "EnemyBase.h"
#include "Busyo.h"
#include "Game.h"
#include "BusyoMotionCollision.h"
#include "ObjectBase.h"
#include "PrivateCollision.h"
#include <tuple>
#include <utility>

using namespace BsInfo;
/*----------出現----------*/
void Busyo::Appear(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Appear"][_Anime["Appear"]];
	_Anime["Appear"] = (_Cnt / ANIMESPEED_APPEAR) % APPEAR_ANIMEMAX;
	if (frame < APPEAR_ALLFRAME) {
		_Alpha += FADEIN_SPEED;
	}
	if (frame == APPEAR_ALLFRAME) {
		_Alpha = 255;
		_Action_Cnt = _Cnt;
		_State = ENEMYSTATE::PATROL;
	}
}

/*----------巡回----------*/
void Busyo::Patrol(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Patrol"][_Anime["Patrol"]];
	_Anime["Patrol"] = (_Cnt / ANIMESPEED_PATROL) % PATROL_ANIMEMAX;
	if (frame == PATROL_TURNFRAME) {
		if (_isFlip == false) {
			_isFlip = true;
		}
		else { _isFlip = false; }
	}
	if (frame == PATROL_TURNFRAME * 2) {
		if (_isFlip == false) {
			_isFlip = true;
		}
		else { _isFlip = false; }
		_Action_Cnt = _Cnt;
	}
	if (_isFlip == false) {
		//索敵範囲判定オブジェクトの生成
		PrivateCollision pc(_x + _hit_x - PATROL_WIDTH, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
		PrivateCollision bpc(_x - _hit_x, _y - _hit_h, PATROL_BACKWIDTH, PATROL_HEIGHT);
		//索敵範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 索敵範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(pc) == true)
				{
					_State = ENEMYSTATE::COMING;
				}
				if ((*ite)->IsHit(bpc) == true)
				{
					for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
					{
						// iteはプレイヤーか？
						if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
						{
							auto ps = (*ite)->GetSpd();
							if (ps > 5) {
								if (_isFlip == false) {
									_isFlip = true;
								}
								else { _isFlip = false; }
								_State = ENEMYSTATE::COMING;
							}
						}
					}
				}
			}
		}
	}
	if (_isFlip == true) {
		//索敵範囲判定オブジェクトの生成
		PrivateCollision pc(_x - _hit_x, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
		PrivateCollision bpc(_x + _hit_x - PATROL_BACKWIDTH, _y - _hit_h, PATROL_BACKWIDTH, PATROL_HEIGHT);
		//索敵範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 索敵範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(pc) == true)
				{
					_State = ENEMYSTATE::COMING;
				}
				if ((*ite)->IsHit(bpc) == true)
				{
					for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
					{
						// iteはプレイヤーか？
						if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
						{
							auto ps = (*ite)->GetSpd();
							if (ps > 5) {
								if (_isFlip == false) {
									_isFlip = true;
								}
								else { _isFlip = false; }
								_Action_Cnt = _Cnt;
								_State = ENEMYSTATE::COMING;
							}
						}
					}
				}
			}
		}
	}
}
/*----------追跡----------*/
void Busyo::Coming(Game& g) {
	_GrHandle = _GrAll["Coming"][_Anime["Coming"]];
	_Anime["Coming"] = (_Cnt / ANIMESPEED_COMING) % COMING_ANIMEMAX;
	_noHit_Flag = false;
	if (_isFlip == false) {
		_x -= _Spd;
		g.GetChip()->IsHit(*this, -1, 0);
		//撃発生範囲判定オブジェクトの生成
		PrivateCollision cc(_x + _hit_x - COMING_WIDTH, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
		//攻撃発生範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 攻撃発生範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(cc) == true)
				{
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::ATTACK;
					_Anime["Coming"] = 0;
				}
			}
		}
		//追跡中止範囲判定オブジェクトの生成
		PrivateCollision ccc(_x + _hit_x - COMINGCANCEL_WIDTH, _y - _hit_h, COMINGCANCEL_WIDTH, COMINGCANCEL_HEIGHT);
		//追跡中止範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 追跡中止範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(ccc) == false)
				{
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::PATROL;
					_Anime["Coming"] = 0;
				}
			}
		}
	}
	if (_isFlip == true) {
		_x += _Spd;
		g.GetChip()->IsHit(*this, 1, 0);
		//攻撃発生範囲判定オブジェクトの生成
		PrivateCollision cc(_x - _hit_x, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
		//攻撃発生範囲判定オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{

				// 攻撃発生範囲判定オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(cc) == true)
				{
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::ATTACK;
					_Anime["Coming"] = 0;
				}
			}
		}
		//追跡中止範囲判定オブジェクトの生成
		PrivateCollision ccc(_x - _hit_x, _y - _hit_h, COMINGCANCEL_WIDTH, COMINGCANCEL_HEIGHT);
		//追跡中止範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 攻撃中止範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(ccc) == false)
				{
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::PATROL;
					_Anime["Coming"] = 0;
				}
			}
		}
	}
}
/*----------攻撃----------*/
void Busyo::Attack(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Attack"][_Anime["Attack"]];
	if (frame < ATTACK_ANIMEFRAME) {
		_Anime["Attack"] = ((frame) / ANIMESPEED_ATTACK) % ATTACK_ANIMEMAX;
	}
	if (_isFlip == false) {
		PrivateCollision acc(_x + _hit_x - ATTACKCANCEL_WIDTH, _y - _hit_h, ATTACKCANCEL_WIDTH, ATTACKCANCEL_HEIGHT);
		if ( frame == ATTACK_ALLFRAME) {
			//攻撃中止範囲オブジェクトはプレイヤーに当たったか？
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// iteはプレイヤーか？
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// 攻撃中止範囲オブジェクトとプレイヤーの当たり判定を行う
					if ((*ite)->IsHit(acc) == false)
					{
						_Anime["Attack"] = 0;
						_State = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
	if (_isFlip == true) {
		PrivateCollision acc(_x - _hit_x, _y - _hit_h, ATTACKCANCEL_WIDTH, ATTACKCANCEL_HEIGHT);
		if ( frame == ATTACK_ALLFRAME) {
			//攻撃中止範囲オブジェクトはプレイヤーに当たったか？
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// iteはプレイヤーか？
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// 攻撃中止範囲オブジェクトとプレイヤーの当たり判定を行う
					if ((*ite)->IsHit(acc) == false)
					{
						_Anime["Attack"] = 0;
						_State = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
	if (frame == ATTACK_BEGINFRAME || frame == ATTACK_BEGIN2FRAME) {
		if (_isFlip == false) {
			_x -= ATTACK_STEP;
			//攻撃判定オブジェクトの生成
			auto bac = new BusyoAttackCollision(_x + _hit_x - ATTACK_WIDTH, _y - _hit_h);
			// オブジェクトサーバ-に武士の攻撃判定オブジェクトを追加
			g.GetOS()->Add(bac);
		};
		if (_isFlip == true) {
			_x += ATTACK_STEP;
			//攻撃判定オブジェクトの生成
			auto bac = new BusyoAttackCollision(_x - _hit_x, _y - _hit_h);
			// オブジェクトサーバ-に武士の攻撃判定オブジェクトを追加
			g.GetOS()->Add(bac);
		}
	}
	if (frame == ATTACK_ALLFRAME) {
		_Action_Cnt = _Cnt;
	}
}

/*----------被ダメ----------*/
void Busyo::Damage(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Damage"][_Anime["Damage"]];
	if (frame < DAMAGE_ANIMEFRAME) {
		_Anime["Damage"] = ((frame) / ANIMESPEED_DAMAGE) % DAMAGE_ANIMEMAX;
	}
	if (frame == DAMAGE_ALLFRAME) {
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				auto px=(*ite)->GetX();
				if (px < _x) {
					_isFlip = false;
				}
				else { _isFlip = true; }
			}
		}
		_Action_Cnt = _Cnt;
		_State = ENEMYSTATE::ATTACK;
		_Anime["Damage"] = 0;
	}
}
/*----------死亡----------*/
void Busyo::Dead(Game& g) {
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

