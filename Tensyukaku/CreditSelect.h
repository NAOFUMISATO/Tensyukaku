/*****************************************************************//**
 * \file   CreditSelect.h
 * \brief  クレジットセレクトクラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** クレジットセレクト */
class CreditSelect :public ObjectBase {
public:
   /**
    * \brief コンストラクタ
    */
   CreditSelect();
   /**
    * \brief デストラクタ
    */
   ~CreditSelect();
   /**
    * \brief                       //純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::CREDIT   //オブジェクトの種別（クレジットセレクト）を返す
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::CREDIT; }
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