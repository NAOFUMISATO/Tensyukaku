/*****************************************************************//**
 * \file   ModeBase.h
 * \brief  各モードのベースクラス
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include   <string>
#include   <tuple>
#include   <utility>
#include   <unordered_map>
//二重インクルード防止
class ModeServer;
class Game;
/** モードベース */
class ModeBase
{
public:
   /**
    * \brief コンストラクタ
    */
   ModeBase();
   /**
    * \brief デストラクタ
    */
   virtual ~ModeBase();
   /**
    * \brief   初期化関数
    * \param g ゲームクラスの参照
    */
   virtual bool Initialize(Game& g);
   /**
    * \brief   終了関数
    * \param g ゲームクラスの参照
    */
   virtual bool Terminate(Game& g);
   /**
    * \brief   更新関数
    * \param g ゲームクラスの参照
    */
   virtual bool Process(Game& g);
   /**
    * \brief   描画関数
    * \param g ゲームクラスの参照
    */
   virtual bool Draw(Game& g);

protected:
   int _grhandle;    //!< 画像ハンドル
   int _x;           //!< 描画点X座標
   int _y;           //!< 描画点Y座標
   int _cnt;         //!< 動作カウンタ
   int _mode_cnt;    //!< 経過時間記録変数
   int _pal;         //!< BlendMode用変数
   bool _trans_flag; //!< DrawRotaGraphの透明度フラグ
   std::pair<double, double> _drg;  //!< DrawRotaGraph用ペア変数（first拡縮率、second角度）
   std::tuple<int, int, int> _rgb;  //!< Color用タプル型変数
   std::unordered_map<std::string, std::vector<int>> _grall; //!< 全ての画像ハンドルマップ
   std::unordered_map<std::string, int> _anime;              //!< アニメーションマップ
   std::unordered_map<std::string, int> _se;                 //!< SEマップ
   std::unordered_map<std::string, int> _vpal;               //!< ボリュームマップ

private:
   friend ModeServer;
   /**
    * \brief モードサーバー用
    * \param tmNow 現在の時間
    */
   void StepTime(unsigned long tmNow);
   /**
    * \brief モードサーバー用
    */
   void StepCount();
   std::string _sz_name;          //!< モードサーバー用
   int _uid;                      //!< モードサーバー用
   int _layer;                    //!< モードサーバー用
   int _cnt_mode;                 //!< 本モードに入ってからのカウンタ, 0スタート
   unsigned long _tm_mode;        //!< 本モードに入ってからの時間。ms
   unsigned long _tm_step;        //!< 前フレームからの経過時間。ms
   unsigned long _tm_mode_base;   //!< このモードが始まった時間。ms
   unsigned long _tm_pause_base;  //!< ポーズ中のベース時間。ms
   unsigned long _tm_pause_step;  //!< ポーズ中の積算時間。ms 動作中、この値を _tmMode に用いる
   unsigned long _tm_old_frame;   //!< 前フレームの時間。ms
};