/*
   ���m
*/
#include <DxLib.h>
#include <vector>
#include <sstream>
#include "EnemyBase.h"
#include "Bushi.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
#include "MiddleBlood.h"
#include "PrivateCollision.h"

using namespace BInfo;
//���m�̃R���X�g���N�^ : �����iX���W,Y���W,���]����j
Bushi::Bushi(int x,int y,bool flip)
{
   _x = x;
   _y = y;
   _isflip = flip;
   Init();
   LoadPicture();
   LoadSE();
   VolumeInit();
};

Bushi::~Bushi() {
   
};
/*----------������----------*/
void Bushi::Init() {
   _sort = 6;
   _w = GRAPH_WIDTH;
   _h = GRAPH_HEIGHT;
   _gx = GRAPHPOINT_X;
   _gy = GRAPHPOINT_Y;
   _hit_x = POSITION_HITX;
   _hit_y = POSITION_HITY;
   _hit_w = COLLISION_WIDTH;
   _hit_h = COLLISION_HEIGHT;
   _state=ENEMYSTATE::APPEAR;
   _life = LIFE_MAX;
   _spd = SPEED;
   _alpha = 0;
}
/*----------�X�V-----------*/
void Bushi::Process(Game& g) {
   EnemyBase::Process(g);
   //���ʉ��{�����[���ύX
   VolumeChange();
   /*---��Ԗ��̏���---*/
   switch (_state) {
      //�o�����
   case ENEMYSTATE::APPEAR:
      Appear(g);
      break;
      //���G���
   case ENEMYSTATE::PATROL:
      Patrol(g);
      break;
      //�ǐՏ��
   case ENEMYSTATE::COMING:
      Coming(g);
      break;
      //�U�����
   case ENEMYSTATE::ATTACK:
      Attack(g);
      break;
   //��_�����
   case ENEMYSTATE::DAMAGE:
      Damage(g);
      break;
   //���S���
   case ENEMYSTATE::DEAD:
      Dead(g);
      break;
   }
   //�����蔻��̏���
   HitJudge(g);
}
/*----------�`��----------*/
void Bushi::Draw(Game& g) {   
#ifdef _DEBUG
   DebugDraw(g);
#endif
   SetDrawBlendMode(DX_BLENDMODE_ALPHA,_alpha);
   EnemyBase::Draw(g);
}

void Bushi::Delete(Game& g) {
      g.GetOS()->Del(this);
}

//��_������&�����o���̏���
void Bushi::HitJudge(Game& g) {
   //�G�ƃv���C���[�̃A�N�V�����̓����蔻��
   for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
   {
      OBJECTTYPE objtype = (*ite)->GetObjType();
      switch (objtype) {
         //�v���C���[�̒��i�U��
      case ObjectBase::OBJECTTYPE::MIDDLEATTACK:
         if (IsHit(*(*ite)) == true){
            (*ite)->Delete(g);
            _action_cnt = _cnt;
            //SE
            PlaySoundMem(_se["DeadV"], DX_PLAYTYPE_BACK, true);
            _state = ENEMYSTATE::DEAD;
            for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++){
               // ite�̓v���C���[���H
               if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER){
                  //�v���C���[�̋����Q�[�W��MAX�łȂ��Ȃ�v���C���[�̋����Q�[�W�𑝉�������
                  auto ig = (*ite)->GetGauge();
                  if (ig < PLAYER_IAI_MAX) {
                     (*ite)->SetGauge(ig += 1);
                  }
                  //�G�t�F�N�g
                  auto flip = (*ite)->GetFlip();
                  auto bloodtype = GetRand(2);
                  auto mb = new MiddleBlood(_x + _gx, _y + _gy, flip, bloodtype);
                  g.GetOS()->Add(mb);
               }
            }
         }
         break;
         //�v���C���[�̉��i�U��
      case ObjectBase::OBJECTTYPE::LOWATTACK:
         if (IsHit(*(*ite)) == true){
            (*ite)->Delete(g);
            _life--;
            //�̗͂�o�Ȃ玀�S��Ԃ̏����ցA�łȂ��Ȃ��_���̏�����
            if (_life <= 0) {
               //�����Q�[�W�̑���
               for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
               {
                  // ite�̓v���C�����H
                  if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER) {
                     //�v���C���[�̋����Q�[�W��MAX�łȂ��Ȃ�v���C���[�̋����Q�[�W�𑝉�������
                     auto ig = (*ite)->GetGauge();
                     if (ig < PLAYER_IAI_MAX) {
                        (*ite)->SetGauge(ig += 1);
                     }
                     //�G�t�F�N�g
                     auto flip = (*ite)->GetFlip();
                     auto bloodtype = GetRand(2);
                     auto mb = new MiddleBlood(_x + _gx, _y + _gy, flip, bloodtype);
                     g.GetOS()->Add(mb);
                  }
               }
               //SE
               PlaySoundMem(_se["DeadV"], DX_PLAYTYPE_BACK, true);
               _state = ENEMYSTATE::DEAD;
            }
            else {
               //SE
               PlaySoundMem(_se["DamageV"], DX_PLAYTYPE_BACK, true);
               _state = ENEMYSTATE::DAMAGE; 
            }
            _action_cnt = _cnt;
            _anime["Attack"] = 0;
         }
         break;
         //�����y�эs���̉�
      case ObjectBase::OBJECTTYPE::IAI:
      case ObjectBase::OBJECTTYPE::FLAME:
      case ObjectBase::OBJECTTYPE::MUGENFLAME:
         // �G�ƃv���C���[�̋���&�s���̉��I�u�W�F�N�g�̓����蔻����s��
         if (IsHit(*(*ite)) == true){
            _life -= 3;
            _action_cnt = _cnt;
            _state = ENEMYSTATE::DEAD;
         }
         break;
         //�v���C���[
      case ObjectBase::OBJECTTYPE::PLAYER:
         // �v���C���[�Ƃ��̓G�̓����蔻����s��
         if (IsHit(*(*ite)) == true) {
            _x = _before_x;
         }
         break;
      default:
         break;
      }
   }
}

//���m�̉摜�ǂݍ��݊֐�
void Bushi::LoadPicture() {
   _grall["Appear"].resize(APPEAR_ANIMEMAX);
   ResourceServer::LoadDivGraph(APPEAR_GRAPHNAME, APPEAR_ANIMEMAX, APPEAR_WIDTHCOUNT, APPEAR_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Appear"].data());
   _grall["Patrol"].resize(PATROL_ANIMEMAX);
   ResourceServer::LoadDivGraph(PATROL_GRAPHNAME, PATROL_ANIMEMAX, PATROL_WIDTHCOUNT, PATROL_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Patrol"].data());
   _grall["Coming"].resize(COMING_ANIMEMAX);
   ResourceServer::LoadDivGraph(COMING_GRAPHNAME, COMING_ANIMEMAX, COMING_WIDTHCOUNT, COMING_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Coming"].data());
   _grall["Attack"].resize(ATTACK_ANIMEMAX);
   ResourceServer::LoadDivGraph(ATTACK_GRAPHNAME, ATTACK_ANIMEMAX, ATTACK_WIDTHCOUNT, ATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Attack"].data());
   _grall["Damage"].resize(DAMAGE_ANIMEMAX);
   ResourceServer::LoadDivGraph(DAMAGE_GRAPHNAME, DAMAGE_ANIMEMAX, DAMAGE_WIDTHCOUNT, DAMAGE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Damage"].data());
   _grall["Dead"].resize(DEAD_ANIMEMAX);
   ResourceServer::LoadDivGraph(DEAD_GRAPHNAME, DEAD_ANIMEMAX, DEAD_WIDTHCOUNT, DEAD_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Dead"].data());
}

//SE�ǂݍ��݊֐�
void Bushi::LoadSE() {
   _se["Attack"] = ResourceServer::LoadSoundMem("se/Enemy/BushiAttack.wav");
   _se["DamageV"] = ResourceServer::LoadSoundMem("se/Voice/Dead01.wav");
   _se["DeadV"] = ResourceServer::LoadSoundMem("se/Voice/Dead04.wav");
}

//���ʉ��{�����[�������l�ݒ�֐�
void   Bushi::VolumeInit() {
   _vpal["Attack"] = 255;
   _vpal["DamageV"] = 255;
   _vpal["DeadV"] = 180;
}

//�{�����[���ύX�֐�
void   Bushi::VolumeChange() {
   ChangeVolumeSoundMem(_vpal["Attack"], _se["Attack"]);
   ChangeVolumeSoundMem(_vpal["DamageV"], _se["DamageV"]);
   ChangeVolumeSoundMem(_vpal["DeadV"], _se["DeadV"]);
}
//�f�o�b�O�p�֐�
void Bushi::DebugDraw(Game& g) {
   switch (_state) {
   case ENEMYSTATE::PATROL:
      if (_isflip == false) {
         PrivateCollision pc(_x + _hit_x - PATROL_WIDTH, _y - _hit_h,PATROL_WIDTH,PATROL_HEIGHT);
         PrivateCollision bpc(_x - _hit_x, _y - _hit_h, PATROL_BACKWIDTH, PATROL_HEIGHT);
         pc.SetColor(std::make_tuple(0, 255, 0));
         bpc.SetColor(std::make_tuple(0, 128, 128));
         pc.Draw(g);
         bpc.Draw(g);
      }
      if (_isflip == true) {
         PrivateCollision pc(_x - _hit_x, _y - _hit_h,PATROL_WIDTH, PATROL_HEIGHT);
         PrivateCollision bpc(_x + _hit_x - PATROL_BACKWIDTH, _y - _hit_h, PATROL_BACKWIDTH, PATROL_HEIGHT);
         pc.SetColor(std::make_tuple(0, 255, 0));
         bpc.SetColor(std::make_tuple(0, 128, 128));
         pc.Draw(g);
         bpc.Draw(g);
      }
      break;
   case ENEMYSTATE::COMING:
      if (_isflip == false) {
         PrivateCollision cc(_x + _hit_x - COMING_WIDTH, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
         cc.SetColor(std::make_tuple(255, 255, 0));
         cc.Draw(g);
      }
      if (_isflip == true) {
         PrivateCollision cc(_x - _hit_x, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
         cc.SetColor(std::make_tuple(255, 255, 0));
         cc.Draw(g);
      }
      break;
   }
}