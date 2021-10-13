/*****************************************************************//**
 * \file   ModeTitle.h
 * \brief  モードタイトルクラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include   "ModeBase.h"

class ModeTitle : public ModeBase
{
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
   //タイトルの種別をタイトル背景に設定する関数
   void SetTitlebg() { _type = TITLETYPE::TITLEBG; }
   //オブジェクト処理のストップ判定の設定関数
   void SetStopObjProcess(bool stopobjprocess) { _stop_obj_process = stopobjprocess; }
   
private:
   //タイトルの種別列挙
   enum class TITLETYPE { AMGLOGO, TEAMLOGO, TITLEBG };
   TITLETYPE _type;            //タイトルの種別
   bool   _stop_obj_process;   //オブジェクト処理のストップ判定フラグ
};

namespace MTInfo{
   /*----------AMGロゴフェード関係---------*/
   constexpr auto AMG_FADEINFRAME = 60;
   constexpr auto AMG_FADESPEED = 5;
   constexpr auto AMG_FADEOUTBEGINFRAME = 90;
   constexpr auto AMG_FADEOUTENDFRAME = 150;
   /*----------TEAMロゴフェード関係---------*/
   constexpr auto TEAM_FADEINFRAME = 120;
   constexpr auto TEAM_FADESPEED = 3;
   constexpr auto TEAM_FADEOUTBEGINFRAME = 180;
   constexpr auto TEAM_FADEOUTENDFRAME = 300;
   /*----------タイトル背景フェード関係---------*/
   constexpr auto TITLE_FADEINBEGINFRAME = 120;
   constexpr auto TITLE_FADEINENDFRAME = 240;
   constexpr auto TITLE_FADESPEED = 3;
   constexpr auto GAMESTART_APPEARFRAME = 300;
   constexpr auto EXPLAIN_APPEARFRAME = 315;
   constexpr auto GAMEEND_APPEARFRAME = 345;
   constexpr auto CREDIT_APPEARFRAME = 330;
}
