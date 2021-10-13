#pragma once
/*
   武将クラス
*/
#include "EnemyBase.h"
#include "ObjectBase.h"
#include <vector>
class Busyo : public EnemyBase {
public:
   //武将のコンストラクタ   :   引数（X座標,Y座標,反転判定）
   Busyo(int x, int y, bool flip);
   ~Busyo();
   virtual ENEMYTYPE   GetEneType() { return ENEMYTYPE::BUSYO; }
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
   //被ダメ状態時の処理
   void   Damage(Game& g);
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

namespace BsInfo {
   /*----------武将の各座標関係----------*/
   constexpr auto GRAPHPOINT_X = 0;                  //X位置から描画点までの差分
   constexpr auto GRAPHPOINT_Y = -315;               //Y位置から描画点までの差分
   constexpr auto POSITION_HITX = -45;                  //描画点から当たり判定左上座標までの差分
   constexpr auto POSITION_HITY = -135;               //描画点から当たり判定左上座標までの差分
   constexpr auto COLLISION_WIDTH = 90;            //当たり判定横幅
   constexpr auto COLLISION_HEIGHT = 450;            //当たり判定縦幅

   /*----------各モーションの当たり判定関係----------*/
   constexpr auto PATROL_WIDTH = 500;               //索敵範囲当たり判定横幅
   constexpr auto   PATROL_BACKWIDTH = 250;         //背部索敵範囲当たり判定横幅
   constexpr auto PATROL_HEIGHT = 100;               //索敵範囲当たり判定縦幅
   constexpr auto COMING_WIDTH = 300;               //攻撃発生範囲当たり判定横幅
   constexpr auto COMING_HEIGHT = 100;               //攻撃発生範囲当たり判定縦幅
   constexpr auto ATTACK_WIDTH = 200;                  //攻撃当たり判定横幅
   constexpr auto ATTACK_HEIGHT = 150;               //攻撃当たり判定縦幅
   constexpr auto COMINGCANCEL_WIDTH = 1000;   //追跡中止当たり判定横幅
   constexpr auto COMINGCANCEL_HEIGHT = 100;   //追跡中止当たり判定縦幅
   constexpr auto ATTACKCANCEL_WIDTH = 200;      //攻撃中止当たり判定横幅
   constexpr auto ATTACKCANCEL_HEIGHT = 100;      //攻撃中止当たり判定縦幅

   /*----------パラメーター関係----------*/
   constexpr auto LIFE_MAX = 4;                           //体力
   constexpr auto SPEED = 2;                                 //移動速度
   constexpr auto PLAYER_IAI_MAX = 5;                  //プレイヤーの居合最大値
   /*----------画像読み込み&アニメーション&判定フレーム関係----------*/
   //共通
   constexpr auto GRAPH_WIDTH = 810;                  //1枚当たりの画像サイズ（横）
   constexpr auto GRAPH_HEIGHT = 630;               //1枚当たりの画像サイズ（縦）
   //出現
   constexpr auto APPEAR_GRAPHNAME = "res/Busyo/Bs_Stand.png";   //画像ファイル名
   constexpr auto APPEAR_ANIMEMAX = 1;               //全ての画像枚数
   constexpr auto APPEAR_WIDTHCOUNT = 1;         //横の画像枚数
   constexpr auto APPEAR_HEIGHTCOUNT = 1;         //縦の画像枚数
   constexpr auto ANIMESPEED_APPEAR = 60;         //アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto FADEIN_SPEED = 4;                     //アッパー時のフェードインスピード
   constexpr auto APPEAR_ALLFRAME = 60;            //出現全フレーム
   //巡回
   constexpr auto PATROL_GRAPHNAME = "res/Busyo/Bs_Stand.png";   //画像ファイル名
   constexpr auto PATROL_ANIMEMAX = 1;               //全ての画像枚数
   constexpr auto PATROL_WIDTHCOUNT = 1;         //横の画像枚数
   constexpr auto PATROL_HEIGHTCOUNT = 1;         //縦の画像枚数
   constexpr auto ANIMESPEED_PATROL = 180;         //アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto PATROL_TURNFRAME = 180;         //巡回の振り向きフレーム
   //追跡
   constexpr auto COMING_GRAPHNAME = "res/Busyo/Bs_Walk.png";   //画像ファイル名
   constexpr auto COMING_ANIMEMAX = 4;            //全ての画像枚数
   constexpr auto COMING_WIDTHCOUNT = 4;         //横の画像枚数
   constexpr auto COMING_HEIGHTCOUNT = 1;      //縦の画像枚数   
   constexpr auto ANIMESPEED_COMING = 30;         //アニメスピード（何フレームごとに画像を切り替えるか）
   //攻撃
   constexpr auto ATTACK_GRAPHNAME = "res/Busyo/Bs_Attack.png";   //画像ファイル名
   constexpr auto ATTACK_ANIMEMAX = 4;               //全ての画像枚数
   constexpr auto ATTACK_WIDTHCOUNT = 4;         //横の画像枚数
   constexpr auto ATTACK_HEIGHTCOUNT = 1;         //縦の画像枚数
   constexpr auto ANIMESPEED_ATTACK = 14;         //アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto ATTACK_ANIMEFRAME = ATTACK_ANIMEMAX * ANIMESPEED_ATTACK * 2;      //アニメーションフレーム（全ての画像枚数×アニメスピード）
   constexpr auto ATTACK_ALLFRAME = 142;            //攻撃全フレーム（全フレーム-アニメーションフレーム＝攻撃猶予時間）
   constexpr auto ATTACK_STEP = 60;                     //ステップ距離
   constexpr auto STEP_BEGINFRAME = 14;            //ステップの開始フレーム
   constexpr auto ATTACK_BEGINFRAME = 14;         //攻撃判定発生フレーム
   constexpr auto ATTACK_BEGIN2FRAME = 70;         //2段目攻撃判定発生フレーム
   constexpr auto ATTACK_ENDFRAME = 14;            //攻撃判定終了フレーム
   constexpr auto ATTACK_END2FRAME = 84;            //2段目攻撃判定終了フレーム
   //被ダメ
   constexpr auto DAMAGE_GRAPHNAME = "res/Busyo/Bs_Damage.png";   //画像ファイル名
   constexpr auto DAMAGE_ANIMEMAX = 3;            //全ての画像枚数
   constexpr auto DAMAGE_WIDTHCOUNT = 3;         //横の画像枚数
   constexpr auto DAMAGE_HEIGHTCOUNT = 1;      //縦の画像枚数
   constexpr auto ANIMESPEED_DAMAGE = 9;         //アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto DAMAGE_ANIMEFRAME = DAMAGE_ANIMEMAX * ANIMESPEED_DAMAGE;      //アニメーションフレーム（全ての画像枚数×アニメスピード）
   constexpr auto DAMAGE_ALLFRAME = 27;            //被ダメ全フレーム
   //死亡
   constexpr auto DEAD_GRAPHNAME = "res/Busyo/Bs_Dead.png";      //画像ファイル名
   constexpr auto DEAD_ANIMEMAX = 3;                  //全ての画像枚数
   constexpr auto DEAD_WIDTHCOUNT = 3;            //横の画像枚数
   constexpr auto DEAD_HEIGHTCOUNT = 1;            //縦の画像枚数
   constexpr auto ANIMESPEED_DEAD = 20;            //アニメスピード（何フレームごとに画像を切り替えるか）
   constexpr auto DEAD_ANIMEFRAME = DEAD_ANIMEMAX * ANIMESPEED_DEAD;         //アニメーションフレーム（全ての画像枚数×アニメスピード）
   constexpr auto DEAD_ALLFRAME = 120;               //死亡全フレーム
   constexpr auto FADEOUT_SPEED = 4;                  //フェードアウトスピード
}