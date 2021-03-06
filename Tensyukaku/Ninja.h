/*****************************************************************//**
 * \file   Ninja.h
 * \brief  忍者クラス（エネミーベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "EnemyBase.h"
/** 忍者 */
class Ninja : public EnemyBase {
public:
   /**
    * \brief             コンストラクタ
    * \param x           X座標
    * \param y           Y座標
    * \param flip        反転判定
    * \param kunai_stock クナイ本数
    */
   Ninja(int x, int y, bool flip,int kunai_stock);
   /**
    * \brief デストラクタ
    */
   ~Ninja();
   /**
    * \brief                   純粋仮想関数のオーバーライド
    * \return ENEMYTYPE::NINJA オブジェクトの種別（忍者）を返す
    */
   virtual ENEMYTYPE GetEneType() { return ENEMYTYPE::NINJA; }
   /**
    * \brief   初期化関数
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
    * \brief   クナイ投げ状態関数
    * \param g ゲームの参照
    */
   void Throw(Game& g);
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
    * \brief   デバッグ描画関数
    * \param g ゲームの参照
    */
   void DebugDraw(Game& g);
   /**
    * \brief 画像読み込み関数
    */
   void LoadPicture();
   /**
    * \brief 効果音読み込み関数
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

   int _kunai_stock;    //!< クナイ本数
};
/** 忍者クラス用定数 */
namespace NInfo {
   /*----------各座標関係----------*/
   constexpr auto GRAPHPOINT_X = 0;         //!< X位置から描画点までの差分
   constexpr auto GRAPHPOINT_Y = -315;      //!< Y位置から描画点までの差分
   constexpr auto POSITION_HITX = -60;      //!< 描画点から当たり判定左上座標までの差分
   constexpr auto POSITION_HITY = 105;      //!< 描画点から当たり判定左上座標までの差分
   constexpr auto COLLISION_WIDTH = 120;    //!< 当たり判定横幅
   constexpr auto COLLISION_HEIGHT = 210;   //!< 当たり判定縦幅

   /*----------各モーションの当たり判定関係----------*/
   constexpr auto PATROL_WIDTH = 800;       //!< 索敵範囲当たり判定横幅
   constexpr auto PATROL_BACKWIDTH = 600;   //!< 背部索敵範囲当たり判定横幅
   constexpr auto PATROL_HEIGHT = 100;      //!< 索敵範囲当たり判定縦幅
   constexpr auto COMING_WIDTH = 150;       //!< 攻撃発生範囲当たり判定横幅
   constexpr auto COMING_HEIGHT = 100;      //!< 攻撃発生範囲当たり判定縦幅
   constexpr auto ATTACK_WIDTH = 150;       //!< 攻撃当たり判定横幅
   constexpr auto ATTACK_HEIGHT = 150;      //!< 攻撃当たり判定縦幅
   constexpr auto COMINGCANCEL_WIDTH = 800; //!< 追跡中止当たり判定横幅
   constexpr auto COMINGCANCEL_HEIGHT = 100;//!< 追跡中止当たり判定縦幅
   constexpr auto ATTACKCANCEL_WIDTH = 150; //!< 攻撃中止当たり判定横幅
   constexpr auto ATTACKCANCEL_HEIGHT = 100;//!< 攻撃中止当たり判定縦幅
   constexpr auto THROWCANCEL_WIDTH = 800;  //!< クナイ投げ中止当たり判定横幅
   constexpr auto THROWCANCEL_HEIGHT = 100; //!< クナイ投げ中止当たり判定縦幅

   /*----------パラメーター関係----------*/
   constexpr auto LIFE_MAX = 1;             //!< 体力
   constexpr auto SPEED = 3;                //!< 移動速度
   constexpr auto PLAYER_IAI_MAX = 5;       //!< プレイヤーの居合最大値

   /*----------忍者の画像読み込み&アニメーション&判定フレーム関係----------*/
   //共通
   constexpr auto GRAPH_WIDTH = 630;        //!< 1枚当たりの画像サイズ（横）
   constexpr auto GRAPH_HEIGHT = 630;       //!< 1枚当たりの画像サイズ（縦）
   //出現
   constexpr auto APPEAR_GRAPHNAME = "res/Ninja/N_Stand.png";   //!< 画像ファイル名
   constexpr auto APPEAR_ANIMEMAX = 1;       //!< 全ての画像枚数
   constexpr auto APPEAR_WIDTHCOUNT = 1;     //!< 横の画像枚数
   constexpr auto APPEAR_HEIGHTCOUNT = 1;    //!< 縦の画像枚数
   constexpr auto ANIMESPEED_APPEAR = 60;    //!< アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto FADEIN_SPEED = 4;          //!< アッパー時のフェードインスピード
   constexpr auto APPEAR_ALLFRAME = 60;      //!< 出現全フレーム
   //巡回
   constexpr auto PATROL_GRAPHNAME = "res/Ninja/N_Stand.png";   //!< 画像ファイル名
   constexpr auto PATROL_ANIMEMAX = 1;       //!< 全ての画像枚数
   constexpr auto PATROL_WIDTHCOUNT = 1;     //!< 横の画像枚数
   constexpr auto PATROL_HEIGHTCOUNT = 1;    //!< 縦の画像枚数
   constexpr auto ANIMESPEED_PATROL = 5;     //!< 各状態アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto PATROL_TURNFRAME = 120;    //!< 巡回の振り向きフレーム
   //追跡
   constexpr auto COMING_GRAPHNAME = "res/Ninja/N_Walk.png";   //!< 画像ファイル名
   constexpr auto COMING_ANIMEMAX = 4;       //!< 全ての画像枚数
   constexpr auto COMING_WIDTHCOUNT = 4;     //!< 横の画像枚数
   constexpr auto COMING_HEIGHTCOUNT = 1;    //!< 縦の画像枚数   
   constexpr auto ANIMESPEED_COMING = 10;    //!< 各状態アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto COMING_ALLFRAME= COMING_ANIMEMAX * ANIMESPEED_COMING;      //!< アニメーションフレーム（全ての画像枚数×アニメスピード）
   constexpr auto COMINGSPEED_UPFRAME = 20;  //!< スピードアップフレーム
   constexpr auto COMINGSPEED_DOWNFRAME = 30;//!< スピードダウンフレーム
   constexpr auto COMING_UPSPEED = 15;       //!< スピードの上昇時の値
   //攻撃
   constexpr auto ATTACK_GRAPHNAME = "res/Ninja/N_Attack.png";   //!< 画像ファイル名
   constexpr auto ATTACK_ANIMEMAX =4;        //!< 全ての画像枚数
   constexpr auto ATTACK_WIDTHCOUNT = 4;     //!< 横の画像枚数
   constexpr auto ATTACK_HEIGHTCOUNT = 1;    //!< 縦の画像枚数
   constexpr auto ANIMESPEED_ATTACK = 10;    //!< 各状態アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto ATTACK_ANIMEFRAME = ATTACK_ANIMEMAX * ANIMESPEED_ATTACK;      //!< アニメーションフレーム（全ての画像枚数×アニメスピード）
   constexpr auto ATTACK_ALLFRAME = 50;      //!< 攻撃全フレーム（全フレーム-アニメーションフレーム＝攻撃猶予時間）
   constexpr auto ATTACK_BEGINFRAME = 20;    //!< 攻撃判定発生フレーム
   constexpr auto ATTACK_ENDFRAME = 10;      //!< 攻撃判定終了フレーム
   //クナイ投げ
   constexpr auto THROW_GRAPHNAME = "res/Ninja/N_Throw.png";   //!< 画像ファイル名
   constexpr auto THROW_ANIMEMAX = 4;        //!< 全ての画像枚数
   constexpr auto THROW_WIDTHCOUNT = 4;      //!< 横の画像枚数
   constexpr auto THROW_HEIGHTCOUNT = 1;     //!< 縦の画像枚数
   constexpr auto ANIMESPEED_THROW = 20;     //!< 各状態アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto THROW_ANIMEFRAME = THROW_ANIMEMAX * ANIMESPEED_THROW;      //!< アニメーションフレーム（全ての画像枚数×アニメスピード）
   constexpr auto THROW_ALLFRAME = 150;      //!< 攻撃全フレーム（全フレーム-アニメーションフレーム＝攻撃猶予時間）
   constexpr auto KUNAI_RELEASEFRAME = 40;   //!< 攻撃判定発生フレーム
   constexpr auto KUNAI_SPEED=10;            //!< クナイの速さ
   //死亡
   constexpr auto DEAD_GRAPHNAME = "res/Ninja/N_Dead.png";      //!< 画像ファイル名
   constexpr auto DEAD_ANIMEMAX = 3;         //!< 全ての画像枚数
   constexpr auto DEAD_WIDTHCOUNT = 3;       //!< 横の画像枚数
   constexpr auto DEAD_HEIGHTCOUNT = 1;      //!< 縦の画像枚数
   constexpr auto ANIMESPEED_DEAD = 20;      //!< 各状態アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto DEAD_ANIMEFRAME = DEAD_ANIMEMAX * ANIMESPEED_DEAD;      //!< アニメーションフレーム（全ての画像枚数×アニメスピード）
   constexpr auto DEAD_ALLFRAME = 120;       //!< 死亡全フレーム
   constexpr auto FADEOUT_SPEED = 4;         //!< フェードアウトスピード
   /*----------クナイの各座標関係----------*/
   constexpr auto KUNAI_GRAPHPOINT_X = 0;     //!< X位置から描画点までの差分
   constexpr auto KUNAI_GRAPHPOINT_Y = -45;   //!< Y位置から描画点までの差分
   constexpr auto KUNAI_POSITION_HITX = -45;  //!< 描画点から当たり判定左上座標までの差分
   constexpr auto KUNAI_POSITION_HITY = -20;  //!< 描画点から当たり判定左上座標までの差分
   constexpr auto KUNAI_COLLISION_WIDTH = 90; //!< 当たり判定横幅
   constexpr auto KUNAI_COLLISION_HEIGHT = 40;//!< 当たり判定縦幅
   /*----------クナイ画像読み込み&アニメーション関係----------*/
   constexpr auto KUNAI_GRAPHNAME = "res/Ninja/Kunai.png";   //!< 画像ファイル名
   constexpr auto REPEL_FRAME = 60;           //!< 弾かれてから消滅までのフレーム
   constexpr auto KUNAI_ALPHACHANGE = 4;      //!< 弾かれた後の1フレーム当たりの透明度の減少量
   constexpr auto KUNAI_ANGLECHANGE = 0.1;    //!< 弾かれた後の1フレーム当たりの角度の変更量
   constexpr auto KUNAI_XCHANGE = 2;          //!< 弾かれた後の1フレーム当たりのX移動量
   constexpr auto KUNAI_YCHANGE = 4;          //!< 弾かれた後の1フレーム当たりのY移動量
}