/*****************************************************************//**
 * \file   RestPoint.h
 * \brief  �񕜃|�C���g�|�����N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** �񕜃|�C���g�|���� */
class RestPoint :public ObjectBase {
public:
   /**
    * \brief   �R���X�g���N�^
    * \param x X���W
    * \param y Y���W
    */
   RestPoint(int x,int y);
   /**
    * \brief �f�X�g���N�^
    */
   ~RestPoint();
   /**
    * \brief                        �������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::RESTPOINT �I�u�W�F�N�g�̎�ʁi�񕜃|�C���g�|�����j��Ԃ�
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::RESTPOINT; }
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
   int _graph_no;    //!< �V�[�g�ԍ��ϐ�
   bool _hit_flag;   //!< �v���C���[�������������̃t���O
};