/*****************************************************************//**
 * \file   TitleLogo.h
 * \brief  �^�C�g�����S�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** �^�C�g�����S */
class TitleLogo :public ObjectBase {
public:
   /**
    * \brief �R���X�g���N�^
    */
   TitleLogo();
   /**
    * \brief �f�X�g���N�^
    */
   ~TitleLogo();
   /**
    * \brief                         //�������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::TITLELOGO  //�I�u�W�F�N�g�̎�ʁi�^�C�g�����S�j��Ԃ�
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::TITLELOGO; }
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
