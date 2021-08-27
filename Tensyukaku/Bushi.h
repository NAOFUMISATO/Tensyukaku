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
	void	Patrol(Game& g);		//�����Ԏ��̏���
	void	Coming(Game& g);		//�ǐՏ�Ԏ��̏���
	void	Attack(Game& g);		//�U����Ԏ��̏���
	void	Damage(Game& g);		//��_����Ԏ��̏���
	void	Dead(Game& g);			//���S��Ԏ��̏���
	void	LoadActionGraph();		//���m�̉摜�ǂݍ��݊֐�
	void	LoadActionSE();			//���m��SE�ǂݍ��݊֐�
	void	AnimeUpdate(Game& g);	//���m�̃A�j���[�V�����֐�
	void	DebugDraw(Game& g);		//�f�o�b�O�p�֐�
};

namespace BInfo {
	/*----------���m�̊e���W�֌W----------*/
	constexpr auto GRAPHPOINT_X = 0;				//X�ʒu����`��_�܂ł̍���
	constexpr auto GRAPHPOINT_Y = -210;			//Y�ʒu����`��_�܂ł̍���
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
	constexpr auto LIFE_MAX = 3;					//�̗�
	constexpr auto SPEED = 2;					//�ړ����x
	
	/*----------�摜�ǂݍ���&�A�j���[�V����&����t���[���֌W----------*/
	//����
	constexpr auto GRAPH_WIDTH = 540;			//1��������̉摜�T�C�Y�i���j
	constexpr auto GRAPH_HEIGHT = 420;			//1��������̉摜�T�C�Y�i�c�j
	constexpr auto GRAPH_SCALE = 1.0;			//�g�嗦
	constexpr auto GRAPH_ANGLE = 0;				//�p�x
	//����
	constexpr auto PATROL_GRAPHNAME = "res/Bushi/B_Stand.png";	//�摜�t�@�C����
	constexpr auto PATROL_ANIMEMAX = 1;			//�S�Ẳ摜����
	constexpr auto PATROL_WIDTHCOUNT = 1;		//���̉摜����
	constexpr auto PATROL_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_PATROL = 5;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto PATROL_FRAME = 180;			//����S�t���[��
	//�ړ�
	constexpr auto COMING_GRAPHNAME = "res/Bushi/B_Walk.png";	//�摜�t�@�C����
	constexpr auto COMING_ANIMEMAX = 4;			//�S�Ẳ摜����
	constexpr auto COMING_WIDTHCOUNT = 4;		//���̉摜����
	constexpr auto COMING_HEIGHTCOUNT = 1;		//�c�̉摜����	
	constexpr auto ANIMESPEED_COMING = 30;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	//�U��
	constexpr auto ATTACK_GRAPHNAME = "res/Bushi/B_Attack.png";	//�摜�t�@�C����
	constexpr auto ATTACK_ANIMEMAX = 3;			//�S�Ẳ摜����
	constexpr auto ATTACK_WIDTHCOUNT = 3;		//���̉摜����
	constexpr auto ATTACK_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_ATTACK = 15;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto ATTACK_ALLFRAME = 40;		//�U���S�t���[��
	constexpr auto ATTACK_BEGINFRAME = 15;		//�U�����蔭���t���[��
	constexpr auto ATTACK_ENDFRAME = 15;		//�U������I���t���[��
	//��_��
	constexpr auto DAMAGE_GRAPHNAME = "res/Bushi/B_Damage.png";	//�摜�t�@�C����
	constexpr auto DAMAGE_ANIMEMAX = 3;			//�S�Ẳ摜����
	constexpr auto DAMAGE_WIDTHCOUNT = 3;		//���̉摜����
	constexpr auto DAMAGE_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_DAMAGE = 15;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto DAMAGE_ALLFRAME = 44;		//��_���S�t���[��
	//���S
	constexpr auto DEAD_GRAPHNAME = "res/Bushi/B_Dead.png";		//�摜�t�@�C����
	constexpr auto DEAD_ANIMEMAX = 1;			//�S�Ẳ摜����
	constexpr auto DEAD_WIDTHCOUNT = 1;			//���̉摜����
	constexpr auto DEAD_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_DEAD = 60;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto DEAD_ALLFRAME = 50;			//���S�S�t���[��
	/*----------SE�֌W----------*/
	constexpr auto WALK_SE = "se/Footstep.wav";			//����
	constexpr auto ATTACK_SE = "se/slash3.wav";			//�U��	

}