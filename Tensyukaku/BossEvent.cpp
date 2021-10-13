#include "BossEvent.h"
#include "Game.h"
using namespace BEInfo;
BossEventA::BossEventA(int x, int y) {
   _x = x;
   _y = y;
   Init();
}
BossEventA::~BossEventA() {
}

void BossEventA::Init() {
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
void BossEventA::Process(Game& g) {
   ObjectBase::Process(g);
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
}
void BossEventA::Draw(Game& g) {
   ObjectBase::Draw(g);
}
void BossEventA::Delete(Game& g) {
   g.GetOS()->Del(this);
}
BossEventB::BossEventB(int x, int y) {
   _x = x;
   _y = y;
   Init();
}
BossEventB::~BossEventB() {
}

void BossEventB::Init() {
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
void BossEventB::Process(Game& g) {
   ObjectBase::Process(g);
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
}
void BossEventB::Draw(Game& g) {
   ObjectBase::Draw(g);
}
void BossEventB::Delete(Game& g) {
   g.GetOS()->Del(this);
}