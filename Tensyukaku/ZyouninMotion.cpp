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
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Appear"][_anime["Appear"]];
	_anime["Appear"] = (_cnt / ANIMESPEED_APPEAR) % APPEAR_ANIMEMAX;
	if (frame < APPEAR_ALLFRAME) {
		_alpha += FADEIN_SPEED;
	}
	//�S�t���[���o�����Ȃ瓧���x��MAX�ɂ��āA���G��Ԃֈڍs
	if (frame == APPEAR_ALLFRAME) {
		_alpha = 255;
		_action_cnt = _cnt;
		_state = ENEMYSTATE::PATROL;
	}
}
/*----------����---------*/
void Zyounin::Patrol(Game& g) {
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Patrol"][_anime["Patrol"]];
	_anime["Patrol"] = (_cnt / ANIMESPEED_PATROL) % PATROL_ANIMEMAX;
	//��莞�Ԃ��ƂɐU��Ԃ鏈��
	if (frame == PATROL_TURNFRAME) {
		if (_isflip == false) {
			_isflip = true;
		}
		else { _isflip = false; }
	}
	if (frame == PATROL_TURNFRAME * 2) {
		if (_isflip == false) {
			_isflip = true;
		}
		else { _isflip = false; }
		_action_cnt = _cnt;
	}
	if (_isflip == false) {
		//�O�����G�͈͔���I�u�W�F�N�g�̐���
		PrivateCollision pc(_x + _hit_x - PATROL_WIDTH, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
		//������G�͈͔���I�u�W�F�N�g�̐���
		PrivateCollision bpc(_x - _hit_x, _y - _hit_h, PATROL_BACKWIDTH, PATROL_HEIGHT);
		//���G�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++) {
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER) {
				//�O�����G�͈̓I�u�W�F�N�g�ƃv���C���[�����������ꍇ�A�N�i�C��0�Ȃ�ǐՏ�Ԃֈڍs�A�����łȂ��Ȃ�N�i�C������Ԃֈڍs
				if ((*ite)->IsHit(pc) == true)
				{
					_action_cnt = _cnt;
					if (_kunai_stock > 0) {
						_state = ENEMYSTATE::THROW;
					}
					else {
						_state = ENEMYSTATE::COMING;
					}
				}
				//������G�͈̓I�u�W�F�N�g�ɓ������Ă��銎�A�v���C���[�̑��������ȏ�Ȃ�U��Ԃ�A�N�i�C��0�Ȃ�ǐՏ�Ԃֈڍs�A�����łȂ��Ȃ�N�i�C������Ԃֈڍs
				if ((*ite)->IsHit(bpc) == true) {
					auto ps = (*ite)->GetSpd();
					if (ps > 5) {
						if (_isflip == false) {
							_isflip = true;
						}
						else { _isflip = false; }
						if (_kunai_stock > 0) {
							_state = ENEMYSTATE::THROW;
						}
						else {
							_state = ENEMYSTATE::COMING;
						}
					}
				}
			}
		}
	}
	if (_isflip == true) {
		//�O�����G�͈͔���I�u�W�F�N�g�̐���
		PrivateCollision pc(_x - _hit_x, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
		//������G�͈͔���I�u�W�F�N�g�̐���
		PrivateCollision bpc(_x + _hit_x - PATROL_BACKWIDTH, _y - _hit_h, PATROL_BACKWIDTH, PATROL_HEIGHT);
		//���G�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++) {
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER) {
				//�O�����G�͈̓I�u�W�F�N�g�ƃv���C���[�����������ꍇ�A�N�i�C��0�Ȃ�ǐՏ�Ԃֈڍs�A�����łȂ��Ȃ�N�i�C������Ԃֈڍs
				if ((*ite)->IsHit(pc) == true) {
					_action_cnt = _cnt;
					if (_kunai_stock > 0) {
						_state = ENEMYSTATE::THROW;
					}
					else {
						_state = ENEMYSTATE::COMING;
					}
				}
				//������G�͈̓I�u�W�F�N�g�ɓ������Ă��銎�A�v���C���[�̑��������ȏ�Ȃ�U��Ԃ�A�N�i�C��0�Ȃ�ǐՏ�Ԃֈڍs�A�����łȂ��Ȃ�N�i�C������Ԃֈڍs
				if ((*ite)->IsHit(bpc) == true) {
					auto ps = (*ite)->GetSpd();
					if (ps > 5) {
						if (_isflip == false) {
							_isflip = true;
						}
						else { _isflip = false; }
						_action_cnt = _cnt;
						if (_kunai_stock > 0) {
							_state = ENEMYSTATE::THROW;
						}
						else {
							_state = ENEMYSTATE::COMING;
						}
					}
				}
			}
		}
	}
}
/*----------�ǐ�----------*/
void Zyounin::Coming(Game& g) {
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Coming"][_anime["Coming"]];
	if (frame < COMING_ALLFRAME) {
		_anime["Coming"] = ((frame) / ANIMESPEED_COMING) % COMING_ANIMEMAX;
	}
	if (frame > COMINGSPEED_UPFRAME && COMINGSPEED_DOWNFRAME >= frame) {
		_spd = COMING_UPSPEED;
	}
	else {
		_spd = SPEED;
	}
	if (_isflip == false) {

		_x -= _spd;
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
					_action_cnt = _cnt;
					_state = ENEMYSTATE::ATTACK;
					_anime["Coming"] = 0;
				}
			}
		}
		//�ǐՒ��~�͈͔���I�u�W�F�N�g�̐���
		PrivateCollision ccc(_x + _hit_x - COMINGCANCEL_WIDTH, _y - _hit_h, COMINGCANCEL_WIDTH, COMINGCANCEL_HEIGHT);
		//�ǐՒ��~�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER){
				// �ǐՒ��~�͈̓I�u�W�F�N�g�ƃv���C���[��������Ȃ��Ȃ�������G��ԂɈڍs
				if ((*ite)->IsHit(ccc) == false)
				{
					_action_cnt = _cnt;
					_state = ENEMYSTATE::PATROL;
					_anime["Coming"] = 0;
				}
			}
		}
	}
	if (_isflip == true) {
		_x += _spd;
		g.GetChip()->IsHit(*this, 1, 0);
		//�U�������͈͔���I�u�W�F�N�g�̐���
		PrivateCollision cc(_x - _hit_x, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
		//�U�������͈͔���I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// �U�������͈͔���I�u�W�F�N�g�ƃv���C���[��������Ȃ��Ȃ�������G��ԂɈڍs
				if ((*ite)->IsHit(cc) == true)
				{
					_action_cnt = _cnt;
					_state = ENEMYSTATE::ATTACK;
					_anime["Coming"] = 0;
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
					_action_cnt = _cnt;
					_state = ENEMYSTATE::PATROL;
					_anime["Coming"] = 0;
				}
			}
		}
	}
	if (frame == COMING_ALLFRAME) {
		_action_cnt = _cnt;
		_anime["Coming"] = 0;
	}
}
/*--------------�U��---------------*/
void Zyounin::Attack(Game& g) {
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Attack"][_anime["Attack"]];
	if (frame < ATTACK_ANIMEFRAME) {
		_anime["Attack"] = ((frame) / ANIMESPEED_ATTACK) % ATTACK_ANIMEMAX;
	}
	if (_isflip == false) {
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
						_action_cnt = _cnt;
						_anime["Attack"] = 0;
						_state = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
	if (_isflip == true) {
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
						_action_cnt = _cnt;
						_anime["Attack"] = 0;
						_state = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
	if (frame == ATTACK_BEGINFRAME) {
		PlaySoundMem(_se["Attack"], DX_PLAYTYPE_BACK, true);
		if (_isflip == false) {
			//�U������I�u�W�F�N�g�̐���
			auto nac = new ZyouninAttackCollision(_x + _hit_x - ATTACK_WIDTH, _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɔE�҂̍U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(nac);
		};
		if (_isflip == true) {
			//�U������I�u�W�F�N�g�̐���
			auto nac = new ZyouninAttackCollision(_x - _hit_x, _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɔE�҂̍U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(nac);
		}
	}
	if (frame == ATTACK_ALLFRAME) {
		_action_cnt = _cnt;
	}
}
/*---------�N�i�C����--------*/
void Zyounin::Throw(Game& g) {
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Throw"][_anime["Throw"]];
	if (frame < THROW_ANIMEFRAME) {
		_anime["Throw"] = ((frame) / ANIMESPEED_THROW) % THROW_ANIMEMAX;
	}
	if (_isflip == false) {
		PrivateCollision acc(_x + _hit_x - THROWCANCEL_WIDTH, _y - _hit_h, THROWCANCEL_WIDTH, THROWCANCEL_HEIGHT);
		if (frame == THROW_ANIMEFRAME|| frame == THROW_ALLFRAME) {
			if (_kunai_stock <= 0) {
				_action_cnt = _cnt;
				_anime["Throw"] = 0;
				_state = ENEMYSTATE::COMING;
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
						_action_cnt = _cnt;
						_anime["Throw"] = 0;
						_state = ENEMYSTATE::PATROL;
					}
				}
			}
		}
	}
	if (_isflip == true) {
		PrivateCollision acc(_x - _hit_x, _y - _hit_h, THROWCANCEL_WIDTH, THROWCANCEL_HEIGHT);
		if (frame == THROW_ANIMEFRAME || frame == THROW_ALLFRAME) {
			if (_kunai_stock <= 0) {
				_anime["Throw"] = 0;
				_action_cnt = _cnt;
				_state = ENEMYSTATE::COMING;
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
						_action_cnt = _cnt;
						_anime["Throw"] = 0;
						_state = ENEMYSTATE::PATROL;
					}
				}
			}
		}
	}
	if (frame == KUNAI_RELEASEFRAME) {
		_kunai_stock--;
		PlaySoundMem(_se["Kunai"], DX_PLAYTYPE_BACK, true);
		if (_isflip == false) {
			//�N�i�C�I�u�W�F�N�g�̐���
			auto ku = new Kunai(_x - 110, _y - 130, false,KUNAI_SPEED);
			// �I�u�W�F�N�g�T�[�o-�ɃN�i�C�I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(ku);
		};
		if (_isflip == true) {
			//�N�i�C�I�u�W�F�N�g�̐���
			auto ku = new Kunai(_x + 110, _y - 130, true, KUNAI_SPEED);
			// �I�u�W�F�N�g�T�[�o-�ɃN�i�C�I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(ku);

		}
	}
	if (frame == KUNAI_RELEASE2FRAME) {
		_kunai_stock--;
		PlaySoundMem(_se["Kunai"], DX_PLAYTYPE_BACK, true);
		if (_isflip == false) {
			//�N�i�C�I�u�W�F�N�g�̐���
			auto ku = new Kunai(_x - 110, _y - 130, false, KUNAI_SPEED);
			// �I�u�W�F�N�g�T�[�o-�ɃN�i�C�I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(ku);
		};
		if (_isflip == true) {
			//�N�i�C�I�u�W�F�N�g�̐���
			auto ku = new Kunai(_x + 110, _y - 130, true, KUNAI_SPEED);
			// �I�u�W�F�N�g�T�[�o-�ɃN�i�C�I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(ku);

		}
	}
	if (frame == THROW_ALLFRAME) {
		_action_cnt = _cnt;
	}


}
/*---------���S----------*/
void Zyounin::Dead(Game& g) {
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Dead"][_anime["Dead"]];
	_hit_x = 10000;
	if (frame < DEAD_ANIMEFRAME) {
		_anime["Dead"] = ((frame) / ANIMESPEED_DEAD) % DEAD_ANIMEMAX;
	}
	if (frame >= DEAD_ANIMEFRAME && DEAD_ALLFRAME > frame) {
		_alpha -= FADEOUT_SPEED;
	}
	if (frame == DEAD_ALLFRAME)
	{
		Delete(g);
	}
}