/*****************************************************************//**
 * \file   IaiCollision.h
 * \brief  居合当たり判定クラス（オブジェクトベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"

 /** 居合当たり判定クラス */
class IaiCollision : public ObjectBase {
public:
   /**
   * \brief   コンストラクタ
   * \param x X座標
   * \param y Y座標
   */
   IaiCollision(int x, int y);
   /**
    * \brief デストラクタ
    */
   ~IaiCollision();
   /**
   * \brief                  純粋仮想関数のオーバーライド
   * \return OBJECTTYPE::IAI オブジェクトの種別（居合攻撃当たり判定）を返す
   */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::IAI; }
   /**
    * \brief 初期化関数
    */
   void Init()override;
   /**
    * \brief   更新関数
    * \param g ゲームクラスの参照
    */
   void Process(Game& g)override;
   /**
    * \brief   描画関数
    * \param g ゲームクラスの参照
    */
   void Draw(Game& g)override;
   /**
    * \brief   オブジェクトの消去関数
    * \param g ゲームクラスの参照
    */
   void Delete(Game& g)override;
};