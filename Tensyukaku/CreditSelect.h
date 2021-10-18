/*****************************************************************//**
 * \file   CreditSelect.h
 * \brief  �N���W�b�g�Z���N�g�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** �N���W�b�g�Z���N�g */
class CreditSelect :public ObjectBase {
public:
   /**
    * \brief �R���X�g���N�^
    */
   CreditSelect();
   /**
    * \brief �f�X�g���N�^
    */
   ~CreditSelect();
   /**
    * \brief                       //�������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::CREDIT   //�I�u�W�F�N�g�̎�ʁi�N���W�b�g�Z���N�g�j��Ԃ�
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::CREDIT; }
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
};