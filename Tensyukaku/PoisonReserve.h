/*****************************************************************//**
 * \file   PoisonReserve.h
 * \brief  �ŉt�����N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** �ŉt���� */
class PoisonReserve :public ObjectBase {
public:
   /**
    * \brief   �R���X�g���N�^
    * \param x X���W
    * \param y Y���W
    */
   PoisonReserve(int x, int y);
   /**
    * \brief �f�X�g���N�^
    */
   ~PoisonReserve();
   /**
    * \brief                    �������z�֐��̃I�[�o�[���C�h
    * \param OBJECTTYPE::POISON �I�u�W�F�N�g�̎�ʁi�ŉt�j��Ԃ�
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::POISON; }
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
   /**
   * \brief   �I�u�W�F�N�g�̏����֐�
   * \param g �Q�[���̎Q��
   */
   void Delete(Game& g)override;
};