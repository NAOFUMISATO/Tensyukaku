/*****************************************************************//**
 * \file   FloorTextBlock.h
 * \brief  �K�w�\���u���b�N�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** �K�w�\���u���b�N */
class FloorTextBlock :public ObjectBase {
public:
   /**
    * \brief          �R���X�g���N�^
    * \param texttype �u���b�N�̎�ʕ�����
    */
   FloorTextBlock(std::string  texttype);
   /**
    * \brief �f�X�g���N�^
    */
   ~FloorTextBlock();
   /**
    * \brief                             �������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::FLOORTEXTBLOCK �I�u�W�F�N�g�̎�ʁi�K�w�\���u���b�N�j��Ԃ�
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::FLOORTEXTBLOCK; }
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

private:
   /**
    * \brief �K�w�\���u���b�N�̎�ʂɂ����W�ݒ�֐�
    */
   void PositionSetting();

   std::string _text_type;    //!< �K�w�\���u���b�N�̎�ʂ��w�肷�镶����
};
/** �K�w�\���u���b�N�N���X�p�萔 */
namespace FTInfo {
   constexpr auto GRAPHPOINT_X = 0;      //!< X�ʒu����`��_�܂ł̍���
   constexpr auto GRAPHPOINT_Y = -50;    //!< Y�ʒu����`��_�܂ł̍���
   constexpr auto POSITION_HITX = -50;   //!< �`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto POSITION_HITY = -50;   //!< �`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto COLLISION_WIDTH = 100; //!< �����蔻�艡��
   constexpr auto COLLISION_HEIGHT = 100;//!< �����蔻��c��
   constexpr auto  TOP_TEXT_X =500;      //!< �u�V��v�\���u���b�NX���W
   constexpr auto  TOP_TEXT_Y = 1000;    //!< �u�V��v�\���u���b�NY���W
   constexpr auto  UPPER_TEXT_X = 400;   //!< �u��w�v�\���u���b�NX���W
   constexpr auto  UPPER_TEXT_Y = 2520;  //!< �u��w�v�\���u���b�NY���W
   constexpr auto  MIDDLE_TEXT_X = 5500; //!< �u���w�v�\���u���b�NX���W
   constexpr auto  MIDDLE_TEXT_Y = 5560; //!< �u���w�v�\���u���b�NY���W
   constexpr auto  UNDER_TEXT_X = 350;   //!< �u���w�v�\���u���b�NX���W
   constexpr auto  UNDER_TEXT_Y = 9360;  //!< �u���w�v�\���u���b�NY���W
}