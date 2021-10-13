/*****************************************************************//**
 * \file   ModeCredit.h
 * \brief  クレジットクラス（モードベースのサブクラス）、左スティックガイドボタンクラス（モードベースのサブクラス）、赤ボタンガイドクラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
/*---クレジットクラス---*/
class ModeCredit :public ModeBase {
   typedef ModeBase base;
public:
   //初期化
   virtual bool Initialize(Game& g);
   //終了
   virtual bool Terminate(Game& g);
   //更新
   virtual bool Process(Game& g);
   //描画
   virtual bool Draw(Game& g);
private:
   bool _leftmove_flag;  //クレジット画面が左へ移動する入力を受け付けるフラグ
   bool _rightmove_flag; //クレジット画面が右へ移動する入力を受け付けるフラグ
   bool _start_flag;     //クレジットの開始フラグ
   bool _end_flag;       //クレジットの終了フラグ
};
/*---左スティックガイドボタンクラス---*/
class Guide:public ModeBase {
   typedef ModeBase base;
public:
   //初期化
   virtual bool Initialize(Game& g);
   //終了
   virtual bool Terminate(Game& g);
   //更新
   virtual bool Process(Game& g);
   //描画
   virtual bool Draw(Game& g);
};
/*---赤ボタンガイドクラス---*/
class RedReturn :public ModeBase {
   typedef ModeBase base;
public:
   //初期化
   virtual bool Initialize(Game& g);
   //終了
   virtual bool Terminate(Game& g);
   //更新
   virtual bool Process(Game& g);
   //描画
   virtual bool Draw(Game& g);
};
namespace CrInfo {
   constexpr auto FADE_FRAME = 60;   //フェードフレーム
   constexpr auto  FADE_SPEED = 5;   //フェードスピード
}