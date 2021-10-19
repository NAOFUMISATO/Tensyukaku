/*****************************************************************//**
 * \file   ParticleBase.h
 * \brief  �e�p�[�e�B�N���̃x�[�X�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
//��d�C���N���[�h�h�~
class Game;
/** �p�[�e�B�N�� */
class ParticleBase :public ObjectBase {
public:
   /**
    * \brief �R���X�g���N�^
    */
   ParticleBase();
   /**
    * \brief �f�X�g���N�^
    */
   ~ParticleBase();
   /**
    * \brief                       �������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::PARTICLE �I�u�W�F�N�g�̎�ʁi�p�[�e�B�N���j��Ԃ�
    */
   virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::PARTICLE; }
   /** �p�[�e�B�N���̎�ʗ� */
   enum class PARTICLETYPE {
      CURSOR,       //!< �^�C�g���J�[�\��
      FLAMEPERFORM, //!< ���㉉�o
      MIDDLEATTACK1,//!< ���i�U���P
      MIDDLEATTACK2,//!< ���i�U���Q
      LOWATTACK1,   //!< ���i�U���P
      LOWATTACK2,   //!< ���i�U���Q
      IAI1,         //!< �����P
      IAI2,         //!< �����Q
      IAI3,         //!< �����R
      SWAY,         //!< �X�E�F�C
      RECOVERY,     //!< ��
      IAIGAUGE,     //!< �����Q�[�WMAX(�Q�[�W��)
      GAUGEMAXLIGHT,//!< �����Q�[�WMAX(�v���C���[��)
      KUNAILIGHT,   //!< �N�i�C�����\������
      LANCELIGHT    //!< �����\������
   };
   /**
    * \brief    �������z�֐���
    * \return 0 �h����Œ�`
    */
   virtual PARTICLETYPE GetParType() = 0;
   /**
    * \brief �������֐�
    */
   virtual void Init();
   /**
    * \brief   �X�V�֐�
    * \param g �Q�[���̎Q��
    */
   virtual void Process(Game& g);
   /**
    * \brief   �`��֐�
    * \param g �Q�[���̎Q��
    */
   virtual void Draw(Game& g);

protected:
   std::pair<double, double> _xy;   //!< XY���W
   std::pair<double, double> _dxy;  //!< �p�[�e�B�N���̃I�u�W�F�N�g�����XY���W�`�捷��
   std::pair<double, double> _mxy;  //!< �p�[�e�B�N���̈ړ�����
   int _pal;                        //!< �����x
   int _bm;                         //!< �u�����h���[�h
   std::tuple<int, int, int> _rgb;  //!< RGB�l
};