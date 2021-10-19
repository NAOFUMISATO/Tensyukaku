/*****************************************************************//**
 * \file   KunaiParticle.h
 * \brief  �N�i�C�����\������p�[�e�B�N���N���X�i�p�[�e�B�N���x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ParticleBase.h"
/** �N�i�C�����\������p�[�e�B�N�� */
class KunaiParticle : public ParticleBase {
public:
   /**
    * \brief      �R���X�g���N�^
    * \param xy   XY���W
    * \param vxy  �p�[�e�B�N���̈ړ�����
    * \param flip ���]����
    */
   KunaiParticle(std::pair<double, double> xy, std::pair<double, double> mxy, bool flip);
   /**
    * \brief �f�X�g���N�^
    */
   ~KunaiParticle();
   /**
    * \brief                                  �������z�֐��̃I�[�o�[���C�h
    * \return PARTICLETYPE::KUNAIRESERVELIGHT �p�[�e�B�N���̎�ʁi�N�i�C�����\������p�[�e�B�N���j��Ԃ�
    */
   virtual PARTICLETYPE GetParType() { return PARTICLETYPE::KUNAILIGHT; }
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
/** �N�i�C�����\������p�[�e�B�N���N���X�p�萔 */
namespace KPInfo {
   constexpr auto KRESERVELIGHT_PARTICLE_GRAPH = "res/Particle/KunaiReserveLight.png";   //!< �摜�t�@�C����
   constexpr auto KRESERVELIGHT_PARTICLE_POSITIONX = 0.0;               //!< ��_(����)����`��_�ւ�X���W����
   constexpr auto KRESERVELIGHT_PARTICLE_POSITIONY = -100.0;            //!< ��_(����)����`��_�ւ�Y���W����
   constexpr auto KRESERVELIGHT_PARTICLE_BLENDMODE = DX_BLENDMODE_ADD;  //!< �u�����h���[�h�ݒ�
   constexpr auto KRESERVELIGHT_PARTICLE_PAL = 128;                     //!< �u�����h�l(0�`255)
   constexpr auto KRESERVELIGHT_PARTICLE_RED = 128;                     //!< �ԐF�l(0�`255)
   constexpr auto KRESERVELIGHT_PARTICLE_GREEN = 128;                   //!< �ΐF�l(0�`255)
   constexpr auto KRESERVELIGHT_PARTICLE_BLUE = 128;                    //!< �F�l(0�`255)
   constexpr auto KRESERVELIGHT_PARTICLE_SCALE = 1.0;                   //!< �g�k�l(1.0���f�t�H���g)
   constexpr auto KRESERVELIGHT_PARTICLE_ANGLE = 0.0;                   //!< �`��p�x(3.14=180��)
   constexpr auto KRESERVELIGHT_PARTICLE_CNT = 20;                      //!< �p�[�e�B�N��1������̐�������
   constexpr auto KRESERVELIGHT_PARTICLE_QTY = 10;                      //!< 1�t���[��������̃p�[�e�B�N����
   //�p�[�e�B�N��1������̈ړ������̃����_���l����
   constexpr auto KRESERVELIGHT_PARTICLE_RANDOMX1 = 20;                 //!< �p�[�e�B�N����X�����_���l
   constexpr auto KRESERVELIGHT_PARTICLE_RANDOMX2 = 10.0;               //!<       �V
   constexpr auto KRESERVELIGHT_PARTICLE_RANDOMX3 = 8.0;                //!<       �V
   constexpr auto KRESERVELIGHT_PARTICLE_RANDOMY1 = 20;                 //!< �p�[�e�B�N����Y�����_���l
   constexpr auto KRESERVELIGHT_PARTICLE_RANDOMY2 = 10.0;               //!<       �V
   constexpr auto KRESERVELIGHT_PARTICLE_RANDOMY3 = 8.0;                //!<       �V
}