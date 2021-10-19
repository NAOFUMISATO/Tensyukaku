/*****************************************************************//**
 * \file   IaiParticle2.h
 * \brief  居合パーティクル２クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ParticleBase.h"
/** 居合パーティクル２ */
class IaiParticle2 : public ParticleBase {
public:
   /**
    * \brief      コンストラクタ
    * \param xy   XY座標
    * \param vxy  パーティクルの移動方向
    * \param flip 反転判定
    */
   IaiParticle2(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
   /**
    * \brief デストラクタ
    */
   ~IaiParticle2();
   /**
    * \brief                     純粋仮想関数のオーバーライド
    * \return PARTICLETYPE::IAI2 パーティクルの種別（居合パーティクル２）を返す
    */
   virtual PARTICLETYPE GetParType() { return PARTICLETYPE::IAI2; }
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
/** 居合パーティクル２クラス用定数 */
namespace IP2Info {
   constexpr auto IAI_PARTICLE2_GRAPH = "res/Particle/IaiKiseki2.png";   //!< 画像ファイル名
   constexpr auto IAI_PARTICLE2_POSITIONX = 0.0;              //!< 基準点(足下)から描画点へのX座標差分
   constexpr auto IAI_PARTICLE2_POSITIONY = -225.0;           //!< 基準点(足下)から描画点へのY座標差分
   constexpr auto IAI_PARTICLE2_BLENDMODE = DX_BLENDMODE_SUB; //!< ブンドモード設定
   constexpr auto IAI_PARTICLE2_PAL = 100;                    //!< ブレンド値(0～255)
   constexpr auto IAI_PARTICLE2_RED = 170;                    //!< 赤色値(0～255)
   constexpr auto IAI_PARTICLE2_GREEN = 170;                  //!< 緑色値(0～255)
   constexpr auto IAI_PARTICLE2_BLUE = 170;                   //!< 青色値(0～255)
   constexpr auto IAI_PARTICLE2_SCALE = 1.0;                  //!< 拡縮値(1.0がデフォルト)
   constexpr auto IAI_PARTICLE2_ANGLE = 0.0;                  //!< 描画角度(3.14=180°)
   constexpr auto IAI_PARTICLE2_CNT = 30;                     //!< パーティクル1個あたりの生存時間
   constexpr auto IAI_PARTICLE2_QTY = 5;                      //!< 1フレーム当たりのパーティクル数
   //パーティクル1個当たりの移動方向のランダム値調整
   constexpr auto IAI_PARTICLE2_RANDOMX1 = 20;                //!< パーティクルのXランダム値
   constexpr auto IAI_PARTICLE2_RANDOMX2 = 10.0;              //!<       〃
   constexpr auto IAI_PARTICLE2_RANDOMX3 = 8.0;               //!<       〃
   constexpr auto IAI_PARTICLE2_RANDOMY1 = 20;                //!< パーティクルのYランダム値
   constexpr auto IAI_PARTICLE2_RANDOMY2 = 10.0;              //!<       〃
   constexpr auto IAI_PARTICLE2_RANDOMY3 = 8.0;               //!<       〃
}
