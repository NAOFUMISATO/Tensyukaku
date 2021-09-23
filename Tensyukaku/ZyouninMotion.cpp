#include <DxLib.h>
#include "EnemyBase.h"
#include "Zyounin.h"
#include "Game.h"
#include "ZyouninMotionCollision.h"
#include "ObjectBase.h"
#include "PrivateCollision.h"
#include "Kunai.h"

using namespace ZInfo;
/*----------�o��----------*/
void Zyounin::Appear(Game& g) {
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
/*----------����---------*/
void Zyounin::Patrol(Game& g) {
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
		//�E�҂̍��G�͈͔���I�u�W�F�N�g�̐���
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
					_Action_Cnt = _Cnt;
					if (_Kunai_Stock > 0) {
						_State = ENEMYSTATE::THROW;
					}
					else {
						_State = ENEMYSTATE::COMING;
					}
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
		//���G�͈͔���I�u�W�F�N�g�̐���
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
					_Action_Cnt = _Cnt;
					if (_Kunai_Stock > 0) {
						_State = ENEMYSTATE::THROW;
					}
					else {
						_State = ENEMYSTATE::COMING;
					}
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
								_Action_Cnt = _Cnt;
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
void Zyounin::Coming(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Coming"][_Anime["Coming"]];
	if (frame < COMING_ALLFRAME) {
		_Anime["Coming"] = ((frame) / ANIMESPEED_COMING) % COMING_ANIMEMAX;
	}
	if (frame > COMINGSPEED_UPFRAME && COMINGSPEED_DOWNFRAME >= frame) {
		_Spd = COMING_UPSPEED;
	}
	else {
		_Spd = SPEED;
	}
	if (_isFlip == false) {

		_x -= _Spd;
		g.GetChip()->IsHit(*this, -1, 0);
		//�U�������͈͔���I�u�W�F�N�g�̐���
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
					_State = ENEMYSTATE::ATTACK;
					_Anime["Coming"] = 0;
				}
			}
		}
		//�ǐՒ��~�͈͔���I�u�W�F�N�g�̐���
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
		//�U�������͈͔���I�u�W�F�N�g�̐���
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
					_State = ENEMYSTATE::ATTACK;
					_Anime["Coming"] = 0;
				}
			}
		}
		//�ǐՒ��~�͈͔���I�u�W�F�N�g�̐���
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
					_Anime["Coming"] = 0;
				}
			}
		}
	}
	if (frame == COMING_ALLFRAME) {
		_Action_Cnt = _Cnt;
		_Anime["Coming"] = 0;
	}
}
/*--------------�U��---------------*/
void Zyounin::Attack(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Attack"][_Anime["Attack"]];
	if (frame < ATTACK_ANIMEFRAME) {
		_Anime["Attack"] = ((frame) / ANIMESPEED_ATTACK) % ATTACK_ANIMEMAX;
	}
	if (_isFlip == false) {
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
						_Action_Cnt = _Cnt;
						_Anime["Attack"] = 0;
						_State = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
	if (_isFlip == true) {
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
			//�U������I�u�W�F�N�g�̐���
			auto nac = new ZyouninAttackCollision(_x + _hit_x - ATTACK_WIDTH, _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɔE�҂̍U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(nac);
		};
		if (_isFlip == true) {
			//�U������I�u�W�F�N�g�̐���
			auto nac = new ZyouninAttackCollision(_x - _hit_x, _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɔE�҂̍U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(nac);
		}
	}
	if (frame == ATTACK_ALLFRAME) {
		_Action_Cnt = _Cnt;
	}
}
/*---------�N�i�C����--------*/
void Zyounin::Throw(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Throw"][_Anime["Throw"]];
	if (frame < THROW_ANIMEFRAME) {
		_Anime["Throw"] = ((frame) / ANIMESPEED_THROW) % THROW_ANIMEMAX;
	}
	if (_isFlip == false) {
		PrivateCollision acc(_x + _hit_x - THROWCANCEL_WIDTH, _y - _hit_h, THROWCANCEL_WIDTH, THROWCANCEL_HEIGHT);
		if (frame == THROW_ANIMEFRAME|| frame == THROW_ALLFRAME) {
			if (_Kunai_Stock <= 0) {
				_Action_Cnt = _Cnt;
				_Anime["Throw"] = 0;
				_State = ENEMYSTATE::COMING;
			}
			//�U�����~�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// ite�̓v���C���[���H
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// �U�����~�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
					if ((*ite)->IsHit(acc) == false)
					{
						_Action_Cnt = _Cnt;
						_Anime["Throw"] = 0;
						_State = ENEMYSTATE::PATROL;
					}
				}
			}
		}
	}
	if (_isFlip == true) {
		PrivateCollision acc(_x - _hit_x, _y - _hit_h, THROWCANCEL_WIDTH, THROWCANCEL_HEIGHT);
		if (frame == THROW_ANIMEFRAME || frame == THROW_ALLFRAME) {
			if (_Kunai_Stock <= 0) {
				_Anime["Throw"] = 0;
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
					if ((*ite)->IsHit(acc) == false)
					{
						_Action_Cnt = _Cnt;
						_Anime["Throw"] = 0;
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
			auto ku = new Kunai(_x - 110, _y - 130, false,KUNAI_SPEED);
			// �I�u�W�F�N�g�T�[�o-�ɃN�i�C�I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(ku);
		};
		if (_isFlip == true) {
			//�N�i�C�I�u�W�F�N�g�̐���
			auto ku = new Kunai(_x + 110, _y - 130, true, KUNAI_SPEED);
			// �I�u�W�F�N�g�T�[�o-�ɃN�i�C�I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(ku);

		}
	}
	if (frame == KUNAI_RELEASE2FRAME) {
		_Kunai_Stock--;
		if (_isFlip == false) {
			//�N�i�C�I�u�W�F�N�g�̐���
			auto ku = new Kunai(_x - 110, _y - 130, false, KUNAI_SPEED);
			// �I�u�W�F�N�g�T�[�o-�ɃN�i�C�I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(ku);
		};
		if (_isFlip == true) {
			//�N�i�C�I�u�W�F�N�g�̐���
			auto ku = new Kunai(_x + 110, _y - 130, true, KUNAI_SPEED);
			// �I�u�W�F�N�g�T�[�o-�ɃN�i�C�I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(ku);

		}
	}
	if (frame == THROW_ALLFRAME) {
		_Action_Cnt = _Cnt;
	}


}
/*---------���S----------*/
void Zyounin::Dead(Game& g) {
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