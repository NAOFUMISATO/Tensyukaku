/*****************************************************************//**
 * \file   OverSelect.h
 * \brief  ゲームオーバーセレクトクラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"

class OverSelect :public ModeBase {
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
   //選択状態の列挙
   enum class SELECTSTATE {
      NOSELECT, RETRYSELECT, GOTITLESELECT
   };
   SELECTSTATE _state; //選択状態
   int _graph_no;      //シート番号変数
   bool _input_flag;   //入力を受け付けるフラグ
};