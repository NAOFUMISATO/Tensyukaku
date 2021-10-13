/*****************************************************************//**
 * \file   ModeTutorial.h
 * \brief  �C���Q�[���ł̃`���[�g���A���N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"

class  ModeTutorial :public ModeBase {
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
   //�`���[�g���A���̎�ʂ�ݒ肷��֐�
   void SetType(std::string tutorialtype) { _tutorial_type = tutorialtype; }
private:
   //�摜�ǂݍ��݊֐�
   void LoadPicture();
   std::string   _tutorial_type;   //�`���[�g���A���̎�ʕϐ�
};

namespace TuInfo {
   constexpr auto GRAPH_WIDTH = 880;    //�摜�T�C�Y����
   constexpr auto GRAPH_HEIGHT = 470;   //�摜�T�C�Y�c��
}