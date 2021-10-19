/*****************************************************************//**
 * \file   SwayParticle.h
 * \brief  スウェイパーティクルクラス（パーティクルベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ParticleBase.h"
/** スウェイパーティクル */
class SwayParticle : public ParticleBase {
public:
   /**
    * \brief      コンストラクタ
    * \param xy   XY座標
    * \param vxy  パーティクルの移動方向
    * \param flip 反転判定
    */
   SwayParticle(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
   /**
    * \brief デストラクタ
    */
   ~SwayParticle();
   /**
    * \brief                     純粋仮想関数のオーバーライド
    * \return PARTICLETYPE::SWAY パーティクルの種別（スウェイパーティクル）を返す
    */
   virtual PARTICLETYPE GetParType() { return PARTICLETYPE::SWAY; }
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
/** スウェイパーティクルクラス用定数 */
namespace SPInfo {
   constexpr auto SWAY_PARTICLE_GRAPH = "res/Particle/Sway.png"; //!< 画像ファイル名
   constexpr auto SWAY_PARTICLE_POSITIONX = 0.0;                 //!< 基準点(足下)から描画点へのX座標差分
   constexpr auto SWAY_PARTICLE_POSITIONY = -10.0;               //!< 基準点(足下)から描画点へのY座標差分
   constexpr auto SWAY_PARTICLE_BLENDMODE = DX_BLENDMODE_SUB;    //!< ブレンドモード設定
   constexpr auto SWAY_PARTICLE_PAL = 255;                       //!< ブレンド値(0～255)
   constexpr auto SWAY_PARTICLE_RED = 255;                       //!< 赤色値(0～255)
   constexpr auto SWAY_PARTICLE_GREEN = 255;                     //!< 緑色値(0～255)
   constexpr auto SWAY_PARTICLE_BLUE = 255;                      //!< 青色値(0～255)
   constexpr auto SWAY_PARTICLE_SCALE = 1.0;                     //!< 拡縮値(1.0がデフォルト)
   constexpr auto SWAY_PARTICLE_ANGLE = 0.0;                     //!< 描画角度(3.14=180°)
   constexpr auto SWAY_PARTICLE_CNT = 25;                        //!< パーティクル1個あたりの生存時間
   constexpr auto SWAY_PARTICLE_QTY = 10;                        //!< 1フレーム当たりのパーティクル数
   //パーティクル1個当たりの移動方向のランダム値調整
   constexpr auto SWAY_PARTICLE_RANDOMX1 = 25;                   //!< パーティクルのXランダム値
   constexpr auto SWAY_PARTICLE_RANDOMX2 = 5.0;                  //!<       〃
   constexpr auto SWAY_PARTICLE_RANDOMX3 = 2.5;                  //!<       〃
   constexpr auto SWAY_PARTICLE_RANDOMY1 = 20;                   //!< パーティクルのYランダム値
   constexpr auto SWAY_PARTICLE_RANDOMY2 = 10.0;                 //!<       〃
   constexpr auto SWAY_PARTICLE_RANDOMY3 = 2.5;                  //!<       〃
}
