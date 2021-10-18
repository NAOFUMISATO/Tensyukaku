/*****************************************************************//**
 * \file   ModeExPlain.cpp
 * \brief  �^�C�g���ł̐�����ʃN���X�i���[�h�x�[�X�̃T�u�N���X�j�A������ʗp�R���g���[���[�N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModeExPlain.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ModeTitle.h"
 /*-----������------*/
bool ModeExPlain::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 960;      //X���W�̏�����
   _y = 540;      //Y���W�̏�����
   _cnt = 6;      //5�t���[���Ń��[�h�폜�̂��߁A����J�E���^6�ŏ�����
   _grhandle = ResourceServer::LoadGraph("res/Mode/Black.png");   //�ڂ��������p�̍��摜�ǂݍ���
   auto pc = new EXController();   //������ʗp�R���g���[���[�N���X�̃C���X�^���X����
   g.GetMS()->Add(pc, 3, "EXController");
   return true;
}
/*-----�I��------*/
bool ModeExPlain::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}
/*-----�X�V------*/
bool ModeExPlain::Process(Game& g) {
   base::Process(g);
   auto frame = _cnt - _mode_cnt;
   //4�{�^�������Ńt���[�����Z�b�g
   if (g.GetTrg() & PAD_INPUT_4) {
      _mode_cnt = _cnt;
   }
   //5�t���[���o�����Ȃ烂�[�h�폜�A�^�C�g�����[�h�̏������ĊJ����
   if (frame == 5) {
      auto mt = (ModeTitle*)g.GetMS()->Get("Title");
      mt->SetStopObjProcess(false);
      g.GetMS()->Del(this);
      g.GetMS()->Del(g.GetMS()->Get("EXController"));
   }
   return true;
}
/*-----�`��------*/
bool ModeExPlain::Draw(Game& g) {
   base::Draw(g);
   return true;
}

/*-----------������ʗp�R���g���[���[�N���X-------------*/
 /*-----������------*/
bool EXController::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 960;                //�w���W�̏�����
   _y = 540;                //�x���W�̏�����
   _trans_flag = true;      //�w�i���߃t���O��^�ŏ�����
   _grhandle = ResourceServer::LoadGraph("res/Mode/EXController.png");   //�摜�ǂݍ���
   return true;
}

bool EXController::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}
/*-----�X�V------*/
bool EXController::Process(Game& g) {
   base::Process(g);
   return true;
}
/*-----�`��------*/
bool EXController::Draw(Game& g) {
   base::Draw(g);
   return true;
}