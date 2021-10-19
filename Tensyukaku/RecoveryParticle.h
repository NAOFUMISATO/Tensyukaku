/*****************************************************************//**
 * \file   RecoveryParticle.h
 * \brief  �񕜃p�[�e�B�N���N���X�i�p�[�e�B�N���x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ParticleBase.h"
/** �񕜃p�[�e�B�N�� */
class RecoveryParticle : public ParticleBase {
public:
   /**
    * \brief      �R���X�g���N�^
    * \param xy   XY���W
    * \param vxy  �p�[�e�B�N���̈ړ�����
    * \param flip ���]����
    */
   RecoveryParticle(std::pair<double, double> xy, std::pair<double, double> vxy);
   /**
    * \brief �f�X�g���N�^
    */
   ~RecoveryParticle();
   /**
    * \brief                         �������z�֐��̃I�[�o�[���C�h
    * \return PARTICLETYPE::RECOVERY �p�[�e�B�N���̎�ʁi�񕜃p�[�e�B�N���j��Ԃ�
    */
   virtual PARTICLETYPE GetParType() { return PARTICLETYPE::RECOVERY; }
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
/** �񕜃p�[�e�B�N���N���X�p�萔 */
namespace RPInfo {
   constexpr auto RECOVERY_PARTICLE_GRAPH = "res/Particle/Recovery.png";   //!< �摜�t�@�C����
   constexpr auto RECOVERY_PARTICLE_POSITIONX = 0.0;              //!< ��_(����)����`��_�ւ�X���W����
   constexpr auto RECOVERY_PARTICLE_POSITIONY = -350.0;           //!< ��_(����)����`��_�ւ�Y���W����
   constexpr auto RECOVERY_PARTICLE_BLENDMODE = DX_BLENDMODE_ADD; //!< �u�����h���[�h�ݒ�
   constexpr auto RECOVERY_PARTICLE_PAL = 150;                    //!< �u�����h�l(0�`255)
   constexpr auto RECOVERY_PARTICLE_RED = 30;                     //!< �ԐF�l(0�`255)
   constexpr auto RECOVERY_PARTICLE_GREEN = 200;                  //!< �ΐF�l(0�`255)
   constexpr auto RECOVERY_PARTICLE_BLUE = 30;                    //!< �F�l(0�`255)
   constexpr auto RECOVERY_PARTICLE_SCALE = 1.0;                  //!< �g�k�l(1.0���f�t�H���g)
   constexpr auto RECOVERY_PARTICLE_ANGLE = 0.0;                  //!< �`��p�x(3.14=180��)
   constexpr auto RECOVERY_PARTICLE_CNT = 30;                     //!< �p�[�e�B�N��1������̐�������
   constexpr auto RECOVERY_PARTICLE_QTY = 10;                     //!< 1�t���[��������̃p�[�e�B�N����
   //�p�[�e�B�N��1������̈ړ������̃����_���l����
   constexpr auto RECOVERY_PARTICLE_RANDOMX1 = 10;                //!< �p�[�e�B�N����X�����_���l
   constexpr auto RECOVERY_PARTICLE_RANDOMX2 = 5.0;               //!<       �V
   constexpr auto RECOVERY_PARTICLE_RANDOMX3 = 4.0;               //!<       �V
   constexpr auto RECOVERY_PARTICLE_RANDOMY1 = 10;                //!< �p�[�e�B�N����Y�����_���l
   constexpr auto RECOVERY_PARTICLE_RANDOMY2 = 5.0;               //!<       �V
   constexpr auto RECOVERY_PARTICLE_RANDOMY3 = 4.0;               //!<       �V
}
