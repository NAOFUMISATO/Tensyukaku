/*****************************************************************//**
 * \file   LowBlood.h
 * \brief  忍者型の血しぶきエフェクトクラス（エフェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "EfectBase.h"
 /** 忍者型の血しぶきエフェクト */
class LowBlood :public EfectBase {
public:
    /**
     * \brief           コンストラクタ
     * \param x         X座標
     * \param y         Y座標
     * \param bloodtype 血しぶきの種別
     */
   LowBlood(int x, int y, bool flip, int bloodtype);
   /**
    * \brief デストラクタ
    */
   ~LowBlood();
   /**
   * \brief                      純粋仮想関数のオーバーライド
   * \return EFECTTYPE::LOWBLOOD エフェクトの種別（忍者型の血しぶきエフェクト）を返す
   */
   virtual EFECTTYPE GetEfeType() { return EFECTTYPE::LOWBLOOD; }
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
   int  _blood_type;    //!< 血しぶきの種別変数
};