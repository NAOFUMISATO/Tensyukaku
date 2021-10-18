/*****************************************************************//**
 * \file   EnemyBase.h
 * \brief  �G�̃x�[�X�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** �G�̊�� */
class EnemyBase : public ObjectBase {
protected:
   /** �G�̏�ԗ� */
   enum class ENEMYSTATE {
      APPEAR,       //!< �o��
      PATROL,       //!< ���G
      COMING,       //!< �ǐ�
      ATTACK,       //!< �U��
      GUARDATTACK,  //!< �������U��(�����̂�)
      THROW,        //!< �N�i�C����(�E�҂̂�)
      GUARDBREAK,   //!< ������(�����̂�)
      DAMAGE,       //!< ��_��(���m�A�����̂�)
      DEAD          //!< ���S
   };

public:
   /**
    * \brief �R���X�g���N�^
    */
   EnemyBase();
   /**
    * \brief �f�X�g���N�^
    */
   ~EnemyBase();
   /**
    * \brief                    �������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::ENEMY �I�u�W�F�N�g�̎�ʁi�G�j��Ԃ�
    */
   virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::ENEMY; }
   /** �G�̎�ʗ� */
   enum class ENEMYTYPE {
      BUSHI,    //���m
      BUSYO,    //����
      NINJA,    //�E��
      ZYOUNIN,  //��E
      LANCER,   //����
      SHIELDER  //����
   };
   /**
    * \brief �������z�֐���
    * \return 0
    */
   virtual ENEMYTYPE GetEneType() = 0;
   /**
    * \brief �������֐�
    */
   virtual void Init();
   /**
    * \brief   �X�V�֐�
    * \param g �Q�[���̎Q��
    */
   virtual void Process(Game& g);
   /**
    * \brief   �`��֐�
    * \param g �Q�[���̎Q��
    */
   virtual void Draw(Game& g);
   /**
    * \brief   �I�u�W�F�N�g�̏����֐�
    * \param g �Q�[���̎Q��
    */
   virtual void Delete(Game& g) {};

protected:
   ENEMYTYPE _type;     //!< �G�̎�ޕϐ�
   ENEMYSTATE _state;   //!< ��ԑJ�ڕϐ�
};

