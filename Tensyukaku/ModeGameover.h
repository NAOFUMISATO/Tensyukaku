/*****************************************************************//**
 * \file   ModeGameover.h
 * \brief  ���[�h�Q�[���I�[�o�[�N���X�i���[�h�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include   "ModeBase.h"

class ModeGameover : public ModeBase{
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
};

