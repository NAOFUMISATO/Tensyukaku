/*****************************************************************//**
 * \file   EpilogueText.h
 * \brief  �G�s���[�O�e�L�X�g�N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
/** �G�s���[�O�e�L�X�g */
class  EpilogueText :public ModeBase {
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
   /**
    * \brief SE�ǂݍ��݊֐�
    */
   void LoadSE();
   /**
    * \brief SE���ʏ������֐�
    */
   void VolumeInit();
   /**
    * \brief SE���ʕύX�֐�
    */
   void VolumeChange();
   /*---�����o�ϐ�---*/
   int _graph_no;   //!<�V�[�g�ԍ�
};
