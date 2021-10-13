#pragma once
/*
   �E��
*/
#include "EnemyBase.h"
#include <vector>
class Ninja : public EnemyBase {
public:
   //�E�҂̃R���X�g���N�^    :   �����iX���W,Y���W,���]����,�N�i�C�{���j
   Ninja(int x, int y, bool flip,int kunai_stock);
   ~Ninja();
   virtual ENEMYTYPE   GetEneType() { return ENEMYTYPE::NINJA; }
   //������
   void   Init()override;
   //�X�V
   void   Process(Game& g)override;
   //�`��
   void   Draw(Game& g)override;
   //�I�u�W�F�N�g�̏���
   void   Delete(Game& g)override;

private:
   //�o����Ԏ��̏���
   void   Appear(Game& g);
   //�����Ԏ��̏���
   void   Patrol(Game& g);
   //�ǐՏ�Ԏ��̏���
   void   Coming(Game& g);
   //�U����Ԏ��̏���
   void   Attack(Game& g);
   //�N�i�C�������̏���
   void   Throw(Game& g);
   //���S��Ԏ��̏���
   void   Dead(Game& g);
   //��_������&�����o���̏���
   void   HitJudge(Game& g);
   //�f�o�b�O�p�֐�
   void   DebugDraw(Game& g);
   //�摜�ǂݍ��݊֐�
   void   LoadPicture();
   //���ʉ��ǂݍ��݊֐�
   void   LoadSE();   
   //���ʉ��{�����[�������l�ݒ�֐�
   void   VolumeInit();
   //�{�����[���ύX�֐�
   void   VolumeChange();

/*---------�����o�ϐ�--------*/
   int      _kunai_stock;                  //�N�i�C�{��
};
namespace NInfo {
   /*----------�e���W�֌W----------*/
   constexpr auto GRAPHPOINT_X = 0;                     //X�ʒu����`��_�܂ł̍���
   constexpr auto GRAPHPOINT_Y = -315;                  //Y�ʒu����`��_�܂ł̍���
   constexpr auto POSITION_HITX = -60;                  //�`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto POSITION_HITY = 105;                  //�`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto COLLISION_WIDTH = 120;            //�����蔻�艡��
   constexpr auto COLLISION_HEIGHT = 210;            //�����蔻��c��

   /*----------�e���[�V�����̓����蔻��֌W----------*/
   constexpr auto PATROL_WIDTH = 800;                  //���G�͈͓����蔻�艡��
   constexpr auto PATROL_BACKWIDTH = 600;         //�w�����G�͈͓����蔻�艡��
   constexpr auto PATROL_HEIGHT = 100;               //���G�͈͓����蔻��c��
   constexpr auto COMING_WIDTH = 150;                  //�U�������͈͓����蔻�艡��
   constexpr auto COMING_HEIGHT = 100;               //�U�������͈͓����蔻��c��
   constexpr auto ATTACK_WIDTH = 150;                  //�U�������蔻�艡��
   constexpr auto ATTACK_HEIGHT = 150;                  //�U�������蔻��c��
   constexpr auto COMINGCANCEL_WIDTH = 800;      //�ǐՒ��~�����蔻�艡��
   constexpr auto COMINGCANCEL_HEIGHT = 100;   //�ǐՒ��~�����蔻��c��
   constexpr auto ATTACKCANCEL_WIDTH = 150;      //�U�����~�����蔻�艡��
   constexpr auto ATTACKCANCEL_HEIGHT = 100;   //�U�����~�����蔻��c��
   constexpr auto THROWCANCEL_WIDTH = 800;      //�N�i�C�������~�����蔻�艡��
   constexpr auto THROWCANCEL_HEIGHT = 100;   //�N�i�C�������~�����蔻��c��

   /*----------�p�����[�^�[�֌W----------*/
   constexpr auto LIFE_MAX = 1;                     //�̗�
   constexpr auto SPEED = 3;                           //�ړ����x
   constexpr auto PLAYER_IAI_MAX = 5;            //�v���C���[�̋����ő�l

   /*----------�摜�ǂݍ���&�A�j���[�V����&����t���[���֌W----------*/
   //����
   constexpr auto GRAPH_WIDTH = 630;         //1��������̉摜�T�C�Y�i���j
   constexpr auto GRAPH_HEIGHT = 630;         //1��������̉摜�T�C�Y�i�c�j
   //�o��
   constexpr auto APPEAR_GRAPHNAME = "res/Ninja/N_Stand.png";   //�摜�t�@�C����
   constexpr auto APPEAR_ANIMEMAX = 1;            //�S�Ẳ摜����
   constexpr auto APPEAR_WIDTHCOUNT = 1;      //���̉摜����
   constexpr auto APPEAR_HEIGHTCOUNT = 1;      //�c�̉摜����
   constexpr auto ANIMESPEED_APPEAR = 60;      //�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto FADEIN_SPEED = 4;                     //�A�b�p�[���̃t�F�[�h�C���X�s�[�h
   constexpr auto APPEAR_ALLFRAME = 60;            //�o���S�t���[��
   //����
   constexpr auto PATROL_GRAPHNAME = "res/Ninja/N_Stand.png";   //�摜�t�@�C����
   constexpr auto PATROL_ANIMEMAX = 1;            //�S�Ẳ摜����
   constexpr auto PATROL_WIDTHCOUNT = 1;      //���̉摜����
   constexpr auto PATROL_HEIGHTCOUNT = 1;      //�c�̉摜����
   constexpr auto ANIMESPEED_PATROL = 5;         //�e��ԃA�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto PATROL_TURNFRAME = 120;      //����̐U������t���[��
   //�ǐ�
   constexpr auto COMING_GRAPHNAME = "res/Ninja/N_Walk.png";   //�摜�t�@�C����
   constexpr auto COMING_ANIMEMAX = 4;                     //�S�Ẳ摜����
   constexpr auto COMING_WIDTHCOUNT = 4;               //���̉摜����
   constexpr auto COMING_HEIGHTCOUNT = 1;               //�c�̉摜����   
   constexpr auto ANIMESPEED_COMING = 10;               //�e��ԃA�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto COMING_ALLFRAME= COMING_ANIMEMAX * ANIMESPEED_COMING;      //�A�j���[�V�����t���[���i�S�Ẳ摜�����~�A�j���X�s�[�h�j
   constexpr auto COMINGSPEED_UPFRAME = 20;         //�X�s�[�h�A�b�v�t���[��
   constexpr auto COMINGSPEED_DOWNFRAME = 30;      //�X�s�[�h�_�E���t���[��
   constexpr auto COMING_UPSPEED = 15;                     //�X�s�[�h�̏㏸���̒l
   //�U��
   constexpr auto ATTACK_GRAPHNAME = "res/Ninja/N_Attack.png";   //�摜�t�@�C����
   constexpr auto ATTACK_ANIMEMAX =4;                     //�S�Ẳ摜����
   constexpr auto ATTACK_WIDTHCOUNT = 4;                  //���̉摜����
   constexpr auto ATTACK_HEIGHTCOUNT = 1;               //�c�̉摜����
   constexpr auto ANIMESPEED_ATTACK = 10;               //�e��ԃA�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto ATTACK_ANIMEFRAME = ATTACK_ANIMEMAX * ANIMESPEED_ATTACK;      //�A�j���[�V�����t���[���i�S�Ẳ摜�����~�A�j���X�s�[�h�j
   constexpr auto ATTACK_ALLFRAME = 50;      //�U���S�t���[���i�S�t���[��-�A�j���[�V�����t���[�����U���P�\���ԁj
   constexpr auto ATTACK_BEGINFRAME = 20;               //�U�����蔭���t���[��
   constexpr auto ATTACK_ENDFRAME = 10;                  //�U������I���t���[��
   //�N�i�C����
   constexpr auto THROW_GRAPHNAME = "res/Ninja/N_Throw.png";   //�摜�t�@�C����
   constexpr auto THROW_ANIMEMAX = 4;                     //�S�Ẳ摜����
   constexpr auto THROW_WIDTHCOUNT = 4;                  //���̉摜����
   constexpr auto THROW_HEIGHTCOUNT = 1;               //�c�̉摜����
   constexpr auto ANIMESPEED_THROW = 20;               //�e��ԃA�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto THROW_ANIMEFRAME = THROW_ANIMEMAX * ANIMESPEED_THROW;      //�A�j���[�V�����t���[���i�S�Ẳ摜�����~�A�j���X�s�[�h�j
   constexpr auto THROW_ALLFRAME = 150;                  //�U���S�t���[���i�S�t���[��-�A�j���[�V�����t���[�����U���P�\���ԁj
   constexpr auto KUNAI_RELEASEFRAME = 40;               //�U�����蔭���t���[��
   constexpr auto KUNAI_SPEED=10;                              //�N�i�C�̑���
   //���S
   constexpr auto DEAD_GRAPHNAME = "res/Ninja/N_Dead.png";      //�摜�t�@�C����
   constexpr auto DEAD_ANIMEMAX = 3;                  //�S�Ẳ摜����
   constexpr auto DEAD_WIDTHCOUNT = 3;               //���̉摜����
   constexpr auto DEAD_HEIGHTCOUNT = 1;            //�c�̉摜����
   constexpr auto ANIMESPEED_DEAD = 20;               //�e��ԃA�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto DEAD_ANIMEFRAME = DEAD_ANIMEMAX * ANIMESPEED_DEAD;      //�A�j���[�V�����t���[���i�S�Ẳ摜�����~�A�j���X�s�[�h�j
   constexpr auto DEAD_ALLFRAME = 120;               //���S�S�t���[��
   constexpr auto FADEOUT_SPEED = 4;                  //�t�F�[�h�A�E�g�X�s�[�h

   /*----------�N�i�C�̊e���W�֌W----------*/
   constexpr auto KUNAI_GRAPHPOINT_X = 0;         //X�ʒu����`��_�܂ł̍���
   constexpr auto KUNAI_GRAPHPOINT_Y = -45;      //Y�ʒu����`��_�܂ł̍���
   constexpr auto KUNAI_POSITION_HITX = -45;      //�`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto KUNAI_POSITION_HITY = -20;      //�`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto KUNAI_COLLISION_WIDTH = 90;   //�����蔻�艡��
   constexpr auto KUNAI_COLLISION_HEIGHT = 40;   //�����蔻��c��

   /*----------�摜�ǂݍ���&�A�j���[�V�����֌W----------*/
   constexpr auto KUNAI_GRAPHNAME = "res/Ninja/Kunai.png";   //�摜�t�@�C����
   constexpr auto REPEL_FRAME = 60;                  //�e����Ă�����ł܂ł̃t���[��
   constexpr auto KUNAI_ALPHACHANGE = 4;         //�e���ꂽ���1�t���[��������̓����x�̌�����
   constexpr auto KUNAI_ANGLECHANGE = 0.1;      //�e���ꂽ���1�t���[��������̊p�x�̕ύX��
   constexpr auto KUNAI_XCHANGE = 2;               //�e���ꂽ���1�t���[���������X�ړ���
   constexpr auto KUNAI_YCHANGE = 4;                  //�e���ꂽ���1�t���[���������Y�ړ���

}