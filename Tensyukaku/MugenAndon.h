/*****************************************************************//**
 * \file   MugenAndon.h
 * \brief  �����s���N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** �����s�� */
class MugenAndon :public ObjectBase {
public:
   /**
    * \brief   �R���X�g���N�^
    * \param x X���W
    * \param y Y���W
    */
   MugenAndon(int x, int y);
   /**
    * \brief �f�X�g���N�^
    */
   ~MugenAndon();
   /**
    * \brief                         �������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::MUGENANDON �I�u�W�F�N�g�̎�ʁi�����s���j��Ԃ�
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::MUGENANDON; }
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
   int _flame_y;           //!< �������閳������Y���W
   bool _andondrop_flag;   //!< �����s�����|�ꂽ���̃t���O
   bool _playerflip_flag;  //!< �v���C���[�̔��]����ۑ��t���O
};
/** �����s���N���X�p�萔 */
namespace MAInfo {
   /*----------�s���̊e���W�֌W----------*/
   constexpr auto GRAPHPOINT_X = 0;          //!< X�ʒu����`��_�܂ł̍���
   constexpr auto GRAPHPOINT_Y = -112;       //!< Y�ʒu����`��_�܂ł̍���
   constexpr auto POSITION_HITX = -45;       //!< �`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto POSITION_HITY = -113;      //!< �`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto COLLISION_WIDTH = 90;      //!< �v���C���[�̓����蔻�艡��
   constexpr auto COLLISION_HEIGHT = 225;    //!< �v���C���[�̓����蔻��c��

   /*----------�摜�ǂݍ���&�A�j���[�V����&����t���[���֌W----------*/
   constexpr auto GRAPH_WIDTH = 90;          //!< 1��������̉摜�T�C�Y�i���j
   constexpr auto GRAPH_HEIGHT = 225;        //!< 1��������̉摜�T�C�Y�i�c�j
   constexpr auto MANDON_GRAPHNAME = "res/Gimik/Andon.png";   //!< �摜�t�@�C����
   constexpr auto MANDON_ANIMEMAX = 1;       //!< �S�Ẳ摜����
   constexpr auto MANDON_WIDTHCOUNT = 1;     //!< ���̉摜����
   constexpr auto MANDON_HEIGHTCOUNT = 1;    //!< �c�̉摜����
   constexpr auto MANDON_ALLFRAME = 90;      //!< �s�����|�ꂽ�ۂ̏��ł܂ł̃t���[��
   constexpr auto MANDON_DROPFRAME = 30;     //!< �s�����|�ꂫ��܂ł̃t���[��
   constexpr auto MANDON_DROPANGLE = 0.07;   //!< 1�t���[��������̍s�����|���p�x
   constexpr auto MANDON_DROPANGLEMAX = 1.5; //!< �s���̓|���p�x�̍ő�l
   constexpr auto MANDON_DROPMOVEX = 4;      //!< �s�����|�ꂽ�ۂ�X�̈ړ���
   constexpr auto MANDON_DROPMOVEY = 2;      //!< �s�����|�ꂽ�ۂ�Y�̈ړ���
   constexpr auto MANDON_FIREWIDTH = 100;    //!< ��������鉊���Ƃ̋���(���S�_)
   constexpr auto MANDON_FIREFRAME1 = 40;    //!< �������������t���[��1
   constexpr auto MANDON_FIREFRAME2 = 60;    //!< �������������t���[��2
   constexpr auto MANDON_FIREFRAME3 = 80;    //!< �������������t���[��3
   constexpr auto MANDON_FADEOUTSPEED = 4;   //!< �t�F�[�h�A�E�g�X�s�[�h

}