#pragma once

#include <string>

// �}�b�v�`�b�v�N���X
class Game;
class ObjectBase;
class MapChip {
public:
	MapChip(std::string filePath, std::string tiledFileName);
	~MapChip();

	void	Process(Game& g);
	void	Draw(Game& g);

	int		CheckHit(int x, int y);
	int		IsHit(ObjectBase& o, int mx, int my);
	int		GetscrX() { return _scr_x; }
	int		GetscrY() { return _scr_y; }
	int		GetMSW() { return _mapsize_w; }
	int		GetMSH() { return _mapsize_h; }
	int		GetCC() { return _chipcount; }
	int		GetCCW() { return _chipcount_w; }
	int		GetCCH() { return _chipcount_h; }
	int		GetCSW() { return _chipsize_w; }
	int		GetCSH() { return _chipsize_h; }
	void		SetscrX(int scrX) { _scr_x = scrX; }
	void		SetscrY(int scrY) { _scr_y = scrY; }

private:

	// �}�b�v�̃T�C�Y�i�`�b�v���j
	int _mapsize_w;	// width
	int _mapsize_h;	// height

	// �`�b�v�̌�
	int _chipcount;		// tilecount
	int _chipcount_w;		// columns
	int _chipcount_h;		// �v�Z�ŏo��

	// �`�b�v�̃T�C�Y�ipixel���j
	int _chipsize_w;
	int _chipsize_h;

	// ���C���[��
	int _mapsize_layer;	// �u<layer �v �̐��𐔂���

	// �`�b�v�f�[�^�̃t�@�C����
	std::string		_strchip_file;

	// �X�N���[��
	int		_scr_x, _scr_y;



	std::string StringFileLoad(std::string strFileName);
	int		TiledJsonLoad(std::string filePath, std::string strFileName);

	int* _cg_chip;		// �}�b�v�`�b�v�摜

	// �}�b�v�f�[�^
	int* _map_data;
};
