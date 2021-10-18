/*****************************************************************//**
 * \file   PrologueText.h
 * \brief  プロローグテキストクラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
 /** プロローグテキスト */
class  PrologueText :public ModeBase {
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

private:
   /**
    * \brief SE読み込み関数
    */
   void LoadSE();
   /**
    * \brief SE音量初期化関数
    */
   void VolumeInit();
   /**
    * \brief SE音量変更関数
    */
   void VolumeChange();

   int _graph_no;   //!< シート番号変数
   bool _skip_flag; //!< スキップボタンを押下したかのフラグ
};
