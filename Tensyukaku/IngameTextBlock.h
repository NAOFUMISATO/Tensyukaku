#pragma once
#include "ObjectBase.h"

class IngameTextBlock :public ObjectBase {
public:
   IngameTextBlock(std::string  texttype);
   ~IngameTextBlock();
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::CPOINTBLOCK; }
   void Init()override;
   void Process(Game& g)override;
   void Draw(Game& g)override;
   void Delete(Game& g)override;
private:
   void TextPosition();
   std::string  _text_type;
};
namespace ITInfo {
   constexpr auto GRAPHPOINT_X = 0;      //X位置から描画点までの差分
   constexpr auto GRAPHPOINT_Y = -50;      //Y位置から描画点までの差分
   constexpr auto POSITION_HITX = -50;      //描画点から当たり判定左上座標までの差分
   constexpr auto POSITION_HITY = -50;      //描画点から当たり判定左上座標までの差分
   constexpr auto COLLISION_WIDTH = 100;   //当たり判定横幅
   constexpr auto COLLISION_HEIGHT = 100;   //当たり判定縦幅
   /*----------各テキストブロック座標----------*/
   //天守
   constexpr auto  TOP_TEXT_X =500;
   constexpr auto  TOP_TEXT_Y = 1000;
   //上層
   constexpr auto  UPPER_TEXT_X = 400;
   constexpr auto  UPPER_TEXT_Y = 2520;
   //中層
   constexpr auto  MIDDLE_TEXT_X = 5500;
   constexpr auto  MIDDLE_TEXT_Y = 5560;
   //下層
   constexpr auto  UNDER_TEXT_X = 350;
   constexpr auto  UNDER_TEXT_Y = 9360;
}