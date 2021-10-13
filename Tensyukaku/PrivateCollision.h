/*****************************************************************//**
 * \file   PrivateCollision.h
 * \brief  受け側で判定を取らない当たり判定クラス（オブジェクトベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
#include <tuple>

class PrivateCollision : public ObjectBase {
public:
   //コンストラクタ : 引数（X座標,Y座標,当たり判定横幅,当たり判定縦幅）
   PrivateCollision(int x, int y, int hit_w, int hit_h);
   //デストラクタ
   ~PrivateCollision();
   //純粋仮想関数のオーバーライド
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::PRIVATECOLLISION; }
   //初期化
   void   Init()override;
   //デバッグ用当たり判定色指定関数
   void   SetColor(std::tuple<int, int, int> color) { _debug_color = color; }
};