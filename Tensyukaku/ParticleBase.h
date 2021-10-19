/*****************************************************************//**
 * \file   ParticleBase.h
 * \brief  各パーティクルのベースクラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
//二重インクルード防止
class Game;
/** パーティクル */
class ParticleBase :public ObjectBase {
public:
   /**
    * \brief コンストラクタ
    */
   ParticleBase();
   /**
    * \brief デストラクタ
    */
   ~ParticleBase();
   /**
    * \brief                       純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::PARTICLE オブジェクトの種別（パーティクル）を返す
    */
   virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::PARTICLE; }
   /** パーティクルの種別列挙 */
   enum class PARTICLETYPE {
      CURSOR,       //!< タイトルカーソル
      FLAMEPERFORM, //!< 炎上演出
      MIDDLEATTACK1,//!< 中段攻撃１
      MIDDLEATTACK2,//!< 中段攻撃２
      LOWATTACK1,   //!< 下段攻撃１
      LOWATTACK2,   //!< 下段攻撃２
      IAI1,         //!< 居合１
      IAI2,         //!< 居合２
      IAI3,         //!< 居合３
      SWAY,         //!< スウェイ
      RECOVERY,     //!< 回復
      IAIGAUGE,     //!< 居合ゲージMAX(ゲージ側)
      GAUGEMAXLIGHT,//!< 居合ゲージMAX(プレイヤー側)
      KUNAILIGHT,   //!< クナイ投げ予備動作
      LANCELIGHT    //!< 槍兵予備動作
   };
   /**
    * \brief    純粋仮想関数化
    * \return 0 派生先で定義
    */
   virtual PARTICLETYPE GetParType() = 0;
   /**
    * \brief 初期化関数
    */
   virtual void Init();
   /**
    * \brief   更新関数
    * \param g ゲームの参照
    */
   virtual void Process(Game& g);
   /**
    * \brief   描画関数
    * \param g ゲームの参照
    */
   virtual void Draw(Game& g);

protected:
   std::pair<double, double> _xy;   //!< XY座標
   std::pair<double, double> _dxy;  //!< パーティクルのオブジェクトからのXY座標描画差分
   std::pair<double, double> _mxy;  //!< パーティクルの移動方向
   int _pal;                        //!< 透明度
   int _bm;                         //!< ブレンドモード
   std::tuple<int, int, int> _rgb;  //!< RGB値
};