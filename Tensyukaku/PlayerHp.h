/*****************************************************************//**
 * \file   PlayerHp.h
 * \brief  �v���C���[�̗̑�UI�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** �v���C���[�̗̑�UI */
class PlayerHp :public ObjectBase {
public:
   /**
    * \brief    �R���X�g���N�^
    * \param hp �v���C���[�̗̑�
    */
   PlayerHp(int hp);
   /**
    * \brief �f�X�g���N�^
    */
   ~PlayerHp();
   /**
    * \brief                 �������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::UI �I�u�W�F�N�g�̎�ʁiUI�j��Ԃ�
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::UI; }
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
};

