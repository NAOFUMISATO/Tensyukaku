/*****************************************************************//**
 * \file   RecoveryBlock.h
 * \brief  �񕜃u���b�N�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** �񕜃u���b�N */
class RecoveryBlock :public ObjectBase {
public:
   /**
    * \brief   �R���X�g���N�^
    * \param x X���W
    * \param y Y���W
    */
   RecoveryBlock(int x,int y);
   /**
    * \brief �f�X�g���N�^
    */
   ~RecoveryBlock();
   /**
    * \brief                              //�������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::RECOVERYBLOCK  //�I�u�W�F�N�g�̎�ʁi�񕜃u���b�N�j��Ԃ�
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::RECOVERYBLOCK; }
   /**
    * \brief �������֐�
    */
   void Init()override;
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