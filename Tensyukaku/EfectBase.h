/*****************************************************************//**
 * \file   EfectBase.h
 * \brief  各エフェクトのベースクラス（オブジェクトベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** 各エフェクトのベース */
class EfectBase :public ObjectBase {
public:
   /**
    * \brief コンストラクタ
    */
   EfectBase();
   /**
    * \brief デストラクタ
    */
   ~EfectBase();
   /**
   * \brief                    純粋仮想関数のオーバーライド
   * \return OBJECTTYPE::EFECT オブジェクトの種別（エフェクト）を返す
   */
   virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::EFECT; }
   /** 各エフェクトの種別列挙 */
   enum class EFECTTYPE {
   MIDDLEBLOOD,  //!< 武士型の血しぶき
   LOWBLOOD,     //!< 忍者型の血しぶき
   BOSSBLOOD     //!< ボスの血しぶき
   };
   /**
    * \brief    純粋仮想関数化純粋仮想関数化
    * \return 0 派生先で定義
    */
   virtual  EFECTTYPE GetEfeType() = 0;
   /**
   * \brief 初期化関数
   */
   virtual void Init();
   /**
   * \brief   更新関数
   * \param g ゲームの参照
   */
   virtual void Process(Game& g);
   /**
   * \brief   描画関数
   * \param g ゲームの参照
   */
   virtual void Draw(Game& g);
   /**
   * \brief   オブジェクトの消去関数
   * \param g ゲームの参照
   */
   virtual void Delete(Game& g) {};
};