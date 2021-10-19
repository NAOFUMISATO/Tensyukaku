/*****************************************************************//**
 * \file   IaiGaugeParticle.h
 * \brief  �����Q�[�WMAX���̃Q�[�W���p�[�e�B�N���N���X�i�p�[�e�B�N���x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ParticleBase.h"
/** �����Q�[�WMAX���̃Q�[�W���p�[�e�B�N�� */
class IaiGaugeParticle : public ParticleBase {
public:
   /**
    * \brief      �R���X�g���N�^
    * \param xy   XY���W
    * \param vxy  �p�[�e�B�N���̈ړ�����
    * \param flip ���]����
    */
   IaiGaugeParticle(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
   /**
    * \brief �f�X�g���N�^
    */
   ~IaiGaugeParticle();
   /**
   * \brief                         �������z�֐��̃I�[�o�[���C�h
   * \return PARTICLETYPE::IAIGAUGE �p�[�e�B�N���̎�ʁi�����Q�[�WMAX���̃Q�[�W���p�[�e�B�N���j��Ԃ�
   */
   virtual PARTICLETYPE GetParType() { return PARTICLETYPE::IAIGAUGE; }
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
/** �����Q�[�WMAX���̃Q�[�W���p�[�e�B�N���N���X�p�萔 */
namespace IGPInfo {
   constexpr auto IAIG_PARTICLE_GRAPH = "res/Particle/IaiGaugeP.png";  //!< �摜�t�@�C����
   constexpr auto IAIG_PARTICLE_POSITIONX = 0.0;              //!< ��_(����)����`��_�ւ�X���W����
   constexpr auto IAIG_PARTICLE_POSITIONY = 0.0;              //!< ��_(����)����`��_�ւ�Y���W����
   constexpr auto IAIG_PARTICLE_BLENDMODE = DX_BLENDMODE_ADD; //!< �u�����h���[�h�ݒ�
   constexpr auto IAIG_PARTICLE_PAL = 128;                    //!< �u�����h�l(0�`255)
   constexpr auto IAIG_PARTICLE_RED = 230;                    //!< �ԐF�l(0�`255)
   constexpr auto IAIG_PARTICLE_GREEN = 70;                   //!< �ΐF�l(0�`255)
   constexpr auto IAIG_PARTICLE_BLUE = 5;                     //!< �F�l(0�`255)
   constexpr auto IAIG_PARTICLE_SCALE = 1.0;                  //!< �g�k�l(1.0���f�t�H���g)
   constexpr auto IAIG_PARTICLE_ANGLE = 0.0;                  //!< �`��p�x(3.14=180��)
   constexpr auto IAIG_PARTICLE_CNT = 10;                     //!< �p�[�e�B�N��1������̐�������
   constexpr auto IAIG_PARTICLE_QTY = 5;                      //!< 1�t���[��������̃p�[�e�B�N����
   //�p�[�e�B�N��1������̈ړ������̃����_���l����
   constexpr auto IAIG_PARTICLE_RANDOMX1 = 10;                //!< �p�[�e�B�N����X�����_���l
   constexpr auto IAIG_PARTICLE_RANDOMX2 = 5.0;               //!<       �V
   constexpr auto IAIG_PARTICLE_RANDOMX3 = 4.0;               //!<       �V
   constexpr auto IAIG_PARTICLE_RANDOMY1 = 10;                //!< �p�[�e�B�N����Y�����_���l
   constexpr auto IAIG_PARTICLE_RANDOMY2 = 5.0;               //!<       �V
   constexpr auto IAIG_PARTICLE_RANDOMY3 = 4.0;               //!<       �V
}
