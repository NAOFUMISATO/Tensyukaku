/*****************************************************************//**
 * \file   PlayerMotionCollision.h
 * \brief  中段攻撃、下段攻撃、蹴り、居合、特殊攻撃当たり判定クラス（オブジェクトベースのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"

/*---中段攻撃当たり判定クラス---*/
class MiddleAttackCollision : public ObjectBase {
public:
   //コンストラクタ : 引数（X座標,Y座標）
   MiddleAttackCollision(int x, int y);
   //デストラクタ
   ~MiddleAttackCollision();
   //純粋仮想関数のオーバーライド
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::MIDDLEATTACK; }
   //初期化
   void Init()override;
   //更新
   void Process(Game& g)override;
   //描画
   void Draw(Game& g)override;
   //オブジェクトの消去関数
   void Delete(Game& g)override;
};

/*---下段攻撃当たり判定クラス---*/
class LowAttackCollision : public ObjectBase {
public:
   //コンストラクタ : 引数（X座標,Y座標）
   LowAttackCollision(int x, int y);
   //デストラクタ
   ~LowAttackCollision();
   //純粋仮想関数のオーバーライド
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::LOWATTACK; }
   //初期化
   void Init()override;
   //更新
   void Process(Game& g)override;
   //描画
   void Draw(Game& g)override;
   //オブジェクトの消去関数
   void Delete(Game& g)override;
};

/*---蹴り当たり判定クラス---*/
class KickCollision : public ObjectBase {
public:
   //コンストラクタ : 引数（X座標,Y座標）
   KickCollision(int x, int y);
   //デストラクタ
   ~KickCollision();
   //純粋仮想関数のオーバーライド
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::KICK; }
   //初期化
   void Init()override;
   //更新
   void Process(Game& g)override;
   //描画
   void Draw(Game& g)override;
   //オブジェクトの消去関数
   void Delete(Game& g)override;
};

/*---居合当たり判定クラス---*/
class IaiCollision : public ObjectBase {
public:
   //コンストラクタ : 引数（X座標,Y座標）
   IaiCollision(int x, int y);
   //デストラクタ
   ~IaiCollision();
   //純粋仮想関数のオーバーライド
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::IAI; }
   //初期化
   void Init()override;
   //更新
   void Process(Game& g)override;
   //描画
   void Draw(Game& g)override;
   //オブジェクトの消去関数
   void Delete(Game& g)override;
};

/*---特殊攻撃当たり判定クラス---*/
class SpecialCollision : public ObjectBase {
public:
   //コンストラクタ : 引数（X座標,Y座標）
   SpecialCollision(int x, int y);
   //デストラクタ
   ~SpecialCollision();
   //純粋仮想関数のオーバーライド
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::SPECIAL; }
   //初期化
   void Init()override;
   //更新
   void Process(Game& g)override;
   //描画
   void Draw(Game& g)override;
   //オブジェクトの消去関数
   void Delete(Game& g)override;
};
