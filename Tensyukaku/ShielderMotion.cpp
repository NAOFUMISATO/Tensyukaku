#include <DxLib.h>
#include "EnemyBase.h"
#include "Shielder.h"
#include "Shield.h"
#include "Game.h"
#include "ShielderMotionCollision.h"
#include "ObjectBase.h"
#include "PrivateCollision.h"

using namespace SInfo;
/*----------�o��----------*/
void Shielder::Appear(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Appear"][_Anime["Appear"]];
	_Anime["Appear"] = (_Cnt / ANIMESPEED_APPEAR) % APPEAR_ANIMEMAX;
	if (frame < APPEAR_ALLFRAME) {
		_Alpha += FADEIN_SPEED;
	}
	if (frame == APPEAR_ALLFRAME) {
		_Alpha = 255;
		_Action_Cnt = _Cnt;
		_State = ENEMYSTATE::PATROL;
	}
}
/*----------����----------*/
void Shielder::Patrol(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Patrol"][_Anime["Patrol"]];
	_Anime["Patrol"] = (_Cnt / ANIMESPEED_PATROL) % PATROL_ANIMEMAX;
	if (frame == PATROL_TURNFRAME) {
		if (_isFlip == false) {
			_isFlip = true;
		}
		else { _isFlip = false; }
	}
	if (frame == PATROL_TURNFRAME * 2) {
		if (_isFlip == false) {
			_isFlip = true;
		}
		else { _isFlip = false; }
		_Action_Cnt = _Cnt;
	}
	if (_isFlip == false) {
		//�����̍��G�͈͔���I�u�W�F�N�g�̐���
		PrivateCollision pc(_x + _hit_x - PATROL_WIDTH, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
		PrivateCollision bpc(_x - _hit_x, _y - _hit_h, PATROL_BACKWIDTH, PATROL_HEIGHT);
		//���G�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// ���G�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(pc) == true)
				{
					_State = ENEMYSTATE::COMING;
				}
				if ((*ite)->IsHit(bpc) == true)
				{
					for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
					{
						// ite�̓v���C���[���H
						if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
						{
							auto ps = (*ite)->GetSpd();
							if (ps > 5) {
								if (_isFlip == false) {
									_isFlip = true;
								}
								else { _isFlip = false; }
								_State = ENEMYSTATE::COMING;
							}
						}
					}
				}
			}
		}
	}
	if (_isFlip == true) {
		//�����̍��G�͈͔���I�u�W�F�N�g�̐���
		PrivateCollision pc(_x - _hit_x, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
		PrivateCollision bpc(_x + _hit_x - PATROL_BACKWIDTH, _y - _hit_h, PATROL_BACKWIDTH, PATROL_HEIGHT);
		//���G�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// ���G�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(pc) == true)
				{
					_State = ENEMYSTATE::COMING;
				}
				 if ((*ite)->IsHit(bpc) == true)
				 {
					 for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
					 {
						 // ite�̓v���C���[���H
						 if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
						 {
							 auto ps = (*ite)->GetSpd();
							 if (ps > 5) {
								 if (_isFlip == false) {
									 _isFlip = true;
								 }
								 else { _isFlip = false; }
								 _State = ENEMYSTATE::COMING;
							 }
						 }
					 }
				}
			}
		}
	}
}
/*----------�ǐ�----------*/
void Shielder::Coming(Game& g) {
	_GrHandle = _GrAll["Coming"][_Anime["Coming"]];
	_Anime["Coming"] = (_Cnt / ANIMESPEED_COMING) % COMING_ANIMEMAX;
	if (_isFlip == false) {
		_x -= _Spd;
		g.GetChip()->IsHit(*this, -1, 0);
		//�����̍U�������͈͔���I�u�W�F�N�g�̐���
		PrivateCollision cc(_x + _hit_x - COMING_WIDTH, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
		//�U�������͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{

				// �U�������͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(cc) == true)
				{
					_Action_Cnt = _Cnt;
					if (_ShieldAlive_Flag == false) {
						_State = ENEMYSTATE::ATTACK;
					}
					else {
						_State = ENEMYSTATE::GUARDATTACK;
					}
				}
			}
		}
		//�����̒ǐՒ��~�͈͔���I�u�W�F�N�g�̐���
		PrivateCollision ccc(_x + _hit_x - COMINGCANCEL_WIDTH, _y - _hit_h, COMINGCANCEL_WIDTH, COMINGCANCEL_HEIGHT);
		//�ǐՒ��~�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// �ǐՒ��~�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(ccc) == false)
				{
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::PATROL;
					_Anime["Coming"] = 0;
				}
			}
		}
	}
	if (_isFlip == true) {
		_x += _Spd;
		g.GetChip()->IsHit(*this, 1, 0);
		//�����̍U�������͈͔���I�u�W�F�N�g�̐���
		PrivateCollision cc(_x - _hit_x, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
		//�U�������͈͔���I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// �U�������͈͔���I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(cc) == true)
				{
					_Action_Cnt = _Cnt;
					_Anime["Coming"] = 0;
					if (_ShieldAlive_Flag == false) {
						_State = ENEMYSTATE::ATTACK;
					}
					else {
						_State = ENEMYSTATE::GUARDATTACK;
					}
				}
			}
		}
		//�����̒ǐՒ��~�͈͔���I�u�W�F�N�g�̐���
		PrivateCollision ccc(_x - _hit_x, _y - _hit_h, COMINGCANCEL_WIDTH, COMINGCANCEL_HEIGHT);
		//�ǐՒ��~�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// �U�����~�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(ccc) == false)
				{
					_Action_Cnt = _Cnt;
					_State = ENEMYSTATE::PATROL;
				}
			}
		}
	}
}
/*----------�U��----------*/
void Shielder::Attack(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Attack"][_Anime["Attack"]];
	if (frame<ATTACK_ANIMEFRAME){
		_Anime["Attack"] = ((frame) / ANIMESPEED_ATTACK) % ATTACK_ANIMEMAX; 
	}
	if (_isFlip == false) {
		if (frame == STEP_BEGINFRAME) {
			_x -= ATTACK_STEP;
		}
		PrivateCollision acc(_x + _hit_x - ATTACKCANCEL_WIDTH, _y - _hit_h, ATTACKCANCEL_WIDTH, ATTACKCANCEL_HEIGHT);
		if (frame == ATTACK_ANIMEFRAME || frame == ATTACK_ALLFRAME) {
			//�U�����~�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// ite�̓v���C���[���H
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// �U�����~�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
					if ((*ite)->IsHit(acc) == false)
					{
						_Anime["Attack"] = 0;
						_State = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
	if (_isFlip == true) {
		if (frame == STEP_BEGINFRAME) {
			_x += ATTACK_STEP;
		}
		PrivateCollision acc(_x - _hit_x, _y - _hit_h, ATTACKCANCEL_WIDTH, ATTACKCANCEL_HEIGHT);
		if (frame == ATTACK_ANIMEFRAME || frame == ATTACK_ALLFRAME) {
			//�U�����~�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// ite�̓v���C���[���H
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// �U�����~�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
					if ((*ite)->IsHit(acc) == false)
					{
						_Anime["Attack"] = 0;
						_State = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
	if (frame == ATTACK_BEGINFRAME) {
		if (_isFlip == false) {
			//�����̍U������I�u�W�F�N�g�̐���
			auto sac = new ShielderAttackCollision(_x + _hit_x - ATTACK_WIDTH, _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɏ����̍U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(sac);

		};
		if (_isFlip == true) {
			//�����̍U������I�u�W�F�N�g�̐���
			auto sac = new ShielderAttackCollision(_x - _hit_x, _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɏ����̍U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(sac);
		}
	}
	if (frame == ATTACK_ALLFRAME) {
		_Action_Cnt = _Cnt;
	}
}

/*---------�������U��----------*/
void Shielder::GuardAttack(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["GuardAttack"][_Anime["GuardAttack"]];
	if (frame < ATTACK_ANIMEFRAME) {
		_Anime["GuardAttack"] = ((frame) / ANIMESPEED_GUARDATTACK) % GUARDATTACK_ANIMEMAX;
	}
	if (_isFlip == false) {
		if (frame == STEP_BEGINFRAME) {
			_x -=ATTACK_STEP;
		}
		PrivateCollision acc(_x + _hit_x - ATTACKCANCEL_WIDTH, _y - _hit_h, ATTACKCANCEL_WIDTH, ATTACKCANCEL_HEIGHT);
		if (frame == GUARDATTACK_ANIMEFRAME || frame == GUARDATTACK_ALLFRAME) {
			//�U�����~�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// ite�̓v���C���[���H
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// �U�����~�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
					if ((*ite)->IsHit(acc) == false)
					{
						_Anime["GuardAttack"] = 0;
						_State = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
	if (_isFlip == true) {
		if (frame == STEP_BEGINFRAME) {
			_x += ATTACK_STEP;
		}
		PrivateCollision acc(_x - _hit_x, _y - _hit_h, ATTACKCANCEL_WIDTH, ATTACKCANCEL_HEIGHT);
		if (frame == GUARDATTACK_ANIMEFRAME || frame == GUARDATTACK_ALLFRAME) {
			//�U�����~�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// ite�̓v���C���[���H
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// �U�����~�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
					if ((*ite)->IsHit(acc) == false)
					{
						_Anime["GuardAttack"] = 0;
						_State = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
	if (frame == ATTACK_BEGINFRAME) {
		_ShieldAttack_Flag = true;
		_Shield_Cnt=_Cnt;
		if (_isFlip == false) {
			//�����̍U������I�u�W�F�N�g�̐���
			auto sac = new ShielderAttackCollision(_x + _hit_x - ATTACK_WIDTH, _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɏ����̍U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(sac);

		};
		if (_isFlip == true) {
			//�����̍U������I�u�W�F�N�g�̐���
			auto sac = new ShielderAttackCollision(_x - _hit_x, _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɏ����̍U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(sac);
		}
	}
	if (frame == GUARDATTACK_ALLFRAME) {
		_ShieldAttack_Flag = false;
		_Action_Cnt = _Cnt;
	}
}
/*----------������----------*/
void Shielder::GuardBreak(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle =_GrAll["GuardBreak"][_Anime["GuardBreak"]];
	if (frame < GUARDBREAK_ANIMEFRAME) {
		_Anime["GuardBreak"] = ((frame) / ANIMESPEED_GUARDBREAK) % GUARDBREAK_ANIMEMAX;
	}
	if (frame == GUARDBREAK_ALLFRAME) {
	_Action_Cnt = _Cnt;
	_State = ENEMYSTATE::COMING;
	}
}
/*----------���S----------*/
void Shielder::Dead(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle =_GrAll["Dead"][_Anime["Dead"]];
	_hit_x = 10000;
	if (frame < DEAD_ANIMEFRAME) {
		_Anime["Dead"] = ((frame) / ANIMESPEED_DEAD) % DEAD_ANIMEMAX;
	}
	if (frame >= DEAD_ANIMEFRAME && DEAD_ALLFRAME > frame) {
		_Alpha -= FADEOUT_SPEED;
	}
	if (frame == DEAD_ALLFRAME) {
		Delete(g);
	}
}