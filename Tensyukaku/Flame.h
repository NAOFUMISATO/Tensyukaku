#pragma once
#include "ObjectBase.h"

class Flame :public ObjectBase {
public:
	Flame(int x,int y);
	~Flame();

	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::FLAME; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
};

namespace FInfo {
	/*----------���̊e���W�֌W----------*/
	constexpr auto GRAPHPOINT_X = 0;		//X�ʒu����`��_�܂ł̍���
	constexpr auto GRAPHPOINT_Y = -150;		//Y�ʒu����`��_�܂ł̍���
	constexpr auto POSITION_HITX = -150;	//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto POSITION_HITY = -150;	//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto COLLISION_WIDTH = 300;	//�����蔻�艡��
	constexpr auto COLLISION_HEIGHT = 300;	//�����蔻��c��
	/*----------�摜�ǂݍ���&�A�j���[�V����&����t���[���֌W----------*/
	constexpr auto GRAPH_WIDTH = 300;		//1��������̉摜�T�C�Y�i���j
	constexpr auto GRAPH_HEIGHT = 300;		//1��������̉摜�T�C�Y�i�c�j
	//��
	constexpr auto FLAME_GRAPHNAME = "res/Gimik/Flame.png";	//�摜�t�@�C����
	constexpr auto FLAME_ANIMEMAX = 7;		//�S�Ẳ摜����
	constexpr auto FLAME_WIDTHCOUNT = 7;		//���̉摜����
	constexpr auto FLAME_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_FLAME = 15;		//�e��ԃA�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto FLAME_ANIMEFRAME = FLAME_ANIMEMAX * ANIMESPEED_FLAME;		//�A�j���[�V�����t���[���i�S�Ẳ摜�����~�A�j���X�s�[�h�j
	constexpr auto FLAME_ALLFLAME = 135;
	constexpr auto FLAME_FADEOUTSPEED = 4;		//�t�F�[�h�X�s�[�h
	
}