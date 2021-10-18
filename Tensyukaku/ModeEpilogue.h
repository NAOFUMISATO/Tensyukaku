/*****************************************************************//**
 * \file   ModeEpilogue.h
 * \brief  エピローグクラス（モードベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
/** エピローグ */
class  ModeEpilogue :public ModeBase {
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
/** エピローグクラス用定数 */
namespace EpiInfo {
   constexpr auto BG_FADEIN_FRAME = 120;       //!< 背景フェードインフレーム
   constexpr auto BG_FADEIN_SPEED = 2;         //!< 背景フェードイン速度
   constexpr auto TEXT1_FADEIN_FRAME = 120;    //!< テキスト1のフェードインフレーム
   constexpr auto TEXT_FADE_SPEED = 3;         //!< テキストのフェード速度
   constexpr auto TEXT_FIRST_XPOSITION = 500;  //!< テキストの初期Ｘ座標
   constexpr auto TEXT_MOVE_SPEED = 2;         //!< テキストの移動速度
   constexpr auto TEXT1_FADEOUT_BEGINFRAME= 180 + TEXT1_FADEIN_FRAME;                      //!< テキスト１のフェードアウト開始フレーム
   constexpr auto TEXT1_FADEOUT_ENDFRAME  = 120 + TEXT1_FADEOUT_BEGINFRAME;                //!< テキスト１のフェードアウト終了フレーム
   constexpr auto TEXT2_FADEIN_BEGINFRAME = 60 + TEXT1_FADEOUT_ENDFRAME;                   //!< テキスト２のフェードイン開始フレーム
   constexpr auto TEXT2_FADEIN_ENDFRAME   = 120 + TEXT2_FADEIN_BEGINFRAME;                 //!< テキスト２のフェードイン終了フレーム
   constexpr auto TEXT2_FADEOUT_BEGINFRAME= 450 + TEXT2_FADEIN_ENDFRAME;                   //!< テキスト２のフェードアウト開始フレーム
   constexpr auto TEXT2_FADEOUT_ENDFRAME = 120 + TEXT2_FADEOUT_BEGINFRAME;                 //!< テキスト２のフェードアウト終了フレーム
   constexpr auto TEXT3_FADEIN_BEGINFRAME = 60 + TEXT2_FADEOUT_ENDFRAME;                   //!< テキスト３のフェードイン開始フレーム
   constexpr auto TEXT3_FADEIN_ENDFRAME = 120 + TEXT3_FADEIN_BEGINFRAME;                   //!< テキスト３のフェードイン終了フレーム
   constexpr auto TEXT3_FADEOUT_BEGINFRAME= 240 + TEXT3_FADEIN_ENDFRAME;                   //!< テキスト３のフェードアウト開始フレーム
   constexpr auto TEXT3_FADEOUT_ENDFRAME = 120 + TEXT3_FADEOUT_BEGINFRAME;                 //!< テキスト３のフェードアウト終了フレーム
   constexpr auto TEXT4_FADEIN_BEGINFRAME = 60 + TEXT3_FADEOUT_ENDFRAME;                   //!< テキスト４のフェードイン開始フレーム
   constexpr auto TEXT4_FADEIN_ENDFRAME = 120 + TEXT4_FADEIN_BEGINFRAME;                   //!< テキスト４のフェードイン終了フレーム
   constexpr auto TEXT4_FADEOUT_BEGINFRAME= 330 + TEXT4_FADEIN_ENDFRAME;                   //!< テキスト４のフェードアウト開始フレーム
   constexpr auto TEXT4_FADEOUT_ENDFRAME = 120 + TEXT4_FADEOUT_BEGINFRAME;                 //!< テキスト４のフェードアウト終了フレーム
   constexpr auto BG_FADEOUT_BEGINFRAME   = 60 + TEXT4_FADEOUT_ENDFRAME + BG_FADEIN_FRAME; //!< 背景のフェードアウト開始フレーム
   constexpr auto BG_FADEOUT_ENDFRAME     = 60 + BG_FADEOUT_BEGINFRAME;                    //!< 背景のフェードアウト終了フレーム
   constexpr auto BG_FADEOUT_SPEED = 4;                                                    //!< 背景のフェードアウト速度

   /*---------テキストの画像描画関係----------*/
   constexpr auto TEXT_GRAPH_WIDTH = 260;   //!< 1枚当たりの画像サイズ（横）
   constexpr auto TEXT_GRAPH_HEIGHT = 529;  //!< 1枚当たりの画像サイズ（縦）
   constexpr auto TEXT_GRAPHNAME = "res/Mode/AllEText.png"; //!< 画像ファイル名
   constexpr auto TEXT_ANIMEMAX = 4;        //!< 全ての画像枚数
   constexpr auto TEXT_WIDTHCOUNT = 4;      //!< 横の画像枚数
   constexpr auto TEXT_HEIGHTCOUNT = 1;     //!< 縦の画像枚数
}