/*****************************************************************//**
 * \file   ModeTutorial.h
 * \brief  �C���Q�[���ł̃`���[�g���A���N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
/** �`���[�g���A�� */
class  ModeTutorial :public ModeBase {
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
    * \brief              �`���[�g���A���̎�ʂ�ݒ肷��֐�
    * \param tutorialtype �`���[�g���A���̎��
    */
   void SetType(std::string tutorialtype) { _tutorial_type = tutorialtype; }
private:
   /**
    * \brief �摜�ǂݍ��݊֐�
    */
   void LoadPicture();
   std::string _tutorial_type;   //!< �`���[�g���A���̎�ʕϐ�
};
/** ���[�h�`���[�g���A���N���X�p�萔 */
namespace TuInfo {
   constexpr auto GRAPH_WIDTH = 880;    //!< �摜�T�C�Y����
   constexpr auto GRAPH_HEIGHT = 470;   //!< �摜�T�C�Y�c��
}