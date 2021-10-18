/*****************************************************************//**
 * \file   Andon.h
 * \brief  行燈クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** 行燈 */
class Andon :public ObjectBase {
public:
   /**
    * \brief   コンストラクタ
    * \param x X座標
    * \param y Y座標
    */
   Andon( int x,int y);
   /**
    \brief デストラクタ
    */
   ~Andon();
   /**
    * \brief                      //純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::ANDON   //オブジェクトの種別（行燈）を返す
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::ANDON; }
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
   int _flame_y;            //!< 発生する炎のY座標
   bool _andon_drop_flag;   //!< 行燈が倒れたかのフラグ
   bool _player_flip_flag;  //!< プレイヤーの反転判定保存フラグ
};
/** 行燈クラス用定数 */
namespace AInfo {
   /*----------行燈の各座標関係----------*/
   constexpr auto GRAPHPOINT_X = 0;         //!< X位置から描画点までの差分
   constexpr auto GRAPHPOINT_Y = -112;      //!< Y位置から描画点までの差分
   constexpr auto POSITION_HITX = -45;      //!< 描画点から当たり判定左上座標までの差分
   constexpr auto POSITION_HITY = -113;     //!< 描画点から当たり判定左上座標までの差分
   constexpr auto COLLISION_WIDTH = 90;     //!< プレイヤーの当たり判定横幅
   constexpr auto COLLISION_HEIGHT = 225;   //!< プレイヤーの当たり判定縦幅

   /*----------画像読み込み&アニメーション&判定フレーム関係----------*/
   constexpr auto GRAPH_WIDTH = 90;         //!< 1枚当たりの画像サイズ（横）
   constexpr auto GRAPH_HEIGHT = 225;       //!< 1枚当たりの画像サイズ（縦）
   constexpr auto ANDON_GRAPHNAME = "res/Gimik/Andon.png";   //!< 画像ファイル名
   constexpr auto ANDON_ANIMEMAX = 1;       //!< 全ての画像枚数
   constexpr auto ANDON_WIDTHCOUNT = 1;     //!< 横の画像枚数
   constexpr auto ANDON_HEIGHTCOUNT = 1;    //!< 縦の画像枚数
   constexpr auto ANDON_ALLFRAME = 90;      //!< 行燈が倒れた際の消滅までのフレーム
   constexpr auto ANDON_DROPFRAME = 30;     //!< 行燈が倒れきるまでのフレーム
   constexpr auto ANDON_DROPANGLE = 0.07;   //!< 1フレーム当たりの行燈が倒れる角度
   constexpr auto ANDON_DROPANGLEMAX = 1.5; //!< 行燈の倒れる角度の最大値
   constexpr auto ANDON_DROPMOVEX = 4;      //!< 行燈が倒れた際のXの移動量
   constexpr auto ANDON_DROPMOVEY = 2;      //!< 行燈が倒れた際のYの移動量
   constexpr auto ANDON_FIREWIDTH = 100;    //!< 生成される炎ごとの距離(中心点)
   constexpr auto ANDON_FIREFRAME1 = 40;    //!< 炎が生成されるフレーム1
   constexpr auto ANDON_FIREFRAME2 = 60;    //!< 炎が生成されるフレーム2
   constexpr auto ANDON_FIREFRAME3 = 80;    //!< 炎が生成されるフレーム3
   constexpr auto ANDON_FADEOUTSPEED = 4;   //!< フェードアウトスピード
}