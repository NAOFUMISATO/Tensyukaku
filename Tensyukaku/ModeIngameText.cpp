/*****************************************************************//**
 * \file   ModeIngameText.cpp
 * \brief  �C���Q�[���ł̊K�w�\���N���X�i���[�h�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ResourceServer.h"
#include "Game.h"
#include "ModeIngameText.h"
#include "ModeGame.h"

using namespace ITInfo;
/*-----������------*/
bool ModeIngameText::Initialize(Game& g) {
   if (!base::Initialize(g)) { return false; }
   _x = 960;                       //X���W������
   _y = 250;                       //Y���W������
   _pal = 0;                       //�t�F�[�h�C�����Ă������߁A�����x�O�ŏ�����
   _fadein_frame = FADEIN_FRAME;   //�K�w�ɂ���ăt�F�[�h�C���t���[�����قȂ邽�߁A�����o�ϐ��ŏ�����
   _fadeout_frame = FADEOUT_FRAME; //�K�w�ɂ���ăt�F�[�h�A�E�g�t���[�����قȂ邽�߁A�����o�ϐ��ŏ�����
   _fade_speed=FADE_SPEED;         //�K�w�ɂ���ăt�F�[�h�X�s�[�h���قȂ邽�߁A�����o�ϐ��ŏ�����
   _mode_cnt = _cnt;               //�t���[���̏�����
   _trans_flag = true;             //�w�i���߃t���O��^�ŏ�����
   LoadPicture();                  //�摜�ǂݍ���
   return true;
}
/*-----�I��------*/
bool ModeIngameText::Terminate(Game& g) {
   base::Terminate(g);
   return true;
}
/*-----�X�V------*/
bool ModeIngameText::Process(Game& g) {
   base::Process(g);
   auto frame = _cnt - _mode_cnt;
   //�e�K�w�ɂ���ĉ摜&�t�F�[�h�֌W�̕ύX
   if (_text_type == "TOP") {
      _grhandle = _grall["TOP"][0];
   }
   else if (_text_type == "UPPER") {
      _grhandle = _grall["UPPER"][0];
   }
   else if (_text_type == "MIDDLE") {
      _grhandle = _grall["MIDDLE"][0];
   }
   else if (_text_type == "UNDER") {
      _grhandle = _grall["UNDER"][0];
      _fadeout_frame = 80;
      _fade_speed = 6;
   }
   //�t�F�[�h�C���̏���
   if (frame < _fadein_frame) {
      _pal += _fade_speed;
   }
   if (frame == _fadein_frame) {
      _pal = 255;
   }
   //�t�F�[�h�A�E�g�̏���
   if (frame >= _fadeout_frame&&_pal>0) {
      _pal -= _fade_speed;
   }
   if (frame >= _fadeout_frame && _pal <= 0) {
      g.GetMS()->Del(this);
   }
   return true;
}
/*-----�`��------*/
bool ModeIngameText::Draw(Game& g) {
   base::Draw(g);
   return true;
}
//�摜�ǂݍ��݊֐�
void  ModeIngameText::LoadPicture() {
   _grall["TOP"].resize(1);
   ResourceServer::LoadDivGraph("res/Mode/IngameText04.png", 1, 1, 1,GRAPH_WIDTH,GRAPH_HEIGHT,_grall["TOP"].data());
   _grall["UPPER"].resize(1);
   ResourceServer::LoadDivGraph("res/Mode/IngameText03.png", 1, 1, 1, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["UPPER"].data());
   _grall["MIDDLE"].resize(1);
   ResourceServer::LoadDivGraph("res/Mode/IngameText02.png", 1, 1, 1, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["MIDDLE"].data());
   _grall["UNDER"].resize(1);
   ResourceServer::LoadDivGraph("res/Mode/IngameText01.png", 1, 1, 1, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["UNDER"].data());
}
