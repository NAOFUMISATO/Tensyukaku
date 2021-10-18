/*****************************************************************//**
 * \file   BossEventBlock.h
 * \brief  ボスイベント発生ブロッククラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** ボスイベント発生ブロック */
class BossEventBlock :public ObjectBase {
public:
   /**
    * \brief          コンストラクタ
    * \param blocknum ブロック番号
    */
   BossEventBlock(int blocknum);
   /**
    * \brief デストラクタ
    */
   ~BossEventBlock();
   /**
    * \brief                              純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::BOSSEVENTBLOCK  オブジェクトの種別（ボスイベントブロック）を返す
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::BOSSEVENTBLOCK; }
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
    * \brief ブロック番号ごとの座標設定関数
    */
   void PositionSetting();

   int _block_num;   //!< ブロック番号変数
};
/** ボスイベント発生ブロッククラス用定数 */
namespace BEInfo {

   constexpr auto BOSSA_X = 5300;         //!< ボスイベントブロックAのX座標
   constexpr auto BOSSA_Y = 1760;         //!< ボスイベントブロックAのY座標
   constexpr auto BOSSB_X = 4500;         //!< ボスイベントブロックBのX座標
   constexpr auto BOSSB_Y = 1000;         //!< ボスイベントブロックBのY座標
   constexpr auto GRAPHPOINT_X = 0;       //!< X位置から描画点までの差分
   constexpr auto GRAPHPOINT_Y = -50;     //!< Y位置から描画点までの差分
   constexpr auto POSITION_HITX = -50;    //!< 描画点から当たり判定左上座標までの差分
   constexpr auto POSITION_HITY = -50;    //!< 描画点から当たり判定左上座標までの差分
   constexpr auto COLLISION_WIDTH = 100;  //!< 当たり判定横幅
   constexpr auto COLLISION_HEIGHT = 100; //!< 当たり判定縦幅


}