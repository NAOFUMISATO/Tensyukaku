#pragma once
#include	"BackGround.h"
#include	"MapChip.h"
#include	"Player.h"
#include	"ObjectServer.h"
#include	"ModeServer.h"
namespace Tsk {
	// ��ʐݒ�
	constexpr auto SCREEN_W = 1920;		///< ��ʂ̉��𑜓x
	constexpr auto SCREEN_H = 1080;		///< ��ʂ̏c�𑜓x
	constexpr auto SCREEN_DEPTH = 32;   ///< �P�h�b�g������̃r�b�g��


	// �Q�[���N���X
	class Game
	{
	public:
		Game();				// �A�v���̏�����
		~Game();			// �A�v���̉��

		void	Input();		// �t���[�������F����
		void	Process();		// �t���[�������F�v�Z
		void	Draw();		// �t���[�������F�`��

		//�Q�b�^�[�֐�
		int		GetKey() { return _gKey; }
		int		GetTrg() { return _gTrg; }
		int		GetmapH() { return _mapH; }
		int		GetcvX() { return _cvX; }
		int		GetcvY() { return _cvY; }
		BackGround	GetBg() { return _bg; }
		ModeServer* GetMS() { return _serverMode; }
		ObjectServer* GetOS() { return &_objServer; }
	/*	MapChips GetChips() { return _mapChips; }*/
		//�Z�b�^�[�֐�
		void	SetcvX(int cvX) { cvX = _cvX; }
		void	SetcvY(int cvY) { cvY = _cvY; }
		void	SetmapW(int mapW) { mapW = _mapW; }
		void	SetmapH(int mapH) { mapH = _mapH; }

	private:
		int _gKey;			// �L�[���͂̏��
		int _gTrg;			// �L�[���͂̃g���K���
		int _gCnt;			// ���t���[��+1����J�E���g
		int	_cvX, _cvY;		// �J����
		int _mapW, _mapH;	// �}�b�v

		BackGround	_bg;	// �w�i
		ModeServer* _serverMode; //���[�h�T�[�o�[
		ObjectServer _objServer; // �v���C���[��G�Ȃǂ�o�^����
		//MapChips	_mapChips; // �}�b�v�`�b�v
	};
}