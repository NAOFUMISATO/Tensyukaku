/*****************************************************************//**
 * \file   EpilogueText.h
 * \brief  �G�s���[�O�e�L�X�g�N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"

class  EpilogueText :public ModeBase {
   typedef ModeBase base;
public:
   //������
   virtual bool Initialize(Game& g);
   //�I��
   virtual bool Terminate(Game& g);
   //�X�V
   virtual bool Process(Game& g);
   //�`��
   virtual bool Draw(Game& g);
private:
   //SE�ǂݍ��݊֐�
   void LoadSE();
   //SE���ʏ������֐�
   void VolumeInit();
   //SE���ʕύX�֐�
   void VolumeChange();

   int _graph_no;   //�V�[�g�ԍ��w��ϐ�
};
