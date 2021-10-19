/*****************************************************************//**
 * \file   TutorialBoard.h
 * \brief  �`���[�g���A���{�[�h�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include  "ObjectBase.h"
/** �`���[�g���A���{�[�h */
class TutorialBoard :public ObjectBase {
public:
   /**
    * \brief              �R���X�g���N�^
    * \param tutorialtype �`���[�g���A���̎�ʕ�����
    */
   TutorialBoard(std::string tutorialtype);
   /**
    * \brief �f�X�g���N�^
    */
   ~TutorialBoard();
   /**
    * \brief                            �������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::TUTORIALBOARD �I�u�W�F�N�g�̎�ʁi�`���[�g���A���{�[�h�j��Ԃ�
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::TUTORIALBOARD; }
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
    * \brief �`���[�g���A���{�[�h�̎�ʂɂ����W�ݒ�֐�
    */
   void PositionSetting();

   std::string  _tutorial_type;   //!< �`���[�g���A���̎�ʂ��w�肷�镶����
   bool _tutorialhit_flag;        //!< �`���[�g���A���ɓ������Ă��邩�̃t���O
};
/** �`���[�g���A���{�[�h�N���X�p�萔 */
namespace TBInfo{
   constexpr auto TUTORIAL1A_X = 800;   //!< �`���[�g���A���{�[�h���"1A"��X���W
   constexpr auto TUTORIAL1A_Y = 9360;  //!< �`���[�g���A���{�[�h���"1A"��Y���W
   constexpr auto TUTORIAL1B_X = 1200;  //!< �`���[�g���A���{�[�h���"1B"��X���W
   constexpr auto TUTORIAL1B_Y = 9360;  //!< �`���[�g���A���{�[�h���"1B"��Y���W
   constexpr auto TUTORIAL2A_X = 3200;  //!< �`���[�g���A���{�[�h���"2A"��X���W
   constexpr auto TUTORIAL2A_Y = 8600;  //!< �`���[�g���A���{�[�h���"2A"��Y���W
   constexpr auto TUTORIAL3A_X = 500;   //!< �`���[�g���A���{�[�h���"3A"��X���W
   constexpr auto TUTORIAL3A_Y = 7840;  //!< �`���[�g���A���{�[�h���"3A"��Y���W
   constexpr auto TUTORIAL3B_X = 2200;  //!< �`���[�g���A���{�[�h���"3B"��X���W
   constexpr auto TUTORIAL3B_Y = 7840;  //!< �`���[�g���A���{�[�h���"3B"��Y���W
   constexpr auto TUTORIAL4A_X = 5200;  //!< �`���[�g���A���{�[�h���"4A"��X���W
   constexpr auto TUTORIAL4A_Y = 7080;  //!< �`���[�g���A���{�[�h���"4A"��Y���W
   constexpr auto TUTORIAL5A_X = 3800;  //!< �`���[�g���A���{�[�h���"5A"��X���W
   constexpr auto TUTORIAL5A_Y = 6320;  //!< �`���[�g���A���{�[�h���"5A"��Y���W
}