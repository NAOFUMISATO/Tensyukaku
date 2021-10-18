/*****************************************************************//**
 * \file   Shield.h
 * \brief  盾のクラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** 盾 */
class Shield :public ObjectBase {
public:
   /**
    * \brief コンストラクタ
    */
   Shield();
   /**
    * \brief デストラクタ
    */
   ~Shield();
   /**
    * \brief                     純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::SHIELD オブジェクトの種別（盾）を返す
    */
   virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::SHIELD; }
   /**
    * \brief 初期化関数
    */
   void   Init()override;
   /**
    * \brief   更新関数
    * \param g ゲームの参照
    */
   void   Process(Game& g)override;
   /**
    * \brief   描画関数
    * \param g ゲームの参照
    */
   void   Draw(Game& g)override;
   /**
    * \brief            画像ハンドルを返す
    * \return _grhandle 画像ハンドル
    */
   int      GetHandle() { return _grhandle; }
   /**
    * \brief              描画角度を返す関数
    * \return _drg.second 描画角度
    */
   double   GetAngle() { return _drg.second; }
   /**
    * \brief       描画角度を設定する関数
    * \param angle 描画角度
    */
   void   SetAngle(double angle) { _drg.second = angle; }
};
