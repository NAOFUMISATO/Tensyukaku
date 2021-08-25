#include <DxLib.h>
#include "EnemyBase.h"
#include "Shielder.h"
#include "Shield.h"
#include "Game.h"
#include "ShielderMotionCollision.h"
#include "ObjectBase.h"
#include <tuple>
#include <utility>

using namespace SInfo;

/*----------����----------*/
void Shielder::Patrol(Game& g) {
	_GrHandle = _Patrol_GrAll[_Patrol_AnimeNo];
	if (_Cnt - _Action_Cnt == PATROL_TURNFRAME) {
		_isFlip = true;
	}
	if (_Cnt - _Action_Cnt == PATROL_TURNFRAME + PATROL_TURNFRAME) {
		_isFlip = false;
		_Action_Cnt = _Cnt;
	}
	if (_isFlip == false) {
		//�����̍��G�͈͔���I�u�W�F�N�g�̐���
		ShielderPatrolCollision spc;
		// �����̍��G�͈͔���I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
		spc.SetPosition(_x + _hit_x - spc.GetHitW(), _y - _hit_h);
		//���G�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// ���G�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(spc) == true)
				{
					_State = ENEMYSTATE::COMING;
				}
			}
		}
	}
	if (_isFlip == true) {
		//���m�̍��G�͈͔���I�u�W�F�N�g�̐���
		ShielderPatrolCollision spc;
		// ���m�̍��G�͈͔���I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
		spc.SetPosition(_x - _hit_x, _y - _hit_h);
		//���G�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// ���G�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(spc) == true)
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
				if (_Shield_Flag == false) {
					_Life--;
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::DEAD;
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
				if (_Shield_Flag == false) {
					_Life--;
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::DEAD;
				}
			}
		}
	}
	//�G�ƃv���C���[�̃L�b�N�I�u�W�F�N�g�̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�̓v���C���[�̃L�b�N�I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::KICK)
		{
			// �G�ƃv���C���[�̃L�b�N�I�u�W�F�N�g�̓����蔻����s��
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) �̓L�b�N�I�u�W�F�N�g
				_Shield_Cnt = _Cnt;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::GUARDBREAK;
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
				_Shield_Cnt = _Cnt;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
}
/*----------�ǐ�----------*/
void Shielder::Coming(Game& g) {
	_GrHandle = _Coming_GrAll[_Coming_AnimeNo];
	if (_isFlip == false) {
		_x -= _Spd;
		//�����̍U�������͈͔���I�u�W�F�N�g�̐���
		ShielderComingCollision scc;
		// �����̍U�������͈̓I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
		scc.SetPosition(_x + _hit_x - scc.GetHitW(), _y - _hit_h);
		//�U�������͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{

				// �U�������͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(scc) == true)
				{
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::ATTACK;
				}
			}
		}
	}
	if (_isFlip == true) {
		_x += _Spd;
		//�����̍U�������͈͔���I�u�W�F�N�g�̐���
		ShielderComingCollision scc;
		//�����̍U�������͈͔���I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
		scc.SetPosition(_x - _hit_x, _y - _hit_h);
		//�U�������͈͔���I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// �U�������͈͔���I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(scc) == true)
				{
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::ATTACK;
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
				if (_Shield_Flag == false) {
					_Life--;
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::DEAD;
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
				if (_Shield_Flag == false) {
					_Life--;
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::DEAD;
				}
			}
		}
	}
	//�G�ƃv���C���[�̃L�b�N�I�u�W�F�N�g�̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�̓v���C���[�̃L�b�N�I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::KICK)
		{
			// �G�ƃv���C���[�̃L�b�N�I�u�W�F�N�g�̓����蔻����s��
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) �̓L�b�N�I�u�W�F�N�g
				_Shield_Cnt = _Cnt;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::GUARDBREAK;
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
				_Shield_Cnt = _Cnt;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
}
/*----------�U��----------*/
void Shielder::Attack(Game& g) {
	_GrHandle = _Attack_GrAll[_Attack_AnimeNo];

	/*if (_Cnt - _Action_Cnt <= ATTACK_BEGINFRAME + ATTACK_ENDFRAME+20) {
	_Attack_AnimeNo = ((_Cnt - _Action_Cnt) / ANIMESPEED_ATTACK) % ATTACK_ANIMEMAX; }*/
	if (_Cnt - _Action_Cnt == ATTACK_BEGINFRAME) {
		//�����̍U������I�u�W�F�N�g�̐���
		ShielderAttackCollision* sac = new ShielderAttackCollision();
		if (_isFlip == false) {
			//�����̍U������I�u�W�F�N�g�̊J�n�ʒu�������ʒu����Z�o
			sac->SetPosition(_x + _hit_x - sac->GetHitW(), _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɏ����̍U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(sac);

		};
		if (_isFlip == true) {
			//�����̍U������I�u�W�F�N�g�̊J�n�ʒu�������ʒu����Z�o
			sac->SetPosition(_x - _hit_x, _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɏ����̍U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(sac);

		}
	}
	if (_Cnt - _Action_Cnt == ATTACK_ALLFRAME)
	{
		_State = ENEMYSTATE::PATROL;
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
				if (_Shield_Flag == false) {
					_Life--;
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::DEAD;
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
				if (_Shield_Flag == false) {
					_Life--;
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::DEAD;
				}
			}
		}
	}
	//�G�ƃv���C���[�̃L�b�N�I�u�W�F�N�g�̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�̓v���C���[�̃L�b�N�I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::KICK)
		{
			// �G�ƃv���C���[�̃L�b�N�I�u�W�F�N�g�̓����蔻����s��
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) �̓L�b�N�I�u�W�F�N�g
				_Shield_Cnt = _Cnt;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::GUARDBREAK;
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
				_Shield_Cnt = _Cnt;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
		}
	}
}
/*----------������----------*/
void Shielder::GuardBreak(Game& g) {
	_GrHandle = _GuardBreak_GrAll[_GuardBreak_AnimeNo];
	if (_Cnt - _Action_Cnt == GUARDBREAK_ALLFRAME) {
	_Action_Cnt = _Cnt;
	_State = ENEMYSTATE::PATROL;
	}
}
/*----------���S----------*/
void Shielder::Dead(Game& g) {
	_GrHandle = _Dead_GrAll[_Dead_AnimeNo];
	if (_Cnt - _Action_Cnt == DEAD_ALLFRAME) {
		Delete(g);
	}
}