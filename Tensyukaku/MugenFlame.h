/*****************************************************************//**
 * \file   MugenFlame.h
 * \brief  無限炎クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** 無限炎 */
class MugenFlame :public ObjectBase {
public:
   /**
    * \brief   コンストラクタ
    * \param x X座標
    * \param y Y座標
    */
   MugenFlame(int x, int y);
   /**
    * \brief デストラクタ
    */
   ~MugenFlame();
   /**
    * \brief                           //純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::MUGENFLAME   //オブジェクトの種別（無限炎）を返す
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::MUGENFLAME; }
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
/** 無限炎クラス用定数 */
namespace MFInfo {
   /*----------炎の各座標関係----------*/
   constexpr auto GRAPHPOINT_X = 0;       //!< X位置から描画点までの差分
   constexpr auto GRAPHPOINT_Y = -150;    //!< Y位置から描画点までの差分
   constexpr auto POSITION_HITX = -150;   //!< 描画点から当たり判定左上座標までの差分
   constexpr auto POSITION_HITY = -150;   //!< 描画点から当たり判定左上座標までの差分
   constexpr auto COLLISION_WIDTH = 300;  //!< 当たり判定横幅
   constexpr auto COLLISION_HEIGHT = 300; //!< 当たり判定縦幅
   /*----------画像読み込み&アニメーション&判定フレーム関係----------*/
   constexpr auto GRAPH_WIDTH = 300;      //!< 1枚当たりの画像サイズ（横）
   constexpr auto GRAPH_HEIGHT = 300;     //!< 1枚当たりの画像サイズ（縦）
   constexpr auto MFLAME_GRAPHNAME = "res/Gimik/Flame.png";   //!< 画像ファイル名
   constexpr auto MFLAME_ANIMEMAX = 7;    //!< 全ての画像枚数
   constexpr auto MFLAME_WIDTHCOUNT = 7;  //!< 横の画像枚数
   constexpr auto MFLAME_HEIGHTCOUNT = 1; //!< 縦の画像枚数
   constexpr auto ANIMESPEED_MFLAME = 15; //!< 各状態アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto MFLAME_ANIMEFRAME = MFLAME_ANIMEMAX * ANIMESPEED_MFLAME;  //!< アニメーションフレーム（全ての画像枚数×アニメスピード）
   constexpr auto MFLAME_ALLFLAME = 135;  //!< 全フレーム
   constexpr auto MFLAME_FADEOUTSPEED = 4;//!< フェードスピード

}