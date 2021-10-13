/*****************************************************************//**
 * \file   OverlayBlack.h
 * \brief  �t�F�[�h�A�E�g�t�F�[�h�C���̂��߂̍��w�i�N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"

class OverlayBlack : public ModeBase
{
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
   //�e�t�F�[�h�֌W��ݒ肷��֐�
   void SetFade(int fadeoutframe,int fadeinbeginframe,int fadeinendframe, int fadespeed);
   //�����x�̒l��Ԃ��֐�
   int GetPal() { return _pal; }
private:
   int _fadeout_frame;     //�t�F�[�h�A�E�g���I���t���[����ݒ肷��ϐ�
   int _fadein_beginframe; //�t�F�[�h�C���J�n�t���[����ݒ肷��ϐ�
   int _fadein_endframe;   //�t�F�[�h�C���I���t���[����ݒ肷��ϐ�
   int _fade_speed;       //�t�F�[�h�X�s�[�h��ݒ肷��ϐ�
};