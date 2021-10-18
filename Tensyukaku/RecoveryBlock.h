/*****************************************************************//**
 * \file   RecoveryBlock.h
 * \brief  回復ブロッククラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** 回復ブロック */
class RecoveryBlock :public ObjectBase {
public:
   /**
    * \brief   コンストラクタ
    * \param x X座標
    * \param y Y座標
    */
   RecoveryBlock(int x,int y);
   /**
    * \brief デストラクタ
    */
   ~RecoveryBlock();
   /**
    * \brief                              //純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::RECOVERYBLOCK  //オブジェクトの種別（回復ブロック）を返す
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::RECOVERYBLOCK; }
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