#pragma once
#include "ObjectBase.h"

class PoisonNinja :public  ObjectBase {
public:
	PoisonNinja(int x,int y,bool flip);
	~PoisonNinja();

	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::POISONNINJA; }
	void Init();
	void Process(Game& g)override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
private:
	//�G�̏�ԗ�
	enum class ENEMYSTATE{
	APPEAR,PATROL,POISING
	};
	void Appear(Game& g);
	void Patrol(Game& g);
	void Poising(Game& g);

/*-----�����o�ϐ�-----*/
	ENEMYSTATE _State;
	int _Appear_y;
	bool _Keep_Flag;
};


namespace PNInfo{
/*----------�ŉt�E�҂̊e���W�֌W----------*/
constexpr auto GRAPHPOINT_X = 0;			//X�ʒu����`��_�܂ł̍���
constexpr auto GRAPHPOINT_Y = -315;			//Y�ʒu����`��_�܂ł̍���
/*----------�e���[�V�����̓����蔻��֌W----------*/
constexpr auto PATROL_WIDTH = 500;			//���G�͈͓����蔻�艡��
constexpr auto PATROL_HEIGHT = 500;			//���G�͈͓����蔻��c��
constexpr auto POISINGCANCEL_WIDTH = 500;	//�ŉt���炵���~�����蔻�艡��
constexpr auto POISINGCANCEL_HEIGHT = 500;	//�ŉt���炵���~�����蔻��c��

/*----------�摜�ǂݍ���&�A�j���[�V����&����t���[���֌W----------*/
//����
constexpr auto GRAPH_WIDTH = 630;			//1��������̉摜�T�C�Y�i���j
constexpr auto GRAPH_HEIGHT = 630;			//1��������̉摜�T�C�Y�i�c�j
//�o��
constexpr auto APPEAR_GRAPHNAME = "res/Gimik/N_Poison_Stand.png";	//�摜�t�@�C����
constexpr auto APPEAR_ANIMEMAX = 1;			//�S�Ẳ摜����
constexpr auto APPEAR_WIDTHCOUNT = 1;		//���̉摜����
constexpr auto APPEAR_HEIGHTCOUNT = 1;		//�c�̉摜����
constexpr auto ANIMESPEED_APPEAR = 60;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
constexpr auto FADEIN_SPEED = 4;			//�A�b�p�[���̃t�F�[�h�C���X�s�[�h
constexpr auto APPEAR_ALLFRAME = 60;		//�o���S�t���[��
//���G
constexpr auto PATROL_GRAPHNAME = "res/Gimik/N_Poison_Stand.png";	//�摜�t�@�C����
constexpr auto PATROL_ANIMEMAX = 1;			//�S�Ẳ摜����
constexpr auto PATROL_WIDTHCOUNT = 1;		//���̉摜����
constexpr auto PATROL_HEIGHTCOUNT = 1;		//�c�̉摜����
constexpr auto ANIMESPEED_PATROL = 60;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
constexpr auto PATROL_TURNFRAME = 120;		//���G���̐U������t���[��
//�ŉt���炵
constexpr auto POISING_GRAPHNAME = "res/Gimik/N_Poison.png";	//�摜�t�@�C����
constexpr auto POISING_ANIMEMAX = 2;		//�S�Ẳ摜����
constexpr auto POISING_WIDTHCOUNT = 2;		//���̉摜����
constexpr auto POISING_HEIGHTCOUNT = 1;		//�c�̉摜����
constexpr auto ANIMESPEED_POISING = 40;		//�e��ԃA�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
constexpr auto POISING_ANIMEFRAME = POISING_ANIMEMAX * ANIMESPEED_POISING;		//�A�j���[�V�����t���[���i�S�Ẳ摜�����~�A�j���X�s�[�h�j
constexpr auto POISING_ALLFRAME = 230;		//�ŉt���炵�S�t���[��
constexpr auto POISON_SPAWN_X = 170;		//�E�҂���̓ŉt�����ݍ��ލ��W�ւ�X����
constexpr auto POISON_SPAWN_Y = 80;			//�E�҂���̓ŉt�����ݍ��ލ��W�ւ�Y����
//����
constexpr auto DELETE_HEIGHT = 500;			//�ŉt�E�҂�������Y�̈ړ���
constexpr auto FADEOUT_SPEED = 10;			//�t�F�[�h�X�s�[�h
}