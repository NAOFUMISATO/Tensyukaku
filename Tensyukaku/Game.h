#pragma once
#include	"BackGround.h"
#include	"MapChip.h"
#include	"BossMapChip.h"
#include	"Player.h"
#include	"ObjectServer.h"
#include	"ModeServer.h"

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
	int		GetXBuf() { return _Xbuf; }
	int		GetYBuf() { return _Ybuf; }
	int		GetmapH() { return _mapH; }
	int		GetmapW() { return _mapW; }
	int		GetcvX() { return _cvX; }
	int		GetcvY() { return _cvY; }
	MapChip* GetChip() { return _mapChip; }
	BossMapChip* GetBossChip() { return _bossmapChip; }
	ModeServer* GetMS() { return _serverMode; }
	ObjectServer* GetOS() { return &_objServer; }

	//�Z�b�^�[�֐�
	void	SetcvX(int cvX) { _cvX = cvX; }
	void	SetcvY(int cvY) { _cvY = cvY; }
	void	SetmapW(int mapW) { _mapW = mapW; }
	void	SetmapH(int mapH) { _mapH = mapH; }

private:
	int _gKey;			// �L�[���͂̏��
	int _gTrg;			// �L�[���͂̃g���K���
	int	_Xbuf;			//���X�e�b�B�NX���͗�
	int	_Ybuf;			//���X�e�b�B�NY���͗�
	int _gCnt;			// ���t���[��+1����J�E���g
	int	_cvX, _cvY;		// �J����
	int _mapW, _mapH;	// �}�b�v

	MapChip* _mapChip;			//�}�b�v�`�b�v
	BossMapChip* _bossmapChip;	//�{�X�}�b�v�`�b�v
	ModeServer* _serverMode;	//���[�h�T�[�o�[
	ObjectServer _objServer;	//�v���C���[��G�Ȃǂ�o�^����
};
