/*****************************************************************//**
 * \file   GaugeMaxParticle.h
 * \brief  居合ゲージMAX時のプレイヤー側パーティクルクラス（パーティクルベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ParticleBase.h"
/** 居合ゲージMAX時のプレイヤー側パーティクル */
class GaugeMaxParticle : public ParticleBase {
public:
   /**
    * \brief      コンストラクタ
    * \param xy   XY座標
    * \param vxy  パーティクルの移動方向
    * \param flip 反転判定
    */
   GaugeMaxParticle(std::pair<double, double> xy, std::pair<double, double> vxy);
   /**
    * \brief デストラクタ
    */
   ~GaugeMaxParticle();
   /**
   * \brief                              純粋仮想関数のオーバーライド
   * \return PARTICLETYPE::GAUGEMAXLIGHT パーティクルの種別（居合ゲージMAX時のプレイヤー側パーティクル）を返す
   */
   virtual PARTICLETYPE GetParType() { return PARTICLETYPE::GAUGEMAXLIGHT; }
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
/** 居合ゲージMAX時のプレイヤー側パーティクルクラス用定数 */
namespace GMPInfo {
   constexpr auto GAGEMAX_PARTICLE_GRAPH = "res/Particle/GageMax.png";   //!< 画像ファイル名
   constexpr auto GAGEMAX_PARTICLE_POSITIONX = 0.0;              //!< 基準点(足下)から描画点へのX座標差分
   constexpr auto GAGEMAX_PARTICLE_POSITIONY = -220.0;           //!< 基準点(足下)から描画点へのY座標差分
   constexpr auto GAGEMAX_PARTICLE_BLENDMODE = DX_BLENDMODE_ADD; //!< ブレンドモード設定
   constexpr auto GAGEMAX_PARTICLE_PAL = 150;                    //!< ブレンド値(0～255)
   constexpr auto GAGEMAX_PARTICLE_RED = 240;                    //!< 赤色値(0～255)
   constexpr auto GAGEMAX_PARTICLE_GREEN = 70;                   //!< 緑色値(0～255)
   constexpr auto GAGEMAX_PARTICLE_BLUE = 5;                     //!< 青色値(0～255)
   constexpr auto GAGEMAX_PARTICLE_SCALE = 1.0;                  //!< 拡縮値(1.0がデフォルト)
   constexpr auto GAGEMAX_PARTICLE_ANGLE = 0.0;                  //!< 描画角度(3.14=180°)
   constexpr auto GAGEMAX_PARTICLE_CNT = 40;                     //!< パーティクル1個あたりの生存時間
   constexpr auto GAGEMAX_PARTICLE_QTY = 10;                     //!< 1フレーム当たりのパーティクル数
   //パーティクル1個当たりの移動方向のランダム値調整
   constexpr auto GAGEMAX_PARTICLE_RANDOMX1 = 5;                 //!< パーティクルのXランダム値
   constexpr auto GAGEMAX_PARTICLE_RANDOMX2 = 5.0;               //!<       〃
   constexpr auto GAGEMAX_PARTICLE_RANDOMX3 = 4.0;               //!<       〃
   constexpr auto GAGEMAX_PARTICLE_RANDOMY1 = 5;                 //!< パーティクルのYランダム値
   constexpr auto GAGEMAX_PARTICLE_RANDOMY2 = 5.0;               //!<       〃
   constexpr auto GAGEMAX_PARTICLE_RANDOMY3 = 4.0;               //!<       〃
}
