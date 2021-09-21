#pragma once
#include "ObjectBase.h"

class Andon :public ObjectBase {
public:
	Andon( int x,int y);
	~Andon();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::ANDON; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
private:
	int _Flame_y;
	bool _AndonDrop_Flag;
	bool _PlayerFlip_Flag;
};

namespace AInfo {
	/*----------�s���̊e���W�֌W----------*/
	constexpr auto GRAPHPOINT_X = 0;			//X�ʒu����`��_�܂ł̍���
	constexpr auto GRAPHPOINT_Y = -112;			//Y�ʒu����`��_�܂ł̍���
	constexpr auto POSITION_HITX = -45;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto POSITION_HITY = -113;		//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto COLLISION_WIDTH = 90;		//�v���C���[�̓����蔻�艡��
	constexpr auto COLLISION_HEIGHT = 225;		//�v���C���[�̓����蔻��c��

	/*----------�摜�ǂݍ���&�A�j���[�V����&����t���[���֌W----------*/
	//����
	constexpr auto GRAPH_WIDTH = 90;			//1��������̉摜�T�C�Y�i���j
	constexpr auto GRAPH_HEIGHT = 225;			//1��������̉摜�T�C�Y�i�c�j
	
	constexpr auto ANDON_GRAPHNAME = "res/Gimik/Andon.png";	//�摜�t�@�C����
	constexpr auto ANDON_ANIMEMAX = 1;			//�S�Ẳ摜����
	constexpr auto ANDON_WIDTHCOUNT = 1;		//���̉摜����
	constexpr auto ANDON_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANDON_ALLFRAME = 90;			//�s�����|�ꂽ�ۂ̏��ł܂ł̃t���[��
	constexpr auto ANDON_DROPFRAME = 30;		//�s�����|�ꂫ��܂ł̃t���[��
	constexpr auto ANDON_DROPANGLE = 0.07;		//1�t���[��������̍s�����|���p�x
	constexpr auto ANDON_DROPANGLEMAX = 1.5;	//�s���̓|���p�x�̍ő�l
	constexpr auto ANDON_DROPMOVEX = 4;		//�s�����|�ꂽ�ۂ�X�̈ړ���
	constexpr auto ANDON_DROPMOVEY = 2;		//�s�����|�ꂽ�ۂ�Y�̈ړ���
	constexpr auto ANDON_FIREWIDTH = 100;		//��������鉊���Ƃ̋���(���S�_)
	constexpr auto ANDON_FIREFRAME1 = 40;		//�������������t���[��1
	constexpr auto ANDON_FIREFRAME2 = 60;		//�������������t���[��2
	constexpr auto ANDON_FIREFRAME3 = 80;		//�������������t���[��3
	constexpr auto ANDON_FADEOUTSPEED = 4;		//�t�F�[�h�A�E�g�X�s�[�h
	
}