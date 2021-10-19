/*****************************************************************//**
 * \file   Game.h
 * \brief  �Q�[���N���X
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "BackGround.h"
#include "MapChip.h"
#include "Player.h"
#include "ObjectServer.h"
#include "ModeServer.h"
#include <unordered_map>

constexpr auto SCREEN_W = 1920;  //!< ��ʂ̉��𑜓x
constexpr auto SCREEN_H = 1080;  //!< ��ʂ̏c�𑜓x
constexpr auto SCREEN_DEPTH = 32;//!< �P�h�b�g������̃r�b�g��

/** �Q�[���{�� */
class Game{
public:
   /**
    * \brief �R���X�g���N�^
    */
   Game();
   /**
    * \brief �f�X�g���N�^
    */
   ~Game();
   /**
    * \brief �t���[������:����
    */
   void Input();
   /**
    * \brief �t���[������:�v�Z
    */
   void Process();
   /**
    * \brief �t���[������:�`��
    */
   void Draw();

   /**
    * \brief        �L�[���͂̏���Ԃ��֐�
    * \return _gkey �L�[���͂̏��
    */
   int GetKey() { return _gkey; }
   /**
    * \brief        �L�[���͂̃g���K����Ԃ��֐�
    * \return _gtrg �L�[���͂̃g���K���
    */
   int GetTrg() { return _gtrg; }
   /**
    * \brief        ���X�e�b�B�NX���͗ʂ̏���Ԃ��֐�
    * \return _xbuf ���X�e�b�B�NX���͗ʂ̏��
    */
   int GetXBuf() { return _xbuf; }
   /**
    * \brief        ���X�e�b�B�NY���͗ʂ̏���Ԃ��֐�
    * \return _ybuf ���X�e�b�B�NY���͗ʂ̏��
    */
   int GetYBuf() { return _ybuf; }
   /**
    * \brief         �}�b�v�̏c����Ԃ��֐�
    * \return _map_h �}�b�v�̏c��
    */
   int GetmapH() { return _map_h; }
   /**
    * \brief         �}�b�v�̉�����Ԃ��֐�
    * \return _map_w �}�b�v�̉���
    */
   int GetmapW() { return _map_w; }
   /**
    * \brief        �}�b�vX���W��Ԃ��֐�
    * \return _cv_x �}�b�vX���W
    */
   int GetcvX() { return _cv_x; }
   /**
    * \brief        �J����Y���W��Ԃ��֐�
    * \return _cv_y �J����Y���W
    */
   int GetcvY() { return _cv_y; }
   /**
    * \brief                �ċN����̊J�n���ǂ����̃t���O��Ԃ��֐�
    * \return _restart_flag �ċN����̊J�n���ǂ����̃t���O
    */
   bool GetRestartFlag() { return _restart_flag; }
   /**
    * \brief           �}�b�v�`�b�v�N���X��Ԃ��֐�
    * \return _mapchip �}�b�v�`�b�v�N���X
    */
   MapChip* GetChip() { return _mapchip; }
   /**
    * \brief              ���[�h�T�[�o�[�N���X��Ԃ��֐�
    * \return _servermode ���[�h�T�[�o�[�N���X
    */
   ModeServer* GetMS() { return _servermode; }
   /**
    * \brief              �I�u�W�F�N�g�T�[�o�[�N���X�̎Q�Ƃ�Ԃ��֐�
    * \return &_objserver �I�u�W�F�N�g�T�[�o�[�N���X
    */
   ObjectServer* GetOS() { return &_objserver; }
   /**
    * \brief       BGM�}�b�v��Ԃ��֐�
    * \return _bgm BGM�}�b�v
    */
   std::unordered_map<std::string, int> GetBgm() { return _bgm; }
   /**
    * \brief        �{�����[���}�b�v��Ԃ��֐�
    * \return _vpal �{�����[���}�b�v
    */
   std::unordered_map<std::string, int> GetVpal() { return _vpal; }
   /**
    * \brief               �`�F�b�N�|�C���g�t���O�}�b�v��Ԃ��֐�
    * \return _cpoint_flag �`�F�b�N�|�C���g�t���O�}�b�v
    */
   std::unordered_map<std::string, bool> GetCPointFlag() { return  _cpoint_flag; }
   /**
    * \brief     �J����X���W��ݒ肷��֐�
    * \param cvx �J����X���W
    */
   void SetcvX(int cvx) { _cv_x = cvx; }
   /**
    * \brief     �J����Y���W��ݒ肷��֐�
    * \param cvy �J����Y���W
    */
   void SetcvY(int cvy) { _cv_y = cvy; }
   /**
    * \brief      �}�b�v������ݒ肷��֐�
    * \param mapw �}�b�v����
    */
   void SetmapW(int mapw) { _map_w = mapw; }
   /**
    * \brief      �}�b�v�c����ݒ肷��֐�
    * \param maph �}�b�v�c��
    */
   void SetmapH(int maph) { _map_h = maph; }
   /**
    * \brief             �ċN����̊J�n���ǂ����̃t���O��ݒ肷��֐�
    * \param restartflag �ċN����̊J�n���ǂ����̃t���O
    */
   void SetRestartFlag(bool restartflag) { _restart_flag = restartflag; }
   /**
    * \brief            �`�F�b�N�|�C���g�t���O�}�b�v��ݒ肷��֐�
    * \param cpointflag �`�F�b�N�|�C���g�t���O�}�b�v
    */
   void SetCPointFlag(std::unordered_map<std::string, bool> cpointflag) { _cpoint_flag = cpointflag; }
   /**
    * \brief      �{�����[���}�b�v��ݒ肷��֐�
    * \param vpal �{�����[���}�b�v
    */
   void SetVpal(std::unordered_map<std::string, int> vpal) { _vpal = vpal; }
   /**
    * \brief BGM�̃{�����[���������֐�
    */
   void VolumeInit();

private:
   /**
    * \brief BGM�ǂݍ��݊֐�
    */
   void LoadBgm();
   /**
    * \brief BGM�{�����[���ύX�֐�
    */
   void VolumeChange();

   int _gkey;         //!< �L�[���͂̏��
   int _gtrg;         //!< �L�[���͂̃g���K���
   int _xbuf;         //!< ���X�e�b�B�NX���͗�
   int _ybuf;         //!< ���X�e�b�B�NY���͗�
   int _gcnt;         //!< ���t���[��+1����J�E���g
   int _cv_x;         //!< �J����X���W
   int _cv_y;         //!< �J����Y���W
   int _map_w;        //!< �}�b�v����
   int _map_h;        //!< �}�b�v�c��
   bool _restart_flag;//!< �ċN����̊J�n���ǂ����̃t���O
   std::unordered_map<std::string, int> _bgm;          //!< BGM�}�b�v
   std::unordered_map<std::string, int> _vpal;         //!< �{�����[���}�b�v
   std::unordered_map<std::string, bool> _cpoint_flag; //!< �`�F�b�N�|�C���g�t���O�}�b�v

   MapChip* _mapchip;         //!< �}�b�v�`�b�v
   ModeServer* _servermode;   //!< ���[�h�T�[�o�[
   ObjectServer _objserver;   //!< �I�u�W�F�N�g��o�^����
};
