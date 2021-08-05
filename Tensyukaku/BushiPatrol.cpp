#include <DxLib.h>
#include "EnemyBase.h"
#include "Bushi.h"
#include "Game.h"
#include "BushiPatrolCollision.h"
using namespace Tsk;
using namespace BInfo;
void Bushi::Patrol(Game& g) {
	if (_Cnt - _Action_Cnt == Patrol_Frame1) {
		_isFlip = true;
		//���m�̍��G�͈͔���I�u�W�F�N�g�̐���
		BushiPatrolCollision* BPC = new BushiPatrolCollision();
		// ���m�̍��G�͈͔���I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
		BPC->SetPosition(_x - _hit_x, _y - _hit_h);
		// �I�u�W�F�N�g�T�[�o-�ɕ��m�̍��G�͈͔���I�u�W�F�N�g��ǉ�
		g.GetOS()->Add(BPC);
	}
	if (_Cnt - _Action_Cnt == Patrol_Frame2) {
		_isFlip = false;
		//���m�̍��G�͈͔���I�u�W�F�N�g�̐���
		BushiPatrolCollision* BPC = new BushiPatrolCollision();
		// ���m�̍��G�͈͔���I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
		BPC->SetPosition(_x + _hit_x - BPC->GetW(), _y - _hit_h);
		// �I�u�W�F�N�g�T�[�o-�ɕ��m�̍��G�͈͔���I�u�W�F�N�g��ǉ�
		g.GetOS()->Add(BPC);
		 _Action_Cnt= _Cnt;
	}

	

	
		
	
}

