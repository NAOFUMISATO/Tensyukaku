/*****************************************************************//**
 * \file   ModeIngameText.h
 * \brief  インゲームでの階層表示クラス（モードベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"

class  ModeIngameText :public ModeBase {
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
   //テキストの種類を設定する関数
   void SetType(std::string texttype) { _text_type = texttype; }
private:
   //画像読み込み関数
   void LoadPicture();

   std::string _text_type; //テキストの種類を指定する変数
   int _fadein_frame;      //フェードインするフレームを指定する変数
   int _fadeout_frame;     //フェードアウトするフレームを指定する変数
   int _fade_speed;        //フェードのスピードを指定する変数
};

namespace ITInfo {
   constexpr auto GRAPH_WIDTH = 1120;  //1枚当たりの画像サイズ（横）
   constexpr auto GRAPH_HEIGHT = 265;  //1枚当たりの画像サイズ（縦)
   constexpr auto FADEIN_FRAME = 60;   //フェードインフレーム
   constexpr auto FADEOUT_FRAME = 180; // フェードアウトフレーム
   constexpr auto FADE_SPEED = 4;      // フェードアウトフレーム

}