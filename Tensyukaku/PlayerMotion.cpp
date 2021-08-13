#include <DxLib.h>
#include "Player.h"
#include "Game.h"
#include "PlayerMotionCollision.h"

using namespace PInfo;
/*----------待機----------*/
void Player::Idle(Game& g) {
	if (g.GetTrg() & PAD_INPUT_4) {
		_State = PLAYERSTATE::MIDDLEATTACK;
		_Action_Cnt = _Cnt;
		PlaySoundMem(_MiddleAttack_SEHandle, DX_PLAYTYPE_BACK, true);
	}
	if (g.GetTrg() & PAD_INPUT_5) {
		_State = PLAYERSTATE::LOWATTACK;
		_Action_Cnt = _Cnt;
		PlaySoundMem(_LowAttack_SEHandle, DX_PLAYTYPE_BACK, true);
	}
	if (g.GetTrg() & PAD_INPUT_6) {
		_State = PLAYERSTATE::KICK;
		_Action_Cnt = _Cnt;
		PlaySoundMem(_Kick_SEHandle, DX_PLAYTYPE_BACK, true);
	}
	if (g.GetKey() & PAD_INPUT_LEFT || g.GetKey() & PAD_INPUT_RIGHT) {
		_State = PLAYERSTATE::MOVE;
	}
	//敵の攻撃の当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteは敵の攻撃オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK|| (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK)
		{
			// プレイヤーとその攻撃の当たり判定を行う
			if (IsHit(*(*ite)) == true&& _Star_Flag == false)
			{
				// プレイヤーの状態遷移と攻撃オブジェクトのダメージ処理
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
				_Life--;
				_Action_Cnt = _Cnt;
				_State = PLAYERSTATE::DAMAGE;
			}
		}
	}
}
/*----------移動----------*/
void Player::Move(Game& g) {
	if (g.GetTrg() & PAD_INPUT_4) {
		_State = PLAYERSTATE::MIDDLEATTACK;
		_Action_Cnt = _Cnt;
		PlaySoundMem(_MiddleAttack_SEHandle, DX_PLAYTYPE_BACK, true);
	}
	else if (g.GetTrg() & PAD_INPUT_5) {
		_State = PLAYERSTATE::LOWATTACK;
		_Action_Cnt = _Cnt;
		PlaySoundMem(_LowAttack_SEHandle, DX_PLAYTYPE_BACK, true);
	}
	else if (g.GetTrg() & PAD_INPUT_6) {
		_State = PLAYERSTATE::KICK;
		_Action_Cnt = _Cnt;
		PlaySoundMem(_Kick_SEHandle, DX_PLAYTYPE_BACK, true);
	}
	else if (g.GetKey() & PAD_INPUT_LEFT)
	{
		_x -= _Spd;
		g.GetChip()->IsHit(*this, -1, 0);
		_isFlip = false;

	}
	else if (g.GetKey() & PAD_INPUT_RIGHT)
	{
		_x += _Spd;
		g.GetChip()->IsHit(*this, 1, 0);
		_isFlip = true;

	}
	else {
		_State = PLAYERSTATE::IDLE;
	}
	//敵の攻撃の当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteは敵の攻撃オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK || (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK)
		{
			// プレイヤーとその攻撃の当たり判定を行う
			if (IsHit(*(*ite)) == true && _Star_Flag == false)
			{
				// プレイヤーの状態遷移と攻撃オブジェクトのダメージ処理
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
				_Life--;
				_Action_Cnt = _Cnt;
				_State = PLAYERSTATE::DAMAGE;
			}
		}
	}
}
/*----------中段攻撃----------*/
void Player::MidAttack(Game& g) {

	if (_Cnt - _Action_Cnt == MABegin_Frame) {
		//中段攻撃判定オブジェクトの生成
		MiddleAttackCollision* MAC = new MiddleAttackCollision();
		if (_isFlip == false) {
			// 中段攻撃判定オブジェクトの開始位置をプレイヤー位置から算出
			MAC->SetPosition(_x + _hit_x - MAC->GetW(), _y - _hit_h);
			// オブジェクトサーバ-に中段攻撃判定オブジェクトを追加
			g.GetOS()->Add(MAC);
		};
		if (_isFlip == true) {
			// 中段攻撃判定オブジェクトの開始位置をプレイヤー位置から算出
			MAC->SetPosition(_x - _hit_x, _y - _hit_h);
			// オブジェクトサーバ-に中段攻撃判定オブジェクトを追加
			g.GetOS()->Add(MAC);
		}
	}
	if (_Cnt - _Action_Cnt == MiddleAttack_Frame) {
		_State = PLAYERSTATE::IDLE;
	}
	//敵の攻撃の当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteは敵の攻撃オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK || (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK)
		{
			// プレイヤーとその攻撃の当たり判定を行う
			if (IsHit(*(*ite)) == true && _Star_Flag == false)
			{
				// プレイヤーの状態遷移と攻撃オブジェクトのダメージ処理
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
				_Life--;
				_Action_Cnt = _Cnt;
				_State = PLAYERSTATE::DAMAGE;
			}
		}
	}
}
/*----------下段攻撃----------*/
void Player::LowAttack(Game& g) {
	//下段攻撃判定オブジェクトの生成
	if (_Cnt - _Action_Cnt == LABegin_Frame) {
		LowAttackCollision* LAC = new LowAttackCollision();
		if (_isFlip == false) {
			// 下段攻撃判定オブジェクトの開始位置をプレイヤー位置から算出
			LAC->SetPosition(_x + _hit_x - LAC->GetW(), _y - LAC->GetH());
			// オブジェクトサーバ-に下段攻撃判定オブジェクトを追加
			g.GetOS()->Add(LAC);
		};
		if (_isFlip == true) {
			// 下段攻撃判定オブジェクトの開始位置をプレイヤー位置から算出
			LAC->SetPosition(_x - _hit_x, _y - LAC->GetH());
			// オブジェクトサーバ-に下段攻撃判定オブジェクトを追加
			g.GetOS()->Add(LAC);
		}
	}
	if (_Cnt - _Action_Cnt == LowAttack_Frame) {
		_State = PLAYERSTATE::IDLE;
	}
	//敵の攻撃の当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteは敵の攻撃オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK || (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK)
		{
			// プレイヤーとその攻撃の当たり判定を行う
			if (IsHit(*(*ite)) == true && _Star_Flag == false)
			{
				// プレイヤーの状態遷移と攻撃オブジェクトのダメージ処理
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
				_Life--;
				_Action_Cnt = _Cnt;
				_State = PLAYERSTATE::DAMAGE;
			}
		}
	}
}

/*----------蹴り----------*/
void Player::Kick(Game& g) {
	//蹴り判定オブジェクトの生成
	if (_Cnt - _Action_Cnt == KIBegin_Frame) {
		KickCollision* KIC = new KickCollision();
		if (_isFlip == false) {
			// 蹴り判定オブジェクトの開始位置をプレイヤー位置から算出
			KIC->SetPosition(_x + _hit_x - KIC->GetW(), _y - _hit_h / 2);
			// オブジェクトサーバ-に蹴り判定オブジェクトを追加
			g.GetOS()->Add(KIC);
		};
		if (_isFlip == true) {
			// 蹴り判定オブジェクトの開始位置をプレイヤー位置から算出
			KIC->SetPosition(_x - _hit_x, _y - _hit_h / 2);
			// オブジェクトサーバ-に蹴り判定オブジェクトを追加
			g.GetOS()->Add(KIC);
		}
	}
	if (_Cnt - _Action_Cnt == Kick_Frame) {
		_State = PLAYERSTATE::IDLE;
	}
	//敵の攻撃の当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteは敵の攻撃オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK || (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK)
		{
			// プレイヤーとその攻撃の当たり判定を行う
			if (IsHit(*(*ite)) == true && _Star_Flag == false)
			{
				// プレイヤーの状態遷移と攻撃オブジェクトのダメージ処理
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
				_Life--;
				_Action_Cnt = _Cnt;
				_State = PLAYERSTATE::DAMAGE;
			}
		}
	}

}

/*----------居合----------*/
//void Player::Iai(Game& g) {
//	if (_Cnt - _Action_Cnt == Iai_Frame) {
//
//	}
//}
///*----------スウェイ----------*/
//void Player::Sway(Game& g){
//}

/*----------被ダメ----------*/
void Player::Damage(Game& g) {
	if (_Cnt - _Action_Cnt == Damage_Frame) {
		_Star_Cnt = _Cnt;
		if (_Life > 0) {
			_Star_Flag = true;
		}
		if (_Life <= 0) {
			_Action_Cnt = _Cnt;
			_State=PLAYERSTATE::DEAD;
		}
		else {
			_State = PLAYERSTATE::IDLE;
		}
	}
}

/*----------死亡----------*/
void Player::Dead(Game& g) {
	if (_Cnt - _Action_Cnt == Dead_Frame) {
		Delete(g);
	}
}