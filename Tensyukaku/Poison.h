#pragma once
#include "ObjectBase.h"
//�ŉt�̏������y�ї������̃N���X
class PoisonReserve :public ObjectBase {
public:
   PoisonReserve(int x, int y);
   ~PoisonReserve();

   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::POISON; }

   void Init();
   void Process(Game& g)override;
   void Draw(Game& g)override;
   void Delete(Game& g)override;
};

class PoisonFall :public ObjectBase {
public:
   PoisonFall(int x, int y);
   ~PoisonFall();

   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::POISON; }

   void Init();
   void Process(Game& g)override;
   void Draw(Game& g)override;
   void Delete(Game& g)override;
private:
   enum class POISONSTATE {FALL,LAND};
   POISONSTATE _State;
   int _Appear_y;
};

namespace PoInfo {
   /*----------�ŉt�����̊e���W�֌W----------*/
   constexpr auto GRAPHPOINT_X = 0;      //X�ʒu����`��_�܂ł̍���
   constexpr auto GRAPHPOINT_Y = 25;      //Y�ʒu����`��_�܂ł̍���
   constexpr auto POSITION_HITX = -20;      //�`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto POSITION_HITY = -30;      //�`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto COLLISION_WIDTH = 40;   //�����蔻�艡��
   constexpr auto COLLISION_HEIGHT = 60;   //�����蔻��c��
   
   /*----------�摜�ǂݍ���&�A�j���[�V����&����t���[���֌W----------*/
   constexpr auto GRAPH_WIDTH = 90;      //1��������̉摜�T�C�Y�i���j
   constexpr auto GRAPH_HEIGHT = 90;      //1��������̉摜�T�C�Y�i�c�j
   //�ŉt����
   constexpr auto RESERVE_GRAPHNAME = "res/Gimik/PoisonReserve.png";   //�摜�t�@�C����
   constexpr auto RESERVE_ANIMEMAX = 4;      //�S�Ẳ摜����
   constexpr auto RESERVE_WIDTHCOUNT = 4;      //���̉摜����
   constexpr auto RESERVE_HEIGHTCOUNT = 1;      //�c�̉摜����
   constexpr auto ANIMESPEED_RESERVE = 30;      //�e��ԃA�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto RESERVE_FALLFRAME = 90;         //������Ԃ���ŉt�������n�߂�t���[��
   constexpr auto RESERVE_ANIMEFRAME = RESERVE_ANIMEMAX * ANIMESPEED_RESERVE;      //�A�j���[�V�����t���[���i�S�Ẳ摜�����~�A�j���X�s�[�h�j
   constexpr auto RESERVE_FADEOUTSPEED = 8;      //�t�F�[�h�X�s�[�h
   constexpr auto RESERVE_ALLFRAME = 150;      //�ŉt�����̑S�t���[��
   //�ŉt����
   constexpr auto FALL_GRAPHNAME = "res/Gimik/PoisonFall.png";   //�摜�t�@�C����
   constexpr auto FALL_ANIMEMAX = 1;         //�S�Ẳ摜����
   constexpr auto FALL_WIDTHCOUNT = 1;         //���̉摜����
   constexpr auto FALL_HEIGHTCOUNT = 1;      //�c�̉摜����
   constexpr auto FALL_STOPFRAME = 41;      //�������~�܂�t���[��
   //�ŉt���n
   constexpr auto LAND_GRAPHNAME = "res/Gimik/PoisonLand.png";   //�摜�t�@�C����
   constexpr auto LAND_ANIMEMAX = 3;         //�S�Ẳ摜����
   constexpr auto LAND_WIDTHCOUNT = 3;         //���̉摜����
   constexpr auto LAND_HEIGHTCOUNT = 1;      //�c�̉摜����
   constexpr auto ANIMESPEED_LAND = 10;      //�e��ԃA�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto LAND_ANIMEFRAME = LAND_ANIMEMAX * ANIMESPEED_LAND;            //�A�j���[�V�����t���[���i�S�Ẳ摜�����~�A�j���X�s�[�h�j
   constexpr auto LAND_FADEOUTSPEED = 8;      //�t�F�[�h�X�s�[�h
   constexpr auto LAND_ALLFRAME = 60;      //�ŉt�̑S�t���[��
}