#pragma once
#include "EnemyBase.h"
/*
	����
*/
class Shielder :public EnemyBase {
public:
	Shielder( int x, int y, bool flip);
	~Shielder();
	virtual ENEMYTYPE	GetEneType() { return ENEMYTYPE::SHIELDER; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;
private:
	void	Appear(Game& g);		//�o����Ԏ��̏���
	void	Patrol(Game& g);		//�����Ԏ��̏���
	void	Coming(Game& g);		//�ǐՏ�Ԏ��̏���
	void	Attack(Game& g);		//�U����Ԏ��̏���
	void	GuardAttack(Game& g);	//�������U����Ԏ��̏���
	void	GuardBreak(Game& g);	//��������Ԏ��̏���
	void	Dead(Game& g);			//���S��Ԏ��̏���
	void	HitJudge(Game& g);	//��_������&�����o���̏���
	void	ShieldDraw(Game& g);	//���̕`��֐�
	void	LoadPicture();		//�摜�ǂݍ��݊֐�
	void	LoadSE();			//SE�ǂݍ��݊֐�
	void	VolumeInit();	//���ʉ��{�����[�������l�ݒ�֐�
	void	VolumeChange();	//�{�����[���ύX�֐�
	void	DebugDraw(Game& g);		//�f�o�b�O�p�֐�

	/*---------�����o�ϐ�---------*/
	bool	_ShieldAppear_Flag;	//���̏o���t���O
	bool	_ShieldAlive_Flag;		//���̐����t���O
	bool	_ShieldAttack_Flag;	//���ێ����̍U���t���O
	bool	_ShieldBreak_Flag;	//�������t���O
	bool	_ShieldDraw_Flag;		//���̕`��t���O
	int		_Shield_Cnt;		//���p�̓���J�E���^�ۑ��ϐ�

};

namespace SInfo {
	/*----------�����̊e���W�֌W----------*/
	constexpr auto GRAPHPOINT_X = 0;			//X�ʒu����`��_�܂ł̍���
	constexpr auto GRAPHPOINT_Y = -315;			//Y�ʒu����`��_�܂ł̍���
	constexpr auto POSITION_HITX = -45;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto POSITION_HITY = -135;		//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto COLLISION_WIDTH = 90;		//�����蔻�艡��
	constexpr auto COLLISION_HEIGHT = 450;		//�����蔻��c��
	
	/*----------�e���[�V�����̓����蔻��֌W----------*/
	constexpr auto PATROL_WIDTH = 500;			//���G�͈͓����蔻�艡��
	constexpr auto PATROL_BACKWIDTH = 300;	//�w�����G�͈͓����蔻�艡��
	constexpr auto PATROL_HEIGHT = 100;			//���G�͈͓����蔻��c��
	constexpr auto COMING_WIDTH = 350;			//�U�������͈͓����蔻�艡��
	constexpr auto COMING_HEIGHT = 100;			//�U�������͈͓����蔻��c��
	constexpr auto ATTACK_WIDTH = 350;			//�U�������蔻�艡��
	constexpr auto ATTACK_HEIGHT = 150;			//�U�������蔻��c��
	constexpr auto COMINGCANCEL_WIDTH = 1000;	//�ǐՒ��~�����蔻�艡��
	constexpr auto COMINGCANCEL_HEIGHT = 100;	//�ǐՒ��~�����蔻��c��
	constexpr auto ATTACKCANCEL_WIDTH = 350;	//�U�����~�����蔻�艡��
	constexpr auto ATTACKCANCEL_HEIGHT = 100;	//�U�����~�����蔻��c��

	/*----------�p�����[�^�[�֌W----------*/
	constexpr auto LIFE_MAX = 1;				//�̗�
	constexpr auto SPEED = 1;					//�ړ����x
	constexpr auto PLAYER_IAI_MAX = 5;			//�v���C���[�̋����ő�l

	/*----------�摜�ǂݍ���&�A�j���[�V����&����t���[���֌W----------*/
	//����
	constexpr auto GRAPH_WIDTH = 840;			//1��������̉摜�T�C�Y�i���j
	constexpr auto GRAPH_HEIGHT = 630;			//1��������̉摜�T�C�Y�i�c�j
	constexpr auto GRAPH_SCALE = 1.0;			//�g�嗦
	constexpr auto GRAPH_ANGLE = 0;				//�p�x
	//�o��
	constexpr auto APPEAR_GRAPHNAME = "res/Shielder/T_Stand.png";	//�摜�t�@�C����
	constexpr auto APPEAR_ANIMEMAX = 1;			//�S�Ẳ摜����
	constexpr auto APPEAR_WIDTHCOUNT = 1;		//���̉摜����
	constexpr auto APPEAR_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_APPEAR = 60;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto FADEIN_SPEED = 4;			//�A�b�p�[���̃t�F�[�h�C���X�s�[�h
	constexpr auto APPEAR_ALLFRAME = 60;		//�o���S�t���[��
	//����
	constexpr auto PATROL_GARAPHNAME = "res/Shielder/T_Stand.png";	//�摜�t�@�C����
	constexpr auto PATROL_ANIMEMAX = 1;			//�S�Ẳ摜����
	constexpr auto PATROL_WIDTHCOUNT = 1;		//���̉摜����
	constexpr auto PATROL_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_PATROL = 5;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto PATROL_TURNFRAME = 180;		//����̐U������t���[��
	//�ǐ�
	constexpr auto COMING_GRAPHNAME = "res/Shielder/T_Walk.png";	//�摜�t�@�C����
	constexpr auto COMING_ANIMEMAX = 4;			//�S�Ẳ摜����
	constexpr auto COMING_WIDTHCOUNT = 4;		//���̉摜����
	constexpr auto COMING_HEIGHTCOUNT = 1;		//�c�̉摜����	
	constexpr auto ANIMESPEED_COMING = 30;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	//�U��
	constexpr auto ATTACK_GRAPHNAME = "res/Shielder/T_Attack.png";	//�摜�t�@�C����
	constexpr auto ATTACK_ANIMEMAX = 4;			//�S�Ẳ摜����
	constexpr auto ATTACK_WIDTHCOUNT = 4;		//���̉摜����
	constexpr auto ATTACK_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_ATTACK = 20;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto ATTACK_ANIMEFRAME = ATTACK_ANIMEMAX * ANIMESPEED_ATTACK;		//�A�j���[�V�����t���[���i�S�Ẳ摜�����~�A�j���X�s�[�h�j
	constexpr auto ATTACK_ALLFRAME = 100;		//�U���S�t���[���i�S�t���[��-�A�j���[�V�����t���[�����U���P�\���ԁj
	constexpr auto ATTACK_BEGINFRAME = 20;		//�U�����蔭���t���[��
	constexpr auto ATTACK_ENDFRAME = 20;		//�U������I���t���[��
	constexpr auto STEP_BEGINFRAME = 20;		//�U�����̈ړ��J�n�t���[��
	constexpr auto ATTACK_STEP = 60;			//�U�����̈ړ�����
	//�������U��
	constexpr auto GUARDATTACK_GRAPHNAME = "res/Shielder/T_GuardAttack.png";	//�摜�t�@�C����
	constexpr auto GUARDATTACK_ANIMEMAX = 4;		//�S�Ẳ摜����
	constexpr auto GUARDATTACK_WIDTHCOUNT = 4;		//���̉摜����
	constexpr auto GUARDATTACK_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_GUARDATTACK = 20;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto GUARDATTACK_ANIMEFRAME = GUARDATTACK_ANIMEMAX * ANIMESPEED_GUARDATTACK;//�A�j���[�V�����t���[���i�S�Ẳ摜�����~�A�j���X�s�[�h�j
	constexpr auto GUARDATTACK_ALLFRAME = 100;		//�U���S�t���[���i�S�t���[��-�A�j���[�V�����t���[�����U���P�\���ԁj
	constexpr auto GUARDATTACK_BEGINFRAME = 20;		//�U�����蔭���t���[��
	constexpr auto GUARDATTACK_ENDFRAME = 40;		//�U������I���t���[��
	//������
	constexpr auto GUARDBREAK_GRAPHNAME = "res/Shielder/T_Damage.png";	//�摜�t�@�C����
	constexpr auto GUARDBREAK_ANIMEMAX = 3;		//�S�Ẳ摜����
	constexpr auto GUARDBREAK_WIDTHCOUNT = 3;	//���̉摜����
	constexpr auto GUARDBREAK_HEIGHTCOUNT = 1;	//�c�̉摜����
	constexpr auto ANIMESPEED_GUARDBREAK = 15;	//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto GUARDBREAK_ANIMEFRAME = GUARDBREAK_ANIMEMAX * ANIMESPEED_GUARDBREAK;	//�A�j���[�V�����t���[���i�S�Ẳ摜�����~�A�j���X�s�[�h�j
	constexpr auto GUARDBREAK_ALLFRAME = 55;	//��_���S�t���[��
	//���S
	constexpr auto DEAD_GRAPHNAME = "res/Shielder/T_Dead.png";		//�摜�t�@�C����
	constexpr auto DEAD_ANIMEMAX = 3;			//�S�Ẳ摜����
	constexpr auto DEAD_WIDTHCOUNT = 3;			//���̉摜����
	constexpr auto DEAD_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_DEAD = 20;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto DEAD_ANIMEFRAME = DEAD_ANIMEMAX * ANIMESPEED_DEAD;		//�A�j���[�V�����t���[���i�S�Ẳ摜�����~�A�j���X�s�[�h�j
	constexpr auto DEAD_ALLFRAME = 120;			//���S�S�t���[��
	constexpr auto FADEOUT_SPEED = 4;			//�t�F�[�h�A�E�g�X�s�[�h
	
	/*----------���̍��W�֌W----------*/
	constexpr auto SHIELD_GRAPH_POINTX = 0;				//X�ʒu����`��_�܂ł̍���
	constexpr auto SHIELD_GRAPH_POINTY = -120;			//Y�ʒu����`��_�܂ł̍���
	constexpr auto SHIELD_POSITION_HITX = -45;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto SHIELD_POSITION_HITY = -135;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto SHIELD_COLLISION_WIDTH = 90;			//�����蔻�艡��
	constexpr auto SHIELD_COLLISION_HEIGHT = 450;		//�����蔻��c��

	/*----------���̋����֌W----------*/
	constexpr auto SHIELD_ANGLE = -0.0;
	constexpr auto SHIELD_DIFFPOINTX = -0;
	constexpr auto SHIELD_DIFFPOINTY = -55;
	constexpr auto SHIELD_ALPHA = 255;
	constexpr auto SHIELD_ANGLECHANGE = 0.03;
	constexpr auto SHIELD_ALPHACHANGE = 5;
	constexpr auto SHIELD_XCHANGE = 1;
	constexpr auto SHIELD_YCHANGE = 5;

	/*----------SE�֌W----------*/
	constexpr auto WALK_SE = "se/Footstep.wav";			//����
	constexpr auto ATTACK_SE = "se/slash3.wav";			//�U��	

};