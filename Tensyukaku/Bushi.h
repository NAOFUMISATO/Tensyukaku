#pragma once
#include "EnemyBase.h"
#include "ObjectBase.h"
#include <vector>
// ���m�N���X

class Bushi : public EnemyBase {
public:
	Bushi(int x, int y, bool flip);
	~Bushi();
	virtual ENEMYTYPE	GetEneType() { return ENEMYTYPE::BUSHI; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;

private:
	void	Appear(Game& g);		//�o����Ԏ��̏���
	void	Patrol(Game& g);		//�����Ԏ��̏���
	void	Coming(Game& g);		//�ǐՏ�Ԏ��̏���
	void	Attack(Game& g);		//�U����Ԏ��̏���
	void	Damage(Game& g);		//��_����Ԏ��̏���
	void	Dead(Game& g);			//���S��Ԏ��̏���
	void	HitJudge(Game& g);	//��_������&�����o���̏���
	void	LoadActionGraph();		//���m�̉摜�ǂݍ��݊֐�
	void	LoadActionSE();			//���m��SE�ǂݍ��݊֐�
	void	DebugDraw(Game& g);		//�f�o�b�O�p�֐�
};

namespace BInfo {
	/*----------���m�̊e���W�֌W----------*/
	constexpr auto GRAPHPOINT_X = 0;			//X�ʒu����`��_�܂ł̍���
	constexpr auto GRAPHPOINT_Y = -315;			//Y�ʒu����`��_�܂ł̍���
	constexpr auto POSITION_HITX = -45;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto POSITION_HITY = -135;		//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto COLLISION_WIDTH = 90;		//�����蔻�艡��
	constexpr auto COLLISION_HEIGHT = 450;		//�����蔻��c��

	/*----------�e���[�V�����̓����蔻��֌W----------*/
	constexpr auto PATROL_WIDTH = 500;			//���G�͈͓����蔻�艡��
	constexpr auto	PATROL_BACKWIDTH = 250;	//�w�����G�͈͓����蔻�艡��
	constexpr auto PATROL_HEIGHT = 100;			//���G�͈͓����蔻��c��
	constexpr auto COMING_WIDTH = 200;			//�U�������͈͓����蔻�艡��
	constexpr auto COMING_HEIGHT = 100;			//�U�������͈͓����蔻��c��
	constexpr auto ATTACK_WIDTH = 200;			//�U�������蔻�艡��
	constexpr auto ATTACK_HEIGHT = 150;			//�U�������蔻��c��
	constexpr auto COMINGCANCEL_WIDTH = 1000;	//�ǐՒ��~�����蔻�艡��
	constexpr auto COMINGCANCEL_HEIGHT = 100;	//�ǐՒ��~�����蔻��c��
	constexpr auto ATTACKCANCEL_WIDTH = 200;	//�U�����~�����蔻�艡��
	constexpr auto ATTACKCANCEL_HEIGHT = 100;	//�U�����~�����蔻��c��

	/*----------�p�����[�^�[�֌W----------*/
	constexpr auto LIFE_MAX = 3;				//�̗�
	constexpr auto SPEED = 2;					//�ړ����x
	constexpr auto PLAYER_IAI_MAX = 5;			//�v���C���[�̋����ő�l
	/*----------�摜�ǂݍ���&�A�j���[�V����&����t���[���֌W----------*/
	//����
	constexpr auto GRAPH_WIDTH = 810;			//1��������̉摜�T�C�Y�i���j
	constexpr auto GRAPH_HEIGHT = 630;			//1��������̉摜�T�C�Y�i�c�j
	//�o��
	constexpr auto APPEAR_GRAPHNAME = "res/Bushi/B_Stand.png";	//�摜�t�@�C����
	constexpr auto APPEAR_ANIMEMAX = 1;			//�S�Ẳ摜����
	constexpr auto APPEAR_WIDTHCOUNT = 1;		//���̉摜����
	constexpr auto APPEAR_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_APPEAR = 60;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto FADEIN_SPEED = 4;			//�A�b�p�[���̃t�F�[�h�C���X�s�[�h
	constexpr auto APPEAR_ALLFRAME = 60;		//�o���S�t���[��
	//����
	constexpr auto PATROL_GRAPHNAME = "res/Bushi/B_Stand.png";	//�摜�t�@�C����
	constexpr auto PATROL_ANIMEMAX = 1;			//�S�Ẳ摜����
	constexpr auto PATROL_WIDTHCOUNT = 1;		//���̉摜����
	constexpr auto PATROL_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_PATROL = 180;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto PATROL_TURNFRAME = 180;		//����̐U������t���[��
	//�ǐ�
	constexpr auto COMING_GRAPHNAME = "res/Bushi/B_Walk.png";	//�摜�t�@�C����
	constexpr auto COMING_ANIMEMAX = 4;			//�S�Ẳ摜����
	constexpr auto COMING_WIDTHCOUNT = 4;		//���̉摜����
	constexpr auto COMING_HEIGHTCOUNT = 1;		//�c�̉摜����	
	constexpr auto ANIMESPEED_COMING = 30;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	//�U��
	constexpr auto ATTACK_GRAPHNAME = "res/Bushi/B_Attack.png";	//�摜�t�@�C����
	constexpr auto ATTACK_ANIMEMAX = 4;			//�S�Ẳ摜����
	constexpr auto ATTACK_WIDTHCOUNT = 4;		//���̉摜����
	constexpr auto ATTACK_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_ATTACK = 15;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto ATTACK_ANIMEFRAME = ATTACK_ANIMEMAX * ANIMESPEED_ATTACK;		//�A�j���[�V�����t���[���i�S�Ẳ摜�����~�A�j���X�s�[�h�j
	constexpr auto ATTACK_ALLFRAME = 80;		//�U���S�t���[���i�S�t���[��-�A�j���[�V�����t���[�����U���P�\���ԁj
	constexpr auto ATTACK_STEP = 60;			//�X�e�b�v����
	constexpr auto STEP_BEGINFRAME = 15;		//�X�e�b�v�̊J�n�t���[��
	constexpr auto ATTACK_BEGINFRAME = 15;		//�U�����蔭���t���[��
	constexpr auto ATTACK_ENDFRAME = 15;		//�U������I���t���[��
	//��_��
	constexpr auto DAMAGE_GRAPHNAME = "res/Bushi/B_Damage.png";	//�摜�t�@�C����
	constexpr auto DAMAGE_ANIMEMAX = 3;			//�S�Ẳ摜����
	constexpr auto DAMAGE_WIDTHCOUNT = 3;		//���̉摜����
	constexpr auto DAMAGE_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_DAMAGE = 15;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto DAMAGE_ANIMEFRAME = DAMAGE_ANIMEMAX * ANIMESPEED_DAMAGE;		//�A�j���[�V�����t���[���i�S�Ẳ摜�����~�A�j���X�s�[�h�j
	constexpr auto DAMAGE_ALLFRAME = 55;		//��_���S�t���[��
	//���S
	constexpr auto DEAD_GRAPHNAME = "res/Bushi/B_Dead.png";		//�摜�t�@�C����
	constexpr auto DEAD_ANIMEMAX = 3;			//�S�Ẳ摜����
	constexpr auto DEAD_WIDTHCOUNT = 3;			//���̉摜����
	constexpr auto DEAD_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_DEAD = 20;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto DEAD_ANIMEFRAME = DEAD_ANIMEMAX * ANIMESPEED_DEAD;		//�A�j���[�V�����t���[���i�S�Ẳ摜�����~�A�j���X�s�[�h�j
	constexpr auto DEAD_ALLFRAME = 120 ;		//���S�S�t���[��
	constexpr auto FADEOUT_SPEED = 4;			//�t�F�[�h�A�E�g�X�s�[�h
	/*----------SE�֌W----------*/
	constexpr auto WALK_SE = "se/Footstep.wav";			//����
	constexpr auto ATTACK_SE = "se/slash3.wav";			//�U��	

}