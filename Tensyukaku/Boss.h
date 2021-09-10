#pragma once
#include "ObjectBase.h"

class Boss :public ObjectBase {
public:
	Boss(int x,int y);
	~Boss();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::BOSS; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
private:
	//�{�X�̏�ԗ�
	enum class BOSSSTATE {IDLE, EVENTA, EVENTB, EVENTC };
	void Idle(Game& g);				//�ҋ@��Ԏ��̏���
	void EventA(Game& g);			//�C�x���gA���̏���
	void EventB(Game& g);			//�C�x���gB���̏���
	void EventC(Game& g);			//�C�x���gC���̏���
	void LoadActionGraph();			//�{�X�̉摜�ǂݍ��݊֐�
	void LoadActionSE();			//�{�X�̌��ʉ��ǂݍ��݊֐�

	/*----------�����o�ϐ�-----------*/
	BOSSSTATE _State;
	int _WalkSpeed;

};

namespace BossInifo {
	constexpr auto GRAPHPOINT_X = 0;
	constexpr auto GRAPHPOINT_Y = -315;
	constexpr auto POSITION_HITX = -45;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto POSITION_HITY = -135;		//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto COLLISION_WIDTH = 90;		//�{�X�̓����蔻�艡��
	constexpr auto COLLISION_HEIGHT = 450;		//�{�X�̓����蔻��c��

	/*----------�摜�ǂݍ���&�A�j���[�V����&����t���[���֌W----------*/
	//����
	constexpr auto GRAPH_WIDTH = 630;			//1��������̉摜�T�C�Y�i���j
	constexpr auto GRAPH_HEIGHT = 630;			//1��������̉摜�T�C�Y�i�c�j
	//�ҋ@
	constexpr auto IDLE_GRAPHNAME = "res/Boss/BossIdle.png";	//�摜�t�@�C����
	constexpr auto IDLE_ANIMEMAX = 1;			//�S�Ẳ摜����
	constexpr auto IDLE_WIDTHCOUNT = 1;		//���̉摜����
	constexpr auto IDLE_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_IDLE = 1;			//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	//�ړ�
	constexpr auto MOVE_GRAPHNAME = "res/Boss/BossWalk.png";	//�摜�t�@�C����
	constexpr auto MOVE_ANIMEMAX = 6;			//�S�Ẳ摜����
	constexpr auto MOVE_WIDTHCOUNT = 6;			//���̉摜����
	constexpr auto MOVE_HEIGHTCOUNT = 1;		//�c�̉摜����	
	constexpr auto ANIMESPEED_WALK = 9;			//�����A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto ANIMESPEED_RUN = 6;			//����A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto MOVE_SEFRAME = 120;			//�ړ�SE�̊Ǘ��t���[��
	//���S
	constexpr auto DEAD_GRAPHNAME = "res/Boss/BossDead.png";	//�摜�t�@�C����
	constexpr auto DEAD_ANIMEMAX = 4;	//�S�Ẳ摜����
	constexpr auto DEAD_WIDTHCOUNT = 4;	//���̉摜����
	constexpr auto DEAD_HEIGHTCOUNT = 1;//�c�̉摜����
	constexpr auto ANIMESPEED_DEAD = 10;	//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto DEAD_ANIMEFRAME = DEAD_ANIMEMAX * ANIMESPEED_DEAD; //�A�j���[�V�����t���[��
	constexpr auto DEAD_ALLFRAME = 60;	//���S�S�t���[��(�S�t���[���[�A�j���[�V�����t���[�����P�\����)
}