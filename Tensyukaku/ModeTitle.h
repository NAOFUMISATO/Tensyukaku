/*****************************************************************//**
 * \file   ModeTitle.h
 * \brief  ���[�h�^�C�g���N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include   "ModeBase.h"
/** �^�C�g�� */
class ModeTitle : public ModeBase
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
    * \brief �^�C�g���̎�ʂ��^�C�g���w�i�ɐݒ肷��֐�
    */
   void SetTitlebg() { _type = TITLETYPE::TITLEBG; }
    /**
     * \brief                �I�u�W�F�N�g�����̃X�g�b�v����̐ݒ�֐�
     * \param stopobjprocess �I�u�W�F�N�g�����̃X�g�b�v����
     */
   void SetStopObjProcess(bool stopobjprocess) { _stop_obj_process = stopobjprocess; }

private:
   /** �^�C�g���̎�ʗ� */
   enum class TITLETYPE { 
      AMGLOGO,       //!< AMG���S
      TEAMLOGO,      //!< �`�[�����S
      TITLEBG        //!< �^�C�g���w�i
   };
   TITLETYPE _type;            //!< �^�C�g���̎�ʕϐ�
   bool   _stop_obj_process;   //!< �I�u�W�F�N�g�����̃X�g�b�v����t���O
};
/** ���[�h�^�C�g���p�萔 */
namespace MTInfo{
   constexpr auto AMG_FADEINFRAME = 60;         //!< AMG���S�t�F�[�h�C���t���[��
   constexpr auto AMG_FADESPEED = 5;            //!< AMG���S�t�F�[�h���x
   constexpr auto AMG_FADEOUTBEGINFRAME = 90;   //!< AMG���S�t�F�[�h�A�E�g�J�n�t���[��
   constexpr auto AMG_FADEOUTENDFRAME = 150;    //!< AMG���S�t�F�[�h�A�E�g�I���t���[��
   constexpr auto TEAM_FADEINFRAME = 120;       //!< AMG���S�t�F�[�h�C���t���[��
   constexpr auto TEAM_FADESPEED = 3;           //!< AMG���S�t�F�[�h���x
   constexpr auto TEAM_FADEOUTBEGINFRAME = 180; //!< AMG���S�t�F�[�h�A�E�g�J�n�t���[��
   constexpr auto TEAM_FADEOUTENDFRAME = 300;   //!< AMG���S�t�F�[�h�A�E�g�I���t���[��
   constexpr auto TITLE_FADEINBEGINFRAME = 120; //!< �^�C�g���w�i�t�F�[�h�C���J�n�t���[��
   constexpr auto TITLE_FADEINENDFRAME = 240;   //!< �^�C�g���w�i�t�F�[�h�C���I���t���[��
   constexpr auto TITLE_FADESPEED = 3;          //!< �^�C�g���w�i�t�F�[�h���x
   constexpr auto GAMESTART_APPEARFRAME = 300;  //!< �Q�[���X�^�[�g�Z���N�g�o���t���[��
   constexpr auto EXPLAIN_APPEARFRAME = 315;    //!< ������ʃZ���N�g�o���t���[��
   constexpr auto CREDIT_APPEARFRAME = 330;     //!< �N���W�b�g��ʃZ���N�g�o���t���[��
   constexpr auto GAMEEND_APPEARFRAME = 345;    //!< �Q�[���I���Z���N�g�o���t���[��
}
