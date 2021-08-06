#include <DxLib.h>
#include "Player.h"
#include "Game.h"
#include "PlayerMotionCollision.h"
using namespace Tsk;
using namespace PInfo;
void Player::Idle(Game& g) {
	if (g.GetKey() & PAD_INPUT_LEFT || g.GetKey() & PAD_INPUT_RIGHT) {
		_Action = PLAYERACTION::MOVE;
	}
	if (g.GetTrg() & PAD_INPUT_X) {
		_Action = PLAYERACTION::MIDDLEATTACK;
		_Action_Cnt = _Cnt;
		PlaySoundMem(_MiddleAttack_SEHandle, DX_PLAYTYPE_BACK, true);
	}
	if (g.GetTrg() & PAD_INPUT_Z) {
		_Action = PLAYERACTION::LOWATTACK;
		_Action_Cnt = _Cnt;
		PlaySoundMem(_LowAttack_SEHandle, DX_PLAYTYPE_BACK, true);
	}
	_MiddleAttack_AnimeNo = 0;
	_LowAttack_AnimeNo = 0;
}

void Player::Move(Game& g) {
	if (g.GetTrg() & PAD_INPUT_X) {
		_Action = PLAYERACTION::MIDDLEATTACK;
		_Action_Cnt = _Cnt;
		PlaySoundMem(_MiddleAttack_SEHandle, DX_PLAYTYPE_BACK, true);
	}
	else if (g.GetTrg() & PAD_INPUT_Z) {
		_Action = PLAYERACTION::LOWATTACK;
		_Action_Cnt = _Cnt;
		PlaySoundMem(_LowAttack_SEHandle, DX_PLAYTYPE_BACK, true);
	}
	else if (g.GetKey() & PAD_INPUT_LEFT)
	{
		_x -= _Spd;
		/*g.GetChips().IsHit(*this, -1, 0);*/
		_isFlip = false;

	}
	else if (g.GetKey() & PAD_INPUT_RIGHT)
	{
		_x += _Spd;
		/*g.GetChips().IsHit(*this, 1, 0);*/
		_isFlip = true;

	}
	else {
		_Action = PLAYERACTION::IDLE;
	}
}

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
		_Action = PLAYERACTION::IDLE;
	}
}

void Player::LowAttack(Game& g) {
	//���i�U������I�u�W�F�N�g�̐���
	if (_Cnt - _Action_Cnt == LABegin_Frame) {
		LowAttackCollision* LAC = new LowAttackCollision();
		if (_isFlip == false) {
			// ���i�U������I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
			LAC->SetPosition(_x + _hit_x - LAC->GetW(), _y - LAC->GetH());
			// �I�u�W�F�N�g�T�[�o-�ɒ��i�U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(LAC);
		};
		if (_isFlip == true) {
			// ���i�U������I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
			LAC->SetPosition(_x - _hit_x, _y - LAC->GetH());
			// �I�u�W�F�N�g�T�[�o-�ɒ��i�U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(LAC);
		}
	}
	if (_Cnt - _Action_Cnt == MiddleAttack_Frame) {
		_Action = PLAYERACTION::IDLE;
	}
}
