/*****************************************************************//**
 * \file   FlamePerformParticle.h
 * \brief  ���㉉�o�p�[�e�B�N���N���X�i�p�[�e�B�N���x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ParticleBase.h"
/** ���㉉�o�p�[�e�B�N�� */
class FlamePerform :public ParticleBase {
public:
   /**
    * \brief      �R���X�g���N�^
    * \param xy   XY���W
    * \param vxy  �p�[�e�B�N���̈ړ�����
    * \param flip ���]����
    */
   FlamePerform(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
   /**
    * \brief �f�X�g���N�^
    */
   ~FlamePerform();
   /**
    * \brief                             �������z�֐��̃I�[�o�[���C�h
    * \return PARTICLETYPE::FLAMEPERFORM �p�[�e�B�N���̎�ʁi���㉉�o�p�[�e�B�N���j��Ԃ�
    */
   virtual PARTICLETYPE GetParType() { return PARTICLETYPE::FLAMEPERFORM; }
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
/** ���㉉�o�p�[�e�B�N���N���X�p�萔 */
namespace FParInfo {
   constexpr auto FLAME_GRAPH = "res/Particle/Flame.png"; //!< �摜�t�@�C����
   constexpr auto FLAME_POSITIONX = 0.0;                  //!< ��_(����)����`��_�ւ�X���W����
   constexpr auto FLAME_POSITIONY = 400.0;                //!< ��_(����)����`��_�ւ�Y���W����
   constexpr auto FLAME_BLENDMODE = DX_BLENDMODE_ADD;     //!< �u�����h���[�h�ݒ�
   constexpr auto FLAME_PAL = 64;                         //!< �u�����h�l(0�`255)
   constexpr auto FLAME_RED = 240;                        //!< �ԐF�l(0�`255)
   constexpr auto FLAME_GREEN = 70;                       //!< �ΐF�l(0�`255)
   constexpr auto FLAME_BLUE = 5;                         //!< �F�l(0�`255)
   constexpr auto FLAME_SCALE = 1.0;                      //!< �g�k�l(1.0���f�t�H���g)
   constexpr auto FLAME_ANGLE = 0.0;                      //!< �`��p�x(3.14=180��)
   constexpr auto FLAME_CNT = 130;                        //!< �p�[�e�B�N��1������̐�������
   constexpr auto FLAME_QTY = 1;                          //!< 1�t���[��������̃p�[�e�B�N����
   //�p�[�e�B�N��1������̈ړ������̃����_���l����
   constexpr auto FLAME_RANDOMX1 = 30;                    //!< �p�[�e�B�N����X�����_���l
   constexpr auto FLAME_RANDOMX2 = 10.5;                  //!<       �V
   constexpr auto FLAME_RANDOMX3 = 10.5;                  //!<       �V
   constexpr auto FLAME_RANDOMY1 = 17;                    //!< �p�[�e�B�N����Y�����_���l
   constexpr auto FLAME_RANDOMY2 = 19.5;                  //!<       �V
   constexpr auto FLAME_RANDOMY3 = 8.5;                   //!<       �V
}