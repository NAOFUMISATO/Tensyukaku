#include <DxLib.h>
#include "EnemyBase.h"
#include "Bushi.h"
#include "Game.h"
#include "BushiPatrolCollision.h"
using namespace Tsk;
using namespace BInfo;
void Bushi::Patrol(Game& g) {
	if(_Patrol_Flag==false){
		_Patrol_Flag = true;
		//���m�̍��G�͈͔���I�u�W�F�N�g�̐���
		BushiPatrolCollision* BPC = new BushiPatrolCollision();
		// ���m�̍��G�͈͔���I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
		BPC->SetPosition(_x + _hit_x - BPC->GetW(), _y - _hit_h);
		// �I�u�W�F�N�g�T�[�o-�ɕ��m�̍��G�͈͔���I�u�W�F�N�g��ǉ�
		g.GetOS()->Add(BPC);
	}
	if (_Cnt - _Action_Cnt == Patrol_Frame) {
		_isFlip = true;
		//���m�̍��G�͈͔���I�u�W�F�N�g�̐���
		BushiPatrolCollision* BPC = new BushiPatrolCollision();
		// ���m�̍��G�͈͔���I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
		BPC->SetPosition(_x - _hit_x, _y - _hit_h);
		// �I�u�W�F�N�g�T�[�o-�ɕ��m�̍��G�͈͔���I�u�W�F�N�g��ǉ�
		g.GetOS()->Add(BPC);
		//���G�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// ���G�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if (IsHitCO(*BPC) == true)
				{
					BPC->Damage(g);
					ENEMYSTATE::COMING;
				}
			}
		}
	
	}
	if (_Cnt - _Action_Cnt == Patrol_Frame+Patrol_Frame) {
		_isFlip = false;
		//���m�̍��G�͈͔���I�u�W�F�N�g�̐���
		BushiPatrolCollision* BPC = new BushiPatrolCollision();
		// ���m�̍��G�͈͔���I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
		BPC->SetPosition(_x + _hit_x - BPC->GetW(), _y - _hit_h);
		// �I�u�W�F�N�g�T�[�o-�ɕ��m�̍��G�͈͔���I�u�W�F�N�g��ǉ�
		g.GetOS()->Add(BPC);
		//���G�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// ���G�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if (IsHitCC(*BPC) == true)
				{
					BPC->Damage(g);
					ENEMYSTATE::COMING;
				}
			}
		}
		_Action_Cnt = _Cnt;
	}
	
}

