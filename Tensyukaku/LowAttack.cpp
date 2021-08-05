#include <DxLib.h>
#include "Player.h"
#include "Game.h"
#include "LowAttackCollision.h"
using namespace Tsk;
using namespace PInfo;
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