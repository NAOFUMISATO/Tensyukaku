/*****************************************************************//**
 * \file   ModeGame.h
 * \brief  モードインゲームクラス（モードベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ModeBase.h"
#include "BackGround.h"
#include "Player.h"
#include "GimikPlacement.h"
#include "EnemySpawn.h"
#include "EventHappen.h"
/** モードインゲーム */
class ModeGame : public ModeBase
{
   typedef ModeBase base;
public:
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
   /**
    * \brief  オブジェクト処理のストップ判定を返す関数
    * \return オブジェクト処理のストップ判定
    */
   bool GetstopObjProcess() { return _stop_obj_process; }
   /**
    * \brief                オブジェクト処理のストップ判定の設定関数
    * \param stopobjprocess オブジェクト処理のストップ判定
    */
   void SetStopObjProcess(bool stopobjprocess) { _stop_obj_process = stopobjprocess; }

private:
   int _player_y;                  //!< インスタンス生成されるプレイヤーの初期Y座標
   int _player_x;                  //!< インスタンス生成されるプレイヤーの初期X座標
   bool _player_flip;              //!< インスタンス生成されるプレイヤーの初期反転判定
   bool _stop_obj_process;         //!< オブジェクト処理のストップ判定
   BackGround _bg;                 //!< 背景クラス変数
   GimikPlacement* _gimikplacement;//!< ギミックの配置クラス変数
   EnemySpawn* _enemyspawn;        //!< 敵スポーンブロックの配置クラス変数
   EventHappen* _eventhappen;      //!< イベントブロックの配置クラス変数
};