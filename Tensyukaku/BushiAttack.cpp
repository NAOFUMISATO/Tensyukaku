#include <DxLib.h>
#include "EnemyBase.h"
#include "Bushi.h"
#include "Game.h"
#include "BushiAttackCollision.h"
#include "ObjectBase.h"
using namespace Tsk;
using namespace BInfo;
void Bushi::Attack(Game& g) {
	if (_Cnt - _Action_Cnt == ABegin_Frame) {
		//���i�U������I�u�W�F�N�g�̐���
		BushiAttackCollision* BAC = new BushiAttackCollision();
		if (_isFlip == false) {
			// �U������I�u�W�F�N�g�̊J�n�ʒu�𕐎m�ʒu����Z�o
			BAC->SetPosition(_x + _hit_x - BAC->GetW(), _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɒ��i�U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(BAC);
		};
		if (_isFlip == true) {
			// �U������I�u�W�F�N�g�̊J�n�ʒu�𕐎m�ʒu����Z�o
			BAC->SetPosition(_x - _hit_x, _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɒ��i�U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(BAC);
		}
	}
	if (_Cnt - _Action_Cnt == Attack_Frame)
	{
		_State = Bushi::ENEMYSTATE::PATROL;
	}
}