/*****************************************************************//**
 * \file   PoisonFall.h
 * \brief  毒液落下クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
class PoisonFall :public ObjectBase {
public:
   /**
    * \brief   コンストラクタ
    * \param x X座標
    * \param y Y座標
    */
   PoisonFall(int x, int y);
   /**
    * \brief デストラクタ
    */
   ~PoisonFall();
   /**
    * \brief                     デストラクタ
    * \return OBJECTTYPE::POISON オブジェクトの種別（毒液）を返す
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::POISON; }
   /**
    * \brief 初期化関数
    */
   void Init()override;
   /**
    * \brief   更新関数
    * \param g ゲームの参照
    */
   void Process(Game& g)override;
   /**
    * \brief   描画関数
    * \param g ゲームの参照
    */
   void Draw(Game& g)override;
   /**
    * \brief   オブジェクトの消去関数
    * \param g ゲームの参照
    */
   void Delete(Game& g)override;

private:
   /** 毒液の状態列挙 */
   enum class POISONSTATE { 
      FALL,    //!< 落下中
      LAND     //!< 着地
   };

   POISONSTATE _State;  //!< 毒液の状態変数
};