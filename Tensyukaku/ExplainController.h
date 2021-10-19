/*****************************************************************//**
 * \file   ExplainController.h
 * \brief  説明画面用コントローラークラス（モードベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
/** 説明画面用コントローラー */
class  ExplainController :public ModeBase {
   typedef ModeBase base;
public:
   /**
   * \brief   初期化関数
   * \param g ゲームクラスの参照
   */
   virtual bool Initialize(Game& g);
   /**
    * \brief   終了関数
    * \param g ゲームクラスの参照
    */
   virtual bool Terminate(Game& g);
   /**
    * \brief   更新関数
    * \param g ゲームクラスの参照
    */
   virtual bool Process(Game& g);
   /**
    * \brief   描画関数
    * \param g ゲームクラスの参照
    */
   virtual bool Draw(Game& g);
};