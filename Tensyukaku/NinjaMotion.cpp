#include <DxLib.h>
#include "EnemyBase.h"
#include "Ninja.h"
#include "Game.h"
#include "NinjaMotionCollision.h"
#include "ObjectBase.h"
#include "PrivateCollision.h"
#include "Kunai.h"

using namespace NInfo;
/*----------�o��----------*/
void Ninja::Appear(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Appear"][_Anime["Appear"]];
	_Anime["Appear"] = (_Cnt / ANIMESPEED_APPEAR) % APPEAR_ANIMEMAX;
	if (frame < APPEAR_ALLFRAME) {
		_Alpha += FADEIN_SPEED;
	}
	if (frame == APPEAR_ALLFRAME) {
		_Alpha = 255;
		_State = ENEMYSTATE::PATROL;
	}
}
/*----------����---------*/
void Ninja::Patrol(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Patrol"][_Anime["Patrol"]];
	_Anime["Patrol"] = (_Cnt / ANIMESPEED_PATROL) % PATROL_ANIMEMAX;
	if (frame == PATROL_TURNFRAME) {
		_isFlip = true;
	}
	if (frame == PATROL_TURNFRAME * 2) {
		_isFlip = false;
		_Action_Cnt = _Cnt;
	}
	if (_isFlip == false) {
		//�E�҂̍��G�͈͔���I�u�W�F�N�g�̐���
		PrivateCollision npc(_x + _hit_x - PATROL_WIDTH, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
		//���G�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// ���G�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(npc) == true)
				{
					_Action_Cnt = _Cnt;
					if (_Kunai_Stock > 0) {
						_State = ENEMYSTATE::THROW;
					}
					else {
						_State = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}

	if (_isFlip == true) {
		//�E�҂̍��G�͈͔���I�u�W�F�N�g�̐���
		PrivateCollision npc(_x - _hit_x, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
		//���G�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// ���G�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(npc) == true)
				{
					_Action_Cnt = _Cnt;
					if (_Kunai_Stock > 0) {
						_State = ENEMYSTATE::THROW;
					}
					else {
						_State = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
	//�G�ƃv���C���[�A�N�V�����̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		OBJECTTYPE objType = (*ite)->GetObjType();
		switch (objType) {
		case ObjectBase::OBJECTTYPE::LOWATTACK:
			// �G�ƃv���C���[�̉��i�U���I�u�W�F�N�g�̓����蔻����s��
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) �͍U���I�u�W�F�N�g
				_Life--;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
				//�����Q�[�W�̑���
				for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
				{
					// ite�̓v���C���[���H
					if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
					{
						auto ig = (*ite)->GetGauge();
						if (ig < PLAYER_IAI_MAX) {
							(*ite)->SetGauge(ig += 1);
						}
					}
				}
			}
			break;
		case ObjectBase::OBJECTTYPE::IAI:
		case ObjectBase::OBJECTTYPE::FLAME:
			// �G�ƃv���C���[�̋����I�u�W�F�N�g�̓����蔻����s��
			if (IsHit(*(*ite)) == true)
			{
				_Life--;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
			break;
		default:
			break;
		}
	}
}
/*----------�ǐ�----------*/
void Ninja::Coming(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Coming"][_Anime["Coming"]];
	if (frame < COMING_ALLFRAME) {
		_Anime["Coming"] = ((frame) / ANIMESPEED_COMING) % COMING_ANIMEMAX;
	}
	if (frame >COMINGSPEED_UPFRAME && COMINGSPEED_DOWNFRAME >= frame) {
		_Spd = COMING_UPSPEED;
	}
	else {
		_Spd =SPEED;
	}
	if (_isFlip == false) {
	
		_x -= _Spd;
		g.GetChip()->IsHit(*this, -1, 0);
		//�E�҂̍U�������͈͔���I�u�W�F�N�g�̐���
		PrivateCollision ncc(_x + _hit_x - COMING_WIDTH, _y - _hit_h,COMING_WIDTH,COMING_HEIGHT);
		//�U�������͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// �U�������͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(ncc) == true)
				{
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::ATTACK;
					_Anime["Coming"] = 0;
				}
			}
		}
		//�E�҂̒ǐՒ��~�͈͔���I�u�W�F�N�g�̐���
		PrivateCollision nccc(_x + _hit_x - COMINGCANCEL_WIDTH, _y - _hit_h, COMINGCANCEL_WIDTH, COMINGCANCEL_HEIGHT);
		//�ǐՒ��~�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// �ǐՒ��~�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(nccc) == false)
				{
					_Action_Cnt=_Cnt;
					_State = ENEMYSTATE::PATROL;
					_Anime["Coming"] = 0;
				}
			}
		}
	}
	if (_isFlip == true) {
		_x += _Spd;
		g.GetChip()->IsHit(*this, 1, 0);
		//�E�҂̍U�������͈͔���I�u�W�F�N�g�̐���
		PrivateCollision ncc(_x - _hit_x, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
		//�U�������͈͔���I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// �U�������͈͔���I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(ncc) == true)
				{
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::ATTACK;
					_Anime["Coming"] = 0;
				}
			}
		}
		//�E�҂̒ǐՒ��~�͈͔���I�u�W�F�N�g�̐���
		PrivateCollision nccc(_x - _hit_x, _y - _hit_h, COMINGCANCEL_WIDTH, COMINGCANCEL_HEIGHT);
		//�ǐՒ��~�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// �U�����~�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(nccc) == false)
				{
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::PATROL;
					_Anime["Coming"] = 0;
				}
			}
		}
	}
	//�G�ƃv���C���[�A�N�V�����̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		OBJECTTYPE objType = (*ite)->GetObjType();
		switch (objType) {
		case ObjectBase::OBJECTTYPE::LOWATTACK:
			// �G�ƃv���C���[�̉��i�U���I�u�W�F�N�g�̓����蔻����s��
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) �͍U���I�u�W�F�N�g
				_Life--;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
				//�����Q�[�W�̑���
				for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
				{
					// ite�̓v���C���[���H
					if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
					{
						auto ig = (*ite)->GetGauge();
						if (ig < PLAYER_IAI_MAX) {
							(*ite)->SetGauge(ig += 1);
						}
					}
				}
			}
			break;
		case ObjectBase::OBJECTTYPE::IAI:
		case ObjectBase::OBJECTTYPE::FLAME:
			// �G�ƃv���C���[�̋����I�u�W�F�N�g�̓����蔻����s��
			if (IsHit(*(*ite)) == true)
			{
				_Life--;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
			break;
		default:
			break;
		}
	}
	if (frame == COMING_ALLFRAME) {
		_Action_Cnt = _Cnt;
		_Anime["Coming"] = 0;
	}
}
/*--------------�U��---------------*/
void Ninja::Attack(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Attack"][_Anime["Attack"]];
	if (frame < ATTACK_ANIMEFRAME) {
		_Anime["Attack"] = ((frame) / ANIMESPEED_ATTACK) % ATTACK_ANIMEMAX;
	}
	if (_isFlip == false) {
		PrivateCollision nacc(_x + _hit_x - ATTACKCANCEL_WIDTH, _y - _hit_h, ATTACKCANCEL_WIDTH, ATTACKCANCEL_HEIGHT);
		if (frame == ATTACK_ANIMEFRAME || frame == ATTACK_ALLFRAME) {
			//�U�����~�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// ite�̓v���C���[���H
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// �U�����~�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
					if ((*ite)->IsHit(nacc) == false)
					{
						_Action_Cnt = _Cnt;
						_Anime["Attack"] = 0;
						_State = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
	if (_isFlip == true) {
		PrivateCollision nacc(_x - _hit_x, _y - _hit_h, ATTACKCANCEL_WIDTH, ATTACKCANCEL_HEIGHT);
		if (frame == ATTACK_ANIMEFRAME || frame == ATTACK_ALLFRAME) {
			//�U�����~�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// ite�̓v���C���[���H
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// �U�����~�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
					if ((*ite)->IsHit(nacc) == false)
					{
						_Action_Cnt = _Cnt;
						_Anime["Attack"] = 0;
						_State = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
	if (frame == ATTACK_BEGINFRAME) {
		
		if (_isFlip == false) {
			//�E�҂̍U������I�u�W�F�N�g�̐���
			auto nac = new NinjaAttackCollision(_x + _hit_x - ATTACK_WIDTH, _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɔE�҂̍U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(nac);
		};
		if (_isFlip == true) {
			//�E�҂̍U������I�u�W�F�N�g�̐���
			auto nac = new NinjaAttackCollision(_x - _hit_x, _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɔE�҂̍U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(nac);
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
				//�����Q�[�W�̑���
				for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
				{
					// ite�̓v���C�����H
					if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
					{
						auto ig = (*ite)->GetGauge();
						if (ig < PLAYER_IAI_MAX) {
							(*ite)->SetGauge(ig += 1);
						}
					}
				}
			}
		}
	}
	//�G�ƃv���C���[�̋����I�u�W�F�N�g�̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�̓v���C���[�̋����I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::IAI || (*ite)->GetObjType() == OBJECTTYPE::FLAME)
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
	if (frame == ATTACK_ALLFRAME) {
		_Action_Cnt = _Cnt;
	}
}
/*---------�N�i�C����--------*/
void Ninja::Throw(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Attack"][_Anime["Attack"]];
	if (frame < THROW_ANIMEFRAME) {
		_Anime["Attack"] = ((frame) / ANIMESPEED_THROW) % THROW_ANIMEMAX;
	}
	if (_isFlip == false) {
		PrivateCollision nacc(_x + _hit_x - THROWCANCEL_WIDTH, _y - _hit_h, THROWCANCEL_WIDTH, THROWCANCEL_HEIGHT);
		if (frame == THROW_ANIMEFRAME || frame == THROW_ALLFRAME) {
			if (_Kunai_Stock <= 0) {
				_Action_Cnt = _Cnt;
				_Anime["Attack"] = 0;
				_State = ENEMYSTATE::COMING;
			}
			//�U�����~�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// ite�̓v���C���[���H
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// �U�����~�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
					if ((*ite)->IsHit(nacc) == false)
					{
						_Action_Cnt = _Cnt;
						_Anime["Attack"] = 0;
						_State = ENEMYSTATE::PATROL;
					}
				}
			}
		}
	}
	if (_isFlip == true) {
		PrivateCollision nacc(_x - _hit_x, _y - _hit_h, THROWCANCEL_WIDTH, THROWCANCEL_HEIGHT);
		if (frame == THROW_ANIMEFRAME || frame == THROW_ALLFRAME) {
			if (_Kunai_Stock <= 0) {
				_Anime["Attack"] = 0;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::COMING;
			}
			//�U�����~�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// ite�̓v���C���[���H
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// �U�����~�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
					if ((*ite)->IsHit(nacc) == false)
					{
						_Action_Cnt = _Cnt;
						_Anime["Attack"] = 0;
						_State = ENEMYSTATE::PATROL;
					}
				}
			}
		}
	}
	if (frame == KUNAI_RELEASEFRAME) {
		_Kunai_Stock--;
		if (_isFlip == false) {
			//�N�i�C�I�u�W�F�N�g�̐���
			auto ku = new Kunai(_x -110, _y -130,false);
			// �I�u�W�F�N�g�T�[�o-�ɃN�i�C�I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(ku);
		};
		if (_isFlip == true) {
			//�N�i�C�I�u�W�F�N�g�̐���
			auto ku = new Kunai(_x + 110, _y - 130, true);
			// �I�u�W�F�N�g�T�[�o-�ɃN�i�C�I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(ku);

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
				//�����Q�[�W�̑���
				for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
				{
					// ite�̓v���C�����H
					if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
					{
						auto ig = (*ite)->GetGauge();
						if (ig < PLAYER_IAI_MAX) {
							(*ite)->SetGauge(ig += 1);
						}
					}
				}
			}
		}
	}
	//�G�ƃv���C���[�̋����I�u�W�F�N�g�̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�̓v���C���[�̋����I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::IAI || (*ite)->GetObjType() == OBJECTTYPE::FLAME)
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
	if (frame == THROW_ALLFRAME) {
		_Action_Cnt = _Cnt;
	}


}
/*---------���S----------*/
void Ninja::Dead(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Dead"][_Anime["Dead"]];
	_hit_x = 10000;
	if (frame < DEAD_ANIMEFRAME) {
		_Anime["Dead"] = ((frame) / ANIMESPEED_DEAD) % DEAD_ANIMEMAX;
	}
	if (frame >= DEAD_ANIMEFRAME && DEAD_ALLFRAME > frame) {
		_Alpha -= FADEOUT_SPEED;
	}
	if (frame == DEAD_ALLFRAME)
	{
		Delete(g);
	}
}