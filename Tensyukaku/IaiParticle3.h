/*****************************************************************//**
 * \file   IaiParticle3.h
 * \brief  �����p�[�e�B�N���R�N���X�i�p�[�e�B�N���x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ParticleBase.h"
/** �����p�[�e�B�N���R */
class IaiParticle3 : public ParticleBase {
public:
   /**
    * \brief      �R���X�g���N�^
    * \param xy   XY���W
    * \param vxy  �p�[�e�B�N���̈ړ�����
    * \param flip ���]����
    */
   IaiParticle3(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
   /**
    * \brief �f�X�g���N�^
    */
   ~IaiParticle3();
   /**
    * \brief                     �������z�֐��̃I�[�o�[���C�h
    * \return PARTICLETYPE::IAI3 �p�[�e�B�N���̎�ʁi�����p�[�e�B�N���R�j��Ԃ�
    */
   virtual PARTICLETYPE GetParType() { return PARTICLETYPE::IAI3; }
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
/** �����p�[�e�B�N���R�N���X�p�萔 */
namespace IP3Info {
   constexpr auto IAI_PARTICLE3_GRAPH = "res/Particle/IaiSibuki.png";   //!< �摜�t�@�C����
   constexpr auto IAI_PARTICLE3_POSITIONX = 0.0;              //!< ��_(����)����`��_�ւ�X���W����
   constexpr auto IAI_PARTICLE3_POSITIONY = -225.0;           //!< ��_(����)����`��_�ւ�Y���W����
   constexpr auto IAI_PARTICLE3_BLENDMODE = DX_BLENDMODE_SUB; //!< �u�����h���[�h�ݒ�
   constexpr auto IAI_PARTICLE3_PAL = 128;                    //!< �u�����h�l(0�`255)
   constexpr auto IAI_PARTICLE3_RED = 200;                    //!< �ԐF�l(0�`255)
   constexpr auto IAI_PARTICLE3_GREEN = 200;                  //!< �ΐF�l(0�`255)
   constexpr auto IAI_PARTICLE3_BLUE = 200;                   //!< �F�l(0�`255)
   constexpr auto IAI_PARTICLE3_SCALE = 1.0;                  //!< �g�k�l(1.0���f�t�H���g)
   constexpr auto IAI_PARTICLE3_ANGLE = 0.0;                  //!< �`��p�x(3.14=180��)
   constexpr auto IAI_PARTICLE3_CNT = 30;                     //!< �p�[�e�B�N��1������̐�������
   constexpr auto IAI_PARTICLE3_QTY = 5;                      //!< 1�t���[��������̃p�[�e�B�N����
   //�p�[�e�B�N��1������̈ړ������̃����_���l����
   constexpr auto IAI_PARTICLE3_RANDOMX1 = 45;                //!< �p�[�e�B�N����X�����_���l
   constexpr auto IAI_PARTICLE3_RANDOMX2 = 10.0;              //!<       �V
   constexpr auto IAI_PARTICLE3_RANDOMX3 = 2.5;               //!<       �V
   constexpr auto IAI_PARTICLE3_RANDOMY1 = 45;                //!< �p�[�e�B�N����Y�����_���l
   constexpr auto IAI_PARTICLE3_RANDOMY2 = 10.0;              //!<       �V
   constexpr auto IAI_PARTICLE3_RANDOMY3 = 2.5;               //!<       �V
}
