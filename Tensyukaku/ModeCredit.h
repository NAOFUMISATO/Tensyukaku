/*****************************************************************//**
 * \file   ModeCredit.h
 * \brief  �N���W�b�g�N���X�i���[�h�x�[�X�̃T�u�N���X�j�A���X�e�B�b�N�K�C�h�{�^���N���X�i���[�h�x�[�X�̃T�u�N���X�j�A�ԃ{�^���K�C�h�N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
/*---�N���W�b�g�N���X---*/
class ModeCredit :public ModeBase {
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
   bool _leftmove_flag;  //�N���W�b�g��ʂ����ֈړ�������͂��󂯕t����t���O
   bool _rightmove_flag; //�N���W�b�g��ʂ��E�ֈړ�������͂��󂯕t����t���O
   bool _start_flag;     //�N���W�b�g�̊J�n�t���O
   bool _end_flag;       //�N���W�b�g�̏I���t���O
};
/*---���X�e�B�b�N�K�C�h�{�^���N���X---*/
class Guide:public ModeBase {
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
/*---�ԃ{�^���K�C�h�N���X---*/
class RedReturn :public ModeBase {
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
namespace CrInfo {
   constexpr auto FADE_FRAME = 60;   //�t�F�[�h�t���[��
   constexpr auto  FADE_SPEED = 5;   //�t�F�[�h�X�s�[�h
}