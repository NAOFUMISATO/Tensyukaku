#include <DxLib.h>
#include "EnemyBase.h"
#include "Ninja.h"
#include "Game.h"
#include "NinjaMotionCollision.h"
#include "ObjectBase.h"

using namespace NInfo;
void Ninja::Patrol(Game& g) {
	_GrHandle = _Patrol_GrAll[_Patrol_AnimeNo];
	if (_Cnt - _Action_Cnt == Patrol_Frame) {
		_isFlip = true;
	}
	if (_Cnt - _Action_Cnt == Patrol_Frame + Patrol_Frame) {
		_isFlip = false;
		_Action_Cnt = _Cnt;
	}
	if (_isFlip == false) {
		//�E�҂̍��G�͈͔���I�u�W�F�N�g�̐���
		NinjaPatrolCollision NPC;

		// �E�҂̍��G�͈͔���I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
		NPC.SetPosition(_x + _hit_x - NPC.GetW(), _y - _hit_h);
		NPC.GetHitW();
		NPC.GetHitH();
		//���G�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// ���G�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(NPC) == true)
				{
					_State = ENEMYSTATE::COMING;
				}
			}
		}
	}

	if (_isFlip == true) {
		//���m�̍��G�͈͔���I�u�W�F�N�g�̐���
		NinjaPatrolCollision NPC;
		// ���m�̍��G�͈͔���I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
		NPC.SetPosition(_x - _hit_x, _y - _hit_h);
		NPC.GetHitW();
		NPC.GetHitH();
		NPC.Draw(g);
		//���G�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{

				// ���G�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(NPC) == true)
				{

					_State = ENEMYSTATE::COMING;
				}
			}
		}
	}
	//�G�ƃv���C���[�̉��i�U���I�u�W�F�N�g�̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�̓v���C���[�̉��i�U���I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::LOWATTACK)
		{

			// �G�ƃv���C���[�̉��i�U���I�u�W�F�N�g�̓����蔻����s��
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) �͍U���I�u�W�F�N�g
				_Life--;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
	//�G�ƃv���C���[�̋����I�u�W�F�N�g�̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�̓v���C���[�̋����I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::IAI)
		{

			// �G�ƃv���C���[�̋����I�u�W�F�N�g�̓����蔻����s��
			if (IsHit(*(*ite)) == true)
			{
				_Life--;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
}
void Ninja::Coming(Game& g) {
	_GrHandle = _Coming_GrAll[_Coming_AnimeNo];
	if (_isFlip == false) {
		_x -= _Spd;
		//���m�̍U�������͈͔���I�u�W�F�N�g�̐���
		NinjaComingCollision NCC;

		// ���m�̍U�������͈̓I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
		NCC.SetPosition(_x + _hit_x - NCC.GetW(), _y - _hit_h);
		NCC.GetHitW();
		NCC.GetHitH();
		//�U�������͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{

				// �U�������͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(NCC) == true)
				{
					_Action_Cnt = _Cnt;
					_State = Ninja::ENEMYSTATE::ATTACK;
				}
			}
		}
	}
	if (_isFlip == true) {
		_x += _Spd;
		//���m�̍U�������͈͔���I�u�W�F�N�g�̐���
		NinjaComingCollision NCC;
		// ���m�̍U�������͈͔���I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
		NCC.SetPosition(_x - _hit_x, _y - _hit_h);
		NCC.GetHitW();
		NCC.GetHitH();
		NCC.Draw(g);
		//�U�������͈͔���I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// �U�������͈͔���I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(NCC) == true)
				{
					_Action_Cnt = _Cnt;
					_State = Ninja::ENEMYSTATE::ATTACK;
				}
			}
		}
	}
	//�G�ƃv���C���[�̉��i�U���I�u�W�F�N�g�̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�̓v���C���[�̉��i�U���I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::LOWATTACK)
		{

			// �G�ƃv���C���[�̉��i�U���I�u�W�F�N�g�̓����蔻����s��
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) �͍U���I�u�W�F�N�g
				_Life--;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
	//�G�ƃv���C���[�̋����I�u�W�F�N�g�̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�̓v���C���[�̋����I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::IAI)
		{

			// �G�ƃv���C���[�̋����I�u�W�F�N�g�̓����蔻����s��
			if (IsHit(*(*ite)) == true)
			{
				_Life--;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
}

void Ninja::Attack(Game& g) {
	_GrHandle = _Attack_GrAll[_Attack_AnimeNo];
	if (_Cnt - _Action_Cnt == ABegin_Frame) {
		//���m�̍U������I�u�W�F�N�g�̐���
		NinjaAttackCollision* NAC = new NinjaAttackCollision();
		if (_isFlip == false) {
			// ���m�̍U������I�u�W�F�N�g�̊J�n�ʒu�𕐎m�ʒu����Z�o
			NAC->SetPosition(_x + _hit_x - NAC->GetW(), _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɕ��m�̍U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(NAC);
		};
		if (_isFlip == true) {
			// ���m�̍U������I�u�W�F�N�g�̊J�n�ʒu�𕐎m�ʒu����Z�o
			NAC->SetPosition(_x - _hit_x, _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɕ��m�̍U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(NAC);
		}
	}
	if (_Cnt - _Action_Cnt == Attack_Frame)
	{
		_State = Ninja::ENEMYSTATE::PATROL;
	}
	//�G�ƃv���C���[�̉��i�U���I�u�W�F�N�g�̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�̓v���C���[�̉��i�U���I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::LOWATTACK)
		{

			// �G�ƃv���C���[�̉��i�U���I�u�W�F�N�g�̓����蔻����s��
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) �͍U���I�u�W�F�N�g
				_Life--;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
	//�G�ƃv���C���[�̋����I�u�W�F�N�g�̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�̓v���C���[�̋����I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::IAI)
		{

			// �G�ƃv���C���[�̋����I�u�W�F�N�g�̓����蔻����s��
			if (IsHit(*(*ite)) == true)
			{
				_Life--;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
}

void Ninja::Dead(Game& g) {
	_GrHandle = _Dead_GrAll[_Dead_AnimeNo];
	if (_Cnt - _Action_Cnt == Dead_Frame)
	{
		Delete(g);
	}
}

