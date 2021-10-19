/*****************************************************************//**
 * \file   OverlayBlack.cpp
 * \brief  �t�F�[�h�A�E�g�t�F�[�h�C���̂��߂̍��w�i�N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "OverlayBlack.h"
#include "Game.h"
#include "ResourceServer.h"

bool OverlayBlack::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 960;           //X���W�̏�����
   _y = 540;           //Y���W�̏�����
   _pal = 0;           //�t�F�[�h�C�����Ă������߁A�����x0�ŏ�����
   _mode_cnt = _cnt;   //�t���[���̏�����
   _grhandle=ResourceServer::LoadGraph("res/Mode/Black.png"); //�摜�ǂݍ���
   return true;
}

bool OverlayBlack::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}

void OverlayBlack::SetFade(int fadeoutframe,int fadeinbeginframe,int fadeinendframe, int fadespeed) {
   _fadeout_frame= fadeoutframe;
   _fadein_beginframe = fadeinbeginframe;
   _fadein_endframe = fadeinendframe;
   _fade_speed = fadespeed;
}

bool OverlayBlack::Process(Game& g) {
   base::Process(g);
   auto frame = _cnt - _mode_cnt;
   //�t�F�[�h�̏���
   if (frame >= 0 && _fadeout_frame >frame) {
      _pal += _fade_speed;
   }
   if (frame == _fadeout_frame) {
      _pal = 255;
   }
   if (frame >= _fadein_beginframe && _fadein_endframe > frame) {
      _pal -= _fade_speed;
   }
   if (frame == _fadein_endframe) {
      _pal = 0;
      g.GetMS()->Del(this);
   }
   return true;
}

bool OverlayBlack::Draw(Game& g) {
   base::Draw(g);
   return true;
}