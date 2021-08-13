#pragma once

#include <string>

// マップチップクラス
class Game;
class ObjectBase;
class MapChip {
public:
	MapChip(std::string filePath, std::string tiledFileName);
	~MapChip();

	void	Process(Game& g);
	void	Draw();

	int		CheckHit(int x, int y);
	int		IsHit(ObjectBase& o, int mx, int my);
	int		GetScrX() { return _scrX; }
	int		GetScrY() { return _scrY; }
	void	SetScr(int scrX, int scrY) {scrX = _scrX, scrY = _scrY;}

private:

	// マップのサイズ（チップ数）
	int MAPSIZE_W;	// width
	int MAPSIZE_H;	// height

	// チップの個数
	int CHIPCOUNT;		// tilecount
	int CHIPCOUNT_W;		// columns
	int CHIPCOUNT_H;		// 計算で出す

	// チップのサイズ（pixel数）
	int CHIPSIZE_W;
	int CHIPSIZE_H;

	// レイヤー数
	int MAPSIZE_LAYER;	// 「<layer 」 の数を数える

	// チップデータのファイル名
	std::string		_strChipFile;

	// スクロール
	int		_scrX, _scrY;



	std::string StringFileLoad(std::string strFileName);
	int		TiledJsonLoad(std::string filePath, std::string strFileName);

	int* _cgChip;		// マップチップ画像

	// マップデータ
	int* _mapData;
};
