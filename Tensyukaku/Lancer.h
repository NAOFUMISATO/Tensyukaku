#pragma once
/*
   槍兵
*/
#include "EnemyBase.h"
class Lancer :public EnemyBase {
public:
   //槍兵のコンストラクタ    :   引数（X座標,Y座標,反転判定）
   Lancer(int x, int y, bool flip);
   ~Lancer();
   virtual ENEMYTYPE   GetEneType() { return ENEMYTYPE::LANCER; }
   //初期化
   void   Init()override;
   //更新
   void   Process(Game& g)override;
   //描画
   void   Draw(Game& g)override;
   //オブジェクトの消去
   void   Delete(Game& g)override;

private:
   //出現状態時の処理
   void   Appear(Game& g);
   //巡回状態時の処理
   void   Patrol(Game& g);   
   //追跡状態時の処理
   void   Coming(Game& g);   
   //攻撃状態時の処理
   void   Attack(Game& g);
   //死亡状態時の処理
   void   Dead(Game& g);
   //被ダメ判定&押し出しの処理
   void   HitJudge(Game& g);
   //画像読み込み関数
   void   LoadPicture();
   //SE読み込み関数
   void   LoadSE();   
   //効果音ボリューム初期値設定関数
   void   VolumeInit();
   //ボリューム変更関数
   void   VolumeChange();   
   //デバッグ用関数
   void   DebugDraw(Game& g);
};

namespace LInfo {
   /*----------盾兵の各座標関係----------*/
   constexpr auto GRAPHPOINT_X = 0;                        //X位置から描画点までの差分
   constexpr auto GRAPHPOINT_Y = -315;                     //Y位置から描画点までの差分
   constexpr auto POSITION_HITX = -45;                     //描画点から当たり判定左上座標までの差分
   constexpr auto POSITION_HITY = -135;                     //描画点から当たり判定左上座標までの差分
   constexpr auto COLLISION_WIDTH = 90;                  //当たり判定横幅
   constexpr auto COLLISION_HEIGHT = 450;               //当たり判定縦幅

   /*----------各モーションの当たり判定関係----------*/
   constexpr auto PATROL_WIDTH = 600;                     //索敵範囲当たり判定横幅
   constexpr auto PATROL_BACKWIDTH = 300;            //背部索敵範囲当たり判定横幅
   constexpr auto PATROL_HEIGHT = 100;                  //索敵範囲当たり判定縦幅
   constexpr auto COMING_WIDTH = 450;                     //攻撃発生範囲当たり判定横幅
   constexpr auto COMING_HEIGHT = 100;                  //攻撃発生範囲当たり判定縦幅
   constexpr auto ATTACK_WIDTH = 350;                     //攻撃当たり判定横幅
   constexpr auto ATTACK_HEIGHT = 150;                     //攻撃当たり判定縦幅
   constexpr auto COMINGCANCEL_WIDTH = 1000;      //追跡中止当たり判定横幅
   constexpr auto COMINGCANCEL_HEIGHT = 100;      //追跡中止当たり判定縦幅
   constexpr auto ATTACKCANCEL_WIDTH = 350;         //攻撃中止当たり判定横幅
   constexpr auto ATTACKCANCEL_HEIGHT = 100;      //攻撃中止当たり判定縦幅

   /*----------パラメーター関係----------*/
   constexpr auto LIFE_MAX = 1;                     //体力
   constexpr auto SPEED = 2;                           //移動速度
   constexpr auto PLAYER_IAI_MAX = 5;            //プレイヤーの居合最大値

   /*----------画像読み込み&アニメーション&判定フレーム関係----------*/
   //共通
   constexpr auto GRAPH_WIDTH = 840;         //1枚当たりの画像サイズ（横）
   constexpr auto GRAPH_HEIGHT = 630;         //1枚当たりの画像サイズ（縦）
   constexpr auto GRAPH_SCALE = 1.0;            //拡大率
   constexpr auto GRAPH_ANGLE = 0;               //角度
   //出現
   constexpr auto APPEAR_GRAPHNAME = "res/Lancer/L_Stand.png";   //画像ファイル名
   constexpr auto APPEAR_ANIMEMAX = 1;            //全ての画像枚数
   constexpr auto APPEAR_WIDTHCOUNT = 1;      //横の画像枚数
   constexpr auto APPEAR_HEIGHTCOUNT = 1;      //縦の画像枚数
   constexpr auto ANIMESPEED_APPEAR = 60;      //アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto FADEIN_SPEED = 4;                     //アッパー時のフェードインスピード
   constexpr auto APPEAR_ALLFRAME = 60;            //出現全フレーム
   //巡回
   constexpr auto PATROL_GARAPHNAME = "res/Lancer/L_Stand.png";   //画像ファイル名
   constexpr auto PATROL_ANIMEMAX = 1;            //全ての画像枚数
   constexpr auto PATROL_WIDTHCOUNT = 1;      //横の画像枚数
   constexpr auto PATROL_HEIGHTCOUNT = 1;      //縦の画像枚数
   constexpr auto ANIMESPEED_PATROL = 5;         //アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto PATROL_TURNFRAME = 180;      //巡回の振り向きフレーム
   //追跡
   constexpr auto COMING_GRAPHNAME = "res/Lancer/L_Walk.png";   //画像ファイル名
   constexpr auto COMING_ANIMEMAX = 4;            //全ての画像枚数
   constexpr auto COMING_WIDTHCOUNT = 4;      //横の画像枚数
   constexpr auto COMING_HEIGHTCOUNT = 1;      //縦の画像枚数   
   constexpr auto ANIMESPEED_COMING = 30;      //アニメスピード（何フレームごとに画像を切り替えるか）
   //攻撃
   constexpr auto ATTACK_GRAPHNAME = "res/Lancer/L_Attack.png";   //画像ファイル名
   constexpr auto ATTACK_ANIMEMAX = 6;            //全ての画像枚数
   constexpr auto ATTACK_WIDTHCOUNT = 6;         //横の画像枚数
   constexpr auto ATTACK_HEIGHTCOUNT = 1;      //縦の画像枚数
   constexpr auto ANIMESPEED_ATTACK = 15;      //アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto ATTACK_ANIMEFRAME = ATTACK_ANIMEMAX * ANIMESPEED_ATTACK;      //アニメーションフレーム（全ての画像枚数×アニメスピード）
   constexpr auto ATTACK_ALLFRAME = 110;         //攻撃全フレーム（全フレーム-アニメーションフレーム＝攻撃猶予時間）
   constexpr auto ATTACK_BEGINFRAME = 45;      //攻撃判定発生フレーム
   constexpr auto ATTACK_ENDFRAME = 15;         //攻撃判定終了フレーム
   constexpr auto RESERVE_PARFRAME = 15;
   constexpr auto STEP_BEGINFRAME = 45;            //攻撃時の移動開始フレーム
   constexpr auto ATTACK_STEP = 60;                     //攻撃時の移動距離
   //死亡
   constexpr auto DEAD_GRAPHNAME = "res/Lancer/L_Dead.png";      //画像ファイル名
   constexpr auto DEAD_ANIMEMAX = 3;               //全ての画像枚数
   constexpr auto DEAD_WIDTHCOUNT = 3;            //横の画像枚数
   constexpr auto DEAD_HEIGHTCOUNT = 1;         //縦の画像枚数
   constexpr auto ANIMESPEED_DEAD = 20;            //アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto DEAD_ANIMEFRAME = DEAD_ANIMEMAX * ANIMESPEED_DEAD;      //アニメーションフレーム（全ての画像枚数×アニメスピード）
   constexpr auto DEAD_ALLFRAME = 120;            //死亡全フレーム
   constexpr auto FADEOUT_SPEED = 4;               //フェードアウトスピード
}