/*****************************************************************//**
 * \file   MugenAndon.h
 * \brief  無限行燈クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** 無限行燈 */
class MugenAndon :public ObjectBase {
public:
   /**
    * \brief   コンストラクタ
    * \param x X座標
    * \param y Y座標
    */
   MugenAndon(int x, int y);
   /**
    * \brief デストラクタ
    */
   ~MugenAndon();
   /**
    * \brief                         純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::MUGENANDON オブジェクトの種別（無限行燈）を返す
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::MUGENANDON; }
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
   /**
    * \brief   オブジェクトの消去関数
    * \param g ゲームの参照
    */
   void Delete(Game& g)override;

private:
   int _flame_y;           //!< 発生する無限炎のY座標
   bool _andondrop_flag;   //!< 無限行燈が倒れたかのフラグ
   bool _playerflip_flag;  //!< プレイヤーの反転判定保存フラグ
};
/** 無限行燈クラス用定数 */
namespace MAInfo {
   /*----------行燈の各座標関係----------*/
   constexpr auto GRAPHPOINT_X = 0;          //!< X位置から描画点までの差分
   constexpr auto GRAPHPOINT_Y = -112;       //!< Y位置から描画点までの差分
   constexpr auto POSITION_HITX = -45;       //!< 描画点から当たり判定左上座標までの差分
   constexpr auto POSITION_HITY = -113;      //!< 描画点から当たり判定左上座標までの差分
   constexpr auto COLLISION_WIDTH = 90;      //!< プレイヤーの当たり判定横幅
   constexpr auto COLLISION_HEIGHT = 225;    //!< プレイヤーの当たり判定縦幅

   /*----------画像読み込み&アニメーション&判定フレーム関係----------*/
   constexpr auto GRAPH_WIDTH = 90;          //!< 1枚当たりの画像サイズ（横）
   constexpr auto GRAPH_HEIGHT = 225;        //!< 1枚当たりの画像サイズ（縦）
   constexpr auto MANDON_GRAPHNAME = "res/Gimik/Andon.png";   //!< 画像ファイル名
   constexpr auto MANDON_ANIMEMAX = 1;       //!< 全ての画像枚数
   constexpr auto MANDON_WIDTHCOUNT = 1;     //!< 横の画像枚数
   constexpr auto MANDON_HEIGHTCOUNT = 1;    //!< 縦の画像枚数
   constexpr auto MANDON_ALLFRAME = 90;      //!< 行燈が倒れた際の消滅までのフレーム
   constexpr auto MANDON_DROPFRAME = 30;     //!< 行燈が倒れきるまでのフレーム
   constexpr auto MANDON_DROPANGLE = 0.07;   //!< 1フレーム当たりの行燈が倒れる角度
   constexpr auto MANDON_DROPANGLEMAX = 1.5; //!< 行燈の倒れる角度の最大値
   constexpr auto MANDON_DROPMOVEX = 4;      //!< 行燈が倒れた際のXの移動量
   constexpr auto MANDON_DROPMOVEY = 2;      //!< 行燈が倒れた際のYの移動量
   constexpr auto MANDON_FIREWIDTH = 100;    //!< 生成される炎ごとの距離(中心点)
   constexpr auto MANDON_FIREFRAME1 = 40;    //!< 炎が生成されるフレーム1
   constexpr auto MANDON_FIREFRAME2 = 60;    //!< 炎が生成されるフレーム2
   constexpr auto MANDON_FIREFRAME3 = 80;    //!< 炎が生成されるフレーム3
   constexpr auto MANDON_FADEOUTSPEED = 4;   //!< フェードアウトスピード

}