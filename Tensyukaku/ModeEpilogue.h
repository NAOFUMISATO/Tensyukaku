/*****************************************************************//**
 * \file   ModeEpilogue.h
 * \brief  �G�s���[�O�N���X�i���[�h�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
/** �G�s���[�O */
class  ModeEpilogue :public ModeBase {
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
};
/** �G�s���[�O�N���X�p�萔 */
namespace EpiInfo {
   constexpr auto BG_FADEIN_FRAME = 120;       //!< �w�i�t�F�[�h�C���t���[��
   constexpr auto BG_FADEIN_SPEED = 2;         //!< �w�i�t�F�[�h�C�����x
   constexpr auto TEXT1_FADEIN_FRAME = 120;    //!< �e�L�X�g1�̃t�F�[�h�C���t���[��
   constexpr auto TEXT_FADE_SPEED = 3;         //!< �e�L�X�g�̃t�F�[�h���x
   constexpr auto TEXT_FIRST_XPOSITION = 500;  //!< �e�L�X�g�̏����w���W
   constexpr auto TEXT_MOVE_SPEED = 2;         //!< �e�L�X�g�̈ړ����x
   constexpr auto TEXT1_FADEOUT_BEGINFRAME= 180 + TEXT1_FADEIN_FRAME;                      //!< �e�L�X�g�P�̃t�F�[�h�A�E�g�J�n�t���[��
   constexpr auto TEXT1_FADEOUT_ENDFRAME  = 120 + TEXT1_FADEOUT_BEGINFRAME;                //!< �e�L�X�g�P�̃t�F�[�h�A�E�g�I���t���[��
   constexpr auto TEXT2_FADEIN_BEGINFRAME = 60 + TEXT1_FADEOUT_ENDFRAME;                   //!< �e�L�X�g�Q�̃t�F�[�h�C���J�n�t���[��
   constexpr auto TEXT2_FADEIN_ENDFRAME   = 120 + TEXT2_FADEIN_BEGINFRAME;                 //!< �e�L�X�g�Q�̃t�F�[�h�C���I���t���[��
   constexpr auto TEXT2_FADEOUT_BEGINFRAME= 450 + TEXT2_FADEIN_ENDFRAME;                   //!< �e�L�X�g�Q�̃t�F�[�h�A�E�g�J�n�t���[��
   constexpr auto TEXT2_FADEOUT_ENDFRAME = 120 + TEXT2_FADEOUT_BEGINFRAME;                 //!< �e�L�X�g�Q�̃t�F�[�h�A�E�g�I���t���[��
   constexpr auto TEXT3_FADEIN_BEGINFRAME = 60 + TEXT2_FADEOUT_ENDFRAME;                   //!< �e�L�X�g�R�̃t�F�[�h�C���J�n�t���[��
   constexpr auto TEXT3_FADEIN_ENDFRAME = 120 + TEXT3_FADEIN_BEGINFRAME;                   //!< �e�L�X�g�R�̃t�F�[�h�C���I���t���[��
   constexpr auto TEXT3_FADEOUT_BEGINFRAME= 240 + TEXT3_FADEIN_ENDFRAME;                   //!< �e�L�X�g�R�̃t�F�[�h�A�E�g�J�n�t���[��
   constexpr auto TEXT3_FADEOUT_ENDFRAME = 120 + TEXT3_FADEOUT_BEGINFRAME;                 //!< �e�L�X�g�R�̃t�F�[�h�A�E�g�I���t���[��
   constexpr auto TEXT4_FADEIN_BEGINFRAME = 60 + TEXT3_FADEOUT_ENDFRAME;                   //!< �e�L�X�g�S�̃t�F�[�h�C���J�n�t���[��
   constexpr auto TEXT4_FADEIN_ENDFRAME = 120 + TEXT4_FADEIN_BEGINFRAME;                   //!< �e�L�X�g�S�̃t�F�[�h�C���I���t���[��
   constexpr auto TEXT4_FADEOUT_BEGINFRAME= 330 + TEXT4_FADEIN_ENDFRAME;                   //!< �e�L�X�g�S�̃t�F�[�h�A�E�g�J�n�t���[��
   constexpr auto TEXT4_FADEOUT_ENDFRAME = 120 + TEXT4_FADEOUT_BEGINFRAME;                 //!< �e�L�X�g�S�̃t�F�[�h�A�E�g�I���t���[��
   constexpr auto BG_FADEOUT_BEGINFRAME   = 60 + TEXT4_FADEOUT_ENDFRAME + BG_FADEIN_FRAME; //!< �w�i�̃t�F�[�h�A�E�g�J�n�t���[��
   constexpr auto BG_FADEOUT_ENDFRAME     = 60 + BG_FADEOUT_BEGINFRAME;                    //!< �w�i�̃t�F�[�h�A�E�g�I���t���[��
   constexpr auto BG_FADEOUT_SPEED = 4;                                                    //!< �w�i�̃t�F�[�h�A�E�g���x

   /*---------�e�L�X�g�̉摜�`��֌W----------*/
   constexpr auto TEXT_GRAPH_WIDTH = 260;   //!< 1��������̉摜�T�C�Y�i���j
   constexpr auto TEXT_GRAPH_HEIGHT = 529;  //!< 1��������̉摜�T�C�Y�i�c�j
   constexpr auto TEXT_GRAPHNAME = "res/Mode/AllEText.png"; //!< �摜�t�@�C����
   constexpr auto TEXT_ANIMEMAX = 4;        //!< �S�Ẳ摜����
   constexpr auto TEXT_WIDTHCOUNT = 4;      //!< ���̉摜����
   constexpr auto TEXT_HEIGHTCOUNT = 1;     //!< �c�̉摜����
}