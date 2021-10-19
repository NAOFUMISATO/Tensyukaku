/*****************************************************************//**
 * \file   SwayParticle.h
 * \brief  �X�E�F�C�p�[�e�B�N���N���X�i�p�[�e�B�N���x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ParticleBase.h"
/** �X�E�F�C�p�[�e�B�N�� */
class SwayParticle : public ParticleBase {
public:
   /**
    * \brief      �R���X�g���N�^
    * \param xy   XY���W
    * \param vxy  �p�[�e�B�N���̈ړ�����
    * \param flip ���]����
    */
   SwayParticle(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
   /**
    * \brief �f�X�g���N�^
    */
   ~SwayParticle();
   /**
    * \brief                     �������z�֐��̃I�[�o�[���C�h
    * \return PARTICLETYPE::SWAY �p�[�e�B�N���̎�ʁi�X�E�F�C�p�[�e�B�N���j��Ԃ�
    */
   virtual PARTICLETYPE GetParType() { return PARTICLETYPE::SWAY; }
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
/** �X�E�F�C�p�[�e�B�N���N���X�p�萔 */
namespace SPInfo {
   constexpr auto SWAY_PARTICLE_GRAPH = "res/Particle/Sway.png"; //!< �摜�t�@�C����
   constexpr auto SWAY_PARTICLE_POSITIONX = 0.0;                 //!< ��_(����)����`��_�ւ�X���W����
   constexpr auto SWAY_PARTICLE_POSITIONY = -10.0;               //!< ��_(����)����`��_�ւ�Y���W����
   constexpr auto SWAY_PARTICLE_BLENDMODE = DX_BLENDMODE_SUB;    //!< �u�����h���[�h�ݒ�
   constexpr auto SWAY_PARTICLE_PAL = 255;                       //!< �u�����h�l(0�`255)
   constexpr auto SWAY_PARTICLE_RED = 255;                       //!< �ԐF�l(0�`255)
   constexpr auto SWAY_PARTICLE_GREEN = 255;                     //!< �ΐF�l(0�`255)
   constexpr auto SWAY_PARTICLE_BLUE = 255;                      //!< �F�l(0�`255)
   constexpr auto SWAY_PARTICLE_SCALE = 1.0;                     //!< �g�k�l(1.0���f�t�H���g)
   constexpr auto SWAY_PARTICLE_ANGLE = 0.0;                     //!< �`��p�x(3.14=180��)
   constexpr auto SWAY_PARTICLE_CNT = 25;                        //!< �p�[�e�B�N��1������̐�������
   constexpr auto SWAY_PARTICLE_QTY = 10;                        //!< 1�t���[��������̃p�[�e�B�N����
   //�p�[�e�B�N��1������̈ړ������̃����_���l����
   constexpr auto SWAY_PARTICLE_RANDOMX1 = 25;                   //!< �p�[�e�B�N����X�����_���l
   constexpr auto SWAY_PARTICLE_RANDOMX2 = 5.0;                  //!<       �V
   constexpr auto SWAY_PARTICLE_RANDOMX3 = 2.5;                  //!<       �V
   constexpr auto SWAY_PARTICLE_RANDOMY1 = 20;                   //!< �p�[�e�B�N����Y�����_���l
   constexpr auto SWAY_PARTICLE_RANDOMY2 = 10.0;                 //!<       �V
   constexpr auto SWAY_PARTICLE_RANDOMY3 = 2.5;                  //!<       �V
}
