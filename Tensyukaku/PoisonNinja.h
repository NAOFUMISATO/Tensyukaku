/*****************************************************************//**
 * \file   PoisonNinja.h
 * \brief  毒液忍者クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** 毒液忍者 */
class PoisonNinja :public  ObjectBase {
public:
   /**
    * \brief      コンストラクタ
    * \param x    X座標
    * \param y    Y座標
    * \param flip 反転判定
    */
   PoisonNinja(int x,int y,bool flip);
   /**
    * \brief デストラクタ
    */
   ~PoisonNinja();
   /**
    * \brief                          純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::POISONNINJA オブジェクトの種別（毒液忍者）を返す
    */
   virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::POISONNINJA; }
   /**
    * \brief 初期化関数
    */
   void Init();
   /**
    * \brief   更新関数
    * \param g ゲームの参照
    */
   void Process(Game& g)override;
   /**
    * \brief   描画関数
    * \param g ゲームの参照
    */
   void Draw(Game& g)override;
   /**
    * \brief   オブジェクトの消去関数
    * \param g ゲームの参照
    */
   void Delete(Game& g)override;

private:
   /** 毒液忍者の状態列挙 */
   enum class ENEMYSTATE{
   APPEAR,     //!< 出現
   PATROL,     //!< 巡回
   POISING     //!< 毒液垂らし
   };
   /**
    * \brief   出現状態の関数
    * \param g ゲームの参照
    */
   void Appear(Game& g);
   /**
    * \brief   索敵状態の関数
    * \param g ゲームの参照
    */
   void Patrol(Game& g);
   /**
    * \brief   毒液垂らし状態の関数
    * \param g ゲームの参照
    */
   void Poising(Game& g);

   ENEMYSTATE _state;   //!< 毒液忍者の状態変数
};

/** 毒液忍者クラス用定数 */
namespace PNInfo {
   /*----------毒液忍者の各座標関係----------*/
   constexpr auto GRAPHPOINT_X = 0;          //!< X位置から描画点までの差分
   constexpr auto GRAPHPOINT_Y = -315;       //!< Y位置から描画点までの差分
   /*----------各モーションの当たり判定関係----------*/
   constexpr auto PATROL_WIDTH = 1000;       //!< 索敵範囲当たり判定横幅
   constexpr auto PATROL_HEIGHT = 500;       //!< 索敵範囲当たり判定縦幅
   constexpr auto POISINGCANCEL_WIDTH = 500; //!< 毒液垂らし中止当たり判定横幅
   constexpr auto POISINGCANCEL_HEIGHT = 500;//!< 毒液垂らし中止当たり判定縦幅

   /*----------画像読み込み&アニメーション&判定フレーム関係----------*/
   //共通
   constexpr auto GRAPH_WIDTH = 630;         //!< 1枚当たりの画像サイズ（横）
   constexpr auto GRAPH_HEIGHT = 630;        //!< 1枚当たりの画像サイズ（縦）
   //出現
   constexpr auto APPEAR_GRAPHNAME = "res/Gimik/N_Poison_Stand.png";   //!< 画像ファイル名
   constexpr auto APPEAR_ANIMEMAX = 1;       //!< 全ての画像枚数
   constexpr auto APPEAR_WIDTHCOUNT = 1;     //!< 横の画像枚数
   constexpr auto APPEAR_HEIGHTCOUNT = 1;    //!< 縦の画像枚数
   constexpr auto ANIMESPEED_APPEAR = 60;    //!< アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto FADEIN_SPEED = 4;          //!< アッパー時のフェードインスピード
   constexpr auto APPEAR_ALLFRAME = 60;      //!< 出現全フレーム
   //索敵
   constexpr auto PATROL_GRAPHNAME = "res/Gimik/N_Poison_Stand.png";   //!< 画像ファイル名
   constexpr auto PATROL_ANIMEMAX = 1;       //!< 全ての画像枚数
   constexpr auto PATROL_WIDTHCOUNT = 1;     //!< 横の画像枚数
   constexpr auto PATROL_HEIGHTCOUNT = 1;    //!< 縦の画像枚数
   constexpr auto ANIMESPEED_PATROL = 60;    //!< アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto PATROL_TURNFRAME = 120;    //!< 索敵時の振り向きフレーム
   //毒液垂らし
   constexpr auto POISING_GRAPHNAME = "res/Gimik/N_Poison.png";   //!< 画像ファイル名
   constexpr auto POISING_ANIMEMAX = 2;      //!< 全ての画像枚数
   constexpr auto POISING_WIDTHCOUNT = 2;    //!< 横の画像枚数
   constexpr auto POISING_HEIGHTCOUNT = 1;   //!< 縦の画像枚数
   constexpr auto ANIMESPEED_POISING = 40;   //!< 各状態アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto POISING_ANIMEFRAME = POISING_ANIMEMAX * ANIMESPEED_POISING;      //!< アニメーションフレーム（全ての画像枚数×アニメスピード）
   constexpr auto POISING_ALLFRAME = 230;    //!< 毒液垂らし全フレーム
   constexpr auto POISON_SPAWN_X = 170;      //!< 忍者からの毒液が染み込む座標へのX差分
   constexpr auto POISON_SPAWN_Y = 80;       //!< 忍者からの毒液が染み込む座標へのY差分
   //消去
   constexpr auto DELETE_HEIGHT = 500;       //!< 毒液忍者が消えるYの移動量
   constexpr auto FADEOUT_SPEED = 10;        //!< フェードスピード
}
/** 毒液準備、毒液落下クラス用定数 */
namespace PoInfo {
   /*----------毒液準備の各座標関係----------*/
   constexpr auto GRAPHPOINT_X = 0;         //!< X位置から描画点までの差分
   constexpr auto GRAPHPOINT_Y = 25;        //!< Y位置から描画点までの差分
   constexpr auto POSITION_HITX = -20;      //!< 描画点から当たり判定左上座標までの差分
   constexpr auto POSITION_HITY = -30;      //!< 描画点から当たり判定左上座標までの差分
   constexpr auto COLLISION_WIDTH = 40;     //!< 当たり判定横幅
   constexpr auto COLLISION_HEIGHT = 60;    //!< 当たり判定縦幅

   /*----------画像読み込み&アニメーション&判定フレーム関係----------*/
   constexpr auto GRAPH_WIDTH = 90;         //!< 1枚当たりの画像サイズ（横）
   constexpr auto GRAPH_HEIGHT = 90;        //!< 1枚当たりの画像サイズ（縦）
   //毒液準備
   constexpr auto RESERVE_GRAPHNAME = "res/Gimik/PoisonReserve.png";   //!< 画像ファイル名
   constexpr auto RESERVE_ANIMEMAX = 4;     //!< 全ての画像枚数
   constexpr auto RESERVE_WIDTHCOUNT = 4;   //!< 横の画像枚数
   constexpr auto RESERVE_HEIGHTCOUNT = 1;  //!< 縦の画像枚数
   constexpr auto ANIMESPEED_RESERVE = 30;  //!< 各状態アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto RESERVE_FALLFRAME = 90;   //!< 準備状態から毒液が落ち始めるフレーム
   constexpr auto RESERVE_ANIMEFRAME = RESERVE_ANIMEMAX * ANIMESPEED_RESERVE;   //!< アニメーションフレーム（全ての画像枚数×アニメスピード）
   constexpr auto RESERVE_FADEOUTSPEED = 8; //!< フェードスピード
   constexpr auto RESERVE_ALLFRAME = 150;   //!< 毒液準備の全フレーム
   //毒液落下
   constexpr auto FALL_GRAPHNAME = "res/Gimik/PoisonFall.png";   //!< 画像ファイル名
   constexpr auto FALL_ANIMEMAX = 1;        //!< 全ての画像枚数
   constexpr auto FALL_WIDTHCOUNT = 1;      //!< 横の画像枚数
   constexpr auto FALL_HEIGHTCOUNT = 1;     //!< 縦の画像枚数
   constexpr auto FALL_STOPFRAME = 41;      //!< 落下が止まるフレーム
   //毒液着地
   constexpr auto LAND_GRAPHNAME = "res/Gimik/PoisonLand.png";   //!< 画像ファイル名
   constexpr auto LAND_ANIMEMAX = 3;        //!< 全ての画像枚数
   constexpr auto LAND_WIDTHCOUNT = 3;      //!< 横の画像枚数
   constexpr auto LAND_HEIGHTCOUNT = 1;     //!< 縦の画像枚数
   constexpr auto ANIMESPEED_LAND = 10;     //!< 各状態アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto LAND_ANIMEFRAME = LAND_ANIMEMAX * ANIMESPEED_LAND;   //!< アニメーションフレーム（全ての画像枚数×アニメスピード）
   constexpr auto LAND_FADEOUTSPEED = 8;    //!< フェードスピード
   constexpr auto LAND_ALLFRAME = 60;       //!< 毒液の全フレーム
}