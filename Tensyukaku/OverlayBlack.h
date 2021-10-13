/*****************************************************************//**
 * \file   OverlayBlack.h
 * \brief  フェードアウトフェードインのための黒背景クラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"

class OverlayBlack : public ModeBase
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
   //各フェード関係を設定する関数
   void SetFade(int fadeoutframe,int fadeinbeginframe,int fadeinendframe, int fadespeed);
   //透明度の値を返す関数
   int GetPal() { return _pal; }
private:
   int _fadeout_frame;     //フェードアウトが終わるフレームを設定する変数
   int _fadein_beginframe; //フェードイン開始フレームを設定する変数
   int _fadein_endframe;   //フェードイン終了フレームを設定する変数
   int _fade_speed;       //フェードスピードを設定する変数
};