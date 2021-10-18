/*****************************************************************//**
 * \file   ModeCredit.h
 * \brief  �N���W�b�g�N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
/** �N���W�b�g */
class ModeCredit :public ModeBase {
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

private:
   bool _leftmove_flag;  //!< �N���W�b�g��ʂ����ֈړ�������͂��󂯕t����t���O
   bool _rightmove_flag; //!< �N���W�b�g��ʂ��E�ֈړ�������͂��󂯕t����t���O
   bool _start_flag;     //!< �N���W�b�g�̊J�n�t���O
   bool _end_flag;       //!< �N���W�b�g�̏I���t���O
};

/** �N���W�b�g�A���X�e�B�b�N�{�^���K�C�h�A�ԃ{�^���K�C�h�N���X�p�萔 */
namespace CrInfo {
   constexpr auto FADE_FRAME = 60;   //!< �t�F�[�h�t���[��
   constexpr auto  FADE_SPEED = 5;   //!< �t�F�[�h�X�s�[�h
}