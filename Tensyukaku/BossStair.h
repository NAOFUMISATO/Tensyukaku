/*****************************************************************//**
 * \file   BossStair.h
 * \brief  �{�X�K�i�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** �{�X�K�i */
class BossStair :public ObjectBase {
public:
   /**
    * \brief   �R���X�g���N�^
    * \param x X���W
    * \param y Y���W
    */
   BossStair(int x, int y);
   /**
    * \brief �f�X�g���N�^
    */
   ~BossStair();
   /**
    * \brief                        �������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::BOSSSTAIR �I�u�W�F�N�g�̎�ʁi�{�X�K�i�j��Ԃ�
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::BOSSSTAIR; }
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
};
/** �{�X�K�i�N���X�p�萔 */
namespace BSInfo {
   constexpr auto GRAPHPOINT_X = 0;         //!< X�ʒu����`��_�܂ł̍���
   constexpr auto GRAPHPOINT_Y = -400;      //!< Y�ʒu����`��_�܂ł̍���
   constexpr auto POSITION_HITX = -120;     //!< �`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto POSITION_HITY = -360;     //!< �`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto COLLISION_WIDTH = 240;    //!< �K�i�̓����蔻�艡��
   constexpr auto COLLISION_HEIGHT = 760;   //!< �K�i�̓����蔻��c��
}