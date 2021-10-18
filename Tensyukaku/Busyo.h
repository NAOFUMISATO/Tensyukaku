/*****************************************************************//**
 * \file   Busyo.h
 * \brief  武将クラス（エネミーベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "EnemyBase.h"
#include "ObjectBase.h"
/** 武将 */
class Busyo : public EnemyBase {
public:
   /**
    * \brief      コンストラクタ
    * \param x    X座標
    * \param y    Y座標
    * \param flip 反転判定
    */
   Busyo(int x, int y, bool flip);
   /**
    * \brief デストラクタ
    */
   ~Busyo();
   /**
    * \brief                   純粋仮想関数のオーバーライド
    * \return ENEMYTYPE::BUSHI 敵の種別（武将）を返す
    */
   virtual ENEMYTYPE GetEneType() { return ENEMYTYPE::BUSYO; }
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
   /**
    * \brief   出現状態関数
    * \param g ゲームの参照
    */
   void Appear(Game& g);
   /**
    * \brief   巡回状態関数
    * \param g ゲームの参照
    */
   void Patrol(Game& g);
   /**
    * \brief   追跡状態関数
    * \param g ゲームの参照
    */
   void Coming(Game& g);
   /**
    * \brief   攻撃状態関数
    * \param g ゲームの参照
    */
   void Attack(Game& g);
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
    * \brief   各当たり判定関数
    * \param g ゲームの参照
    */
   void HitJudge(Game& g);
   /**
    * \brief 画像読み込み関数
    */
   void LoadPicture();
   /**
    * \brief SE読み込み関数
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
   /**
    * \brief   デバッグ描画関数
    * \param g ゲームの参照
    */
   void DebugDraw(Game& g);
};
/** 武将クラス用定数 */
namespace BsInfo {
   /*----------武将の各座標関係----------*/
   constexpr auto GRAPHPOINT_X = 0;          //!< X位置から描画点までの差分
   constexpr auto GRAPHPOINT_Y = -315;       //!< Y位置から描画点までの差分
   constexpr auto POSITION_HITX = -45;       //!< 描画点から当たり判定左上座標までの差分
   constexpr auto POSITION_HITY = -135;      //!< 描画点から当たり判定左上座標までの差分
   constexpr auto COLLISION_WIDTH = 90;      //!< 当たり判定横幅
   constexpr auto COLLISION_HEIGHT = 450;    //!< 当たり判定縦幅

   /*----------各モーションの当たり判定関係----------*/
   constexpr auto PATROL_WIDTH = 500;        //!< 索敵範囲当たり判定横幅
   constexpr auto PATROL_BACKWIDTH = 250;    //!< 背部索敵範囲当たり判定横幅
   constexpr auto PATROL_HEIGHT = 100;       //!< 索敵範囲当たり判定縦幅
   constexpr auto COMING_WIDTH = 300;        //!< 攻撃発生範囲当たり判定横幅
   constexpr auto COMING_HEIGHT = 100;       //!< 攻撃発生範囲当たり判定縦幅
   constexpr auto ATTACK_WIDTH = 200;        //!< 攻撃当たり判定横幅
   constexpr auto ATTACK_HEIGHT = 150;       //!< 攻撃当たり判定縦幅
   constexpr auto COMINGCANCEL_WIDTH = 1000; //!< 追跡中止当たり判定横幅
   constexpr auto COMINGCANCEL_HEIGHT = 100; //!< 追跡中止当たり判定縦幅
   constexpr auto ATTACKCANCEL_WIDTH = 200;  //!< 攻撃中止当たり判定横幅
   constexpr auto ATTACKCANCEL_HEIGHT = 100; //!< 攻撃中止当たり判定縦幅

   /*----------パラメーター関係----------*/
   constexpr auto LIFE_MAX = 4;              //!< 体力
   constexpr auto SPEED = 2;                 //!< 移動速度
   constexpr auto PLAYER_IAI_MAX = 5;        //!< プレイヤーの居合最大値
   /*----------画像読み込み&アニメーション&判定フレーム関係----------*/
   //共通
   constexpr auto GRAPH_WIDTH = 810;         //!< 1枚当たりの画像サイズ（横）
   constexpr auto GRAPH_HEIGHT = 630;        //!< 1枚当たりの画像サイズ（縦）
   //出現
   constexpr auto APPEAR_GRAPHNAME = "res/Busyo/Bs_Stand.png";   //!< 画像ファイル名
   constexpr auto APPEAR_ANIMEMAX = 1;       //!< 全ての画像枚数
   constexpr auto APPEAR_WIDTHCOUNT = 1;     //!< 横の画像枚数
   constexpr auto APPEAR_HEIGHTCOUNT = 1;    //!< 縦の画像枚数
   constexpr auto ANIMESPEED_APPEAR = 60;    //!< アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto FADEIN_SPEED = 4;          //!< アッパー時のフェードインスピード
   constexpr auto APPEAR_ALLFRAME = 60;      //!< 出現全フレーム
   //巡回
   constexpr auto PATROL_GRAPHNAME = "res/Busyo/Bs_Stand.png";   //!< 画像ファイル名
   constexpr auto PATROL_ANIMEMAX = 1;       //!< 全ての画像枚数
   constexpr auto PATROL_WIDTHCOUNT = 1;     //!< 横の画像枚数
   constexpr auto PATROL_HEIGHTCOUNT = 1;    //!< 縦の画像枚数
   constexpr auto ANIMESPEED_PATROL = 180;   //!< アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto PATROL_TURNFRAME = 180;    //!< 巡回の振り向きフレーム
   //追跡
   constexpr auto COMING_GRAPHNAME = "res/Busyo/Bs_Walk.png";   //!< 画像ファイル名
   constexpr auto COMING_ANIMEMAX = 4;       //!< 全ての画像枚数
   constexpr auto COMING_WIDTHCOUNT = 4;     //!< 横の画像枚数
   constexpr auto COMING_HEIGHTCOUNT = 1;    //!< 縦の画像枚数   
   constexpr auto ANIMESPEED_COMING = 30;    //!< アニメスピード（何フレームごとに画像を切り替えるか）
   //攻撃
   constexpr auto ATTACK_GRAPHNAME = "res/Busyo/Bs_Attack.png";   //!< 画像ファイル名
   constexpr auto ATTACK_ANIMEMAX = 4;       //!< 全ての画像枚数
   constexpr auto ATTACK_WIDTHCOUNT = 4;     //!< 横の画像枚数
   constexpr auto ATTACK_HEIGHTCOUNT = 1;    //!< 縦の画像枚数
   constexpr auto ANIMESPEED_ATTACK = 14;    //!< アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto ATTACK_ANIMEFRAME = ATTACK_ANIMEMAX * ANIMESPEED_ATTACK * 2;   //!< アニメーションフレーム（全ての画像枚数×アニメスピード）
   constexpr auto ATTACK_ALLFRAME = 142;     //!< 攻撃全フレーム（全フレーム-アニメーションフレーム＝攻撃猶予時間）
   constexpr auto ATTACK_STEP = 60;          //!< ステップ距離
   constexpr auto STEP_BEGINFRAME = 14;      //!< ステップの開始フレーム
   constexpr auto ATTACK_BEGINFRAME = 14;    //!< 攻撃判定発生フレーム
   constexpr auto ATTACK_BEGIN2FRAME = 70;   //!< 2段目攻撃判定発生フレーム
   constexpr auto ATTACK_ENDFRAME = 14;      //!< 攻撃判定終了フレーム
   constexpr auto ATTACK_END2FRAME = 84;     //!< 2段目攻撃判定終了フレーム
   //被ダメ
   constexpr auto DAMAGE_GRAPHNAME = "res/Busyo/Bs_Damage.png";   //!< 画像ファイル名
   constexpr auto DAMAGE_ANIMEMAX = 3;       //!< 全ての画像枚数
   constexpr auto DAMAGE_WIDTHCOUNT = 3;     //!< 横の画像枚数
   constexpr auto DAMAGE_HEIGHTCOUNT = 1;    //!< 縦の画像枚数
   constexpr auto ANIMESPEED_DAMAGE = 9;     //!< アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto DAMAGE_ANIMEFRAME = DAMAGE_ANIMEMAX * ANIMESPEED_DAMAGE;   //!< アニメーションフレーム（全ての画像枚数×アニメスピード）
   constexpr auto DAMAGE_ALLFRAME = 27;      //!< 被ダメ全フレーム
   //死亡
   constexpr auto DEAD_GRAPHNAME = "res/Busyo/Bs_Dead.png";      //!< 画像ファイル名
   constexpr auto DEAD_ANIMEMAX = 3;         //!< 全ての画像枚数
   constexpr auto DEAD_WIDTHCOUNT = 3;       //!< 横の画像枚数
   constexpr auto DEAD_HEIGHTCOUNT = 1;      //!< 縦の画像枚数
   constexpr auto ANIMESPEED_DEAD = 20;      //!< アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto DEAD_ANIMEFRAME = DEAD_ANIMEMAX * ANIMESPEED_DEAD;   //!< アニメーションフレーム（全ての画像枚数×アニメスピード）
   constexpr auto DEAD_ALLFRAME = 120;       //!< 死亡全フレーム
   constexpr auto FADEOUT_SPEED = 4;         //!< フェードアウトスピード
}