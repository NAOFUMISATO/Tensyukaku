#pragma once
/*
   �����N���X
*/
#include "EnemyBase.h"
#include "ObjectBase.h"
#include <vector>
class Busyo : public EnemyBase {
public:
   //�����̃R���X�g���N�^   :   �����iX���W,Y���W,���]����j
   Busyo(int x, int y, bool flip);
   ~Busyo();
   virtual ENEMYTYPE   GetEneType() { return ENEMYTYPE::BUSYO; }
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
   //��_����Ԏ��̏���
   void   Damage(Game& g);
   //���S��Ԏ��̏���
   void   Dead(Game& g);
   //��_������&�����o���̏���
   void   HitJudge(Game& g);
   //�摜�ǂݍ��݊֐�
   void   LoadPicture();
   //SE�ǂݍ��݊֐�
   void   LoadSE();
   //���ʉ��{�����[�������l�ݒ�֐�
   void   VolumeInit();
   //�{�����[���ύX�֐�
   void   VolumeChange();
   //�f�o�b�O�p�֐�
   void   DebugDraw(Game& g);
};

namespace BsInfo {
   /*----------�����̊e���W�֌W----------*/
   constexpr auto GRAPHPOINT_X = 0;                  //X�ʒu����`��_�܂ł̍���
   constexpr auto GRAPHPOINT_Y = -315;               //Y�ʒu����`��_�܂ł̍���
   constexpr auto POSITION_HITX = -45;                  //�`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto POSITION_HITY = -135;               //�`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto COLLISION_WIDTH = 90;            //�����蔻�艡��
   constexpr auto COLLISION_HEIGHT = 450;            //�����蔻��c��

   /*----------�e���[�V�����̓����蔻��֌W----------*/
   constexpr auto PATROL_WIDTH = 500;               //���G�͈͓����蔻�艡��
   constexpr auto   PATROL_BACKWIDTH = 250;         //�w�����G�͈͓����蔻�艡��
   constexpr auto PATROL_HEIGHT = 100;               //���G�͈͓����蔻��c��
   constexpr auto COMING_WIDTH = 300;               //�U�������͈͓����蔻�艡��
   constexpr auto COMING_HEIGHT = 100;               //�U�������͈͓����蔻��c��
   constexpr auto ATTACK_WIDTH = 200;                  //�U�������蔻�艡��
   constexpr auto ATTACK_HEIGHT = 150;               //�U�������蔻��c��
   constexpr auto COMINGCANCEL_WIDTH = 1000;   //�ǐՒ��~�����蔻�艡��
   constexpr auto COMINGCANCEL_HEIGHT = 100;   //�ǐՒ��~�����蔻��c��
   constexpr auto ATTACKCANCEL_WIDTH = 200;      //�U�����~�����蔻�艡��
   constexpr auto ATTACKCANCEL_HEIGHT = 100;      //�U�����~�����蔻��c��

   /*----------�p�����[�^�[�֌W----------*/
   constexpr auto LIFE_MAX = 4;                           //�̗�
   constexpr auto SPEED = 2;                                 //�ړ����x
   constexpr auto PLAYER_IAI_MAX = 5;                  //�v���C���[�̋����ő�l
   /*----------�摜�ǂݍ���&�A�j���[�V����&����t���[���֌W----------*/
   //����
   constexpr auto GRAPH_WIDTH = 810;                  //1��������̉摜�T�C�Y�i���j
   constexpr auto GRAPH_HEIGHT = 630;               //1��������̉摜�T�C�Y�i�c�j
   //�o��
   constexpr auto APPEAR_GRAPHNAME = "res/Busyo/Bs_Stand.png";   //�摜�t�@�C����
   constexpr auto APPEAR_ANIMEMAX = 1;               //�S�Ẳ摜����
   constexpr auto APPEAR_WIDTHCOUNT = 1;         //���̉摜����
   constexpr auto APPEAR_HEIGHTCOUNT = 1;         //�c�̉摜����
   constexpr auto ANIMESPEED_APPEAR = 60;         //�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto FADEIN_SPEED = 4;                     //�A�b�p�[���̃t�F�[�h�C���X�s�[�h
   constexpr auto APPEAR_ALLFRAME = 60;            //�o���S�t���[��
   //����
   constexpr auto PATROL_GRAPHNAME = "res/Busyo/Bs_Stand.png";   //�摜�t�@�C����
   constexpr auto PATROL_ANIMEMAX = 1;               //�S�Ẳ摜����
   constexpr auto PATROL_WIDTHCOUNT = 1;         //���̉摜����
   constexpr auto PATROL_HEIGHTCOUNT = 1;         //�c�̉摜����
   constexpr auto ANIMESPEED_PATROL = 180;         //�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto PATROL_TURNFRAME = 180;         //����̐U������t���[��
   //�ǐ�
   constexpr auto COMING_GRAPHNAME = "res/Busyo/Bs_Walk.png";   //�摜�t�@�C����
   constexpr auto COMING_ANIMEMAX = 4;            //�S�Ẳ摜����
   constexpr auto COMING_WIDTHCOUNT = 4;         //���̉摜����
   constexpr auto COMING_HEIGHTCOUNT = 1;      //�c�̉摜����   
   constexpr auto ANIMESPEED_COMING = 30;         //�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   //�U��
   constexpr auto ATTACK_GRAPHNAME = "res/Busyo/Bs_Attack.png";   //�摜�t�@�C����
   constexpr auto ATTACK_ANIMEMAX = 4;               //�S�Ẳ摜����
   constexpr auto ATTACK_WIDTHCOUNT = 4;         //���̉摜����
   constexpr auto ATTACK_HEIGHTCOUNT = 1;         //�c�̉摜����
   constexpr auto ANIMESPEED_ATTACK = 14;         //�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto ATTACK_ANIMEFRAME = ATTACK_ANIMEMAX * ANIMESPEED_ATTACK * 2;      //�A�j���[�V�����t���[���i�S�Ẳ摜�����~�A�j���X�s�[�h�j
   constexpr auto ATTACK_ALLFRAME = 142;            //�U���S�t���[���i�S�t���[��-�A�j���[�V�����t���[�����U���P�\���ԁj
   constexpr auto ATTACK_STEP = 60;                     //�X�e�b�v����
   constexpr auto STEP_BEGINFRAME = 14;            //�X�e�b�v�̊J�n�t���[��
   constexpr auto ATTACK_BEGINFRAME = 14;         //�U�����蔭���t���[��
   constexpr auto ATTACK_BEGIN2FRAME = 70;         //2�i�ڍU�����蔭���t���[��
   constexpr auto ATTACK_ENDFRAME = 14;            //�U������I���t���[��
   constexpr auto ATTACK_END2FRAME = 84;            //2�i�ڍU������I���t���[��
   //��_��
   constexpr auto DAMAGE_GRAPHNAME = "res/Busyo/Bs_Damage.png";   //�摜�t�@�C����
   constexpr auto DAMAGE_ANIMEMAX = 3;            //�S�Ẳ摜����
   constexpr auto DAMAGE_WIDTHCOUNT = 3;         //���̉摜����
   constexpr auto DAMAGE_HEIGHTCOUNT = 1;      //�c�̉摜����
   constexpr auto ANIMESPEED_DAMAGE = 9;         //�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto DAMAGE_ANIMEFRAME = DAMAGE_ANIMEMAX * ANIMESPEED_DAMAGE;      //�A�j���[�V�����t���[���i�S�Ẳ摜�����~�A�j���X�s�[�h�j
   constexpr auto DAMAGE_ALLFRAME = 27;            //��_���S�t���[��
   //���S
   constexpr auto DEAD_GRAPHNAME = "res/Busyo/Bs_Dead.png";      //�摜�t�@�C����
   constexpr auto DEAD_ANIMEMAX = 3;                  //�S�Ẳ摜����
   constexpr auto DEAD_WIDTHCOUNT = 3;            //���̉摜����
   constexpr auto DEAD_HEIGHTCOUNT = 1;            //�c�̉摜����
   constexpr auto ANIMESPEED_DEAD = 20;            //�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto DEAD_ANIMEFRAME = DEAD_ANIMEMAX * ANIMESPEED_DEAD;         //�A�j���[�V�����t���[���i�S�Ẳ摜�����~�A�j���X�s�[�h�j
   constexpr auto DEAD_ALLFRAME = 120;               //���S�S�t���[��
   constexpr auto FADEOUT_SPEED = 4;                  //�t�F�[�h�A�E�g�X�s�[�h
}