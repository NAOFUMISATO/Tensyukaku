/*****************************************************************//**
 * \file   EnemySpawn.h
 * \brief  スポーンブロックのインスタンス生成クラス
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
//二重インクルード防止
class Game;
/** スポーンブロックのインスタンス生成 */
class EnemySpawn {
public:
   /**
    * \brief   コンストラクタ
    * \param g ゲームの参照
    */
   EnemySpawn(Game& g);
   /**
    * \brief デストラクタ
    */
   ~EnemySpawn();
   /**
    * \brief   初期化関数
    * \param g ゲームの参照
    */
   void Init(Game& g);
};
