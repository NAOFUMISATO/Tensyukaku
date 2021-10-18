/*****************************************************************//**
 * \file   Shield.h
 * \brief  ���̃N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** �� */
class Shield :public ObjectBase {
public:
   /**
    * \brief �R���X�g���N�^
    */
   Shield();
   /**
    * \brief �f�X�g���N�^
    */
   ~Shield();
   /**
    * \brief                     �������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::SHIELD �I�u�W�F�N�g�̎�ʁi���j��Ԃ�
    */
   virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::SHIELD; }
   /**
    * \brief �������֐�
    */
   void   Init()override;
   /**
    * \brief   �X�V�֐�
    * \param g �Q�[���̎Q��
    */
   void   Process(Game& g)override;
   /**
    * \brief   �`��֐�
    * \param g �Q�[���̎Q��
    */
   void   Draw(Game& g)override;
   /**
    * \brief            �摜�n���h����Ԃ�
    * \return _grhandle �摜�n���h��
    */
   int      GetHandle() { return _grhandle; }
   /**
    * \brief              �`��p�x��Ԃ��֐�
    * \return _drg.second �`��p�x
    */
   double   GetAngle() { return _drg.second; }
   /**
    * \brief       �`��p�x��ݒ肷��֐�
    * \param angle �`��p�x
    */
   void   SetAngle(double angle) { _drg.second = angle; }
};
