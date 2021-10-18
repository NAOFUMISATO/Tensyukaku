/*****************************************************************//**
 * \file   ModeCredit.h
 * \brief  クレジットクラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
/** クレジット */
class ModeCredit :public ModeBase {
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
   bool _leftmove_flag;  //!< クレジット画面が左へ移動する入力を受け付けるフラグ
   bool _rightmove_flag; //!< クレジット画面が右へ移動する入力を受け付けるフラグ
   bool _start_flag;     //!< クレジットの開始フラグ
   bool _end_flag;       //!< クレジットの終了フラグ
};

/** クレジット、左スティックボタンガイド、赤ボタンガイドクラス用定数 */
namespace CrInfo {
   constexpr auto FADE_FRAME = 60;   //!< フェードフレーム
   constexpr auto  FADE_SPEED = 5;   //!< フェードスピード
}