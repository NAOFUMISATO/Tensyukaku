/*****************************************************************//**
 * \file   CusorParticle.h
 * \brief  タイトルカーソルパーティクルクラス（パーティクルベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ParticleBase.h"
/** タイトルカーソルパーティクル */
class CursorParticle: public ParticleBase {
public:
   /**
    * \brief         コンストラクタ
    * \param xy      XY座標
    * \param vxy     パーティクルの移動方向
    * \param hittype タイトルのそれぞれの選択オブジェクトに当たった際のタイプ変化
    */
   CursorParticle(std::pair<double, double> xy, std::pair<double, double> mxy, std::string hittype);
   /**
    * \brief デストラクタ
    */
   ~CursorParticle();
   /**
    * \brief                        純粋仮想関数のオーバーライド
    * \return PARTICLETYPE::CURSOR  パーティクルの種別（タイトルカーソルパーティクル）を返す
    */
   virtual PARTICLETYPE GetParType() { return PARTICLETYPE::CURSOR; }
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

private:
   /**
    * \brief カーソルパーティクルの種別設定関数
    */
   void SetType();

   std::string  _hit_type;   //!< カーソルパーティクルの種別を指定する文字列
};
/** タイトルカーソルパーティクルクラス用定数 */
namespace CParInfo {
   constexpr auto CURSOR_PARTICLE1_GRAPH = "res/Particle/Cursor.png"; //!< 画像ファイル名
   constexpr auto CURSOR_PARTICLE1_POSITIONX = 0.0;                   //!< 基準点(足下)から描画点へのX座標差分
   constexpr auto CURSOR_PARTICLE1_POSITIONY = -10.0;                 //!< 基準点(足下)から描画点へのY座標差分
   constexpr auto CURSOR_PARTICLE1_BLENDMODE = DX_BLENDMODE_PMA_ADD;  //!< ブレンドモード設定
   constexpr auto CURSOR_PARTICLE1_PAL = 50;                          //!< ブレンド値
   constexpr auto CURSOR_PARTICLE1_SCALE = 1.0;                       //!< 拡縮値
   constexpr auto CURSOR_PARTICLE1_ANGLE = 0.0;                       //!< 描画角度(3.14=180°)
   //パーティクル1個当たりの移動方向のランダム値調整
   constexpr auto CURSOR_PARTICLE1_RANDOMX1 = 30;                     //!< パーティクルのXランダム値
   constexpr auto CURSOR_PARTICLE1_RANDOMX2 = 10.5;                   //!<       〃
   constexpr auto CURSOR_PARTICLE1_RANDOMX3 = 10.5;                   //!<       〃
   constexpr auto CURSOR_PARTICLE1_RANDOMY1 = 17;                     //!< パーティクルのYランダム値
   constexpr auto CURSOR_PARTICLE1_RANDOMY2 = 19.5;                   //!<       〃
   constexpr auto CURSOR_PARTICLE1_RANDOMY3 = 8.5;                    //!<       〃
   
}