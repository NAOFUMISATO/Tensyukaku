/*****************************************************************//**
 * \file   ModeTitle.h
 * \brief  モードタイトルクラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include   "ModeBase.h"
/** タイトル */
class ModeTitle : public ModeBase
{
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
    * \brief タイトルの種別をタイトル背景に設定する関数
    */
   void SetTitlebg() { _type = TITLETYPE::TITLEBG; }
    /**
     * \brief                オブジェクト処理のストップ判定の設定関数
     * \param stopobjprocess オブジェクト処理のストップ判定
     */
   void SetStopObjProcess(bool stopobjprocess) { _stop_obj_process = stopobjprocess; }

private:
   /** タイトルの種別列挙 */
   enum class TITLETYPE { 
      AMGLOGO,       //!< AMGロゴ
      TEAMLOGO,      //!< チームロゴ
      TITLEBG        //!< タイトル背景
   };
   TITLETYPE _type;            //!< タイトルの種別変数
   bool   _stop_obj_process;   //!< オブジェクト処理のストップ判定フラグ
};
/** モードタイトル用定数 */
namespace MTInfo{
   constexpr auto AMG_FADEINFRAME = 60;         //!< AMGロゴフェードインフレーム
   constexpr auto AMG_FADESPEED = 5;            //!< AMGロゴフェード速度
   constexpr auto AMG_FADEOUTBEGINFRAME = 90;   //!< AMGロゴフェードアウト開始フレーム
   constexpr auto AMG_FADEOUTENDFRAME = 150;    //!< AMGロゴフェードアウト終了フレーム
   constexpr auto TEAM_FADEINFRAME = 120;       //!< AMGロゴフェードインフレーム
   constexpr auto TEAM_FADESPEED = 3;           //!< AMGロゴフェード速度
   constexpr auto TEAM_FADEOUTBEGINFRAME = 180; //!< AMGロゴフェードアウト開始フレーム
   constexpr auto TEAM_FADEOUTENDFRAME = 300;   //!< AMGロゴフェードアウト終了フレーム
   constexpr auto TITLE_FADEINBEGINFRAME = 120; //!< タイトル背景フェードイン開始フレーム
   constexpr auto TITLE_FADEINENDFRAME = 240;   //!< タイトル背景フェードイン終了フレーム
   constexpr auto TITLE_FADESPEED = 3;          //!< タイトル背景フェード速度
   constexpr auto GAMESTART_APPEARFRAME = 300;  //!< ゲームスタートセレクト出現フレーム
   constexpr auto EXPLAIN_APPEARFRAME = 315;    //!< 説明画面セレクト出現フレーム
   constexpr auto CREDIT_APPEARFRAME = 330;     //!< クレジット画面セレクト出現フレーム
   constexpr auto GAMEEND_APPEARFRAME = 345;    //!< ゲーム終了セレクト出現フレーム
}
