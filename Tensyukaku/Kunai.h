/*****************************************************************//**
 * \file   Kunai.h
 * \brief  �E�Ҍ^��������N�i�C�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** �N�i�C */
class Kunai :public ObjectBase {
public:
   /**
    * \brief      �R���X�g���N�^
    * \param x    X���W
    * \param y    Y���W
    * \param flip ���]����
    * \param spd  ���x
    */
   Kunai(int x,int y,bool flip,int spd);
   /**
    * \brief �R���X�g���N�^
    */
   ~Kunai();
   /**
    * \brief                   �������z�֐��̃I�[�o�[���C�h
    * \param OBJECTTYPE::KUNAI �I�u�W�F�N�g�̎�ʁi�N�i�C�j��Ԃ�
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::KUNAI; }
   /**
    * \brief �������֐�
    */
   void Init()override;
   /**
    * \brief   �X�V�֐�
    * \param g �Q�[���̎Q��
    */
   void Process(Game& g)override;
   /**
    * \brief   �`��֐�
    * \param g �Q�[���̎Q��
    */
   void Draw(Game& g)override;
   /**
    * \brief   �I�u�W�F�N�g�̏����֐�
    * \param g �Q�[���̎Q��
    */
   void Delete(Game& g)override;

private:
   bool _repel_flag;    //!< �N�i�C���e���ꂽ���̃t���O
};