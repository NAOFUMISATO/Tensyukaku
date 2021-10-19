/*****************************************************************//**
 * \file   IaiParticle3.h
 * \brief  居合パーティクル３クラス（パーティクルベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ParticleBase.h"
/** 居合パーティクル３ */
class IaiParticle3 : public ParticleBase {
public:
   /**
    * \brief      コンストラクタ
    * \param xy   XY座標
    * \param vxy  パーティクルの移動方向
    * \param flip 反転判定
    */
   IaiParticle3(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
   /**
    * \brief デストラクタ
    */
   ~IaiParticle3();
   /**
    * \brief                     純粋仮想関数のオーバーライド
    * \return PARTICLETYPE::IAI3 パーティクルの種別（居合パーティクル３）を返す
    */
   virtual PARTICLETYPE GetParType() { return PARTICLETYPE::IAI3; }
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
/** 居合パーティクル３クラス用定数 */
namespace IP3Info {
   constexpr auto IAI_PARTICLE3_GRAPH = "res/Particle/IaiSibuki.png";   //!< 画像ファイル名
   constexpr auto IAI_PARTICLE3_POSITIONX = 0.0;              //!< 基準点(足下)から描画点へのX座標差分
   constexpr auto IAI_PARTICLE3_POSITIONY = -225.0;           //!< 基準点(足下)から描画点へのY座標差分
   constexpr auto IAI_PARTICLE3_BLENDMODE = DX_BLENDMODE_SUB; //!< ブレンドモード設定
   constexpr auto IAI_PARTICLE3_PAL = 128;                    //!< ブレンド値(0～255)
   constexpr auto IAI_PARTICLE3_RED = 200;                    //!< 赤色値(0～255)
   constexpr auto IAI_PARTICLE3_GREEN = 200;                  //!< 緑色値(0～255)
   constexpr auto IAI_PARTICLE3_BLUE = 200;                   //!< 青色値(0～255)
   constexpr auto IAI_PARTICLE3_SCALE = 1.0;                  //!< 拡縮値(1.0がデフォルト)
   constexpr auto IAI_PARTICLE3_ANGLE = 0.0;                  //!< 描画角度(3.14=180°)
   constexpr auto IAI_PARTICLE3_CNT = 30;                     //!< パーティクル1個あたりの生存時間
   constexpr auto IAI_PARTICLE3_QTY = 5;                      //!< 1フレーム当たりのパーティクル数
   //パーティクル1個当たりの移動方向のランダム値調整
   constexpr auto IAI_PARTICLE3_RANDOMX1 = 45;                //!< パーティクルのXランダム値
   constexpr auto IAI_PARTICLE3_RANDOMX2 = 10.0;              //!<       〃
   constexpr auto IAI_PARTICLE3_RANDOMX3 = 2.5;               //!<       〃
   constexpr auto IAI_PARTICLE3_RANDOMY1 = 45;                //!< パーティクルのYランダム値
   constexpr auto IAI_PARTICLE3_RANDOMY2 = 10.0;              //!<       〃
   constexpr auto IAI_PARTICLE3_RANDOMY3 = 2.5;               //!<       〃
}
