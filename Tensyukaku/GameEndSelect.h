/*****************************************************************//**
 * \file   GameEndSelect.h
 * \brief  �Q�[���I���Z���N�g�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** �Q�[���I���Z���N�g */
class GameEndSelect :public ObjectBase {
public:
   /**
    * \brief �R���X�g���N�^
    */
   GameEndSelect();
   /**
    * \brief �f�X�g���N�^
    */
   ~GameEndSelect();
   /**
    * \brief                        //�������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::GAMEEND   //�I�u�W�F�N�g�̎�ʁi�Q�[���I���Z���N�g�j��Ԃ�
    */
   virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::GAMEEND; }
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
