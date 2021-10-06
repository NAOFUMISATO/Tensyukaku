#include <DxLib.h>
#include "EnemyBase.h"
#include "Ninja.h"
#include "Game.h"
#include "NinjaMotionCollision.h"
#include "ObjectBase.h"
#include "EnemyParticle.h"
#include "PrivateCollision.h"
#include "Kunai.h"

using namespace NInfo;
using namespace EPInfo;
/*----------出現----------*/
void Ninja::Appear(Game& g) {
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Appear"][_anime["Appear"]];
	_anime["Appear"] = (_cnt / ANIMESPEED_APPEAR) % APPEAR_ANIMEMAX;
	if (frame < APPEAR_ALLFRAME) {
		_alpha += FADEIN_SPEED;
	}
	if (frame == APPEAR_ALLFRAME) {
		_alpha = 255;
		_action_cnt = _cnt;
		_state = ENEMYSTATE::PATROL;
	}
}
/*----------巡回---------*/
void Ninja::Patrol(Game& g) {
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Patrol"][_anime["Patrol"]];
	_anime["Patrol"] = (_cnt / ANIMESPEED_PATROL) % PATROL_ANIMEMAX;
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
		//忍者の索敵範囲判定オブジェクトの生成
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
					_action_cnt = _cnt;
					if (_Kunai_Stock > 0) {
						_state = ENEMYSTATE::THROW;
					}
					else {
						_state = ENEMYSTATE::COMING;
					}
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
								if (_Kunai_Stock > 0) {
									_state = ENEMYSTATE::THROW;
								}
								else {
									_state = ENEMYSTATE::COMING;
								}
							}
						}
					}
				}
			}
		}
	}

	if (_isflip == true) {
		//忍者の索敵範囲判定オブジェクトの生成
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
					_action_cnt = _cnt;
					if (_Kunai_Stock > 0) {
						_state = ENEMYSTATE::THROW;
					}
					else {
						_state = ENEMYSTATE::COMING;
					}
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
								_action_cnt = _cnt;
								if (_Kunai_Stock > 0) {
									_state = ENEMYSTATE::THROW;
								}
								else {
									_state = ENEMYSTATE::COMING;
								}
							}
						}
					}
				}
			}
		}
	}
}
/*----------追跡----------*/
void Ninja::Coming(Game& g) {
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Coming"][_anime["Coming"]];
	if (frame < COMING_ALLFRAME) {
		_anime["Coming"] = ((frame) / ANIMESPEED_COMING) % COMING_ANIMEMAX;
	}
	if (frame >COMINGSPEED_UPFRAME && COMINGSPEED_DOWNFRAME >= frame) {
		_spd = COMING_UPSPEED;
	}
	else {
		_spd =SPEED;
	}
	if (_isflip == false) {
	
		_x -= _spd;
		g.GetChip()->IsHit(*this, -1, 0);
		//忍者の攻撃発生範囲判定オブジェクトの生成
		PrivateCollision cc(_x + _hit_x - COMING_WIDTH, _y - _hit_h,COMING_WIDTH,COMING_HEIGHT);
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
					_state = ENEMYSTATE::ATTACK;
					_anime["Coming"] = 0;
				}
			}
		}
		//忍者の追跡中止範囲判定オブジェクトの生成
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
					_action_cnt=_cnt;
					_state = ENEMYSTATE::PATROL;
					_anime["Coming"] = 0;
				}
			}
		}
	}
	if (_isflip == true) {
		_x += _spd;
		g.GetChip()->IsHit(*this, 1, 0);
		//忍者の攻撃発生範囲判定オブジェクトの生成
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
					_state = ENEMYSTATE::ATTACK;
					_anime["Coming"] = 0;
				}
			}
		}
		//忍者の追跡中止範囲判定オブジェクトの生成
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
					_state = ENEMYSTATE::PATROL;
					_anime["Coming"] = 0;
				}
			}
		}
	}
	if (frame == COMING_ALLFRAME) {
		_action_cnt = _cnt;
		_anime["Coming"] = 0;
	}
}
/*--------------攻撃---------------*/
void Ninja::Attack(Game& g) {
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Attack"][_anime["Attack"]];
	if (frame < ATTACK_ANIMEFRAME) {
		_anime["Attack"] = ((frame) / ANIMESPEED_ATTACK) % ATTACK_ANIMEMAX;
	}
	if (_isflip == false) {
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
						_action_cnt = _cnt;
						_anime["Attack"] = 0;
						_state = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
	if (_isflip == true) {
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
						_action_cnt = _cnt;
						_anime["Attack"] = 0;
						_state = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
	if (frame == ATTACK_BEGINFRAME) {
		PlaySoundMem(_se["Attack"],DX_PLAYTYPE_BACK,true);
		if (_isflip == false) {
			//忍者の攻撃判定オブジェクトの生成
			auto nac = new NinjaAttackCollision(_x + _hit_x - ATTACK_WIDTH, _y - _hit_h);
			// オブジェクトサーバ-に忍者の攻撃判定オブジェクトを追加
			g.GetOS()->Add(nac);
		};
		if (_isflip == true) {
			//忍者の攻撃判定オブジェクトの生成
			auto nac = new NinjaAttackCollision(_x - _hit_x, _y - _hit_h);
			// オブジェクトサーバ-に忍者の攻撃判定オブジェクトを追加
			g.GetOS()->Add(nac);
		}
	}
	if (frame == ATTACK_ALLFRAME) {
		_action_cnt = _cnt;
	}
}
/*---------クナイ投げ--------*/
void Ninja::Throw(Game& g) {
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Throw"][_anime["Throw"]];
	if (frame < THROW_ANIMEFRAME) {
		_anime["Throw"] = ((frame) / ANIMESPEED_THROW) % THROW_ANIMEMAX;
	}
	if (_isflip == false) {
		PrivateCollision acc(_x + _hit_x - THROWCANCEL_WIDTH, _y - _hit_h, THROWCANCEL_WIDTH, THROWCANCEL_HEIGHT);
		if (frame == THROW_ANIMEFRAME || frame == THROW_ALLFRAME) {
			if (_Kunai_Stock <= 0) {
				_action_cnt = _cnt;
				_anime["Throw"] = 0;
				_state = ENEMYSTATE::COMING;
			}
		}
		if (frame == 1) {
			for (int i = 0; i < KRESERVELIGHT_PARTICLE_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % KRESERVELIGHT_PARTICLE_RANDOMX1) - KRESERVELIGHT_PARTICLE_RANDOMX2) / KRESERVELIGHT_PARTICLE_RANDOMX3, ((rand() % -KRESERVELIGHT_PARTICLE_RANDOMY1) - KRESERVELIGHT_PARTICLE_RANDOMY2) / KRESERVELIGHT_PARTICLE_RANDOMY3);
				auto rl = new KunaiReserveLight(xy, dxy, true);
				g.GetOS()->Add(rl);
			}
			//攻撃中止範囲オブジェクトはプレイヤーに当たったか？
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// iteはプレイヤーか？
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// 攻撃中止範囲オブジェクトとプレイヤーの当たり判定を行う
					if ((*ite)->IsHit(acc) == false)
					{
						_action_cnt = _cnt;
						_anime["Throw"] = 0;
						_state = ENEMYSTATE::PATROL;
					}
				}
			}
		}
	}
	if (_isflip == true) {
		PrivateCollision acc(_x - _hit_x, _y - _hit_h, THROWCANCEL_WIDTH, THROWCANCEL_HEIGHT);
		if (frame == THROW_ANIMEFRAME || frame == THROW_ALLFRAME) {
			if (_Kunai_Stock <= 0) {
				_anime["Throw"] = 0;
				_action_cnt = _cnt;
				_state = ENEMYSTATE::COMING;
			}
		}
		if (frame == 1) {
			for (int i = 0; i < KRESERVELIGHT_PARTICLE_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % KRESERVELIGHT_PARTICLE_RANDOMX1) - KRESERVELIGHT_PARTICLE_RANDOMX2) / KRESERVELIGHT_PARTICLE_RANDOMX3, ((rand() % -KRESERVELIGHT_PARTICLE_RANDOMY1) - KRESERVELIGHT_PARTICLE_RANDOMY2) / KRESERVELIGHT_PARTICLE_RANDOMY3);
				auto rl = new KunaiReserveLight(xy, dxy, false);
				g.GetOS()->Add(rl);
			}
			//攻撃中止範囲オブジェクトはプレイヤーに当たったか？
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// iteはプレイヤーか？
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// 攻撃中止範囲オブジェクトとプレイヤーの当たり判定を行う
					if ((*ite)->IsHit(acc) == false)
					{
						_action_cnt = _cnt;
						_anime["Throw"] = 0;
						_state = ENEMYSTATE::PATROL;
					}
				}
			}
		}
	}
	if (frame == KUNAI_RELEASEFRAME) {
		_Kunai_Stock--;
		PlaySoundMem(_se["Kunai"], DX_PLAYTYPE_BACK, true);
		if (_isflip == false) {
			//クナイオブジェクトの生成
			auto ku = new Kunai(_x -110, _y -130,false, KUNAI_SPEED);
			// オブジェクトサーバ-にクナイオブジェクトを追加
			g.GetOS()->Add(ku);
		};
		if (_isflip == true) {
			//クナイオブジェクトの生成
			auto ku = new Kunai(_x + 110, _y - 130, true, KUNAI_SPEED);
			// オブジェクトサーバ-にクナイオブジェクトを追加
			g.GetOS()->Add(ku);

		}
	}
	if (frame == THROW_ALLFRAME) {
		_action_cnt = _cnt;
	}


}
/*---------死亡----------*/
void Ninja::Dead(Game& g) {
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Dead"][_anime["Dead"]];
	_hit_x = 10000;
	if (frame < DEAD_ANIMEFRAME) {
		_anime["Dead"] = ((frame) / ANIMESPEED_DEAD) % DEAD_ANIMEMAX;
	}
	if (frame >= DEAD_ANIMEFRAME && DEAD_ALLFRAME > frame) {
		_alpha -= FADEOUT_SPEED;
	}
	if (frame == DEAD_ALLFRAME)
	{
		Delete(g);
	}
}