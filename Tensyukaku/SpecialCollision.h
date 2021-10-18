/*****************************************************************//**
 * \file   SpecialCollision.h
 * \brief  ����U�������蔻��N���X�i�I�u�W�F�N�g�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"

/** ����U�������蔻��N���X */
class SpecialCollision : public ObjectBase {
public:
   /**
   * \brief   �R���X�g���N�^
   * \param x X���W
   * \param y Y���W
   */
   SpecialCollision(int x, int y);
   /**
    * \brief �f�X�g���N�^
    */
   ~SpecialCollision();
   /**
   * \brief                            �������z�֐��̃I�[�o�[���C�h
   * \return OBJECTTYPE::SPECIALATTACK �I�u�W�F�N�g�̎�ʁi����U�������蔻��j��Ԃ�
   */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::SPECIAL; }
   /**
    * \brief �������֐�
    */
   void Init()override;
   /**
    * \brief   �X�V�֐�
    * \param g �Q�[���N���X�̎Q��
    */
   void Process(Game& g)override;
   /**
    * \brief   �`��֐�
    * \param g �Q�[���N���X�̎Q��
    */
   void Draw(Game& g)override;
   /**
    * \brief   �I�u�W�F�N�g�̏����֐�
    * \param g �Q�[���N���X�̎Q��
    */
   void Delete(Game& g)override;
};
