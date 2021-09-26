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
	auto frame = _cnt - _action_cnt;
	_GrHandle = _GrAll["Appear"][_Anime["Appear"]];
	_Anime["Appear"] = (_cnt / ANIMESPEED_APPEAR) % APPEAR_ANIMEMAX;
	if (frame < APPEAR_ALLFRAME) {
		_alpha += FADEIN_SPEED;
	}
	if (frame == APPEAR_ALLFRAME) {
		_alpha = 255;
		_action_cnt = _cnt;
		_State = ENEMYSTATE::PATROL;
	}
}
/*----------巡回----------*/
void Shielder::Patrol(Game& g) {
	auto frame = _cnt - _action_cnt;
	_GrHandle = _GrAll["Patrol"][_Anime["Patrol"]];
	_Anime["Patrol"] = (_cnt / ANIMESPEED_PATROL) % PATROL_ANIMEMAX;
	if (frame == PATROL_TURNFRAME) {
		if (_isflip == false) {
			_isflip = true;
		}
		else { _isflip = false; }
	}
	if (frame == PATROL_TURNFRAME * 2) {
		if (_isflip == false) {
			_isflip = true;
		}
		else { _isflip = false; }
		_action_cnt = _cnt;
	}
	if (_isflip == false) {
		//盾兵の索敵範囲判定オブジェクトの生成
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
								if (_isflip == false) {
									_isflip = true;
								}
								else { _isflip = false; }
								_State = ENEMYSTATE::COMING;
							}
						}
					}
				}
			}
		}
	}
	if (_isflip == true) {
		//盾兵の索敵範囲判定オブジェクトの生成
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
								 if (_isflip == false) {
									 _isflip = true;
								 }
								 else { _isflip = false; }
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
void Shielder::Coming(Game& g) {
	_GrHandle = _GrAll["Coming"][_Anime["Coming"]];
	_Anime["Coming"] = (_cnt / ANIMESPEED_COMING) % COMING_ANIMEMAX;
	if (_isflip == false) {
		_x -= _spd;
		g.GetChip()->IsHit(*this, -1, 0);
		//盾兵の攻撃発生範囲判定オブジェクトの生成
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
					_action_cnt = _cnt;
					if (_ShieldAlive_Flag == false) {
						_State = ENEMYSTATE::ATTACK;
					}
					else {
						_State = ENEMYSTATE::GUARDATTACK;
					}
				}
			}
		}
		//盾兵の追跡中止範囲判定オブジェクトの生成
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
					_action_cnt = _cnt;
					_State = ENEMYSTATE::PATROL;
					_Anime["Coming"] = 0;
				}
			}
		}
	}
	if (_isflip == true) {
		_x += _spd;
		g.GetChip()->IsHit(*this, 1, 0);
		//盾兵の攻撃発生範囲判定オブジェクトの生成
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
					_action_cnt = _cnt;
					_Anime["Coming"] = 0;
					if (_ShieldAlive_Flag == false) {
						_State = ENEMYSTATE::ATTACK;
					}
					else {
						_State = ENEMYSTATE::GUARDATTACK;
					}
				}
			}
		}
		//盾兵の追跡中止範囲判定オブジェクトの生成
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
					_action_cnt = _cnt;
					_State = ENEMYSTATE::PATROL;
				}
			}
		}
	}
}
/*----------攻撃----------*/
void Shielder::Attack(Game& g) {
	auto frame = _cnt - _action_cnt;
	_GrHandle = _GrAll["Attack"][_Anime["Attack"]];
	if (frame<ATTACK_ANIMEFRAME){
		_Anime["Attack"] = ((frame) / ANIMESPEED_ATTACK) % ATTACK_ANIMEMAX; 
	}
	if (_isflip == false) {
		if (frame == STEP_BEGINFRAME) {
			_x -= ATTACK_STEP;
		}
		PrivateCollision acc(_x + _hit_x - ATTACKCANCEL_WIDTH, _y - _hit_h, ATTACKCANCEL_WIDTH, ATTACKCANCEL_HEIGHT);
		if (frame == ATTACK_ANIMEFRAME || frame == ATTACK_ALLFRAME) {
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
	if (_isflip == true) {
		if (frame == STEP_BEGINFRAME) {
			_x += ATTACK_STEP;
		}
		PrivateCollision acc(_x - _hit_x, _y - _hit_h, ATTACKCANCEL_WIDTH, ATTACKCANCEL_HEIGHT);
		if (frame == ATTACK_ANIMEFRAME || frame == ATTACK_ALLFRAME) {
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
	if (frame == ATTACK_BEGINFRAME) {
		PlaySoundMem(_Se["Attack"], DX_PLAYTYPE_BACK, true);
		if (_isflip == false) {
			//盾兵の攻撃判定オブジェクトの生成
			auto sac = new ShielderAttackCollision(_x + _hit_x - ATTACK_WIDTH, _y - _hit_h);
			// オブジェクトサーバ-に盾兵の攻撃判定オブジェクトを追加
			g.GetOS()->Add(sac);

		};
		if (_isflip == true) {
			//盾兵の攻撃判定オブジェクトの生成
			auto sac = new ShielderAttackCollision(_x - _hit_x, _y - _hit_h);
			// オブジェクトサーバ-に盾兵の攻撃判定オブジェクトを追加
			g.GetOS()->Add(sac);
		}
	}
	if (frame == ATTACK_ALLFRAME) {
		_action_cnt = _cnt;
	}
}

/*---------盾持ち攻撃----------*/
void Shielder::GuardAttack(Game& g) {
	auto frame = _cnt - _action_cnt;
	_GrHandle = _GrAll["GuardAttack"][_Anime["GuardAttack"]];
	if (frame < ATTACK_ANIMEFRAME) {
		_Anime["GuardAttack"] = ((frame) / ANIMESPEED_GUARDATTACK) % GUARDATTACK_ANIMEMAX;
	}
	if (_isflip == false) {
		if (frame == STEP_BEGINFRAME) {
			_x -=ATTACK_STEP;
		}
		PrivateCollision acc(_x + _hit_x - ATTACKCANCEL_WIDTH, _y - _hit_h, ATTACKCANCEL_WIDTH, ATTACKCANCEL_HEIGHT);
		if (frame == GUARDATTACK_ANIMEFRAME || frame == GUARDATTACK_ALLFRAME) {
			//攻撃中止範囲オブジェクトはプレイヤーに当たったか？
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// iteはプレイヤーか？
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// 攻撃中止範囲オブジェクトとプレイヤーの当たり判定を行う
					if ((*ite)->IsHit(acc) == false)
					{
						_Anime["GuardAttack"] = 0;
						_State = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
	if (_isflip == true) {
		if (frame == STEP_BEGINFRAME) {
			_x += ATTACK_STEP;
		}
		PrivateCollision acc(_x - _hit_x, _y - _hit_h, ATTACKCANCEL_WIDTH, ATTACKCANCEL_HEIGHT);
		if (frame == GUARDATTACK_ANIMEFRAME || frame == GUARDATTACK_ALLFRAME) {
			//攻撃中止範囲オブジェクトはプレイヤーに当たったか？
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// iteはプレイヤーか？
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// 攻撃中止範囲オブジェクトとプレイヤーの当たり判定を行う
					if ((*ite)->IsHit(acc) == false)
					{
						_Anime["GuardAttack"] = 0;
						_State = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
	if (frame == ATTACK_BEGINFRAME) {
		_ShieldAttack_Flag = true;
		_Shield_Cnt=_cnt;
		PlaySoundMem(_Se["Attack"], DX_PLAYTYPE_BACK, true);
		if (_isflip == false) {
			//盾兵の攻撃判定オブジェクトの生成
			auto sac = new ShielderAttackCollision(_x + _hit_x - ATTACK_WIDTH, _y - _hit_h);
			// オブジェクトサーバ-に盾兵の攻撃判定オブジェクトを追加
			g.GetOS()->Add(sac);

		};
		if (_isflip == true) {
			//盾兵の攻撃判定オブジェクトの生成
			auto sac = new ShielderAttackCollision(_x - _hit_x, _y - _hit_h);
			// オブジェクトサーバ-に盾兵の攻撃判定オブジェクトを追加
			g.GetOS()->Add(sac);
		}
	}
	if (frame == GUARDATTACK_ALLFRAME) {
		_ShieldAttack_Flag = false;
		_action_cnt = _cnt;
	}
}
/*----------盾崩し----------*/
void Shielder::GuardBreak(Game& g) {
	auto frame = _cnt - _action_cnt;
	_GrHandle =_GrAll["GuardBreak"][_Anime["GuardBreak"]];
	if (frame < GUARDBREAK_ANIMEFRAME) {
		_Anime["GuardBreak"] = ((frame) / ANIMESPEED_GUARDBREAK) % GUARDBREAK_ANIMEMAX;
	}
	if (frame == GUARDBREAK_ALLFRAME) {
	_action_cnt = _cnt;
	_State = ENEMYSTATE::COMING;
	}
}
/*----------死亡----------*/
void Shielder::Dead(Game& g) {
	auto frame = _cnt - _action_cnt;
	_GrHandle =_GrAll["Dead"][_Anime["Dead"]];
	_hit_x = 10000;
	if (frame < DEAD_ANIMEFRAME) {
		_Anime["Dead"] = ((frame) / ANIMESPEED_DEAD) % DEAD_ANIMEMAX;
	}
	if (frame >= DEAD_ANIMEFRAME && DEAD_ALLFRAME > frame) {
		_alpha -= FADEOUT_SPEED;
	}
	if (frame == DEAD_ALLFRAME) {
		Delete(g);
	}
}