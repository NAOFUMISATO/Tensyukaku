/*****************************************************************//**
 * \file   ObjectBase.h
 * \brief  各オブジェクトのベースクラス
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "HitBox.h"
#include <vector>
#include "Math.h"
#include <utility>
#include <tuple>
#include <unordered_map>
//二重インクルード防止
class Game;
/** 各オブジェクトのベース */
class ObjectBase {
public:
   /**
    * \brief コンストラクタ
    */
   ObjectBase();
   /**
    * \brief デストラクタ
    */
   ~ObjectBase();
   /** オブジェクトの種類列挙 */
   enum class OBJECTTYPE {
      TITLELOGO,       //!< タイトルロゴ
      GAMESTART,       //!< ゲームスタートセレクト
      EXPLAIN,         //!< 説明画面セレクト
      GAMEEND,         //!< ゲーム終了セレクト
      CREDIT,          //!< クレジットセレクト
      CURSOR,          //!< タイトルカーソル
      PLAYER,          //!< プレイヤー
      ENEMY,           //!< 敵
      SHIELD,          //!< 盾
      BOSS,            //!< ボス
      UI,              //!< UI
      PARTICLE,        //!< パーティクル
      EFECT,           //!< エフェクト
      MIDDLEATTACK,    //!< 中段攻撃当たり判定
      LOWATTACK,       //!< 下段攻撃当たり判定
      KICK,            //!< 蹴り当たり判定
      IAI,             //!< 居合当たり判定
      SPECIAL,         //!< 特殊攻撃当たり判定
      PRIVATECOLLISION,//!< 受け側で判定を行わない当たり判定
      BUSHIATTACK,     //!< 武士の攻撃当たり判定
      NINJAATTACK,     //!< 忍者の攻撃当たり判定
      KUNAI,           //!< クナイ当たり判定
      SHIELDERATTACK,  //!< 盾兵の攻撃当たり判定
      LANCERATTACK,    //!< 槍兵の攻撃当たり判定
      BUSYOATTACK,     //!< 武将の攻撃当たり判定
      ZYOUNINATTACK,   //!< 上忍の攻撃当たり判定
      STAIR,           //!< 階段
      BOSSSTAIR,       //!< ボス階段
      RESTPOINT,       //!< 回復ポイント用掛け軸
      POISONNINJA,     //!< 毒液忍者
      POISON,          //!< 毒液
      ANDON,           //!< 行燈
      FLAME,           //!< 行燈の炎
      MUGENANDON,      //!< 無限行燈
      MUGENFLAME,      //!< 無限行燈の無限炎
      TUTORIALBOARD,   //!< チュートリアルボード
      RECOVERYBLOCK,   //!< 回復ブロック
      CPOINTBLOCK,     //!< チェックポイントブロック
      BOSSEVENTBLOCK,  //!< ボスイベントブロック
      FLAMEBLOCK,      //!< 炎演出ブロック
      SPAWNBLOCK,      //!< スポーンブロック
      FLOORTEXTBLOCK   //!< 階層表示ブロック
   };
   /**
    * \brief    純粋仮想関数化
    * \return 0 派生先で定義
    */
   virtual OBJECTTYPE GetObjType() = 0;
   /**
    * \brief 初期化関数
    */
   virtual void Init();
   /**
    * \brief   更新関数
    * \param g ゲームの参照
    */
   virtual void Process(Game& g);
   /**
    * \brief   描画関数
    * \param g ゲームの参照
    */
   virtual void Draw(Game& g);
   /**
    * \brief   当たり判定を行う関数
    * \param o オブジェクトの種類
    */
   virtual bool IsHit(ObjectBase& o);
   /**
    * \brief   オブジェクトの消去関数
    * \param g ゲームの参照
    */
   virtual void Delete(Game& g) {};

   /**
    * \brief     X座標の値を返す関数
    * \return _x X座標
    */
   int GetX() { return _x; }
   /**
    * \brief     Y座標の値を返す関数
    * \return _y Y座標
    */
   int GetY() { return _y; }
   /**
    * \brief        体力の値を返す関数
    * \return _life 体力
    */
   int GetLife() { return _life; }
   /**
    * \brief             居合ゲージの値を返す関数
    * \return _iai_gauge 居合ゲージ
    */
   int GetGauge() { return _iai_gauge; }
   /**
    * \brief       速さの値を返す関数
    * \return _spd 速さ
    */
   int GetSpd() { return _spd; }
   /**
    * \brief        オブジェクトのソート順番の値を返す関数
    * \return _sort オブジェクトのソート順番
    */
   int GetSort() { return _sort; }
   /**
    * \brief          反転判定を返す関数
    * \return _isflip 反転判定
    */
   bool GetFlip() { return _isflip; }
   /**
    * \brief                                              マップチップとの当たり判定用の値を全て返す関数
    * \return {_x,_y,_gx,_gy,_hit_x,_hit_y,_hit_w,_hit_h} マップチップとの当たり判定用各座標関係
    */
   HitBox GetHB() { return { _x,_y,_gx,_gy,_hit_x,_hit_y,_hit_w,_hit_h }; }
   /**
    * \brief            ベクトルでの位置の値を返す関数
    * \return _position ベクトルでの位置
    */
   Vector2 GetPosition() { return _position; }
   /**
    * \brief   X座標の値を設定する関数
    * \param x X座標
    */
   void SetX(int x) { _x = x; }
   /**
    * \brief   Y座標の値を設定する関数
    * \param y Y座標
    */
   void SetY(int y) { _y = y; }
   /**
    * \brief    居合ゲージの値を設定する関数
    * \param ig 居合ゲージ
    */
   void SetGauge(int ig) {_iai_gauge=ig; }
   /**
    * \brief   XYの値を設定する関数
    * \param x X座標
    * \param y Y座標
    */
   void SetPosition(int x, int y) { _x = x; _y = y; }
   /**
    * \brief        反転判定を設定する関数
    * \param isflip 反転判定
    */
   void SetFlip(bool isflip) { _isflip = isflip; }
   /**
    * \brief             ボスイベントA判定を設定する関数
    * \param beventAflag ボスイベントA判定
    */
   void SetBossEventA(bool beventaflag) { _bossevent_a_flag =beventaflag; }
   /**
    * \brief             ボスイベントB判定を設定する関数
    * \param beventBflag ボスイベントB判定
    */
   void SetBossEventB(bool beventbflag) { _bossevent_b_flag =beventbflag; }

protected:
   int _grhandle;         //!< 画像ハンドル
   int _sort;             //!< キャラ描画ソート用変数
   int _x;                //!< X座標（基準位置）
   int _y;                //!< Y座標（基準位置）
   int _gx;               //!< X座標基準位置から描画時の差分
   int _gy;               //!< Y座標基準位置から描画時の差分
   int _w;                //!< 横幅
   int _h;                //!< 縦幅
   int _life;             //!< 体力
   int _spd;              //!< 移動速度
   int _alpha;            //!< 透明度
   int _iai_gauge;        //!< 居合ゲージ
   int _hit_x;            //!< 描画点から左上座標までのX座標差分
   int _hit_y;            //!< 描画点から左上座標までのY座標差分
   int _hit_w;            //!< 当たり判定の横幅
   int _hit_h;            //!< 当たり判定の縦幅
   int _dx;               //!< 描画判定用X座標
   int _dy;               //!< 描画判定用Y座標
   int _debug_alpha;      //!< デバック用矩形透明度
   int _cnt;              //!< 動作カウンタ
   int _action_cnt;       //!< アクション経過時間保存変数
   int _before_x;         //!< 前回のX座標保存変数
   int _before_y;         //!< 前回のY座標保存変数
   bool _draw_flag;       //!< XY座標が画面+一定値以内ならば描画するフラグ
   bool _isflip;          //!< 反転判定
   bool _bossevent_a_flag;//!< ボスイベントAフラグ
   bool _bossevent_b_flag;//!< ボスイベントBフラグ
   bool _debug_fill;      //!< デバッグ用矩形塗りつぶしフラグ
   Vector2 _position;     //!< 位置ベクトル
   std::pair <int, int>_hit_judge;        //!< 当たり判定用変数
   std::pair <double, double>_drg;        //!< DrawRotaGraph用変数
   std::tuple<int, int, int>_debug_color; //!< デバック用矩形カラー
   std::unordered_map<std::string, std::vector<int>> _grall; //!< 全ての画像ハンドルマップ
   std::unordered_map<std::string, int> _anime;              //!< アニメーションマップ
   std::unordered_map<std::string, int> _se;                 //!< SEマップ
   std::unordered_map<std::string, int> _vpal;               //!< ボリュームマップ
};
