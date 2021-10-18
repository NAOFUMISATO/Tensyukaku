/*****************************************************************//**
 * \file   ModeTutorial.h
 * \brief  インゲームでのチュートリアルクラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
/** チュートリアル */
class  ModeTutorial :public ModeBase {
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
   /**
    * \brief              チュートリアルの種別を設定する関数
    * \param tutorialtype チュートリアルの種別
    */
   void SetType(std::string tutorialtype) { _tutorial_type = tutorialtype; }
private:
   /**
    * \brief 画像読み込み関数
    */
   void LoadPicture();
   std::string _tutorial_type;   //!< チュートリアルの種別変数
};
/** モードチュートリアルクラス用定数 */
namespace TuInfo {
   constexpr auto GRAPH_WIDTH = 880;    //!< 画像サイズ横幅
   constexpr auto GRAPH_HEIGHT = 470;   //!< 画像サイズ縦幅
}