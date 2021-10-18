#include "BossEventBlock.h"
#include "Game.h"

using namespace BEInfo;
BossEventBlock::BossEventBlock(int blocknum) {
   _block_num = blocknum;
   Init();
}
BossEventBlock::~BossEventBlock() {
}

void BossEventBlock::Init() {
   PositionSetting();
   _gx = GRAPHPOINT_X;
   _gy = GRAPHPOINT_Y;
   _hit_x = POSITION_HITX;
   _hit_y = POSITION_HITY;
   _hit_w = COLLISION_WIDTH;
   _hit_h = COLLISION_HEIGHT;
#ifdef _DEBUG
   _debug_color = std::make_tuple(255, 255, 255);
   _debug_alpha = 128;
   _debug_fill = true;
#endif
}
void BossEventBlock::Process(Game& g) {
   ObjectBase::Process(g);
   switch (_block_num) {
   case 1:
      //ボスイベントAとプレイヤーの当たり判定
      for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
      {
         // iteはプレイヤーか？
         if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
         {
            // //ボスイベントAとプレイヤーの当たり判定を行う
            if (IsHit(*(*ite)) == true)
            {
               Delete(g);
               (*ite)->SetBEventA(true);
               for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
               {
                  // iteはプレイヤーか？
                  if ((*ite)->GetObjType() == OBJECTTYPE::BOSS)
                  {
                     (*ite)->SetBEventA(true);
                  }
               }
            }
         }
      }
      break;
   case 2:
      //ボスイベントBとプレイヤーの当たり判定
      for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
      {
         // iteはプレイヤーか？
         if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
         {
            // //ボスイベントBとプレイヤーの当たり判定を行う
            if (IsHit(*(*ite)) == true)
            {
               Delete(g);
               (*ite)->SetBEventB(true);
               for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
               {
                  // iteはプレイヤーか？
                  if ((*ite)->GetObjType() == OBJECTTYPE::BOSS)
                  {
                     (*ite)->SetBEventB(true);
                     g.GetMS()->Del(g.GetMS()->Get("Flame"));
                  }
               }
            }
         }
      }
      break;
   }
}
void BossEventBlock::Draw(Game& g) {
   ObjectBase::Draw(g);
}
void BossEventBlock::Delete(Game& g) {
   g.GetOS()->Del(this);
}

void BossEventBlock::PositionSetting() {
   switch (_block_num) {
   case 1:
      _x = BOSSA_X;
      _y = BOSSA_Y;
      break;
   case 2:
      _x = BOSSB_X;
      _y = BOSSB_Y;
      break;
   }
}
