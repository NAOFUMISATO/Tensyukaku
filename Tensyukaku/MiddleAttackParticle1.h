/*****************************************************************//**
 * \file   MiddleAttackParticle1.h
 * \brief  中段攻撃パーティクル１クラス（パーティクルベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ParticleBase.h"
/** 中段攻撃パーティクル1 */
class MiddleAttackParticle1 : public ParticleBase {
public:
   /**
    * \brief      コンストラクタ
    * \param xy   XY座標
    * \param vxy  パーティクルの移動方向
    * \param flip 反転判定
    */
   MiddleAttackParticle1(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
   /**
    * \brief デストラクタ
    */
   ~MiddleAttackParticle1();
   /**
    * \brief                              純粋仮想関数のオーバーライド
    * \return PARTICLETYPE::MIDDLEATTACK1 パーティクルの種別（中段攻撃パーティクル1）を返す
    */
   virtual PARTICLETYPE GetParType() { return PARTICLETYPE::MIDDLEATTACK1; }
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
/** 中段攻撃パーティクル１クラス用定数 */
namespace MP1Info {
   constexpr auto MIDDLEATTACK_PARTICLE1_GRAPH = "res/Particle/MiddleAttack.png";  //!< 画像ファイル名
   constexpr auto MIDDLEATTACK_PARTICLE1_POSITIONX = 0.0;               //!< 基準点(足下)から描画点へのX座標差分
   constexpr auto MIDDLEATTACK_PARTICLE1_POSITIONY = -325.0;            //!< 基準点(足下)から描画点へのY座標差分
   constexpr auto MIDDLEATTACK_PARTICLE1_BLENDMODE = DX_BLENDMODE_SUB;  //!< ブレンドモード設定
   constexpr auto MIDDLEATTACK_PARTICLE1_PAL = 64;                      //!< ブレンド値(0～255)
   constexpr auto MIDDLEATTACK_PARTICLE1_RED = 128;                     //!< 赤色値(0～255)
   constexpr auto MIDDLEATTACK_PARTICLE1_GREEN = 128;                   //!< 緑色値(0～255)
   constexpr auto MIDDLEATTACK_PARTICLE1_BLUE = 128;                    //!< 青色値(0～255)
   constexpr auto MIDDLEATTACK_PARTICLE1_SCALE = 1.0;                   //!< 拡縮値(1.0がデフォルト)
   constexpr auto MIDDLEATTACK_PARTICLE1_ANGLE = 0.0;                   //!< 描画角度(3.14=180°)
   constexpr auto MIDDLEATTACK_PARTICLE1_CNT = 20;                      //!< パーティクル1個あたりの生存時間
   constexpr auto MIDDLEATTACK_PARTICLE1_QTY = 10;                      //!< 1フレーム当たりのパーティクル数
   //パーティクル1個当たりの移動方向のランダム値調整
   constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMX1 = 20;                 //!< パーティクルのXランダム値
   constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMX2 = 10.0;               //!<       〃
   constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMX3 = 8.0;                //!<       〃
   constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMY1 = 20;                 //!< パーティクルのYランダム値
   constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMY2 = 10.0;               //!<       〃
   constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMY3 = 8.0;                //!<       〃
}
