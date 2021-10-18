/*****************************************************************//**
 * \file   ModePrologue.h
 * \brief  �v�����[�O�N���X�i���[�h�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
/** �v�����[�O */
class  ModePrologue :public ModeBase {
   typedef ModeBase base;
public:
   /**
    * \brief   �������֐�
    * \param g �Q�[���N���X�̎Q��
    */
   virtual bool Initialize(Game& g);
   /**
    * \brief   �I���֐�
    * \param g �Q�[���N���X�̎Q��
    */
   virtual bool Terminate(Game& g);
   /**
    * \brief   �X�V�֐�
    * \param g �Q�[���N���X�̎Q��
    */
   virtual bool Process(Game& g);
   /**
    * \brief   �`��֐�
    * \param g �Q�[���N���X�̎Q��
    */
   virtual bool Draw(Game& g);
private:
   int _graph_no;      //!< �V�[�g�ԍ�
};
/** �v�����[�O�N���X�p�萔 */
namespace ProInfo {
   constexpr auto BG1_FADEIN_FRAME = 120;    //!< �w�i�t�F�[�h�C���t���[��
   constexpr auto BG1_FADEIN_SPEED = 2;      //!< �w�i�t�F�[�h�C�����x
   constexpr auto TEXT1_FADEIN_FRAME = 60;   //!< �e�L�X�g1�̃t�F�[�h�C���t���[��
   constexpr auto TEXT_FADE_SPEED = 4;       //!< �e�L�X�g�̃t�F�[�h���x
   constexpr auto TEXT1_FADEOUT_BEGINFRAME = 550+ TEXT1_FADEIN_FRAME;                       //!< �e�L�X�g�P�̃t�F�[�h�A�E�g�J�n�t���[��
   constexpr auto TEXT1_FADEOUT_ENDFRAME   = 60+ TEXT1_FADEOUT_BEGINFRAME;                  //!< �e�L�X�g�P�̃t�F�[�h�A�E�g�I���t���[��
   constexpr auto TEXT2_FADEIN_BEGINFRAME  = 60 + TEXT1_FADEOUT_ENDFRAME;                   //!< �e�L�X�g�Q�̃t�F�[�h�C���J�n�t���[��
   constexpr auto TEXT2_FADEIN_ENDFRAME    = 60 + TEXT2_FADEIN_BEGINFRAME;                  //!< �e�L�X�g�Q�̃t�F�[�h�C���I���t���[��
   constexpr auto TEXT2_FADEOUT_BEGINFRAME = 480+ TEXT2_FADEIN_ENDFRAME;                    //!< �e�L�X�g�Q�̃t�F�[�h�A�E�g�J�n�t���[��
   constexpr auto TEXT2_FADEOUT_ENDFRAME   = 60 + TEXT2_FADEOUT_BEGINFRAME;                 //!< �e�L�X�g�Q�̃t�F�[�h�A�E�g�I���t���[��
   constexpr auto TEXT3_FADEIN_BEGINFRAME  = 60 + TEXT2_FADEOUT_ENDFRAME;                   //!< �e�L�X�g�R�̃t�F�[�h�C���J�n�t���[��
   constexpr auto TEXT3_FADEIN_ENDFRAME    = 60 + TEXT3_FADEIN_BEGINFRAME;                  //!< �e�L�X�g�R�̃t�F�[�h�C���I���t���[��
   constexpr auto TEXT3_FADEOUT_BEGINFRAME = 350 + TEXT3_FADEIN_ENDFRAME;                   //!< �e�L�X�g�R�̃t�F�[�h�A�E�g�J�n�t���[��
   constexpr auto TEXT3_FADEOUT_ENDFRAME   = 60 + TEXT3_FADEOUT_BEGINFRAME;                 //!< �e�L�X�g�R�̃t�F�[�h�A�E�g�I���t���[��
   constexpr auto TEXT4_FADEIN_BEGINFRAME  = 60 + TEXT3_FADEOUT_ENDFRAME;                   //!< �e�L�X�g�S�̃t�F�[�h�C���J�n�t���[��
   constexpr auto TEXT4_FADEIN_ENDFRAME    = 60 + TEXT4_FADEIN_BEGINFRAME;                  //!< �e�L�X�g�S�̃t�F�[�h�C���I���t���[��
   constexpr auto TEXT4_FADEOUT_BEGINFRAME = 650 + TEXT4_FADEIN_ENDFRAME;                   //!< �e�L�X�g�S�̃t�F�[�h�A�E�g�J�n�t���[��
   constexpr auto TEXT4_FADEOUT_ENDFRAME   = 60 + TEXT4_FADEOUT_BEGINFRAME;                 //!< �e�L�X�g�S�̃t�F�[�h�A�E�g�I���t���[��
   constexpr auto BG1_FADEOUT_BEGINFRAME   = 0 + TEXT4_FADEOUT_ENDFRAME + BG1_FADEIN_FRAME; //!< �w�i�̃t�F�[�h�A�E�g�J�n�t���[��
   constexpr auto BG1_FADEOUT_ENDFRAME     = 60 + BG1_FADEOUT_BEGINFRAME;                   //!< �w�i�̃t�F�[�h�A�E�g�I���t���[��
   constexpr auto BG1_FADEOUT_SPEED = 4;                                                    //!< �w�i�̃t�F�[�h���x
   constexpr auto BG2_FADEIN_BEGINFRAME    = 60 + BG1_FADEOUT_ENDFRAME;                     //!< �w�i2���ڂ̃t�F�[�h�C���J�n�t���[��
   constexpr auto BG2_FADEIN_ENDFRAME      = 60 + BG2_FADEIN_BEGINFRAME;                    //!< �w�i2���ڂ̃t�F�[�h�C���I���t���[��
   constexpr auto BG2_FADEIN_SPEED = 4;                                                     //!< �w�i2���ڂ̃t�F�[�h���x
   constexpr auto TEXT5_FADEIN_BEGINFRAME  = 60 + BG2_FADEIN_ENDFRAME- BG1_FADEIN_FRAME;    //!< �e�L�X�g�T�̃t�F�[�h�C���J�n�t���[��
   constexpr auto TEXT5_FADEIN_ENDFRAME    = 60 + TEXT5_FADEIN_BEGINFRAME;                  //!< �e�L�X�g�T�̃t�F�[�h�C���I���t���[��
   constexpr auto TEXT5_FADEOUT_BEGINFRAME = 550 + TEXT5_FADEIN_ENDFRAME;                   //!< �e�L�X�g�T�̃t�F�[�h�A�E�g�J�n�t���[��
   constexpr auto TEXT5_FADEOUT_ENDFRAME   = 60 + TEXT5_FADEOUT_BEGINFRAME;                 //!< �e�L�X�g�T�̃t�F�[�h�A�E�g�I���t���[��
   constexpr auto PROLOGUE_FADEOUT_FRAME   = 120 + TEXT5_FADEOUT_ENDFRAME;                  //!< �v�����[�O�̃t�F�[�h�A�E�g�J�n�t���[��
   /*-----------�w�i�ړ��t���[���֌W----------*/
   constexpr auto BG_XMOVE_FRAME = 700+BG1_FADEIN_FRAME;                                    //!< �w�i���ړ��J�n�t���[��
   constexpr auto BG_YMOVE_FRAME = 1660+ BG1_FADEIN_FRAME;                                  //!< �w�i�c�ړ��J�n�t���[��
   constexpr auto BG_XMOVE_LIMIT = 3840;                                                    //!< �w�i���ړ����E�l
   constexpr auto BG_YMOVE_LIMIT = 2160;                                                    //!< �w�i�c�ړ����E�l
   constexpr auto BG_XMOVE_SPEED = 2;                                                       //!< �w�i���ړ����x
   constexpr auto BG_YMOVE_SPEED = 1;                                                       //!< �w�i�c�ړ����x
   /*---------�w�i&�e�L�X�g�̉摜�`��֌W----------*/
   constexpr auto BG_GRAPH_WIDTH = 3840;      //1��������̉摜�T�C�Y�i���j
   constexpr auto BG_GRAPH_HEIGHT = 2160;     //1��������̉摜�T�C�Y�i�c�j
   constexpr auto BG_GRAPHNAME = "res/Mode/PrologueAll.png";   //�摜�t�@�C����
   constexpr auto BG_ANIMEMAX = 2;            //�S�Ẳ摜����
   constexpr auto BG_WIDTHCOUNT = 2;          //���̉摜����
   constexpr auto BG_HEIGHTCOUNT = 1;         //�c�̉摜����

   constexpr auto TEXT_GRAPH_WIDTH = 420;      //1��������̉摜�T�C�Y�i���j
   constexpr auto TEXT_GRAPH_HEIGHT = 910;     //1��������̉摜�T�C�Y�i�c�j
   constexpr auto TEXT_GRAPHNAME = "res/Mode/AllPText.png";   //�摜�t�@�C����
   constexpr auto TEXT_ANIMEMAX = 5;           //�S�Ẳ摜����
   constexpr auto TEXT_WIDTHCOUNT = 5;         //���̉摜����
   constexpr auto TEXT_HEIGHTCOUNT = 1;        //�c�̉摜����
   /*---------�X�L�b�v�e�L�X�g�֌W---------*/
   constexpr auto SKIP_FADEOUT_FRAME = 550;    //�t�F�[�h�A�E�g����t���[��
   constexpr auto SKIP_FADESPEED = 5;          //�t�F�[�h�X�s�[�h
}