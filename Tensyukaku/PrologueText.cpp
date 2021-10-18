/*****************************************************************//**
 * \file   PrologueText.cpp
 * \brief  �v�����[�O�e�L�X�g�N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModePrologue.h"
#include "PrologueText.h"
#include "ModeGame.h"
#include "Game.h"
#include "PrologueSkip.h"
#include "OverlayBlack.h"
#include "ResourceServer.h"

using namespace ProInfo;
/*----�v�����[�O�e�L�X�g�N���X-----*/
/*---������---*/
bool PrologueText::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 1600;          //X���W�̏�����
   _y = 540;           //Y���W�̏�����
   _pal = 0;           //�t�F�[�h�C�����Ă������߁A�����x�O�ŏ�����
   _graph_no = 0;      //�V�[�g�ԍ��O�ŏ�����
   _mode_cnt = _cnt;   //�t���[���̏�����
   _trans_flag = true; //�w�i���߃t���O��^�ŏ�����
   _skip_flag = false; //�X�L�b�v�{�^�������������̃t���O���U�ŏ�����
   //�摜�ǂݍ���
   _grall["PText"].resize(TEXT_ANIMEMAX);
   ResourceServer::LoadDivGraph(TEXT_GRAPHNAME, TEXT_ANIMEMAX, TEXT_WIDTHCOUNT, TEXT_HEIGHTCOUNT, TEXT_GRAPH_WIDTH, TEXT_GRAPH_HEIGHT, _grall["PText"].data());
   LoadSE();           //SE�ǂݍ���
   VolumeInit();       //SE���ʏ�����
   PlaySoundMem(_se["Text1"], DX_PLAYTYPE_BACK, true);   //�e�L�X�g1�Đ�
   return true;
}
/*-----�I��------*/
bool PrologueText::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}
/*---�X�V---*/
bool PrologueText::Process(Game& g) {
   base::Process(g);
   VolumeChange();         //SE���ʕύX
   auto frame = _cnt - _mode_cnt;
   _grhandle = _grall["PText"][_anime["PText"]];
   _anime["PText"] = _graph_no;
   /*-----�e�e�L�X�g�̃t�F�[�h�C���A�t�F�[�h�A�E�g����-----*/
   //�e�L�X�g1
   //�X�L�b�v�{�^�������t���O���U�Ȃ珈��������
   if (_skip_flag == false) {
      if (frame < TEXT1_FADEIN_FRAME) {
         _pal += TEXT_FADE_SPEED;
      }
      if (frame == TEXT1_FADEIN_FRAME) {
         _pal = 255;
         auto as = new PrologueASkip();      //�X�L�b�v�e�L�X�g����
         g.GetMS()->Add(as, 1, "PASkip");
      }
      if (frame >= TEXT1_FADEOUT_BEGINFRAME && TEXT1_FADEOUT_ENDFRAME > frame) {
         _pal -= TEXT_FADE_SPEED;
      }
      if (frame == TEXT1_FADEOUT_ENDFRAME) {
         _pal = 0;
         _graph_no = 1;
      }
      //�e�L�X�g2
      if (frame == TEXT2_FADEIN_BEGINFRAME) {
         //�{�C�X�Đ�
         PlaySoundMem(_se["Text2"], DX_PLAYTYPE_BACK, true);
      }
      if (frame >= TEXT2_FADEIN_BEGINFRAME && TEXT2_FADEIN_ENDFRAME > frame) {
         _pal += TEXT_FADE_SPEED;
      }
      if (frame == TEXT2_FADEIN_ENDFRAME) {
         _pal = 255;
      }
      if (frame >= TEXT2_FADEOUT_BEGINFRAME && TEXT2_FADEOUT_ENDFRAME > frame) {
         _pal -= TEXT_FADE_SPEED;
      }
      if (frame == TEXT2_FADEOUT_ENDFRAME) {
         _pal = 0;
         _graph_no = 2;
      }
      //�e�L�X�g3
      if (frame == TEXT3_FADEIN_BEGINFRAME) {
         //�{�C�X�Đ�
         PlaySoundMem(_se["Text3"], DX_PLAYTYPE_BACK, true);
      }
      if (frame >= TEXT3_FADEIN_BEGINFRAME && TEXT3_FADEIN_ENDFRAME > frame) {
         _pal += TEXT_FADE_SPEED;
      }
      if (frame == TEXT3_FADEIN_ENDFRAME) {
         _pal = 255;
      }
      if (frame >= TEXT3_FADEOUT_BEGINFRAME && TEXT3_FADEOUT_ENDFRAME > frame) {
         _pal -= TEXT_FADE_SPEED;
      }
      if (frame == TEXT3_FADEOUT_ENDFRAME) {
         _pal = 0;
         _graph_no = 3;
      }
      //�e�L�X�g4
      if (frame == TEXT4_FADEIN_BEGINFRAME) {
         //�{�C�X�Đ�
         PlaySoundMem(_se["Text4"], DX_PLAYTYPE_BACK, true);
      }
      if (frame >= TEXT4_FADEIN_BEGINFRAME && TEXT4_FADEIN_ENDFRAME > frame) {
         _pal += TEXT_FADE_SPEED;
      }
      if (frame == TEXT4_FADEIN_ENDFRAME) {
         _pal = 255;
      }
      if (frame >= TEXT4_FADEOUT_BEGINFRAME && TEXT4_FADEOUT_ENDFRAME > frame) {
         _pal -= TEXT_FADE_SPEED;
      }
      if (frame == TEXT4_FADEOUT_ENDFRAME) {
         _pal = 0;
         _x = 1500;
         _y = 850;
         _graph_no = 4;
      }
      //�e�L�X�g5
      if (frame == TEXT5_FADEIN_BEGINFRAME) {
         //�{�C�X�Đ�
         PlaySoundMem(_se["Text5"], DX_PLAYTYPE_BACK, true);
      }
      if (frame >= TEXT5_FADEIN_BEGINFRAME && TEXT5_FADEIN_ENDFRAME > frame) {
         _pal += TEXT_FADE_SPEED;
      }
      if (frame == TEXT5_FADEIN_ENDFRAME) {
         _pal = 255;
      }
      if (frame >= TEXT5_FADEOUT_BEGINFRAME && TEXT5_FADEOUT_ENDFRAME > frame) {
         _pal -= TEXT_FADE_SPEED;
      }
      if (frame == TEXT5_FADEOUT_ENDFRAME) {
         _pal = 0;
         g.GetMS()->Del(this);   //���̃��[�h���폜
      }
   }
   /*---�{�^�������ɂ��X�L�b�v---*/
   auto fadeoutframe =85;
   //3�{�^���������������A�X�L�b�v�����t���O���U�Ȃ�Ώ�������
   if (g.GetTrg() & PAD_INPUT_3&&_skip_flag==false) {
      _mode_cnt = _cnt;
      _skip_flag = true;
      auto ol = new OverlayBlack();          //�t�F�[�h�A�E�g�̂��߂̃��[�h�I�[�o�[���C�u���b�N����
      ol->SetFade(fadeoutframe, 480, 600, 4);//�t�F�[�h���Ԃ̐ݒ�
      g.GetMS()->Add(ol, 2, "OverlayBlack");
   }
   //����������t���[���ȓ��Ȃ�Ώ�������
   if (frame >= 0 && frame < fadeoutframe && _skip_flag == true) {
      //�X�L�b�v���̉����̃t�F�[�h�A�E�g
      auto vpal = g.GetVpal();
      vpal["Prologue"] -= 1;
      g.SetVpal(vpal);
      _vpal["Text1"]-=4;
      _vpal["Text2"]-=4;
      _vpal["Text3"]-=4;
      _vpal["Text4"]-=4;
      _vpal["Text5"]-=4;
   }
   //���������t���[����A��������
   if (frame == fadeoutframe&& _skip_flag == true) {
      //�e�����̒�~
      StopSoundMem(_se["Text1"]);
      StopSoundMem(_se["Text2"]);
      StopSoundMem(_se["Text3"]);
      StopSoundMem(_se["Text4"]);
      StopSoundMem(_se["Text5"]);
      StopSoundMem(g.GetBgm() ["Prologue"]);
      g.GetMS()->Del(g.GetMS()->Get("PASkip"));   //�X�L�b�v�e�L�X�g�폜
      g.GetMS()->Del(g.GetMS()->Get("Prologue")); //�v�����[�O���[�h�폜
      g.GetMS()->Del(this);                       //���̃��[�h���폜
      auto mg = new ModeGame();                   //���[�h�Q�[������
      g.GetMS()->Add(mg, 0, "Game");
   }
   return true;
}
/*---�`��---*/
bool PrologueText::Draw(Game& g) {
   base::Draw(g);
   return true;
}

//SE�ǂݍ��݊֐�
void PrologueText::LoadSE() {
   _se["Text1"] = ResourceServer::LoadSoundMem("se/Voice/Prologue01.wav");
   _se["Text2"] = ResourceServer::LoadSoundMem("se/Voice/Prologue02.wav");
   _se["Text3"] = ResourceServer::LoadSoundMem("se/Voice/Prologue03.wav");
   _se["Text4"] = ResourceServer::LoadSoundMem("se/Voice/Prologue04.wav");
   _se["Text5"] = ResourceServer::LoadSoundMem("se/Voice/Prologue05.wav");
}

//�{�����[�������l�ݒ�֐�
void PrologueText::VolumeInit() {
   _vpal["Text1"]=255;
   _vpal["Text2"]=255;
   _vpal["Text3"]=255;
   _vpal["Text4"]=255;
   _vpal["Text5"]=255;
}
//�{�����[���ύX�֐�
void PrologueText::VolumeChange() {
   ChangeVolumeSoundMem(_vpal["Text1"],_se["Text1"]);
   ChangeVolumeSoundMem(_vpal["Text2"], _se["Text2"]);
   ChangeVolumeSoundMem(_vpal["Text3"], _se["Text3"]);
   ChangeVolumeSoundMem(_vpal["Text4"], _se["Text4"]);
   ChangeVolumeSoundMem(_vpal["Text5"], _se["Text5"]);
}
