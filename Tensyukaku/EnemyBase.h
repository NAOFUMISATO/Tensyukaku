/*****************************************************************//**
 * \file   EnemyBase.h
 * \brief  �G�̃x�[�X�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
class EnemyBase : public ObjectBase {
protected:
   //�G�̏�ԗ�
   enum class ENEMYSTATE { 
      APPEAR,               //�o��
      PATROL,               //���G
      COMING,               //�ǐ�
      ATTACK,               //�U��
      GUARDATTACK,   //�������U��   (�����̂�)
      THROW,               //�N�i�C����   (�E�҂̂�)
      GUARDBREAK,      //������         (�����̂�)
      DAMAGE,               //��_��         (���m�A�����̂�)
      DEAD                     //���S 
   };
public:
   EnemyBase();
   ~EnemyBase();
   virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::ENEMY; }
   //�G�̎�ޗ�
   enum class ENEMYTYPE {
      BUSHI,               //���m
      BUSYO,               //����
      NINJA,               //�E��
      ZYOUNIN,         //��E
      LANCER,            //����
      SHIELDER         //����
   };
   //�������z�֐�
   virtual ENEMYTYPE GetEneType() = 0;
   //������
   virtual   void   Init();
   //�X�V
   virtual   void   Process(Game& g);
   //�`��
   virtual   void   Draw(Game& g);
   //�I�u�W�F�N�g�̏���
   virtual   void   Delete(Game& g) {};

protected:
   ENEMYTYPE _type;            //�G�̎�ޕϐ�
   ENEMYSTATE _state;         //��ԑJ�ڕϐ�
};

