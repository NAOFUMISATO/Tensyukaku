/*****************************************************************//**
 * \file   KunaiParticle.h
 * \brief  クナイ投げ予備動作パーティクルクラス（パーティクルベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ParticleBase.h"
/** クナイ投げ予備動作パーティクル */
class KunaiParticle : public ParticleBase {
public:
   /**
    * \brief      コンストラクタ
    * \param xy   XY座標
    * \param vxy  パーティクルの移動方向
    * \param flip 反転判定
    */
   KunaiParticle(std::pair<double, double> xy, std::pair<double, double> mxy, bool flip);
   /**
    * \brief デストラクタ
    */
   ~KunaiParticle();
   /**
    * \brief                                  純粋仮想関数のオーバーライド
    * \return PARTICLETYPE::KUNAIRESERVELIGHT パーティクルの種別（クナイ投げ予備動作パーティクル）を返す
    */
   virtual PARTICLETYPE GetParType() { return PARTICLETYPE::KUNAILIGHT; }
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
/** クナイ投げ予備動作パーティクルクラス用定数 */
namespace KPInfo {
   constexpr auto KRESERVELIGHT_PARTICLE_GRAPH = "res/Particle/KunaiReserveLight.png";   //!< 画像ファイル名
   constexpr auto KRESERVELIGHT_PARTICLE_POSITIONX = 0.0;               //!< 基準点(足下)から描画点へのX座標差分
   constexpr auto KRESERVELIGHT_PARTICLE_POSITIONY = -100.0;            //!< 基準点(足下)から描画点へのY座標差分
   constexpr auto KRESERVELIGHT_PARTICLE_BLENDMODE = DX_BLENDMODE_ADD;  //!< ブレンドモード設定
   constexpr auto KRESERVELIGHT_PARTICLE_PAL = 128;                     //!< ブレンド値(0～255)
   constexpr auto KRESERVELIGHT_PARTICLE_RED = 128;                     //!< 赤色値(0～255)
   constexpr auto KRESERVELIGHT_PARTICLE_GREEN = 128;                   //!< 緑色値(0～255)
   constexpr auto KRESERVELIGHT_PARTICLE_BLUE = 128;                    //!< 青色値(0～255)
   constexpr auto KRESERVELIGHT_PARTICLE_SCALE = 1.0;                   //!< 拡縮値(1.0がデフォルト)
   constexpr auto KRESERVELIGHT_PARTICLE_ANGLE = 0.0;                   //!< 描画角度(3.14=180°)
   constexpr auto KRESERVELIGHT_PARTICLE_CNT = 20;                      //!< パーティクル1個あたりの生存時間
   constexpr auto KRESERVELIGHT_PARTICLE_QTY = 10;                      //!< 1フレーム当たりのパーティクル数
   //パーティクル1個当たりの移動方向のランダム値調整
   constexpr auto KRESERVELIGHT_PARTICLE_RANDOMX1 = 20;                 //!< パーティクルのXランダム値
   constexpr auto KRESERVELIGHT_PARTICLE_RANDOMX2 = 10.0;               //!<       〃
   constexpr auto KRESERVELIGHT_PARTICLE_RANDOMX3 = 8.0;                //!<       〃
   constexpr auto KRESERVELIGHT_PARTICLE_RANDOMY1 = 20;                 //!< パーティクルのYランダム値
   constexpr auto KRESERVELIGHT_PARTICLE_RANDOMY2 = 10.0;               //!<       〃
   constexpr auto KRESERVELIGHT_PARTICLE_RANDOMY3 = 8.0;                //!<       〃
}