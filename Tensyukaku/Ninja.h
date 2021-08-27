#pragma once
#include "EnemyBase.h"
#include <vector>
// �E�҃N���X

class Ninja : public EnemyBase {
public:
	Ninja(int x, int y, bool flip);
	~Ninja();
	virtual ENEMYTYPE	GetEneType() { return ENEMYTYPE::NINJA; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;

private:
	void	Patrol(Game& g);		//�����Ԏ��̏���
	void	Coming(Game& g);		//�ǐՏ�Ԏ��̏���
	void	Attack(Game& g);		//�U����Ԏ��̏���
	void	Dead(Game& g);			//���S��Ԏ��̏���
	void	LoadActionGraph();		//�E�҂̉摜�ǂݍ��݊֐�
	void	LoadActionSE();			//�E�҂�SE�ǂݍ��݊֐�
	void	AnimeUpdate(Game& g);	//�E�҂̃A�j���[�V�����֐�
	void	DebugDraw(Game& g);		//�f�o�b�O�p�֐�
};
namespace NInfo {
	/*----------�E�҂̊e���W�֌W----------*/
	constexpr auto GRAPHPOINT_X = 0;				//X�ʒu����`��_�܂ł̍���
	constexpr auto GRAPHPOINT_Y = -210;			//Y�ʒu����`��_�܂ł̍���
	constexpr auto POSITION_HITX = -40;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto POSITION_HITY = 70;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto COLLISION_WIDTH = 80;			//�����蔻�艡��
	constexpr auto COLLISION_HEIGHT = 140;		//�����蔻��c��

	/*----------�e���[�V�����̓����蔻��֌W----------*/
	constexpr auto PATROL_WIDTH = 1000;			//���G�͈͓����蔻�艡��
	constexpr auto PATROL_HEIGHT = 100;			//���G�͈͓����蔻��c��
	constexpr auto COMING_WIDTH = 200;			//�U�������͈͓����蔻�艡��
	constexpr auto COMING_HEIGHT = 100;			//�U�������͈͓����蔻��c��
	constexpr auto ATTACK_WIDTH = 100;			//�U�������蔻�艡��
	constexpr auto ATTACK_HEIGHT = 100;			//�U�������蔻��c��

	/*----------�p�����[�^�[�֌W----------*/
	constexpr auto LIFE_MAX = 1;					//�̗�
	constexpr auto SPPED = 3;					//�ړ����x

	/*----------�摜�ǂݍ���&�A�j���[�V����&����t���[���֌W----------*/
	//����
	constexpr auto GRAPH_WIDTH = 420;			//1��������̉摜�T�C�Y�i���j
	constexpr auto GRAPH_HEIGHT = 420;			//1��������̉摜�T�C�Y�i�c�j
	constexpr auto GRAPH_SCALE = 1.0;			//�g�嗦
	constexpr auto GRAPH_ANGLE = 0;				//�p�x
	//�ҋ@
	constexpr auto PATROL_GRAPHNAME = "res/Ninja/N_Stand.png";	//�摜�t�@�C����
	constexpr auto PATROL_ANIMEMAX = 1;			//�S�Ẳ摜����
	constexpr auto PATROL_WIDTHCOUNT = 1;		//���̉摜����
	constexpr auto PATROL_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_PATROL = 5;		//�e��ԃA�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto PATROL_ALLFRAME = 120;			//����S�t���[��
	//�ړ�
	constexpr auto COMING_GRAPHNAME = "res/Ninja/N_Walk.png";	//�摜�t�@�C����
	constexpr auto COMING_ANIMEMAX = 4;			//�S�Ẳ摜����
	constexpr auto COMING_WIDTHCOUNT = 4;		//���̉摜����
	constexpr auto COMING_HEIGHTCOUNT = 1;		//�c�̉摜����	
	constexpr auto ANIMESPEED_COMING = 10;		//�e��ԃA�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	//�U��
	constexpr auto ATTACK_GRAPHNAME = "res/Ninja/N_Attack.png";	//�摜�t�@�C����
	constexpr auto ATTACK_ANIMEMAX = 3;			//�S�Ẳ摜����
	constexpr auto ATTACK_WIDTHCOUNT = 3;		//���̉摜����
	constexpr auto ATTACK_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_ATTACK = 15;		//�e��ԃA�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto ATTACK_ALLFRAME = 40;			//�U���S�t���[��
	constexpr auto ATTACK_BEGINFRAME = 30;			//�U�������t���[��
	constexpr auto ATTACK_ENDFRAME = 10;				//�U���I���t���[��
	//���S
	constexpr auto DEAD_GRAPHNAME = "res/Ninja/N_Dead.png";		//�摜�t�@�C����
	constexpr auto DEAD_ANIMEMAX = 1;			//�S�Ẳ摜����
	constexpr auto DEAD_WIDTHCOUNT = 1;			//���̉摜����
	constexpr auto DEAD_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_DEAD = 60;		//�e��ԃA�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto DEAD_FRAME = 50;				//���S�S�t���[��
	/*----------SE�֌W----------*/
	constexpr auto WALK_SE = "se/Footstep.wav";			//����
	constexpr auto ATTACK_SE = "se/slash3.wav";			//�U��
}