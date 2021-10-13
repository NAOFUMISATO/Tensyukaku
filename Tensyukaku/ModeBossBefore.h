/*****************************************************************//**
 * \file   ModeBossBefore.h
 * \brief  ボスステージ前の1枚絵クラス（モードベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"

class ModeBossBefore :public ModeBase {
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
};

namespace BBInfo {
   constexpr auto FOOT_FRAME = 120;      //SEを鳴らすフレーム
   constexpr auto VOICE_FRAME = 180;     //VOICEを鳴らすフレーム
   constexpr auto FADEOUT_FRAME = 540;   //フェードアウトするフレーム
}