#pragma once
#include "ObjectBase.h"
//毒液の準備時及び落下時のクラス
class PoisonReserve :public ObjectBase {
public:
   PoisonReserve(int x, int y);
   ~PoisonReserve();

   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::POISON; }

   void Init();
   void Process(Game& g)override;
   void Draw(Game& g)override;
   void Delete(Game& g)override;
};

class PoisonFall :public ObjectBase {
public:
   PoisonFall(int x, int y);
   ~PoisonFall();

   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::POISON; }

   void Init();
   void Process(Game& g)override;
   void Draw(Game& g)override;
   void Delete(Game& g)override;
private:
   enum class POISONSTATE {FALL,LAND};
   POISONSTATE _State;
   int _Appear_y;
};

namespace PoInfo {
   /*----------毒液準備の各座標関係----------*/
   constexpr auto GRAPHPOINT_X = 0;      //X位置から描画点までの差分
   constexpr auto GRAPHPOINT_Y = 25;      //Y位置から描画点までの差分
   constexpr auto POSITION_HITX = -20;      //描画点から当たり判定左上座標までの差分
   constexpr auto POSITION_HITY = -30;      //描画点から当たり判定左上座標までの差分
   constexpr auto COLLISION_WIDTH = 40;   //当たり判定横幅
   constexpr auto COLLISION_HEIGHT = 60;   //当たり判定縦幅
   
   /*----------画像読み込み&アニメーション&判定フレーム関係----------*/
   constexpr auto GRAPH_WIDTH = 90;      //1枚当たりの画像サイズ（横）
   constexpr auto GRAPH_HEIGHT = 90;      //1枚当たりの画像サイズ（縦）
   //毒液準備
   constexpr auto RESERVE_GRAPHNAME = "res/Gimik/PoisonReserve.png";   //画像ファイル名
   constexpr auto RESERVE_ANIMEMAX = 4;      //全ての画像枚数
   constexpr auto RESERVE_WIDTHCOUNT = 4;      //横の画像枚数
   constexpr auto RESERVE_HEIGHTCOUNT = 1;      //縦の画像枚数
   constexpr auto ANIMESPEED_RESERVE = 30;      //各状態アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto RESERVE_FALLFRAME = 90;         //準備状態から毒液が落ち始めるフレーム
   constexpr auto RESERVE_ANIMEFRAME = RESERVE_ANIMEMAX * ANIMESPEED_RESERVE;      //アニメーションフレーム（全ての画像枚数×アニメスピード）
   constexpr auto RESERVE_FADEOUTSPEED = 8;      //フェードスピード
   constexpr auto RESERVE_ALLFRAME = 150;      //毒液準備の全フレーム
   //毒液落下
   constexpr auto FALL_GRAPHNAME = "res/Gimik/PoisonFall.png";   //画像ファイル名
   constexpr auto FALL_ANIMEMAX = 1;         //全ての画像枚数
   constexpr auto FALL_WIDTHCOUNT = 1;         //横の画像枚数
   constexpr auto FALL_HEIGHTCOUNT = 1;      //縦の画像枚数
   constexpr auto FALL_STOPFRAME = 41;      //落下が止まるフレーム
   //毒液着地
   constexpr auto LAND_GRAPHNAME = "res/Gimik/PoisonLand.png";   //画像ファイル名
   constexpr auto LAND_ANIMEMAX = 3;         //全ての画像枚数
   constexpr auto LAND_WIDTHCOUNT = 3;         //横の画像枚数
   constexpr auto LAND_HEIGHTCOUNT = 1;      //縦の画像枚数
   constexpr auto ANIMESPEED_LAND = 10;      //各状態アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto LAND_ANIMEFRAME = LAND_ANIMEMAX * ANIMESPEED_LAND;            //アニメーションフレーム（全ての画像枚数×アニメスピード）
   constexpr auto LAND_FADEOUTSPEED = 8;      //フェードスピード
   constexpr auto LAND_ALLFRAME = 60;      //毒液の全フレーム
}