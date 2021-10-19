/*****************************************************************//**
 * \file   OverSelect.cpp
 * \brief  �Q�[���I�[�o�[�Z���N�g�N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "OverSelect.h"
#include "Game.h"
#include "ModeTitle.h"
#include "ModeGame.h"
#include "ResourceServer.h"
#include "OverlayBlack.h"

namespace {
   constexpr auto FADEIN_FRAME = 60;
   constexpr auto FADE_SPEED = 4;
}

bool OverSelect::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 960;                       //X���W�̏�����
   _y = 850;                       //Y���W�̏�����
   _pal = 0;                       //�t�F�[�h�C�����Ă������߁A�����x0�ŏ�����
   _graph_no = 0;                  //�V�[�g�ԍ��O�ŏ�����
   _state = SELECTSTATE::NOSELECT; //�����I�����Ă��Ȃ���Ԃŏ�����
   _trans_flag = true;             //�w�i���߃t���O��^�ŏ�����
   _input_flag = true;             //���͎�t�t���O��^�ŏ�����
   _grall["PSelect"].resize(3);
   ResourceServer::LoadDivGraph("res/Mode/OverSelect.png", 3, 3, 1, 1230, 275, _grall["PSelect"].data()); //�摜�ǂݍ���
   //SE�ǂݍ���
   _se["Select"] = ResourceServer::LoadSoundMem("se/OutGame/OtherSelectPush.wav");
   _se["Push"] = ResourceServer::LoadSoundMem("se/OutGame/GameStartPush.wav");
   //SE���ʏ�����
   _vpal["Select"] = 125;
   _vpal["Push"] = 200;
   return true;
}

bool OverSelect::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}

bool OverSelect::Process(Game& g) {
   base::Process(g);
   //SE���ʕύX
   ChangeVolumeSoundMem(_vpal["Select"], _se["Select"]);
   ChangeVolumeSoundMem(_vpal["Push"], _se["Push"]);
   auto frame = _cnt - _mode_cnt;
   auto fadeoutframe = 60;
   _grhandle = _grall["PSelect"][_anime["PSelect"]];
   _anime["PSelect"] = _graph_no;
   //�t�F�[�h�C���̏���
   if (frame < FADEIN_FRAME) {
      _pal += FADE_SPEED;
   }
   if (frame == FADEIN_FRAME) {
      _pal = 255;
   }
   /*-----�e��Ԗ��̏���-----*/
   switch (_state) {
   //�����I�����Ă��Ȃ����
   case SELECTSTATE::NOSELECT:
      _graph_no = 0;
      //�t�F�[�h���I������Ȃ璆�̏������󂯕t����
      if (frame > FADEIN_FRAME) {
         //�����͂����Ȃ烊�g���C�I����Ԃֈڍs
         if (g.GetTrg() & PAD_INPUT_LEFT) {
            //SE�Đ�
            PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
            _state = SELECTSTATE::RETRYSELECT;
         }
         //�E���͂����Ȃ�^�C�g���I����Ԃֈڍs
         if (g.GetTrg() & PAD_INPUT_RIGHT) {
            //SE�Đ�
            PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
            _state = SELECTSTATE::GOTITLESELECT;
         }
      }
      break;
      //���g���C�I�����
   case SELECTSTATE::RETRYSELECT:
      _graph_no = 1;
      //3�{�^�������������A���͎�t�t���O���^�Ȃ珈������
      if (g.GetTrg() & PAD_INPUT_3&&_input_flag==true) {
         //SE�Đ�
         PlaySoundMem(_se["Push"], DX_PLAYTYPE_BACK, true);
         _mode_cnt = _cnt;
         _input_flag = false;
         auto ob = new OverlayBlack();          //�t�F�[�h�A�E�g�̂��߂̃I�[�o�[���C�u���b�N���[�h����
         ob->SetFade(fadeoutframe, 90, 150, 5); //�t�F�[�h���Ԃ̐ݒ�
         g.GetMS()->Add(ob, 5, "OverlayBlack");
      }
      //�������A���t���[���o�����Ȃ珈������
      if (frame == fadeoutframe) {
         g.GetMS()->Del(this);                      //���̃��[�h���폜����
         g.GetMS()->Del(g.GetMS()->Get("Gameover"));//�Q�[���I�[�o�[���[�h���폜����
         g.GetMS()->Del(g.GetMS()->Get("OverLogo"));//�Q�[���I�[�o�[���S���폜����
         g.GetMS()->Del(g.GetMS()->Get("Game"));    //���[�h�Q�[�����폜����
         auto mg = new ModeGame();                  //���[�h�Q�[������
         g.GetMS()->Add(mg, 0, "Game");
      }
      //�E���͂������A���͎�t�t���O���^�Ȃ�^�C�g���I����Ԃֈڍs
      if (g.GetTrg() & PAD_INPUT_RIGHT && _input_flag == true) {
         PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
         _state = SELECTSTATE::GOTITLESELECT;
      }
      break;
      //�^�C�g���I�����
   case SELECTSTATE::GOTITLESELECT:
      _graph_no = 2;
      //3�{�^�������������A���͎�t�t���O���^�Ȃ珈������
      if (g.GetTrg() & PAD_INPUT_3 && _input_flag == true) {
         //SE�Đ�
         PlaySoundMem(_se["Push"], DX_PLAYTYPE_BACK, true);
         _mode_cnt = _cnt;
         _input_flag = false;
         auto ob =new OverlayBlack();          //�t�F�[�h�A�E�g�̂��߂̃I�[�o�[���C�u���b�N���[�h����
         ob->SetFade(fadeoutframe, 70, 70, 4); //�t�F�[�h���Ԃ̐ݒ�
         g.GetMS()->Add(ob, 5, "OverlayBlack");
      }
      //�������A���t���[���o�����Ȃ珈������
      if (frame== fadeoutframe) {
         g.GetMS()->Del(this);                      //���̃��[�h���폜����
         g.GetMS()->Del(g.GetMS()->Get("OverLogo"));//�Q�[���I�[�o�[���[�h���폜����
         g.GetMS()->Del(g.GetMS()->Get("Gameover"));//�Q�[���I�[�o�[���S���폜����
         g.GetMS()->Del(g.GetMS()->Get("Game"));    //���[�h�Q�[�����폜����
         auto mt = new ModeTitle();                 //���[�h�^�C�g������
         mt->SetTitlebg();                          //���[�h�^�C�g����Ԃ��^�C�g���w�i�ɐݒ�
         g.GetMS()->Add(mt, 0, "Title");
      }
      //�����͂������A���͎�t�t���O���^�Ȃ�^�C�g���I����Ԃֈڍs
      if (g.GetTrg() & PAD_INPUT_LEFT && _input_flag == true) {
         PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
         _state = SELECTSTATE::RETRYSELECT;
      }
      break;
   }
   return true;
}

bool OverSelect::Draw(Game& g) {
   base::Draw(g);
   return true;
}

