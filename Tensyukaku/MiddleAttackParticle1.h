/*****************************************************************//**
 * \file   MiddleAttackParticle1.h
 * \brief  ���i�U���p�[�e�B�N���P�N���X�i�p�[�e�B�N���x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ParticleBase.h"
/** ���i�U���p�[�e�B�N��1 */
class MiddleAttackParticle1 : public ParticleBase {
public:
   /**
    * \brief      �R���X�g���N�^
    * \param xy   XY���W
    * \param vxy  �p�[�e�B�N���̈ړ�����
    * \param flip ���]����
    */
   MiddleAttackParticle1(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
   /**
    * \brief �f�X�g���N�^
    */
   ~MiddleAttackParticle1();
   /**
    * \brief                              �������z�֐��̃I�[�o�[���C�h
    * \return PARTICLETYPE::MIDDLEATTACK1 �p�[�e�B�N���̎�ʁi���i�U���p�[�e�B�N��1�j��Ԃ�
    */
   virtual PARTICLETYPE GetParType() { return PARTICLETYPE::MIDDLEATTACK1; }
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
/** ���i�U���p�[�e�B�N���P�N���X�p�萔 */
namespace MP1Info {
   constexpr auto MIDDLEATTACK_PARTICLE1_GRAPH = "res/Particle/MiddleAttack.png";  //!< �摜�t�@�C����
   constexpr auto MIDDLEATTACK_PARTICLE1_POSITIONX = 0.0;               //!< ��_(����)����`��_�ւ�X���W����
   constexpr auto MIDDLEATTACK_PARTICLE1_POSITIONY = -325.0;            //!< ��_(����)����`��_�ւ�Y���W����
   constexpr auto MIDDLEATTACK_PARTICLE1_BLENDMODE = DX_BLENDMODE_SUB;  //!< �u�����h���[�h�ݒ�
   constexpr auto MIDDLEATTACK_PARTICLE1_PAL = 64;                      //!< �u�����h�l(0�`255)
   constexpr auto MIDDLEATTACK_PARTICLE1_RED = 128;                     //!< �ԐF�l(0�`255)
   constexpr auto MIDDLEATTACK_PARTICLE1_GREEN = 128;                   //!< �ΐF�l(0�`255)
   constexpr auto MIDDLEATTACK_PARTICLE1_BLUE = 128;                    //!< �F�l(0�`255)
   constexpr auto MIDDLEATTACK_PARTICLE1_SCALE = 1.0;                   //!< �g�k�l(1.0���f�t�H���g)
   constexpr auto MIDDLEATTACK_PARTICLE1_ANGLE = 0.0;                   //!< �`��p�x(3.14=180��)
   constexpr auto MIDDLEATTACK_PARTICLE1_CNT = 20;                      //!< �p�[�e�B�N��1������̐�������
   constexpr auto MIDDLEATTACK_PARTICLE1_QTY = 10;                      //!< 1�t���[��������̃p�[�e�B�N����
   //�p�[�e�B�N��1������̈ړ������̃����_���l����
   constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMX1 = 20;                 //!< �p�[�e�B�N����X�����_���l
   constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMX2 = 10.0;               //!<       �V
   constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMX3 = 8.0;                //!<       �V
   constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMY1 = 20;                 //!< �p�[�e�B�N����Y�����_���l
   constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMY2 = 10.0;               //!<       �V
   constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMY3 = 8.0;                //!<       �V
}
