/*****************************************************************//**
 * \file   MiddleBlood.h
 * \brief  武士型の血しぶきエフェクトクラス（エフェクトベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "EfectBase.h"
/** 武士型の血しぶきエフェクト */
class MiddleBlood :public EfectBase {
public:
   /**
    * \brief           コンストラクタ
    * \param x         X座標
    * \param y         Y座標
    * \param bloodtype 血しぶきの種別
    */
   MiddleBlood(int x, int y,  bool flip, int bloodtype);
   /**
   * \brief デストラクタ
   */
   ~MiddleBlood();
   /**
   * \brief                         純粋仮想関数のオーバーライド
   * \return EFECTTYPE::MIDDLEBLOOD エフェクトの種別（武士型の血しぶきエフェクト）を返す
   */
   virtual EFECTTYPE GetEfeType() { return EFECTTYPE::MIDDLEBLOOD; }
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