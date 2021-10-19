/*****************************************************************//**
 * \file   IaiParticle2.h
 * \brief  �����p�[�e�B�N���Q�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ParticleBase.h"
/** �����p�[�e�B�N���Q */
class IaiParticle2 : public ParticleBase {
public:
   /**
    * \brief      �R���X�g���N�^
    * \param xy   XY���W
    * \param vxy  �p�[�e�B�N���̈ړ�����
    * \param flip ���]����
    */
   IaiParticle2(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
   /**
    * \brief �f�X�g���N�^
    */
   ~IaiParticle2();
   /**
    * \brief                     �������z�֐��̃I�[�o�[���C�h
    * \return PARTICLETYPE::IAI2 �p�[�e�B�N���̎�ʁi�����p�[�e�B�N���Q�j��Ԃ�
    */
   virtual PARTICLETYPE GetParType() { return PARTICLETYPE::IAI2; }
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
/** �����p�[�e�B�N���Q�N���X�p�萔 */
namespace IP2Info {
   constexpr auto IAI_PARTICLE2_GRAPH = "res/Particle/IaiKiseki2.png";   //!< �摜�t�@�C����
   constexpr auto IAI_PARTICLE2_POSITIONX = 0.0;              //!< ��_(����)����`��_�ւ�X���W����
   constexpr auto IAI_PARTICLE2_POSITIONY = -225.0;           //!< ��_(����)����`��_�ւ�Y���W����
   constexpr auto IAI_PARTICLE2_BLENDMODE = DX_BLENDMODE_SUB; //!< �u���h���[�h�ݒ�
   constexpr auto IAI_PARTICLE2_PAL = 100;                    //!< �u�����h�l(0�`255)
   constexpr auto IAI_PARTICLE2_RED = 170;                    //!< �ԐF�l(0�`255)
   constexpr auto IAI_PARTICLE2_GREEN = 170;                  //!< �ΐF�l(0�`255)
   constexpr auto IAI_PARTICLE2_BLUE = 170;                   //!< �F�l(0�`255)
   constexpr auto IAI_PARTICLE2_SCALE = 1.0;                  //!< �g�k�l(1.0���f�t�H���g)
   constexpr auto IAI_PARTICLE2_ANGLE = 0.0;                  //!< �`��p�x(3.14=180��)
   constexpr auto IAI_PARTICLE2_CNT = 30;                     //!< �p�[�e�B�N��1������̐�������
   constexpr auto IAI_PARTICLE2_QTY = 5;                      //!< 1�t���[��������̃p�[�e�B�N����
   //�p�[�e�B�N��1������̈ړ������̃����_���l����
   constexpr auto IAI_PARTICLE2_RANDOMX1 = 20;                //!< �p�[�e�B�N����X�����_���l
   constexpr auto IAI_PARTICLE2_RANDOMX2 = 10.0;              //!<       �V
   constexpr auto IAI_PARTICLE2_RANDOMX3 = 8.0;               //!<       �V
   constexpr auto IAI_PARTICLE2_RANDOMY1 = 20;                //!< �p�[�e�B�N����Y�����_���l
   constexpr auto IAI_PARTICLE2_RANDOMY2 = 10.0;              //!<       �V
   constexpr auto IAI_PARTICLE2_RANDOMY3 = 8.0;               //!<       �V
}
