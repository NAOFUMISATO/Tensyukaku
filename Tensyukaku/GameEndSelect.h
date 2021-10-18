/*****************************************************************//**
 * \file   GameEndSelect.h
 * \brief  ゲーム終了セレクトクラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** ゲーム終了セレクト */
class GameEndSelect :public ObjectBase {
public:
   /**
    * \brief コンストラクタ
    */
   GameEndSelect();
   /**
    * \brief デストラクタ
    */
   ~GameEndSelect();
   /**
    * \brief                        //純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::GAMEEND   //オブジェクトの種別（ゲーム終了セレクト）を返す
    */
   virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::GAMEEND; }
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
