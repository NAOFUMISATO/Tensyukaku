/*****************************************************************//**
 * \file   ExplainSelect.h
 * \brief  説明画面セレクトクラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** 説明画面セレクト */
class ExplainSelect :public ObjectBase {
public:
   /**
    * \brief コンストラクタ
    */
   ExplainSelect();
   /**
    * \brief デストラクタ
    */
   ~ExplainSelect();
   /**
    * \brief                        //純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::EXPLAIN   //オブジェクトの種別（説明画面セレクト）を返す
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::EXPLAIN; }
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