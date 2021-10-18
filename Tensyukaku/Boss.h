/*****************************************************************//**
 * \file   Boss.h
 * \brief  ボスクラス（エネミーベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** ボス */
class Boss :public ObjectBase {
public:
   /**
    * \brief      コンストラクタ
    * \param x    X座標
    * \param y    Y座標
    * \param flip 反転判定
    */
   Boss(int x,int y,bool flip);
   /**
    * \brief デストラクタ
    */
   ~Boss();
   /**
    * \brief                   純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::BOSS オブジェクトの種別（ボス）を返す
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::BOSS; }
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
   * \brief   更新関数
   * \param g ゲームの参照
   */
   void Draw(Game& g)override;

private:
   /** ボスの状態列挙 */
   enum class BOSSSTATE {
      IDLE,     //!< 待機
      EVENTA,   //!< イベントA
      EVENTB,   //!< イベントB
      DAMAGE,   //!< 被ダメ
      DEAD      //!< 死亡
   };
   /**
    * \brief   待機状態関数
    * \param g ゲームの参照
    */
   void Idle(Game& g);
   /**
    * \brief   イベントA状態関数
    * \param g ゲームの参照
    */
   void BossEventA(Game& g);
   /**
    * \brief   イベントB状態関数
    * \param g ゲームの参照
    */
   void BossEventB(Game& g);
   /**
    * \brief   被ダメ状態関数
    * \param g ゲームの参照
    */
   void Damage(Game& g);
   /**
    * \brief   死亡状態関数
    * \param g ゲームの参照
    */
   void Dead(Game& g);
   /**
    * \brief   ボスイベントへの状態遷移関数
    * \param g ゲームの参照
    */
   void EventChange(Game& g);
   /**
    * \brief ボスの画像読み込み関数
    */
   void LoadPicture();
   /**
    * \brief ボスのSE読み込み関数
    */
   void LoadSE();
   /**
    * \brief 効果音ボリューム初期値設定関数
    */
   void VolumeInit();
   /**
    * \brief ボリューム変更関数
    */
   void VolumeChange();

   BOSSSTATE _state;    //!< 状態遷移変数
   int _walk_speed;     //!< 移動速度

};
/** ボスクラス用定数 */
namespace BossInifo {
   constexpr auto GRAPHPOINT_X = 0;         //!< X位置から描画点までの差分
   constexpr auto GRAPHPOINT_Y = -315;      //!< Y位置から描画点までの差分
   constexpr auto POSITION_HITX = -45;      //!< 描画点から当たり判定左上座標までの差分
   constexpr auto POSITION_HITY = -135;     //!< 描画点から当たり判定左上座標までの差分
   constexpr auto COLLISION_WIDTH = 90;     //!< ボスの当たり判定横幅
   constexpr auto COLLISION_HEIGHT = 450;   //!< ボスの当たり判定縦幅

   /*----------画像読み込み&アニメーション&判定フレーム関係----------*/
   //共通
   constexpr auto GRAPH_WIDTH = 630;        //!< 1枚当たりの画像サイズ（横）
   constexpr auto GRAPH_HEIGHT = 630;       //!< 1枚当たりの画像サイズ（縦）
   //待機
   constexpr auto IDLE_GRAPHNAME = "res/Boss/BossIdle.png";   //!< 画像ファイル名
   constexpr auto IDLE_ANIMEMAX = 1;        //!< 全ての画像枚数
   constexpr auto IDLE_WIDTHCOUNT = 1;      //!< 横の画像枚数
   constexpr auto IDLE_HEIGHTCOUNT = 1;     //!< 縦の画像枚数
   constexpr auto ANIMESPEED_IDLE = 1;      //!< アニメスピード（何フレームごとに画像を切り替えるか）
   //移動
   constexpr auto MOVE_GRAPHNAME = "res/Boss/BossWalk.png";   //!< 画像ファイル名
   constexpr auto MOVE_ANIMEMAX = 6;        //!< 全ての画像枚数
   constexpr auto MOVE_WIDTHCOUNT = 3;      //!< 横の画像枚数
   constexpr auto MOVE_HEIGHTCOUNT = 2;     //!< 縦の画像枚数
   constexpr auto ANIMESPEED_WALK = 10;     //!< 歩きアニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto ANIMESPEED_RUN = 6;       //!< 走りアニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto MOVE_SEFRAME = 120;       //!< 移動SEの管理フレーム
   //後ずさり
   constexpr auto BACK_GRAPHNAME = "res/Boss/BossBack.png";   //!< 画像ファイル名
   constexpr auto BACK_ANIMEMAX = 6;        //!< 全ての画像枚数
   constexpr auto BACK_WIDTHCOUNT =3;       //!< 横の画像枚数
   constexpr auto BACK_HEIGHTCOUNT =2;      //!< 縦の画像枚数
   constexpr auto ANIMESPEED_BACK = 10;     //!< 後ずさりアニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto BACK_SEFRAME = 120;       //!< 移動SEの管理フレーム
   //被ダメ
   constexpr auto DAMAGE_GRAPHNAME = "res/Boss/BossDamage.png";   //!< 画像ファイル名
   constexpr auto DAMAGE_ANIMEMAX = 1;      //!< 全ての画像枚数
   constexpr auto DAMAGE_WIDTHCOUNT = 1;    //!< 横の画像枚数
   constexpr auto DAMAGE_HEIGHTCOUNT = 1;   //!< 縦の画像枚数
   constexpr auto ANIMESPEED_DAMAGE = 60;   //!< アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto DAMAGE_ANIMEFRAME = DAMAGE_ANIMEMAX * ANIMESPEED_DAMAGE; //!< アニメーションフレーム
   constexpr auto DAMAGE_ALLFRAME = 80;     //!< 死亡全フレーム(全フレームーアニメーションフレーム＝猶予時間)
   //死亡
   constexpr auto DEAD_GRAPHNAME = "res/Boss/BossDead2.png";   //!< 画像ファイル名
   constexpr auto DEAD_ANIMEMAX = 3;        //!< 全ての画像枚数
   constexpr auto DEAD_WIDTHCOUNT = 3;      //!< 横の画像枚数
   constexpr auto DEAD_HEIGHTCOUNT = 1;     //!< 縦の画像枚数
   constexpr auto ANIMESPEED_DEAD = 60;     //!< アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto DEAD_ANIMEFRAME = DEAD_ANIMEMAX * ANIMESPEED_DEAD; //!< アニメーションフレーム
   constexpr auto DEAD_ALLFRAME = 180;      //!< 死亡全フレーム(全フレームーアニメーションフレーム＝猶予時間)
}