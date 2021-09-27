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
	int		GetKey() { return _gkey; }
	int		GetTrg() { return _gtrg; }
	int		GetXBuf() { return _xbuf; }
	int		GetYBuf() { return _ybuf; }
	int		GetmapH() { return _map_h; }
	int		GetmapW() { return _map_w; }
	int		GetcvX() { return _cv_x; }
	int		GetcvY() { return _cv_y; }
	bool		GetCPointFlag() { return _cpoint_flag; }
	bool		GetRestartFlag() { return _restart_flag; }
	bool		GetTutorial1Flag() { return _tutorial1_flag; }
	bool		GetTutorial2Flag() { return _tutorial2_flag; }
	bool		GetTutorial3Flag() { return _tutorial3_flag; }
	bool		GetTutorial4Flag() { return _tutorial4_flag; }
	bool		GetTutorial5Flag() { return _tutorial5_flag; }

	MapChip* GetChip() { return _mapchip; }
	ModeServer* GetMS() { return _servermode; }
	ObjectServer* GetOS() { return &_objserver; }
	std::unordered_map<std::string, int> GetBgm() { return _bgm; }
	std::unordered_map<std::string, int> GetVpal() { return _vpal; }
	//�Z�b�^�[�֐�
	void	SetcvX(int cvX) { _cv_x = cvX; }
	void	SetcvY(int cvY) { _cv_y = cvY; }
	void	SetmapW(int mapW) { _map_w = mapW; }
	void	SetmapH(int mapH) { _map_h = mapH; }
	void	SetChip(MapChip* map) { _mapchip = map; }
	void	SetCPointFlag(bool cpointflag) { _cpoint_flag = cpointflag; }
	void	SetRestartFlag(bool restartflag) { _restart_flag = restartflag; }
	void	SetTutorial1Flag(bool tutorial1flag) { _tutorial1_flag=tutorial1flag; }
	void	SetTutorial2Flag(bool tutorial2flag) { _tutorial2_flag=tutorial2flag; }
	void	SetTutorial3Flag(bool tutorial3flag) { _tutorial3_flag=tutorial3flag; }
	void	SetTutorial4Flag(bool tutorial4flag) { _tutorial4_flag=tutorial4flag; }
	void	SetTutorial5Flag(bool tutorial5flag) { _tutorial5_flag=tutorial5flag; }
	void   SetVpal(std::unordered_map<std::string, int> vpal) { _vpal = vpal; }
private:
	void		LoadBgm();	//BGM�ǂݍ���
	void		VolumeInit();//BGM�̃{�����[�������l
	void		VolumeChange();//BGM�̃{�����[���ύX�֐�

	int _gkey;			// �L�[���͂̏��
	int _gtrg;			// �L�[���͂̃g���K���
	int	_xbuf;			//���X�e�b�B�NX���͗�
	int	_ybuf;			//���X�e�b�B�NY���͗�
	int _gcnt;			// ���t���[��+1����J�E���g
	int	_cv_x, _cv_y;		// �J����
	int _map_w, _map_h;	// �}�b�v
	bool _cpoint_flag;	//�`�F�b�N�|�C���g�t���O
	bool _restart_flag;//�ċN����̊J�n���ǂ����̃t���O
	bool _tutorial1_flag;//�`���[�g���A��1�̏o���t���O
	bool _tutorial2_flag;//�`���[�g���A��2�̏o���t���O
	bool _tutorial3_flag;//�`���[�g���A��3�̏o���t���O
	bool _tutorial4_flag;//�`���[�g���A��4�̏o���t���O
	bool _tutorial5_flag;//�`���[�g���A��5�̏o���t���O
	std::unordered_map<std::string, int> _bgm; //BGM�}�b�v
	std::unordered_map<std::string, int> _vpal; //�{�����[���}�b�v

	MapChip* _mapchip;			//�}�b�v�`�b�v
	ModeServer* _servermode;	//���[�h�T�[�o�[
	ObjectServer _objserver;	//�v���C���[��G�Ȃǂ�o�^����
};
