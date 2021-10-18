/*****************************************************************//**
 * \file   EnemyBase.h
 * \brief  敵のベースクラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** 敵の基底 */
class EnemyBase : public ObjectBase {
protected:
   /** 敵の状態列挙 */
   enum class ENEMYSTATE {
      APPEAR,       //!< 出現
      PATROL,       //!< 索敵
      COMING,       //!< 追跡
      ATTACK,       //!< 攻撃
      GUARDATTACK,  //!< 盾持ち攻撃(盾兵のみ)
      THROW,        //!< クナイ投げ(忍者のみ)
      GUARDBREAK,   //!< 盾崩れ(盾兵のみ)
      DAMAGE,       //!< 被ダメ(武士、武将のみ)
      DEAD          //!< 死亡
   };

public:
   /**
    * \brief コンストラクタ
    */
   EnemyBase();
   /**
    * \brief デストラクタ
    */
   ~EnemyBase();
   /**
    * \brief                    純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::ENEMY オブジェクトの種別（敵）を返す
    */
   virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::ENEMY; }
   /** 敵の種別列挙 */
   enum class ENEMYTYPE {
      BUSHI,    //武士
      BUSYO,    //武将
      NINJA,    //忍者
      ZYOUNIN,  //上忍
      LANCER,   //槍兵
      SHIELDER  //盾兵
   };
   /**
    * \brief 純粋仮想関数化
    * \return 0
    */
   virtual ENEMYTYPE GetEneType() = 0;
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
    * \brief   オブジェクトの消去関数
    * \param g ゲームの参照
    */
   virtual void Delete(Game& g) {};

protected:
   ENEMYTYPE _type;     //!< 敵の種類変数
   ENEMYSTATE _state;   //!< 状態遷移変数
};

