/*****************************************************************//**
 * \file   OverlayBlack.h
 * \brief  フェードアウトフェードインのための黒背景クラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
/** フェードアウトフェードインのための黒背景 */
class OverlayBlack : public ModeBase
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
    * \brief                  各フェード関係を設定する関数
    * \param fadeoutframe     フェードアウト終了フレーム
    * \param fadeinbeginframe フェードイン開始フレーム
    * \param fadeinendframe   フェードイン終了フレーム
    * \param fadespeed        フェード速度
    */
   void SetFade(int fadeoutframe,int fadeinbeginframe,int fadeinendframe, int fadespeed);
   /**
    * \brief       透明度の値を返す関数
    * \return _pal 透明度の値
    */
   int GetPal() { return _pal; }

private:
   int _fadeout_frame;     //!< フェードアウトが終わるフレームを設定する変数
   int _fadein_beginframe; //!< フェードイン開始フレームを設定する変数
   int _fadein_endframe;   //!< フェードイン終了フレームを設定する変数
   int _fade_speed;        //!< フェードスピードを設定する変数
};