/*****************************************************************//**
 * \file   CPointBlock.h
 * \brief  �`�F�b�N�|�C���g�u���b�N�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** �`�F�b�N�|�C���g�u���b�N */
class CPointBlock :public ObjectBase {
public:
   /**
    * \brief            �R���X�g���N�^
    * \param cpointtype �`�F�b�N�|�C���g�u���b�N�̎�ʕ�����
    */
   CPointBlock(std::string  cpointtype);
   /**
    * \brief �f�X�g���N�^
    */
   ~CPointBlock();
   /**
    * \brief                           �������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::CPOINTBLOCK  �I�u�W�F�N�g�̎�ʁi�`�F�b�N�|�C���g�u���b�N�j��Ԃ�
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::CPOINTBLOCK; }
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
   /**
    * \brief   �I�u�W�F�N�g�̏����֐�
    * \param g �Q�[���̎Q��
    */
   void Delete(Game& g)override;

private:
   /**
    * \brief ��ʂ��Ƃ̍��W�ݒ�֐�
    */
   void PositionSetting();

   std::string  _cpoint_type;    //!< �`�F�b�N�|�C���g�u���b�N��ʂ��w�肷�镶����
};
//�`�F�b�N�|�C���g
namespace CPInfo {
   constexpr auto CPOINT_2A_X = 3600;     //!< �`�F�b�N�|�C���g�u���b�N���"2A"��X���W
   constexpr auto CPOINT_2A_Y = 8600;     //!< �`�F�b�N�|�C���g�u���b�N���"2A"��Y���W
   constexpr auto CPOINT_3A_X = 250;      //!< �`�F�b�N�|�C���g�u���b�N���"3A"��X���W
   constexpr auto CPOINT_3A_Y = 7840;     //!< �`�F�b�N�|�C���g�u���b�N���"3A"��Y���W
   constexpr auto CPOINT_4A_X = 5600;     //!< �`�F�b�N�|�C���g�u���b�N���"4A"��X���W
   constexpr auto CPOINT_4A_Y = 7080;     //!< �`�F�b�N�|�C���g�u���b�N���"4A"��Y���W
   constexpr auto CPOINT_5A_X = 250;      //!< �`�F�b�N�|�C���g�u���b�N���"5A"��X���W
   constexpr auto CPOINT_5A_Y = 6320;     //!< �`�F�b�N�|�C���g�u���b�N���"5A"��Y���W
   constexpr auto CPOINT_5B_X = 5500;     //!< �`�F�b�N�|�C���g�u���b�N���"5B"��X���W
   constexpr auto CPOINT_5B_Y = 6320;     //!< �`�F�b�N�|�C���g�u���b�N���"5B"��Y���W
   constexpr auto CPOINT_8A_X = 5000;     //!< �`�F�b�N�|�C���g�u���b�N���"8A"��X���W
   constexpr auto CPOINT_8A_Y = 4040;     //!< �`�F�b�N�|�C���g�u���b�N���"8A"��Y���W
   constexpr auto CPOINT_11A_X = 5600;    //!< �`�F�b�N�|�C���g�u���b�N���"11A"��X���W
   constexpr auto CPOINT_11A_Y = 1760;    //!< �`�F�b�N�|�C���g�u���b�N���"11A"��Y���W
}