/*****************************************************************//**
 * \file   Flame.h
 * \brief  �s���̉��N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** �s���̉� */
class Flame :public ObjectBase {
public:
   /**
    * \brief   �R���X�g���N�^
    * \param x X���W
    * \param y Y���W
    */
   Flame(int x,int y);
   /**
    * \brief �f�X�g���N�^
    */
   ~Flame();
   /**
    * \brief                      //�������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::FLAME   //�I�u�W�F�N�g�̎�ʁi�s���̉��j��Ԃ�
    */
   virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::FLAME; }
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
/** �s���̉��N���X�p�萔 */
namespace FInfo {
   /*----------���̊e���W�֌W----------*/
   constexpr auto GRAPHPOINT_X = 0;        //!< X�ʒu����`��_�܂ł̍���
   constexpr auto GRAPHPOINT_Y = -150;     //!< Y�ʒu����`��_�܂ł̍���
   constexpr auto POSITION_HITX = -150;    //!< �`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto POSITION_HITY = -150;    //!< �`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto COLLISION_WIDTH = 300;   //!< �����蔻�艡��
   constexpr auto COLLISION_HEIGHT = 300;  //!< �����蔻��c��
   /*----------�摜�ǂݍ���&�A�j���[�V����&����t���[���֌W----------*/
   constexpr auto GRAPH_WIDTH = 300;       //!< 1��������̉摜�T�C�Y�i���j
   constexpr auto GRAPH_HEIGHT = 300;      //!< 1��������̉摜�T�C�Y�i�c�j
   constexpr auto FLAME_GRAPHNAME = "res/Gimik/Flame.png";   //!< �摜�t�@�C����
   constexpr auto FLAME_ANIMEMAX = 7;      //!< �S�Ẳ摜����
   constexpr auto FLAME_WIDTHCOUNT = 7;    //!< ���̉摜����
   constexpr auto FLAME_HEIGHTCOUNT = 1;   //!< �c�̉摜����
   constexpr auto ANIMESPEED_FLAME = 15;   //!< �e��ԃA�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto FLAME_ANIMEFRAME = FLAME_ANIMEMAX * ANIMESPEED_FLAME;   //!< �A�j���[�V�����t���[���i�S�Ẳ摜�����~�A�j���X�s�[�h�j
   constexpr auto FLAME_ALLFLAME = 135;    //!< �����R���s����S�t���[��
   constexpr auto FLAME_FADEOUTSPEED = 4;  //!< �t�F�[�h�X�s�[�h
   
}