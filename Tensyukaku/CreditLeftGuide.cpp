/*****************************************************************//**
 * \file   CreditLeftGuide.cpp
 * \brief  ���X�e�B�b�N�K�C�h�{�^���N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Game.h"
#include "ResourceServer.h"
#include "CreditLeftGuide.h"

/*-----------���X�e�B�b�N�K�C�h�{�^���N���X-------------*/
/*-----������------*/
bool CreditLeftGuide::Initialize(Game& g) {
   _x = 1800;          //�w���W�̏�����
   _y = 100;           //�x���W�̏�����
   _pal = 255;         //�����x�̏�����
   _trans_flag = true; //�w�i���߃t���O��^�ŏ�����
   _grhandle = ResourceServer::LoadGraph("res/Mode/MoveGuide.png");   //�摜�ǂݍ���
   return true;
}
/*-----�I��------*/
bool CreditLeftGuide::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}
/*-----�X�V------*/
bool CreditLeftGuide::Process(Game& g) {
   base::Process(g);
   return true;
}
/*-----�`��------*/
bool CreditLeftGuide::Draw(Game& g) {
   SetDrawBlendMode(DX_BLENDMODE_ALPHA, _pal);
   DrawRotaGraph(_x, _y, 1.0, 0.0, _grhandle, _trans_flag, false);
   SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
   return true;
}