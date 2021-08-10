//#pragma once
//namespace Tsk {
//	class Game;
//	class ObjectBase;
//
//#include <string>
//
//	// �}�b�v�`�b�v�N���X
//	class MapChips {
//	public:
//		MapChips(std::string filePath, std::string tiledFileName);
//		~MapChips();
//
//		void	Process(Game& g);
//		void	Draw();
//
//		int		CheckHit(int x, int y);
//		int		IsHit(ObjectBase& o, int mx, int my);
//
//
//	public:
//
//		// �}�b�v�̃T�C�Y�i�`�b�v���j
//		int MAPSIZE_W;	// width
//		int MAPSIZE_H;	// height
//
//		// �`�b�v�̌�
//		int CHIPCOUNT;		// tilecount
//		int CHIPCOUNT_W;		// columns
//		int CHIPCOUNT_H;		// �v�Z�ŏo��
//
//		// �`�b�v�̃T�C�Y�ipixel���j
//		int CHIPSIZE_W;
//		int CHIPSIZE_H;
//
//		// ���C���[��
//		int MAPSIZE_LAYER;	// �u<layer �v �̐��𐔂���
//
//		// �`�b�v�f�[�^�̃t�@�C����
//		std::string		_strChipFile;
//
//		// �X�N���[��
//		int		_scrX, _scrY;
//
//
//	private:
//		std::string StringFileLoad(std::string strFileName);
//		int		TiledJsonLoad(std::string filePath, std::string strFileName);
//
//		int* _cgChip;		// �}�b�v�`�b�v�摜
//
//		// �}�b�v�f�[�^
//		int* _mapData;
//	};
//}