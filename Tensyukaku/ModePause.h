/*****************************************************************//**
 * \file   ModePause.h
 * \brief  �C���Q�[���ł̃|�[�Y��ʃN���X�i���[�h�x�[�X�N���X�̃T�u�N���X�j�A�|�[�Y��ʂɕ\������R���g���[���[�N���X�i���[�h�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
 /*----------�C���Q�[���ł̃|�[�Y��ʃN���X-------------*/
class  ModePause :public ModeBase {
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
/*-----------�|�[�Y��ʗp�R���g���[���[�N���X-------------*/
class PController :public ModeBase {
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