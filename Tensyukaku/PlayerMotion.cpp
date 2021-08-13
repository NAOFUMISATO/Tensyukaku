#include <DxLib.h>
#include "Player.h"
#include "Game.h"
#include "PlayerMotionCollision.h"

using namespace PInfo;
/*----------�ҋ@----------*/
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
	//�G�̍U���̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�͓G�̍U���I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK|| (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK)
		{
			// �v���C���[�Ƃ��̍U���̓����蔻����s��
			if (IsHit(*(*ite)) == true&& _Star_Flag == false)
			{
				// �v���C���[�̏�ԑJ�ڂƍU���I�u�W�F�N�g�̃_���[�W����
				(*ite)->Delete(g);		// (*ite) �͍U���I�u�W�F�N�g
				_Life--;
				_Action_Cnt = _Cnt;
				_State = PLAYERSTATE::DAMAGE;
			}
		}
	}
}
/*----------�ړ�----------*/
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
	//�G�̍U���̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�͓G�̍U���I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK || (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK)
		{
			// �v���C���[�Ƃ��̍U���̓����蔻����s��
			if (IsHit(*(*ite)) == true && _Star_Flag == false)
			{
				// �v���C���[�̏�ԑJ�ڂƍU���I�u�W�F�N�g�̃_���[�W����
				(*ite)->Delete(g);		// (*ite) �͍U���I�u�W�F�N�g
				_Life--;
				_Action_Cnt = _Cnt;
				_State = PLAYERSTATE::DAMAGE;
			}
		}
	}
}
/*----------���i�U��----------*/
void Player::MidAttack(Game& g) {

	if (_Cnt - _Action_Cnt == MABegin_Frame) {
		//���i�U������I�u�W�F�N�g�̐���
		MiddleAttackCollision* MAC = new MiddleAttackCollision();
		if (_isFlip == false) {
			// ���i�U������I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
			MAC->SetPosition(_x + _hit_x - MAC->GetW(), _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɒ��i�U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(MAC);
		};
		if (_isFlip == true) {
			// ���i�U������I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
			MAC->SetPosition(_x - _hit_x, _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɒ��i�U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(MAC);
		}
	}
	if (_Cnt - _Action_Cnt == MiddleAttack_Frame) {
		_State = PLAYERSTATE::IDLE;
	}
	//�G�̍U���̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�͓G�̍U���I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK || (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK)
		{
			// �v���C���[�Ƃ��̍U���̓����蔻����s��
			if (IsHit(*(*ite)) == true && _Star_Flag == false)
			{
				// �v���C���[�̏�ԑJ�ڂƍU���I�u�W�F�N�g�̃_���[�W����
				(*ite)->Delete(g);		// (*ite) �͍U���I�u�W�F�N�g
				_Life--;
				_Action_Cnt = _Cnt;
				_State = PLAYERSTATE::DAMAGE;
			}
		}
	}
}
/*----------���i�U��----------*/
void Player::LowAttack(Game& g) {
	//���i�U������I�u�W�F�N�g�̐���
	if (_Cnt - _Action_Cnt == LABegin_Frame) {
		LowAttackCollision* LAC = new LowAttackCollision();
		if (_isFlip == false) {
			// ���i�U������I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
			LAC->SetPosition(_x + _hit_x - LAC->GetW(), _y - LAC->GetH());
			// �I�u�W�F�N�g�T�[�o-�ɉ��i�U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(LAC);
		};
		if (_isFlip == true) {
			// ���i�U������I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
			LAC->SetPosition(_x - _hit_x, _y - LAC->GetH());
			// �I�u�W�F�N�g�T�[�o-�ɉ��i�U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(LAC);
		}
	}
	if (_Cnt - _Action_Cnt == LowAttack_Frame) {
		_State = PLAYERSTATE::IDLE;
	}
	//�G�̍U���̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�͓G�̍U���I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK || (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK)
		{
			// �v���C���[�Ƃ��̍U���̓����蔻����s��
			if (IsHit(*(*ite)) == true && _Star_Flag == false)
			{
				// �v���C���[�̏�ԑJ�ڂƍU���I�u�W�F�N�g�̃_���[�W����
				(*ite)->Delete(g);		// (*ite) �͍U���I�u�W�F�N�g
				_Life--;
				_Action_Cnt = _Cnt;
				_State = PLAYERSTATE::DAMAGE;
			}
		}
	}
}

/*----------�R��----------*/
void Player::Kick(Game& g) {
	//�R�蔻��I�u�W�F�N�g�̐���
	if (_Cnt - _Action_Cnt == KIBegin_Frame) {
		KickCollision* KIC = new KickCollision();
		if (_isFlip == false) {
			// �R�蔻��I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
			KIC->SetPosition(_x + _hit_x - KIC->GetW(), _y - _hit_h / 2);
			// �I�u�W�F�N�g�T�[�o-�ɏR�蔻��I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(KIC);
		};
		if (_isFlip == true) {
			// �R�蔻��I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
			KIC->SetPosition(_x - _hit_x, _y - _hit_h / 2);
			// �I�u�W�F�N�g�T�[�o-�ɏR�蔻��I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(KIC);
		}
	}
	if (_Cnt - _Action_Cnt == Kick_Frame) {
		_State = PLAYERSTATE::IDLE;
	}
	//�G�̍U���̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�͓G�̍U���I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::BUSHIATTACK || (*ite)->GetObjType() == OBJECTTYPE::NINJAATTACK)
		{
			// �v���C���[�Ƃ��̍U���̓����蔻����s��
			if (IsHit(*(*ite)) == true && _Star_Flag == false)
			{
				// �v���C���[�̏�ԑJ�ڂƍU���I�u�W�F�N�g�̃_���[�W����
				(*ite)->Delete(g);		// (*ite) �͍U���I�u�W�F�N�g
				_Life--;
				_Action_Cnt = _Cnt;
				_State = PLAYERSTATE::DAMAGE;
			}
		}
	}

}

/*----------����----------*/
//void Player::Iai(Game& g) {
//	if (_Cnt - _Action_Cnt == Iai_Frame) {
//
//	}
//}
///*----------�X�E�F�C----------*/
//void Player::Sway(Game& g){
//}

/*----------��_��----------*/
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

/*----------���S----------*/
void Player::Dead(Game& g) {
	if (_Cnt - _Action_Cnt == Dead_Frame) {
		Delete(g);
	}
}