/*****************************************************************//**
 * \file   IaiGaugeParticle.h
 * \brief  居合ゲージMAX時のゲージ側パーティクルクラス（パーティクルベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ParticleBase.h"
/** 居合ゲージMAX時のゲージ側パーティクル */
class IaiGaugeParticle : public ParticleBase {
public:
   /**
    * \brief      コンストラクタ
    * \param xy   XY座標
    * \param vxy  パーティクルの移動方向
    * \param flip 反転判定
    */
   IaiGaugeParticle(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
   /**
    * \brief デストラクタ
    */
   ~IaiGaugeParticle();
   /**
   * \brief                         純粋仮想関数のオーバーライド
   * \return PARTICLETYPE::IAIGAUGE パーティクルの種別（居合ゲージMAX時のゲージ側パーティクル）を返す
   */
   virtual PARTICLETYPE GetParType() { return PARTICLETYPE::IAIGAUGE; }
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
/** 居合ゲージMAX時のゲージ側パーティクルクラス用定数 */
namespace IGPInfo {
   constexpr auto IAIG_PARTICLE_GRAPH = "res/Particle/IaiGaugeP.png";  //!< 画像ファイル名
   constexpr auto IAIG_PARTICLE_POSITIONX = 0.0;              //!< 基準点(足下)から描画点へのX座標差分
   constexpr auto IAIG_PARTICLE_POSITIONY = 0.0;              //!< 基準点(足下)から描画点へのY座標差分
   constexpr auto IAIG_PARTICLE_BLENDMODE = DX_BLENDMODE_ADD; //!< ブレンドモード設定
   constexpr auto IAIG_PARTICLE_PAL = 128;                    //!< ブレンド値(0～255)
   constexpr auto IAIG_PARTICLE_RED = 230;                    //!< 赤色値(0～255)
   constexpr auto IAIG_PARTICLE_GREEN = 70;                   //!< 緑色値(0～255)
   constexpr auto IAIG_PARTICLE_BLUE = 5;                     //!< 青色値(0～255)
   constexpr auto IAIG_PARTICLE_SCALE = 1.0;                  //!< 拡縮値(1.0がデフォルト)
   constexpr auto IAIG_PARTICLE_ANGLE = 0.0;                  //!< 描画角度(3.14=180°)
   constexpr auto IAIG_PARTICLE_CNT = 10;                     //!< パーティクル1個あたりの生存時間
   constexpr auto IAIG_PARTICLE_QTY = 5;                      //!< 1フレーム当たりのパーティクル数
   //パーティクル1個当たりの移動方向のランダム値調整
   constexpr auto IAIG_PARTICLE_RANDOMX1 = 10;                //!< パーティクルのXランダム値
   constexpr auto IAIG_PARTICLE_RANDOMX2 = 5.0;               //!<       〃
   constexpr auto IAIG_PARTICLE_RANDOMX3 = 4.0;               //!<       〃
   constexpr auto IAIG_PARTICLE_RANDOMY1 = 10;                //!< パーティクルのYランダム値
   constexpr auto IAIG_PARTICLE_RANDOMY2 = 5.0;               //!<       〃
   constexpr auto IAIG_PARTICLE_RANDOMY3 = 4.0;               //!<       〃
}
