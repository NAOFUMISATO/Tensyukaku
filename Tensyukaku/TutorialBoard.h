/*****************************************************************//**
 * \file   TutorialBoard.h
 * \brief  チュートリアルボードクラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include  "ObjectBase.h"
/** チュートリアルボード */
class TutorialBoard :public ObjectBase {
public:
   /**
    * \brief              コンストラクタ
    * \param tutorialtype チュートリアルの種別文字列
    */
   TutorialBoard(std::string tutorialtype);
   /**
    * \brief デストラクタ
    */
   ~TutorialBoard();
   /**
    * \brief                            純粋仮想関数のオーバーライド
    * \return OBJECTTYPE::TUTORIALBOARD オブジェクトの種別（チュートリアルボード）を返す
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::TUTORIALBOARD; }
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
    * \brief チュートリアルボードの種別による座標設定関数
    */
   void PositionSetting();

   std::string  _tutorial_type;   //!< チュートリアルの種別を指定する文字列
   bool _tutorialhit_flag;        //!< チュートリアルに当たっているかのフラグ
};
/** チュートリアルボードクラス用定数 */
namespace TBInfo{
   constexpr auto TUTORIAL1A_X = 800;   //!< チュートリアルボード種別"1A"のX座標
   constexpr auto TUTORIAL1A_Y = 9360;  //!< チュートリアルボード種別"1A"のY座標
   constexpr auto TUTORIAL1B_X = 1200;  //!< チュートリアルボード種別"1B"のX座標
   constexpr auto TUTORIAL1B_Y = 9360;  //!< チュートリアルボード種別"1B"のY座標
   constexpr auto TUTORIAL2A_X = 3200;  //!< チュートリアルボード種別"2A"のX座標
   constexpr auto TUTORIAL2A_Y = 8600;  //!< チュートリアルボード種別"2A"のY座標
   constexpr auto TUTORIAL3A_X = 500;   //!< チュートリアルボード種別"3A"のX座標
   constexpr auto TUTORIAL3A_Y = 7840;  //!< チュートリアルボード種別"3A"のY座標
   constexpr auto TUTORIAL3B_X = 2200;  //!< チュートリアルボード種別"3B"のX座標
   constexpr auto TUTORIAL3B_Y = 7840;  //!< チュートリアルボード種別"3B"のY座標
   constexpr auto TUTORIAL4A_X = 5200;  //!< チュートリアルボード種別"4A"のX座標
   constexpr auto TUTORIAL4A_Y = 7080;  //!< チュートリアルボード種別"4A"のY座標
   constexpr auto TUTORIAL5A_X = 3800;  //!< チュートリアルボード種別"5A"のX座標
   constexpr auto TUTORIAL5A_Y = 6320;  //!< チュートリアルボード種別"5A"のY座標
}