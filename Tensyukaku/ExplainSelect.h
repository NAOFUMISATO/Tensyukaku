/*****************************************************************//**
 * \file   ExplainSelect.h
 * \brief  ������ʃZ���N�g�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** ������ʃZ���N�g */
class ExplainSelect :public ObjectBase {
public:
   /**
    * \brief �R���X�g���N�^
    */
   ExplainSelect();
   /**
    * \brief �f�X�g���N�^
    */
   ~ExplainSelect();
   /**
    * \brief                        //�������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::EXPLAIN   //�I�u�W�F�N�g�̎�ʁi������ʃZ���N�g�j��Ԃ�
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::EXPLAIN; }
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
};