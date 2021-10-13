/*****************************************************************//**
 * \file   ModePause.h
 * \brief  インゲームでのポーズ画面クラス（モードベースクラスのサブクラス）、ポーズ画面に表示するコントローラークラス（モードベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
 /*----------インゲームでのポーズ画面クラス-------------*/
class  ModePause :public ModeBase {
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
/*-----------ポーズ画面用コントローラークラス-------------*/
class PController :public ModeBase {
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