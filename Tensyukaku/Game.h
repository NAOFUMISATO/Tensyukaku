#pragma once
#include	"BackGround.h"
#include	"MapChip.h"
#include	"Player.h"
#include	"ObjectServer.h"
#include	"ModeServer.h"
#include	<unordered_map>

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
	int		GetCPointFlag() { return _CPoint_Flag; }
	MapChip* GetChip() { return _mapChip; }
	ModeServer* GetMS() { return _serverMode; }
	ObjectServer* GetOS() { return &_objServer; }
	std::unordered_map<std::string, int> GetBgm() { return _Bgm; }
	std::unordered_map<std::string, int> GetVpal() { return _Vpal; }
	//�Z�b�^�[�֐�
	void	SetcvX(int cvX) { _cvX = cvX; }
	void	SetcvY(int cvY) { _cvY = cvY; }
	void	SetmapW(int mapW) { _mapW = mapW; }
	void	SetmapH(int mapH) { _mapH = mapH; }
	void	SetChip(MapChip* map) { _mapChip = map; }
	void	SetCPointFlag(bool cpointflag) { _CPoint_Flag = cpointflag; }
	void   SetVpal(std::unordered_map<std::string, int> vpal) { _Vpal = vpal; }
private:
	void		LoadBgm();	//BGM�ǂݍ���
	void		VolumeInit();//BGM�̃{�����[�������l
	void		VolumeChange();//BGM�̃{�����[���ύX�֐�

	int _gKey;			// �L�[���͂̏��
	int _gTrg;			// �L�[���͂̃g���K���
	int	_Xbuf;			//���X�e�b�B�NX���͗�
	int	_Ybuf;			//���X�e�b�B�NY���͗�
	int _gCnt;			// ���t���[��+1����J�E���g
	int	_cvX, _cvY;		// �J����
	int _mapW, _mapH;	// �}�b�v
	bool _CPoint_Flag;	//�`�F�b�N�|�C���g�t���O
	std::unordered_map<std::string, int> _Bgm; //BGM�}�b�v
	std::unordered_map<std::string, int> _Vpal; //�{�����[���}�b�v

	MapChip* _mapChip;			//�}�b�v�`�b�v
	ModeServer* _serverMode;	//���[�h�T�[�o�[
	ObjectServer _objServer;	//�v���C���[��G�Ȃǂ�o�^����
};
