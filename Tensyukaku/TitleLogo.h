/*****************************************************************//**
 * \file   TitleLogo.h
 * \brief  タイトルロゴクラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** タイトルロゴ */
class TitleLogo :public ObjectBase {
public:
   /**
    * \brief コンストラクタ
    */
   TitleLogo();
   /**
    * \brief デストラクタ
    */
   ~TitleLogo();
   /**
    * \brief                         //純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::TITLELOGO  //オブジェクトの種別（タイトルロゴ）を返す
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::TITLELOGO; }
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
