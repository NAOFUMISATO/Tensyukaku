/*****************************************************************//**
 * \file   RecoveryParticle.h
 * \brief  回復パーティクルクラス（パーティクルベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ParticleBase.h"
/** 回復パーティクル */
class RecoveryParticle : public ParticleBase {
public:
   /**
    * \brief      コンストラクタ
    * \param xy   XY座標
    * \param vxy  パーティクルの移動方向
    * \param flip 反転判定
    */
   RecoveryParticle(std::pair<double, double> xy, std::pair<double, double> vxy);
   /**
    * \brief デストラクタ
    */
   ~RecoveryParticle();
   /**
    * \brief                         純粋仮想関数のオーバーライド
    * \return PARTICLETYPE::RECOVERY パーティクルの種別（回復パーティクル）を返す
    */
   virtual PARTICLETYPE GetParType() { return PARTICLETYPE::RECOVERY; }
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
/** 回復パーティクルクラス用定数 */
namespace RPInfo {
   constexpr auto RECOVERY_PARTICLE_GRAPH = "res/Particle/Recovery.png";   //!< 画像ファイル名
   constexpr auto RECOVERY_PARTICLE_POSITIONX = 0.0;              //!< 基準点(足下)から描画点へのX座標差分
   constexpr auto RECOVERY_PARTICLE_POSITIONY = -350.0;           //!< 基準点(足下)から描画点へのY座標差分
   constexpr auto RECOVERY_PARTICLE_BLENDMODE = DX_BLENDMODE_ADD; //!< ブレンドモード設定
   constexpr auto RECOVERY_PARTICLE_PAL = 150;                    //!< ブレンド値(0～255)
   constexpr auto RECOVERY_PARTICLE_RED = 30;                     //!< 赤色値(0～255)
   constexpr auto RECOVERY_PARTICLE_GREEN = 200;                  //!< 緑色値(0～255)
   constexpr auto RECOVERY_PARTICLE_BLUE = 30;                    //!< 青色値(0～255)
   constexpr auto RECOVERY_PARTICLE_SCALE = 1.0;                  //!< 拡縮値(1.0がデフォルト)
   constexpr auto RECOVERY_PARTICLE_ANGLE = 0.0;                  //!< 描画角度(3.14=180°)
   constexpr auto RECOVERY_PARTICLE_CNT = 30;                     //!< パーティクル1個あたりの生存時間
   constexpr auto RECOVERY_PARTICLE_QTY = 10;                     //!< 1フレーム当たりのパーティクル数
   //パーティクル1個当たりの移動方向のランダム値調整
   constexpr auto RECOVERY_PARTICLE_RANDOMX1 = 10;                //!< パーティクルのXランダム値
   constexpr auto RECOVERY_PARTICLE_RANDOMX2 = 5.0;               //!<       〃
   constexpr auto RECOVERY_PARTICLE_RANDOMX3 = 4.0;               //!<       〃
   constexpr auto RECOVERY_PARTICLE_RANDOMY1 = 10;                //!< パーティクルのYランダム値
   constexpr auto RECOVERY_PARTICLE_RANDOMY2 = 5.0;               //!<       〃
   constexpr auto RECOVERY_PARTICLE_RANDOMY3 = 4.0;               //!<       〃
}
