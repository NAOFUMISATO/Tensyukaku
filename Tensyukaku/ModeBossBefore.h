/*****************************************************************//**
 * \file   ModeBossBefore.h
 * \brief  �{�X�X�e�[�W�O��1���G�N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
/** �{�X�X�e�[�W�O��1���G */
class ModeBossBefore :public ModeBase {
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
/** �{�X�X�e�[�W�O��1���G�N���X�p�萔 */
namespace BBInfo {
   constexpr auto FOOT_FRAME = 120;      //!< SE��炷�t���[��
   constexpr auto VOICE_FRAME = 180;     //!< VOICE��炷�t���[��
   constexpr auto FADEOUT_FRAME = 540;   //!< �t�F�[�h�A�E�g����t���[��
}