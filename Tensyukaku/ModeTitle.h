/*****************************************************************//**
 * \file   ModeTitle.h
 * \brief  ���[�h�^�C�g���N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include   "ModeBase.h"

class ModeTitle : public ModeBase
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
   //�^�C�g���̎�ʂ��^�C�g���w�i�ɐݒ肷��֐�
   void SetTitlebg() { _type = TITLETYPE::TITLEBG; }
   //�I�u�W�F�N�g�����̃X�g�b�v����̐ݒ�֐�
   void SetStopObjProcess(bool stopobjprocess) { _stop_obj_process = stopobjprocess; }
   
private:
   //�^�C�g���̎�ʗ�
   enum class TITLETYPE { AMGLOGO, TEAMLOGO, TITLEBG };
   TITLETYPE _type;            //�^�C�g���̎��
   bool   _stop_obj_process;   //�I�u�W�F�N�g�����̃X�g�b�v����t���O
};

namespace MTInfo{
   /*----------AMG���S�t�F�[�h�֌W---------*/
   constexpr auto AMG_FADEINFRAME = 60;
   constexpr auto AMG_FADESPEED = 5;
   constexpr auto AMG_FADEOUTBEGINFRAME = 90;
   constexpr auto AMG_FADEOUTENDFRAME = 150;
   /*----------TEAM���S�t�F�[�h�֌W---------*/
   constexpr auto TEAM_FADEINFRAME = 120;
   constexpr auto TEAM_FADESPEED = 3;
   constexpr auto TEAM_FADEOUTBEGINFRAME = 180;
   constexpr auto TEAM_FADEOUTENDFRAME = 300;
   /*----------�^�C�g���w�i�t�F�[�h�֌W---------*/
   constexpr auto TITLE_FADEINBEGINFRAME = 120;
   constexpr auto TITLE_FADEINENDFRAME = 240;
   constexpr auto TITLE_FADESPEED = 3;
   constexpr auto GAMESTART_APPEARFRAME = 300;
   constexpr auto EXPLAIN_APPEARFRAME = 315;
   constexpr auto GAMEEND_APPEARFRAME = 345;
   constexpr auto CREDIT_APPEARFRAME = 330;
}
