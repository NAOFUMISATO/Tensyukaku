/*****************************************************************//**
 * \file   GimikPlacement.h
 * \brief  �M�~�b�N�֌W�̃C���X�^���X�����N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
//��d�C���N���[�h�h�~
class Game;
/** �M�~�b�N�֌W�̃C���X�^���X���� */
class GimikPlacement {
public:
   /**
    * \brief   �R���X�g���N�^
    * \param g �Q�[���̎Q��
    */
   GimikPlacement(Game& g);
   /**
    * \brief �f�X�g���N�^
    */
   ~GimikPlacement();
   /** 
    * \brief   �������֐�
    * \param g �Q�[���̎Q��
    */
   void Init(Game& g);

private:
   /**
    * \brief   �K�i�̃C���X�^���X�����֐�
    * \param g �Q�[���̎Q��
    */
   void StairAppear(Game& g);
   /**
    * \brief   �s���̃C���X�^���X�����֐�
    * \param g �Q�[���̎Q��
    */
   void AndonAppear(Game& g);
   /**
    * \brief   �񕜃|�C���g�p�|�����C���X�^���X�����֐�
    * \param g �Q�[���̎Q��
    */
   void RestObjAppear(Game& g);
};
/** �M�~�b�N�֌W�̃C���X�^���X�����N���X�萔 */
namespace GInfo {
   /*----------�e�M�~�b�N�̈ʒu&����----------*/
   //�K�i
   constexpr auto STAIR1A_X = 3665; /*!<�K�i���"1A"��X���W */  constexpr auto STAIR1A_Y = 9360;  /*!<�K�i���"1A"��Y���W */  constexpr auto STAIR1A_FLIP = false; /*!<�K�i���"1A"�̔��]���� */ 
   constexpr auto STAIR2A_X = 175;  /*!<�K�i���"2A"��X���W */  constexpr auto STAIR2A_Y = 8600;  /*!<�K�i���"2A"��Y���W */  constexpr auto STAIR2A_FLIP = true;  /*!<�K�i���"2A"�̔��]���� */
   constexpr auto STAIR3A_X = 5585; /*!<�K�i���"3A"��X���W */  constexpr auto STAIR3A_Y = 7840;  /*!<�K�i���"3A"��Y���W */  constexpr auto STAIR3A_FLIP = false; /*!<�K�i���"3A"�̔��]���� */
   constexpr auto STAIR4A_X = 175;  /*!<�K�i���"4A"��X���W */  constexpr auto STAIR4A_Y = 7080;  /*!<�K�i���"4A"��Y���W */  constexpr auto STAIR4A_FLIP = true;  /*!<�K�i���"4A"�̔��]���� */
   constexpr auto STAIR5A_X = 5585; /*!<�K�i���"5A"��X���W */  constexpr auto STAIR5A_Y = 6320;  /*!<�K�i���"5A"��Y���W */  constexpr auto STAIR5A_FLIP = false; /*!<�K�i���"5A"�̔��]���� */
   constexpr auto STAIR6A_X = 4015; /*!<�K�i���"6A"��X���W */  constexpr auto STAIR6A_Y = 5560;  /*!<�K�i���"6A"��Y���W */  constexpr auto STAIR6A_FLIP = true;  /*!<�K�i���"6A"�̔��]���� */
   constexpr auto STAIR6B_X = 3665; /*!<�K�i���"6B"��X���W */  constexpr auto STAIR6B_Y = 5560;  /*!<�K�i���"6B"��Y���W */  constexpr auto STAIR6B_FLIP = false; /*!<�K�i���"6B"�̔��]���� */
   constexpr auto STAIR7A_X = 5585; /*!<�K�i���"7A"��X���W */  constexpr auto STAIR7A_Y = 4800;  /*!<�K�i���"7A"��Y���W */  constexpr auto STAIR7A_FLIP = false; /*!<�K�i���"7A"�̔��]���� */
   constexpr auto STAIR7B_X = 2055; /*!<�K�i���"7B"��X���W */  constexpr auto STAIR7B_Y = 4800;  /*!<�K�i���"7B"��Y���W */  constexpr auto STAIR7B_FLIP = true;  /*!<�K�i���"7B"�̔��]���� */
   constexpr auto STAIR8A_X = 4900; /*!<�K�i���"8A"��X���W */  constexpr auto STAIR8A_Y = 4040;  /*!<�K�i���"8A"��Y���W */  constexpr auto STAIR8A_FLIP = true;  /*!<�K�i���"8A"�̔��]���� */
   constexpr auto STAIR9A_X = 175;  /*!<�K�i���"9A"��X���W */  constexpr auto STAIR9A_Y = 3280;  /*!<�K�i���"9A"��Y���W */  constexpr auto STAIR9A_FLIP = true;  /*!<�K�i���"9A"�̔��]���� */
   constexpr auto STAIR10A_X = 5585;/*!<�K�i���"10A"��X���W */ constexpr auto STAIR10A_Y = 2520; /*!<�K�i���"10A"��Y���W */ constexpr auto STAIR10A_FLIP = false;/*!<�K�i���"10A"�̔��]���� */
   constexpr auto STAIR11A_X = 175; /*!<�K�i���"11A"��X���W */ constexpr auto STAIR11A_Y = 1760; /*!<�K�i���"11A"��Y���W */ constexpr auto STAIR11A_FLIP = true; /*!<�K�i���"11A"�̔��]���� */

   //�s��
   constexpr auto ANDON5A_X = 4000; /*!<�s�����"5A"��X���W */  constexpr auto ANDON5A_Y = 6320;  /*!<�s�����"5A"��Y���W */ 
   constexpr auto ANDON5B_X = 4900; /*!<�s�����"5B"��X���W */  constexpr auto ANDON5B_Y = 6320;  /*!<�s�����"5B"��Y���W */
   constexpr auto ANDON6A_X = 2800; /*!<�s�����"6A"��X���W */  constexpr auto ANDON6A_Y = 5560;  /*!<�s�����"6A"��Y���W */
   constexpr auto ANDON8A_X = 4600; /*!<�s�����"8A"��X���W */  constexpr auto ANDON8A_Y = 4040;  /*!<�s�����"8A"��Y���W */
   constexpr auto ANDON8B_X = 4100; /*!<�s�����"8B"��X���W */  constexpr auto ANDON8B_Y = 4040;  /*!<�s�����"8B"��Y���W */
   constexpr auto ANDON8C_X = 3580; /*!<�s�����"8C"��X���W */  constexpr auto ANDON8C_Y = 4040;  /*!<�s�����"8C"��Y���W */
   constexpr auto ANDON8D_X = 3100; /*!<�s�����"8D"��X���W */  constexpr auto ANDON8D_Y = 4040;  /*!<�s�����"8D"��Y���W */
   constexpr auto ANDON8E_X = 2650; /*!<�s�����"8E"��X���W */  constexpr auto ANDON8E_Y = 4040;  /*!<�s�����"8E"��Y���W */
   constexpr auto ANDON11A_X = 4900;/*!<�s�����"11A"��X���W */  constexpr auto ANDON11A_Y = 1760;/*!<�s�����"11A"��Y���W */
   constexpr auto ANDON11B_X = 3800;/*!<�s�����"11B"��X���W */  constexpr auto ANDON11B_Y = 1760;/*!<�s�����"11B"��Y���W */
   constexpr auto ANDON11C_X = 2700;/*!<�s�����"11C"��X���W */  constexpr auto ANDON11C_Y = 1760;/*!<�s�����"11C"��Y���W */
   constexpr auto ANDON11D_X = 1900;/*!<�s�����"11D"��X���W */ constexpr auto ANDON11D_Y = 1760; /*!<�s�����"11D"��Y���W */
   constexpr auto ANDON11E_X = 1000;/*!<�s�����"11E"��X���W */ constexpr auto ANDON11E_Y = 1760; /*!<�s�����"11E"��Y���W */
   
   //�񕜃|�C���g
   constexpr auto  REST_POINT6A_X = 2100;/*!<�񕜃|�C���g���"6A"��X���W */ constexpr auto REST_POINT6A_Y = 4800 + 370;/*!<�񕜃|�C���g���"6A"��Y���W */
   constexpr auto  REST_POINT7A_X = 5000;/*!<�񕜃|�C���g���"7A"��X���W */ constexpr auto REST_POINT7A_Y = 4040 + 370;/*!<�񕜃|�C���g���"7A"��Y���W */
}