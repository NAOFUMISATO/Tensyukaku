/*****************************************************************//**
 * \file   MiddleBlood.h
 * \brief  ���m�^�̌����Ԃ��G�t�F�N�g�N���X�i�G�t�F�N�g�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "EfectBase.h"
/** ���m�^�̌����Ԃ��G�t�F�N�g */
class MiddleBlood :public EfectBase {
public:
   /**
    * \brief           �R���X�g���N�^
    * \param x         X���W
    * \param y         Y���W
    * \param bloodtype �����Ԃ��̎��
    */
   MiddleBlood(int x, int y,  bool flip, int bloodtype);
   /**
   * \brief �f�X�g���N�^
   */
   ~MiddleBlood();
   /**
   * \brief                         �������z�֐��̃I�[�o�[���C�h
   * \return EFECTTYPE::MIDDLEBLOOD �G�t�F�N�g�̎�ʁi���m�^�̌����Ԃ��G�t�F�N�g�j��Ԃ�
   */
   virtual EFECTTYPE GetEfeType() { return EFECTTYPE::MIDDLEBLOOD; }
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