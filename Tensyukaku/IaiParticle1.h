/*****************************************************************//**
 * \file   IaiParticle1.h
 * \brief  居合パーティクル１クラス(パーティクルベースクラスのサブクラス)
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ParticleBase.h"
/** 居合パーティクル１ */
class IaiParticle1 : public ParticleBase {
public:
   /**
    * \brief      コンストラクタ
    * \param xy   XY座標
    * \param vxy  パーティクルの移動方向
    * \param flip 反転判定
    */
   IaiParticle1(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
   /**
    * \brief デストラクタ
    */
   ~IaiParticle1();
   /**
   * \brief                     純粋仮想関数のオーバーライド
   * \return PARTICLETYPE::IAI1 パーティクルの種別（居合パーティクル１）を返す
   */
   virtual PARTICLETYPE GetParType() { return PARTICLETYPE::IAI1; }
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
/** 居合パーティクル１クラス用定数 */
namespace IP1Info {
   constexpr auto IAI_PARTICLE1_GRAPH = "res/Particle/IaiLight.png";   //!< 画像ファイル名
   constexpr auto IAI_PARTICLE1_POSITIONX = 0.0;              //!< 基準点(足下)から描画点へのX座標差分
   constexpr auto IAI_PARTICLE1_POSITIONY = -225.0;           //!< 基準点(足下)から描画点へのY座標差分
   constexpr auto IAI_PARTICLE1_BLENDMODE = DX_BLENDMODE_ADD; //!< ブレンドモード設定
   constexpr auto IAI_PARTICLE1_PAL = 128;                    //!< ブレンド値(0～255)
   constexpr auto IAI_PARTICLE1_RED = 80;                     //!< 赤色値(0～255)
   constexpr auto IAI_PARTICLE1_GREEN = 80;                   //!< 緑色値(0～255)
   constexpr auto IAI_PARTICLE1_BLUE = 60;                    //!< 青色値(0～255)
   constexpr auto IAI_PARTICLE1_SCALE = 0.8;                  //!< 拡縮値(1.0がデフォルト)
   constexpr auto IAI_PARTICLE1_ANGLE = 0.0;                  //!< 描画角度(3.14=180°)
   constexpr auto IAI_PARTICLE1_CNT = 20;                     //!< パーティクル1個あたりの生存時間
   constexpr auto IAI_PARTICLE1_QTY = 5;                      //!< 1フレーム当たりのパーティクル数
   //パーティクル1個当たりの移動方向のランダム値調整
   constexpr auto IAI_PARTICLE1_RANDOMX1 = 20;                //!< パーティクルのXランダム値
   constexpr auto IAI_PARTICLE1_RANDOMX2 = 10.0;              //!<       〃
   constexpr auto IAI_PARTICLE1_RANDOMX3 = 8.0;               //!<       〃
   constexpr auto IAI_PARTICLE1_RANDOMY1 = 20;                //!< パーティクルのYランダム値
   constexpr auto IAI_PARTICLE1_RANDOMY2 = 10.00;             //!<       〃
   constexpr auto IAI_PARTICLE1_RANDOMY3 = 8.0;               //!<       〃
}
