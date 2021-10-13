/*****************************************************************//**
 * \file   PauseSelect.h
 * \brief  �|�[�Y�Z���N�g�N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"

class PauseSelect :public ModeBase {
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
   //�`���[�g���A�����[�h�폜�֐�
   void TutorialDel(Game& g);
   //�I����Ԃ̗�
   enum class SELECTSTATE {
   NOSELECT,RETURNSELECT,GOTITLESELECT
   };
   SELECTSTATE _state; //�I�����
   int _graph_no;      //�V�[�g�ԍ��ϐ�
   bool _input_flag;   //���͎�t�t���O
};