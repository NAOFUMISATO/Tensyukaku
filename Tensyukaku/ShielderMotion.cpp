#include <DxLib.h>
#include "Shielder.h"
#include "Shield.h"
#include "Game.h"
#include "ShielderAttackCollision.h"
#include "PrivateCollision.h"
#include "EnemyParticle.h"

using namespace EPInfo;
using namespace SInfo;
/*----------�o��----------*/
void Shielder::Appear(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["Appear"][_anime["Appear"]];
   _anime["Appear"] = (_cnt / ANIMESPEED_APPEAR) % APPEAR_ANIMEMAX;
   if (frame < APPEAR_ALLFRAME) {
      _alpha += FADEIN_SPEED;
   }
   if (frame == APPEAR_ALLFRAME) {
      _alpha = 255;
      _action_cnt = _cnt;
      _state = ENEMYSTATE::PATROL;
   }
}
/*----------����----------*/
void Shielder::Patrol(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["Patrol"][_anime["Patrol"]];
   _anime["Patrol"] = (_cnt / ANIMESPEED_PATROL) % PATROL_ANIMEMAX;
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
               _state = ENEMYSTATE::COMING;
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
   }
   if (_isflip == true) {
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
               _state = ENEMYSTATE::COMING;
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
   }
}
/*----------�ǐ�----------*/
void Shielder::Coming(Game& g) {
   _grhandle = _grall["Coming"][_anime["Coming"]];
   _anime["Coming"] = (_cnt / ANIMESPEED_COMING) % COMING_ANIMEMAX;
   if (_isflip == false) {
      _x -= _spd;
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
               _action_cnt = _cnt;
               if (_ShieldAlive_Flag == false) {
                  _state = ENEMYSTATE::ATTACK;
               }
               else {
                  _state = ENEMYSTATE::GUARDATTACK;
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
               _action_cnt = _cnt;
               _anime["Coming"] = 0;
               if (_ShieldAlive_Flag == false) {
                  _state = ENEMYSTATE::ATTACK;
               }
               else {
                  _state = ENEMYSTATE::GUARDATTACK;
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
               _action_cnt = _cnt;
               _state = ENEMYSTATE::PATROL;
            }
         }
      }
   }
}
/*----------�U��----------*/
void Shielder::Attack(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["Attack"][_anime["Attack"]];
   if (frame<ATTACK_ANIMEFRAME){
      _anime["Attack"] = ((frame) / ANIMESPEED_ATTACK) % ATTACK_ANIMEMAX; 
   }
   if (_isflip == false) {
      if(frame==1){
         for (int i = 0; i < LRESERVELIGHT_PARTICLE_QTY; i++)
         {
            std::pair<int, int> xy = std::make_pair(_x, _y);
            std::pair<double, double> dxy = std::make_pair(((rand() % LRESERVELIGHT_PARTICLE_RANDOMX1) - LRESERVELIGHT_PARTICLE_RANDOMX2) / LRESERVELIGHT_PARTICLE_RANDOMX3, ((rand() % -LRESERVELIGHT_PARTICLE_RANDOMY1) - LRESERVELIGHT_PARTICLE_RANDOMY2) / LRESERVELIGHT_PARTICLE_RANDOMY3);
            auto rl = new LanceReserveLight(xy, dxy, true);
            g.GetOS()->Add(rl);
         }
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
                  _anime["Attack"] = 0;
                  _state = ENEMYSTATE::COMING;
               }
            }
         }
      }
   }
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
         _x -= ATTACK_STEP;
         //�����̍U������I�u�W�F�N�g�̐���
         auto sac = new ShielderAttackCollision(_x + _hit_x - ATTACK_WIDTH, _y - _hit_h);
         // �I�u�W�F�N�g�T�[�o-�ɏ����̍U������I�u�W�F�N�g��ǉ�
         g.GetOS()->Add(sac);

      };
      if (_isflip == true) {
         _x += ATTACK_STEP;
         //�����̍U������I�u�W�F�N�g�̐���
         auto sac = new ShielderAttackCollision(_x - _hit_x, _y - _hit_h);
         // �I�u�W�F�N�g�T�[�o-�ɏ����̍U������I�u�W�F�N�g��ǉ�
         g.GetOS()->Add(sac);
      }
   }
   if (frame == ATTACK_ALLFRAME) {
      _action_cnt = _cnt;
   }
}

/*---------�������U��----------*/
void Shielder::GuardAttack(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["GuardAttack"][_anime["GuardAttack"]];
   if (frame < ATTACK_ANIMEFRAME) {
      _anime["GuardAttack"] = ((frame) / ANIMESPEED_GUARDATTACK) % GUARDATTACK_ANIMEMAX;
   }
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
                  _anime["GuardAttack"] = 0;
                  _state = ENEMYSTATE::COMING;
               }
            }
         }
      }
   }
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
                  _anime["GuardAttack"] = 0;
                  _state = ENEMYSTATE::COMING;
               }
            }
         }
      }
   }
   if (frame == 30) {
      _ShieldAttack_Flag = true;
      _Shield_Cnt = _cnt;
   }
   if (frame == ATTACK_BEGINFRAME) {
      
      
      PlaySoundMem(_se["Attack"], DX_PLAYTYPE_BACK, true);
      if (_isflip == false) {
         _x -= ATTACK_STEP;
         //�����̍U������I�u�W�F�N�g�̐���
         auto sac = new ShielderAttackCollision(_x + _hit_x - ATTACK_WIDTH, _y - _hit_h);
         // �I�u�W�F�N�g�T�[�o-�ɏ����̍U������I�u�W�F�N�g��ǉ�
         g.GetOS()->Add(sac);

      };
      if (_isflip == true) {
         _x += ATTACK_STEP;
         //�����̍U������I�u�W�F�N�g�̐���
         auto sac = new ShielderAttackCollision(_x - _hit_x, _y - _hit_h);
         // �I�u�W�F�N�g�T�[�o-�ɏ����̍U������I�u�W�F�N�g��ǉ�
         g.GetOS()->Add(sac);
      }
   }
   if (frame == GUARDATTACK_ALLFRAME) {
      _ShieldAttack_Flag = false;
      _action_cnt = _cnt;
   }
}
/*----------������----------*/
void Shielder::GuardBreak(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle =_grall["GuardBreak"][_anime["GuardBreak"]];
   if (frame < GUARDBREAK_ANIMEFRAME) {
      _anime["GuardBreak"] = ((frame) / ANIMESPEED_GUARDBREAK) % GUARDBREAK_ANIMEMAX;
   }
   if (frame == GUARDBREAK_ALLFRAME) {
   _action_cnt = _cnt;
   _state = ENEMYSTATE::COMING;
   }
}
/*----------���S----------*/
void Shielder::Dead(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle =_grall["Dead"][_anime["Dead"]];
   _hit_x = 10000;
   if (frame < DEAD_ANIMEFRAME) {
      _anime["Dead"] = ((frame) / ANIMESPEED_DEAD) % DEAD_ANIMEMAX;
   }
   if (frame >= DEAD_ANIMEFRAME && DEAD_ALLFRAME > frame) {
      _alpha -= FADEOUT_SPEED;
   }
   if (frame == DEAD_ALLFRAME) {
      Delete(g);
   }
}