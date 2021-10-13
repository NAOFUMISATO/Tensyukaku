/*****************************************************************//**
 * \file   PrivateCollision.h
 * \brief  �󂯑��Ŕ�������Ȃ������蔻��N���X�i�I�u�W�F�N�g�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
#include <tuple>

class PrivateCollision : public ObjectBase {
public:
   //�R���X�g���N�^ : �����iX���W,Y���W,�����蔻�艡��,�����蔻��c���j
   PrivateCollision(int x, int y, int hit_w, int hit_h);
   //�f�X�g���N�^
   ~PrivateCollision();
   //�������z�֐��̃I�[�o�[���C�h
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::PRIVATECOLLISION; }
   //������
   void   Init()override;
   //�f�o�b�O�p�����蔻��F�w��֐�
   void   SetColor(std::tuple<int, int, int> color) { _debug_color = color; }
};