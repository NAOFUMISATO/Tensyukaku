#include <DxLib.h>
#include "EnemyBase.h"
#include "Bushi.h"
#include "Game.h"
#include "BushiMotionCollision.h"
#include "ObjectBase.h"
#include <tuple>
#include <utility>

using namespace BInfo;

/*----------����----------*/
void Bushi::Patrol(Game& g) {
	_GrHandle = _GrAll["Patrol"][_Anime["Patrol"]];
	auto frame = _Cnt - _Action_Cnt;
	if (frame == PATROL_FRAME) {
		_isFlip = true;
	}
	if (frame == PATROL_FRAME *2) {
		_isFlip = false;
		_Action_Cnt = _Cnt;
	}
	if (_isFlip == false) {
		//���m�̍��G�͈͔���I�u�W�F�N�g�̐���
		BushiPatrolCollision bpc(_x + _hit_x - PATROL_WIDTH, _y - _hit_h);
		//���G�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// ���G�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(bpc) == true)
				{
					_State = ENEMYSTATE::COMING;
				}
			}
		}
	}
	if (_isFlip == true) {
		//���m�̍��G�͈͔���I�u�W�F�N�g�̐���
		BushiPatrolCollision bpc(_x - _hit_x, _y - _hit_h);
		//���G�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// ���G�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(bpc) == true)
				{
					_State = ENEMYSTATE::COMING;
				}
			}
		}

	}
	//�G�ƃv���C���[�̒��i�U���I�u�W�F�N�g�̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�̓v���C���[�̒��i�U���I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::MIDDLEATTACK)
		{
			// �G�ƃv���C���[�̒��i�U���I�u�W�F�N�g�̓����蔻����s��
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) �͍U���I�u�W�F�N�g
				_Life = 0;
				_Action_Cnt = _Cnt;
				_State =ENEMYSTATE::DAMAGE;
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
				_State =ENEMYSTATE::DAMAGE;
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
				_Life -= 3;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
}
/*----------�ǐ�----------*/
void Bushi::Coming(Game& g) {
	_GrHandle = _GrAll["Coming"][_Anime["Coming"]];
	if (_isFlip == false) {
		_x -= _Spd;
		//���m�̍U�������͈͔���I�u�W�F�N�g�̐���
		BushiComingCollision bcc(_x + _hit_x - COMING_WIDTH, _y - _hit_h);
		//�U�������͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// �U�������͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(bcc) == true)
				{
					_Action_Cnt = _Cnt;
					_State =ENEMYSTATE::ATTACK;
				}
			}
		}
	}
	if (_isFlip == true) {
		_x += _Spd;
		//���m�̍U�������͈͔���I�u�W�F�N�g�̐���
		BushiComingCollision bcc(_x - _hit_x, _y - _hit_h);
		//�U�������͈͔���I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{

				// �U�������͈͔���I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(bcc) == true)
				{
					_Action_Cnt = _Cnt;
					_State =ENEMYSTATE::ATTACK;
				}
			}
		}
	}
	//�G�ƃv���C���[�̒��i�U���I�u�W�F�N�g�̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�̓v���C���[�̒��i�U���I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::MIDDLEATTACK)
		{
			// �G�ƃv���C���[�̒��i�U���I�u�W�F�N�g�̓����蔻����s��
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) �͍U���I�u�W�F�N�g
				_Life -= 3;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DAMAGE;
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
				_State = ENEMYSTATE::DAMAGE;
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
				_Life -= 3;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
}
/*----------�U��----------*/
void Bushi::Attack(Game& g) {
	_GrHandle = _GrAll["Attack"][_Anime["Attack"]];
	if (_Cnt - _Action_Cnt == ATTACK_BEGINFRAME) {
		if (_isFlip == false) {
			//���m�̍U������I�u�W�F�N�g�̐���
			auto bac = new BushiAttackCollision(_x + _hit_x - ATTACK_WIDTH, _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɕ��m�̍U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(bac);
		};
		if (_isFlip == true) {
			//���m�̍U������I�u�W�F�N�g�̐���
			auto bac = new BushiAttackCollision(_x - _hit_x, _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɕ��m�̍U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(bac);
		}
	}
	if (_Cnt - _Action_Cnt == ATTACK_ALLFRAME)
	{
		_State =ENEMYSTATE::PATROL;
	}
	//�G�ƃv���C���[�̒��i�U���I�u�W�F�N�g�̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�̓v���C���[�̒��i�U���I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::MIDDLEATTACK)
		{
			// �G�ƃv���C���[�̒��i�U���I�u�W�F�N�g�̓����蔻����s��
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) �͍U���I�u�W�F�N�g
				_Life -= 3;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DAMAGE;
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
				_State = ENEMYSTATE::DAMAGE;
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
				_Life -= 3;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
}
/*----------��_��----------*/
void Bushi::Damage(Game& g) {
	_GrHandle = _GrAll["Damage"][_Anime["Damage"]];
	auto frame = _Cnt - _Action_Cnt;
	if (frame == DAMAGE_ALLFRAME) {
		if (_Life <= 0) {
			_Action_Cnt = _Cnt;
			_State = ENEMYSTATE::DEAD;
		}
		else {
			_Action_Cnt = _Cnt;
			_State = ENEMYSTATE::PATROL;
		}
	}
}
/*----------���S----------*/
void Bushi::Dead(Game& g) {
	_GrHandle = _GrAll["Dead"][_Anime["Dead"]];
	auto frame = _Cnt - _Action_Cnt;
	if (frame == DEAD_ALLFRAME) {
		Delete(g);
	}
}