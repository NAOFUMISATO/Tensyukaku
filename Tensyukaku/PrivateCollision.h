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
/** �󂯑��Ŕ�������Ȃ������蔻�� */
class PrivateCollision : public ObjectBase {
public:
   /**
    * \bruef   �R���X�g���N�^
    * \param x X���W
    * \param y Y���W
    * \param hit_w �����蔻�艡��
    * \param hit_h �����蔻��c��
    */
   PrivateCollision(int x, int y, int hit_w, int hit_h);
   /**
    * \brief �f�X�g���N�^
    */
   ~PrivateCollision();
   /**
   * \brief                                �������z�֐��̃I�[�o�[���C�h
   * \return OBJECTTYPE::PRIVATECOLLISION  �I�u�W�F�N�g�̎�ʁi�󂯑��Ŕ�������Ȃ������蔻��j��Ԃ�
   */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::PRIVATECOLLISION; }
   /**
    * \brief �������֐�
    */
   void Init()override;
   /**
    * \brief       �f�o�b�O�p�����蔻��F�w��֐�
    * \param color �f�o�b�N�p��`�J���[
    */
   void SetColor(std::tuple<int, int, int> color) { _debug_color = color; }
};