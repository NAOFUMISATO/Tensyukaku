#include <DxLib.h>
#include "Player.h"
#include "Game.h"
#include "PlayerMotionCollision.h"
#include "ObjectBase.h"
#include "MiddleAttackParticle.h"
#include "LowAttackParticle.h"
#include "IaiParticle.h"
#include "Stair.h"
using namespace PInfo;
using namespace ParInfo;
/*----------待機----------*/
void Player::Idle(Game& g) {
	_GrHandle = _Idle_GrAll[_Idle_AnimeNo];
	if (g.GetTrg() & PAD_INPUT_1) {
		_State = PLAYERSTATE::IAI;
		_Action_Cnt = _Cnt;
		PlaySoundMem(_SwordIn_SEHandle, DX_PLAYTYPE_BACK, true);
	}
	if (g.GetTrg() & PAD_INPUT_4) {
		_State = PLAYERSTATE::MIDDLEATTACK;
		_Action_Cnt = _Cnt;		
	}
	if (g.GetTrg() & PAD_INPUT_5) {
		_State = PLAYERSTATE::LOWATTACK;
		_Action_Cnt = _Cnt;
	}
	if (g.GetTrg() & PAD_INPUT_6) {
		_State = PLAYERSTATE::KICK;
		_Action_Cnt = _Cnt;
	}
	if (g.GetKey() & PAD_INPUT_LEFT || g.GetKey() & PAD_INPUT_RIGHT) {
		_State = PLAYERSTATE::MOVE;
		_Action_Cnt = _Cnt;
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
				PlaySoundMem(_Damage_SEHandle, DX_PLAYTYPE_BACK, true);
			}
		}
	}
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteは階段オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::STAIR)
		{
			// プレイヤーとその階段の当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				if (g.GetTrg() & PAD_INPUT_2) {
					
					_State = PLAYERSTATE::STAIRMOVE;
				}
			}
		}
	}
}
/*----------移動----------*/
void Player::Move(Game& g) {
	_GrHandle = _Move_GrAll[_Move_AnimeNo];
	/*if (_Cnt - _Action_Cnt == Move_Frame) {
	PlaySoundMem(_Walk_SEHandle, DX_PLAYTYPE_BACK, true);
	_Action_Cnt = _Cnt;
	}*/
	if (g.GetTrg() & PAD_INPUT_1) {
		_State = PLAYERSTATE::IAI;
		_Action_Cnt = _Cnt;
		PlaySoundMem(_SwordIn_SEHandle, DX_PLAYTYPE_BACK, true);
	}
	else if (g.GetTrg() & PAD_INPUT_4) {
		_State = PLAYERSTATE::MIDDLEATTACK;
		_Action_Cnt = _Cnt;
	}
	else if (g.GetTrg() & PAD_INPUT_5) {
		_State = PLAYERSTATE::LOWATTACK;
		_Action_Cnt = _Cnt;
	}
	else if (g.GetTrg() & PAD_INPUT_6) {
		_State = PLAYERSTATE::KICK;
		_Action_Cnt = _Cnt;
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
	else if(g.GetKey() & PAD_INPUT_UP)
	{
		_y -= _Spd;
		g.GetChip()->IsHit(*this, 1, 0);
		_isFlip = true;

	}
	else if (g.GetKey() & PAD_INPUT_DOWN)
	{
		_y += _Spd;
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
				PlaySoundMem(_Damage_SEHandle, DX_PLAYTYPE_BACK, true);
			}
		}
	}
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteは階段オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::STAIR)
		{
			// プレイヤーとその階段の当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				if (g.GetTrg() & PAD_INPUT_2) {
					
					_State=PLAYERSTATE::STAIRMOVE;
				}
			}
		}
	}
}
/*----------中段攻撃----------*/
void Player::MidAttack(Game& g) {
	_GrHandle = _MiddleAttack_GrAll[_MiddleAttack_AnimeNo];
	if (_Cnt - _Action_Cnt == MABegin_Frame) {
		PlaySoundMem(_MiddleAttack_SEHandle, DX_PLAYTYPE_BACK, true);
		//中段攻撃判定オブジェクトの生成
		MiddleAttackCollision* MAC = new MiddleAttackCollision();
		if (_isFlip == false) {
			// 中段攻撃判定オブジェクトの開始位置をプレイヤー位置から算出
			MAC->SetPosition(_x + _hit_x - MAC->GetW(), _y - _hit_h);
			// オブジェクトサーバ-に中段攻撃判定オブジェクトを追加
			g.GetOS()->Add(MAC);
			//パーティクル追加
			for (int i = 0; i < MiddleAttackPar1_qty; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % MAP1_Xrand1) - MAP1_Xrand2) / MAP1_Xrand3, ((rand() % MAP1_Yrand1) - MAP1_Yrand2) / MAP1_Yrand3);
				MiddleAttackParticle1* m1 = new MiddleAttackParticle1(xy, dxy);
				m1->SetFlip(false);
				g.GetOS()->Add(m1);
			}
			for (int i = 0; i < MiddleAttackPar2_qty; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % MAP2_Xrand1) - MAP2_Xrand2) / MAP2_Xrand3, ((rand() % MAP2_Yrand1) - MAP2_Yrand2) / MAP2_Yrand3);
				MiddleAttackParticle2* m2 = new MiddleAttackParticle2(xy, dxy);
				m2->SetFlip(false);
				g.GetOS()->Add(m2);
			}
		};
		if (_isFlip == true) {
			// 中段攻撃判定オブジェクトの開始位置をプレイヤー位置から算出
			MAC->SetPosition(_x - _hit_x, _y - _hit_h);
			// オブジェクトサーバ-に中段攻撃判定オブジェクトを追加
			g.GetOS()->Add(MAC);
			for (int i = 0; i < MiddleAttackPar1_qty; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % MAP1_Xrand1) - MAP1_Xrand2) / MAP1_Xrand3, ((rand() % MAP1_Yrand1) - MAP1_Yrand2) / MAP1_Yrand3);
				MiddleAttackParticle1* m1 = new MiddleAttackParticle1(xy, dxy);
				m1->SetFlip(true);
				g.GetOS()->Add(m1);
			}
			for (int i = 0; i < MiddleAttackPar2_qty; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % MAP2_Xrand1) - MAP2_Xrand2) / MAP2_Xrand3, ((rand() % MAP2_Yrand1) - MAP2_Yrand2) / MAP2_Yrand3);
				MiddleAttackParticle2* m2 = new MiddleAttackParticle2(xy, dxy);
				m2->SetFlip(true);
				g.GetOS()->Add(m2);
			}
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
				PlaySoundMem(_Damage_SEHandle, DX_PLAYTYPE_BACK, true);
			}
		}
	}
}
/*----------下段攻撃----------*/
void Player::LowAttack(Game& g) {
	_GrHandle = _LowAttack_GrAll[_LowAttack_AnimeNo];
	//下段攻撃判定オブジェクトの生成
	if (_Cnt - _Action_Cnt == LABegin_Frame) {
		PlaySoundMem(_LowAttack_SEHandle, DX_PLAYTYPE_BACK, true);
		LowAttackCollision* LAC = new LowAttackCollision();
		if (_isFlip == false) {
			// 下段攻撃判定オブジェクトの開始位置をプレイヤー位置から算出
			LAC->SetPosition(_x + _hit_x - LAC->GetW(), _y - LAC->GetH());
			// オブジェクトサーバ-に下段攻撃判定オブジェクトを追加
			g.GetOS()->Add(LAC);
			//パーティクル追加
			for (int i = 0; i < LowAttackPar1_qty; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % LAP1_Xrand1) - LAP1_Xrand2) / LAP1_Xrand3, ((rand() % -LAP1_Yrand1) - LAP1_Yrand2) / LAP1_Yrand3);
				LowAttackParticle1* l1 = new LowAttackParticle1(xy, dxy);
				l1->SetFlip(false);
				g.GetOS()->Add(l1);
			}
			for (int i = 0; i < LowAttackPar2_qty; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % LAP2_Xrand1) - LAP2_Xrand2) / LAP2_Xrand3, ((rand() % LAP2_Yrand1) - LAP2_Yrand2) / LAP2_Yrand3);
				LowAttackParticle2* l2 = new LowAttackParticle2(xy, dxy);
				l2->SetFlip(false);
				g.GetOS()->Add(l2);
			}
		};
		if (_isFlip == true) {
			// 下段攻撃判定オブジェクトの開始位置をプレイヤー位置から算出
			LAC->SetPosition(_x - _hit_x, _y - LAC->GetH());
			// オブジェクトサーバ-に下段攻撃判定オブジェクトを追加
			g.GetOS()->Add(LAC);
			for (int i = 0; i < LowAttackPar1_qty; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % LAP1_Xrand1) - LAP1_Xrand2) / LAP1_Xrand3, ((rand() % -LAP1_Yrand1) - LAP1_Yrand2) / LAP1_Yrand3);
				LowAttackParticle1* l1 = new LowAttackParticle1(xy, dxy);
				l1->SetFlip(true);
				g.GetOS()->Add(l1);
			}
			for (int i = 0; i < LowAttackPar2_qty; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % LAP2_Xrand1) - LAP2_Xrand2) / LAP2_Xrand3, ((rand() % LAP2_Yrand1) - LAP2_Yrand2) / LAP2_Yrand3);
				LowAttackParticle2* l2 = new LowAttackParticle2(xy, dxy);
				l2->SetFlip(true);
				g.GetOS()->Add(l2);
			}
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
				PlaySoundMem(_Damage_SEHandle, DX_PLAYTYPE_BACK, true);
			}
		}
	}
}

/*----------蹴り----------*/
void Player::Kick(Game& g) {
	_GrHandle = _Kick_GrAll[_Kick_AnimeNo];
	//蹴り判定オブジェクトの生成
	if (_Cnt - _Action_Cnt == KIBegin_Frame) {
		PlaySoundMem(_Kick_SEHandle, DX_PLAYTYPE_BACK, true);
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
				PlaySoundMem(_Damage_SEHandle, DX_PLAYTYPE_BACK, true);
			}
		}
	}
}

/*----------居合----------*/
void Player::Iai(Game& g) {
	_GrHandle = _Iai_GrAll[_Iai_AnimeNo];
	if (_Cnt - _Action_Cnt >= IABegin_Frame && Iai_Frame >= _Cnt - _Action_Cnt) {
		if (_isFlip == false) {
			_x -= 40;
			g.GetChip()->IsHit(*this, -1, 0);
		}
		if (_isFlip == true) {
			_x += 40;
			g.GetChip()->IsHit(*this, 1, 0);
		}
	}
	if (_Cnt - _Action_Cnt == IABegin_Frame - 6) {
		if (_isFlip == false) {
			for (int i = 0; i < Iai1_qty; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % IAI1_Xrand1) - IAI1_Xrand2) / IAI1_Xrand3, ((rand() % -IAI1_Yrand1) - IAI1_Yrand2) / IAI1_Yrand3);
				IaiParticle1* I1 = new IaiParticle1(xy, dxy);
				I1->SetFlip(false);
				g.GetOS()->Add(I1);
			}
		}
		if (_isFlip == true) {
			for (int i = 0; i < Iai1_qty; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % IAI1_Xrand1) - IAI1_Xrand2) / IAI1_Xrand3, ((rand() % -IAI1_Yrand1) - IAI1_Yrand2) / IAI1_Yrand3);
				IaiParticle1* I1 = new IaiParticle1(xy, dxy);
				I1->SetFlip(true);
				g.GetOS()->Add(I1);
			}
		}
	}
	if (_Cnt - _Action_Cnt == IABegin_Frame) {
		StopSoundMem(_SwordIn_SEHandle);
		PlaySoundMem(_Iai_SEHandle, DX_PLAYTYPE_BACK, true);
		IaiCollision* IAC = new IaiCollision();
		if (_isFlip == false) {
			// 居合判定オブジェクトの開始位置をプレイヤー位置から算出
			IAC->SetPosition(_x + _hit_x - IAC->GetW(), _y - _hit_h / 2);
			// オブジェクトサーバ-に蹴り判定オブジェクトを追加
			g.GetOS()->Add(IAC);
			for (int i = 0; i < Iai2_qty; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % IAI2_Xrand1) - IAI2_Xrand2) / IAI2_Xrand3, ((rand() % -IAI2_Yrand1) - IAI2_Yrand2) / IAI2_Yrand3);
				IaiParticle2* I2 = new IaiParticle2(xy, dxy);
				I2->SetFlip(false);
				g.GetOS()->Add(I2);
			}
			for (int i = 0; i < Iai3_qty; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % IAI3_Xrand1) - IAI3_Xrand2) / IAI3_Xrand3, ((rand() % -IAI3_Yrand1) - IAI3_Yrand2) / IAI3_Yrand3);
				IaiParticle3* I3 = new IaiParticle3(xy, dxy);
				I3->SetFlip(false);
				g.GetOS()->Add(I3);
			}
		}
		if (_isFlip == true) {
			// 居合判定オブジェクトの開始位置をプレイヤー位置から算出
			IAC->SetPosition(_x - _hit_x, _y - _hit_h / 2);
			// オブジェクトサーバ-に居合判定オブジェクトを追加
			g.GetOS()->Add(IAC);
			for (int i = 0; i < Iai2_qty; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % IAI2_Xrand1) - IAI2_Xrand2) / IAI2_Xrand3, ((rand() % -IAI2_Yrand1) - IAI2_Yrand2) / IAI2_Yrand3);
				IaiParticle2* I2 = new IaiParticle2(xy, dxy);
				I2->SetFlip(true);
				g.GetOS()->Add(I2);
			}
			for (int i = 0; i < Iai3_qty; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % IAI3_Xrand1) - IAI3_Xrand2) / IAI3_Xrand3, ((rand() % -IAI3_Yrand1) - IAI3_Yrand2) / IAI3_Yrand3);
				IaiParticle3* I3 = new IaiParticle3(xy, dxy);
				I3->SetFlip(true);
				g.GetOS()->Add(I3);
			}
		}
		if (_Cnt - _Action_Cnt >= 0 && IABegin_Frame >= _Cnt - _Action_Cnt) {
			//敵の攻撃の当たり判定
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// iteは敵の攻撃オブジェクトか？
				if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK || (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK)
				{
					// プレイヤーとその敵の攻撃の当たり判定を行う
					if (IsHit(*(*ite)) == true && _Star_Flag == false)
					{
						// プレイヤーの状態遷移と敵の攻撃オブジェクトのダメージ処理
						(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
						_Life--;
						_Action_Cnt = _Cnt;
						_State = PLAYERSTATE::DAMAGE;
						PlaySoundMem(_Damage_SEHandle, DX_PLAYTYPE_BACK, true);
					}
				}
			}
		}
	}
	if (_Cnt - _Action_Cnt == Iai_Frame) {
		_State = PLAYERSTATE::IDLE;
	}
}
///*----------スウェイ----------*/
//void Player::Sway(Game& g){
//}

/*----------被ダメ----------*/
void Player::Damage(Game& g) {
	_GrHandle = _Damage_GrAll[_Damage_AnimeNo];
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
	_GrHandle = _Dead_GrAll[_Dead_AnimeNo];
	if (_Cnt - _Action_Cnt == Dead_Frame) {
		Delete(g);
	}
}

/*---------階段位置調整---------*/
void Player::StairMove(Game& g) {
	_GrHandle = _Move_GrAll[_Move_AnimeNo];
	Stair st;
	if (st.GetFlip() == false) {
		if (_x >= st.GetX()+st.GetHitX()) {
			_isFlip = false;
			--_x;
		}
		if (_x <= st.GetX() + st.GetHitX()) {
			_isFlip = true;
			_position = { static_cast<double>(_x),static_cast<double>(_y) };
			_State = PLAYERSTATE::STAIRUP;
		}
	}
	if (st.GetFlip() == true) {
		if (_x <= st.GetX() + st.GetHitX()+st.GetHitW()) {
			_isFlip = true;
			++_x;
		}
		if (_x >= st.GetX() + st.GetHitX() + st.GetHitW()) {
			_isFlip = false;
			_position = { static_cast<double>(_x),static_cast<double>(_y) };
			_State = PLAYERSTATE::STAIRUP;
		}
	}
	
}

/*---------階段上昇------------*/
void Player::StairUp(Game& g) {
	_GrHandle = _Move_GrAll[_Move_AnimeNo];
	_Stairup_Spd = 1.5f;
	Stair st;
	if (st.GetFlip() == false) {
		_angle = Math::ToRadians(280);
	}
	if (st.GetFlip() == true) {
		_angle = Math::ToRadians(260);
	}
	_velocityDir = { std::cos(_angle), std::sin(_angle) };
	auto vd = _velocityDir * _Stairup_Spd;
	_position += vd;
	_x = _position.x;
	_y = _position.y;
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteは階段オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::STAIR)
		{
			// プレイヤーとその階段の当たり判定を行う
			if (IsHit(*(*ite)) == false)
			{
				_State=PLAYERSTATE::IDLE;
			}
		}
	}
	
}