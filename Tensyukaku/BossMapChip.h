#pragma once

#include <string>

// マップチップクラス
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
