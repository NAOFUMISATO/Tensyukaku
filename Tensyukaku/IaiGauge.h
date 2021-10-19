/*****************************************************************//**
 * \file   IaiGauge.h
 * \brief  �����Q�[�WUI�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"

/** �����Q�[�WUI */
class IaiGauge :public ObjectBase {
public:
   /**
    * \brief �R���X�g���N�^
    */
   IaiGauge();
   /**
    * \brief �f�X�g���N�^
    */
   ~IaiGauge();
   /**
    * \brief                 �������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::UI �I�u�W�F�N�g�̎�ʁiUI�j��Ԃ�
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::UI; }
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
};