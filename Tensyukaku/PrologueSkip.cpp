/*****************************************************************//**
 * \file   PrologueSkip.cpp
 * \brief  �X�L�b�v�e�L�X�g�N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModePrologue.h"
#include "PrologueSkip.h"
#include "ModeGame.h"
#include "Game.h"
#include "OverlayBlack.h"
#include "ResourceServer.h"

using namespace ProInfo;
 /*----�X�L�b�v�e�L�X�g�N���X-----*/
 /*-----������-----*/
bool PrologueASkip::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 1700;          //X���W�̏�����
   _y = 1030;          //Y���W�̏�����
   _trans_flag = true; //�w�i���߃t���O��^�ŏ�����
   _mode_cnt = _cnt;   //�t���[���̏�����
   _grhandle = ResourceServer::LoadGraph("res/Mode/PrologueSkip.png");   //�摜�ǂݍ���
   return true;
}
/*-----�I��------*/
bool PrologueASkip::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}
/*-----�X�V-----*/
bool PrologueASkip::Process(Game& g) {
   base::Process(g);
   auto frame = _cnt - _mode_cnt;
   //���t���[���o������t�F�[�h�A�E�g
   if (frame >= SKIP_FADEOUT_FRAME) {
      _pal -= SKIP_FADESPEED;
   }
   if (_pal == 0) {
      g.GetMS()->Del(this);    //���̃��[�h���폜
   }
   return true;
}
/*-----�`��-----*/
bool PrologueASkip::Draw(Game& g) {
   base::Draw(g);
   return true;
}
