/*****************************************************************//**
 * \file   EnemySpawn.h
 * \brief  �X�|�[���u���b�N�̃C���X�^���X�����N���X
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
//��d�C���N���[�h�h�~
class Game;
/** �X�|�[���u���b�N�̃C���X�^���X���� */
class EnemySpawn {
public:
   /**
    * \brief   �R���X�g���N�^
    * \param g �Q�[���̎Q��
    */
   EnemySpawn(Game& g);
   /**
    * \brief �f�X�g���N�^
    */
   ~EnemySpawn();
   /**
    * \brief   �������֐�
    * \param g �Q�[���̎Q��
    */
   void Init(Game& g);
};
