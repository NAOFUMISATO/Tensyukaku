/*****************************************************************//**
 * \file   ExplainController.cpp
 * \brief  ������ʗp�R���g���[���[�N���X�i���[�h�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ExplainController.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ModeTitle.h"

bool ExplainController::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 960;                //�w���W�̏�����
   _y = 540;                //�x���W�̏�����
   _trans_flag = true;      //�w�i���߃t���O��^�ŏ�����
   _grhandle = ResourceServer::LoadGraph("res/Mode/EXController.png");   //�摜�ǂݍ���
   return true;
}

bool ExplainController::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}

bool ExplainController::Process(Game& g) {
   base::Process(g);
   return true;
}

bool ExplainController::Draw(Game& g) {
   base::Draw(g);
   return true;
}