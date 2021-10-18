/*****************************************************************//**
 * \file   Cursor.h
 * \brief  タイトルカーソルクラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** タイトルカーソル */
class Cursor :public ObjectBase {
public:
   /**
    * \brief コンストラクタ
    */
   Cursor();
   /**
    * \brief デストラクタ
    */
   ~Cursor();
   /**
    * \brief                       //純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::CURSOR   //オブジェクトの種別（タイトルカーソル）を返す
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::CURSOR; }
   /**
    * \brief 初期化関数
    */
   void Init()override;
   /**
    * \brief   更新関数
    * \param g ゲームの参照
    */
   void Process(Game& g)override;
   /**
    * \brief   描画関数
    * \param g ゲームの参照
    */
   void Draw(Game& g)override;

private:
   /**
    * \brief   各当たり判定関数
    * \param g ゲームの参照
    */
   void HitJudge(Game& g);
   /**
    * \brief 効果音読み込み関数
    */
   void LoadSE();
   /**
    * \brief 効果音ボリューム初期値設定関数
    */
   void VolumeInit();
   /**
    * \brief ボリューム変更関数
    */
   void VolumeChange();
   /** カーソルの状態列挙 */
   enum class CURSOLSTATE {
      NOHIT,     //!< 何も触れていない
      STARTHIT,  //!< スタートセレクトに触れている
      EXHIT,     //!< 説明画面セレクトに触れている
      ENDHIT,    //!< ゲーム終了セレクトに触れている
      CREDITHIT  //!< クレジットセレクトに触れている
   };

   CURSOLSTATE _state;    //!< カーソルの状態
   Vector2 _velocity_dir; //!< 速度方向
   std::string _hit_type; //!< パーティクルのタイプ指定
   int _par_qty;          //!< パーティクルの1フレーム当たりの量
   bool _input_flag;      //!< 入力管理フラグ
   bool _startpush_flag;  //!< スタートセレクトに触れている状態で特定のボタン押下したかのフラグ
   bool _endpush_flag;    //!< ゲーム終了セレクトに触れている状態で特定のボタン押下したかのフラグ
   bool _creditpush_flag; //!< クレジットセレクトに触れている状態で特定のボタン押下したかのフラグ
};
/** タイトルカーソル用定数 */
namespace CuInfo{
   constexpr auto NOHIT_PARQTY = 7; //何も触れていない状態でのパーティクルの1フレーム当たりの量
   constexpr auto HIT_PARQTY =10;   //何れかのセレクトに触れた状態でのパーティクルの1フレーム当たりの量
}