/*****************************************************************//**
 * \file   OverlayBlack.h
 * \brief  �t�F�[�h�A�E�g�t�F�[�h�C���̂��߂̍��w�i�N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
/** �t�F�[�h�A�E�g�t�F�[�h�C���̂��߂̍��w�i */
class OverlayBlack : public ModeBase
{
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
   /**
    * \brief                  �e�t�F�[�h�֌W��ݒ肷��֐�
    * \param fadeoutframe     �t�F�[�h�A�E�g�I���t���[��
    * \param fadeinbeginframe �t�F�[�h�C���J�n�t���[��
    * \param fadeinendframe   �t�F�[�h�C���I���t���[��
    * \param fadespeed        �t�F�[�h���x
    */
   void SetFade(int fadeoutframe,int fadeinbeginframe,int fadeinendframe, int fadespeed);
   /**
    * \brief       �����x�̒l��Ԃ��֐�
    * \return _pal �����x�̒l
    */
   int GetPal() { return _pal; }

private:
   int _fadeout_frame;     //!< �t�F�[�h�A�E�g���I���t���[����ݒ肷��ϐ�
   int _fadein_beginframe; //!< �t�F�[�h�C���J�n�t���[����ݒ肷��ϐ�
   int _fadein_endframe;   //!< �t�F�[�h�C���I���t���[����ݒ肷��ϐ�
   int _fade_speed;        //!< �t�F�[�h�X�s�[�h��ݒ肷��ϐ�
};