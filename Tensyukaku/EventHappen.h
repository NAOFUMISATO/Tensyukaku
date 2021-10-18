/*****************************************************************//**
 * \file   EventHappen.h
 * \brief  イベントブロックのインスタンス生成クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
//二重インクルード防止
class Game;
/** イベントブロックのインスタンス生成 */
class EventHappen {
public:
   /**
    * \brief   コンストラクタ
    * \param g ゲームの参照
    */
   EventHappen(Game& g);
   /**
    * \brief デストラクタ
    */
   ~EventHappen();
   /**
    * \brief   初期化関数
    * \param g ゲームの参照
    */
   void Init(Game& g);

private:
   /**
    * \brief   チュートリアルボード生成関数
    * \param g ゲームの参照
    */
   void TutorialAppear(Game& g);
   /**
    * \brief   チェックポイントブロック生成関数
    * \param g ゲームの参照
    */
   void CPointAppear(Game& g);
   /**
    * \brief   ボスイベントブロック生成関数
    * \param g ゲームの参照
    */
   void BossEventAppear(Game& g);
   /**
    * \brief   インゲームでの階層表示ブロック生成関数
    * \param g ゲームの参照
    */
   void IngameTextAppear(Game& g);
   /**
    * \brief   回復ポイントブロック生成関数
    * \param g ゲームの参照
    */
   void RecoveryAppear(Game& g);
   /**
    * \brief   炎演出ブロック生成関数
    * \param g ゲームの参照
    */
   void FlameAppear(Game& g);
};
/** イベントブロックのインスタンス生成クラス用定数 */
namespace EHInfo {
   /*----------各イベントブロック座標等----------*/
   constexpr auto BOSSA_NUM = 1;
   constexpr auto BOSSB_NUM = 2;
   //炎演出ブロック
   constexpr auto FLAME_X = 500;
   constexpr auto FLAME_Y = 1760;
}