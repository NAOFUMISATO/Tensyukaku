/*****************************************************************//**
 * \file   Kunai.h
 * \brief  忍者型が投げるクナイクラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** クナイ */
class Kunai :public ObjectBase {
public:
   /**
    * \brief      コンストラクタ
    * \param x    X座標
    * \param y    Y座標
    * \param flip 反転判定
    * \param spd  速度
    */
   Kunai(int x,int y,bool flip,int spd);
   /**
    * \brief コンストラクタ
    */
   ~Kunai();
   /**
    * \brief                   純粋仮想関数のオーバーライド
    * \param OBJECTTYPE::KUNAI オブジェクトの種別（クナイ）を返す
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::KUNAI; }
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
   bool _repel_flag;    //!< クナイが弾かれたかのフラグ
};