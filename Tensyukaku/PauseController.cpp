/*****************************************************************//**
 * \file   PauseController.cpp
 * \brief  �|�[�Y��ʂɕ\������R���g���[���[�N���X�i���[�h�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author 0117H
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModeGame.h"
#include "PauseController.h"
#include "Game.h"
#include "ResourceServer.h"
/*-----------�|�[�Y��ʗp�R���g���[���[�N���X-------------*/
/*-----������-----*/
bool PController::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 960;              //X���W�̏�����
   _y = 400;              //Y���W�̏�����
   _pal = 255;            //�����x�̏�����
   _mode_cnt = _cnt;      //�t���[���̏�����
   _trans_flag = true;    //�w�i���߃t���O��^�ŏ�����
   _grhandle = ResourceServer::LoadGraph("res/Mode/PController.png");  //�摜�ǂݍ���
   return true;
}
/*-----�I��------*/
bool PController::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}
/*-----�X�V-----*/
bool PController::Process(Game& g) {
   base::Process(g);
   return true;
}
/*-----�`��-----*/
bool PController::Draw(Game& g) {
   base::Draw(g);
   return true;
}
