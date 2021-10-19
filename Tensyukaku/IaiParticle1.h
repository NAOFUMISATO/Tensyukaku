/*****************************************************************//**
 * \file   IaiParticle1.h
 * \brief  �����p�[�e�B�N���P�N���X(�p�[�e�B�N���x�[�X�N���X�̃T�u�N���X)
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ParticleBase.h"
/** �����p�[�e�B�N���P */
class IaiParticle1 : public ParticleBase {
public:
   /**
    * \brief      �R���X�g���N�^
    * \param xy   XY���W
    * \param vxy  �p�[�e�B�N���̈ړ�����
    * \param flip ���]����
    */
   IaiParticle1(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
   /**
    * \brief �f�X�g���N�^
    */
   ~IaiParticle1();
   /**
   * \brief                     �������z�֐��̃I�[�o�[���C�h
   * \return PARTICLETYPE::IAI1 �p�[�e�B�N���̎�ʁi�����p�[�e�B�N���P�j��Ԃ�
   */
   virtual PARTICLETYPE GetParType() { return PARTICLETYPE::IAI1; }
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
/** �����p�[�e�B�N���P�N���X�p�萔 */
namespace IP1Info {
   constexpr auto IAI_PARTICLE1_GRAPH = "res/Particle/IaiLight.png";   //!< �摜�t�@�C����
   constexpr auto IAI_PARTICLE1_POSITIONX = 0.0;              //!< ��_(����)����`��_�ւ�X���W����
   constexpr auto IAI_PARTICLE1_POSITIONY = -225.0;           //!< ��_(����)����`��_�ւ�Y���W����
   constexpr auto IAI_PARTICLE1_BLENDMODE = DX_BLENDMODE_ADD; //!< �u�����h���[�h�ݒ�
   constexpr auto IAI_PARTICLE1_PAL = 128;                    //!< �u�����h�l(0�`255)
   constexpr auto IAI_PARTICLE1_RED = 80;                     //!< �ԐF�l(0�`255)
   constexpr auto IAI_PARTICLE1_GREEN = 80;                   //!< �ΐF�l(0�`255)
   constexpr auto IAI_PARTICLE1_BLUE = 60;                    //!< �F�l(0�`255)
   constexpr auto IAI_PARTICLE1_SCALE = 0.8;                  //!< �g�k�l(1.0���f�t�H���g)
   constexpr auto IAI_PARTICLE1_ANGLE = 0.0;                  //!< �`��p�x(3.14=180��)
   constexpr auto IAI_PARTICLE1_CNT = 20;                     //!< �p�[�e�B�N��1������̐�������
   constexpr auto IAI_PARTICLE1_QTY = 5;                      //!< 1�t���[��������̃p�[�e�B�N����
   //�p�[�e�B�N��1������̈ړ������̃����_���l����
   constexpr auto IAI_PARTICLE1_RANDOMX1 = 20;                //!< �p�[�e�B�N����X�����_���l
   constexpr auto IAI_PARTICLE1_RANDOMX2 = 10.0;              //!<       �V
   constexpr auto IAI_PARTICLE1_RANDOMX3 = 8.0;               //!<       �V
   constexpr auto IAI_PARTICLE1_RANDOMY1 = 20;                //!< �p�[�e�B�N����Y�����_���l
   constexpr auto IAI_PARTICLE1_RANDOMY2 = 10.00;             //!<       �V
   constexpr auto IAI_PARTICLE1_RANDOMY3 = 8.0;               //!<       �V
}
