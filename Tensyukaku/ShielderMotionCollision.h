/*****************************************************************//**
 * \file   ShielderMotionCollision.h
 * \brief  盾兵の攻撃当たり判定クラス（オブジェクトベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"

class ShielderAttackCollision : public ObjectBase {
public:
   //コンストラクタ : 引数（X座標,Y座標）
   ShielderAttackCollision(int x, int y);
   //デストラクタ
   ~ShielderAttackCollision();
   //純粋仮想関数のオーバーライド
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::SHIELDERATTACK; }
   //初期化
   void Init()override;
   //更新
   void Process(Game& g)override;
   //描画
   void Draw(Game& g)override;
   //オブジェクトの消去関数
   void Delete(Game& g)override;
};
