/*****************************************************************//**
 * \file   ModePause.cpp
 * \brief  �C���Q�[���ł̃|�[�Y��ʃN���X�i���[�h�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModePause.h"
#include "ModeGame.h"
#include "PauseSelect.h"
#include "PauseController.h"
#include "Game.h"
#include "ResourceServer.h"

bool ModePause::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 960;           //X���W�̏�����
   _y = 540;           //Y���W�̏�����
   _pal = 200;         //�����x�̏�����
   _mode_cnt = _cnt;   //�t���[���̏�����
   _grhandle = ResourceServer::LoadGraph("res/Mode/Black.png");         //�摜�ǂݍ��݁i�ڂ��������̂��߁A���w�i�j
   _se["Appear"] = ResourceServer::LoadSoundMem("se/OutGame/Pause.wav");//SE�ǂݍ���
   _vpal["Appear"] = 255;                                               //SE���ʏ�����
   ChangeVolumeSoundMem(_vpal["Appear"], _se["Appear"]);                //SE���ʕύX
   PlaySoundMem(_se["Appear"], DX_PLAYTYPE_BACK, true);                 //SE�Đ�
   auto ps = new PauseSelect();      //�|�[�Y�Z���N�g����
   g.GetMS()->Add(ps, 25, "PSelect");   
   auto pc = new PController();      //�|�[�Y��ʗp�R���g���[���[����
   g.GetMS()->Add(pc, 25, "PController");
   return true;
}

bool ModePause::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}

bool ModePause::Process(Game& g) {
   base::Process(g);
   return true;
}

bool ModePause::Draw(Game& g) {
   base::Draw(g);
   return true;
}