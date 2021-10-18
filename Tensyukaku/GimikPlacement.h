/*****************************************************************//**
 * \file   GimikPlacement.h
 * \brief  ギミック関係のインスタンス生成クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
//二重インクルード防止
class Game;
/** ギミック関係のインスタンス生成 */
class GimikPlacement {
public:
   /**
    * \brief   コンストラクタ
    * \param g ゲームの参照
    */
   GimikPlacement(Game& g);
   /**
    * \brief デストラクタ
    */
   ~GimikPlacement();
   /** 
    * \brief   初期化関数
    * \param g ゲームの参照
    */
   void Init(Game& g);

private:
   /**
    * \brief   階段のインスタンス生成関数
    * \param g ゲームの参照
    */
   void StairAppear(Game& g);
   /**
    * \brief   行燈のインスタンス生成関数
    * \param g ゲームの参照
    */
   void AndonAppear(Game& g);
   /**
    * \brief   回復ポイント用掛け軸インスタンス生成関数
    * \param g ゲームの参照
    */
   void RestObjAppear(Game& g);
};
/** ギミック関係のインスタンス生成クラス定数 */
namespace GInfo {
   /*----------各ギミックの位置&向き----------*/
   //階段
   constexpr auto STAIR1A_X = 3665; /*!<階段種別"1A"のX座標 */  constexpr auto STAIR1A_Y = 9360;  /*!<階段種別"1A"のY座標 */  constexpr auto STAIR1A_FLIP = false; /*!<階段種別"1A"の反転判定 */ 
   constexpr auto STAIR2A_X = 175;  /*!<階段種別"2A"のX座標 */  constexpr auto STAIR2A_Y = 8600;  /*!<階段種別"2A"のY座標 */  constexpr auto STAIR2A_FLIP = true;  /*!<階段種別"2A"の反転判定 */
   constexpr auto STAIR3A_X = 5585; /*!<階段種別"3A"のX座標 */  constexpr auto STAIR3A_Y = 7840;  /*!<階段種別"3A"のY座標 */  constexpr auto STAIR3A_FLIP = false; /*!<階段種別"3A"の反転判定 */
   constexpr auto STAIR4A_X = 175;  /*!<階段種別"4A"のX座標 */  constexpr auto STAIR4A_Y = 7080;  /*!<階段種別"4A"のY座標 */  constexpr auto STAIR4A_FLIP = true;  /*!<階段種別"4A"の反転判定 */
   constexpr auto STAIR5A_X = 5585; /*!<階段種別"5A"のX座標 */  constexpr auto STAIR5A_Y = 6320;  /*!<階段種別"5A"のY座標 */  constexpr auto STAIR5A_FLIP = false; /*!<階段種別"5A"の反転判定 */
   constexpr auto STAIR6A_X = 4015; /*!<階段種別"6A"のX座標 */  constexpr auto STAIR6A_Y = 5560;  /*!<階段種別"6A"のY座標 */  constexpr auto STAIR6A_FLIP = true;  /*!<階段種別"6A"の反転判定 */
   constexpr auto STAIR6B_X = 3665; /*!<階段種別"6B"のX座標 */  constexpr auto STAIR6B_Y = 5560;  /*!<階段種別"6B"のY座標 */  constexpr auto STAIR6B_FLIP = false; /*!<階段種別"6B"の反転判定 */
   constexpr auto STAIR7A_X = 5585; /*!<階段種別"7A"のX座標 */  constexpr auto STAIR7A_Y = 4800;  /*!<階段種別"7A"のY座標 */  constexpr auto STAIR7A_FLIP = false; /*!<階段種別"7A"の反転判定 */
   constexpr auto STAIR7B_X = 2055; /*!<階段種別"7B"のX座標 */  constexpr auto STAIR7B_Y = 4800;  /*!<階段種別"7B"のY座標 */  constexpr auto STAIR7B_FLIP = true;  /*!<階段種別"7B"の反転判定 */
   constexpr auto STAIR8A_X = 4900; /*!<階段種別"8A"のX座標 */  constexpr auto STAIR8A_Y = 4040;  /*!<階段種別"8A"のY座標 */  constexpr auto STAIR8A_FLIP = true;  /*!<階段種別"8A"の反転判定 */
   constexpr auto STAIR9A_X = 175;  /*!<階段種別"9A"のX座標 */  constexpr auto STAIR9A_Y = 3280;  /*!<階段種別"9A"のY座標 */  constexpr auto STAIR9A_FLIP = true;  /*!<階段種別"9A"の反転判定 */
   constexpr auto STAIR10A_X = 5585;/*!<階段種別"10A"のX座標 */ constexpr auto STAIR10A_Y = 2520; /*!<階段種別"10A"のY座標 */ constexpr auto STAIR10A_FLIP = false;/*!<階段種別"10A"の反転判定 */
   constexpr auto STAIR11A_X = 175; /*!<階段種別"11A"のX座標 */ constexpr auto STAIR11A_Y = 1760; /*!<階段種別"11A"のY座標 */ constexpr auto STAIR11A_FLIP = true; /*!<階段種別"11A"の反転判定 */

   //行燈
   constexpr auto ANDON5A_X = 4000; /*!<行燈種別"5A"のX座標 */  constexpr auto ANDON5A_Y = 6320;  /*!<行燈種別"5A"のY座標 */ 
   constexpr auto ANDON5B_X = 4900; /*!<行燈種別"5B"のX座標 */  constexpr auto ANDON5B_Y = 6320;  /*!<行燈種別"5B"のY座標 */
   constexpr auto ANDON6A_X = 2800; /*!<行燈種別"6A"のX座標 */  constexpr auto ANDON6A_Y = 5560;  /*!<行燈種別"6A"のY座標 */
   constexpr auto ANDON8A_X = 4600; /*!<行燈種別"8A"のX座標 */  constexpr auto ANDON8A_Y = 4040;  /*!<行燈種別"8A"のY座標 */
   constexpr auto ANDON8B_X = 4100; /*!<行燈種別"8B"のX座標 */  constexpr auto ANDON8B_Y = 4040;  /*!<行燈種別"8B"のY座標 */
   constexpr auto ANDON8C_X = 3580; /*!<行燈種別"8C"のX座標 */  constexpr auto ANDON8C_Y = 4040;  /*!<行燈種別"8C"のY座標 */
   constexpr auto ANDON8D_X = 3100; /*!<行燈種別"8D"のX座標 */  constexpr auto ANDON8D_Y = 4040;  /*!<行燈種別"8D"のY座標 */
   constexpr auto ANDON8E_X = 2650; /*!<行燈種別"8E"のX座標 */  constexpr auto ANDON8E_Y = 4040;  /*!<行燈種別"8E"のY座標 */
   constexpr auto ANDON11A_X = 4900;/*!<行燈種別"11A"のX座標 */  constexpr auto ANDON11A_Y = 1760;/*!<行燈種別"11A"のY座標 */
   constexpr auto ANDON11B_X = 3800;/*!<行燈種別"11B"のX座標 */  constexpr auto ANDON11B_Y = 1760;/*!<行燈種別"11B"のY座標 */
   constexpr auto ANDON11C_X = 2700;/*!<行燈種別"11C"のX座標 */  constexpr auto ANDON11C_Y = 1760;/*!<行燈種別"11C"のY座標 */
   constexpr auto ANDON11D_X = 1900;/*!<行燈種別"11D"のX座標 */ constexpr auto ANDON11D_Y = 1760; /*!<行燈種別"11D"のY座標 */
   constexpr auto ANDON11E_X = 1000;/*!<行燈種別"11E"のX座標 */ constexpr auto ANDON11E_Y = 1760; /*!<行燈種別"11E"のY座標 */
   
   //回復ポイント
   constexpr auto  REST_POINT6A_X = 2100;/*!<回復ポイント種別"6A"のX座標 */ constexpr auto REST_POINT6A_Y = 4800 + 370;/*!<回復ポイント種別"6A"のY座標 */
   constexpr auto  REST_POINT7A_X = 5000;/*!<回復ポイント種別"7A"のX座標 */ constexpr auto REST_POINT7A_Y = 4040 + 370;/*!<回復ポイント種別"7A"のY座標 */
}