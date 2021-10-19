/*****************************************************************//**
 * \file   GameStartSelect.h
 * \brief  �Q�[���J�n�Z���N�g�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** �Q�[���J�n�Z���N�g */
class GameStartSelect :public ObjectBase {
public:
   /**
    * \brief �R���X�g���N�^
    */
   GameStartSelect();
   /**
    * \brief �f�X�g���N�^
    */
   ~GameStartSelect();
   /**
    * \brief                       �������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::GAMSTART �I�u�W�F�N�g�̎�ʁi�Q�[���J�n�Z���N�g�j��Ԃ�
    */
   virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::GAMESTART; }
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