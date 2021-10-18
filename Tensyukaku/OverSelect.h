/*****************************************************************//**
 * \file   OverSelect.h
 * \brief  ゲームオーバーセレクトクラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
/** ゲームオーバーセレクト */
class OverSelect :public ModeBase {
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

private:
   /** 選択状態の列挙 */
   enum class SELECTSTATE {
      NOSELECT,         //!< 何も選択していない
      RETRYSELECT,      //!< リトライ選択
      GOTITLESELECT     //!< タイトル選択
   };

   SELECTSTATE _state;  //!< 選択状態
   int _graph_no;       //!< シート番号変数
   bool _input_flag;    //!< 入力を受付判定フラグ
};