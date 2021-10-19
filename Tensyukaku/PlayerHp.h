/*****************************************************************//**
 * \file   PlayerHp.h
 * \brief  プレイヤーの体力UIクラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** プレイヤーの体力UI */
class PlayerHp :public ObjectBase {
public:
   /**
    * \brief    コンストラクタ
    * \param hp プレイヤーの体力
    */
   PlayerHp(int hp);
   /**
    * \brief デストラクタ
    */
   ~PlayerHp();
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
   /**
    * \brief   オブジェクトの消去関数
    * \param g ゲームの参照
    */
   void Delete(Game& g)override;
};

