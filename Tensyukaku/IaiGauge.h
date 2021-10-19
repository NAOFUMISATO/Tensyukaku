/*****************************************************************//**
 * \file   IaiGauge.h
 * \brief  居合ゲージUIクラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"

/** 居合ゲージUI */
class IaiGauge :public ObjectBase {
public:
   /**
    * \brief コンストラクタ
    */
   IaiGauge();
   /**
    * \brief デストラクタ
    */
   ~IaiGauge();
   /**
    * \brief                 純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::UI オブジェクトの種別（UI）を返す
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::UI; }
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
};