/*****************************************************************//**
 * \file   MapChip.h
 * \brief  マップチップクラス
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include <string>
//二重インクルード防止
class Game;
class ObjectBase;
class MapChip {
public:
   MapChip(std::string filePath, std::string tiledFileName);
   ~MapChip();

   void Process(Game& g);
   void Draw(Game& g);

   int CheckHit(int x, int y);
   int IsHit(ObjectBase& o, int mx, int my);
   int GetscrX() { return _scr_x; }
   int GetscrY() { return _scr_y; }
   int GetMSW() { return _mapsize_w; }
   int GetMSH() { return _mapsize_h; }
   int GetCC() { return _chipcount; }
   int GetCCW() { return _chipcount_w; }
   int GetCCH() { return _chipcount_h; }
   int GetCSW() { return _chipsize_w; }
   int GetCSH() { return _chipsize_h; }
   void SetscrX(int scrX) { _scr_x = scrX; }
   void SetscrY(int scrY) { _scr_y = scrY; }

private:
   int _mapsize_w;
   int _mapsize_h;
   int _chipcount;
   int _chipcount_w;
   int _chipcount_h;
   int _chipsize_w;
   int _chipsize_h;
   int _mapsize_layer;
   std::string _strchip_file;
   int _scr_x, _scr_y;
   std::string StringFileLoad(std::string strFileName);
   int TiledJsonLoad(std::string filePath, std::string strFileName);
   int* _cg_chip;
   int* _map_data;
};
