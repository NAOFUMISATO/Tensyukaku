/*****************************************************************//**
 * \file   EventHappen.h
 * \brief  �C�x���g�u���b�N�̃C���X�^���X�����N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
//��d�C���N���[�h�h�~
class Game;
/** �C�x���g�u���b�N�̃C���X�^���X���� */
class EventHappen {
public:
   /**
    * \brief   �R���X�g���N�^
    * \param g �Q�[���̎Q��
    */
   EventHappen(Game& g);
   /**
    * \brief �f�X�g���N�^
    */
   ~EventHappen();
   /**
    * \brief   �������֐�
    * \param g �Q�[���̎Q��
    */
   void Init(Game& g);

private:
   /**
    * \brief   �`���[�g���A���{�[�h�����֐�
    * \param g �Q�[���̎Q��
    */
   void TutorialAppear(Game& g);
   /**
    * \brief   �`�F�b�N�|�C���g�u���b�N�����֐�
    * \param g �Q�[���̎Q��
    */
   void CPointAppear(Game& g);
   /**
    * \brief   �{�X�C�x���g�u���b�N�����֐�
    * \param g �Q�[���̎Q��
    */
   void BossEventAppear(Game& g);
   /**
    * \brief   �C���Q�[���ł̊K�w�\���u���b�N�����֐�
    * \param g �Q�[���̎Q��
    */
   void IngameTextAppear(Game& g);
   /**
    * \brief   �񕜃|�C���g�u���b�N�����֐�
    * \param g �Q�[���̎Q��
    */
   void RecoveryAppear(Game& g);
   /**
    * \brief   �����o�u���b�N�����֐�
    * \param g �Q�[���̎Q��
    */
   void FlameAppear(Game& g);
};