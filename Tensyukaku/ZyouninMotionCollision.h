/*****************************************************************//**
 * \file   ZyouninMotionCollision.h
 * \brief  ��E�̍U�������蔻��N���X�i�I�u�W�F�N�g�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"

class ZyouninAttackCollision : public ObjectBase {
public:
   //�R���X�g���N�^ : �����iX���W,Y���W�j
   ZyouninAttackCollision(int x, int y);
   //�f�X�g���N�^
   ~ZyouninAttackCollision();
   //�������z�֐��̃I�[�o�[���C�h
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::ZYOUNINATTACK; }
   //������
   void Init()override;
   //�X�V
   void Process(Game& g)override;
   //�`��
   void Draw(Game& g)override;
   //�I�u�W�F�N�g�̏����֐�
   void Delete(Game& g)override;
};
