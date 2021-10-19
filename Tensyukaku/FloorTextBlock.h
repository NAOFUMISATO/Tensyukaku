/*****************************************************************//**
 * \file   FloorTextBlock.h
 * \brief  階層表示ブロッククラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** 階層表示ブロック */
class FloorTextBlock :public ObjectBase {
public:
   /**
    * \brief          コンストラクタ
    * \param texttype ブロックの種別文字列
    */
   FloorTextBlock(std::string  texttype);
   /**
    * \brief デストラクタ
    */
   ~FloorTextBlock();
   /**
    * \brief                             純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::FLOORTEXTBLOCK オブジェクトの種別（階層表示ブロック）を返す
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::FLOORTEXTBLOCK; }
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

private:
   /**
    * \brief 階層表示ブロックの種別による座標設定関数
    */
   void PositionSetting();

   std::string _text_type;    //!< 階層表示ブロックの種別を指定する文字列
};
/** 階層表示ブロッククラス用定数 */
namespace FTInfo {
   constexpr auto GRAPHPOINT_X = 0;      //!< X位置から描画点までの差分
   constexpr auto GRAPHPOINT_Y = -50;    //!< Y位置から描画点までの差分
   constexpr auto POSITION_HITX = -50;   //!< 描画点から当たり判定左上座標までの差分
   constexpr auto POSITION_HITY = -50;   //!< 描画点から当たり判定左上座標までの差分
   constexpr auto COLLISION_WIDTH = 100; //!< 当たり判定横幅
   constexpr auto COLLISION_HEIGHT = 100;//!< 当たり判定縦幅
   constexpr auto  TOP_TEXT_X =500;      //!< 「天守」表示ブロックX座標
   constexpr auto  TOP_TEXT_Y = 1000;    //!< 「天守」表示ブロックY座標
   constexpr auto  UPPER_TEXT_X = 400;   //!< 「上層」表示ブロックX座標
   constexpr auto  UPPER_TEXT_Y = 2520;  //!< 「上層」表示ブロックY座標
   constexpr auto  MIDDLE_TEXT_X = 5500; //!< 「中層」表示ブロックX座標
   constexpr auto  MIDDLE_TEXT_Y = 5560; //!< 「中層」表示ブロックY座標
   constexpr auto  UNDER_TEXT_X = 350;   //!< 「下層」表示ブロックX座標
   constexpr auto  UNDER_TEXT_Y = 9360;  //!< 「下層」表示ブロックY座標
}