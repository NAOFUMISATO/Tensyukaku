#include <DxLib.h>
#include "Player.h"
#include "Game.h"
#include "MiddleAttackCollision.h"
using namespace Tsk;
using namespace PInfo;
void Player::MidAttack(Game& g) {
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
	if (_Cnt - _Action_Cnt == MiddleAttack_Frame) {
		MAC->Damage(g);
		_Action = PLAYERACTION::IDLE;
	}
}