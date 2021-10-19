/*****************************************************************//**
 * \file   FlameBlock.h
 * \brief  �����o�u���b�N�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** �����o�u���b�N */
class FlameBlock :public ObjectBase {
public:
   /**
    * \brief   �R���X�g���N�^
    * \param x X���W
    * \param y Y���W
    */
   FlameBlock(int x, int y);
   /**
    * \brief �f�X�g���N�^
    */
   ~FlameBlock();
   /**
    * \brief                         �������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::FLAMEBLOCK �I�u�W�F�N�g�̎�ʁi�����o�u���b�N�j��Ԃ�
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::FLAMEBLOCK; }
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