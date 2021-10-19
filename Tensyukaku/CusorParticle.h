/*****************************************************************//**
 * \file   CusorParticle.h
 * \brief  �^�C�g���J�[�\���p�[�e�B�N���N���X�i�p�[�e�B�N���x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ParticleBase.h"
/** �^�C�g���J�[�\���p�[�e�B�N�� */
class CursorParticle: public ParticleBase {
public:
   /**
    * \brief         �R���X�g���N�^
    * \param xy      XY���W
    * \param vxy     �p�[�e�B�N���̈ړ�����
    * \param hittype �^�C�g���̂��ꂼ��̑I���I�u�W�F�N�g�ɓ��������ۂ̃^�C�v�ω�
    */
   CursorParticle(std::pair<double, double> xy, std::pair<double, double> mxy, std::string hittype);
   /**
    * \brief �f�X�g���N�^
    */
   ~CursorParticle();
   /**
    * \brief                        �������z�֐��̃I�[�o�[���C�h
    * \return PARTICLETYPE::CURSOR  �p�[�e�B�N���̎�ʁi�^�C�g���J�[�\���p�[�e�B�N���j��Ԃ�
    */
   virtual PARTICLETYPE GetParType() { return PARTICLETYPE::CURSOR; }
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

private:
   /**
    * \brief �J�[�\���p�[�e�B�N���̎�ʐݒ�֐�
    */
   void SetType();

   std::string  _hit_type;   //!< �J�[�\���p�[�e�B�N���̎�ʂ��w�肷�镶����
};
/** �^�C�g���J�[�\���p�[�e�B�N���N���X�p�萔 */
namespace CParInfo {
   constexpr auto CURSOR_PARTICLE1_GRAPH = "res/Particle/Cursor.png"; //!< �摜�t�@�C����
   constexpr auto CURSOR_PARTICLE1_POSITIONX = 0.0;                   //!< ��_(����)����`��_�ւ�X���W����
   constexpr auto CURSOR_PARTICLE1_POSITIONY = -10.0;                 //!< ��_(����)����`��_�ւ�Y���W����
   constexpr auto CURSOR_PARTICLE1_BLENDMODE = DX_BLENDMODE_PMA_ADD;  //!< �u�����h���[�h�ݒ�
   constexpr auto CURSOR_PARTICLE1_PAL = 50;                          //!< �u�����h�l
   constexpr auto CURSOR_PARTICLE1_SCALE = 1.0;                       //!< �g�k�l
   constexpr auto CURSOR_PARTICLE1_ANGLE = 0.0;                       //!< �`��p�x(3.14=180��)
   //�p�[�e�B�N��1������̈ړ������̃����_���l����
   constexpr auto CURSOR_PARTICLE1_RANDOMX1 = 30;                     //!< �p�[�e�B�N����X�����_���l
   constexpr auto CURSOR_PARTICLE1_RANDOMX2 = 10.5;                   //!<       �V
   constexpr auto CURSOR_PARTICLE1_RANDOMX3 = 10.5;                   //!<       �V
   constexpr auto CURSOR_PARTICLE1_RANDOMY1 = 17;                     //!< �p�[�e�B�N����Y�����_���l
   constexpr auto CURSOR_PARTICLE1_RANDOMY2 = 19.5;                   //!<       �V
   constexpr auto CURSOR_PARTICLE1_RANDOMY3 = 8.5;                    //!<       �V
   
}