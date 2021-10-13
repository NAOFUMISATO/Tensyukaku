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
   constexpr auto GRAPHPOINT_X = 0;      //X�ʒu����`��_�܂ł̍���
   constexpr auto GRAPHPOINT_Y = -50;      //Y�ʒu����`��_�܂ł̍���
   constexpr auto POSITION_HITX = -50;      //�`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto POSITION_HITY = -50;      //�`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto COLLISION_WIDTH = 100;   //�����蔻�艡��
   constexpr auto COLLISION_HEIGHT = 100;   //�����蔻��c��
   /*----------�e�e�L�X�g�u���b�N���W----------*/
   //�V��
   constexpr auto  TOP_TEXT_X =500;
   constexpr auto  TOP_TEXT_Y = 1000;
   //��w
   constexpr auto  UPPER_TEXT_X = 400;
   constexpr auto  UPPER_TEXT_Y = 2520;
   //���w
   constexpr auto  MIDDLE_TEXT_X = 5500;
   constexpr auto  MIDDLE_TEXT_Y = 5560;
   //���w
   constexpr auto  UNDER_TEXT_X = 350;
   constexpr auto  UNDER_TEXT_Y = 9360;
}