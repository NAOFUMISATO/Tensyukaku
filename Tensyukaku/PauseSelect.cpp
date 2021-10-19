/*****************************************************************//**
 * \file   PauseSelect.cpp
 * \brief  �|�[�Y�Z���N�g�N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "PauseSelect.h"
#include "Game.h"
#include "ModeTitle.h"
#include "ModeGame.h"
#include "OverlayBlack.h"
#include "ResourceServer.h"
#include "ObjectBase.h"

bool PauseSelect::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 960;                       //X���W�̏�����
   _y = 850;                       //Y���W�̏�����
   _graph_no = 0;                  //�V�[�g�ԍ��O�ŏ�����
   _state = SELECTSTATE::NOSELECT; //�����I�����Ă��Ȃ���Ԃŏ�����
   _trans_flag = true;             //�w�i���߃t���O��^�ŏ�����
   _input_flag = true;             //���͎�t�t���O��^�ŏ�����
   //�摜�ǂݍ���
   _grall["PSelect"].resize(3);
   ResourceServer::LoadDivGraph("res/Mode/PauseSelect.png",3,3,1,1230,275,_grall["PSelect"].data());
   //SE�ǂݍ���
   _se["Select"] = ResourceServer::LoadSoundMem("se/OutGame/OtherSelectPush.wav");
   _se["Push"] = ResourceServer::LoadSoundMem("se/OutGame/GameStartPush.wav");
   //SE���ʏ�����
   _vpal["Select"] = 125;
   _vpal["Push"] =200;
   return true;
}

bool PauseSelect::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}

bool PauseSelect::Process(Game& g) {
   base::Process(g);
   //SE���ʕύX
   ChangeVolumeSoundMem(_vpal["Select"], _se["Select"]);
   ChangeVolumeSoundMem(_vpal["Push"], _se["Push"]);
   auto frame = _cnt - _mode_cnt;
   auto fadeoutframe = 60;
   _grhandle = _grall["PSelect"][_anime["PSelect"]];
   _anime["PSelect"] = _graph_no;
   /*-----�e��Ԗ��̏���-----*/
   switch (_state) {
      //�����I�����Ă��Ȃ����
   case SELECTSTATE::NOSELECT:
      _graph_no = 0;
      //�����͂����Ȃ烊�g���C�I����Ԃֈڍs
      if (g.GetTrg() & PAD_INPUT_LEFT) {
         //SE�Đ�
         PlaySoundMem(_se["Select"],DX_PLAYTYPE_BACK,true);
         _state = SELECTSTATE::RETURNSELECT;
      }
      //�E���͂����Ȃ烊�g���C�I����Ԃֈڍs
      if (g.GetTrg() & PAD_INPUT_RIGHT) {
         //SE�Đ�
         PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
         _state = SELECTSTATE::GOTITLESELECT;
      }
      break;
      //�Q�[���ɖ߂�I�����
   case SELECTSTATE::RETURNSELECT:
      _graph_no = 1;
      //3�{�^�������������A���͎�t�t���O���^�Ȃ珈������
      if (g.GetTrg() & PAD_INPUT_3&&_input_flag==true) {
         //SE�Đ�
         PlaySoundMem(_se["Push"], DX_PLAYTYPE_BACK, true);
         _input_flag = false;
         _mode_cnt = _cnt;
      }
      //�����Ɠ����ɃA�N�V�������s��Ȃ����߂�1�t���[���󂯂ď�������
      if (frame == 1 && _input_flag == false) {
         g.GetMS()->Del(this);                            //���̃��[�h�̍폜
         g.GetMS()->Del(g.GetMS()->Get("Pause"));         //�|�[�Y���[�h�폜
         g.GetMS()->Del(g.GetMS()->Get("PController"));   //�|�[�Y��ʗp�R���g���[���[���폜
         auto mg = (ModeGame*)g.GetMS()->Get("Game");
         mg->SetStopObjProcess(false);                    //���[�h�Q�[���̏������ĊJ
      }
      //�E���͂������A���͎�t�t���O���^�Ȃ烊�g���C�I����Ԃֈڍs
      if (g.GetTrg() & PAD_INPUT_RIGHT && _input_flag == true) {
         //SE�Đ�
         PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
         _state = SELECTSTATE::GOTITLESELECT;
      }
      break;
      //�^�C�g���I�����
   case SELECTSTATE::GOTITLESELECT:
      _graph_no = 2;
      //3�{�^�������������A���͎�t�t���O���^�Ȃ珈������
      if (g.GetTrg() & PAD_INPUT_3&&_input_flag==true) {
         //SE�Đ�
         PlaySoundMem(_se["Push"], DX_PLAYTYPE_BACK, true);
         _input_flag =false;
         _mode_cnt = _cnt;
         g.GetMS()->Del(g.GetMS()->Get("Flame"));         //�����o���[�h�̍폜
         auto ob = new OverlayBlack();                    //�t�F�[�h�A�E�g�ׂ̈́A�I�[�o���C�u���b�N���[�h����
         ob->SetFade(fadeoutframe,180, 240, 5);           //�t�F�[�h���Ԃ̐ݒ�
         g.GetMS()->Add(ob, 30, "OverlayBlack");
      }
      //���������t���[���o�ߌ�A��������
      if (frame == fadeoutframe && _input_flag == false) {
         g.GetMS()->Del(this);                            //���̃��[�h�̍폜
         g.GetMS()->Del(g.GetMS()->Get("PController"));   //������ʗp�R���g���[���[�폜
         g.GetMS()->Del(g.GetMS()->Get("Pause"));         //���[�h�|�[�Y�폜
         auto mg = (ModeGame*)g.GetMS()->Get("Game");
         mg->SetStopObjProcess(false);                    //�Q�[���̏������ĊJ����
         TutorialDel(g);                                  //�`���[�g���A���{�[�h�ɓ������Ă����Ȃ烂�[�h�`���[�g���A�����폜����
         g.GetMS()->Del(g.GetMS()->Get("Game"));          //���[�h�Q�[�����폜����
         auto mt = new ModeTitle();                       //���[�h�^�C�g������
         mt->SetTitlebg();                                //�^�C�g����Ԃ��^�C�g���w�i�ɐݒ�
         g.GetMS()->Add(mt, 0, "Title");
         //�e�����̒�~
         StopSoundMem(g.GetBgm()["Main"]);
         StopSoundMem(g.GetBgm()["Flame"]);
         StopSoundMem(g.GetBgm()["Boss"]);
      }
      //�����͂������A���͎�t�t���O���^�Ȃ烊�g���C�I����Ԃֈڍs
      if(g.GetTrg() & PAD_INPUT_LEFT && _input_flag == true) {
         PlaySoundMem(_se["Select"], DX_PLAYTYPE_BACK, true);
         _state = SELECTSTATE::RETURNSELECT;
      }
      break;
   }
   return true;
}

bool PauseSelect::Draw(Game& g) {
   base::Draw(g);
   return true;
}

void PauseSelect::TutorialDel(Game& g) {
    g.GetMS()->Del(g.GetMS()->Get("1A"));
    g.GetMS()->Del(g.GetMS()->Get("1B"));
    g.GetMS()->Del(g.GetMS()->Get("2A"));
    g.GetMS()->Del(g.GetMS()->Get("3A"));
    g.GetMS()->Del(g.GetMS()->Get("3B"));
    g.GetMS()->Del(g.GetMS()->Get("4A"));
    g.GetMS()->Del(g.GetMS()->Get("5A"));
}

