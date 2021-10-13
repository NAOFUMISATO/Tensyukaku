#include  <DxLib.h>
#include "Game.h"
#include "ResourceServer.h"
#include "LowBlood.h"

LowBlood::LowBlood(int x, int y, bool flip, int bloodtype) {
   _x = x;
   _y = y;
   _isflip = flip;
   _blood_type = bloodtype;
   _grall["LowBlood1"].resize(1);
   ResourceServer::LoadDivGraph("res/Efect/LowBlood1.png", 1, 1, 1, 600, 160, _grall["LowBlood1"].data());
   _grall["LowBlood2"].resize(1);
   ResourceServer::LoadDivGraph("res/Efect/LowBlood2.png", 1, 1, 1, 600, 160, _grall["LowBlood2"].data());
   _grall["LowBlood3"].resize(1);
   ResourceServer::LoadDivGraph("res/Efect/LowBlood3.png", 1, 1, 1, 600, 160, _grall["LowBlood3"].data());
   _grall["LowBlood4"].resize(1);
   ResourceServer::LoadDivGraph("res/Efect/LowBlood4.png", 1, 1, 1, 600, 160, _grall["LowBlood4"].data());
   Init();
}
LowBlood::~LowBlood() {
};

void LowBlood::Init() {
   _alpha = 255;
   _action_cnt = _cnt;
}

void LowBlood::Process(Game& g) {
   EfectBase::Process(g);
   auto frame = _cnt - _action_cnt;
   switch (_blood_type) {
   case 0:
      _grhandle = _grall["LowBlood1"][0];
      break;   
   case 1:
      _grhandle = _grall["LowBlood2"][0];
      break;   
   case 2:
      _grhandle = _grall["LowBlood3"][0];
      break;   
   case 3:
      _grhandle = _grall["LowBlood4"][0];
      break;
   }
   if (frame >= 30 && _alpha > 0) {
      _alpha -= 10;
   }
   if (_alpha == 0) {
      Delete(g);
   }
}

void LowBlood::Draw(Game& g) {
   EfectBase::Draw(g);
}

void LowBlood::Delete(Game& g) {
   g.GetOS()->Del(this);
}