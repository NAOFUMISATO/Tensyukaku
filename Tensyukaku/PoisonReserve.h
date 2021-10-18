/*****************************************************************//**
 * \file   PoisonReserve.h
 * \brief  毒液準備クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** 毒液準備 */
class PoisonReserve :public ObjectBase {
public:
   /**
    * \brief   コンストラクタ
    * \param x X座標
    * \param y Y座標
    */
   PoisonReserve(int x, int y);
   /**
    * \brief デストラクタ
    */
   ~PoisonReserve();
   /**
    * \brief                    純粋仮想関数のオーバーライド
    * \param OBJECTTYPE::POISON オブジェクトの種別（毒液）を返す
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::POISON; }
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