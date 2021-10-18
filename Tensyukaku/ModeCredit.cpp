/*****************************************************************//**
 * \file   ModeCredit.cpp
 * \brief  �N���W�b�g�N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModeCredit.h"
#include "Game.h"
#include "Player.h"
#include "ModeTitle.h"
#include "ResourceServer.h"
#include "OverlayBlack.h"
#include "CreditLeftGuide.h"
#include "CreditRedReturn.h"

using namespace CrInfo;
/*-----������------*/
bool ModeCredit::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 2880;               //X���W������
   _y = 1080;               //Y���W������
   _pal = 0;                //�t�F�[�h�C�����Ă������߁A�����x0�ŏ�����
   _mode_cnt = _cnt;        //�t���[���̏�����
   _leftmove_flag = false;  //�N���W�b�g�̃y�[�W���߂���t���O�i���ֈړ��p�j
   _rightmove_flag = false; //�N���W�b�g�̃y�[�W���߂���t���O�i�E�ֈړ��p�j
   _start_flag = true;      //�N���W�b�g���[�h�̊J�n�t���O��^�ŏ�����
   _end_flag = false;       //�N���W�b�g���[�h�̏I���t���O���U�ŏ�����
   _grhandle=ResourceServer::LoadGraph("res/Mode/ModeCredit.png");  //�摜�ǂ݂���
   //SE�ǂݍ���
   _se["CreditOpen"] = ResourceServer::LoadSoundMem("se/OutGame/CreditOpen.wav");
   _se["CreditMove"] = ResourceServer::LoadSoundMem("se/OutGame/CreditMove.wav");
   //SE���ʏ�����
   _vpal["CreditOpen"] = 200;   
   _vpal["CreditMove"] = 200;
   return true;
}
/*-----�I��------*/
bool ModeCredit::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}
/*-----�X�V------*/
bool ModeCredit::Process(Game& g) {
   base::Process(g);
   //SE�̉��ʕύX
   ChangeVolumeSoundMem(_vpal["CreditOpen"], _se["CreditOpen"]);
   ChangeVolumeSoundMem(_vpal["CreditMove"], _se["CreditMove"]);
   auto frame = _cnt - _mode_cnt;
   if (frame == 1) {
      //SE�Đ�
      PlaySoundMem(_se["CreditOpen"],DX_PLAYTYPE_BACK,true);
   }
   //�t�F�[�h�C���̏���
   if (frame<FADE_FRAME&&_start_flag==true) {
      _pal += FADE_SPEED;
   }
   if (frame == FADE_FRAME && _start_flag == true) {
      auto gu = new CreditLeftGuide();         //���X�e�B�b�N�K�C�h�̐���
      g.GetMS()->Add(gu, 3, "Guide");
      auto rr = new CreditRedReturn();      //�ԃ{�^���K�C�h�̐���
      g.GetMS()->Add(rr, 3, "RedReturn");
      _start_flag = false;
   }
   //�t�F�[�h�A�E�g�̏���
   if (frame == FADE_FRAME && _end_flag == true) {
      g.GetMS()->Del(this);
      auto mt = new ModeTitle();      //���[�h�^�C�g������
      mt->SetTitlebg();   
      g.GetMS()->Add(mt, 0, "Title");
   }
   if (g.GetTrg() & PAD_INPUT_LEFT&&_x==960) {
      //SE�Đ�
      PlaySoundMem(_se["CreditMove"], DX_PLAYTYPE_BACK, true);
      _leftmove_flag = true;
   }
   if (g.GetTrg() & PAD_INPUT_RIGHT && _x == 2880) {
      //SE�Đ�
      PlaySoundMem(_se["CreditMove"], DX_PLAYTYPE_BACK, true);
      _rightmove_flag = true;
   }
   //4�{�^�����������Ȃ�e���[�h�폜���A�^�C�g�����[�h����
   if (g.GetTrg() & PAD_INPUT_4) {
      _mode_cnt = _cnt;
      auto ol = new OverlayBlack();                 //�t�F�[�h�A�E�g�̂��߂̃I�[�o�[���C���[�h����
      ol->SetFade(FADE_FRAME, 120,180, FADE_SPEED); //�t�F�[�h���Ԃ̐ݒ�
      g.GetMS()->Add(ol, 2, "OverlayBlack");
      g.GetMS()->Del(g.GetMS()->Get("Guide"));      //���X�e�B�b�N�K�C�h�폜
      g.GetMS()->Del(g.GetMS()->Get("RedReturn"));  //�ԃ{�^���K�C�h�폜
      _end_flag = true;
   }
   if (_leftmove_flag == true) {
      if (_x < 2880) {
         _x += 60;
      }
      if (_x == 2880) {
         _leftmove_flag = false;
      }
   }
   if (_rightmove_flag == true) {
      if (_x > 960) {
         _x-= 60;
      }
      if (_x == 960) {
         _rightmove_flag = false;
      }
   }
   return true;
}
/*-----�`��------*/
bool ModeCredit::Draw(Game& g) {
   auto posx = _x - 960;
   auto posy = _y - 540;
   SetDrawBlendMode(DX_BLENDMODE_ALPHA, _pal);
   DrawRotaGraph(posx, posy, 1.0, 0.0, _grhandle, _trans_flag, false);
   SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
   return true;
}