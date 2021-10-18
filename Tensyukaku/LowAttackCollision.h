/*****************************************************************//**
 * \file   LowAttackCollision.h
 * \brief  下段攻撃当たり判定クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"

 /** 下段攻撃当たり判定クラス */
class LowAttackCollision : public ObjectBase {
public:
   /**
   * \brief   コンストラクタ
   * \param x X座標
   * \param y Y座標
   */
   LowAttackCollision(int x, int y);
   /**
    * \brief デストラクタ
    */
   ~LowAttackCollision();
   /**
   * \brief                        純粋仮想関数のオーバーライド
   * \return OBJECTTYPE::LOWATTACK オブジェクトの種別（下段攻撃当たり判定）を返す
   */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::LOWATTACK; }
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