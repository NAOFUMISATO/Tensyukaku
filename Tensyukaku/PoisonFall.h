/*****************************************************************//**
 * \file   PoisonFall.h
 * \brief  �ŉt�����N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
class PoisonFall :public ObjectBase {
public:
   /**
    * \brief   �R���X�g���N�^
    * \param x X���W
    * \param y Y���W
    */
   PoisonFall(int x, int y);
   /**
    * \brief �f�X�g���N�^
    */
   ~PoisonFall();
   /**
    * \brief                     �f�X�g���N�^
    * \return OBJECTTYPE::POISON �I�u�W�F�N�g�̎�ʁi�ŉt�j��Ԃ�
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::POISON; }
   /**
    * \brief �������֐�
    */
   void Init()override;
   /**
    * \brief   �X�V�֐�
    * \param g �Q�[���̎Q��
    */
   void Process(Game& g)override;
   /**
    * \brief   �`��֐�
    * \param g �Q�[���̎Q��
    */
   void Draw(Game& g)override;
   /**
    * \brief   �I�u�W�F�N�g�̏����֐�
    * \param g �Q�[���̎Q��
    */
   void Delete(Game& g)override;

private:
   /** �ŉt�̏�ԗ� */
   enum class POISONSTATE { 
      FALL,    //!< ������
      LAND     //!< ���n
   };

   POISONSTATE _State;  //!< �ŉt�̏�ԕϐ�
};