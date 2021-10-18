/*****************************************************************//**
 * \file   BossEventBlock.h
 * \brief  �{�X�C�x���g�����u���b�N�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** �{�X�C�x���g�����u���b�N */
class BossEventBlock :public ObjectBase {
public:
   /**
    * \brief          �R���X�g���N�^
    * \param blocknum �u���b�N�ԍ�
    */
   BossEventBlock(int blocknum);
   /**
    * \brief �f�X�g���N�^
    */
   ~BossEventBlock();
   /**
    * \brief                              �������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::BOSSEVENTBLOCK  �I�u�W�F�N�g�̎�ʁi�{�X�C�x���g�u���b�N�j��Ԃ�
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::BOSSEVENTBLOCK; }
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
    * \brief �u���b�N�ԍ����Ƃ̍��W�ݒ�֐�
    */
   void PositionSetting();

   int _block_num;   //!< �u���b�N�ԍ��ϐ�
};
/** �{�X�C�x���g�����u���b�N�N���X�p�萔 */
namespace BEInfo {

   constexpr auto BOSSA_X = 5300;         //!< �{�X�C�x���g�u���b�NA��X���W
   constexpr auto BOSSA_Y = 1760;         //!< �{�X�C�x���g�u���b�NA��Y���W
   constexpr auto BOSSB_X = 4500;         //!< �{�X�C�x���g�u���b�NB��X���W
   constexpr auto BOSSB_Y = 1000;         //!< �{�X�C�x���g�u���b�NB��Y���W
   constexpr auto GRAPHPOINT_X = 0;       //!< X�ʒu����`��_�܂ł̍���
   constexpr auto GRAPHPOINT_Y = -50;     //!< Y�ʒu����`��_�܂ł̍���
   constexpr auto POSITION_HITX = -50;    //!< �`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto POSITION_HITY = -50;    //!< �`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto COLLISION_WIDTH = 100;  //!< �����蔻�艡��
   constexpr auto COLLISION_HEIGHT = 100; //!< �����蔻��c��


}