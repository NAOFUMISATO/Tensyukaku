/*****************************************************************//**
 * \file   FlameBlock.h
 * \brief  炎演出ブロッククラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** 炎演出ブロック */
class FlameBlock :public ObjectBase {
public:
   /**
    * \brief   コンストラクタ
    * \param x X座標
    * \param y Y座標
    */
   FlameBlock(int x, int y);
   /**
    * \brief デストラクタ
    */
   ~FlameBlock();
   /**
    * \brief                         純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::FLAMEBLOCK オブジェクトの種別（炎演出ブロック）を返す
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::FLAMEBLOCK; }
   /**
    * \brief 初期化関数
    */
   void Init()override;
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