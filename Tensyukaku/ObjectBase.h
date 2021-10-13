#pragma once
/*
   各オブジェクトの基底クラス
*/
#include "HitBox.h"
#include <vector>
#include "Math.h"
#include <utility>
#include <tuple>
#include <unordered_map>
class Game;
class ObjectBase {
public:
   ObjectBase();
   ~ObjectBase();
   //オブジェクトの種類列挙
   enum class OBJECTTYPE {
      TITLELOGO,GAMESTART, EXPLAIN,GAMEEND,CREDIT, CURSOR,                                                                                                //ゲームタイトル
      PLAYER, ENEMY,BOSS,                                                                                                                                                         //キャラ
      UI, PARTICLE,EFECT,                                                                                                                                                         //UI&エフェクト
      MIDDLEATTACK, LOWATTACK, KICK, IAI,SPECIAL,                                                                                                                     //プレイヤーの攻撃
      PRIVATECOLLISION,BUSHIATTACK,NINJAATTACK,KUNAI,SHIELDERATTACK,SHIELD, LANCERATTACK,BUSYOATTACK,ZYOUNINATTACK,      //敵の攻撃&索敵範囲等
      STAIR,BOSSSTAIR, RESTPOINT,POISONNINJA,POISON,ANDON,FLAME, MUGENANDON,MUGENFLAME, TUTORIALBOARD,                     //ギミック
      RECOVERYBLOCK,CPOINTBLOCK,BOSSEVENTBLOCK,FLAMEBLOCK, SPAWNBLOCK, EVENTBLOCK,                                                    //各ギミック用当たり判定
   };
   //純粋仮想関数
   virtual OBJECTTYPE   GetObjType() = 0;
   //初期化
   virtual   void      Init();
   //更新
   virtual   void      Process(Game& g);
   //描画
   virtual   void      Draw(Game& g);
   //当たり判定を行う関数
   virtual   bool   IsHit(ObjectBase& o);
   //オブジェクトの消去
   virtual   void      Delete(Game& g) {};

   //Xの値を返す関数
   int   GetX() { return _x; }
   //Yの値を返す関数
   int   GetY() { return _y; }
   //体力の値を返す関数
   int   GetHp() { return _life; }
   //ゲージの値を返す関数
   int   GetGauge() { return _iai_gauge; }
   //速さの値を返す関数
   int   GetSpd() { return _spd; }
   //オブジェクトごとのソート順番を返す関数
   int   GetSort() { return _sort; }
   //反転判定を返す関数
   bool   GetFlip() { return _isflip; }
   //当たり判定用の値を返す関数
   HitBox   GetHB() { return { _x,_y,_gx,_gy,_hit_x,_hit_y,_hit_w,_hit_h }; }
   //ベクトルの値を返す関数
   Vector2   GetPosition() { return _position; }
   //Xの値を設定する関数
   void      SetX(int x) { _x = x; }
   //Yの値を設定する関数
   void      SetY(int y) { _y = y; }
   //ゲージの値を設定する関数
   void      SetGauge(int ig) {_iai_gauge=ig; }
   //XYの値を設定する関数
   void      SetPosition(int x, int y) { _x = x; _y = y; }
   //反転判定を設定する関数
   void      SetFlip(bool isflip) { _isflip = isflip; }
   //ボスイベントA判定を設定する関数
   void      SetBEventA(bool beventAflag) { _bosseventA_flag =beventAflag; }
   //ボスイベントB判定を設定する関数
   void      SetBEventB(bool beventBflag) { _bosseventB_flag =beventBflag; }
   
   
protected:
   int      _grhandle;                                 // 画像ハンドル
   int      _sort;                                       //キャラ描画ソート用変数
   int      _x, _y;                                       // 座標（基準位置）
   int      _gx, _gy;                                    // 基準位置から描画時の差分
   int      _w, _h;                                       // 大きさ
   int      _life;                                       // 体力
   int      _spd;                                       // 移動速度
   int      _alpha;                                    // 透明度
   int      _iai_gauge;                              // 居合ゲージ
   int      _hit_x, _hit_y;                              //描画点から左上座標までの差分
   int      _hit_w, _hit_h;                           //当たり判定の幅
   int      _dx;                                          //描画判定用変数
   int      _dy;                                          //描画判定用変数
   int      _debug_alpha;                           //デバック用矩形透明度
   int      _cnt;                                       //動作カウンタ
   int      _action_cnt;                              //アクション経過時間保存変数
   int      _before_x;                                 //前回のX座標保存変数
   int      _before_y;                                 //前回のY座標保存変数
   bool   _draw_flag;                              //XY座標が画面+一定値以内ならば描画するフラグ
   bool   _isflip;                                       // 反転判定
   bool   _bosseventA_flag;                     //ボスイベントAフラグ
   bool   _bosseventB_flag;                     //ボスイベントBフラグ
   bool   _debug_fill;                              //デバッグ用矩形塗りつぶしフラグ
   Vector2 _position;                              // 位置ベクトル
   std::pair <int, int>_hit_judge;                  //当たり判定用変数
   std::pair <double, double>_drg;            //DrawRotaGraph用変数
   std::tuple<int, int, int>_debug_color;      //デバック用矩形カラー
   std::unordered_map<std::string, std::vector<int>> _grall;   //全ての画像ハンドルマップ
   std::unordered_map<std::string, int> _anime;                  //アニメーションマップ
   std::unordered_map<std::string, int> _se;                        //SEマップ
   std::unordered_map<std::string, int> _vpal;                     //ボリュームマップ
};
