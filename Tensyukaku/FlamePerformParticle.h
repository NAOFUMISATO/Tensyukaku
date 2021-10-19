/*****************************************************************//**
 * \file   FlamePerformParticle.h
 * \brief  炎上演出パーティクルクラス（パーティクルベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ParticleBase.h"
/** 炎上演出パーティクル */
class FlamePerform :public ParticleBase {
public:
   /**
    * \brief      コンストラクタ
    * \param xy   XY座標
    * \param vxy  パーティクルの移動方向
    * \param flip 反転判定
    */
   FlamePerform(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
   /**
    * \brief デストラクタ
    */
   ~FlamePerform();
   /**
    * \brief                             純粋仮想関数のオーバーライド
    * \return PARTICLETYPE::FLAMEPERFORM パーティクルの種別（炎上演出パーティクル）を返す
    */
   virtual PARTICLETYPE GetParType() { return PARTICLETYPE::FLAMEPERFORM; }
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
/** 炎上演出パーティクルクラス用定数 */
namespace FParInfo {
   constexpr auto FLAME_GRAPH = "res/Particle/Flame.png"; //!< 画像ファイル名
   constexpr auto FLAME_POSITIONX = 0.0;                  //!< 基準点(足下)から描画点へのX座標差分
   constexpr auto FLAME_POSITIONY = 400.0;                //!< 基準点(足下)から描画点へのY座標差分
   constexpr auto FLAME_BLENDMODE = DX_BLENDMODE_ADD;     //!< ブレンドモード設定
   constexpr auto FLAME_PAL = 64;                         //!< ブレンド値(0～255)
   constexpr auto FLAME_RED = 240;                        //!< 赤色値(0～255)
   constexpr auto FLAME_GREEN = 70;                       //!< 緑色値(0～255)
   constexpr auto FLAME_BLUE = 5;                         //!< 青色値(0～255)
   constexpr auto FLAME_SCALE = 1.0;                      //!< 拡縮値(1.0がデフォルト)
   constexpr auto FLAME_ANGLE = 0.0;                      //!< 描画角度(3.14=180°)
   constexpr auto FLAME_CNT = 130;                        //!< パーティクル1個あたりの生存時間
   constexpr auto FLAME_QTY = 1;                          //!< 1フレーム当たりのパーティクル数
   //パーティクル1個当たりの移動方向のランダム値調整
   constexpr auto FLAME_RANDOMX1 = 30;                    //!< パーティクルのXランダム値
   constexpr auto FLAME_RANDOMX2 = 10.5;                  //!<       〃
   constexpr auto FLAME_RANDOMX3 = 10.5;                  //!<       〃
   constexpr auto FLAME_RANDOMY1 = 17;                    //!< パーティクルのYランダム値
   constexpr auto FLAME_RANDOMY2 = 19.5;                  //!<       〃
   constexpr auto FLAME_RANDOMY3 = 8.5;                   //!<       〃
}