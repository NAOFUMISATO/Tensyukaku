#include <DxLib.h>
#include "RestPoint.h"
#include "ResourceServer.h"
#include "Game.h"

RestPoint::RestPoint(int x,int y) {
   _x = x;
   _y = y;
   Init();
   _grall["Rest"].resize(2);
   ResourceServer::LoadDivGraph("res/Gimik/RestPointAll.png",2,2,1,160,320, _grall["Rest"].data());
}
RestPoint::~RestPoint() {
}

void RestPoint::Init() {
   _sort = 5;
   _gx = 0;
   _gy = 160;
   _hit_x = -40;
   _hit_y = -160;
   _hit_w = 80;
   _hit_h = 320;
   _graph_no = 0;
   _hit_flag = true;
}

void RestPoint::Process(Game& g) {
   ObjectBase::Process(g);
   _grhandle=_grall["Rest"][_anime["Rest"]];
   _anime["Rest"] = _graph_no;
   //レストポイントとプレイヤーの当たり判定
   for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++) {
      // iteはプレイヤーか？
      if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER) {
         if (IsHit(*(*ite)) == true && _hit_flag == true) {
            _graph_no = 1;
            _hit_flag = false;
         }
      }
   }
}

void RestPoint::Draw(Game& g) {
   ObjectBase::Draw(g);
}