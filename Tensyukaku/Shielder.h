/*****************************************************************//**
 * \file   Shielder.h
 * \brief  盾兵のクラス（エネミーベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "EnemyBase.h"
/** 盾兵 */
class Shielder :public EnemyBase {
public:
   /**
    * \brief      コンストラクタ
    * \param x    X座標
    * \param y    Y座標
    * \param flip 反転判定
    */
   Shielder( int x, int y, bool flip);
   /**
    * \brief デストラクタ
    */
   ~Shielder();
   /**
    * \brief                      純粋仮想関数のオーバーライド
    * \return ENEMYTYPE::SHIELDER オブジェクトの種別（盾兵）を返す
    */
   virtual ENEMYTYPE   GetEneType() { return ENEMYTYPE::SHIELDER; }
   /**
    * \brief 初期化関数
    */
   void   Init()override;
   /**
    * \brief   更新関数
    * \param g ゲームの参照
    */
   void   Process(Game& g)override;
   /**
    * \brief   描画関数
    * \param g ゲームの参照
    */
   void   Draw(Game& g)override;
   /**
    * \brief   オブジェクトの消去関数
    * \param g ゲームの参照
    */
   void   Delete(Game& g)override;

private:
  /**
   * \brief   出現状態関数
   * \param g ゲームの参照
   */
   void   Appear(Game& g);
   /**
    * \brief   巡回状態関数
    * \param g ゲームの参照
    */
   void   Patrol(Game& g);
   /**
    * \brief   追跡状態関数
    * \param g ゲームの参照
    */
   void   Coming(Game& g);
   /**
    * \brief   攻撃状態関数
    * \param g ゲームの参照
    */
   void   Attack(Game& g);
   /**
    * \brief   盾持ち攻撃状態関数
    * \param g ゲームの参照
    */
   void   GuardAttack(Game& g);
   /**
    * \brief   盾崩し状態関数
    * \param g ゲームの参照
    */
   void   GuardBreak(Game& g);
   /**
    * \brief   死亡状態関数
    * \param g ゲームの参照
    */
   void   Dead(Game& g);
   /**
    * \brief   各当たり判定関数
    * \param g ゲームの参照
    */
   void   HitJudge(Game& g);
   /**
    * \brief   盾の描画関数
    * \param g ゲームの参照
    */
   void   ShieldDraw(Game& g);
   /**
    * \brief 画像読み込み関数
    */
   void   LoadPicture();
   /**
    * \brief SE読み込み関数
    */
   void   LoadSE();
   /**
    * \brief 効果音ボリューム初期値設定関数
    */
   void   VolumeInit();
   /**
    * \brief ボリューム変更関数
    */
   void   VolumeChange();
   /**
    * \brief   デバッグ描画関数
    * \param g ゲームの参照
    */
   void   DebugDraw(Game& g);

   bool _ShieldAppear_Flag;   //!< 盾の出現フラグ
   bool _ShieldAlive_Flag;    //!< 盾の生存フラグ
   bool _ShieldAttack_Flag;   //!< 盾保持時の攻撃フラグ
   bool _ShieldBreak_Flag;    //!< 盾崩しフラグ
   bool _ShieldDraw_Flag;     //!< 盾の描画フラグ
   int _Shield_Cnt;           //!< 盾用の動作カウンタ保存変数

};
/** 盾兵クラス用定数 */
namespace SInfo {
   /*----------盾兵の各座標関係----------*/
   constexpr auto GRAPHPOINT_X = 0;            //!< X位置から描画点までの差分
   constexpr auto GRAPHPOINT_Y = -315;         //!< Y位置から描画点までの差分
   constexpr auto POSITION_HITX = -45;         //!< 描画点から当たり判定左上座標までの差分
   constexpr auto POSITION_HITY = -135;        //!< 描画点から当たり判定左上座標までの差分
   constexpr auto COLLISION_WIDTH = 90;        //!< 当たり判定横幅
   constexpr auto COLLISION_HEIGHT = 450;      //!< 当たり判定縦幅
   
   /*----------各モーションの当たり判定関係----------*/
   constexpr auto PATROL_WIDTH = 600;          //!< 索敵範囲当たり判定横幅
   constexpr auto PATROL_BACKWIDTH = 300;      //!< 背部索敵範囲当たり判定横幅
   constexpr auto PATROL_HEIGHT = 100;         //!< 索敵範囲当たり判定縦幅
   constexpr auto COMING_WIDTH = 450;          //!< 攻撃発生範囲当たり判定横幅
   constexpr auto COMING_HEIGHT = 100;         //!< 攻撃発生範囲当たり判定縦幅
   constexpr auto ATTACK_WIDTH = 350;          //!< 攻撃当たり判定横幅
   constexpr auto ATTACK_HEIGHT = 150;         //!< 攻撃当たり判定縦幅
   constexpr auto COMINGCANCEL_WIDTH = 1000;   //!< 追跡中止当たり判定横幅
   constexpr auto COMINGCANCEL_HEIGHT = 100;   //!< 追跡中止当たり判定縦幅
   constexpr auto ATTACKCANCEL_WIDTH = 350;    //!< 攻撃中止当たり判定横幅
   constexpr auto ATTACKCANCEL_HEIGHT = 100;   //!< 攻撃中止当たり判定縦幅

   /*----------パラメーター関係----------*/
   constexpr auto LIFE_MAX = 1;                //!< 体力
   constexpr auto SPEED = 1;                   //!< 移動速度
   constexpr auto PLAYER_IAI_MAX = 5;          //!< プレイヤーの居合最大値

   /*----------画像読み込み&アニメーション&判定フレーム関係----------*/
   //共通
   constexpr auto GRAPH_WIDTH = 840;           //!< 1枚当たりの画像サイズ（横）
   constexpr auto GRAPH_HEIGHT = 630;          //!< 1枚当たりの画像サイズ（縦）
   constexpr auto GRAPH_SCALE = 1.0;           //!< 拡大率
   constexpr auto GRAPH_ANGLE = 0;             //!< 角度
   //出現
   constexpr auto APPEAR_GRAPHNAME = "res/Shielder/T_Stand.png";   //!< 画像ファイル名
   constexpr auto APPEAR_ANIMEMAX = 1;         //!< 全ての画像枚数
   constexpr auto APPEAR_WIDTHCOUNT = 1;       //!< 横の画像枚数
   constexpr auto APPEAR_HEIGHTCOUNT = 1;      //!< 縦の画像枚数
   constexpr auto ANIMESPEED_APPEAR = 60;      //!< アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto FADEIN_SPEED = 4;            //!< アッパー時のフェードインスピード
   constexpr auto APPEAR_ALLFRAME = 60;        //!< 出現全フレーム
   //巡回
   constexpr auto PATROL_GARAPHNAME = "res/Shielder/T_Stand.png";   //!< 画像ファイル名
   constexpr auto PATROL_ANIMEMAX = 1;         //!< 全ての画像枚数
   constexpr auto PATROL_WIDTHCOUNT = 1;       //!< 横の画像枚数
   constexpr auto PATROL_HEIGHTCOUNT = 1;      //!< 縦の画像枚数
   constexpr auto ANIMESPEED_PATROL = 5;       //!< アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto PATROL_TURNFRAME = 180;      //!< 巡回の振り向きフレーム
   //追跡
   constexpr auto COMING_GRAPHNAME = "res/Shielder/T_Walk.png";   //!< 画像ファイル名
   constexpr auto COMING_ANIMEMAX = 4;         //!< 全ての画像枚数
   constexpr auto COMING_WIDTHCOUNT = 4;       //!< 横の画像枚数
   constexpr auto COMING_HEIGHTCOUNT = 1;      //!< 縦の画像枚数
   constexpr auto ANIMESPEED_COMING = 30;      //!< アニメスピード（何フレームごとに画像を切り替えるか）
   //攻撃
   constexpr auto ATTACK_GRAPHNAME = "res/Shielder/T_Attack.png";   //!< 画像ファイル名
   constexpr auto ATTACK_ANIMEMAX = 6;        //!< 全ての画像枚数
   constexpr auto ATTACK_WIDTHCOUNT = 6;      //!< 横の画像枚数
   constexpr auto ATTACK_HEIGHTCOUNT = 1;     //!< 縦の画像枚数
   constexpr auto ANIMESPEED_ATTACK = 15;     //!< アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto ATTACK_ANIMEFRAME = ATTACK_ANIMEMAX * ANIMESPEED_ATTACK;      //!< アニメーションフレーム（全ての画像枚数×アニメスピード）
   constexpr auto ATTACK_ALLFRAME = 110;      //!< 攻撃全フレーム（全フレーム-アニメーションフレーム＝攻撃猶予時間）
   constexpr auto ATTACK_BEGINFRAME = 45;     //!< 攻撃判定発生フレーム
   constexpr auto ATTACK_ENDFRAME = 15;       //!< 攻撃判定終了フレーム
   constexpr auto STEP_BEGINFRAME = 45;       //!< 攻撃時の移動開始フレーム
   constexpr auto ATTACK_STEP = 60;           //!< 攻撃時の移動距離
   //盾持ち攻撃
   constexpr auto GUARDATTACK_GRAPHNAME = "res/Shielder/T_GuardAttack.png";   //!< 画像ファイル名
   constexpr auto GUARDATTACK_ANIMEMAX = 6;   //!< 全ての画像枚数
   constexpr auto GUARDATTACK_WIDTHCOUNT = 6; //!< 横の画像枚数
   constexpr auto GUARDATTACK_HEIGHTCOUNT = 1;//!< 縦の画像枚数
   constexpr auto ANIMESPEED_GUARDATTACK = 15;//!< アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto GUARDATTACK_ANIMEFRAME = GUARDATTACK_ANIMEMAX * ANIMESPEED_GUARDATTACK;//!< アニメーションフレーム（全ての画像枚数×アニメスピード）
   constexpr auto GUARDATTACK_ALLFRAME = 120; //!< 攻撃全フレーム（全フレーム-アニメーションフレーム＝攻撃猶予時間）
   constexpr auto GUARDATTACK_BEGINFRAME = 45;//!< 攻撃判定発生フレーム
   constexpr auto GUARDATTACK_ENDFRAME = 15;  //!< 攻撃判定終了フレーム
   //盾崩し
   constexpr auto GUARDBREAK_GRAPHNAME = "res/Shielder/T_Damage.png";   //!< 画像ファイル名
   constexpr auto GUARDBREAK_ANIMEMAX = 3;    //!< 全ての画像枚数
   constexpr auto GUARDBREAK_WIDTHCOUNT = 3;  //!< 横の画像枚数
   constexpr auto GUARDBREAK_HEIGHTCOUNT = 1; //!< 縦の画像枚数
   constexpr auto ANIMESPEED_GUARDBREAK = 15; //!< アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto GUARDBREAK_ANIMEFRAME = GUARDBREAK_ANIMEMAX * ANIMESPEED_GUARDBREAK; //!< アニメーションフレーム（全ての画像枚数×アニメスピード）
   constexpr auto GUARDBREAK_ALLFRAME = 55;   //!< 被ダメ全フレーム
   //死亡
   constexpr auto DEAD_GRAPHNAME = "res/Shielder/T_Dead.png";      //!< 画像ファイル名
   constexpr auto DEAD_ANIMEMAX = 3;          //!< 全ての画像枚数
   constexpr auto DEAD_WIDTHCOUNT = 3;        //!< 横の画像枚数
   constexpr auto DEAD_HEIGHTCOUNT = 1;       //!< 縦の画像枚数
   constexpr auto ANIMESPEED_DEAD = 20;       //!< アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto DEAD_ANIMEFRAME = DEAD_ANIMEMAX * ANIMESPEED_DEAD;      //!< アニメーションフレーム（全ての画像枚数×アニメスピード）
   constexpr auto DEAD_ALLFRAME = 120;        //!< 死亡全フレーム
   constexpr auto FADEOUT_SPEED = 4;          //!< フェードアウトスピード
   
   /*----------盾の座標関係----------*/
   constexpr auto SHIELD_GRAPH_POINTX = 0;       //!< X位置から描画点までの差分
   constexpr auto SHIELD_GRAPH_POINTY = -120;    //!< Y位置から描画点までの差分
   constexpr auto SHIELD_POSITION_HITX = -45;    //!< 描画点から当たり判定左上座標までの差分
   constexpr auto SHIELD_POSITION_HITY = -135;   //!< 描画点から当たり判定左上座標までの差分
   constexpr auto SHIELD_COLLISION_WIDTH = 90;   //!< 当たり判定横幅
   constexpr auto SHIELD_COLLISION_HEIGHT = 450; //!< 当たり判定縦幅

   /*----------盾の挙動関係----------*/
   constexpr auto SHIELD_ANGLE = -0.0;           //!< 盾の初期角度
   constexpr auto SHIELD_DIFFPOINTX = -0;        //!< 盾の盾兵からの描画差分X座標
   constexpr auto SHIELD_DIFFPOINTY = -55;       //!< 盾の盾兵からの描画差分Y座標
   constexpr auto SHIELD_ALPHA = 255;            //!< 盾の初期透明度
   constexpr auto SHIELD_ANGLECHANGE = 0.03;     //!< 盾弾かれ時の角度変化値
   constexpr auto SHIELD_ALPHACHANGE = 5;        //!< 盾弾かれ時の透明度変化値
   constexpr auto SHIELD_XCHANGE = 1;            //!< 盾弾かれ時のX座標変化値
   constexpr auto SHIELD_YCHANGE = 5;            //!< 盾弾かれ時のY座標変化値
};