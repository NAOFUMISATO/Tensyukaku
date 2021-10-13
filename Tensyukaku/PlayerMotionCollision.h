/*****************************************************************//**
 * \file   PlayerMotionCollision.h
 * \brief  ���i�U���A���i�U���A�R��A�����A����U�������蔻��N���X�i�I�u�W�F�N�g�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"

/*---���i�U�������蔻��N���X---*/
class MiddleAttackCollision : public ObjectBase {
public:
   //�R���X�g���N�^ : �����iX���W,Y���W�j
   MiddleAttackCollision(int x, int y);
   //�f�X�g���N�^
   ~MiddleAttackCollision();
   //�������z�֐��̃I�[�o�[���C�h
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::MIDDLEATTACK; }
   //������
   void Init()override;
   //�X�V
   void Process(Game& g)override;
   //�`��
   void Draw(Game& g)override;
   //�I�u�W�F�N�g�̏����֐�
   void Delete(Game& g)override;
};

/*---���i�U�������蔻��N���X---*/
class LowAttackCollision : public ObjectBase {
public:
   //�R���X�g���N�^ : �����iX���W,Y���W�j
   LowAttackCollision(int x, int y);
   //�f�X�g���N�^
   ~LowAttackCollision();
   //�������z�֐��̃I�[�o�[���C�h
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::LOWATTACK; }
   //������
   void Init()override;
   //�X�V
   void Process(Game& g)override;
   //�`��
   void Draw(Game& g)override;
   //�I�u�W�F�N�g�̏����֐�
   void Delete(Game& g)override;
};

/*---�R�蓖���蔻��N���X---*/
class KickCollision : public ObjectBase {
public:
   //�R���X�g���N�^ : �����iX���W,Y���W�j
   KickCollision(int x, int y);
   //�f�X�g���N�^
   ~KickCollision();
   //�������z�֐��̃I�[�o�[���C�h
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::KICK; }
   //������
   void Init()override;
   //�X�V
   void Process(Game& g)override;
   //�`��
   void Draw(Game& g)override;
   //�I�u�W�F�N�g�̏����֐�
   void Delete(Game& g)override;
};

/*---���������蔻��N���X---*/
class IaiCollision : public ObjectBase {
public:
   //�R���X�g���N�^ : �����iX���W,Y���W�j
   IaiCollision(int x, int y);
   //�f�X�g���N�^
   ~IaiCollision();
   //�������z�֐��̃I�[�o�[���C�h
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::IAI; }
   //������
   void Init()override;
   //�X�V
   void Process(Game& g)override;
   //�`��
   void Draw(Game& g)override;
   //�I�u�W�F�N�g�̏����֐�
   void Delete(Game& g)override;
};

/*---����U�������蔻��N���X---*/
class SpecialCollision : public ObjectBase {
public:
   //�R���X�g���N�^ : �����iX���W,Y���W�j
   SpecialCollision(int x, int y);
   //�f�X�g���N�^
   ~SpecialCollision();
   //�������z�֐��̃I�[�o�[���C�h
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::SPECIAL; }
   //������
   void Init()override;
   //�X�V
   void Process(Game& g)override;
   //�`��
   void Draw(Game& g)override;
   //�I�u�W�F�N�g�̏����֐�
   void Delete(Game& g)override;
};
