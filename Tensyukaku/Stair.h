/*****************************************************************//**
 * \file   Stair.h
 * \brief  階段クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** 階段 */
class Stair :public ObjectBase {
public:
   /**
    * \brief      コンストラクタ
    * \param x    X座標
    * \param y    Y座標
    * \param flip 反転判定
    */
   Stair(int x,int y,bool flip);
   /**
    * \brief デストラクタ
    */
   ~Stair();
   /**
    * \brief                      //純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::STAIR   //オブジェクトの種別（階段）を返す
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::STAIR; }
   /**
    * \brief 初期化関数
    */
   void   Init()override;
   /**
    * \brief   更新関数
    * \param g ゲームの参照
    */
   void   Process(Game& g)override;
   /**
    * \brief   描画関数
    * \param g ゲームの参照
    */
   void   Draw(Game& g)override;
};
/** 階段クラス用定数 */
namespace StInfo {
   constexpr auto GRAPHPOINT_X = 0;         //!< X位置から描画点までの差分
   constexpr auto GRAPHPOINT_Y = -400;      //!< Y位置から描画点までの差分
   constexpr auto POSITION_HITX = -135;     //!< 描画点から当たり判定左上座標までの差分
   constexpr auto POSITION_HITY = -360;     //!< 描画点から当たり判定左上座標までの差分
   constexpr auto COLLISION_WIDTH = 270;    //!< 階段の当たり判定横幅
   constexpr auto COLLISION_HEIGHT = 760;   //!< 階段の当たり判定縦幅
}
