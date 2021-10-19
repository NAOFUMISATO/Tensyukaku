/*****************************************************************//**
 * \file   RestPoint.h
 * \brief  回復ポイント掛け軸クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** 回復ポイント掛け軸 */
class RestPoint :public ObjectBase {
public:
   /**
    * \brief   コンストラクタ
    * \param x X座標
    * \param y Y座標
    */
   RestPoint(int x,int y);
   /**
    * \brief デストラクタ
    */
   ~RestPoint();
   /**
    * \brief                        純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::RESTPOINT オブジェクトの種別（回復ポイント掛け軸）を返す
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::RESTPOINT; }
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

private:
   int _graph_no;    //!< シート番号変数
   bool _hit_flag;   //!< プレイヤーが当たったかのフラグ
};