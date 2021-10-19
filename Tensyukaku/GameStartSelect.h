/*****************************************************************//**
 * \file   GameStartSelect.h
 * \brief  ゲーム開始セレクトクラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** ゲーム開始セレクト */
class GameStartSelect :public ObjectBase {
public:
   /**
    * \brief コンストラクタ
    */
   GameStartSelect();
   /**
    * \brief デストラクタ
    */
   ~GameStartSelect();
   /**
    * \brief                       純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::GAMSTART オブジェクトの種別（ゲーム開始セレクト）を返す
    */
   virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::GAMESTART; }
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