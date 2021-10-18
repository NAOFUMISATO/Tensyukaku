/*****************************************************************//**
 * \file   BossBlood.h
 * \brief  �{�X�̌����Ԃ��G�t�F�N�g�N���X(�G�t�F�N�g�x�[�X�̃T�u�N���X)
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "EfectBase.h"
/** �{�X�̌����Ԃ��G�t�F�N�g */
class BossBlood :public EfectBase {
public:
   /**
    * \brief           �R���X�g���N�^
    * \param x         X���W
    * \param y         Y���W
    * \param bloodtype �����Ԃ��̎��
    */
   BossBlood(int x, int y, int bloodtype);
   /**
    * \brief �f�X�g���N�^
    */
   ~BossBlood();
   /**
   * \brief                        �������z�֐��̃I�[�o�[���C�h
   * \return EFECTTYPE::BOSSBLOOD  �G�t�F�N�g�̎�ʁi�{�X�̌����Ԃ��G�t�F�N�g�j��Ԃ�
   */
   virtual EFECTTYPE GetEfeType() { return EFECTTYPE::BOSSBLOOD; }
   /**
   * \brief �������֐�
   */
   void Init()override;
   /**
    * \brief   �X�V�֐�
    * \param g �Q�[���N���X�̎Q��
    */
   void Process(Game& g)override;
   /**
    * \brief   �`��֐�
    * \param g �Q�[���N���X�̎Q��
    */
   void Draw(Game& g)override;
   /**
    * \brief   �I�u�W�F�N�g�̏����֐�
    * \param g �Q�[���N���X�̎Q��
    */
   void Delete(Game& g)override;

private:
   int  _blood_type;    //!< �����Ԃ��̎�ʕϐ�
};