/*****************************************************************//**
 * \file   GaugeMaxParticle.h
 * \brief  �����Q�[�WMAX���̃v���C���[���p�[�e�B�N���N���X�i�p�[�e�B�N���x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ParticleBase.h"
/** �����Q�[�WMAX���̃v���C���[���p�[�e�B�N�� */
class GaugeMaxParticle : public ParticleBase {
public:
   /**
    * \brief      �R���X�g���N�^
    * \param xy   XY���W
    * \param vxy  �p�[�e�B�N���̈ړ�����
    * \param flip ���]����
    */
   GaugeMaxParticle(std::pair<double, double> xy, std::pair<double, double> vxy);
   /**
    * \brief �f�X�g���N�^
    */
   ~GaugeMaxParticle();
   /**
   * \brief                              �������z�֐��̃I�[�o�[���C�h
   * \return PARTICLETYPE::GAUGEMAXLIGHT �p�[�e�B�N���̎�ʁi�����Q�[�WMAX���̃v���C���[���p�[�e�B�N���j��Ԃ�
   */
   virtual PARTICLETYPE GetParType() { return PARTICLETYPE::GAUGEMAXLIGHT; }
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
/** �����Q�[�WMAX���̃v���C���[���p�[�e�B�N���N���X�p�萔 */
namespace GMPInfo {
   constexpr auto GAGEMAX_PARTICLE_GRAPH = "res/Particle/GageMax.png";   //!< �摜�t�@�C����
   constexpr auto GAGEMAX_PARTICLE_POSITIONX = 0.0;              //!< ��_(����)����`��_�ւ�X���W����
   constexpr auto GAGEMAX_PARTICLE_POSITIONY = -220.0;           //!< ��_(����)����`��_�ւ�Y���W����
   constexpr auto GAGEMAX_PARTICLE_BLENDMODE = DX_BLENDMODE_ADD; //!< �u�����h���[�h�ݒ�
   constexpr auto GAGEMAX_PARTICLE_PAL = 150;                    //!< �u�����h�l(0�`255)
   constexpr auto GAGEMAX_PARTICLE_RED = 240;                    //!< �ԐF�l(0�`255)
   constexpr auto GAGEMAX_PARTICLE_GREEN = 70;                   //!< �ΐF�l(0�`255)
   constexpr auto GAGEMAX_PARTICLE_BLUE = 5;                     //!< �F�l(0�`255)
   constexpr auto GAGEMAX_PARTICLE_SCALE = 1.0;                  //!< �g�k�l(1.0���f�t�H���g)
   constexpr auto GAGEMAX_PARTICLE_ANGLE = 0.0;                  //!< �`��p�x(3.14=180��)
   constexpr auto GAGEMAX_PARTICLE_CNT = 40;                     //!< �p�[�e�B�N��1������̐�������
   constexpr auto GAGEMAX_PARTICLE_QTY = 10;                     //!< 1�t���[��������̃p�[�e�B�N����
   //�p�[�e�B�N��1������̈ړ������̃����_���l����
   constexpr auto GAGEMAX_PARTICLE_RANDOMX1 = 5;                 //!< �p�[�e�B�N����X�����_���l
   constexpr auto GAGEMAX_PARTICLE_RANDOMX2 = 5.0;               //!<       �V
   constexpr auto GAGEMAX_PARTICLE_RANDOMX3 = 4.0;               //!<       �V
   constexpr auto GAGEMAX_PARTICLE_RANDOMY1 = 5;                 //!< �p�[�e�B�N����Y�����_���l
   constexpr auto GAGEMAX_PARTICLE_RANDOMY2 = 5.0;               //!<       �V
   constexpr auto GAGEMAX_PARTICLE_RANDOMY3 = 4.0;               //!<       �V
}
