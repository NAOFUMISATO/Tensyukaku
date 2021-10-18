/*****************************************************************//**
 * \file   PoisonNinja.h
 * \brief  �ŉt�E�҃N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** �ŉt�E�� */
class PoisonNinja :public  ObjectBase {
public:
   /**
    * \brief      �R���X�g���N�^
    * \param x    X���W
    * \param y    Y���W
    * \param flip ���]����
    */
   PoisonNinja(int x,int y,bool flip);
   /**
    * \brief �f�X�g���N�^
    */
   ~PoisonNinja();
   /**
    * \brief                          �������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::POISONNINJA �I�u�W�F�N�g�̎�ʁi�ŉt�E�ҁj��Ԃ�
    */
   virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::POISONNINJA; }
   /**
    * \brief �������֐�
    */
   void Init();
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
   /** �ŉt�E�҂̏�ԗ� */
   enum class ENEMYSTATE{
   APPEAR,     //!< �o��
   PATROL,     //!< ����
   POISING     //!< �ŉt���炵
   };
   /**
    * \brief   �o����Ԃ̊֐�
    * \param g �Q�[���̎Q��
    */
   void Appear(Game& g);
   /**
    * \brief   ���G��Ԃ̊֐�
    * \param g �Q�[���̎Q��
    */
   void Patrol(Game& g);
   /**
    * \brief   �ŉt���炵��Ԃ̊֐�
    * \param g �Q�[���̎Q��
    */
   void Poising(Game& g);

   ENEMYSTATE _state;   //!< �ŉt�E�҂̏�ԕϐ�
};

/** �ŉt�E�҃N���X�p�萔 */
namespace PNInfo {
   /*----------�ŉt�E�҂̊e���W�֌W----------*/
   constexpr auto GRAPHPOINT_X = 0;          //!< X�ʒu����`��_�܂ł̍���
   constexpr auto GRAPHPOINT_Y = -315;       //!< Y�ʒu����`��_�܂ł̍���
   /*----------�e���[�V�����̓����蔻��֌W----------*/
   constexpr auto PATROL_WIDTH = 1000;       //!< ���G�͈͓����蔻�艡��
   constexpr auto PATROL_HEIGHT = 500;       //!< ���G�͈͓����蔻��c��
   constexpr auto POISINGCANCEL_WIDTH = 500; //!< �ŉt���炵���~�����蔻�艡��
   constexpr auto POISINGCANCEL_HEIGHT = 500;//!< �ŉt���炵���~�����蔻��c��

   /*----------�摜�ǂݍ���&�A�j���[�V����&����t���[���֌W----------*/
   //����
   constexpr auto GRAPH_WIDTH = 630;         //!< 1��������̉摜�T�C�Y�i���j
   constexpr auto GRAPH_HEIGHT = 630;        //!< 1��������̉摜�T�C�Y�i�c�j
   //�o��
   constexpr auto APPEAR_GRAPHNAME = "res/Gimik/N_Poison_Stand.png";   //!< �摜�t�@�C����
   constexpr auto APPEAR_ANIMEMAX = 1;       //!< �S�Ẳ摜����
   constexpr auto APPEAR_WIDTHCOUNT = 1;     //!< ���̉摜����
   constexpr auto APPEAR_HEIGHTCOUNT = 1;    //!< �c�̉摜����
   constexpr auto ANIMESPEED_APPEAR = 60;    //!< �A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto FADEIN_SPEED = 4;          //!< �A�b�p�[���̃t�F�[�h�C���X�s�[�h
   constexpr auto APPEAR_ALLFRAME = 60;      //!< �o���S�t���[��
   //���G
   constexpr auto PATROL_GRAPHNAME = "res/Gimik/N_Poison_Stand.png";   //!< �摜�t�@�C����
   constexpr auto PATROL_ANIMEMAX = 1;       //!< �S�Ẳ摜����
   constexpr auto PATROL_WIDTHCOUNT = 1;     //!< ���̉摜����
   constexpr auto PATROL_HEIGHTCOUNT = 1;    //!< �c�̉摜����
   constexpr auto ANIMESPEED_PATROL = 60;    //!< �A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto PATROL_TURNFRAME = 120;    //!< ���G���̐U������t���[��
   //�ŉt���炵
   constexpr auto POISING_GRAPHNAME = "res/Gimik/N_Poison.png";   //!< �摜�t�@�C����
   constexpr auto POISING_ANIMEMAX = 2;      //!< �S�Ẳ摜����
   constexpr auto POISING_WIDTHCOUNT = 2;    //!< ���̉摜����
   constexpr auto POISING_HEIGHTCOUNT = 1;   //!< �c�̉摜����
   constexpr auto ANIMESPEED_POISING = 40;   //!< �e��ԃA�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto POISING_ANIMEFRAME = POISING_ANIMEMAX * ANIMESPEED_POISING;      //!< �A�j���[�V�����t���[���i�S�Ẳ摜�����~�A�j���X�s�[�h�j
   constexpr auto POISING_ALLFRAME = 230;    //!< �ŉt���炵�S�t���[��
   constexpr auto POISON_SPAWN_X = 170;      //!< �E�҂���̓ŉt�����ݍ��ލ��W�ւ�X����
   constexpr auto POISON_SPAWN_Y = 80;       //!< �E�҂���̓ŉt�����ݍ��ލ��W�ւ�Y����
   //����
   constexpr auto DELETE_HEIGHT = 500;       //!< �ŉt�E�҂�������Y�̈ړ���
   constexpr auto FADEOUT_SPEED = 10;        //!< �t�F�[�h�X�s�[�h
}
/** �ŉt�����A�ŉt�����N���X�p�萔 */
namespace PoInfo {
   /*----------�ŉt�����̊e���W�֌W----------*/
   constexpr auto GRAPHPOINT_X = 0;         //!< X�ʒu����`��_�܂ł̍���
   constexpr auto GRAPHPOINT_Y = 25;        //!< Y�ʒu����`��_�܂ł̍���
   constexpr auto POSITION_HITX = -20;      //!< �`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto POSITION_HITY = -30;      //!< �`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto COLLISION_WIDTH = 40;     //!< �����蔻�艡��
   constexpr auto COLLISION_HEIGHT = 60;    //!< �����蔻��c��

   /*----------�摜�ǂݍ���&�A�j���[�V����&����t���[���֌W----------*/
   constexpr auto GRAPH_WIDTH = 90;         //!< 1��������̉摜�T�C�Y�i���j
   constexpr auto GRAPH_HEIGHT = 90;        //!< 1��������̉摜�T�C�Y�i�c�j
   //�ŉt����
   constexpr auto RESERVE_GRAPHNAME = "res/Gimik/PoisonReserve.png";   //!< �摜�t�@�C����
   constexpr auto RESERVE_ANIMEMAX = 4;     //!< �S�Ẳ摜����
   constexpr auto RESERVE_WIDTHCOUNT = 4;   //!< ���̉摜����
   constexpr auto RESERVE_HEIGHTCOUNT = 1;  //!< �c�̉摜����
   constexpr auto ANIMESPEED_RESERVE = 30;  //!< �e��ԃA�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto RESERVE_FALLFRAME = 90;   //!< ������Ԃ���ŉt�������n�߂�t���[��
   constexpr auto RESERVE_ANIMEFRAME = RESERVE_ANIMEMAX * ANIMESPEED_RESERVE;   //!< �A�j���[�V�����t���[���i�S�Ẳ摜�����~�A�j���X�s�[�h�j
   constexpr auto RESERVE_FADEOUTSPEED = 8; //!< �t�F�[�h�X�s�[�h
   constexpr auto RESERVE_ALLFRAME = 150;   //!< �ŉt�����̑S�t���[��
   //�ŉt����
   constexpr auto FALL_GRAPHNAME = "res/Gimik/PoisonFall.png";   //!< �摜�t�@�C����
   constexpr auto FALL_ANIMEMAX = 1;        //!< �S�Ẳ摜����
   constexpr auto FALL_WIDTHCOUNT = 1;      //!< ���̉摜����
   constexpr auto FALL_HEIGHTCOUNT = 1;     //!< �c�̉摜����
   constexpr auto FALL_STOPFRAME = 41;      //!< �������~�܂�t���[��
   //�ŉt���n
   constexpr auto LAND_GRAPHNAME = "res/Gimik/PoisonLand.png";   //!< �摜�t�@�C����
   constexpr auto LAND_ANIMEMAX = 3;        //!< �S�Ẳ摜����
   constexpr auto LAND_WIDTHCOUNT = 3;      //!< ���̉摜����
   constexpr auto LAND_HEIGHTCOUNT = 1;     //!< �c�̉摜����
   constexpr auto ANIMESPEED_LAND = 10;     //!< �e��ԃA�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto LAND_ANIMEFRAME = LAND_ANIMEMAX * ANIMESPEED_LAND;   //!< �A�j���[�V�����t���[���i�S�Ẳ摜�����~�A�j���X�s�[�h�j
   constexpr auto LAND_FADEOUTSPEED = 8;    //!< �t�F�[�h�X�s�[�h
   constexpr auto LAND_ALLFRAME = 60;       //!< �ŉt�̑S�t���[��
}