/*****************************************************************//**
 * \file   Boss.h
 * \brief  �{�X�N���X�i�G�l�~�[�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** �{�X */
class Boss :public ObjectBase {
public:
   /**
    * \brief      �R���X�g���N�^
    * \param x    X���W
    * \param y    Y���W
    * \param flip ���]����
    */
   Boss(int x,int y,bool flip);
   /**
    * \brief �f�X�g���N�^
    */
   ~Boss();
   /**
    * \brief                   �������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::BOSS �I�u�W�F�N�g�̎�ʁi�{�X�j��Ԃ�
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::BOSS; }
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
   * \brief   �X�V�֐�
   * \param g �Q�[���̎Q��
   */
   void Draw(Game& g)override;

private:
   /** �{�X�̏�ԗ� */
   enum class BOSSSTATE {
      IDLE,     //!< �ҋ@
      EVENTA,   //!< �C�x���gA
      EVENTB,   //!< �C�x���gB
      DAMAGE,   //!< ��_��
      DEAD      //!< ���S
   };
   /**
    * \brief   �ҋ@��Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void Idle(Game& g);
   /**
    * \brief   �C�x���gA��Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void BossEventA(Game& g);
   /**
    * \brief   �C�x���gB��Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void BossEventB(Game& g);
   /**
    * \brief   ��_����Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void Damage(Game& g);
   /**
    * \brief   ���S��Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void Dead(Game& g);
   /**
    * \brief   �{�X�C�x���g�ւ̏�ԑJ�ڊ֐�
    * \param g �Q�[���̎Q��
    */
   void EventChange(Game& g);
   /**
    * \brief �{�X�̉摜�ǂݍ��݊֐�
    */
   void LoadPicture();
   /**
    * \brief �{�X��SE�ǂݍ��݊֐�
    */
   void LoadSE();
   /**
    * \brief ���ʉ��{�����[�������l�ݒ�֐�
    */
   void VolumeInit();
   /**
    * \brief �{�����[���ύX�֐�
    */
   void VolumeChange();

   BOSSSTATE _state;    //!< ��ԑJ�ڕϐ�
   int _walk_speed;     //!< �ړ����x

};
/** �{�X�N���X�p�萔 */
namespace BossInifo {
   constexpr auto GRAPHPOINT_X = 0;         //!< X�ʒu����`��_�܂ł̍���
   constexpr auto GRAPHPOINT_Y = -315;      //!< Y�ʒu����`��_�܂ł̍���
   constexpr auto POSITION_HITX = -45;      //!< �`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto POSITION_HITY = -135;     //!< �`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto COLLISION_WIDTH = 90;     //!< �{�X�̓����蔻�艡��
   constexpr auto COLLISION_HEIGHT = 450;   //!< �{�X�̓����蔻��c��

   /*----------�摜�ǂݍ���&�A�j���[�V����&����t���[���֌W----------*/
   //����
   constexpr auto GRAPH_WIDTH = 630;        //!< 1��������̉摜�T�C�Y�i���j
   constexpr auto GRAPH_HEIGHT = 630;       //!< 1��������̉摜�T�C�Y�i�c�j
   //�ҋ@
   constexpr auto IDLE_GRAPHNAME = "res/Boss/BossIdle.png";   //!< �摜�t�@�C����
   constexpr auto IDLE_ANIMEMAX = 1;        //!< �S�Ẳ摜����
   constexpr auto IDLE_WIDTHCOUNT = 1;      //!< ���̉摜����
   constexpr auto IDLE_HEIGHTCOUNT = 1;     //!< �c�̉摜����
   constexpr auto ANIMESPEED_IDLE = 1;      //!< �A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   //�ړ�
   constexpr auto MOVE_GRAPHNAME = "res/Boss/BossWalk.png";   //!< �摜�t�@�C����
   constexpr auto MOVE_ANIMEMAX = 6;        //!< �S�Ẳ摜����
   constexpr auto MOVE_WIDTHCOUNT = 3;      //!< ���̉摜����
   constexpr auto MOVE_HEIGHTCOUNT = 2;     //!< �c�̉摜����
   constexpr auto ANIMESPEED_WALK = 10;     //!< �����A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto ANIMESPEED_RUN = 6;       //!< ����A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto MOVE_SEFRAME = 120;       //!< �ړ�SE�̊Ǘ��t���[��
   //�ジ����
   constexpr auto BACK_GRAPHNAME = "res/Boss/BossBack.png";   //!< �摜�t�@�C����
   constexpr auto BACK_ANIMEMAX = 6;        //!< �S�Ẳ摜����
   constexpr auto BACK_WIDTHCOUNT =3;       //!< ���̉摜����
   constexpr auto BACK_HEIGHTCOUNT =2;      //!< �c�̉摜����
   constexpr auto ANIMESPEED_BACK = 10;     //!< �ジ����A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto BACK_SEFRAME = 120;       //!< �ړ�SE�̊Ǘ��t���[��
   //��_��
   constexpr auto DAMAGE_GRAPHNAME = "res/Boss/BossDamage.png";   //!< �摜�t�@�C����
   constexpr auto DAMAGE_ANIMEMAX = 1;      //!< �S�Ẳ摜����
   constexpr auto DAMAGE_WIDTHCOUNT = 1;    //!< ���̉摜����
   constexpr auto DAMAGE_HEIGHTCOUNT = 1;   //!< �c�̉摜����
   constexpr auto ANIMESPEED_DAMAGE = 60;   //!< �A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto DAMAGE_ANIMEFRAME = DAMAGE_ANIMEMAX * ANIMESPEED_DAMAGE; //!< �A�j���[�V�����t���[��
   constexpr auto DAMAGE_ALLFRAME = 80;     //!< ���S�S�t���[��(�S�t���[���[�A�j���[�V�����t���[�����P�\����)
   //���S
   constexpr auto DEAD_GRAPHNAME = "res/Boss/BossDead2.png";   //!< �摜�t�@�C����
   constexpr auto DEAD_ANIMEMAX = 3;        //!< �S�Ẳ摜����
   constexpr auto DEAD_WIDTHCOUNT = 3;      //!< ���̉摜����
   constexpr auto DEAD_HEIGHTCOUNT = 1;     //!< �c�̉摜����
   constexpr auto ANIMESPEED_DEAD = 60;     //!< �A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto DEAD_ANIMEFRAME = DEAD_ANIMEMAX * ANIMESPEED_DEAD; //!< �A�j���[�V�����t���[��
   constexpr auto DEAD_ALLFRAME = 180;      //!< ���S�S�t���[��(�S�t���[���[�A�j���[�V�����t���[�����P�\����)
}