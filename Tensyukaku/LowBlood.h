/*****************************************************************//**
 * \file   LowBlood.h
 * \brief  �E�Ҍ^�̌����Ԃ��G�t�F�N�g�N���X�i�G�t�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "EfectBase.h"
 /** �E�Ҍ^�̌����Ԃ��G�t�F�N�g */
class LowBlood :public EfectBase {
public:
    /**
     * \brief           �R���X�g���N�^
     * \param x         X���W
     * \param y         Y���W
     * \param bloodtype �����Ԃ��̎��
     */
   LowBlood(int x, int y, bool flip, int bloodtype);
   /**
    * \brief �f�X�g���N�^
    */
   ~LowBlood();
   /**
   * \brief                      �������z�֐��̃I�[�o�[���C�h
   * \return EFECTTYPE::LOWBLOOD �G�t�F�N�g�̎�ʁi�E�Ҍ^�̌����Ԃ��G�t�F�N�g�j��Ԃ�
   */
   virtual EFECTTYPE GetEfeType() { return EFECTTYPE::LOWBLOOD; }
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
   int  _blood_type;    //!< �����Ԃ��̎�ʕϐ�
};