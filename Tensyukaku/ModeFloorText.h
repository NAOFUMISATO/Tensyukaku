/*****************************************************************//**
 * \file   ModeFloorText.h
 * \brief  �K�w�\���N���X�i���[�h�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
/** �K�w�\�� */
class  ModeFloorText :public ModeBase {
   typedef ModeBase base;
public:
   /**
     * \brief   �������֐�
     * \param g �Q�[���N���X�̎Q��
     */
   virtual bool Initialize(Game& g);
   /**
     * \brief   �������֐�
     * \param g �Q�[���N���X�̎Q��
     */
   virtual bool Terminate(Game& g);
   /**
     * \brief   �������֐�
     * \param g �Q�[���N���X�̎Q��
     */
   virtual bool Process(Game& g);
   /**
     * \brief   �������֐�
     * \param g �Q�[���N���X�̎Q��
     */
   virtual bool Draw(Game& g);
   /**
    * \brief          �e�L�X�g�̎�ނ�ݒ肷��֐�
    * \param texttype �e�L�X�g�̎��
    */
   void SetType(std::string texttype) { _text_type = texttype; }
private:
   /**
    * \brief �摜�ǂݍ��݊֐�
    */
   void LoadPicture();

   std::string _text_type; //!< �e�L�X�g�̎��
   int _fadein_frame;      //!< �t�F�[�h�C������t���[�����w�肷��ϐ�
   int _fadeout_frame;     //!< �t�F�[�h�A�E�g����t���[�����w�肷��ϐ�
   int _fade_speed;        //!< �t�F�[�h�̃X�s�[�h���w�肷��ϐ�
};
/** �K�w�\���N���X�p�萔 */
namespace MFTInfo {
   constexpr auto GRAPH_WIDTH = 1120;  //1��������̉摜�T�C�Y�i���j
   constexpr auto GRAPH_HEIGHT = 265;  //1��������̉摜�T�C�Y�i�c)
   constexpr auto FADEIN_FRAME = 60;   //�t�F�[�h�C���t���[��
   constexpr auto FADEOUT_FRAME = 180; // �t�F�[�h�A�E�g�t���[��
   constexpr auto FADE_SPEED = 4;      // �t�F�[�h�A�E�g�t���[��

}