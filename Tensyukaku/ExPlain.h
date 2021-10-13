/*****************************************************************//**
 * \file   ExPlain.h
 * \brief  説明画面クラス（モードベースのサブクラス）、説明画面用コントローラークラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
/*---説明画面クラス---*/
class ExPlain :public ModeBase {
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
/*---説明画面用コントローラークラス---*/
class  EXController :public ModeBase {
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