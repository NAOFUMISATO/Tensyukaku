#include <DxLib.h>
#include "ResourceServer.h"
#include "Game.h"
#include "GameEndSelect.h"
namespace {
   constexpr auto RED = 0;
   constexpr auto GREEN = 1;
   constexpr auto BLUE = 2;
}
//�Q�[���I��
GameEndSelect::GameEndSelect() {
   Init();
   _grhandle = ResourceServer::LoadGraph("res/Mode/GameEnd.png");
};
GameEndSelect::~GameEndSelect() {
};

void GameEndSelect::Init() {
   _x = 1800;
   _y = 970;
   _hit_x = -220;
   _hit_y = -60;
   _hit_w = 400;
   _hit_h = 120;
   _drg.first = 1.0;
   _drg.second = 0.0;
   _alpha = 0;
}

void GameEndSelect::Process(Game& g) {
   ObjectBase::Process(g);
   for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
   {
      // ite�̓J�[�\�����H
      if ((*ite)->GetObjType() == OBJECTTYPE::CURSOR)
      {
         if (IsHit(*(*ite)) == true)
         {
            _drg.first = 1.1;
         }
         else { _drg.first = 1.0; }
      }
   }
   if (_x >= 1620) {
      _x -= 2;
   }
   if (_alpha <= 255) {
      _alpha += 2;
   }
}

void GameEndSelect::Draw(Game& g) {
   auto scale = _drg.first;
   auto angle = _drg.second;
   SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
   DrawRotaGraph(_x, _y, scale, angle, _grhandle, true, _isflip);
#ifdef _DEBUG
   int& re = std::get<RED>(_debug_color);
   int& gr = std::get<GREEN>(_debug_color);
   int& bl = std::get<BLUE>(_debug_color);
   SetDrawBlendMode(DX_BLENDMODE_ALPHA, _debug_alpha);      // �������`��w��
   DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_x + _hit_w, _y + _hit_y + _hit_h, GetColor(re, gr, bl), _debug_fill);   // �������̐Ԃœ����蔻��`��
#endif
   SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);      // �s�����`��w��
}
