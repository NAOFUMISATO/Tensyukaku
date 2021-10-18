/*****************************************************************//**
 * \file   BossBlood.h
 * \brief  ボスの血しぶきエフェクトクラス(エフェクトベースのサブクラス)
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "EfectBase.h"
/** ボスの血しぶきエフェクト */
class BossBlood :public EfectBase {
public:
   /**
    * \brief           コンストラクタ
    * \param x         X座標
    * \param y         Y座標
    * \param bloodtype 血しぶきの種別
    */
   BossBlood(int x, int y, int bloodtype);
   /**
    * \brief デストラクタ
    */
   ~BossBlood();
   /**
   * \brief                        純粋仮想関数のオーバーライド
   * \return EFECTTYPE::BOSSBLOOD  エフェクトの種別（ボスの血しぶきエフェクト）を返す
   */
   virtual EFECTTYPE GetEfeType() { return EFECTTYPE::BOSSBLOOD; }
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

private:
   int  _blood_type;    //!< 血しぶきの種別変数
};