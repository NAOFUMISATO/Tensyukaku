#include <DxLib.h>
#include "EnemyBase.h"
#include "Bushi.h"
#include "Game.h"
#include "BushiMotionCollision.h"
#include "ObjectBase.h"
using namespace Tsk;
using namespace BInfo;
void Bushi::Patrol(Game& g) {
	if (_Cnt - _Action_Cnt == Patrol_Frame) {
		_isFlip = true;
	}
	if (_Cnt - _Action_Cnt == Patrol_Frame + Patrol_Frame) {
		_isFlip = false;
		_Action_Cnt = _Cnt;
	}
	if (_isFlip == false) {
		//���m�̍��G�͈͔���I�u�W�F�N�g�̐���
		BushiPatrolCollision BPC;

		// ���m�̍��G�͈͔���I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
		BPC.SetPosition(_x + _hit_x - BPC.GetW(), _y - _hit_h);
		BPC.GetHitW();
		BPC.GetHitH();
		//���G�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{

				// ���G�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(BPC) == true)
				{
					_State = Bushi::ENEMYSTATE::COMING;
				}
			}
		}
	}
	if (_isFlip == true) {
		//���m�̍��G�͈͔���I�u�W�F�N�g�̐���
		BushiPatrolCollision BPC;
		// ���m�̍��G�͈͔���I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
		BPC.SetPosition(_x - _hit_x, _y - _hit_h);
		BPC.GetHitW();
		BPC.GetHitH();
		BPC.Draw(g);
		//���G�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{

				// ���G�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(BPC) == true)
				{

					_State = Bushi::ENEMYSTATE::COMING;
				}
			}
		}

	}

}
void Bushi::Coming(Game& g) {
	if (_isFlip == false) {
		_x -= _Spd;
		//���m�̍U�������͈͔���I�u�W�F�N�g�̐���
		BushiComingCollision BCC;

		// ���m�̍U�������͈̓I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
		BCC.SetPosition(_x + _hit_x - BCC.GetW(), _y - _hit_h);
		BCC.GetHitW();
		BCC.GetHitH();
		//�U�������͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{

				// �U�������͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(BCC) == true)
				{
					_Action_Cnt = _Cnt;
					_State = Bushi::ENEMYSTATE::ATTACK;
				}
			}
		}
	}
	if (_isFlip == true) {
		_x += _Spd;
		//���m�̍U�������͈͔���I�u�W�F�N�g�̐���
		BushiComingCollision BCC;
		// ���m�̍U�������͈͔���I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
		BCC.SetPosition(_x - _hit_x, _y - _hit_h);
		BCC.GetHitW();
		BCC.GetHitH();
		BCC.Draw(g);
		//�U�������͈͔���I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{

				// �U�������͈͔���I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(BCC) == true)
				{
					_Action_Cnt = _Cnt;
					_State = Bushi::ENEMYSTATE::ATTACK;
				}
			}
		}
	}
}
void Bushi::Attack(Game& g) {
	if (_Cnt - _Action_Cnt == ABegin_Frame) {
		//���m�̍U������I�u�W�F�N�g�̐���
		BushiAttackCollision* BAC = new BushiAttackCollision();
		if (_isFlip == false) {
			// ���m�̍U������I�u�W�F�N�g�̊J�n�ʒu�𕐎m�ʒu����Z�o
			BAC->SetPosition(_x + _hit_x - BAC->GetW(), _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɕ��m�̍U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(BAC);
		};
		if (_isFlip == true) {
			// ���m�̍U������I�u�W�F�N�g�̊J�n�ʒu�𕐎m�ʒu����Z�o
			BAC->SetPosition(_x - _hit_x, _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɕ��m�̍U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(BAC);
		}
	}
	if (_Cnt - _Action_Cnt == Attack_Frame)
	{
		_State = Bushi::ENEMYSTATE::PATROL;
	}
}