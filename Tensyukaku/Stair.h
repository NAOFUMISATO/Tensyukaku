/*****************************************************************//**
 * \file   Stair.h
 * \brief  �K�i�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** �K�i */
class Stair :public ObjectBase {
public:
   /**
    * \brief      �R���X�g���N�^
    * \param x    X���W
    * \param y    Y���W
    * \param flip ���]����
    */
   Stair(int x,int y,bool flip);
   /**
    * \brief �f�X�g���N�^
    */
   ~Stair();
   /**
    * \brief                      //�������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::STAIR   //�I�u�W�F�N�g�̎�ʁi�K�i�j��Ԃ�
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::STAIR; }
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
/** �K�i�N���X�p�萔 */
namespace StInfo {
   constexpr auto GRAPHPOINT_X = 0;         //!< X�ʒu����`��_�܂ł̍���
   constexpr auto GRAPHPOINT_Y = -400;      //!< Y�ʒu����`��_�܂ł̍���
   constexpr auto POSITION_HITX = -135;     //!< �`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto POSITION_HITY = -360;     //!< �`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto COLLISION_WIDTH = 270;    //!< �K�i�̓����蔻�艡��
   constexpr auto COLLISION_HEIGHT = 760;   //!< �K�i�̓����蔻��c��
}
