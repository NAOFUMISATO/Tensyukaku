/*****************************************************************//**
 * \file   OverSelect.h
 * \brief  �Q�[���I�[�o�[�Z���N�g�N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
/** �Q�[���I�[�o�[�Z���N�g */
class OverSelect :public ModeBase {
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
   /** �I����Ԃ̗� */
   enum class SELECTSTATE {
      NOSELECT,         //!< �����I�����Ă��Ȃ�
      RETRYSELECT,      //!< ���g���C�I��
      GOTITLESELECT     //!< �^�C�g���I��
   };

   SELECTSTATE _state;  //!< �I�����
   int _graph_no;       //!< �V�[�g�ԍ��ϐ�
   bool _input_flag;    //!< ���͂���t����t���O
};