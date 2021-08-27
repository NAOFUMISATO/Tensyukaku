#pragma once
#include "EnemyBase.h"

class Shielder :public EnemyBase {
public:
	Shielder(int x, int y, bool flip);
	~Shielder();
	virtual ENEMYTYPE	GetEneType() { return ENEMYTYPE::SHIELDER; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;
private:
	void	Patrol(Game& g);		//�����Ԏ��̏���
	void	Coming(Game& g);		//�ǐՏ�Ԏ��̏���
	void	Attack(Game& g);		//�U����Ԏ��̏���
	void	GuardBreak(Game& g);	//��������Ԏ��̏���
	void	Dead(Game& g);			//���S��Ԏ��̏���
	void	ShieldDraw(Game& g);	//���̕`��֐�
	void	LoadActionGraph();		//�E�҂̉摜�ǂݍ��݊֐�
	void	LoadActionSE();			//�E�҂�SE�ǂݍ��݊֐�
	void	AnimeUpdate(Game& g);	//�E�҂̃A�j���[�V�����֐�
	void	DebugDraw(Game& g);		//�f�o�b�O�p�֐�

	bool	_Shield_Flag;		//���̐����t���O
	int		_Shield_Cnt;		
};

namespace SInfo {
	/*----------�����̊e���W�֌W----------*/
	constexpr auto GRAPHPOINT_X = 0;				//X�ʒu����`��_�܂ł̍���
	constexpr auto GRAPHPOINT_Y = -315;			//Y�ʒu����`��_�܂ł̍���
	constexpr auto POSITION_HITX = -30;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto POSITION_HITY = -90;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto COLLISION_WIDTH = 60;			//�����蔻�艡��
	constexpr auto COLLISION_HEIGHT = 300;		//�����蔻��c��
	
	/*----------�e���[�V�����̓����蔻��֌W----------*/
	constexpr auto PATROL_WIDTH = 500;			//���G�͈͓����蔻�艡��
	constexpr auto PATROL_HEIGHT = 100;			//���G�͈͓����蔻��c��
	constexpr auto COMING_WIDTH = 200;			//�U�������͈͓����蔻�艡��
	constexpr auto COMING_HEIGHT = 100;			//�U�������͈͓����蔻��c��
	constexpr auto ATTACK_WIDTH = 150;			//�U�������蔻�艡��
	constexpr auto ATTACK_HEIGHT = 100;			//�U�������蔻��c��

	/*----------�p�����[�^�[�֌W----------*/
	constexpr auto LIFE_MAX = 1;				//�̗�
	constexpr auto SPEED = 1;					//�ړ����x

	/*----------�摜�ǂݍ���&�A�j���[�V����&����t���[���֌W----------*/
	//����
	constexpr auto GRAPH_WIDTH = 840;			//1��������̉摜�T�C�Y�i���j
	constexpr auto GRAPH_HEIGHT = 630;			//1��������̉摜�T�C�Y�i�c�j
	constexpr auto GRAPH_SCALE = 1.0;			//�g�嗦
	constexpr auto GRAPH_ANGLE = 0;				//�p�x
	//����
	constexpr auto PATROL_GARAPHNAME = "res/Shielder/T_Stand.png";	//�摜�t�@�C����
	constexpr auto PATROL_ANIMEMAX = 1;			//�S�Ẳ摜����
	constexpr auto PATROL_WIDTHCOUNT = 1;		//���̉摜����
	constexpr auto PATROL_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_PATROL = 5;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto PATROL_TURNFRAME = 180;		//����̐U������t���[��
	//�ړ�
	constexpr auto COMING_GRAPHNAME = "res/Shielder/T_Walk.png";	//�摜�t�@�C����
	constexpr auto COMING_ANIMEMAX = 4;			//�S�Ẳ摜����
	constexpr auto COMING_WIDTHCOUNT = 4;		//���̉摜����
	constexpr auto COMING_HEIGHTCOUNT = 1;		//�c�̉摜����	
	constexpr auto ANIMESPEED_COMING = 30;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	//�U��
	constexpr auto ATTACK_GRAPHNAME = "res/Shielder/T_Attack.png";	//�摜�t�@�C����
	constexpr auto ATTACK_ANIMEMAX = 3;			//�S�Ẳ摜����
	constexpr auto ATTACK_WIDTHCOUNT = 3;		//���̉摜����
	constexpr auto ATTACK_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_ATTACK = 20;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto ATTACK_ALLFRAME = 40;		//�U���S�t���[��
	constexpr auto ATTACK_BEGINFRAME = 15;		//�U�����蔭���t���[��
	constexpr auto ATTACK_ENDFRAME = 15;		//�U������I���t���[��
	//������
	constexpr auto GUARDBREAK_GRAPHNAME = "res/Shielder/T_Damage.png";	//�摜�t�@�C����
	constexpr auto GUARDBREAK_ANIMEMAX = 3;		//�S�Ẳ摜����
	constexpr auto GUARDBREAK_WIDTHCOUNT = 3;	//���̉摜����
	constexpr auto GUARDBREAK_HEIGHTCOUNT = 1;	//�c�̉摜����
	constexpr auto ANIMESPEED_GUARDBREAK = 15;	//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto GUARDBREAK_ALLFRAME = 44;	//��_���S�t���[��
	//���S
	constexpr auto DEAD_GRAPHNAME = "res/Shielder/T_Dead.png";		//�摜�t�@�C����
	constexpr auto DEAD_ANIMEMAX = 1;			//�S�Ẳ摜����
	constexpr auto DEAD_WIDTHCOUNT = 1;			//���̉摜����
	constexpr auto DEAD_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_DEAD = 60;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto DEAD_ALLFRAME = 50;				//���S�S�t���[��
	
	/*----------���̍��W�֌W----------*/
	constexpr auto SHIELD_WIDTH = 160;
	constexpr auto SHIELD_HEIGHT = 230;
	constexpr auto SHIELD_GRAPH_POINTX = 0;
	constexpr auto SHIELD_GRAPH_POINTY = -80;

	/*----------���̋����֌W----------*/
	constexpr auto SHIELD_ANGLE = -0.2;
	constexpr auto SHIELD_DIFFPOINTX = -0;
	constexpr auto SHIELD_DIFFPOINTY = -90;
	constexpr auto SHIELD_ALPHA = 255;
	constexpr auto SHIELD_ANGLECHANGE = 0.03;
	constexpr auto SHIELD_ALPHACHANGE = 5;
	constexpr auto SHIELD_XCHANGE = 1;
	constexpr auto SHIELD_YCHANGE = 5;

	/*----------SE�֌W----------*/
	constexpr auto WALK_SE = "se/Footstep.wav";			//����
	constexpr auto ATTACK_SE = "se/slash3.wav";			//�U��	

};