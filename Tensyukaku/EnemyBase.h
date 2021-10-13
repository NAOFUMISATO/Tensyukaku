/*****************************************************************//**
 * \file   EnemyBase.h
 * \brief  敵のベースクラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
class EnemyBase : public ObjectBase {
protected:
   //敵の状態列挙
   enum class ENEMYSTATE { 
      APPEAR,               //出現
      PATROL,               //索敵
      COMING,               //追跡
      ATTACK,               //攻撃
      GUARDATTACK,   //盾持ち攻撃   (盾兵のみ)
      THROW,               //クナイ投げ   (忍者のみ)
      GUARDBREAK,      //盾崩れ         (盾兵のみ)
      DAMAGE,               //被ダメ         (武士、武将のみ)
      DEAD                     //死亡 
   };
public:
   EnemyBase();
   ~EnemyBase();
   virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::ENEMY; }
   //敵の種類列挙
   enum class ENEMYTYPE {
      BUSHI,               //武士
      BUSYO,               //武将
      NINJA,               //忍者
      ZYOUNIN,         //上忍
      LANCER,            //槍兵
      SHIELDER         //盾兵
   };
   //純粋仮想関数
   virtual ENEMYTYPE GetEneType() = 0;
   //初期化
   virtual   void   Init();
   //更新
   virtual   void   Process(Game& g);
   //描画
   virtual   void   Draw(Game& g);
   //オブジェクトの消去
   virtual   void   Delete(Game& g) {};

protected:
   ENEMYTYPE _type;            //敵の種類変数
   ENEMYSTATE _state;         //状態遷移変数
};

