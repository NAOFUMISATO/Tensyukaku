/*****************************************************************//**
 * \file   ModeIngameText.h
 * \brief  �C���Q�[���ł̊K�w�\���N���X�i���[�h�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"

class  ModeIngameText :public ModeBase {
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
   //�e�L�X�g�̎�ނ�ݒ肷��֐�
   void SetType(std::string texttype) { _text_type = texttype; }
private:
   //�摜�ǂݍ��݊֐�
   void LoadPicture();

   std::string _text_type; //�e�L�X�g�̎�ނ��w�肷��ϐ�
   int _fadein_frame;      //�t�F�[�h�C������t���[�����w�肷��ϐ�
   int _fadeout_frame;     //�t�F�[�h�A�E�g����t���[�����w�肷��ϐ�
   int _fade_speed;        //�t�F�[�h�̃X�s�[�h���w�肷��ϐ�
};

namespace ITInfo {
   constexpr auto GRAPH_WIDTH = 1120;  //1��������̉摜�T�C�Y�i���j
   constexpr auto GRAPH_HEIGHT = 265;  //1��������̉摜�T�C�Y�i�c)
   constexpr auto FADEIN_FRAME = 60;   //�t�F�[�h�C���t���[��
   constexpr auto FADEOUT_FRAME = 180; // �t�F�[�h�A�E�g�t���[��
   constexpr auto FADE_SPEED = 4;      // �t�F�[�h�A�E�g�t���[��

}