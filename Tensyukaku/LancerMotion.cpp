#include <DxLib.h>
#include "Lancer.h"
#include "Game.h"
#include "LancerMotionCollision.h"
#include "EnemyParticle.h"
#include "PrivateCollision.h"

using namespace EPInfo;
using namespace LInfo;
/*----------�o��----------*/
void Lancer::Appear(Game& g) {
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
/*----------����----------*/
void Lancer::Patrol(Game& g) {
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
				//�O�����G�͈̓I�u�W�F�N�g�ƃv���C���[�����������Ȃ�ǐՏ�Ԃֈڍs
				if ((*ite)->IsHit(pc) == true) {
					_state = ENEMYSTATE::COMING;
				}
				//������G�͈̓I�u�W�F�N�g�ɓ������Ă��銎�A�v���C���[�̑��������ȏ�Ȃ�U��Ԃ�ǐՏ�Ԃֈڍs
				if ((*ite)->IsHit(bpc) == true) {
					auto ps = (*ite)->GetSpd();
					if (ps > 5) {
						if (_isflip == false) {
							_isflip = true;
						}
						else { _isflip = false; }
						_action_cnt = _cnt;
						_state = ENEMYSTATE::COMING;
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
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER) {
				//�O�����G�͈̓I�u�W�F�N�g�ƃv���C���[�����������Ȃ�ǐՏ�Ԃֈڍs
				if ((*ite)->IsHit(pc) == true) {
					_state = ENEMYSTATE::COMING;
				}
				//������G�͈̓I�u�W�F�N�g�ɓ������Ă��銎�A�v���C���[�̑��������ȏ�Ȃ�U��Ԃ�ǐՏ�Ԃֈڍs
				if ((*ite)->IsHit(bpc) == true) {
					auto ps = (*ite)->GetSpd();
					if (ps > 5) {
						if (_isflip == false) {
							_isflip = true;
						}
						else { _isflip = false; }
						_state = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
}
/*----------�ǐ�----------*/
void Lancer::Coming(Game& g) {
	_grhandle = _grall["Coming"][_anime["Coming"]];
	_anime["Coming"] = (_cnt / ANIMESPEED_COMING) % COMING_ANIMEMAX;
	if (_isflip == false) {
		_x -= _spd;
		g.GetChip()->IsHit(*this, -1, 0);
		//�U�������͈͔���I�u�W�F�N�g�̐���
		PrivateCollision ac(_x + _hit_x - COMING_WIDTH, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
		//�U�������͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++){
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER){
				// �U�������͈̓I�u�W�F�N�g�ƃv���C���[������������U����Ԃֈڍs
				if ((*ite)->IsHit(ac) == true){
					_action_cnt = _cnt;
					_state = ENEMYSTATE::ATTACK;
				}
			}
		}
		//�ǐՒ��~�͈͔���I�u�W�F�N�g�̐���
		PrivateCollision ccc(_x + _hit_x - COMINGCANCEL_WIDTH, _y - _hit_h, COMINGCANCEL_WIDTH, COMINGCANCEL_HEIGHT);
		//�ǐՒ��~�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++){
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER){
				// �ǐՒ��~�͈̓I�u�W�F�N�g�ƃv���C���[��������Ȃ��Ȃ�������G��ԂɈڍs
				if ((*ite)->IsHit(ccc) == false){
					_action_cnt;
					_state = ENEMYSTATE::PATROL;
				}
			}
		}
	}
	if (_isflip == true) {
		_x += _spd;
		g.GetChip()->IsHit(*this, 1, 0);
		//�U�������͈͔���I�u�W�F�N�g�̐���
		PrivateCollision ac(_x - _hit_x, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
		//�U�������͈͔���I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++){
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER){
				// �U�������͈͔���I�u�W�F�N�g�ƃv���C���[��������Ȃ��Ȃ�������G��ԂɈڍs
				if ((*ite)->IsHit(ac) == true){
					_action_cnt = _cnt;
					_state = ENEMYSTATE::ATTACK;
				}
			}
		}
		//�ǐՒ��~�͈͔���I�u�W�F�N�g�̐���
		PrivateCollision ccc(_x - _hit_x, _y - _hit_h, COMINGCANCEL_WIDTH, COMINGCANCEL_HEIGHT);
		//�ǐՒ��~�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++){
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER){
				// �ǐՒ��~�͈̓I�u�W�F�N�g�ƃv���C���[��������Ȃ��Ȃ�������G��ԂɈڍs
				if ((*ite)->IsHit(ccc) == false){
					_action_cnt = _cnt;
					_state = ENEMYSTATE::PATROL;
				}
			}
		}
	}
}
/*----------�U��----------*/
void Lancer::Attack(Game& g) {
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Attack"][_anime["Attack"]];
	//�A�j���t���[���ȉ��Ȃ�A�j���[�V��������
	if (frame < ATTACK_ANIMEFRAME) {
		_anime["Attack"] = ((frame) / ANIMESPEED_ATTACK) % ATTACK_ANIMEMAX;
	}
	//�U���\������p�[�e�B�N��
	if (_isflip == false) {
		if (frame == 1) {
			for (int i = 0; i < LRESERVELIGHT_PARTICLE_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % LRESERVELIGHT_PARTICLE_RANDOMX1) - LRESERVELIGHT_PARTICLE_RANDOMX2) / LRESERVELIGHT_PARTICLE_RANDOMX3, ((rand() % -LRESERVELIGHT_PARTICLE_RANDOMY1) - LRESERVELIGHT_PARTICLE_RANDOMY2) / LRESERVELIGHT_PARTICLE_RANDOMY3);
				auto rl = new LanceReserveLight(xy, dxy, true);
				g.GetOS()->Add(rl);
			}
		}
		if (frame == STEP_BEGINFRAME) {
			_x -= ATTACK_STEP;
		}
		//�U�����~�͈̓I�u�W�F�N�g�̐���
		PrivateCollision acc(_x + _hit_x - ATTACKCANCEL_WIDTH, _y - _hit_h, ATTACKCANCEL_WIDTH, ATTACKCANCEL_HEIGHT);
		if (frame == ATTACK_ANIMEFRAME || frame == ATTACK_ALLFRAME) {
			//�U�����~�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++){
				// ite�̓v���C���[���H
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER){
					// �U�����~�͈̓I�u�W�F�N�g�ƃv���C���[��������Ȃ��Ȃ�����ǐՏ�Ԃֈڍs
					if ((*ite)->IsHit(acc) == false){
						_anime["Attack"] = 0;
						_state = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
	//�U���\������p�[�e�B�N��
	if (_isflip == true) {
		if (frame == 1) {
			for (int i = 0; i < LRESERVELIGHT_PARTICLE_QTY; i++)
			{
				std::pair<int, int> xy = std::make_pair(_x, _y);
				std::pair<double, double> dxy = std::make_pair(((rand() % LRESERVELIGHT_PARTICLE_RANDOMX1) - LRESERVELIGHT_PARTICLE_RANDOMX2) / LRESERVELIGHT_PARTICLE_RANDOMX3, ((rand() % -LRESERVELIGHT_PARTICLE_RANDOMY1) - LRESERVELIGHT_PARTICLE_RANDOMY2) / LRESERVELIGHT_PARTICLE_RANDOMY3);
				auto rl = new LanceReserveLight(xy, dxy, false);
				g.GetOS()->Add(rl);
			}
		}
		if (frame == STEP_BEGINFRAME) {
			_x += ATTACK_STEP;
		}
		//�U�����~�͈̓I�u�W�F�N�g�̐���
		PrivateCollision acc(_x - _hit_x, _y - _hit_h, ATTACKCANCEL_WIDTH, ATTACKCANCEL_HEIGHT);
		if (frame == ATTACK_ANIMEFRAME || frame == ATTACK_ALLFRAME) {
			//�U�����~�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++){
				// ite�̓v���C���[���H
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER){
					// �U�����~�͈̓I�u�W�F�N�g�ƃv���C���[��������Ȃ��Ȃ�����ǐՏ�Ԃֈڍs
					if ((*ite)->IsHit(acc) == false){
						_anime["Attack"] = 0;
						_state = ENEMYSTATE::COMING;
					}
				}
			}
		}
	}
	if (frame == ATTACK_BEGINFRAME) {
		//SE
		PlaySoundMem(_se["Attack"], DX_PLAYTYPE_BACK, true);
		if (_isflip == false) {
			//�U������I�u�W�F�N�g�̐���
			auto ac = new LancerAttackCollision(_x + _hit_x - ATTACK_WIDTH, _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɏ����̍U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(ac);
		}
		if (_isflip == true) {
			//�U������I�u�W�F�N�g�̐���
			auto ac = new LancerAttackCollision(_x - _hit_x, _y - _hit_h);
			// �I�u�W�F�N�g�T�[�o-�ɏ����̍U������I�u�W�F�N�g��ǉ�
			g.GetOS()->Add(ac);
		}
	}
	if (frame == ATTACK_ALLFRAME) {
		_action_cnt = _cnt;
	}
}
/*----------���S----------*/
void Lancer::Dead(Game& g) {
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Dead"][_anime["Dead"]];
	//�����蔻����폜����
	_hit_x = 10000;
	if (frame < DEAD_ANIMEFRAME) {
		_anime["Dead"] = ((frame) / ANIMESPEED_DEAD) % DEAD_ANIMEMAX;
	}
	//�A�j���t���[���ȏォ�S�t���[���ȉ��Ȃ�t�F�[�h�A�E�g���Ă���
	if (frame >= DEAD_ANIMEFRAME && DEAD_ALLFRAME > frame) {
		_alpha -= FADEOUT_SPEED;
	}
	//�S�t���[���o�����Ȃ炱�̃I�u�W�F�N�g���폜����
	if (frame == DEAD_ALLFRAME) {
		Delete(g);
	}
}