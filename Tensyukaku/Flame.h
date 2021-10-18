/*****************************************************************//**
 * \file   Flame.h
 * \brief  行燈の炎クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** 行燈の炎 */
class Flame :public ObjectBase {
public:
   /**
    * \brief   コンストラクタ
    * \param x X座標
    * \param y Y座標
    */
   Flame(int x,int y);
   /**
    * \brief デストラクタ
    */
   ~Flame();
   /**
    * \brief                      //純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::FLAME   //オブジェクトの種別（行燈の炎）を返す
    */
   virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::FLAME; }
   /**
    * \brief 初期化関数
    */
   void Init()override;
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
};
/** 行燈の炎クラス用定数 */
namespace FInfo {
   /*----------炎の各座標関係----------*/
   constexpr auto GRAPHPOINT_X = 0;        //!< X位置から描画点までの差分
   constexpr auto GRAPHPOINT_Y = -150;     //!< Y位置から描画点までの差分
   constexpr auto POSITION_HITX = -150;    //!< 描画点から当たり判定左上座標までの差分
   constexpr auto POSITION_HITY = -150;    //!< 描画点から当たり判定左上座標までの差分
   constexpr auto COLLISION_WIDTH = 300;   //!< 当たり判定横幅
   constexpr auto COLLISION_HEIGHT = 300;  //!< 当たり判定縦幅
   /*----------画像読み込み&アニメーション&判定フレーム関係----------*/
   constexpr auto GRAPH_WIDTH = 300;       //!< 1枚当たりの画像サイズ（横）
   constexpr auto GRAPH_HEIGHT = 300;      //!< 1枚当たりの画像サイズ（縦）
   constexpr auto FLAME_GRAPHNAME = "res/Gimik/Flame.png";   //!< 画像ファイル名
   constexpr auto FLAME_ANIMEMAX = 7;      //!< 全ての画像枚数
   constexpr auto FLAME_WIDTHCOUNT = 7;    //!< 横の画像枚数
   constexpr auto FLAME_HEIGHTCOUNT = 1;   //!< 縦の画像枚数
   constexpr auto ANIMESPEED_FLAME = 15;   //!< 各状態アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto FLAME_ANIMEFRAME = FLAME_ANIMEMAX * ANIMESPEED_FLAME;   //!< アニメーションフレーム（全ての画像枚数×アニメスピード）
   constexpr auto FLAME_ALLFLAME = 135;    //!< 炎が燃え尽きる全フレーム
   constexpr auto FLAME_FADEOUTSPEED = 4;  //!< フェードスピード
   
}