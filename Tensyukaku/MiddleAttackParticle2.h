/*****************************************************************//**
 * \file   MiddleAttackParticle2.h
 * \brief  中段攻撃パーティクル２クラス（パーティクルベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ParticleBase.h"
/** 中段攻撃パーティクル２ */
class MiddleAttackParticle2 : public ParticleBase {
public:
   /**
    * \brief      コンストラクタ
    * \param xy   XY座標
    * \param vxy  パーティクルの移動方向
    * \param flip 反転判定
    */
   MiddleAttackParticle2(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
   /**
    * \brief デストラクタ
    */
   ~MiddleAttackParticle2();
   /**
    * \brief                              純粋仮想関数のオーバーライド
    * \return PARTICLETYPE::MIDDLEATTACK2 パーティクルの種別（中段攻撃パーティクル２）を返す
    */
   virtual PARTICLETYPE GetParType() { return PARTICLETYPE::MIDDLEATTACK2; }
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
};
/** 中段攻撃パーティクル２クラス用定数 */
namespace MP2Info {
   constexpr auto MIDDLEATTACK_PARTICLE2_GRAPH = "res/Particle/MiddleSibuki.png";   //!< 画像ファイル名
   constexpr auto MIDDLEATTACK_PARTICLE2_POSITIONX = 0.0;              //!< 基準点(足下)から描画点へのX座標差分
   constexpr auto MIDDLEATTACK_PARTICLE2_POSITIONY = -325.0;           //!< 基準点(足下)から描画点へのY座標差分
   constexpr auto MIDDLEATTACK_PARTICLE2_BLENDMODE = DX_BLENDMODE_SUB; //!< ブレンドモード設定
   constexpr auto MIDDLEATTACK_PARTICLE2_PAL = 128;                    //!< ブレンド値(0〜255)
   constexpr auto MIDDLEATTACK_PARTICLE2_RED = 200;                    //!< 赤色値(0〜255)
   constexpr auto MIDDLEATTACK_PARTICLE2_GREEN = 200;                  //!< 緑色値(0〜255)
   constexpr auto MIDDLEATTACK_PARTICLE2_BLUE = 200;                   //!< 青色値(0〜255)
   constexpr auto MIDDLEATTACK_PARTICLE2_SCALE = 1.0;                  //!< 拡縮値(1.0がデフォルト)
   constexpr auto MIDDLEATTACK_PARTICLE2_ANGLE = 0.0;                  //!< 描画角度(3.14=180°)
   constexpr auto MIDDLEATTACK_PARTICLE2_CNT = 20;                     //!< パーティクル1個あたりの生存時間
   constexpr auto MIDDLEATTACK_PARTICLE2_QTY = 5;                      //!< 1フレーム当たりのパーティクル数
   //パーティクル1個当たりの移動方向のランダム値調整
   constexpr auto MIDDLEATTACK_PARTICLE2_RANDOMX1 = 20;                //!< パーティクルのXランダム値
   constexpr auto MIDDLEATTACK_PARTICLE2_RANDOMX2 = 5.0;               //!<       〃
   constexpr auto MIDDLEATTACK_PARTICLE2_RANDOMX3 = 2.0;               //!<       〃
   constexpr auto MIDDLEATTACK_PARTICLE2_RANDOMY1 = 20;                //!< パーティクルのYランダム値
   constexpr auto MIDDLEATTACK_PARTICLE2_RANDOMY2 = 5.0;               //!<       〃
   constexpr auto MIDDLEATTACK_PARTICLE2_RANDOMY3 = 2.0;               //!<       〃
}
