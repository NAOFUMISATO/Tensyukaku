/*****************************************************************//**
 * \file   EpilogueText.h
 * \brief  エピローグテキストクラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"

class  EpilogueText :public ModeBase {
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
   //SE読み込み関数
   void LoadSE();
   //SE音量初期化関数
   void VolumeInit();
   //SE音量変更関数
   void VolumeChange();

   int _graph_no;   //シート番号指定変数
};
