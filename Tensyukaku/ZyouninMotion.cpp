#include <DxLib.h>
#include "EnemyBase.h"
#include "Zyounin.h"
#include "Game.h"
#include "ZyouninMotionCollision.h"
#include "ObjectBase.h"
#include "PrivateCollision.h"
#include "Kunai.h"

using namespace ZInfo;
/*----------出現----------*/
void Zyounin::Appear(Game& g) {
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Appear"][_anime["Appear"]];
	_anime["Appear"] = (_cnt / ANIMESPEED_APPEAR) % APPEAR_ANIMEMAX;
	if (frame < APPEAR_ALLFRAME) {
		_alpha += FADEIN_SPEED;
	}
	//全フレーム経ったなら透明度をMAXにして、索敵状態へ移行
	if (frame == APPEAR_ALLFRAME) {
		_alpha = 255;
		_action_cnt = _cnt;
		_state = ENEMYSTATE::PATROL;
	}
}
/*----------巡回---------*/
void Zyounin::Patrol(Game& g) {
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Patrol"][_anime["Patrol"]];
	_anime["Patrol"] = (_cnt / ANIMESPEED_PATROL) % PATROL_ANIMEMAX;
	//一定時間ごとに振り返る処理
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
		//前方索敵範囲判定オブジェクトの生成
		PrivateCollision pc(_x + _hit_x - PATROL_WIDTH, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
		//後方索敵範囲判定オブジェクトの生成
		PrivateCollision bpc(_x - _hit_x, _y - _hit_h, PATROL_BACKWIDTH, PATROL_HEIGHT);
		//索敵範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++) {
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER) {
				//前方索敵範囲オブジェクトとプレイヤーが当たった場合、クナイが0個なら追跡状態へ移行、そうでないならクナイ投げ状態へ移行
				if ((*ite)->IsHit(pc) == true)
				{
					_action_cnt = _cnt;
					if (_kunai_stock > 0) {
						_state = ENEMYSTATE::THROW;
					}
					else {
						_state = ENEMYSTATE::COMING;
					}
				}
				//後方索敵範囲オブジェクトに当たっている且つ、プレイヤーの速さが一定以上なら振り返り、クナイが0個なら追跡状態へ移行、そうでないならクナイ投げ状態へ移行
				if ((*ite)->IsHit(bpc) == true) {
					auto ps = (*ite)->GetSpd();
					if (ps > 5) {
						if (_isflip == false) {
							_isflip = true;
						}
						else { _isflip = false; }
						if (_kunai_stock > 0) {
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
	if (_isflip == true) {
		//前方索敵範囲判定オブジェクトの生成
		PrivateCollision pc(_x - _hit_x, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
		//後方索敵範囲判定オブジェクトの生成
		PrivateCollision bpc(_x + _hit_x - PATROL_BACKWIDTH, _y - _hit_h, PATROL_BACKWIDTH, PATROL_HEIGHT);
		//索敵範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++) {
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER) {
				//前方索敵範囲オブジェクトとプレイヤーが当たった場合、クナイが0個なら追跡状態へ移行、そうでないならクナイ投げ状態へ移行
				if ((*ite)->IsHit(pc) == true) {
					_action_cnt = _cnt;
					if (_kunai_stock > 0) {
						_state = ENEMYSTATE::THROW;
					}
					else {
						_state = ENEMYSTATE::COMING;
					}
				}
				//後方索敵範囲オブジェクトに当たっている且つ、プレイヤーの速さが一定以上なら振り返り、クナイが0個なら追跡状態へ移行、そうでないならクナイ投げ状態へ移行
				if ((*ite)->IsHit(bpc) == true) {
					auto ps = (*ite)->GetSpd();
					if (ps > 5) {
						if (_isflip == false) {
							_isflip = true;
						}
						else { _isflip = false; }
						_action_cnt = _cnt;
						if (_kunai_stock > 0) {
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
/*----------追跡----------*/
void Zyounin::Coming(Game& g) {
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Coming"][_anime["Coming"]];
	if (frame < COMING_ALLFRAME) {
		_anime["Coming"] = ((frame) / ANIMESPEED_COMING) % COMING_ANIMEMAX;
	}
	if (frame > COMINGSPEED_UPFRAME && COMINGSPEED_DOWNFRAME >= frame) {
		_spd = COMING_UPSPEED;
	}
	else {
		_spd = SPEED;
	}
	if (_isflip == false) {

		_x -= _spd;
		g.GetChip()->IsHit(*this, -1, 0);
		//攻撃発生範囲判定オブジェクトの生成
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
					_state = ENEMYSTATE::ATTACK;
					_anime["Coming"] = 0;
				}
			}
		}
		//追跡中止範囲判定オブジェクトの生成
		PrivateCollision ccc(_x + _hit_x - COMINGCANCEL_WIDTH, _y - _hit_h, COMINGCANCEL_WIDTH, COMINGCANCEL_HEIGHT);
		//追跡中止範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER){
				// 追跡中止範囲オブジェクトとプレイヤーが当たらなくなったら索敵状態に移行
				if ((*ite)->IsHit(ccc) == false)
				{
					_action_cnt = _cnt;
					_state = ENEMYSTATE::PATROL;
					_anime["Coming"] = 0;
				}
			}
		}
	}
	if (_isflip == true) {
		_x += _spd;
		g.GetChip()->IsHit(*this, 1, 0);
		//攻撃発生範囲判定オブジェクトの生成
		PrivateCollision cc(_x - _hit_x, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
		//攻撃発生範囲判定オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 攻撃発生範囲判定オブジェクトとプレイヤーが当たらなくなったら索敵状態に移行
				if ((*ite)->IsHit(cc) == true)
				{
					_action_cnt = _cnt;
					_state = ENEMYSTATE::ATTACK;
					_anime["Coming"] = 0;
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
void Zyounin::Attack(Game& g) {
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
		PlaySoundMem(_se["Attack"], DX_PLAYTYPE_BACK, true);
		if (_isflip == false) {
			//攻撃判定オブジェクトの生成
			auto nac = new ZyouninAttackCollision(_x + _hit_x - ATTACK_WIDTH, _y - _hit_h);
			// オブジェクトサーバ-に忍者の攻撃判定オブジェクトを追加
			g.GetOS()->Add(nac);
		};
		if (_isflip == true) {
			//攻撃判定オブジェクトの生成
			auto nac = new ZyouninAttackCollision(_x - _hit_x, _y - _hit_h);
			// オブジェクトサーバ-に忍者の攻撃判定オブジェクトを追加
			g.GetOS()->Add(nac);
		}
	}
	if (frame == ATTACK_ALLFRAME) {
		_action_cnt = _cnt;
	}
}
/*---------クナイ投げ--------*/
void Zyounin::Throw(Game& g) {
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Throw"][_anime["Throw"]];
	if (frame < THROW_ANIMEFRAME) {
		_anime["Throw"] = ((frame) / ANIMESPEED_THROW) % THROW_ANIMEMAX;
	}
	if (_isflip == false) {
		PrivateCollision acc(_x + _hit_x - THROWCANCEL_WIDTH, _y - _hit_h, THROWCANCEL_WIDTH, THROWCANCEL_HEIGHT);
		if (frame == THROW_ANIMEFRAME|| frame == THROW_ALLFRAME) {
			if (_kunai_stock <= 0) {
				_action_cnt = _cnt;
				_anime["Throw"] = 0;
				_state = ENEMYSTATE::COMING;
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
			if (_kunai_stock <= 0) {
				_anime["Throw"] = 0;
				_action_cnt = _cnt;
				_state = ENEMYSTATE::COMING;
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
		_kunai_stock--;
		PlaySoundMem(_se["Kunai"], DX_PLAYTYPE_BACK, true);
		if (_isflip == false) {
			//クナイオブジェクトの生成
			auto ku = new Kunai(_x - 110, _y - 130, false,KUNAI_SPEED);
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
	if (frame == KUNAI_RELEASE2FRAME) {
		_kunai_stock--;
		PlaySoundMem(_se["Kunai"], DX_PLAYTYPE_BACK, true);
		if (_isflip == false) {
			//クナイオブジェクトの生成
			auto ku = new Kunai(_x - 110, _y - 130, false, KUNAI_SPEED);
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
void Zyounin::Dead(Game& g) {
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