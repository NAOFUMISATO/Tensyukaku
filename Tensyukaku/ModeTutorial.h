/*****************************************************************//**
 * \file   ModeTutorial.h
 * \brief  インゲームでのチュートリアルクラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"

class  ModeTutorial :public ModeBase {
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
   //チュートリアルの種別を設定する関数
   void SetType(std::string tutorialtype) { _tutorial_type = tutorialtype; }
private:
   //画像読み込み関数
   void LoadPicture();
   std::string   _tutorial_type;   //チュートリアルの種別変数
};

namespace TuInfo {
   constexpr auto GRAPH_WIDTH = 880;    //画像サイズ横幅
   constexpr auto GRAPH_HEIGHT = 470;   //画像サイズ縦幅
}