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
/*----------�ҋ@----------*/
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
	//�G�̍U���̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�͓G�̍U���I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK|| (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK|| (*ite)->GetObjType() == OBJECTTYPE::SHIELDERATTACK)
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
/*----------�ړ�----------*/
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
	//�G�̍U���̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�͓G�̍U���I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK || (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK|| (*ite)->GetObjType() == OBJECTTYPE::SHIELDERATTACK)
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
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�͊K�i�I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::STAIR)
		{
			// �v���C���[�Ƃ��̊K�i�̓����蔻����s��
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
/*----------���i�U��----------*/
void Player::MidAttack(Game& g) {
	_GrHandle = _GrAll["MiddleAttack"][_Anime["MiddleAttack"]];
	auto frame = _Cnt - _Action_Cnt;
	if (frame == MIDDLEATTACK_BEGINFRAME) {
		PlaySoundMem(_Se["MiddleAttack"], DX_PLAYTYPE_BACK, true);
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
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK || (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK|| (*ite)->GetObjType() == OBJECTTYPE::SHIELDERATTACK)
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
	_GrHandle = _GrAll["LowAttack"][_Anime["LowAttack"]];
	auto frame = _Cnt - _Action_Cnt;
	if (frame == LOWATTACK_BEGINFRAME) {
		PlaySoundMem(_Se["LowAttack"], DX_PLAYTYPE_BACK, true);
		if (_isFlip == false) {
			//���i�U������I�u�W�F�N�g�̐���
			auto lac = new LowAttackCollision(_x + _hit_x - LOWATTACK_WIDTH, _y - LOWATTACK_HEIGHT);
			// �I�u�W�F�N�g�T�[�o-�ɉ��i�U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(lac);
			//�p�[�e�B�N���ǉ�
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
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK || (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK||(*ite)->GetObjType() == OBJECTTYPE::SHIELDERATTACK)
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
	_GrHandle = _GrAll["Kick"][_Anime["Kick"]];
	auto frame = _Cnt - _Action_Cnt;
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
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK || (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK|| (*ite)->GetObjType() == OBJECTTYPE::SHIELDERATTACK)
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
			//�����I�u�W�F�N�g�̐���
			auto iac = new IaiCollision(_x + _hit_x - IAI_WIDTH, _y - _hit_h / 2);
			// �I�u�W�F�N�g�T�[�o-�ɏR�蔻��I�u�W�F�N�g��ǉ�
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
			//�����I�u�W�F�N�g�̐���
			auto iac = new IaiCollision(_x - _hit_x, _y - _hit_h / 2);
			// �I�u�W�F�N�g�T�[�o-�ɋ�������I�u�W�F�N�g��ǉ�
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
			//�G�̍U���̓����蔻��
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// ite�͓G�̍U���I�u�W�F�N�g���H
				if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK || (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK)
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
		_State = PLAYERSTATE::IDLE;
	}
}
///*----------�X�E�F�C----------*/
void Player::Sway(Game& g){

}

/*----------��_��----------*/
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

/*----------���S----------*/
void Player::Dead(Game& g) {
	_GrHandle = _GrAll["Dead"][_Anime["Dead"]];
	auto frame = _Cnt - _Action_Cnt;
	if (_Cnt - _Action_Cnt == DEAD_ALLFRAME) {
		Delete(g);
	}
}

/*---------�K�i�ʒu����---------*/
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

/*---------�K�i�㏸------------*/
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