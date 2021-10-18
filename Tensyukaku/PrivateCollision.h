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
/** 受け側で判定を取らない当たり判定 */
class PrivateCollision : public ObjectBase {
public:
   /**
    * \bruef   コンストラクタ
    * \param x X座標
    * \param y Y座標
    * \param hit_w 当たり判定横幅
    * \param hit_h 当たり判定縦幅
    */
   PrivateCollision(int x, int y, int hit_w, int hit_h);
   /**
    * \brief デストラクタ
    */
   ~PrivateCollision();
   /**
   * \brief                                純粋仮想関数のオーバーライド
   * \return OBJECTTYPE::PRIVATECOLLISION  オブジェクトの種別（受け側で判定を取らない当たり判定）を返す
   */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::PRIVATECOLLISION; }
   /**
    * \brief 初期化関数
    */
   void Init()override;
   /**
    * \brief       デバッグ用当たり判定色指定関数
    * \param color デバック用矩形カラー
    */
   void SetColor(std::tuple<int, int, int> color) { _debug_color = color; }
};