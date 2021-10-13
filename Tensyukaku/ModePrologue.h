/*****************************************************************//**
 * \file   ModePrologue.h
 * \brief  プロローグクラス（モードベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
class  ModePrologue :public ModeBase {
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
   int _graph_no;
};

namespace ProInfo {
   /*----------各フェードフレーム関係----------*/
   constexpr auto BG1_FADEIN_FRAME = 120;
   constexpr auto BG1_FADEIN_SPEED = 2;
   constexpr auto TEXT1_FADEIN_FRAME = 60;
   constexpr auto TEXT_FADE_SPEED = 4;
   constexpr auto TEXT1_FADEOUT_BEGINFRAME= 550 + TEXT1_FADEIN_FRAME;
   constexpr auto TEXT1_FADEOUT_ENDFRAME  = 60 + TEXT1_FADEOUT_BEGINFRAME;
   constexpr auto TEXT2_FADEIN_BEGINFRAME = 60 + TEXT1_FADEOUT_ENDFRAME;
   constexpr auto TEXT2_FADEIN_ENDFRAME   = 60 + TEXT2_FADEIN_BEGINFRAME;
   constexpr auto TEXT2_FADEOUT_BEGINFRAME= 480+ TEXT2_FADEIN_ENDFRAME;
   constexpr auto TEXT2_FADEOUT_ENDFRAME  = 60 + TEXT2_FADEOUT_BEGINFRAME;
   constexpr auto TEXT3_FADEIN_BEGINFRAME = 60 + TEXT2_FADEOUT_ENDFRAME;
   constexpr auto TEXT3_FADEIN_ENDFRAME   = 60 + TEXT3_FADEIN_BEGINFRAME;
   constexpr auto TEXT3_FADEOUT_BEGINFRAME= 350 + TEXT3_FADEIN_ENDFRAME;
   constexpr auto TEXT3_FADEOUT_ENDFRAME  = 60 + TEXT3_FADEOUT_BEGINFRAME;
   constexpr auto TEXT4_FADEIN_BEGINFRAME = 60 + TEXT3_FADEOUT_ENDFRAME;
   constexpr auto TEXT4_FADEIN_ENDFRAME   = 60 + TEXT4_FADEIN_BEGINFRAME;
   constexpr auto TEXT4_FADEOUT_BEGINFRAME= 650 + TEXT4_FADEIN_ENDFRAME;
   constexpr auto TEXT4_FADEOUT_ENDFRAME  = 60 + TEXT4_FADEOUT_BEGINFRAME;
   constexpr auto BG1_FADEOUT_BEGINFRAME  = 0 + TEXT4_FADEOUT_ENDFRAME + BG1_FADEIN_FRAME;
   constexpr auto BG1_FADEOUT_ENDFRAME    = 60 + BG1_FADEOUT_BEGINFRAME;
   constexpr auto BG1_FADEOUT_SPEED = 4;
   constexpr auto BG2_FADEIN_BEGINFRAME   = 60 + BG1_FADEOUT_ENDFRAME;
   constexpr auto BG2_FADEIN_ENDFRAME     = 60 + BG2_FADEIN_BEGINFRAME;
   constexpr auto BG2_FADEIN_SPEED = 4;
   constexpr auto TEXT5_FADEIN_BEGINFRAME = 60 + BG2_FADEIN_ENDFRAME- BG1_FADEIN_FRAME;
   constexpr auto TEXT5_FADEIN_ENDFRAME   = 60 + TEXT5_FADEIN_BEGINFRAME;
   constexpr auto TEXT5_FADEOUT_BEGINFRAME= 550 + TEXT5_FADEIN_ENDFRAME;
   constexpr auto TEXT5_FADEOUT_ENDFRAME  = 60 + TEXT5_FADEOUT_BEGINFRAME;
   constexpr auto PROLOGUE_FADEOUT_FRAME  = 120 + TEXT5_FADEOUT_ENDFRAME;
   /*-----------背景移動フレーム関係----------*/
   constexpr auto BG_XMOVE_FRAME = 700+BG1_FADEIN_FRAME;
   constexpr auto BG_YMOVE_FRAME = 1660+ BG1_FADEIN_FRAME;
   constexpr auto BG_XMOVE_LIMIT = 3840;
   constexpr auto BG_YMOVE_LIMIT = 2160;
   constexpr auto BG_XMOVE_SPEED = 2;
   constexpr auto BG_YMOVE_SPEED = 1;
   /*---------背景&テキストの画像描画関係----------*/
   constexpr auto BG_GRAPH_WIDTH = 3840;      //1枚当たりの画像サイズ（横）
   constexpr auto BG_GRAPH_HEIGHT = 2160;     //1枚当たりの画像サイズ（縦）
   constexpr auto BG_GRAPHNAME = "res/Mode/PrologueAll.png";   //画像ファイル名
   constexpr auto BG_ANIMEMAX = 2;            //全ての画像枚数
   constexpr auto BG_WIDTHCOUNT = 2;          //横の画像枚数
   constexpr auto BG_HEIGHTCOUNT = 1;         //縦の画像枚数

   constexpr auto TEXT_GRAPH_WIDTH = 420;      //1枚当たりの画像サイズ（横）
   constexpr auto TEXT_GRAPH_HEIGHT = 910;     //1枚当たりの画像サイズ（縦）
   constexpr auto TEXT_GRAPHNAME = "res/Mode/AllPText.png";   //画像ファイル名
   constexpr auto TEXT_ANIMEMAX = 5;           //全ての画像枚数
   constexpr auto TEXT_WIDTHCOUNT = 5;         //横の画像枚数
   constexpr auto TEXT_HEIGHTCOUNT = 1;        //縦の画像枚数
   /*---------スキップテキスト関係---------*/
   constexpr auto SKIP_FADEOUT_FRAME = 550;    //フェードアウトするフレーム
   constexpr auto SKIP_FADESPEED = 5;          //フェードスピード
}