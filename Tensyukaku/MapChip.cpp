/*****************************************************************//**
 * \file   MapChip.cpp
 * \brief  マップチップクラス
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <DxLib.h>
#include <string>
#include "MapChip.h"
#include "ResourceServer.h"
#include "Game.h"
#include "ObjectBase.h"
#include "picojson.h"

MapChip::MapChip(std::string filePath, std::string tiledFileName)
{
   // jsonデータからマップデータをロードする
   TiledJsonLoad(filePath, tiledFileName + ".json");

   // チップ画像をロード
   _cg_chip = new int[_chipcount];      // マップチップ画像
   ResourceServer::LoadDivGraph((filePath + _strchip_file).c_str(), _chipcount, _chipcount_w, _chipcount_h, _chipsize_w, _chipsize_h, _cg_chip);

   // スクロール値
   _scr_x = 0;
   _scr_y = 0;

}

MapChip::~MapChip()
{
   // 確保したメモリを解放する
   delete[]   _cg_chip;
   delete[]   _map_data;
}

// 文字列のファイルをロードする
std::string MapChip::StringFileLoad(std::string strFileName)
{
   // ファイルを開く
   FILE* fp;
   fp = fopen(strFileName.c_str(), "rb");
   if (fp == NULL)
   {
      // ファイルが開けなかった（ファイル名が違うなど）
      return "";
   }
   // ファイルのサイズを取得
   fseek(fp, 0, SEEK_END); int size = ftell(fp); fseek(fp, 0, SEEK_SET);
   // メモリを確保する
   char* p;
   p = new char[size + 1];
   // メモリにデータを読み込む
   fread(p, 1, size, fp);
   // ファイルを閉じる
   fclose(fp);
   p[size] = '\0';

   // 読み込んだデータをstringにする
   std::string s = (char*)p;

   // メモリを解放する
   delete[] p;

   // stringを返す
   return s;
}

// Tiled-jsonデータロード
int      MapChip::TiledJsonLoad(std::string filePath, std::string strFileName)
{
   // ファイルを開いてstringを取得する
   std::string strJson = StringFileLoad(filePath + strFileName);
   if (strJson == "")
   {
      // ファイルが開けなかった
      return 0;
   }

   // 読み込んだstringをjsonオブジェクト化する
   picojson::value json;
   picojson::parse(json, strJson);
   picojson::object jsRoot = json.get<picojson::object>();

   // パラメータをjsonから取得
   _mapsize_w = (int)jsRoot["width"].get<double>();
   _mapsize_h = (int)jsRoot["height"].get<double>();

   // タイルセット取得(1つのみ対応)
   picojson::array aTileSets = jsRoot["tilesets"].get<picojson::array>();
   picojson::object jsTile = aTileSets[0].get<picojson::object>();
   _chipcount = (int)jsTile["tilecount"].get<double>();
   _chipcount_w = (int)jsTile["columns"].get<double>();
   _chipcount_h = (_chipcount / _chipcount_w);      // 計算で出す
   _chipsize_w = (int)jsRoot["tilewidth"].get<double>();
   _chipsize_h = (int)jsRoot["tileheight"].get<double>();
   _strchip_file = jsTile["image"].get<std::string>();

   // レイヤー情報の取得
   picojson::array aLayers = jsRoot["layers"].get<picojson::array>();
   // マップの"tilelayer"レイヤー数を数える
   int layer;
   layer = 0;
   for (int i = 0; i < aLayers.size(); i++)
   {
      picojson::object jsLayer = aLayers[i].get<picojson::object>();      // レイヤーオブジェクト
      // レイヤー種類が「tilelayer」のものをカウントする
      if (jsLayer["type"].get<std::string>() == "tilelayer")
      {
         layer++;
      }
   }
   _mapsize_layer = layer;

   // レイヤー内データの取得
   _map_data = new int[(int)(_mapsize_layer * _mapsize_w * _mapsize_h)];
   layer = 0;
   for (int i = 0; i < aLayers.size(); i++)
   {
      picojson::object jsLayer = aLayers[i].get<picojson::object>();      // レイヤーオブジェクト
      // レイヤー種類が「tilelayer」のものをカウントする
      if (jsLayer["type"].get<std::string>() == "tilelayer")
      {
         picojson::array aData = jsLayer["data"].get<picojson::array>();         // マップ配列
         for (int y = 0; y < _mapsize_h; y++)
         {
            for (int x = 0; x < _mapsize_w; x++)
            {
               int layerstart = _mapsize_w * _mapsize_h * layer;
               int index = y * _mapsize_w + x;
               _map_data[layerstart + index] = (int)aData[index].get<double>();

            }
         }
         layer++;
      }
   }

   return 1;
}

void   MapChip::Process(Game& g)
{
   // カメラがマップデータを超えないようにする
   if (_scr_x < 0) { _scr_x = 0; }
   if (_scr_x > _mapsize_w * _chipsize_w - SCREEN_W) { _scr_x = _mapsize_w * _chipsize_w - SCREEN_W; }
   if (_scr_y < 0) { _scr_y = 0; }
   if (_scr_y > _mapsize_h * _chipsize_h - SCREEN_H) { _scr_y = _mapsize_h * _chipsize_h - SCREEN_H; }

}
void   MapChip::Draw(Game& g)
{
   int x, y, layer;
   for (layer = 0; layer < _mapsize_layer; layer++)
   {
      for (y = _scr_y / _chipsize_h; y <= (_scr_y + SCREEN_H) / _chipsize_h + 1; y++)
      {
         if (y < 0 || _mapsize_h <= y) { continue; }
         for (x =_scr_x/_chipsize_w; x <= (_scr_x+SCREEN_W)/ _chipsize_w+1; x++)
         {
            if (x < 0 || _mapsize_w <= x) { continue; }
            int layerstart = _mapsize_w * _mapsize_h * layer;
            int index = y * _mapsize_w + x;
            int pos_x = x * _chipsize_w - _scr_x;
            int pos_y = y * _chipsize_h - _scr_y;
            int chip_no = _map_data[layerstart + index];
            // .tmxのcsv形式は、透明を0とし、画像のチップは[1]から始まる。
            // そのため、全体的に数値を-1する。透明は-1となるので、if判定を追加
            chip_no--;
            if (chip_no >= 0)
            {
               DrawGraph(pos_x, pos_y, _cg_chip[chip_no], TRUE);

               // 開発用：このチップは当たり判定を行うものか？
               if (CheckHit(x, y) != 0)
               {
                  
                  //SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);      // 半透明描画指定
                  //DrawBox(pos_x, pos_y, pos_x + CHIPSIZE_W, pos_y + CHIPSIZE_H, GetColor(255, 0, 0), TRUE);   // 半透明の赤で当たり判定描画
                  //SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);      // 不透明描画指定
                  
               }
            }
         }
      }
   }
}





// マップチップとの当たり判定
// 引数：
//   x,y = マップチップの位置(x,y) チップ単位
// 戻値：
//   0 : 当たり判定を行わない
//   0以外 : 当たり判定を行う（チップ番号を返す）
int MapChip::CheckHit(int x, int y)
{
   // マップチップ位置はマップデータからはみ出ているか？
   if (0 <= x && x < _mapsize_w && 0 <= y && y < _mapsize_h)
   {   // はみでていない

      // マップチップIDが0以外は当たり判定を行う
      // 現在、レイヤーは考慮されていない
      int chip_no = _map_data[y * _mapsize_w + x];

      // 当たるIDかどうかをチェック
      int idtable[] =
      {
      27,28,29,30, 40,41,42,43, 53,54,55,56, 66,67,68,69,79,80,81,82, 92,93,94,95, 105,106,107,108, 118,119,120,121,131,132,133,134,144,145,146,147,157,158,159,160,161,
         
         -1      // 最後
      };
      int i = 0;
      while (idtable[i] != -1)
      {
         if (chip_no == idtable[i])
         {
            // 当たった
            return chip_no;
         }
         i++;
      }
   }

   // 当たっていない
   return 0;
}


// オブジェクトとマップチップが当たったかの判定、および当たった場合の処理
// 引数：
//   o = オブジェクト
//   mx = Xの移動方向(マイナス:0:プラス)
//   my = Yの移動方向(マイナス:0:プラス)
// 戻値：
//   0 : 当たってない
//   1 : 当たった
int MapChip::IsHit(ObjectBase& o, int mx, int my)
{
   int x, y;


   // キャラ矩形を作成する
   int l, t, r, b;      // 左上(left,top) - 右下(right,bottom)
   auto HB = o.GetHB();
   l = HB._x + HB._hit_x;
   t = HB._y + HB._gy + HB._hit_y;
   r = HB._x + HB._hit_x + HB._hit_w;
   b = HB._y + HB._gy + HB._hit_y + HB._hit_h - 1;

   // キャラの左上座標～右下座標にあたるマップチップと、当たり判定を行う
   for (y = t / _chipsize_h; y <= b / _chipsize_h; y++)
   {
      for (x = l / _chipsize_w; x <= r / _chipsize_w; x++)
      {
         // (x,y)は、マップチップの座標（チップ単位）
         // この位置のチップは当たるか？
         int chip_no = CheckHit(x, y);
         if (chip_no != 0)
         {   // このチップと当たった。
            // X,Yの移動方向を見て、その反対方向に補正するz
            if (mx < 0)
            {   // 左に動いていたので、右に補正
               o.SetX(x * _chipsize_w + _chipsize_w - (HB._hit_x));
            }
            if (mx > 0)
            {   // 右に動いていたので、左に補正
               o.SetX(x * _chipsize_w  - (HB._hit_x + HB._hit_w));
            }
            if (my > 0)
            {   // 下に動いていたので、上に補正
               o.SetY(y * _chipsize_h - (HB._hit_y +HB._hit_h));
            }
            if (my < 0)
            {   // 上に動いていたので、下に補正
               o.SetY(y * _chipsize_h + _chipsize_h - (HB._hit_y));
            }
            // 当たったので戻る
            return 1;
         }
      }
   }

   // 当たらなかった
   return 0;
   
}
