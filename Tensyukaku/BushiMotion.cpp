#include <DxLib.h>
#include "EnemyBase.h"
#include "Bushi.h"
#include "Game.h"
#include "BushiMotionCollision.h"
#include "ObjectBase.h"
#include <tuple>
#include <utility>

using namespace BInfo;

/*----------巡回----------*/
void Bushi::Patrol(Game& g) {
	_GrHandle = _Patrol_GrAll[_Patrol_AnimeNo];
	if (_Cnt - _Action_Cnt == PATROL_FRAME) {
		_isFlip = true;
	}
	if (_Cnt - _Action_Cnt == PATROL_FRAME + PATROL_FRAME) {
		_isFlip = false;
		_Action_Cnt = _Cnt;
	}
	if (_isFlip == false) {
		//武士の索敵範囲判定オブジェクトの生成
		BushiPatrolCollision bpc;
		// 武士の索敵範囲判定オブジェクトの開始位置をプレイヤー位置から算出
		bpc.SetPosition(_x + _hit_x - bpc.GetHitW(), _y - _hit_h);
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
		BushiPatrolCollision bpc;
		// 武士の索敵範囲判定オブジェクトの開始位置をプレイヤー位置から算出
		bpc.SetPosition(_x - _hit_x, _y - _hit_h);
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
				_Life -= 3;
				_Action_Cnt = _Cnt;
				_State =ENEMYSTATE::DAMAGE;
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
		if ((*ite)->GetObjType() == OBJECTTYPE::IAI)
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
	_GrHandle = _Coming_GrAll[_Coming_AnimeNo];
	if (_isFlip == false) {
		_x -= _Spd;
		//武士の攻撃発生範囲判定オブジェクトの生成
		BushiComingCollision bcc;
		// 武士の攻撃発生範囲オブジェクトの開始位置をプレイヤー位置から算出
		bcc.SetPosition(_x + _hit_x - bcc.GetHitW(), _y - _hit_h);
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
					_State =ENEMYSTATE::ATTACK;
				}
			}
		}
	}
	if (_isFlip == true) {
		_x += _Spd;
		//武士の攻撃発生範囲判定オブジェクトの生成
		BushiComingCollision bcc;
		// 武士の攻撃発生範囲判定オブジェクトの開始位置をプレイヤー位置から算出
		bcc.SetPosition(_x - _hit_x, _y - _hit_h);
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
					_State =ENEMYSTATE::ATTACK;
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
				_State = ENEMYSTATE::DAMAGE;
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
		if ((*ite)->GetObjType() == OBJECTTYPE::IAI)
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
	
	_GrHandle = _Attack_GrAll[_Attack_AnimeNo];
	if (_Cnt - _Action_Cnt == ATTACK_BEGINFRAME) {
		//武士の攻撃判定オブジェクトの生成
		BushiAttackCollision* bac= new BushiAttackCollision();
		if (_isFlip == false) {
			// 武士の攻撃判定オブジェクトの開始位置を武士位置から算出
			bac->SetPosition(_x + _hit_x - bac->GetHitW(), _y - _hit_h);
			// オブジェクトサーバ-に武士の攻撃判定オブジェクトを追加
			g.GetOS()->Add(bac);
		};
		if (_isFlip == true) {
			// 武士の攻撃判定オブジェクトの開始位置を武士位置から算出
			bac->SetPosition(_x - _hit_x, _y - _hit_h);
			// オブジェクトサーバ-に武士の攻撃判定オブジェクトを追加
			g.GetOS()->Add(bac);
		}
	}
	if (_Cnt - _Action_Cnt == ATTACK_ALLFRAME)
	{
		_State =ENEMYSTATE::PATROL;
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
				_State = ENEMYSTATE::DAMAGE;
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
		if ((*ite)->GetObjType() == OBJECTTYPE::IAI)
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
/*----------被ダメ----------*/
void Bushi::Damage(Game& g) {
	_GrHandle = _Damage_GrAll[_Damage_AnimeNo];
	if (_Cnt - _Action_Cnt == DAMAGE_ALLFRAME) {
		if (_Life <= 0) {
			_Action_Cnt = _Cnt;
			_State = ENEMYSTATE::DEAD;
		}
		else {
			_Action_Cnt = _Cnt;
			_State = ENEMYSTATE::PATROL;
		}
	}
}
/*----------死亡----------*/
void Bushi::Dead(Game& g) {
	_GrHandle = _Dead_GrAll[_Dead_AnimeNo];
	if (_Cnt - _Action_Cnt == DEAD_ALLFRAME) {
		Delete(g);
	}
}