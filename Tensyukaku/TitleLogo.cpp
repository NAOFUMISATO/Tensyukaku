#include <DxLib.h>
#include "ResourceServer.h"
#include "Game.h"
#include "TitleLogo.h"
namespace {
   constexpr auto RED = 0;
   constexpr auto GREEN = 1;
   constexpr auto BLUE = 2;
}
//タイトルロゴ
TitleLogo::TitleLogo() {
   Init();
   _grall["TitleLogo"].resize(30);
   ResourceServer::LoadDivGraph("res/Mode/TitleLogo.png", 30, 7, 5, 1280, 410, _grall["TitleLogo"].data());
}
TitleLogo::~TitleLogo() {
}
void TitleLogo::Init() {
   _x = 1350;
   _y = 200;
   _hit_x = -400;
   _hit_y = -100;
   _hit_w = 700;
   _hit_h = 200;
   _action_cnt = _cnt;
}
void TitleLogo::Process(Game& g) {
   ObjectBase::Process(g);
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["TitleLogo"][_anime["TitleLogo"]];
   if (frame < 90) {
      _anime["TitleLogo"] = ((frame) / 3) % 30;
   }
}

void TitleLogo::Draw(Game& g) {
   auto scale = _drg.first;
   auto angle = _drg.second;
   DrawRotaGraph(_x, _y, scale, angle, _grhandle, true, _isflip);
#ifdef _DEBUG
   int& re = std::get<RED>(_debug_color);
   int& gr = std::get<GREEN>(_debug_color);
   int& bl = std::get<BLUE>(_debug_color);
   SetDrawBlendMode(DX_BLENDMODE_ALPHA, _debug_alpha);      // 半透明描画指定
   DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_x + _hit_w, _y + _hit_y + _hit_h, GetColor(re, gr, bl), _debug_fill);   // 半透明の赤で当たり判定描画
#endif
   SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);      // 不透明描画指定
}