/*****************************************************************//**
 * \file   CreditRedReturn.cpp
 * \brief  �ԃ{�^���K�C�h�N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Game.h"
#include "ResourceServer.h"
#include "CreditRedReturn.h"

/*-----------�ԃ{�^���K�C�h�N���X-------------*/
/*-----������------*/
bool CreditRedReturn::Initialize(Game& g) {
   _x = 1750;          //�w���W�̏�����
   _y = 980;           //�x���W�̏�����
   _pal = 255;         //�����x�̏�����
   _trans_flag = true; //�w�i���߃t���O��^�ŏ�����
   _grhandle = ResourceServer::LoadGraph("res/Mode/RedReturn.png");   //�摜�ǂݍ���
   return true;
}
/*-----�I��------*/
bool CreditRedReturn::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}
/*-----�X�V------*/
bool CreditRedReturn::Process(Game& g) {
   base::Process(g);
   return true;
}
/*-----�`��------*/
bool CreditRedReturn::Draw(Game& g) {
   SetDrawBlendMode(DX_BLENDMODE_ALPHA, _pal);
   DrawRotaGraph(_x, _y, 1.0, 0.0, _grhandle, _trans_flag, false);
   SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
   return true;
}