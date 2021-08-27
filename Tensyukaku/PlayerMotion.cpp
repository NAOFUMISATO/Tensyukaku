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
using namespace StInfo;
/*----------待機----------*/
void Player::Idle(Game& g) {
	_GrHandle = _GrAll["Idle"] [_Anime["Idle"]];
	if (g.GetTrg() & PAD_INPUT_1) {
		_State = PLAYERSTATE::IAI;
		_Action_Cnt = _Cnt;
		PlaySoundMem(_Se["SwordIn"], DX_PLAYTYPE_BACK, true);
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
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK|| (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK|| (*ite)->GetObjType() == OBJECTTYPE::SHIELDERATTACK)
		{
			// プレイヤーとその攻撃の当たり判定を行う
			if (IsHit(*(*ite)) == true&& _Star_Flag == false)
			{
				// プレイヤーの状態遷移と攻撃オブジェクトのダメージ処理
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
				_Life--;
				_Action_Cnt = _Cnt;
				_State = PLAYERSTATE::DAMAGE;
				PlaySoundMem(_Se["Damage"], DX_PLAYTYPE_BACK, true);
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
					_Player_y = _y;
					_Stair_x = (*ite)->GetX();
					_StairFlip_Flag = (*ite)->GetFlip();
					_State = PLAYERSTATE::STAIRMOVE;
				}
			}
		}
	}
}
/*----------移動----------*/
void Player::Move(Game& g) {
	_GrHandle = _GrAll["Move"][_Anime["Move"]];
	if (g.GetTrg() & PAD_INPUT_1) {
		_State = PLAYERSTATE::IAI;
		_Action_Cnt = _Cnt;
		PlaySoundMem(_Se["SwordIn"], DX_PLAYTYPE_BACK, true);
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
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK || (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK|| (*ite)->GetObjType() == OBJECTTYPE::SHIELDERATTACK)
		{
			// プレイヤーとその攻撃の当たり判定を行う
			if (IsHit(*(*ite)) == true && _Star_Flag == false)
			{
				// プレイヤーの状態遷移と攻撃オブジェクトのダメージ処理
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
				_Life--;
				_Action_Cnt = _Cnt;
				_State = PLAYERSTATE::DAMAGE;
				PlaySoundMem(_Se["Damage"], DX_PLAYTYPE_BACK, true);
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
					_Player_y = _y;
					_Stair_x = (*ite)->GetX();
					_StairFlip_Flag = (*ite)->GetFlip();
					_State = PLAYERSTATE::STAIRMOVE;
				}
			}
		}
	}
}
/*----------中段攻撃----------*/
void Player::MidAttack(Game& g) {
	_GrHandle = _GrAll["MiddleAttack"][_Anime["MiddleAttack"]];
	auto frame = _Cnt - _Action_Cnt;
	if (frame == MIDDLEATTACK_BEGINFRAME) {
		PlaySoundMem(_Se["MiddleAttack"], DX_PLAYTYPE_BACK, true);
		if (_isFlip == false) {
			//中段攻撃判定オブジェクトの生成
			auto mac = new MiddleAttackCollision(_x + _hit_x - MIDDLEATTACK_WIDTH, _y - _hit_h);
			// オブジェクトサーバ-に中段攻撃判定オブジェクトを追加
			g.GetOS()->Add(mac);
			//パーティクル追加
			for (int i = 0; i < MIDDLEATTACK_PARTICLE1_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % MIDDLEATTACK_PARTICLE1_RANDOMX1) - MIDDLEATTACK_PARTICLE1_RANDOMX2) / MIDDLEATTACK_PARTICLE1_RANDOMX3, ((rand() % MIDDLEATTACK_PARTICLE1_RANDOMY1) - MIDDLEATTACK_PARTICLE1_RANDOMY2) / MIDDLEATTACK_PARTICLE1_RANDOMY3);
				auto m1 = new MiddleAttackParticle1(xy, dxy,false);
				g.GetOS()->Add(m1);
			}
			for (int i = 0; i < MIDDLEATTACK_PARTICLE2_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % MIDDLEATTACK_PARTICLE2_RANDOMX1) - MIDDLEATTACK_PARTICLE2_RANDOMX2) / MIDDLEATTACK_PARTICLE2_RANDOMX3, ((rand() % MIDDLEATTACK_PARTICLE2_RANDOMY1) - MIDDLEATTACK_PARTICLE2_RANDOMY2) / MIDDLEATTACK_PARTICLE2_RANDOMY3);
				auto m2 = new MiddleAttackParticle2(xy, dxy,false);
				g.GetOS()->Add(m2);
			}
		};
		if (_isFlip == true) {
			//中段攻撃判定オブジェクトの生成
			auto mac = new MiddleAttackCollision(_x - _hit_x, _y - _hit_h);
			// オブジェクトサーバ-に中段攻撃判定オブジェクトを追加
			g.GetOS()->Add(mac);
			for (int i = 0; i < MIDDLEATTACK_PARTICLE1_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % MIDDLEATTACK_PARTICLE1_RANDOMX1) - MIDDLEATTACK_PARTICLE1_RANDOMX2) / MIDDLEATTACK_PARTICLE1_RANDOMX3, ((rand() % MIDDLEATTACK_PARTICLE1_RANDOMY1) - MIDDLEATTACK_PARTICLE1_RANDOMY2) / MIDDLEATTACK_PARTICLE1_RANDOMY3);
				auto m1 = new MiddleAttackParticle1(xy, dxy,true);
				g.GetOS()->Add(m1);
			}
			for (int i = 0; i < MIDDLEATTACK_PARTICLE2_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % MIDDLEATTACK_PARTICLE2_RANDOMX1) - MIDDLEATTACK_PARTICLE2_RANDOMX2) / MIDDLEATTACK_PARTICLE2_RANDOMX3, ((rand() % MIDDLEATTACK_PARTICLE2_RANDOMY1) - MIDDLEATTACK_PARTICLE2_RANDOMY2) / MIDDLEATTACK_PARTICLE2_RANDOMY3);
				auto m2 = new MiddleAttackParticle2(xy, dxy,true);
				g.GetOS()->Add(m2);
			}
		}
	}
	if (frame == MIDDLEATTACK_ALLFRAME) {
		_State = PLAYERSTATE::IDLE;
	}
	//敵の攻撃の当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteは敵の攻撃オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK || (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK|| (*ite)->GetObjType() == OBJECTTYPE::SHIELDERATTACK)
		{
			// プレイヤーとその攻撃の当たり判定を行う
			if (IsHit(*(*ite)) == true && _Star_Flag == false)
			{
				// プレイヤーの状態遷移と攻撃オブジェクトのダメージ処理
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
				_Life--;
				_Action_Cnt = _Cnt;
				_State = PLAYERSTATE::DAMAGE;
				PlaySoundMem(_Se["Damage"], DX_PLAYTYPE_BACK, true);
			}
		}
	}
}
/*----------下段攻撃----------*/
void Player::LowAttack(Game& g) {
	_GrHandle = _GrAll["LowAttack"][_Anime["LowAttack"]];
	auto frame = _Cnt - _Action_Cnt;
	if (frame == LOWATTACK_BEGINFRAME) {
		PlaySoundMem(_Se["LowAttack"], DX_PLAYTYPE_BACK, true);
		if (_isFlip == false) {
			//下段攻撃判定オブジェクトの生成
			auto lac = new LowAttackCollision(_x + _hit_x - LOWATTACK_WIDTH, _y - LOWATTACK_HEIGHT);
			// オブジェクトサーバ-に下段攻撃判定オブジェクトを追加
			g.GetOS()->Add(lac);
			//パーティクル追加
			for (int i = 0; i < LOWATTACK_PARTICLE1_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % LOWATTACK_PARTICLE1_RANDOMX1) - LOWATTACK_PARTICLE1_RANDOMX2) / LOWATTACK_PARTICLE1_RANDOMX3, ((rand() % -LOWATTACK_PARTICLE1_RANDOMY1) - LOWATTACK_PARTICLE1_RANDOMY2) / LOWATTACK_PARTICLE1_RANDOMY3);
				auto l1 = new LowAttackParticle1(xy, dxy,false);
				g.GetOS()->Add(l1);
			}
			for (int i = 0; i < LOWATTACK_PARTICLE2_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % LOWATTACK_PARTICLE2_RANDOMX1) - LOWATTACK_PARTICLE2_RANDOMX2) / LOWATTACK_PARTICLE2_RANDOMX3, ((rand() % LOWATTACK_PARTICLE2_RANDOMY1) - LOWATTACK_PARTICLE2_RANDOMY2) / LOWATTACK_PARTICLE2_RANDOMY3);
				auto l2 = new LowAttackParticle2(xy, dxy,false);
				g.GetOS()->Add(l2);
			}
		};
		if (_isFlip == true) {
			//下段攻撃判定オブジェクトの生成
			auto lac = new LowAttackCollision(_x - _hit_x, _y - LOWATTACK_HEIGHT);
			// オブジェクトサーバ-に下段攻撃判定オブジェクトを追加
			g.GetOS()->Add(lac);
			for (int i = 0; i < LOWATTACK_PARTICLE1_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % LOWATTACK_PARTICLE1_RANDOMX1) - LOWATTACK_PARTICLE1_RANDOMX2) / LOWATTACK_PARTICLE1_RANDOMX3, ((rand() % -LOWATTACK_PARTICLE1_RANDOMY1) - LOWATTACK_PARTICLE1_RANDOMY2) / LOWATTACK_PARTICLE1_RANDOMY3);
				auto l1 = new LowAttackParticle1(xy, dxy,true);
				g.GetOS()->Add(l1);
			}
			for (int i = 0; i < LOWATTACK_PARTICLE2_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % LOWATTACK_PARTICLE2_RANDOMX1) - LOWATTACK_PARTICLE2_RANDOMX2) / LOWATTACK_PARTICLE2_RANDOMX3, ((rand() % LOWATTACK_PARTICLE2_RANDOMY1) - LOWATTACK_PARTICLE2_RANDOMY2) / LOWATTACK_PARTICLE2_RANDOMY3);
				auto l2 = new LowAttackParticle2(xy, dxy,true);
				g.GetOS()->Add(l2);
			}
		}
	}
	if (frame == LOWATTACK_ALLFRAME) {
		_State = PLAYERSTATE::IDLE;
	}
	//敵の攻撃の当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteは敵の攻撃オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK || (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK||(*ite)->GetObjType() == OBJECTTYPE::SHIELDERATTACK)
		{
			// プレイヤーとその攻撃の当たり判定を行う
			if (IsHit(*(*ite)) == true && _Star_Flag == false)
			{
				// プレイヤーの状態遷移と攻撃オブジェクトのダメージ処理
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
				_Life--;
				_Action_Cnt = _Cnt;
				_State = PLAYERSTATE::DAMAGE;
				PlaySoundMem(_Se["Damage"], DX_PLAYTYPE_BACK, true);
			}
		}
	}
}

/*----------蹴り----------*/
void Player::Kick(Game& g) {
	_GrHandle = _GrAll["Kick"][_Anime["Kick"]];
	auto frame = _Cnt - _Action_Cnt;
	if (frame == KICK_BEGINFRAME) {
		PlaySoundMem(_Se["Kick"], DX_PLAYTYPE_BACK, true);
		if (_isFlip == false) {
			//蹴り判定オブジェクトの生成
			auto kic = new KickCollision(_x + _hit_x - KICK_WIDTH, _y - _hit_h / 2);
			// オブジェクトサーバ-に蹴り判定オブジェクトを追加
			g.GetOS()->Add(kic);
		};
		if (_isFlip == true) {
			//蹴り判定オブジェクトの生成
			auto kic = new KickCollision(_x - _hit_x, _y - _hit_h / 2);
			// オブジェクトサーバ-に蹴り判定オブジェクトを追加
			g.GetOS()->Add(kic);
		}
	}
	if (frame == KICK_ALLFRAME) {
		_State = PLAYERSTATE::IDLE;
	}
	//敵の攻撃の当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteは敵の攻撃オブジェクトか？
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK || (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK|| (*ite)->GetObjType() == OBJECTTYPE::SHIELDERATTACK)
		{
			// プレイヤーとその攻撃の当たり判定を行う
			if (IsHit(*(*ite)) == true && _Star_Flag == false)
			{
				// プレイヤーの状態遷移と攻撃オブジェクトのダメージ処理
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
				_Life--;
				_Action_Cnt = _Cnt;
				_State = PLAYERSTATE::DAMAGE;
				PlaySoundMem(_Se["Damage"], DX_PLAYTYPE_BACK, true);
			}
		}
	}
}

/*----------居合----------*/
void Player::Iai(Game& g) {
	_GrHandle = _GrAll["Iai"][_Anime["Iai"]];
	auto frame = _Cnt - _Action_Cnt;
	if (frame >= IAI_BEGINFRAME && IAI_ALLFRAME >= frame) {
		if (_isFlip == false) {
			_x -= 40;
			g.GetChip()->IsHit(*this, -1, 0);
		}
		if (_isFlip == true) {
			_x += 40;
			g.GetChip()->IsHit(*this, 1, 0);
		}
	}
	if (frame == IAI_BEGINFRAME - 6) {
		if (_isFlip == false) {
			for (int i = 0; i < IAI_PARTICLE1_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % IAI_PARTICLE1_RANDOMX1) - IAI_PARTICLE1_RANDOMX2) / IAI_PARTICLE1_RANDOMX3, ((rand() % -IAI_PARTICLE1_RANDOMY1) - IAI_PARTICLE1_RANDOMY2) / IAI_PARTICLE1_RANDOMY3);
				auto i1 = new IaiParticle1(xy, dxy,false);
				g.GetOS()->Add(i1);
			}
		}
		if (_isFlip == true) {
			for (int i = 0; i < IAI_PARTICLE1_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % IAI_PARTICLE1_RANDOMX1) - IAI_PARTICLE1_RANDOMX2) / IAI_PARTICLE1_RANDOMX3, ((rand() % -IAI_PARTICLE1_RANDOMY1) - IAI_PARTICLE1_RANDOMY2) / IAI_PARTICLE1_RANDOMY3);
				auto i1 = new IaiParticle1(xy, dxy,true);
				g.GetOS()->Add(i1);
			}
		}
	}
	if (frame == IAI_BEGINFRAME) {
		StopSoundMem(_Se["SwordIn"]);
		PlaySoundMem(_Se["Iai"], DX_PLAYTYPE_BACK, true);
		
		if (_isFlip == false) {
			//居合オブジェクトの生成
			auto iac = new IaiCollision(_x + _hit_x - IAI_WIDTH, _y - _hit_h / 2);
			// オブジェクトサーバ-に蹴り判定オブジェクトを追加
			g.GetOS()->Add(iac);
			for (int i = 0; i < IAI_PARTICLE2_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % IAI_PARTICLE2_RANDOMX1) - IAI_PARTICLE2_RANDOMX2) / IAI_PARTICLE2_RANDOMX3, ((rand() % -IAI_PARTICLE2_RANDOMY1) - IAI_PARTICLE2_RANDOMY2) / IAI_PARTICLE2_RANDOMY3);
				auto i2 = new IaiParticle2(xy, dxy,false);
				g.GetOS()->Add(i2);
			}
			for (int i = 0; i < IAI_PARTICLE3_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % IAI_PARTICLE3_RANDOMX1) - IAI_PARTICLE3_RANDOMX2) / IAI_PARTICLE3_RANDOMX3, ((rand() % -IAI_PARTICLE3_RANDOMY1) - IAI_PARTICLE3_RANDOMY2) / IAI_PARTICLE3_RANDOMY3);
				auto i3 = new IaiParticle3(xy, dxy,false);
				g.GetOS()->Add(i3);
			}
		}
		if (_isFlip == true) {
			//居合オブジェクトの生成
			auto iac = new IaiCollision(_x - _hit_x, _y - _hit_h / 2);
			// オブジェクトサーバ-に居合判定オブジェクトを追加
			g.GetOS()->Add(iac);
			for (int i = 0; i < IAI_PARTICLE2_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % IAI_PARTICLE2_RANDOMX1) - IAI_PARTICLE2_RANDOMX2) / IAI_PARTICLE2_RANDOMX3, ((rand() % -IAI_PARTICLE2_RANDOMY1) - IAI_PARTICLE2_RANDOMY2) / IAI_PARTICLE2_RANDOMY3);
				auto i2 = new IaiParticle2(xy, dxy,true);
				g.GetOS()->Add(i2);
			}
			for (int i = 0; i < IAI_PARTICLE3_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % IAI_PARTICLE3_RANDOMX1) - IAI_PARTICLE3_RANDOMX2) / IAI_PARTICLE3_RANDOMX3, ((rand() % -IAI_PARTICLE3_RANDOMY1) - IAI_PARTICLE3_RANDOMY2) / IAI_PARTICLE3_RANDOMY3);
				auto i3 = new IaiParticle3(xy, dxy,true);
				g.GetOS()->Add(i3);
			}
		}
		if (frame >= 0 && IAI_BEGINFRAME >= frame) {
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
						PlaySoundMem(_Se["Damage"], DX_PLAYTYPE_BACK, true);
					}
				}
			}
		}
	}
	if (frame == IAI_ALLFRAME) {
		_State = PLAYERSTATE::IDLE;
	}
}
///*----------スウェイ----------*/
void Player::Sway(Game& g){

}

/*----------被ダメ----------*/
void Player::Damage(Game& g) {
	_GrHandle = _GrAll["Damage"][_Anime["Damage"]];
	auto frame = _Cnt - _Action_Cnt;
	if (frame == DAMAGE_ALLFRAME) {
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
	_GrHandle = _GrAll["Dead"][_Anime["Dead"]];
	auto frame = _Cnt - _Action_Cnt;
	if (_Cnt - _Action_Cnt == DEAD_ALLFRAME) {
		Delete(g);
	}
}

/*---------階段位置調整---------*/
void Player::StairMove(Game& g) {
	_GrHandle = _GrAll["Move"][_Anime["Move"]];
	if (_StairFlip_Flag == false) {
		if (_x >= _Stair_x + StInfo::POSITION_HITX) {
			_isFlip = false;
			--_x;
		}
		if (_x <= _Stair_x + StInfo::POSITION_HITX) {
			_isFlip = true;
			_Position = { static_cast<double>(_x),static_cast<double>(_y) };
			_State = PLAYERSTATE::STAIRUP;
		}
	}
	if (_StairFlip_Flag == true) {
		if (_x <= _Stair_x + StInfo::POSITION_HITX + StInfo::COLLISION_WIDTH) {
			_isFlip = true;
			++_x;
		}
		if (_x >= _Stair_x + StInfo::POSITION_HITX + StInfo::COLLISION_WIDTH) {
			_isFlip = false;
			_Position = { static_cast<double>(_x),static_cast<double>(_y) };
			_State = PLAYERSTATE::STAIRUP;
		}
	}
}

/*---------階段上昇------------*/
void Player::StairUp(Game& g) {
	_GrHandle = _GrAll["Move"][_Anime["Move"]];
	_Stairup_Spd = 3.0f;
	if (_StairFlip_Flag == false) {
		_angle = Math::ToRadians(280);
	}
	if (_StairFlip_Flag == true) {
		_angle = Math::ToRadians(260);
	}
	_velocityDir = { std::cos(_angle), std::sin(_angle) };
	auto vd = _velocityDir * _Stairup_Spd;
	_Position += vd;
	_x = _Position.x;
	_y = _Position.y;
	auto upheight = _y - _Player_y;
	if (upheight == -StInfo::COLLISION_HEIGHT) {
		_State = PLAYERSTATE::IDLE;
	}
}