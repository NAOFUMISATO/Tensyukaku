/*****************************************************************//**
 * \file   CPointBlock.h
 * \brief  チェックポイントブロッククラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "ObjectBase.h"
/** チェックポイントブロック */
class CPointBlock :public ObjectBase {
public:
   /**
    * \brief            コンストラクタ
    * \param cpointtype チェックポイントブロックの種別文字列
    */
   CPointBlock(std::string  cpointtype);
   /**
    * \brief デストラクタ
    */
   ~CPointBlock();
   /**
    * \brief                           純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::CPOINTBLOCK  オブジェクトの種別（チェックポイントブロック）を返す
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::CPOINTBLOCK; }
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
   /**
    * \brief   オブジェクトの消去関数
    * \param g ゲームの参照
    */
   void Delete(Game& g)override;

private:
   /**
    * \brief 種別ごとの座標設定関数
    */
   void PositionSetting();

   std::string  _cpoint_type;    //!< チェックポイントブロック種別を指定する文字列
};
//チェックポイント
namespace CPInfo {
   constexpr auto CPOINT_2A_X = 3600;     //!< チェックポイントブロック種別"2A"のX座標
   constexpr auto CPOINT_2A_Y = 8600;     //!< チェックポイントブロック種別"2A"のY座標
   constexpr auto CPOINT_3A_X = 250;      //!< チェックポイントブロック種別"3A"のX座標
   constexpr auto CPOINT_3A_Y = 7840;     //!< チェックポイントブロック種別"3A"のY座標
   constexpr auto CPOINT_4A_X = 5600;     //!< チェックポイントブロック種別"4A"のX座標
   constexpr auto CPOINT_4A_Y = 7080;     //!< チェックポイントブロック種別"4A"のY座標
   constexpr auto CPOINT_5A_X = 250;      //!< チェックポイントブロック種別"5A"のX座標
   constexpr auto CPOINT_5A_Y = 6320;     //!< チェックポイントブロック種別"5A"のY座標
   constexpr auto CPOINT_5B_X = 5500;     //!< チェックポイントブロック種別"5B"のX座標
   constexpr auto CPOINT_5B_Y = 6320;     //!< チェックポイントブロック種別"5B"のY座標
   constexpr auto CPOINT_8A_X = 5000;     //!< チェックポイントブロック種別"8A"のX座標
   constexpr auto CPOINT_8A_Y = 4040;     //!< チェックポイントブロック種別"8A"のY座標
   constexpr auto CPOINT_11A_X = 5600;    //!< チェックポイントブロック種別"11A"のX座標
   constexpr auto CPOINT_11A_Y = 1760;    //!< チェックポイントブロック種別"11A"のY座標
}