/*****************************************************************//**
 * \file   PauseController.h
 * \brief  �|�[�Y��ʂɕ\������R���g���[���[�N���X�i���[�h�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
/** �|�[�Y�R���g���[���[ */
class PController :public ModeBase {
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