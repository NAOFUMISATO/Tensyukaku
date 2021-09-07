#pragma once

#include <string>

// �}�b�v�`�b�v�N���X
class Game;
class ObjectBase;
class BossMapChip {
public:
	BossMapChip(std::string filePath, std::string tiledFileName);
	~BossMapChip();

	void	Process(Game& g);
	void	Draw();

	int		CheckHit(int x, int y);
	int		IsHit(ObjectBase& o, int mx, int my);
	int		GetscrX() { return _scrX; }
	int		GetscrY() { return _scrY; }
	int		GetMSW() { return MAPSIZE_W; }
	int		GetMSH() { return MAPSIZE_H; }
	int		GetCC() { return CHIPCOUNT; }
	int		GetCCW() { return CHIPCOUNT_W; }
	int		GetCCH() { return CHIPCOUNT_H; }
	int		GetCSW() { return CHIPSIZE_W; }
	int		GetCSH() { return CHIPSIZE_H; }
	void	SetscrX(int scrX) { _scrX = scrX; }
	void	SetscrY(int scrY) { _scrY = scrY; }

private:

	// �}�b�v�̃T�C�Y�i�`�b�v���j
	int MAPSIZE_W;	// width
	int MAPSIZE_H;	// height

	// �`�b�v�̌�
	int CHIPCOUNT;		// tilecount
	int CHIPCOUNT_W;		// columns
	int CHIPCOUNT_H;		// �v�Z�ŏo��

	// �`�b�v�̃T�C�Y�ipixel���j
	int CHIPSIZE_W;
	int CHIPSIZE_H;

	// ���C���[��
	int MAPSIZE_LAYER;	// �u<layer �v �̐��𐔂���

	// �`�b�v�f�[�^�̃t�@�C����
	std::string		_strChipFile;

	// �X�N���[��
	int		_scrX, _scrY;



	std::string StringFileLoad(std::string strFileName);
	int		TiledJsonLoad(std::string filePath, std::string strFileName);

	int* _cgChip;		// �}�b�v�`�b�v�摜

	// �}�b�v�f�[�^
	int* _mapData;
};
