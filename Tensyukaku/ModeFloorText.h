/*****************************************************************//**
 * \file   ModeFloorText.h
 * \brief  階層表示クラス（モードベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
/** 階層表示 */
class  ModeFloorText :public ModeBase {
   typedef ModeBase base;
public:
   /**
     * \brief   初期化関数
     * \param g ゲームクラスの参照
     */
   virtual bool Initialize(Game& g);
   /**
     * \brief   初期化関数
     * \param g ゲームクラスの参照
     */
   virtual bool Terminate(Game& g);
   /**
     * \brief   初期化関数
     * \param g ゲームクラスの参照
     */
   virtual bool Process(Game& g);
   /**
     * \brief   初期化関数
     * \param g ゲームクラスの参照
     */
   virtual bool Draw(Game& g);
   /**
    * \brief          テキストの種類を設定する関数
    * \param texttype テキストの種類
    */
   void SetType(std::string texttype) { _text_type = texttype; }
private:
   /**
    * \brief 画像読み込み関数
    */
   void LoadPicture();

   std::string _text_type; //!< テキストの種類
   int _fadein_frame;      //!< フェードインするフレームを指定する変数
   int _fadeout_frame;     //!< フェードアウトするフレームを指定する変数
   int _fade_speed;        //!< フェードのスピードを指定する変数
};
/** 階層表示クラス用定数 */
namespace MFTInfo {
   constexpr auto GRAPH_WIDTH = 1120;  //1枚当たりの画像サイズ（横）
   constexpr auto GRAPH_HEIGHT = 265;  //1枚当たりの画像サイズ（縦)
   constexpr auto FADEIN_FRAME = 60;   //フェードインフレーム
   constexpr auto FADEOUT_FRAME = 180; // フェードアウトフレーム
   constexpr auto FADE_SPEED = 4;      // フェードアウトフレーム

}