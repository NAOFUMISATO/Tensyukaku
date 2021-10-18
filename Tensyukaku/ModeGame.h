/*****************************************************************//**
 * \file   ModeGame.h
 * \brief  ���[�h�C���Q�[���N���X�i���[�h�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
#include "BackGround.h"
#include "Player.h"
#include "GimikPlacement.h"
#include "EnemySpawn.h"
#include "EventHappen.h"
/** ���[�h�C���Q�[�� */
class ModeGame : public ModeBase
{
   typedef ModeBase base;
public:
   /**
     * \brief   �������֐�
     * \param g �Q�[���N���X�̎Q��
     */
   virtual bool Initialize(Game& g);
   /**
     * \brief   �I���֐�
     * \param g �Q�[���N���X�̎Q��
     */
   virtual bool Terminate(Game& g);
   /**
     * \brief   �X�V�֐�
     * \param g �Q�[���N���X�̎Q��
     */
   virtual bool Process(Game& g);
   /**
     * \brief   �`��֐�
     * \param g �Q�[���N���X�̎Q��
     */
   virtual bool Draw(Game& g);
   /**
    * \brief  �I�u�W�F�N�g�����̃X�g�b�v�����Ԃ��֐�
    * \return �I�u�W�F�N�g�����̃X�g�b�v����
    */
   bool GetstopObjProcess() { return _stop_obj_process; }
   /**
    * \brief                �I�u�W�F�N�g�����̃X�g�b�v����̐ݒ�֐�
    * \param stopobjprocess �I�u�W�F�N�g�����̃X�g�b�v����
    */
   void SetStopObjProcess(bool stopobjprocess) { _stop_obj_process = stopobjprocess; }

private:
   int _player_y;                  //!< �C���X�^���X���������v���C���[�̏���Y���W
   int _player_x;                  //!< �C���X�^���X���������v���C���[�̏���X���W
   bool _player_flip;              //!< �C���X�^���X���������v���C���[�̏������]����
   bool _stop_obj_process;         //!< �I�u�W�F�N�g�����̃X�g�b�v����
   BackGround _bg;                 //!< �w�i�N���X�ϐ�
   GimikPlacement* _gimikplacement;//!< �M�~�b�N�̔z�u�N���X�ϐ�
   EnemySpawn* _enemyspawn;        //!< �G�X�|�[���u���b�N�̔z�u�N���X�ϐ�
   EventHappen* _eventhappen;      //!< �C�x���g�u���b�N�̔z�u�N���X�ϐ�
};