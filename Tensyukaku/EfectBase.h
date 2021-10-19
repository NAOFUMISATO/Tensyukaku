/*****************************************************************//**
 * \file   EfectBase.h
 * \brief  �e�G�t�F�N�g�̃x�[�X�N���X�i�I�u�W�F�N�g�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** �e�G�t�F�N�g�̃x�[�X */
class EfectBase :public ObjectBase {
public:
   /**
    * \brief �R���X�g���N�^
    */
   EfectBase();
   /**
    * \brief �f�X�g���N�^
    */
   ~EfectBase();
   /**
   * \brief                    �������z�֐��̃I�[�o�[���C�h
   * \return OBJECTTYPE::EFECT �I�u�W�F�N�g�̎�ʁi�G�t�F�N�g�j��Ԃ�
   */
   virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::EFECT; }
   /** �e�G�t�F�N�g�̎�ʗ� */
   enum class EFECTTYPE {
   MIDDLEBLOOD,  //!< ���m�^�̌����Ԃ�
   LOWBLOOD,     //!< �E�Ҍ^�̌����Ԃ�
   BOSSBLOOD     //!< �{�X�̌����Ԃ�
   };
   /**
    * \brief    �������z�֐����������z�֐���
    * \return 0 �h����Œ�`
    */
   virtual  EFECTTYPE GetEfeType() = 0;
   /**
   * \brief �������֐�
   */
   virtual void Init();
   /**
   * \brief   �X�V�֐�
   * \param g �Q�[���̎Q��
   */
   virtual void Process(Game& g);
   /**
   * \brief   �`��֐�
   * \param g �Q�[���̎Q��
   */
   virtual void Draw(Game& g);
   /**
   * \brief   �I�u�W�F�N�g�̏����֐�
   * \param g �Q�[���̎Q��
   */
   virtual void Delete(Game& g) {};
};