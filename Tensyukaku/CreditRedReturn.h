/*****************************************************************//**
 * \file   CreditRedReturn.h
 * \brief  �ԃ{�^���K�C�h�N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
/** �ԃ{�^���K�C�h */
class CreditRedReturn :public ModeBase {
   typedef ModeBase base;
public:
   /**
     * \brief   �������֐�
     * \param g �Q�[���N���X�̎Q��
     */
   virtual bool Initialize(Game& g);
   /**
     * \brief   �I���֐�
     * \param g �Q�[���N���X�̎Q��
     */
   virtual bool Terminate(Game& g);
   /**
     * \brief   �X�V�֐�
     * \param g �Q�[���N���X�̎Q��
     */
   virtual bool Process(Game& g);
   /**
     * \brief   �`��֐�
     * \param g �Q�[���N���X�̎Q��
     */
   virtual bool Draw(Game& g);
};