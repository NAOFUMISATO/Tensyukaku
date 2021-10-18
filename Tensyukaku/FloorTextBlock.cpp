#include "FloorTextBlock.h"
#include "ModeFloorText.h"
#include "Game.h"
#include "ResourceServer.h"

using namespace FTInfo;
FloorTextBlock::FloorTextBlock(std::string texttype) {
   _text_type = texttype;
   _se["FloorSign"] = ResourceServer::LoadSoundMem("se/Gimik/FloorSign.wav");
   _vpal["FloorSign"] = 255;
   Init();
}
FloorTextBlock::~FloorTextBlock() {
};

void FloorTextBlock::Init() {
   PositionSetting();
   _gx = GRAPHPOINT_X;
   _gy = GRAPHPOINT_Y;
   _hit_x = POSITION_HITX;
   _hit_y = POSITION_HITY;
   _hit_w = COLLISION_WIDTH;
   _hit_h = COLLISION_HEIGHT;
#ifdef _DEBUG
   _debug_color = std::make_tuple(15, 15, 15);
   _debug_alpha = 128;
   _debug_fill = true;
#endif
}
void FloorTextBlock::Process(Game& g) {
   ObjectBase::Process(g);
   //チュートリアルブロックとプレイヤーの当たり判定
   for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
   {
      // iteはプレイヤーか？
      if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
      {
         // //チュートリアルブロックとプレイヤーの当たり判定を行う
         if (IsHit(*(*ite)) == true)
         {
            Delete(g);
            PlaySoundMem(_se["FloorSign"],DX_PLAYTYPE_BACK,true);
            if (_text_type == "TOP") {
               auto ittop = new ModeFloorText();
               ittop->SetType("TOP");
               g.GetMS()->Add(ittop, 3, "TOP");
            }
            else if (_text_type == "UPPER") {
               auto itupper = new ModeFloorText();
               itupper->SetType("UPPER");
               g.GetMS()->Add(itupper, 3, "UPPER");
            }
            else if (_text_type == "MIDDLE") {
               auto itmiddle = new ModeFloorText();
               itmiddle->SetType("MIDDLE");
               g.GetMS()->Add(itmiddle, 3, "MIDDLE");
            }
            else if (_text_type == "UNDER") {
               auto itunder = new ModeFloorText();
               itunder->SetType("UNDER");
               g.GetMS()->Add(itunder, 10, "UNDER");
            }
         }
      }
   }
}

void  FloorTextBlock::Draw(Game& g) {
   ObjectBase::Draw(g);
}

void FloorTextBlock::Delete(Game& g) {
   g.GetOS()->Del(this);
}

void FloorTextBlock::PositionSetting() {
   if (_text_type == "TOP") {
      _x = TOP_TEXT_X;
      _y = TOP_TEXT_Y;
   }
   else if (_text_type == "UPPER") {
      _x = UPPER_TEXT_X;
      _y = UPPER_TEXT_Y;
   }
   else if (_text_type == "MIDDLE") {
      _x = MIDDLE_TEXT_X;
      _y = MIDDLE_TEXT_Y;
   }
   else if (_text_type == "UNDER") {
      _x = UNDER_TEXT_X;
      _y = UNDER_TEXT_Y;
   }
}