/*****************************************************************//**
 * \file   ModeBossBefore.h
 * \brief  �{�X�X�e�[�W�O��1���G�N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"

class ModeBossBefore :public ModeBase {
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

namespace BBInfo {
   constexpr auto FOOT_FRAME = 120;      //SE��炷�t���[��
   constexpr auto VOICE_FRAME = 180;     //VOICE��炷�t���[��
   constexpr auto FADEOUT_FRAME = 540;   //�t�F�[�h�A�E�g����t���[��
}