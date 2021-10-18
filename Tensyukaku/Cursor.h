/*****************************************************************//**
 * \file   Cursor.h
 * \brief  �^�C�g���J�[�\���N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** �^�C�g���J�[�\�� */
class Cursor :public ObjectBase {
public:
   /**
    * \brief �R���X�g���N�^
    */
   Cursor();
   /**
    * \brief �f�X�g���N�^
    */
   ~Cursor();
   /**
    * \brief                       //�������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::CURSOR   //�I�u�W�F�N�g�̎�ʁi�^�C�g���J�[�\���j��Ԃ�
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::CURSOR; }
   /**
    * \brief �������֐�
    */
   void Init()override;
   /**
    * \brief   �X�V�֐�
    * \param g �Q�[���̎Q��
    */
   void Process(Game& g)override;
   /**
    * \brief   �`��֐�
    * \param g �Q�[���̎Q��
    */
   void Draw(Game& g)override;

private:
   /**
    * \brief   �e�����蔻��֐�
    * \param g �Q�[���̎Q��
    */
   void HitJudge(Game& g);
   /**
    * \brief ���ʉ��ǂݍ��݊֐�
    */
   void LoadSE();
   /**
    * \brief ���ʉ��{�����[�������l�ݒ�֐�
    */
   void VolumeInit();
   /**
    * \brief �{�����[���ύX�֐�
    */
   void VolumeChange();
   /** �J�[�\���̏�ԗ� */
   enum class CURSOLSTATE {
      NOHIT,     //!< �����G��Ă��Ȃ�
      STARTHIT,  //!< �X�^�[�g�Z���N�g�ɐG��Ă���
      EXHIT,     //!< ������ʃZ���N�g�ɐG��Ă���
      ENDHIT,    //!< �Q�[���I���Z���N�g�ɐG��Ă���
      CREDITHIT  //!< �N���W�b�g�Z���N�g�ɐG��Ă���
   };

   CURSOLSTATE _state;    //!< �J�[�\���̏��
   Vector2 _velocity_dir; //!< ���x����
   std::string _hit_type; //!< �p�[�e�B�N���̃^�C�v�w��
   int _par_qty;          //!< �p�[�e�B�N����1�t���[��������̗�
   bool _input_flag;      //!< ���͊Ǘ��t���O
   bool _startpush_flag;  //!< �X�^�[�g�Z���N�g�ɐG��Ă����Ԃœ���̃{�^�������������̃t���O
   bool _endpush_flag;    //!< �Q�[���I���Z���N�g�ɐG��Ă����Ԃœ���̃{�^�������������̃t���O
   bool _creditpush_flag; //!< �N���W�b�g�Z���N�g�ɐG��Ă����Ԃœ���̃{�^�������������̃t���O
};
/** �^�C�g���J�[�\���p�萔 */
namespace CuInfo{
   constexpr auto NOHIT_PARQTY = 7; //�����G��Ă��Ȃ���Ԃł̃p�[�e�B�N����1�t���[��������̗�
   constexpr auto HIT_PARQTY =10;   //���ꂩ�̃Z���N�g�ɐG�ꂽ��Ԃł̃p�[�e�B�N����1�t���[��������̗�
}