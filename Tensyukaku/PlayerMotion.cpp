#include <DxLib.h>
#include "Player.h"
#include "Game.h"
#include "PlayerMotionCollision.h"
#include "ObjectBase.h"
#include "PlayerParticle.h"
#include "Stair.h"
#include "EnemyBase.h"
#include "OverlayBlack.h"
#include "ModeGameover.h"
#include "ModeGame.h"
using namespace PInfo;
using namespace PParInfo;
using namespace StInfo;

/*----------出現----------*/
void Player::Appear(Game& g) {
	auto frame = _cnt - _action_cnt;
	_GrHandle = _GrAll["Appear"][_Anime["Appear"]];
	_Anime["Appear"] = 0;
	if (frame == 1) {
		PlaySoundMem(_Se["BStartGame"], DX_PLAYTYPE_BACK, true);
	}
	auto ob = (OverlayBlack*)g.GetMS()->Get("OverlayBlack");
	auto Pal = ob->GetPal();
	if (Pal <= 100) {
		_action_cnt = _cnt;
		_State = PLAYERSTATE::SWORDOUT;
	}
}

/*----------抜刀----------*/
void Player::Swordout(Game& g) {
	auto frame = _cnt - _action_cnt;
 	_GrHandle = _GrAll["Swordout"][_Anime["Swordout"]];
	_Anime["Swordout"] = ((frame) / ANIMESPEED_SWORDOUT) % SWORDOUT_ANIMEMAX;
	auto vpal = g.GetVpal();
	if (frame == 1) {
		vpal["Main"]=0;
		PlaySoundMem(g.GetBgm()["Main"], DX_PLAYTYPE_LOOP, true);
	}
	if (frame <SWORDOUT_ANIMEFRAME&&vpal["Main"]<120) {
		vpal["Main"]+=2;
		g.SetVpal(vpal);
	}
	if (frame == SWORDOUT_ANIMEFRAME) {
		_action_cnt = _cnt;
		_State = PLAYERSTATE::IDLE;
	}
}
/*----------待機----------*/
void Player::Idle(Game& g) {
	_GrHandle = _GrAll["Idle"] [_Anime["Idle"]];
	_Anime["Idle"] = (_cnt / ANIMESPEED_IDLE) % IDLE_ANIMEMAX;
	if (g.GetTrg() & PAD_INPUT_6&&_iai_gauge==IAI_MAX) {
		_State = PLAYERSTATE::IAI;
		_action_cnt = _cnt;
		PlaySoundMem(_Se["Iai"], DX_PLAYTYPE_BACK, true);
	}
	if (g.GetTrg() & PAD_INPUT_5) {
		_State = PLAYERSTATE::SWAY;
		PlaySoundMem(_Se["Sway"], DX_PLAYTYPE_BACK, true);
		_action_cnt = _cnt;
	}
	if (g.GetTrg() & PAD_INPUT_4) {
		_State = PLAYERSTATE::MIDDLEATTACK;
		_action_cnt = _cnt;		
	}
	if (g.GetTrg() & PAD_INPUT_3) {
		_State = PLAYERSTATE::LOWATTACK;
		_action_cnt = _cnt;
	}
	if (g.GetTrg() & PAD_INPUT_1) {
		_State = PLAYERSTATE::KICK;
		_action_cnt = _cnt;
	}
	if (g.GetKey() & PAD_INPUT_LEFT || g.GetKey() & PAD_INPUT_RIGHT) {
		_State = PLAYERSTATE::MOVE;
		_action_cnt = _cnt;
	}
#ifdef _DEBUG
	if (g.GetKey() & PAD_INPUT_UP && g.GetKey() & PAD_INPUT_7|| g.GetKey() & PAD_INPUT_DOWN && g.GetKey() & PAD_INPUT_7)
	{
		_State = PLAYERSTATE::MOVE;
		_action_cnt = _cnt;
	}
#endif
}
/*----------移動----------*/
void Player::Move(Game& g) {
	_GrHandle = _GrAll["Move"][_Anime["Move"]];
	_Anime["Move"] = (_cnt / _move_animespeed) % MOVE_ANIMEMAX;

	if (g.GetTrg() & PAD_INPUT_6 && _iai_gauge == IAI_MAX) {
		_State = PLAYERSTATE::IAI;
		_action_cnt = _cnt;
		PlaySoundMem(_Se["Iai"], DX_PLAYTYPE_BACK, true);
	}
	else if (g.GetTrg() & PAD_INPUT_5) {
		_State = PLAYERSTATE::SWAY;
		PlaySoundMem(_Se["Sway"], DX_PLAYTYPE_BACK, true);
		_action_cnt = _cnt;
	}
	else if (g.GetTrg() & PAD_INPUT_4) {
		_State = PLAYERSTATE::MIDDLEATTACK;
		_action_cnt = _cnt;
	}
	else if (g.GetTrg() & PAD_INPUT_3) {
		_State = PLAYERSTATE::LOWATTACK;
		_action_cnt = _cnt;
	}
	else if (g.GetTrg() & PAD_INPUT_1) {
		_State = PLAYERSTATE::KICK;
		_action_cnt = _cnt;
	}
	else if (g.GetKey() & PAD_INPUT_LEFT)
	{
		_x -= _spd;
		g.GetChip()->IsHit(*this, -1, 0);
		_isflip = false;

	}
	else if (g.GetKey() & PAD_INPUT_RIGHT)
	{
		_x += _spd;
		g.GetChip()->IsHit(*this, 1, 0);
		_isflip = true;

	}
#ifdef _DEBUG
	else if (g.GetKey() & PAD_INPUT_UP && g.GetKey() & PAD_INPUT_7)
	{
		_y -= _spd+10;
		_isflip = true;

	}
	else if (g.GetKey() & PAD_INPUT_DOWN && g.GetKey() & PAD_INPUT_7)
	{
		_y += _spd + 10;
		_isflip = true;

	}
#endif
	else {
		_State = PLAYERSTATE::IDLE;
	}
}
/*----------中段攻撃----------*/
void Player::MidAttack(Game& g) {
	auto frame = _cnt - _action_cnt;
	_GrHandle = _GrAll["MiddleAttack"][_Anime["MiddleAttack"]];
	_Anime["MiddleAttack"] = ((frame) / ANIMESPEED_MIDDLEATTACK) % MIDDLEATTACK_ANIMEMAX;
	if (frame < MIDDLEATTACK_BEGINFRAME) {
		if (_isflip == false) {
			_x -= 10;
			g.GetChip()->IsHit(*this, -1, 0);
		}
		if (_isflip == true) {
			_x += 10;
			g.GetChip()->IsHit(*this, 1, 0);
		}
	}
	if (frame == MIDDLEATTACK_BEGINFRAME) {
		PlaySoundMem(_Se["MiddleAttack"], DX_PLAYTYPE_BACK, true);
		if (_isflip == false) {
			//中段攻撃判定オブジェクトの生成
			auto mac = new MiddleAttackCollision(_x + _hit_x - MIDDLEATTACK_WIDTH, _y - _hit_h);
			// オブジェクトサーバ-に中段攻撃判定オブジェクトを追加
			g.GetOS()->Add(mac);
			//パーティクル追加
			for (int i = 0; i < MIDDLEATTACK_PARTICLE1_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % MIDDLEATTACK_PARTICLE1_RANDOMX1) - MIDDLEATTACK_PARTICLE1_RANDOMX2) / MIDDLEATTACK_PARTICLE1_RANDOMX3, ((rand() % MIDDLEATTACK_PARTICLE1_RANDOMY1) - MIDDLEATTACK_PARTICLE1_RANDOMY2) / MIDDLEATTACK_PARTICLE1_RANDOMY3);
				auto m1 = new MiddleAttackParticle1(xy, dxy, false);
				g.GetOS()->Add(m1);
			}
			for (int i = 0; i < MIDDLEATTACK_PARTICLE2_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % MIDDLEATTACK_PARTICLE2_RANDOMX1) - MIDDLEATTACK_PARTICLE2_RANDOMX2) / MIDDLEATTACK_PARTICLE2_RANDOMX3, ((rand() % MIDDLEATTACK_PARTICLE2_RANDOMY1) - MIDDLEATTACK_PARTICLE2_RANDOMY2) / MIDDLEATTACK_PARTICLE2_RANDOMY3);
				auto m2 = new MiddleAttackParticle2(xy, dxy, false);
				g.GetOS()->Add(m2);
			}
		};
		if (_isflip == true) {
			//中段攻撃判定オブジェクトの生成
			auto mac = new MiddleAttackCollision(_x - _hit_x, _y - _hit_h);
			// オブジェクトサーバ-に中段攻撃判定オブジェクトを追加
			g.GetOS()->Add(mac);
			//パーティクル発生
			for (int i = 0; i < MIDDLEATTACK_PARTICLE1_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % MIDDLEATTACK_PARTICLE1_RANDOMX1) - MIDDLEATTACK_PARTICLE1_RANDOMX2) / MIDDLEATTACK_PARTICLE1_RANDOMX3, ((rand() % MIDDLEATTACK_PARTICLE1_RANDOMY1) - MIDDLEATTACK_PARTICLE1_RANDOMY2) / MIDDLEATTACK_PARTICLE1_RANDOMY3);
				auto m1 = new MiddleAttackParticle1(xy, dxy, true);
				g.GetOS()->Add(m1);
			}
			for (int i = 0; i < MIDDLEATTACK_PARTICLE2_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % MIDDLEATTACK_PARTICLE2_RANDOMX1) - MIDDLEATTACK_PARTICLE2_RANDOMX2) / MIDDLEATTACK_PARTICLE2_RANDOMX3, ((rand() % MIDDLEATTACK_PARTICLE2_RANDOMY1) - MIDDLEATTACK_PARTICLE2_RANDOMY2) / MIDDLEATTACK_PARTICLE2_RANDOMY3);
				auto m2 = new MiddleAttackParticle2(xy, dxy, true);
				g.GetOS()->Add(m2);
			}
		}
	}
	if (frame == MIDDLEATTACK_ALLFRAME) {
		_State = PLAYERSTATE::IDLE;
	}
	
}
/*----------下段攻撃----------*/
void Player::LowAttack(Game& g) {
	auto frame = _cnt - _action_cnt;
	_GrHandle = _GrAll["LowAttack"][_Anime["LowAttack"]];
	_Anime["LowAttack"] = ((frame) / ANIMESPEED_LOWATTACK) % LOWATTACK_ANIMEMAX;
	if (frame == LOWATTACK_BEGINFRAME) {
		PlaySoundMem(_Se["LowAttack"], DX_PLAYTYPE_BACK, true);
		if (_isflip == false) {
			//下段攻撃判定オブジェクトの生成
			auto lac = new LowAttackCollision(_x + _hit_x - LOWATTACK_WIDTH, _y - LOWATTACK_HEIGHT);
			// オブジェクトサーバ-に下段攻撃判定オブジェクトを追加
			g.GetOS()->Add(lac);
			//パーティクル発生
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
		if (_isflip == true) {
			//下段攻撃判定オブジェクトの生成
			auto lac = new LowAttackCollision(_x - _hit_x, _y - LOWATTACK_HEIGHT);
			// オブジェクトサーバ-に下段攻撃判定オブジェクトを追加
			g.GetOS()->Add(lac);
			//パーティクル発生
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
}

/*----------蹴り----------*/
void Player::Kick(Game& g) {
	auto frame = _cnt - _action_cnt;
	_GrHandle = _GrAll["Kick"][_Anime["Kick"]];
	_Anime["Kick"] = ((frame) / ANIMESPEED_KICK) % KICK_ANIMEMAX;
	if (frame == KICK_BEGINFRAME) {
		
		PlaySoundMem(_Se["Kick"], DX_PLAYTYPE_BACK, true);
		if (_isflip == false) {
			//蹴り判定オブジェクトの生成
			auto kic = new KickCollision(_x + _hit_x - KICK_WIDTH, _y - _hit_h / 2);
			// オブジェクトサーバ-に蹴り判定オブジェクトを追加
			g.GetOS()->Add(kic);
		};
		if (_isflip == true) {
			//蹴り判定オブジェクトの生成
			auto kic = new KickCollision(_x - _hit_x, _y - _hit_h / 2);
			// オブジェクトサーバ-に蹴り判定オブジェクトを追加
			g.GetOS()->Add(kic);
		}
	}
	if (frame == KICK_ALLFRAME) {
		
		_State = PLAYERSTATE::IDLE;
	}
}

/*----------居合----------*/
void Player::Iai(Game& g) {
	auto frame = _cnt - _action_cnt;
	_GrHandle = _GrAll["Iai"][_Anime["Iai"]];
	if (frame < IAI_ANIMEFRAME) {
		_Anime["Iai"] = ((frame) / ANIMESPEED_IAI) % IAI_ANIMEMAX;
	}
	if (frame >= IAI_BEGINFRAME && IAI_ALLFRAME - 15 >= frame) {
		_nohit_flag = true;
		if (_isflip == false) {
			_x -= IAI_MOVEMENT;
			g.GetChip()->IsHit(*this, -1, 0);
		}
		if (_isflip == true) {
			_x += IAI_MOVEMENT;
			g.GetChip()->IsHit(*this, 1, 0);
		}
	}
	else { _nohit_flag = false; }
	if (frame == IAI_BEGINFRAME - 6) {
		if (_isflip == false) {
			//パーティクル発生
			for (int i = 0; i < IAI_PARTICLE1_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % IAI_PARTICLE1_RANDOMX1) - IAI_PARTICLE1_RANDOMX2) / IAI_PARTICLE1_RANDOMX3, ((rand() % -IAI_PARTICLE1_RANDOMY1) - IAI_PARTICLE1_RANDOMY2) / IAI_PARTICLE1_RANDOMY3);
				auto i1 = new IaiParticle1(xy, dxy, false);
				g.GetOS()->Add(i1);
			}
		}
		if (_isflip == true) {
			//パーティクル発生
			for (int i = 0; i < IAI_PARTICLE1_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % IAI_PARTICLE1_RANDOMX1) - IAI_PARTICLE1_RANDOMX2) / IAI_PARTICLE1_RANDOMX3, ((rand() % -IAI_PARTICLE1_RANDOMY1) - IAI_PARTICLE1_RANDOMY2) / IAI_PARTICLE1_RANDOMY3);
				auto i1 = new IaiParticle1(xy, dxy, true);
				g.GetOS()->Add(i1);
			}
		}
	}
	if (frame == IAI_BEGINFRAME) {
		_iai_gauge = 0;
		_gaugeup_flag = false;
		if (_isflip == false) {
			//居合オブジェクトの生成
			auto iac = new IaiCollision(_x + _hit_x - IAI_WIDTH, _y - _hit_h / 2);
			// オブジェクトサーバ-に蹴り判定オブジェクトを追加
			g.GetOS()->Add(iac);
			//パーティクル発生
			for (int i = 0; i < IAI_PARTICLE2_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % IAI_PARTICLE2_RANDOMX1) - IAI_PARTICLE2_RANDOMX2) / IAI_PARTICLE2_RANDOMX3, ((rand() % -IAI_PARTICLE2_RANDOMY1) - IAI_PARTICLE2_RANDOMY2) / IAI_PARTICLE2_RANDOMY3);
				auto i2 = new IaiParticle2(xy, dxy, false);
				g.GetOS()->Add(i2);
			}
			for (int i = 0; i < IAI_PARTICLE3_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % IAI_PARTICLE3_RANDOMX1) - IAI_PARTICLE3_RANDOMX2) / IAI_PARTICLE3_RANDOMX3, ((rand() % -IAI_PARTICLE3_RANDOMY1) - IAI_PARTICLE3_RANDOMY2) / IAI_PARTICLE3_RANDOMY3);
				auto i3 = new IaiParticle3(xy, dxy, false);
				g.GetOS()->Add(i3);
			}
		}
		if (_isflip == true) {
			//居合オブジェクトの生成
			auto iac = new IaiCollision(_x - _hit_x, _y - _hit_h / 2);
			// オブジェクトサーバ-に居合判定オブジェクトを追加
			g.GetOS()->Add(iac);
			//パーティクル発生
			for (int i = 0; i < IAI_PARTICLE2_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % IAI_PARTICLE2_RANDOMX1) - IAI_PARTICLE2_RANDOMX2) / IAI_PARTICLE2_RANDOMX3, ((rand() % -IAI_PARTICLE2_RANDOMY1) - IAI_PARTICLE2_RANDOMY2) / IAI_PARTICLE2_RANDOMY3);
				auto i2 = new IaiParticle2(xy, dxy, true);
				g.GetOS()->Add(i2);
			}
			for (int i = 0; i < IAI_PARTICLE3_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % IAI_PARTICLE3_RANDOMX1) - IAI_PARTICLE3_RANDOMX2) / IAI_PARTICLE3_RANDOMX3, ((rand() % -IAI_PARTICLE3_RANDOMY1) - IAI_PARTICLE3_RANDOMY2) / IAI_PARTICLE3_RANDOMY3);
				auto i3 = new IaiParticle3(xy, dxy, true);
				g.GetOS()->Add(i3);
			}
		}
	}
	if (frame == IAI_ALLFRAME) {
		_State = PLAYERSTATE::IDLE;
	}
}
///*----------スウェイ----------*/
void Player::Sway(Game& g){
	auto frame = _cnt - _action_cnt;
	_GrHandle = _GrAll["Sway"][_Anime["Sway"]];
	_Anime["Sway"] = ((frame) / ANIMESPEED_SWAY) % SWAY_ANIMEMAX;
	//スウェイ時の無敵フレーム
	if (frame >= SWAY_NOHITBEGINFRAME && SWAY_NOHITENDFRAME > frame) {
		_nohit_flag = true;
	}
	else { _nohit_flag = false; }
	if (frame == 1) {
		for (int i = 0; i < SWAY_PARTICLE_QTY; i++)
		{
			std::pair<int, int> xy = std::make_pair(_x, _y);
			std::pair<double, double> dxy = std::make_pair(((rand() % SWAY_PARTICLE_RANDOMX1) - SWAY_PARTICLE_RANDOMX2) / SWAY_PARTICLE_RANDOMX3, ((rand() % -SWAY_PARTICLE_RANDOMY1) - SWAY_PARTICLE_RANDOMY2) / SWAY_PARTICLE_RANDOMY3);
			auto sw = new SwayParticle(xy, dxy, true);
			g.GetOS()->Add(sw);
		}
	}
	if (frame < SWAY_MOVEFRAME) {
		if (_isflip == false) {
			_x += SWAY_MOVEMENT;
			g.GetChip()->IsHit(*this, 1, 0);
		}
		if (_isflip == true) {
			_x -= SWAY_MOVEMENT;
			g.GetChip()->IsHit(*this, -1, 0);	
		}
	}
	if (frame == SWAY_ALLFRAME) {
		_State = PLAYERSTATE::IDLE;
	}
}

/*----------被ダメ----------*/
void Player::Damage(Game& g) {
	auto frame = _cnt - _action_cnt;
	_GrHandle = _GrAll["Damage"][_Anime["Damage"]];
	StopSoundMem(_Se["Iai"]);
	_nohit_flag = true; 
	if (frame < DAMAGE_ANIMEFRAME) {
		_Anime["Damage"] = ((frame) / ANIMESPEED_DAMAGE) % DAMAGE_ANIMEMAX;
	}
	if (frame == DAMAGE_ALLFRAME) {
		_Star_Cnt = _cnt;
		_action_cnt = _cnt;
		_nohit_flag = false;
		if (_life > 0) {
			_star_flag = true;
		}
		if (_life <= 0) {
			PlaySoundMem(_Se["Dead"], DX_PLAYTYPE_BACK, true);
			_State=PLAYERSTATE::DEAD;
		}
		else {
			_State = PLAYERSTATE::IDLE;
		}
	}
}

/*----------死亡----------*/
void Player::Dead(Game& g) {
	auto frame = _cnt - _action_cnt;
	_GrHandle = _GrAll["Dead"][_Anime["Dead"]];
	_hit_x = 10000;
	if (frame < DEAD_ANIMEFRAME){
	_Anime["Dead"] = ((frame) / ANIMESPEED_DEAD) % DEAD_ANIMEMAX; 
		}
	if (frame == DEAD_ALLFRAME) {
		g.SetRestartFlag(true);
		auto mg = (ModeGame*)g.GetMS()->Get("Game");
		mg->SetStopObjProcess(true);
		g.GetMS()->Del(g.GetMS()->Get("Flame"));
		StopSoundMem(g.GetBgm()["Main"]);
		StopSoundMem(g.GetBgm()["Boss"]);
		auto mgo = new ModeGameover();
		g.GetMS()->Add(mgo,1, "Gameover");
		
	}
}

/*---------階段位置調整---------*/
void Player::StairMove(Game& g) {
	_GrHandle = _GrAll["Move"][_Anime["Move"]];
	_Anime["Move"] = (_cnt / ANIMESPEED_RUN) % MOVE_ANIMEMAX;
	_nohit_flag = true;
	if (_StairFlip_Flag == false) {
		if (_x >= _Stair_x + StInfo::POSITION_HITX) {
			_isflip = false;
			_x -= STAIRMOVE_SPEED;
		}
		if (_x <= _Stair_x + StInfo::POSITION_HITX) {
			_isflip = true;
			_position = { static_cast<double>(_x),static_cast<double>(_y) };
			_State = PLAYERSTATE::STAIRUP;
		}
	}
	if (_StairFlip_Flag == true) {
		if (_x <= _Stair_x + StInfo::POSITION_HITX + StInfo::COLLISION_WIDTH) {
			_isflip = true;
			_x += STAIRMOVE_SPEED;
		}
		if (_x >= _Stair_x + StInfo::POSITION_HITX + StInfo::COLLISION_WIDTH) {
			_isflip = false;
			_position = { static_cast<double>(_x),static_cast<double>(_y) };
			_State = PLAYERSTATE::STAIRUP;
		}
	}
}

/*---------階段上昇------------*/
void Player::StairUp(Game& g) {
	_GrHandle = _GrAll["Move"][_Anime["Move"]];
	_Anime["Move"] = (_cnt / ANIMESPEED_WALK) % MOVE_ANIMEMAX;
	_Stairup_Spd = STAIRUP_SPEED;
	if (_StairFlip_Flag == false) {
		_angle = 4.886921905584122f;/*Math::ToRadians(280)*/
	}
	if (_StairFlip_Flag == true) {
		_angle = 4.53756055185257f;/*Math::ToRadians(260)*/
	}
	_velocityDir = { std::cos(_angle), std::sin(_angle) };
	auto vd = _velocityDir * _Stairup_Spd;
	auto positionX = static_cast<int>( _position.x);
	auto positionY = static_cast<int>( _position.y);
	_position += vd;
	_x = positionX;
	_y = positionY;
	auto upheight = _y - _Player_y;
	if (upheight == -StInfo::COLLISION_HEIGHT) {
		_nohit_flag = false;
		_State = PLAYERSTATE::IDLE;
	}
}

/*---------ボス階段位置調整---------*/
void Player::BossStairMove(Game& g) {
	_GrHandle = _GrAll["Move"][_Anime["Move"]];
	_Anime["Move"] = (_cnt / ANIMESPEED_RUN) % MOVE_ANIMEMAX;
	_nohit_flag =true;
	if (_StairFlip_Flag == false) {
		if (_x >= _Stair_x + StInfo::POSITION_HITX) {
			_isflip = false;
			_x -= STAIRMOVE_SPEED;
		}
		if (_x <= _Stair_x + StInfo::POSITION_HITX) {
			_isflip = true;
			_position = { static_cast<double>(_x),static_cast<double>(_y) };
			auto ol = new OverlayBlack();
			ol->SetFade(120, 240, 360, 2);
			g.GetMS()->Add(ol, 99999, "OverlayBlack");
			_State = PLAYERSTATE::BOSSSTAIRUP;
		}
	}
	if (_StairFlip_Flag == true) {
		if (_x <= _Stair_x + StInfo::POSITION_HITX + StInfo::COLLISION_WIDTH) {
			_isflip = true;
			_x += STAIRMOVE_SPEED;
		}
		if (_x >= _Stair_x + StInfo::POSITION_HITX + StInfo::COLLISION_WIDTH) {
			_isflip = false;
			_position = { static_cast<double>(_x),static_cast<double>(_y) };
			auto ol = new OverlayBlack();
			ol->SetFade(120, 240, 360, 2);
			g.GetMS()->Add(ol, 99999, "OverlayBlack");
			_State = PLAYERSTATE::BOSSSTAIRUP;
		}
	}
}

/*---------ボス階段上昇------------*/
void Player::BossStairUp(Game& g) {
	_GrHandle = _GrAll["Move"][_Anime["Move"]];
	_Anime["Move"] = (_cnt / ANIMESPEED_WALK) % MOVE_ANIMEMAX;
	auto vpal = g.GetVpal();
	vpal["Main"] -= 1;
	g.SetVpal(vpal);
	_Stairup_Spd = BOSSSTAIRUP_SPEED;
	if (_StairFlip_Flag == false) {
		_angle = 4.886921905584122f;/*Math::ToRadians(280)*/
	}
	if (_StairFlip_Flag == true) {
		_angle = 4.53756055185257f;/*Math::ToRadians(260)*/
	}
	_velocityDir = { std::cos(_angle), std::sin(_angle) };
	auto vd = _velocityDir * _Stairup_Spd;
	auto positionX = static_cast<int>(_position.x);
	auto positionY = static_cast<int>(_position.y);
	_position += vd;
	_x = positionX;
	_y = positionY;
	auto upheight = _y - _Player_y;
	if (upheight == -StInfo::COLLISION_HEIGHT) {
		StopSoundMem(g.GetBgm()["Main"]);
		_nohit_flag = false;
		_State = PLAYERSTATE::IDLE;
	}
}
/*-----イベントAの処理-----*/
void Player::BossEventA(Game& g) {
	auto frame = _cnt - _action_cnt;
	_GrHandle = _GrAll["Idle"][_Anime["Idle"]];
	_Anime["Idle"] = (_cnt / ANIMESPEED_IDLE) % IDLE_ANIMEMAX;
	if (frame == 1) {
		_CameraX = 800;
	}
	if (frame <=120) {
		_CameraX +=1;
	}
	if (frame >= 240) {
		_CameraX -=1;
	}
	if (frame == 360) {
		_CameraX = 500;
		_State = PLAYERSTATE::IDLE;
	}
}
/*-----イベントBの処理-----*/
void Player::BossEventB(Game& g) {
	auto frame = _cnt - _action_cnt;
	_spd = 4;
	if (frame <= 120) {
		_GrHandle = _GrAll["Idle"][_Anime["Idle"]];
		_Anime["Idle"] = (_cnt / ANIMESPEED_IDLE) % IDLE_ANIMEMAX;
		auto vpal = g.GetVpal();
		vpal["Boss"] -= 1;
		vpal["Flame"] -= 1;
		g.SetVpal(vpal);
	}
	if (frame == 120) {
		StopSoundMem(g.GetBgm()["Boss"]);
		StopSoundMem(g.GetBgm()["Flame"]);
	}
	if (frame > 120 && 310 >= frame) {
		_x += _spd;
		_GrHandle = _GrAll["Move"][_Anime["Move"]];
		_Anime["Move"] = (_cnt / 10) % MOVE_ANIMEMAX;
	}
	if (frame > 310) {
		_GrHandle = _GrAll["Idle"][_Anime["Idle"]];
		_Anime["Idle"] = (_cnt / ANIMESPEED_IDLE) % IDLE_ANIMEMAX;
		if (g.GetTrg() & PAD_INPUT_1) {
			_State = PLAYERSTATE::SPECIALATTACK;
			_action_cnt = _cnt;
		}
	}
}
/*-----特殊攻撃の処理-----*/
void Player::SpecialAttack(Game& g) {
	auto frame = _cnt - _action_cnt;
	_GrHandle = _GrAll["Special"][_Anime["Special"]];
	if (frame < SPECIALATTACK_ANIMEFRAME) {
		_Anime["Special"] = ((frame) / ANIMESPEED_SPECIALATTACK) % SPECIALATTACK_ANIMEMAX;
	}
	if (frame == SPECIALATTACK_BEGINFRAME) {
		//特殊攻撃判定オブジェクトの生成
		auto sc = new SpecialCollision(_x - _hit_x, _y - _hit_h);
		// オブジェクトサーバ-に特殊攻撃判定オブジェクトを追加
		g.GetOS()->Add(sc);
	}
}
