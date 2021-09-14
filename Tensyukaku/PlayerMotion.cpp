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
/*----------�ҋ@----------*/
void Player::Idle(Game& g) {
	_GrHandle = _GrAll["Idle"] [_Anime["Idle"]];
	_Anime["Idle"] = (_Cnt / ANIMESPEED_IDLE) % IDLE_ANIMEMAX;
	if (g.GetTrg() & PAD_INPUT_6&&_Iai_Gauge==IAI_MAX) {
		_State = PLAYERSTATE::IAI;
		_Action_Cnt = _Cnt;
		PlaySoundMem(_Se["SwordIn"], DX_PLAYTYPE_BACK, true);
	}
	if (g.GetTrg() & PAD_INPUT_4) {
		_State = PLAYERSTATE::SWAY;
		_Action_Cnt = _Cnt;
	}
	if (g.GetTrg() & PAD_INPUT_1) {
		_State = PLAYERSTATE::MIDDLEATTACK;
		_Action_Cnt = _Cnt;		
	}
	if (g.GetTrg() & PAD_INPUT_3) {
		_State = PLAYERSTATE::LOWATTACK;
		_Action_Cnt = _Cnt;
	}
	if (g.GetTrg() & PAD_INPUT_2) {
		_State = PLAYERSTATE::KICK;
		_Action_Cnt = _Cnt;
	}
	if (g.GetKey() & PAD_INPUT_LEFT || g.GetKey() & PAD_INPUT_RIGHT) {
		_State = PLAYERSTATE::MOVE;
		_Action_Cnt = _Cnt;
	}
#ifdef _DEBUG
	if (g.GetKey() & PAD_INPUT_UP && g.GetKey() & PAD_INPUT_5|| g.GetKey() & PAD_INPUT_DOWN && g.GetKey() & PAD_INPUT_5)
	{
		_State = PLAYERSTATE::MOVE;
		_Action_Cnt = _Cnt;
	}
#endif
	//�G�̍U���̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�͓G�̍U���I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK|| (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK|| (*ite)->GetObjType() == OBJECTTYPE::SHIELDERATTACK|| (*ite)->GetObjType() == OBJECTTYPE::POISON || (*ite)->GetObjType() == OBJECTTYPE::KUNAI)
		{
			// �v���C���[�Ƃ��̍U���̓����蔻����s��
			if (IsHit(*(*ite)) == true&& _Star_Flag == false)
			{
				// �v���C���[�̏�ԑJ�ڂƍU���I�u�W�F�N�g�̃_���[�W����
				(*ite)->Delete(g);		// (*ite) �͍U���I�u�W�F�N�g
				_Life--;
				_Action_Cnt = _Cnt;
				_State = PLAYERSTATE::DAMAGE;
				PlaySoundMem(_Se["Damage"], DX_PLAYTYPE_BACK, true);
			}
		}
	}
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�͊K�i�I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::STAIR)
		{
			// �v���C���[�Ƃ��̊K�i�̓����蔻����s��
			if (IsHit(*(*ite)) == true)
			{
				if (g.GetKey() & PAD_INPUT_UP&&g.GetYBuf()<-UP_YBUF) {
					_Player_y = _y;
					_Stair_x = (*ite)->GetX();
					_StairFlip_Flag = (*ite)->GetFlip();
					_State = PLAYERSTATE::STAIRMOVE;
				}
			}
		}
	}
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�͊K�i�I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::BOSSSTAIR)
		{
			// �v���C���[�Ƃ��̊K�i�̓����蔻����s��
			if (IsHit(*(*ite)) == true)
			{
				if (g.GetKey() & PAD_INPUT_UP && g.GetYBuf() < -UP_YBUF) {
					_Player_y = _y;
					_Stair_x = (*ite)->GetX();
					_StairFlip_Flag = (*ite)->GetFlip();
					_State = PLAYERSTATE::BOSSSTAIRMOVE;
				}
			}
		}
	}
}
/*----------�ړ�----------*/
void Player::Move(Game& g) {
	_GrHandle = _GrAll["Move"][_Anime["Move"]];
	_Anime["Move"] = (_Cnt / _Move_AnimeSpeed) % MOVE_ANIMEMAX;
	
	if (g.GetTrg() & PAD_INPUT_6 && _Iai_Gauge == IAI_MAX) {
		_State = PLAYERSTATE::IAI;
		_Action_Cnt = _Cnt;
		PlaySoundMem(_Se["SwordIn"], DX_PLAYTYPE_BACK, true);
	}
	else if (g.GetTrg() & PAD_INPUT_4) {
		_State = PLAYERSTATE::SWAY;
		_Action_Cnt = _Cnt;
	}
	else if (g.GetTrg() & PAD_INPUT_1) {
		_State = PLAYERSTATE::MIDDLEATTACK;
		_Action_Cnt = _Cnt;
	}
	else if (g.GetTrg() & PAD_INPUT_3) {
		_State = PLAYERSTATE::LOWATTACK;
		_Action_Cnt = _Cnt;
	}
	else if (g.GetTrg() & PAD_INPUT_2) {
		_State = PLAYERSTATE::KICK;
		_Action_Cnt = _Cnt;
	}
	else if (g.GetKey() & PAD_INPUT_LEFT)
	{
		_x -= _Spd;
		g.GetChip()->IsHit(*this, -1, 0);
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�͓G���H
			if ((*ite)->GetObjType() == OBJECTTYPE::ENEMY)
			{
				// �v���C���[�Ƃ��̓G�̓����蔻����s��
				if (IsHit(*(*ite)) == true) {
					_x = _Before_x;

				}
			}
		}
		_isFlip = false;

	}
	else if (g.GetKey() & PAD_INPUT_RIGHT)
	{
		_x += _Spd;
		g.GetChip()->IsHit(*this, 1, 0);
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�͓G���H
			if ((*ite)->GetObjType() == OBJECTTYPE::ENEMY)
			{
				// �v���C���[�Ƃ��̓G�̓����蔻����s��
				if (IsHit(*(*ite)) == true) {
					_x = _Before_x;
				}
			}
		}
		_isFlip = true;

	}
#ifdef _DEBUG
	else if(g.GetKey() & PAD_INPUT_UP&& g.GetKey() & PAD_INPUT_5)
	{
		_y -= _Spd;
		_isFlip = true;

	}
	else if (g.GetKey() & PAD_INPUT_DOWN && g.GetKey() & PAD_INPUT_5)
	{
		_y += _Spd;
		_isFlip = true;

	}
#endif
	else {
		_State = PLAYERSTATE::IDLE;
	}
	//�G�̍U���̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�͓G�̍U���I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK || (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK|| (*ite)->GetObjType() == OBJECTTYPE::SHIELDERATTACK|| (*ite)->GetObjType() == OBJECTTYPE::POISON || (*ite)->GetObjType() == OBJECTTYPE::KUNAI)
		{
			// �v���C���[�Ƃ��̍U���̓����蔻����s��
			if (IsHit(*(*ite)) == true && _Star_Flag == false)
			{
				// �v���C���[�̏�ԑJ�ڂƍU���I�u�W�F�N�g�̃_���[�W����
				(*ite)->Delete(g);		// (*ite) �͍U���I�u�W�F�N�g
				_Life--;
				_State = PLAYERSTATE::DAMAGE;
				PlaySoundMem(_Se["Damage"], DX_PLAYTYPE_BACK, true);
				_Action_Cnt = _Cnt;
			}
		}
	}
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�͊K�i�I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::STAIR)
		{
			// �v���C���[�Ƃ��̊K�i�̓����蔻����s��
			if (IsHit(*(*ite)) == true)
			{
				if (g.GetKey() & PAD_INPUT_UP && g.GetYBuf() < -UP_YBUF) {
					_Player_y = _y;
					_Stair_x = (*ite)->GetX();
					_StairFlip_Flag = (*ite)->GetFlip();
					_State = PLAYERSTATE::STAIRMOVE;
				}
			}
		}
	}
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�͊K�i�I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::BOSSSTAIR)
		{
			// �v���C���[�Ƃ��̊K�i�̓����蔻����s��
			if (IsHit(*(*ite)) == true)
			{
				if (g.GetKey() & PAD_INPUT_UP && g.GetYBuf() < -UP_YBUF) {
					_Player_y = _y;
					_Stair_x = (*ite)->GetX();
					_StairFlip_Flag = (*ite)->GetFlip();
					_State = PLAYERSTATE::BOSSSTAIRMOVE;
				}
			}
		}
	}
}
/*----------���i�U��----------*/
void Player::MidAttack(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["MiddleAttack"][_Anime["MiddleAttack"]];
	_Anime["MiddleAttack"] = ((frame) / ANIMESPEED_MIDDLEATTACK) % MIDDLEATTACK_ANIMEMAX;
	if (frame < MIDDLEATTACK_BEGINFRAME) {
		if (_isFlip == false) {
			_x -= 10;
			g.GetChip()->IsHit(*this, -1, 0);
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// ite�͓G���H
				if ((*ite)->GetObjType() == OBJECTTYPE::ENEMY)
				{
					// �v���C���[�Ƃ��̓G�̓����蔻����s��
					if (IsHit(*(*ite)) == true) {
						_x = _Before_x;
					}
				}
			}
		}
	}
	if (frame < MIDDLEATTACK_BEGINFRAME) {
		if (_isFlip == true) {
			_x += 10;
			g.GetChip()->IsHit(*this, 1, 0);
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// ite�͓G���H
				if ((*ite)->GetObjType() == OBJECTTYPE::ENEMY)
				{
					// �v���C���[�Ƃ��̓G�̓����蔻����s��
					if (IsHit(*(*ite)) == true) {
						_x = _Before_x;
					}
				}
			}
		}
	}
	if (frame == MIDDLEATTACK_BEGINFRAME) {
		PlaySoundMem(_Se["MiddleAttack"], DX_PLAYTYPE_BACK, true);
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�͓G���H
			if ((*ite)->GetObjType() == OBJECTTYPE::ENEMY)
			{
				// �v���C���[�Ƃ��̓G�̓����蔻����s��
				if (IsHit(*(*ite)) == true) {
					_x = _Before_x;
				}
			}
		}
		if (_isFlip == false) {
			//���i�U������I�u�W�F�N�g�̐���
			auto mac = new MiddleAttackCollision(_x + _hit_x - MIDDLEATTACK_WIDTH, _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɒ��i�U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(mac);
			//�p�[�e�B�N���ǉ�
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
			//���i�U������I�u�W�F�N�g�̐���
			auto mac = new MiddleAttackCollision(_x - _hit_x, _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɒ��i�U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(mac);
			//�p�[�e�B�N������
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
	//�G�̍U���̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�͓G�̍U���I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK || (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK|| (*ite)->GetObjType() == OBJECTTYPE::SHIELDERATTACK || (*ite)->GetObjType() == OBJECTTYPE::POISON || (*ite)->GetObjType() == OBJECTTYPE::KUNAI)
		{
			// �v���C���[�Ƃ��̍U���̓����蔻����s��
			if (IsHit(*(*ite)) == true && _Star_Flag == false)
			{
				// �v���C���[�̏�ԑJ�ڂƍU���I�u�W�F�N�g�̃_���[�W����
				(*ite)->Delete(g);		// (*ite) �͍U���I�u�W�F�N�g
				_Life--;
				_Action_Cnt = _Cnt;
				_State = PLAYERSTATE::DAMAGE;
				PlaySoundMem(_Se["Damage"], DX_PLAYTYPE_BACK, true);
			}
		}
	}
}
/*----------���i�U��----------*/
void Player::LowAttack(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["LowAttack"][_Anime["LowAttack"]];
	_Anime["LowAttack"] = ((frame) / ANIMESPEED_LOWATTACK) % LOWATTACK_ANIMEMAX;
	if (frame == LOWATTACK_BEGINFRAME) {
		PlaySoundMem(_Se["LowAttack"], DX_PLAYTYPE_BACK, true);
		if (_isFlip == false) {
			//���i�U������I�u�W�F�N�g�̐���
			auto lac = new LowAttackCollision(_x + _hit_x - LOWATTACK_WIDTH, _y - LOWATTACK_HEIGHT);
			// �I�u�W�F�N�g�T�[�o-�ɉ��i�U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(lac);
			//�p�[�e�B�N������
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
			//���i�U������I�u�W�F�N�g�̐���
			auto lac = new LowAttackCollision(_x - _hit_x, _y - LOWATTACK_HEIGHT);
			// �I�u�W�F�N�g�T�[�o-�ɉ��i�U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(lac);
			//�p�[�e�B�N������
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
	//�G�̍U���̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�͓G�̍U���I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK || (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK||(*ite)->GetObjType() == OBJECTTYPE::SHIELDERATTACK || (*ite)->GetObjType() == OBJECTTYPE::POISON || (*ite)->GetObjType() == OBJECTTYPE::KUNAI)
		{
			// �v���C���[�Ƃ��̍U���̓����蔻����s��
			if (IsHit(*(*ite)) == true && _Star_Flag == false)
			{
				// �v���C���[�̏�ԑJ�ڂƍU���I�u�W�F�N�g�̃_���[�W����
				(*ite)->Delete(g);		// (*ite) �͍U���I�u�W�F�N�g
				_Life--;
				_Action_Cnt = _Cnt;
				_State = PLAYERSTATE::DAMAGE;
				PlaySoundMem(_Se["Damage"], DX_PLAYTYPE_BACK, true);
			}
		}
	}
}

/*----------�R��----------*/
void Player::Kick(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Kick"][_Anime["Kick"]];
	_Anime["Kick"] = ((frame) / ANIMESPEED_KICK) % KICK_ANIMEMAX;
	if (frame == KICK_BEGINFRAME) {
		
		PlaySoundMem(_Se["Kick"], DX_PLAYTYPE_BACK, true);
		if (_isFlip == false) {
			//�R�蔻��I�u�W�F�N�g�̐���
			auto kic = new KickCollision(_x + _hit_x - KICK_WIDTH, _y - _hit_h / 2);
			// �I�u�W�F�N�g�T�[�o-�ɏR�蔻��I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(kic);
		};
		if (_isFlip == true) {
			//�R�蔻��I�u�W�F�N�g�̐���
			auto kic = new KickCollision(_x - _hit_x, _y - _hit_h / 2);
			// �I�u�W�F�N�g�T�[�o-�ɏR�蔻��I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(kic);
		}
	}
	if (frame == KICK_ALLFRAME) {
		
		_State = PLAYERSTATE::IDLE;
	}
	//�G�̍U���̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�͓G�̍U���I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK || (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK|| (*ite)->GetObjType() == OBJECTTYPE::SHIELDERATTACK || (*ite)->GetObjType() == OBJECTTYPE::POISON || (*ite)->GetObjType() == OBJECTTYPE::KUNAI)
		{
			// �v���C���[�Ƃ��̍U���̓����蔻����s��
			if (IsHit(*(*ite)) == true && _Star_Flag == false)
			{
				// �v���C���[�̏�ԑJ�ڂƍU���I�u�W�F�N�g�̃_���[�W����
				(*ite)->Delete(g);		// (*ite) �͍U���I�u�W�F�N�g
				_Life--;
				_Action_Cnt = _Cnt;
				_State = PLAYERSTATE::DAMAGE;
				PlaySoundMem(_Se["Damage"], DX_PLAYTYPE_BACK, true);
			}
		}
	}
}

/*----------����----------*/
void Player::Iai(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Iai"][_Anime["Iai"]];
	if (frame < IAI_ANIMEFRAME) {
		_Anime["Iai"] = ((frame) / ANIMESPEED_IAI) % IAI_ANIMEMAX;
	}
	if (frame >= IAI_BEGINFRAME && IAI_ALLFRAME-15 >= frame) {
		if (_isFlip == false) {
			_x -= IAI_MOVEMENT;
			g.GetChip()->IsHit(*this, -1, 0);
		}
		if (_isFlip == true) {
			_x += IAI_MOVEMENT;
			g.GetChip()->IsHit(*this, 1, 0);
		}
	}
	if (frame == IAI_BEGINFRAME - 6) {
		if (_isFlip == false) {
			//�p�[�e�B�N������
			for (int i = 0; i < IAI_PARTICLE1_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % IAI_PARTICLE1_RANDOMX1) - IAI_PARTICLE1_RANDOMX2) / IAI_PARTICLE1_RANDOMX3, ((rand() % -IAI_PARTICLE1_RANDOMY1) - IAI_PARTICLE1_RANDOMY2) / IAI_PARTICLE1_RANDOMY3);
				auto i1 = new IaiParticle1(xy, dxy,false);
				g.GetOS()->Add(i1);
			}
		}
		if (_isFlip == true) {
			//�p�[�e�B�N������
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
			//�����I�u�W�F�N�g�̐���
			auto iac = new IaiCollision(_x + _hit_x - IAI_WIDTH, _y - _hit_h / 2);
			// �I�u�W�F�N�g�T�[�o-�ɏR�蔻��I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(iac);
			//�p�[�e�B�N������
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
			//�����I�u�W�F�N�g�̐���
			auto iac = new IaiCollision(_x - _hit_x, _y - _hit_h / 2);
			// �I�u�W�F�N�g�T�[�o-�ɋ�������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(iac);
			//�p�[�e�B�N������
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
			//�G�̍U���̓����蔻��
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// ite�͓G�̍U���I�u�W�F�N�g���H
				if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK || (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK || (*ite)->GetObjType() == OBJECTTYPE::SHIELDERATTACK || (*ite)->GetObjType() == OBJECTTYPE::POISON || (*ite)->GetObjType() == OBJECTTYPE::KUNAI)
				{
					// �v���C���[�Ƃ��̓G�̍U���̓����蔻����s��
					if (IsHit(*(*ite)) == true && _Star_Flag == false)
					{
						// �v���C���[�̏�ԑJ�ڂƓG�̍U���I�u�W�F�N�g�̃_���[�W����
						(*ite)->Delete(g);		// (*ite) �͍U���I�u�W�F�N�g
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
		_Iai_Gauge = 0;
		_State = PLAYERSTATE::IDLE;
	}
}
///*----------�X�E�F�C----------*/
void Player::Sway(Game& g){
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Sway"][_Anime["Sway"]];
	_Anime["Sway"] = ((frame) / ANIMESPEED_SWAY) % SWAY_ANIMEMAX;
	if (frame < SWAY_MOVEFRAME) {
		if (_isFlip == false) {
			_x += SWAY_MOVEMENT;
			g.GetChip()->IsHit(*this, 1, 0);
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// ite�͓G���H
				if ((*ite)->GetObjType() == OBJECTTYPE::ENEMY)
				{
					// �v���C���[�Ƃ��̓G�̓����蔻����s��
					if (IsHit(*(*ite)) == true) {
						_x = _Before_x;
					}
				}
			}
		}
		if (_isFlip == true) {
			_x -= SWAY_MOVEMENT;
			g.GetChip()->IsHit(*this, -1, 0);
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// ite�͓G���H
				if ((*ite)->GetObjType() == OBJECTTYPE::ENEMY)
				{
					// �v���C���[�Ƃ��̓G�̓����蔻����s��
					if (IsHit(*(*ite)) == true) {
						_x = _Before_x;
					}
				}
			}
		}
	}
	if (frame == SWAY_ALLFRAME) {
		_State = PLAYERSTATE::IDLE;
	}
}

/*----------��_��----------*/
void Player::Damage(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Damage"][_Anime["Damage"]];
	if (frame < DAMAGE_ANIMEFRAME) {
		_Anime["Damage"] = ((frame) / ANIMESPEED_DAMAGE) % DAMAGE_ANIMEMAX;
	}
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

/*----------���S----------*/
void Player::Dead(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Dead"][_Anime["Dead"]];
	_hit_x = 10000;
	if (frame < DEAD_ANIMEFRAME){
	_Anime["Dead"] = ((frame) / ANIMESPEED_DEAD) % DEAD_ANIMEMAX; 
		}
	if (frame == DEAD_ALLFRAME) {
		g.GetMS()->Del(g.GetMS()->Get("Flame"));
		auto mgo = new ModeGameover();
		g.GetMS()->Add(mgo,1, "Gameover");
		
	}
}

/*---------�K�i�ʒu����---------*/
void Player::StairMove(Game& g) {
	_GrHandle = _GrAll["Move"][_Anime["Move"]];
	_Anime["Move"] = (_Cnt / ANIMESPEED_RUN) % MOVE_ANIMEMAX;
	if (_StairFlip_Flag == false) {
		if (_x >= _Stair_x + StInfo::POSITION_HITX) {
			_isFlip = false;
			_x -= STAIRMOVE_SPEED;
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
			_x += STAIRMOVE_SPEED;
		}
		if (_x >= _Stair_x + StInfo::POSITION_HITX + StInfo::COLLISION_WIDTH) {
			_isFlip = false;
			_Position = { static_cast<double>(_x),static_cast<double>(_y) };
			_State = PLAYERSTATE::STAIRUP;
		}
	}
}

/*---------�K�i�㏸------------*/
void Player::StairUp(Game& g) {
	_GrHandle = _GrAll["Move"][_Anime["Move"]];
	_Anime["Move"] = (_Cnt / ANIMESPEED_WALK) % MOVE_ANIMEMAX;
	_Stairup_Spd = 3.0f;
	if (_StairFlip_Flag == false) {
		_angle = 4.886921905584122f;/*Math::ToRadians(280)*/
	}
	if (_StairFlip_Flag == true) {
		_angle = 4.53756055185257f;/*Math::ToRadians(260)*/
	}
	_velocityDir = { std::cos(_angle), std::sin(_angle) };
	auto vd = _velocityDir * _Stairup_Spd;
	auto positionX = static_cast<int>( _Position.x);
	auto positionY = static_cast<int>( _Position.y);
	_Position += vd;
	_x = positionX;
	_y = positionY;
	auto upheight = _y - _Player_y;
	if (upheight == -StInfo::COLLISION_HEIGHT) {
		_State = PLAYERSTATE::IDLE;
	}
}

/*---------�{�X�K�i�ʒu����---------*/
void Player::BossStairMove(Game& g) {
	_GrHandle = _GrAll["Move"][_Anime["Move"]];
	_Anime["Move"] = (_Cnt / ANIMESPEED_RUN) % MOVE_ANIMEMAX;
	if (_StairFlip_Flag == false) {
		if (_x >= _Stair_x + StInfo::POSITION_HITX) {
			_isFlip = false;
			_x -= STAIRMOVE_SPEED;
		}
		if (_x <= _Stair_x + StInfo::POSITION_HITX) {
			_isFlip = true;
			_Position = { static_cast<double>(_x),static_cast<double>(_y) };
			auto ol = new OverlayBlack();
			ol->FadeSetting(120, 240, 360, 2);
			g.GetMS()->Add(ol, 99999, "OverlayBlack");
			_State = PLAYERSTATE::BOSSSTAIRUP;
		}
	}
	if (_StairFlip_Flag == true) {
		if (_x <= _Stair_x + StInfo::POSITION_HITX + StInfo::COLLISION_WIDTH) {
			_isFlip = true;
			_x += STAIRMOVE_SPEED;
		}
		if (_x >= _Stair_x + StInfo::POSITION_HITX + StInfo::COLLISION_WIDTH) {
			_isFlip = false;
			_Position = { static_cast<double>(_x),static_cast<double>(_y) };
			auto ol = new OverlayBlack();
			ol->FadeSetting(120, 240, 360, 2);
			g.GetMS()->Add(ol, 99999, "OverlayBlack");
			_State = PLAYERSTATE::BOSSSTAIRUP;
		}
	}
}

/*---------�{�X�K�i�㏸------------*/
void Player::BossStairUp(Game& g) {
	_GrHandle = _GrAll["Move"][_Anime["Move"]];
	_Anime["Move"] = (_Cnt / ANIMESPEED_WALK) % MOVE_ANIMEMAX;
	_Stairup_Spd = 3.0f;
	if (_StairFlip_Flag == false) {
		_angle = 4.886921905584122f;/*Math::ToRadians(280)*/
	}
	if (_StairFlip_Flag == true) {
		_angle = 4.53756055185257f;/*Math::ToRadians(260)*/
	}
	_velocityDir = { std::cos(_angle), std::sin(_angle) };
	auto vd = _velocityDir * _Stairup_Spd;
	auto positionX = static_cast<int>(_Position.x);
	auto positionY = static_cast<int>(_Position.y);
	_Position += vd;
	_x = positionX;
	_y = positionY;
	auto upheight = _y - _Player_y;
	if (upheight == -StInfo::COLLISION_HEIGHT) {
		_State = PLAYERSTATE::IDLE;
	}
}
/*-----�C�x���gA�̏���-----*/
void Player::BossEventA(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Idle"][_Anime["Idle"]];
	_Anime["Idle"] = (_Cnt / ANIMESPEED_IDLE) % IDLE_ANIMEMAX;
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
/*-----�C�x���gB�̏���-----*/
void Player::BossEventB(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_Spd = 4;
	if (frame <= 120) {
		_GrHandle = _GrAll["Idle"][_Anime["Idle"]];
		_Anime["Idle"] = (_Cnt / ANIMESPEED_IDLE) % IDLE_ANIMEMAX;
	}
	if (frame > 120 && 310 >= frame) {
		_x += _Spd;
		_GrHandle = _GrAll["Move"][_Anime["Move"]];
		_Anime["Move"] = (_Cnt / 10) % MOVE_ANIMEMAX;
	}
	if (frame > 310) {
		_GrHandle = _GrAll["Idle"][_Anime["Idle"]];
		_Anime["Idle"] = (_Cnt / ANIMESPEED_IDLE) % IDLE_ANIMEMAX;
		if (g.GetTrg() & PAD_INPUT_1) {
			_State = PLAYERSTATE::SPECIALATTACK;
			_Action_Cnt = _Cnt;
		}
	}
}
/*-----����U���̏���-----*/
void Player::SpecialAttack(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Special"][_Anime["Special"]];
	if (frame < SPECIALATTACK_ANIMEFRAME) {
		_Anime["Special"] = ((frame) / ANIMESPEED_SPECIALATTACK) % SPECIALATTACK_ANIMEMAX;
	}
	if (frame == SPECIALATTACK_BEGINFRAME) {
		//����U������I�u�W�F�N�g�̐���
		auto sc = new SpecialCollision(_x - _hit_x, _y - _hit_h);
		// �I�u�W�F�N�g�T�[�o-�ɓ���U������I�u�W�F�N�g��ǉ�
		g.GetOS()->Add(sc);
	}
}
