/*****************************************************************//**
 * \file   Zyounin.cpp
 * \brief  ��E�N���X�i�G�l�~�[�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include <vector>
#include <sstream>
#include "EnemyBase.h"
#include "Zyounin.h"
#include "Game.h"
#include "LowBlood.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
#include "PrivateCollision.h"

using namespace ZInfo;

Zyounin::Zyounin(int x, int y, bool flip, int kunai_stock)
{
   _x = x;
   _y = y;
   _isflip = flip;
   _kunai_stock = kunai_stock;
   Init();
   LoadPicture();
   LoadSE();
   VolumeInit();
};

Zyounin::~Zyounin() {
};

void Zyounin::Init() {
   _sort = 6;
   _grhandle = -1;
   _gx = GRAPHPOINT_X;
   _gy = GRAPHPOINT_Y;
   _hit_x = POSITION_HITX;
   _hit_y = POSITION_HITY;
   _hit_w = COLLISION_WIDTH;
   _hit_h = COLLISION_HEIGHT;
   _state = ENEMYSTATE::APPEAR;
   _life = LIFE_MAX;
   _spd = SPEED;
   _alpha = 0;
}

void Zyounin::Process(Game& g) {
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
   case ENEMYSTATE::THROW:
      Throw(g);
      break;
      //���S���
   case ENEMYSTATE::DEAD:
      Dead(g);
      break;
   }
   //�����蔻��̏���
   HitJudge(g);
}

void Zyounin::Draw(Game& g) {
#ifdef _DEBUG
   DebugDraw(g);
#endif
   SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
   EnemyBase::Draw(g);
}

void Zyounin::Delete(Game& g) {
   g.GetOS()->Del(this);
}

void Zyounin::HitJudge(Game& g) {
   //�G�ƃv���C���[�̃A�N�V�����̓����蔻��
   for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
   {
      OBJECTTYPE objType = (*ite)->GetObjType();
      switch (objType) {
         //�v���C���[�̉��i�U��
      case ObjectBase::OBJECTTYPE::LOWATTACK:
         if (IsHit(*(*ite)) == true){
            (*ite)->Delete(g);
            _life--;
            _action_cnt = _cnt;
            _state = ENEMYSTATE::DEAD;
            //SE
            PlaySoundMem(_se["DeadV"], DX_PLAYTYPE_BACK, true);
            //�����Q�[�W�̑���
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
                  auto mb = new LowBlood(_x + _gx, _y - 200, flip, bloodtype);
                  g.GetOS()->Add(mb);
               }
            }
         }
         break;
         //�����y�эs���̉�
      case ObjectBase::OBJECTTYPE::IAI:
      case ObjectBase::OBJECTTYPE::FLAME:
      case ObjectBase::OBJECTTYPE::MUGENFLAME:
         // �G�ƃv���C���[�̋���&�s���̉��I�u�W�F�N�g�̓����蔻����s��
         if (IsHit(*(*ite)) == true){
            _life--;
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

void Zyounin::LoadPicture() {
   _grall["Appear"].resize(APPEAR_ANIMEMAX);
   ResourceServer::LoadDivGraph(APPEAR_GRAPHNAME, APPEAR_ANIMEMAX, APPEAR_WIDTHCOUNT, APPEAR_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Appear"].data());
   _grall["Patrol"].resize(PATROL_ANIMEMAX);
   ResourceServer::LoadDivGraph(PATROL_GRAPHNAME, PATROL_ANIMEMAX, PATROL_WIDTHCOUNT, PATROL_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Patrol"].data());
   _grall["Coming"].resize(COMING_ANIMEMAX);
   ResourceServer::LoadDivGraph(COMING_GRAPHNAME, COMING_ANIMEMAX, COMING_WIDTHCOUNT, COMING_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Coming"].data());
   _grall["Attack"].resize(ATTACK_ANIMEMAX);
   ResourceServer::LoadDivGraph(ATTACK_GRAPHNAME, ATTACK_ANIMEMAX, ATTACK_WIDTHCOUNT, ATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Attack"].data());
   _grall["Throw"].resize(THROW_ANIMEMAX);
   ResourceServer::LoadDivGraph(THROW_GRAPHNAME, THROW_ANIMEMAX, THROW_WIDTHCOUNT, THROW_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Throw"].data());
   _grall["Dead"].resize(DEAD_ANIMEMAX);
   ResourceServer::LoadDivGraph(DEAD_GRAPHNAME, DEAD_ANIMEMAX, DEAD_WIDTHCOUNT, DEAD_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Dead"].data());
}

void  Zyounin::LoadSE() {
   _se["Attack"] = ResourceServer::LoadSoundMem("se/Enemy/NinjaAttack.wav");
   _se["Kunai"] = ResourceServer::LoadSoundMem("se/Enemy/Kunai.wav");
   _se["DeadV"] = ResourceServer::LoadSoundMem("se/Voice/Dead05.wav");
}

void    Zyounin::VolumeInit() {
   _vpal["Attack"] = 255;
   _vpal["Kunai"] = 255;
   _vpal["DeadV"] = 255;
}

void    Zyounin::VolumeChange() {
   ChangeVolumeSoundMem(_vpal["Attack"], _se["Attack"]);
   ChangeVolumeSoundMem(_vpal["Kunai"], _se["Kunai"]);
   ChangeVolumeSoundMem(_vpal["DeadV"], _se["DeadV"]);
}

void Zyounin::DebugDraw(Game& g) {
   switch (_state) {
   case ENEMYSTATE::PATROL:
      if (_isflip == false) {
         PrivateCollision pc(_x + _hit_x - PATROL_WIDTH, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
         PrivateCollision bpc(_x - _hit_x, _y - _hit_h, PATROL_BACKWIDTH, PATROL_HEIGHT);
         pc.SetColor(std::make_tuple(0, 255, 0));
         bpc.SetColor(std::make_tuple(0, 128, 128));
         pc.Draw(g);
         bpc.Draw(g);
      }
      if (_isflip == true) {
         PrivateCollision pc(_x - _hit_x, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
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
